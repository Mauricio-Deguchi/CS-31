#include <iostream>
#include "Kind.h"
#include "GymMember.h"
using namespace std;


GymMember::GymMember(string name, string accountNumber, Kind kind)
{
	mName = name;
	mAccountNumber = accountNumber;
	mKind = kind;
	mWorkoutCount = 0;
}
int GymMember::workoutsThisMonth()
{
	return(mWorkoutCount);
}
void GymMember::startNewMonth()
{
	mWorkoutCount = 0;
}
void GymMember::newWorkout()
{
	mWorkoutCount++;
}

Kind GymMember::getKind()
{
	return(mKind);
}
string GymMember::getKindAsString()
{
	string kindString;
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
string GymMember::getName()
{
	return(mName);
}
string GymMember::getAccountNumber()
{
	return(mAccountNumber);
}
