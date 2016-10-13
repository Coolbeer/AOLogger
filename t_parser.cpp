#include "t_parser.h"
#include "t_damage.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <iostream>

t_parser::t_parser()
{
}


t_event* t_parser::parseLine(const std::string &logLine)
{
    //Regular expression to find time stamp and channel
    QRegularExpression timeChannelRegex(".+\"(.+)\",\"\",(\\d{10})](.+)");

    //Event spesific regexes
    QRegularExpression missedRegex("You tried to hit (?<target>.+), but missed.");

    QRegularExpressionMatch match = timeChannelRegex.match(QString::fromStdString(logLine));

    if (match.hasMatch()){
        channel = match.captured(1);
        timestamp = match.captured(2).toInt();
        message = match.captured(3);

        if (channel=="Other hit by other"||channel=="You hit other")
        {
            t_damage *damage = new t_damage(timestamp, message.toStdString());
            std::cout << damage->getSource() << " hit " << damage->getTarget() << " for " << damage->getDamageValue() << " points of " << damage->getDamageType() << " damage " << damage->getHitType() <<std::endl;
        }

        else if (channel=="Your misses"){
            QRegularExpressionMatch match = missedRegex.match(message);

            source = player;
            target = match.captured("target");

            std::cout << source.toStdString() << " missed " << target.toStdString() << std::endl;
            return false;
        }
        else
        {
            std::cerr << "Unparsed log line: " << logLine << std::endl;
            return false;
        }
    }
    else
        std::cerr << "Malformed log line: " << logLine << std::endl;
        return false;
}
