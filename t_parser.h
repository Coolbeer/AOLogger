#ifndef T_PARSER_H
#define T_PARSER_H

#include <string>
#include <QString>

class t_parser
{
public:
    t_parser();
    void parseLine(const std::string &logLine);

    QString player = "Player";
    QString channel;
    uint64_t timestamp;
    QString message;

    QString source;
    QString target;
    QString event;
    uint32_t value;
    QString damageType;

    bool isCritical;
    bool isGlancing;


};

#endif // T_PARSER_H
