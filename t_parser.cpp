#include "t_parser.h"
#include "t_damage.h"
#include "t_error.h"

#include <iostream>
#include <sstream>
#include <regex>

t_parser::t_parser()
{
}


t_event* t_parser::parseLine(const std::string &logLine)
{
    //Regular expression to find time stamp and channel
    std::regex timeChannelRegex(".+\"(.+)\",\"\",(\\d{10})](.+)");
    //Event spesific regexes
    std::regex missedRegex("You tried to hit (.+), but missed.");

    std::smatch matches;

    //Find time and channel
    std::regex_match(logLine, matches, timeChannelRegex, std::regex_constants::match_not_eol);
    if (matches.length()>0)
    {
        std::string channel = matches[1];
        uint64_t timestamp;
        std::stringstream(matches[2]) >> timestamp;
        std::string message = matches[3];

        //Damage event
        if (channel == "Other hit by other"||channel == "You hit other")
        {
            t_damage *damage = new t_damage(timestamp, message);
            std::cout << damage->getSource() << " hit " << damage->getTarget() << " for " << damage->getDamageValue() << " points of " << damage->getDamageType() << " damage " << damage->getHitType() <<std::endl;
            return (t_event*)damage;

        }
        //Miss event
        else if (channel == "Your misses")
        {
            std::regex_match(message, matches, missedRegex);
            std::string source = "You";
            std::string target = matches[1];

            //TODO Add t_miss() event here
            std::cout << source << " missed " << target << std::endl;
            return false;
        }
        //Unparsed log line!
        else
        {
            std::cerr << "Unparsed log line: " << logLine << std::endl;
            t_error *err = new t_error();
            return (t_event*)err;
        }
    }
    //I don't know what this is, but it's not a valid log line!
    else
    {
        std::cerr << "Malformed log line: " << logLine << std::endl;
        t_error *err = new t_error();
        return (t_event*)err;
    }
}
