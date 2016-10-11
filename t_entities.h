#ifndef T_ENTITIES_H
#define T_ENTITIES_H

#include "t_entity.h"

class t_entities
{
    public:
        t_entities();
        void setPlayerName(const std::string &pName);
        void addEvent(t_event &newEvent);
    private:
        std::string playerName;
        std::vector<t_entity> theEntities;
};

#endif // T_ENTITIES_H
