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
        t_entity(std::string);

        std::string name;
        std::vector<t_damage> damageGivenList;
        std::vector<t_damage> damageTakenList;
//        std::vector<t_heal> healGiven;
//        std::vector<t_heal> healReceived;
//        std::vector<t_loot> lootList;
//        std::vector<t_error> errorList;

};

#endif // T_ENTITY_H
