#include "t_parser.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>

t_parser::t_parser()
{

}


void t_parser::parseLine(const std::string &logLine)
{
    //Regular expression to find time stamp and channel
    QRegularExpression timeChannelRegex(".+\"(.+)\",\"\",(\\d{10})](.+)");

    //Event spesific regexes
    QRegularExpression hitTargetRegex("(?<source>.+) hit (?<target>.+) for (?<damage>\\d+) points of (?<damageType>\\w+) damage.(?<hitType>.*)");
    QRegularExpression missedRegex("You tried to hit (?<target>.+), but missed.");

    QRegularExpressionMatch match = timeChannelRegex.match(QString::fromStdString(logLine));

    if (match.hasMatch()){
        channel = match.captured(1);
        timestamp = match.captured(2).toInt();
        message = match.captured(3);

        if (channel=="Other hit by other"||channel=="You hit other")
        {
            QRegularExpressionMatch match = hitTargetRegex.match(message);
            source = match.captured("source");
            target = match.captured("target");
            value = match.captured("damage").toInt();
            damageType = match.captured("damageType");
            isCritical = match.captured("hitType")==" Critical hit!";
            isGlancing = match.captured("hitType")==" Glancing hit!";

            //Replace "You" with player name.
            if (source == "You")
                source = player;

            qDebug() << source << "hit" << target << "for" << value << "points of" << damageType << "damage";
        }
        else if (channel=="Your misses"){
            QRegularExpressionMatch match = missedRegex.match(message);

            source = player;
            target = match.captured("target");

            qDebug() << source << "missed" << target;

        }
        else
        {
            qDebug() << QString::fromStdString(logLine);
        }
    }

}
