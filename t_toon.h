#ifndef T_TOON_H
#define T_TOON_H

#include "t_entity.h"

#include <iostream>
#include <vector>

class t_toon : public t_entity
{
public:
    t_toon();
    bool                    setLogFile(const std::string&);
    std::string             getLogFile(void);

private:
    std::string             logFile;
    std::vector<t_entity>   pets;
};

#endif // T_TOON_H
