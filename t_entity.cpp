#include "t_entity.h"

t_entity::t_entity()
{

}

void  t_entity::addEvent(t_event *theEvent)
{

}

std::string t_entity::getName()
{
    return name;
}

void t_entity::setName(const std::string &newName)
{
    name = newName;
}
