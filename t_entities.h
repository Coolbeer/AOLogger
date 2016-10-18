#ifndef T_ENTITIES_H
#define T_ENTITIES_H

#include <unordered_map>

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
        std::unordered_map<std::string, t_entity> entityMap;

};

#endif // T_ENTITIES_H
