#include "t_parser.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <iostream>

t_parser::t_parser()
{

}

void t_parser::parseLine(const std::string &logLine)
{
    std::cout << logLine << std::endl;

    QRegularExpression timeChannelRegex(".+\"(.+)\",\"\",(\\d{10})](.+)");
    QRegularExpressionMatch match = timeChannelRegex.match(QString::fromStdString(logLine));

    if (match.hasMatch()){
        channel = match.captured(1);
        timestamp = match.captured(2).toInt();
        message = match.captured(3);

        for (int i = 0; i <= match.lastCapturedIndex(); ++i) {
            std::cout << i << ": " << timestamp << " - " << channel.toStdString() << " - " << message.toStdString() << std::endl;
        }
        if (channel=="Other hit by other"||channel=="You hit other")
        {
                QRegularExpression missMessage("(?<source>.+) tried to hit (?<target>.+) , but missed.");
                QRegularExpressionMatch missMatch = missMessage.match(message);
                //if (!missMatch.hasMatch())
                QRegularExpression hitMessage("(?<source>.+) hit (?<target>.+) for (?<damage>\\d+) points of (?<damageType>\\w+) damage.(?<hitType>.*)");
                QRegularExpressionMatch hitMatch = hitMessage.match(message);
                for (int i = 0; i <= hitMatch.lastCapturedIndex(); ++i) {
                    std::cout << i << ": " << hitMatch.captured((i)).toStdString() << std::endl;
                }
                source = hitMatch.captured("source");
                target = hitMatch.captured("target");
                value = hitMatch.captured("damage").toInt();
                damageType = hitMatch.captured("damageType");

            if (source == "You")
                source = player;
        }
        std::cout << source.toStdString() << " hit " << target.toStdString() << " for " << value << " points of " << damageType.toStdString() << " damage" << std::endl;

    }

}
