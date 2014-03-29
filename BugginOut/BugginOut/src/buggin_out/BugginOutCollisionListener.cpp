#include "sssf\game\Game.h"
#include "sssf\gsm\physics\Collision.h"
#include "buggin_out\BugginOutCollisionListener.h"
#include "sssf\gsm\state\GameStateManager.h"
void BugginOutCollisionListener::respondToCollision(Game *game, Collision *collision)
{
	// NOTE FROM THE COLLIDABLE OBJECTS, WHICH ARE IN THE COLLISION,
	// WE CAN CHECK AND SEE ON WHICH SIDE THE COLLISION HAPPENED AND
	// CHANGE SOME APPROPRIATE STATE ACCORDINGLY
    

	if (!collision->isCollisionWithTile())
    {
        CollidableObject *sprite1 = collision->getCO1();
        CollidableObject *sprite2 = collision->getCO2();
        if (sprite1->getCollisionEdge() == BOTTOM_EDGE)
        {
            // ENEMY IS DEAD - WE SHOULD PLAY A DEATH ANIMATION
            // AND MARK IT FOR REMOVAL
        }
        else
        {
            // PLAYER IS DEAD - WE SHOULD PLAY A DEATH ANIMATION
            // AND MARK IT FOR REMOVAL/RESPAWN/RESTART GAME, WHATEVER
            // THE DEMANDS OF THE GAME ARE
             
            if(!sprite1->getIfMonster())
            {
              if(sprite1->getHp() > 0)
                {
                    sprite1->setHp(sprite1->getHp() -10);
                    game->setCurrentLife(sprite1->getHp());
                }
                
                else
                {
                    sprite1->setLives(sprite1->getLives() - 1);
                }
            }

            else if(!sprite2->getIfMonster())
            {
             if(sprite2->getHp() > 0)
                {
                    sprite2->setHp(sprite2->getHp() -10);
                     game->setCurrentLife(sprite2->getHp());
                }
                
                else
                {
                    sprite2->setLives(sprite2->getLives() - 1);
                }

            }

        }
    }

  
}
