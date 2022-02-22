#ifndef GYM_H
#define GYM_H
#include <iostream>
#include "Kind.h"
#include "GymMember.h"

class Gym
{
private:		//declares all of our private members
	std::string mName;		// name of gym
	std::string mLocation;	// location of gym
	Kind mKind;			// type of gym
	bool hasCardio;		// types of features available 
	bool hasWeights;
	bool hasPool;
	bool hasTrack;

public:
	Gym(std::string name,std::string location, Kind kind);	// gym class constructor
	void setFeatures(bool cardio, bool weights, bool pool, bool track);		// function to set the available features of a gym

	bool canWorkoutHere(GymMember& m);		// function to decide wether or not a member matches the type of membership
	bool checkin(GymMember& m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack);		// checks which features a member wants and checks them in if possible


	// getters to check the features of a gym
	bool hasCardioFeatures();
	bool hasWeightsFeatures();
	bool hasPoolFeatures();
	bool hasTrackFeatures();
	// getters for various characteristics of a gym
	Kind getKind();
	std::string getKindAsString();
	std::string getLocation();
	std::string getName();
};
#endif