#ifndef T_ENTITY_H
#define T_ENTITY_H

#include <vector>
#include <string>
#include <cstdint>

#include "t_damage.h"
#include "t_damagecontainer.h"

class t_entity
{
    public:
        t_entity();
<<<<<<< HEAD
        t_entity(std::string);

        std::string name;
        std::vector<t_damage> damageGivenList;
        std::vector<t_damage> damageTakenList;
//        std::vector<t_heal> healGiven;
//        std::vector<t_heal> healReceived;
//        std::vector<t_loot> lootList;
//        std::vector<t_error> errorList;
=======
        void                    addEvent(t_event *theEvent);
        std::string             getName(void);
        void                    setName(const std::string &newName);
        virtual                 ~t_entity(void) { };
    private:
        std::string             name;
        std::vector<t_event*>   eventList;
        t_damageContainer       totalDamage;
>>>>>>> origin/master

};

#endif // T_ENTITY_H
