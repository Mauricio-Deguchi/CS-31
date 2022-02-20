#include <iostream>
#include <string>
#include <cassert>

#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

using namespace std;

int main()
{
    GymMember premier("Me", "11111", PREMIER);
    premier.startNewMonth();
    Gym regu("ReguGym", "San Diego", REGULAR);
    regu.setFeatures(true, true, true, true); assert(regu.checkin(premier, false, false, true, false) == true);
    assert(premier.workoutsThisMonth() == 1);
    return(0);
}

