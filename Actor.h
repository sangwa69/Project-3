#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject
{
public:
	Actor(StudentWorld* world, int imageID, double startX, double startY, int startDirection, int depth) :
		GraphObject(imageID, startX, startY, startDirection, depth),
		m_world(world) {};

	virtual void doSomething() = 0;
	StudentWorld* getWorld() { return m_world; };
	virtual bool blocksMovement() = 0;

private:
	StudentWorld* m_world;
};

class AliveActor : public Actor 
{
public:
	AliveActor(StudentWorld* world, int imageID, double startX, double startY, int startDirection) :
		Actor(world, imageID, startX, startY, startDirection, 0),
		alive(true) {};

	virtual void die() { alive = false; return; };
	bool isAlive() { return alive; };

private:
	bool alive;
};

class Peach : public AliveActor {
public:
	Peach(StudentWorld* world, int level_x, int level_y) :
		AliveActor(world, IID_PEACH, SPRITE_WIDTH* level_x, SPRITE_HEIGHT* level_y, right),
		infected(false),
		mushrooms(0), stars(0), flowers(0) {};

	virtual void doSomething();
	virtual bool blocksMovement() { return true; };
private:
	void goTo(double x, double y);
	bool infected;
	int mushrooms, stars, flowers, infectionCount;
};

class Block : public Actor {
public:
	Block(StudentWorld* world, double level_x, double level_y) :
		Actor(world, IID_BLOCK, SPRITE_WIDTH* level_x, SPRITE_HEIGHT* level_y, right, 0) {};

	virtual void doSomething() { return; };
	virtual bool blocksMovement() { return true; };
private:
};
#endif // ACTOR_H_
