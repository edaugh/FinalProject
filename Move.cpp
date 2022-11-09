/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Danny Rudnick Eliana Daugherty Eliza Taylor Justin Esdale
 * dannyrud edaugh elizatay jtesdale
 *
 * Final Project - Elevators
 */
 
#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    stringstream ss(commandString);
    char x;
    ss >> x;
    if(commandString == "") {
        isPass = true;
    }
    else if(toupper(x) == 'Q') {
        isQuit = true;
    }
    else if (toupper(x) == 'S') {
        isSave = true;
    }
    else if (x == 'e') {
        ss >> elevatorId;
        ss >> x;
        if(x == 'p'){
            isPickup = true;
        } else {
            ss >> targetFloor;
        }
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    if(isPass || isQuit || isSave) {
        return true;
    }
    if(elevatorId >= 0 && elevatorId < NUM_ELEVATORS && !(elevators[elevatorId].isServicing())) {
        if(isPickup) {
            return true;
        } else if (targetFloor >= 0 && targetFloor < NUM_FLOORS && targetFloor != elevators[elevatorId].getCurrentFloor()){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    char num;
    int anger;
    int maxNum = 0;
    stringstream ss(pickupList);
    while(ss >> num){
        num = num - '0';
        peopleToPickup[numPeopleToPickup] = num;
        numPeopleToPickup++;
        anger = pickupFloor.getPersonByIndex(num).getAngerLevel();
        totalSatisfaction += (MAX_ANGER - anger);
        int persTargetFloor = pickupFloor.getPersonByIndex(num).getTargetFloor();
        if((abs(persTargetFloor - currentFloor)) > maxNum) {
            maxNum = abs(persTargetFloor - currentFloor);
            targetFloor = persTargetFloor;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
