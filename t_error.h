#ifndef T_ERROR_H
#define T_ERROR_H

#include "t_event.h"

class t_error : t_event
{
    public:
        t_error();
        k_event::k_type     type(void);

};

#endif // T_ERROR_H
