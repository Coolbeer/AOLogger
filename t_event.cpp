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
