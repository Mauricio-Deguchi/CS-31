#include <iostream>
#include "Kind.h"
#include "GymMember.h"


GymMember::GymMember(std::string name, std::string accountNumber, Kind kind)
{// this is the constructor for the class
	mName = name;		// we need to store a name
	mAccountNumber = accountNumber;		// we need to establish an account number
	mKind = kind;					// we need to store the type of membership
	mWorkoutCount = 0;				// initially, the member will not have had any workout sessions	
}
int GymMember::workoutsThisMonth()
{	//getter for the number of workouts
	return(mWorkoutCount);
}
void GymMember::startNewMonth()
{	//resets the workut counter, setter
	mWorkoutCount = 0;
}
void GymMember::newWorkout()
{//setter for the workout counter, increments by 1
	mWorkoutCount++;
}

Kind GymMember::getKind()
{	//getter for type kind
	return(mKind);
}
std::string GymMember::getKindAsString()
{	// depending on the value of kind, we know from our kind.h enum what value corresponds to which membership
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
std::string GymMember::getName()
{	//getter for the members name
	return(mName);
}
std::string GymMember::getAccountNumber()
{	//getter for the members account number
	return(mAccountNumber);
}
