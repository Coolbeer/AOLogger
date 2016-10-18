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
<<<<<<< HEAD
    //Identify event type

    //Find the entities and add the event.
    std::string entityName = newEvent.getSource();
    //Check if this is a new entity
    if (this->entityMap.find(entityName) == this->entityMap.end())
    {
        //This is a new entity. Create it!
//WARNING I am almost entirely certain that this should be instantiated with new
        this->entityMap.insert(std::pair<std::string, t_entity>(newEvent.getSource(), t_entity()));
    }
    //Get the entity
    //Add source event

    entityName = newEvent.getTarget();
    //Check if this is a new entity
    if (this->entityMap.find(entityName) == this->entityMap.end())
    {
        //This is a new entity. Create it!
//WARNING I am almost entirely certain that this should be instantiated with new
        this->entityMap.insert(std::pair<std::string, t_entity>(newEvent.getSource(), t_entity(entityName)));
    }
    //Get the entity
    //Add target event

=======
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
    t_entity newEntity;
    newEntity.setName(whoDidWhat);
    newEntity.addEvent(newEvent);
    theEntities.push_back(newEntity);
>>>>>>> origin/master
}
