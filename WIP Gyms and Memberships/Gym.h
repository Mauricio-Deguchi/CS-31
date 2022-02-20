#ifndef GYM_H
#define GYM_H
#include <iostream>
using namespace std;
#include "Kind.h"
#include "GymMember.h"

class Gym
{
private:
	string mName;
	string mLocation;
	Kind mKind;
	bool hasCardio;
	bool hasWeights;
	bool hasPool;
	bool hasTrack;

public:
	Gym(string name,string location, Kind kind);
	void setFeatures(bool cardio, bool weights, bool pool, bool track);

	bool canWorkoutHere(GymMember& m);
	bool checkin(GymMember& m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack);

	bool hasCardioFeatures();
	bool hasWeightsFeatures();
	bool hasPoolFeatures();
	bool hasTrackFeatures();

	Kind getKind();
	string getKindAsString();
	string getLocation();
	string getName();
};
#endif