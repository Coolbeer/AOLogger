#include "t_damage.h"

#include <iostream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

t_damage::t_damage()
{

}

t_damage::t_damage(uint32_t timestamp, std::string message)
{
    QRegularExpression hitTargetRegex("(?<source>.+) hit (?<target>.+) for (?<damage>\\d+) points of (?<damageType>\\w+) damage.\\s*(?<hitType>\\w*)");
    QRegularExpressionMatch match = hitTargetRegex.match(QString::fromStdString(message));

    this->setSource(match.captured("source").toStdString());
    this->setTarget(match.captured("target").toStdString());
    this->setTimeStamp(timestamp);
    this->setDamageValue(match.captured("damage").toInt());
    this->setDamageType(match.captured("damageType").toStdString());
    this->setHitType(match.captured("hitType").toStdString());

}

k_event::k_type t_damage::type(void)
{
    return k_event::damage;
}

void t_damage::setDamageValue(const uint32_t &dVal)
{
    value = dVal;
}

void t_damage::setDamageType(const std::string &damType)
{
    if(damType == "melee")
        dType = k_dmg::melee;
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
    std::cout << "\"" << hitType << "\"" << std::endl;
    if(hitType == "Glancing")
        hType = k_hit::glancing;
    else if(hitType == "Critical")
        hType = k_hit::critical;
    else if(hitType == "missed")
        hType = k_hit::missed;
    else
        hType = k_hit::normal;

}


std::string t_damage::getDamageType()
{
    switch(dType)
    {
        case k_dmg::melee:
            return "projectile";
        case k_dmg::projectile:
            return "projectile";
        case k_dmg::energy:
            return "energy";
        case k_dmg::disease:
            return "disease";
        case k_dmg::chemical:
            return "chemical";
        case k_dmg::radiation:
            return "radiation";
        case k_dmg::cold:
            return "cold";
        case k_dmg::fire:
            return "fire";
        case k_dmg::fling:
            return "fling";
        case k_dmg::burst:
            return "burst";
        case k_dmg::fullAuto:
            return "fullAuto";
        default:
            return "unknown";
    }
}

uint32_t t_damage::getDamageValue()
{
    return value;
}

std::string t_damage::getHitType()
{
    switch(hType)
    {
        case k_hit::critical:
            return "critical";
        case k_hit::glancing:
            return "glancing";
        default:
            return "normal";
    }
}

