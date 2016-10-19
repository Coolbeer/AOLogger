#include "t_entity.h"

t_entity::t_entity()
{

}

t_entity::t_entity(std::string name)
{
    this->name = name;
}

void  t_entity::addEvent(t_event *theEvent)
{
    if(theEvent->type() != k_event::error)
        eventList.push_back(theEvent);
    if(theEvent->type() == k_event::damage)
        totalDamage.addDamageEvent(static_cast<t_damage*>(theEvent));

}

std::string t_entity::getName()
{
    return name;
}

void t_entity::setName(const std::string &newName)
{
    name = newName;
}
