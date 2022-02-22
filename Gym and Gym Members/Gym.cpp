#include <iostream>
#include "Gym.h"
#include "Kind.h"
#include "GymMember.h"



Gym::Gym(std::string name, std::string location, Kind kind)
{		// class constructor
	mName = name;		//sets name
	mLocation = location;		//sets location
	mKind = kind;			// sets type of gym
	hasCardio = false;		// initially, the gym has no features
	hasWeights = false;
	hasPool = false;
	hasTrack = false;
}
void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track)
{	// here, we can set the features of a gym
	hasCardio = cardio;
	hasWeights = weights;
	hasPool = pool;
	hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember& m)
{	// we wanna check if the member's membership is good enough to check into a gym
	bool flag = false;
	Kind membership = m.getKind();		//we wanna get the type of gym memeber we have
	switch (membership)				// depending on the type of memeber, they may of may not be able to access the gym
	{
	case 0:				// other members can only work out at other gyms (my interpretation)
		if (mKind == membership)
		{
			flag = true;
		}break;
	case 1:
	case 2:
	case 3:
		if (mKind <= membership)		// since the memberships are hierarchicaly based on numbers, if your membership is a high enough number, you can workout at the given gym
		{
			flag = true;
		} break;
	default:break;
	}
	return (flag);
}
bool Gym::checkin(GymMember& m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack)
{
	bool flag = false;
	if (canWorkoutHere(m))
	{
		if (((hasCardio == false)&&(wantsCardio == true))||((hasWeights == false) && (wantsWeights == true))|| ((hasPool == false) && (wantsPool == true))|| ((hasTrack == false) && (wantsTrack == true)))
		{
			flag = false;
		}
		else
		{
			m.newWorkout();
			flag = true;
		}
	}
	return (flag);
}

// simple getters for the features of a gym
bool Gym::hasCardioFeatures()
{
	return (hasCardio);
}
bool Gym::hasWeightsFeatures()
{
	return(hasWeights);
}
bool Gym::hasPoolFeatures()
{
	return(hasPool);
}
bool Gym::hasTrackFeatures()
{
	return(hasTrack);
}

// simple getters for the characteristics of a gym
Kind Gym::getKind()
{
	return(mKind);
}
std::string Gym::getKindAsString()
{
	std::string kindString;
	switch (mKind)
	{
	case 0: kindString = "Other"; break;
	case 1: kindString = "Regular"; break;
	case 2: kindString = "Premier"; break;
	case 3: kindString = "Executive"; break;
	default: kindString = "none"; break;
	}
	return(kindString);
}
std::string Gym::getLocation() {
	return(mLocation);
}
std::string Gym::getName()
{
	return(mName);
}

