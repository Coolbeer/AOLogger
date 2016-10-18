#include "t_damagecontainer.h"

t_damageContainer::t_damageContainer()
{

}

void t_damageContainer::addDamageEvent(t_damage *damageEvent)
{
    switch(damageEvent->getDamageType())
    {
        case k_dmg::melee:
            melee += damageEvent->getDamageValue();
            return;
        case k_dmg::projectile:
            projectile += damageEvent->getDamageValue();
            return;
        case k_dmg::energy:
            energy += damageEvent->getDamageValue();
            return;
        case k_dmg::disease:
            disease += damageEvent->getDamageValue();
            return;
        case k_dmg::chemical:
            chemical += damageEvent->getDamageValue();
            return;
        case k_dmg::radiation:
            radiation += damageEvent->getDamageValue();
            return;
        case k_dmg::cold:
            cold += damageEvent->getDamageValue();
            return;
        case k_dmg::fire:
            fire += damageEvent->getDamageValue();
            return;
        case k_dmg::fling:
            fling += damageEvent->getDamageValue();
            return;
        case k_dmg::burst:
            burst += damageEvent->getDamageValue();
            return;
        case k_dmg::fullAuto:
            fullAuto += damageEvent->getDamageValue();
            return;
        case k_dmg::unknown:
            unknown += damageEvent->getDamageValue();
            return;
    }
}
