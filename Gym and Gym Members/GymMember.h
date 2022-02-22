#ifndef GYMMEMBER_H
#define GYMMEMBER_H
#include <iostream>
#include "Kind.h"


class GymMember
{
private:			// this will establish all the private members
	std::string mName;		// stores the name of the gym member
	std::string mAccountNumber;		// stores the account number of the gym member
	Kind mKind;						// stores the type of memebership
	int mWorkoutCount;				// stores the number of workouts
public:			// establishes all of the public members
	GymMember(std::string name, std::string accountNumber, Kind kind);			// constructor for the a value of type gymMember
	int workoutsThisMonth();		// declares the function to return the number of workouts
	void startNewMonth();		// declares the function to start a new month and reset the counter
	void newWorkout();		// declares the function to raise the workout counter

	Kind getKind();		// declares the function to return the type of membership
	std::string getKindAsString();		// declares the function the obtain the type of memebership as a string
	std::string getName();		// declares the function to obtain the name of the member
	std::string getAccountNumber();		// declares the function return the account number
};
#endif