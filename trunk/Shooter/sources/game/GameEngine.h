#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#include <manager/Engine.h>
#include <osgUtil/LineSegmentIntersector>

class WeaponManager;
class TargetManager;

//manage the game
class GameEngine : public Engine
{
public:

	GameEngine();
	~GameEngine();

	void frame();
	bool isValid();
	void initialize();

	void onLeftClic(osgUtil::LineSegmentIntersector::Intersection intersection);

private:

	WeaponManager* _weaponManager;
	
	TargetManager * _targetManager;
};


#endif //_GAME_ENGINE_H_
