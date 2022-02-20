#include <iostream>
#include "Gym.h"
#include "Kind.h"
#include "GymMember.h"



Gym::Gym(string name, string location, Kind kind)
{
	mName = name;
	mLocation = location;
	mKind = kind;
	hasCardio = false;
	hasWeights = false;
	hasPool = false;
	hasTrack = false;
}
void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track)
{
	hasCardio = cardio;
	hasWeights = weights;
	hasPool = pool;
	hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember& m)
{
	bool flag;
	Kind membership = m.getKind();
	switch (membership)
	{
	case 0: 
		if (mKind == membership)
		{
			flag = true;
		}break;
	case 1:
	case 2:
	case 3:
		if (mKind <= membership)
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

