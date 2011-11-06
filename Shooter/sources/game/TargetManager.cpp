#include <game/TargetManager.h>


TargetManager::TargetManager()
{}

TargetManager::~TargetManager()
{
}


TargetManager::ShootResult TargetManager::Intersect(osgUtil::LineSegmentIntersector::Intersection intersection)
{
	std::string pattern = "Target_";

	//get the intersection nodepath and get the group
	osg::Group * target = NULL;

	int i = intersection.nodePath.size()-1;
	while(!target && i>=0)
	{
		target = intersection.nodePath.at(i)->asGroup();
		
		if(target)
			if(target->getName().find(pattern) == std::string::npos) //contains the pattern mean it is a target
				target = NULL; //no pattern, not a valid target
		
		i--;
	}
	

	//no valid intersection
	if(i<0)
		return TARGET_MISSED;
	
	if(!target)
		return TARGET_MISSED;
	else
		return TARGET_REACHED;

	//first check if the intersected node is a target

	//secondly animate the target
}