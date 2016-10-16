#ifndef T_DAMAGELIST_H
#define T_DAMAGELIST_H

#include <cstdint>

class t_damageContainer
{
    public:
        t_damageContainer();
        uint64_t    melee           = 0;
        uint64_t    projectile      = 0;
        uint64_t    energy          = 0;
        uint64_t    disease         = 0;
        uint64_t    chemical        = 0;
        uint64_t    radiation       = 0;
        uint64_t    cold            = 0;
        uint64_t    fire            = 0;
        uint64_t    fling           = 0;
        uint64_t    burst           = 0;

    private:

};

#endif // T_DAMAGELIST_H
