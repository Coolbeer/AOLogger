#ifndef T_DAMAGE_H
#define T_DAMAGE_H

#include <cstdint>
#include <string>

#include "t_event.h"

namespace k_dmg
{
    enum type{ melee, projectile, energy, disease, chemical, radiation, cold, fire, fling, burst, fullAuto, unknown };
}

namespace k_hit
{
    enum type{ normal, glancing, critical, missed };
}

class t_damage : public t_event
{
    public:
                            t_damage();
                            t_damage(uint32_t, std::string);
        k_event::k_type     type(void);

        void                setDamageType(const std::string &damType);
        void                setDamageValue(const uint32_t &dVal);
        void                setHitType(const std::string &hitType);

        std::string         getDamageType(void);
        uint32_t            getDamageValue(void);
        std::string         getHitType(void);

    private:
        uint32_t            value = 0;
        k_dmg::type dType = k_dmg::unknown;
        k_hit::type hType = k_hit::normal;
};

#endif // T_DAMAGE_H
