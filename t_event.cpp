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

uint64_t t_event::getTimeStamp()
{
    return timeStamp;
}

std::string t_event::getMessage(void)
{
    return message;
}

void t_event::setSource(const std::string &newSource)
{
    source = newSource;
}

void t_event::setTarget(const std::string &newTarget)
{
    target = newTarget;
}

void t_event::setTimeStamp(const uint64_t &tStamp)
{
    timeStamp = tStamp;
}

void t_event::setMessage(const std::string &message)
{
    this->message = message;
}
