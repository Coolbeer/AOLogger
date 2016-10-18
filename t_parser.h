#ifndef T_PARSER_H
#define T_PARSER_H

#include "t_event.h"

#include <string>

class t_parser
{
public:
    t_parser();
    t_event* parseLine(const std::string &logLine);

private:
    uint64_t timestamp;
    std::string message;

};

#endif // T_PARSER_H
