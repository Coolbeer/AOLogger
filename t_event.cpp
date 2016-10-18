#include "t_event.h"

t_event::t_event()
{

}

std::string t_event::getSource(void)
{
    return this->source;
}

std::string t_event::getTarget(void)
{
    return this->target;
}

uint64_t t_event::getTimeStamp()
{
    return this->timeStamp;
}

std::string t_event::getMessage(void)
{
    return this->message;
}

void t_event::setSource(const std::string &newSource)
{
    this->source = newSource;
}

void t_event::setTarget(const std::string &newTarget)
{
    this->target = newTarget;
}

void t_event::setTimeStamp(const uint64_t &tStamp)
{
    this->timeStamp = tStamp;
}

void t_event::setMessage(const std::string &message)
{
    this->message = message;
}
