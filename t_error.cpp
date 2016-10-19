#include "t_error.h"

t_error::t_error(const std::string &source, const std::string &message)
{
    this->setSource(source);
    this->setMessage(message);
}

k_event::k_type t_error::type(void)
{
    return k_event::error;
}
