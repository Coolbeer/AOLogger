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
                                t_entity(std::string);
        virtual                 ~t_entity(void) { };

        void                    addEvent(t_event *theEvent);
        std::string             getName(void);
        void                    setName(const std::string &newName);

//    signals:
//        void                    updateEventListSignal(const std::string &message);

    private:
        std::string             name;
        std::vector<t_event*>   eventList;
        t_damageContainer       totalDamage;

};

#endif // T_ENTITY_H
