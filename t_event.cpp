#include "t_event.h"

t_event::t_event()
{

}

std::string t_event::getSource(void)
{
    return source;
}

std::string t_event::getTarget(void)
{
    return target;
}

void t_event::setSource(const std::string &newSource)
{
    source = newSource;
}

void t_event::setTarget(const std::string &newTarget)
{
    target = newTarget;
}
