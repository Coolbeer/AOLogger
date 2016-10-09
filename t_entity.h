#ifndef T_ENTITY_H
#define T_ENTITY_H

#include <vector>
#include <string>
#include <cstdint>

#include "t_damage.h"

class t_entity
{
    public:
        t_entity();
        std::string name;
        std::vector<t_damage> damageList;
};

#endif // T_ENTITY_H
