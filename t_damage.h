#ifndef T_DAMAGE_H
#define T_DAMAGE_H

#include <cstdint>
#include <string>

namespace k_dmg
{
    enum type{ melee, projectile, energy, disease, chemical, radiation, cold, fire, fling, burst, fullAuto, unknown };
}
namespace k_hit
{
    enum type{ normal, glancing, critical, missed };
}

class t_damage
{
    public:
        t_damage();
        uint64_t timeStamp = 0;
        uint32_t value = 0;
        std::string victim = "";
        k_dmg::type dType = k_dmg::unknown;
        k_hit::type hType = k_hit::normal;
};

#endif // T_DAMAGE_H
