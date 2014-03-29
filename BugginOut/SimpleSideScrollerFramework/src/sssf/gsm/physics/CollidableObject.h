#pragma once
#include "sssf_VS\stdafx.h"
#include "sssf\gsm\physics\AABB.h"
#include "sssf\gsm\physics\PhysicalProperties.h"

// THESE ARE THE SWEEP AND PRUNE ORDERINGS
const unsigned int LEFT_EDGE = 0;
const unsigned int RIGHT_EDGE = 1;
const unsigned int TOP_EDGE = 2;
const unsigned int BOTTOM_EDGE = 3;

class CollidableObject
{
protected:
	AABB boundingVolume;
	bool currentlyCollidable;

    //ADDED BY PAULO BECAUSE THE CODE DOESNT KNOW HOW TO DEAL WITH A DIFFERENT TYPE OTHER THAN A TILE
    bool isTile;
    bool isSprite;
	int hp;
    int lives;
    bool isAMonster;
    
    AABB sweptShape;
	unsigned int sweepAndPruneIndices[4];
	PhysicalProperties pp;
	bool onTileThisFrame;
	bool onTileLastFrame;
    int numberOfJumps  ;
	unsigned int collisionEdge;

public:
	CollidableObject()	{numberOfJumps = 1;hp=100;}
	~CollidableObject()	{}

	// CollidableObject.cpp METHODS
	void updateSweptShape(float percentageOfFrameTimeRemaining);

	// INLINED METHODS
	bool				isCurrentlyCollidable()		{ return currentlyCollidable;	}
	bool				isOnTileThisFrame()			{ return onTileThisFrame;		}
	bool				wasOnTileLastFrame()		{ return onTileLastFrame;		}
	AABB*				getBoundingVolume()			{ return &boundingVolume;		}
	AABB*				getSweptShape()				{ return &sweptShape;			}
	PhysicalProperties* getPhysicalProperties()		{ return &pp;					}
	unsigned int		getCollisionEdge()			{ return collisionEdge;			}
    bool                getIfMonster()      {return isAMonster;}
    int getHp()   {return hp;}
    int getLives()   {return lives;}
//ADDED BY PAULO BECAUSE THE CODE DOESNT KNOW HOW TO DEAL WITH A DIFFERENT TYPE OTHER THAN A TILE
    bool                isItATile()                    { return isTile;                }
    bool                isItASprite()                    { return isSprite;                }

    void setHp(int num) {hp = num;}
    void setLives(int num) {lives = num;}
    void setIfMonster(bool b ) {isAMonster = b;}
    void                setIfIsTile(bool initIsTile ) {isTile = initIsTile;}
    void                setIfIsSprite(bool initIsSprite ) {isSprite = initIsSprite;}
	void				setCollisionEdge(unsigned int initCollisionEdge)
	{	collisionEdge = initCollisionEdge; }
	unsigned int		getSweepAndPruneIndex(unsigned int sweepAndPruneOrdering)		
	{ return sweepAndPruneIndices[sweepAndPruneOrdering];	}
	void				setSweepAndPruneIndex(unsigned int sweepAndPruneOrdering, unsigned int index)
	{ sweepAndPruneIndices[sweepAndPruneOrdering] = index;  }

	void setCurrentlyCollidable(bool initCurrentlyCollidable)
	{	currentlyCollidable = initCurrentlyCollidable; }
   
    void setNumberOfJumps(int number) { numberOfJumps = number;}
    int  getNumberOfJumps() { return numberOfJumps;}
    
    
    void setOnTileThisFrame(bool initOnTileThisFrame)
	{	onTileThisFrame = initOnTileThisFrame; }
	void setOnTileLastFrame(bool initOnTileLastFrame)
	{	onTileLastFrame = initOnTileLastFrame; }

	void advanceOnTileStatus()
	{
		onTileLastFrame = onTileThisFrame;
		onTileThisFrame = false;
	}

};
