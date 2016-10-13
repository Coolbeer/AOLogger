#include "t_error.h"

t_error::t_error()
{

}

k_event::k_type t_error::type(void)
{
    return k_event::error;
}
