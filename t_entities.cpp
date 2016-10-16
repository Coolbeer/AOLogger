#include "t_entities.h"

t_entities::t_entities()
{
    playerName = "Player";
}

void t_entities::setPlayerName(const std::string &pName)
{
    playerName = pName;
}

void t_entities::addEvent(t_event *newEvent)
{
    std::string whoDidWhat = newEvent->getSource();
    if(whoDidWhat == "player")
            whoDidWhat = playerName;
    //TODO: Lets find the player and add the event.

    for(uint16_t i = 0; i != theEntities.size(); ++i)
    {
        if(playerName == theEntities.at(i).getName())
        {
            theEntities.at(i).addEvent(newEvent);
            return;
        }
    }
}
