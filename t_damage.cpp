#include "t_damage.h"

t_damage::t_damage()
{

}

void t_damage::setTimeStamp(const uint64_t &tStamp)
{
    timeStamp = tStamp;
}

void t_damage::setDamageValue(const uint32_t &dVal)
{
    value = dVal;
}

void t_damage::setVictim(const std::string &vic)
{
    victim = vic;
}

void t_damage::setDamageType(const std::string &damType)
{
    if(damType == "melee")
        dType = k_dmg::projectile;
    else if(damType == "projectile")
        dType = k_dmg::projectile;
    else if(damType == "energy")
        dType = k_dmg::energy;
    else if(damType == "disease")
        dType = k_dmg::disease;
    else if(damType == "chemical")
        dType = k_dmg::chemical;
    else if(damType == "radiation")
        dType = k_dmg::radiation;
    else if(damType == "cold")
        dType = k_dmg::cold;
    else if(damType == "fire")
        dType = k_dmg::fire;
    else if(damType == "fling")
        dType = k_dmg::fling;
    else if(damType == "burst")
        dType = k_dmg::burst;
    else if(damType == "fullAuto")
        dType = k_dmg::fullAuto;
    else
        dType = k_dmg::unknown;
}

void t_damage::setHitType(const std::string &hitType)
{
    if(hitType == "normal")
        hType = k_hit::normal;
    else if(hitType == "glancing")
        hType = k_hit::glancing;
    else if(hitType == "critical")
        hType = k_hit::critical;
    else if(hitType == "missed")
        hType = k_hit::missed;
}
