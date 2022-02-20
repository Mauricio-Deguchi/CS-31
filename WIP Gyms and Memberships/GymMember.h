#ifndef GYMMEMBER_H
#define GYMMEMBER_H
#include <iostream>
using namespace std;
#include "Kind.h"
#include <iostream>

class GymMember
{
private:
	string mName;
	string mAccountNumber;
	Kind mKind;
	int mWorkoutCount;
public:
	GymMember(std::string name, std::string accountNumber, Kind kind);
	int workoutsThisMonth();
	void startNewMonth();
	void newWorkout();

	Kind getKind();
	string getKindAsString();
	string getName();
	string getAccountNumber();
};
#endif