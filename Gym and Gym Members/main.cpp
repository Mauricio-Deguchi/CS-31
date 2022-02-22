#include <iostream>
#include <string>
#include <cassert>
#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

int main()
{
    // Establishing our test variable
    GymMember regular("good", "11111", REGULAR);
    GymMember premier("great", "22222", PREMIER);
    GymMember executive("excellent", "33333", EXECUTIVE);
    Gym regu("ReguGym", "San Diego", REGULAR);
    Gym prem("PremGym", "Santa Barbara", PREMIER);
    Gym exec("ExecGym", "Los Angeles", EXECUTIVE);
    regu.setFeatures(false , false, false, true);
    prem.setFeatures(false, false, true, true);
    exec.setFeatures(true, true, true, true);

    //  testing the checkin process
    assert(regu.checkin(regular, false, false, false, false) == true);
    assert(regu.checkin(regular, false, false, false, true) == true);
    assert(regu.checkin(regular, false, false, true, true) == false);
    assert(prem.checkin(regular, false, false, false, false) == false);
    assert(exec.checkin(regular, false, false, false, false) == false);
    assert(regular.workoutsThisMonth() == 2);
    regular.startNewMonth();

    assert(regu.checkin(premier, false, false, false, true) == true);
    assert(prem.checkin(premier, false, false, true, false) == true);
    assert(exec.checkin(premier, false, false, true, false) == false);
    assert(prem.checkin(premier, false, false, true, true) == true);
    assert(regu.checkin(premier, true, false, true, false) == false);
    assert(prem.checkin(premier, true, false, true, false) == false);
    assert(premier.workoutsThisMonth() == 3);
    premier.startNewMonth();

    assert(regu.checkin(executive, false, false, false, true) == true);
    assert(prem.checkin(executive, false, false, true, false) == true);
    assert(exec.checkin(executive, false, false, true, false) == true);
    assert(prem.checkin(executive, false, false, true, true) == true);
    assert(regu.checkin(executive, true, false, true, false) == false);
    assert(prem.checkin(executive, true, false, true, false) == false);
    assert(exec.checkin(executive, false, false, false, false) == true);
    assert(executive.workoutsThisMonth() == 5);
    executive.startNewMonth();


    // testing the workout counter
    regular.newWorkout();
    assert(regular.workoutsThisMonth() == 1);
    regular.newWorkout();
    assert(regular.workoutsThisMonth() == 2);
    regular.startNewMonth();
    assert(regular.workoutsThisMonth() == 0);

    premier.newWorkout();
    assert(premier.workoutsThisMonth() == 1);
    premier.newWorkout();
    assert(premier.workoutsThisMonth() == 2);
    premier.startNewMonth();
    assert(premier.workoutsThisMonth() == 0);

    executive.newWorkout();
    assert(executive.workoutsThisMonth() == 1);
    executive.newWorkout();
    assert(executive.workoutsThisMonth() == 2);
    executive.startNewMonth();
    assert(executive.workoutsThisMonth() == 0);

    // getting kind for membership
    assert(regular.getKind() == 1);
    assert(premier.getKind() == 2);
    assert(executive.getKind() == 3);
    // getting kind for gym
    assert(regu.getKind() == 1);
    assert(prem.getKind() == 2);
    assert(exec.getKind() == 3);

    //getting kind as string for membership
    assert(regular.getKindAsString() == "Regular");
    assert(premier.getKindAsString() == "Premier");
    assert(executive.getKindAsString() == "Executive");
    //getting kind as string for gym
    assert(regu.getKindAsString() == "Regular");
    assert(prem.getKindAsString() == "Premier");
    assert(exec.getKindAsString() == "Executive");

    // get name for membership
    assert(regular.getName() == "good");
    assert(premier.getName() == "great");
    assert(executive.getName() == "excellent");
    // get name for gym
    assert(regu.getName() == "ReguGym");
    assert(prem.getName() == "PremGym");
    assert(exec.getName() == "ExecGym");

    //getting the account number
    assert(regular.getAccountNumber() == "11111");
    assert(premier.getAccountNumber() == "22222");
    assert(executive.getAccountNumber() == "33333");

    //getting the location
    assert(regu.getLocation() == "San Diego");
    assert(prem.getLocation() == "Santa Barbara");
    assert(exec.getLocation() == "Los Angeles");

    // Testing features
    assert(regu.hasCardioFeatures() == false);
    assert(regu.hasWeightsFeatures() == false);
    assert(regu.hasPoolFeatures() == false);
    assert(regu.hasTrackFeatures() == true);

    assert(prem.hasCardioFeatures() == false);
    assert(prem.hasWeightsFeatures() == false);
    assert(prem.hasPoolFeatures() == true);
    assert(prem.hasTrackFeatures() == true);

    assert(exec.hasCardioFeatures() == true);
    assert(exec.hasWeightsFeatures() == true);
    assert(exec.hasPoolFeatures() == true);
    assert(exec.hasTrackFeatures() == true);

    // switching features
    regu.setFeatures(false, true, true, false);
    assert(regu.hasCardioFeatures() == false);
    assert(regu.hasWeightsFeatures() == true);
    assert(regu.hasPoolFeatures() == true);
    assert(regu.hasTrackFeatures() == false);



    std::cout << "All Tests passed!" << std::endl;
    return(0);
}

