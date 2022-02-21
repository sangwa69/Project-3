#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include "Level.h"
#include <string>
#include <vector>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    m_peach = nullptr;
    actors.clear();
}

int StudentWorld::init()
{

	Level lev(assetPath());
	string level_file = "level01.txt";
	Level::LoadResult result = lev.loadLevel(level_file);
	if (result == Level::load_fail_file_not_found)
		cerr << "Could not find level01.txt data file" << endl;
	else if (result == Level::load_fail_bad_format)
		cerr << "level01.txt is improperly formatted" << endl;
	else if (result == Level::load_success)
	{
		cerr << "Successfully loaded level" << endl;
		Level::GridEntry ge;
		ge = lev.getContentsOf(5, 10); // x=5, y=10
		switch (ge)
		{
		case Level::empty:
			cout << "Location 5,10 is empty" << endl;
			break;
		case Level::koopa:
			cout << "Location 5,10 starts with a koopa" << endl;
			break;
		case Level::goomba:
			cout << "Location 5,10 starts with a goomba" << endl;
				break;
		case Level::peach:
			cout << "Location 5,10 is where Peach starts" << endl;
			break;
		case Level::flag:
			cout << "Location 5,10 is where a flag is" << endl;
			break;
		case Level::block:
			cout << "Location 5,10 holds a regular block" << endl;
			break;
		case Level::star_goodie_block:
			cout << "Location 5,10 has a star goodie block" << endl;
				break;
			// etc…
		}
	}
	return GWSTATUS_CONTINUE_GAME;

}



int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    
	//decLives();
	m_peach->doSomething();
	for (Actor* a : actors) {
		a->doSomething();
	}
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
	for (Actor* a : actors)
		delete a;
	actors.clear();
	delete m_peach;
	m_peach = nullptr;
}


StudentWorld::~StudentWorld() {
	cleanUp();
}

bool StudentWorld::isValidPos(double x, double y) {
	for (auto a : actors)
		if (x + SPRITE_WIDTH - 1 > a->getX() && x < a->getX() + SPRITE_WIDTH - 1)
			if (y + SPRITE_HEIGHT - 1 > a->getY() && y < a->getY() + SPRITE_HEIGHT - 1)
				return false;
	return true;
}
