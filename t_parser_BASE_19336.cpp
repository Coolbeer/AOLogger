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

        if (channel=="Other hit by other"||channel=="You hit other")
        {
            QRegularExpression expression("(?<source>.+) hit (?<target>.+) for (?<damage>\\d+) points of (?<damageType>\\w+) damage.(?<hitType>.*)");
            QRegularExpressionMatch match = expression.match(message);
            source = match.captured("source");
            target = match.captured("target");
            value = match.captured("damage").toInt();
            damageType = match.captured("damageType");

            if (source == "You")
                source = player;

            std::cout << source.toStdString() << " hit " << target.toStdString() << " for " << value << " points of " << damageType.toStdString() << " damage" << std::endl;
        }
        if (channel=="Your misses"){
            QRegularExpression expression("You tried to hit (?<target>.+), but missed.");
            QRegularExpressionMatch match = expression.match(message);

            source = player;
            target = match.captured("target");

            std::cout << source.toStdString() << " missed " << target.toStdString() << std::endl;

        }

    }

}
