/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Floor.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Danny Rudnick Eliana Daugherty Eliza Taylor Justin Esdale
 * dannyrud edaugh elizatay jtesdale
 *
 * Final Project - Elevators
 */


#include "Floor.h"

using namespace std;

int Floor::tick(int currentTime) {
    int numExploded = 0;
    int indexExploaded[MAX_PEOPLE_PER_FLOOR];
    for(int i = 0; i < numPeople; i++) {
        if(people[i].tick(currentTime)){
            indexExploaded[numExploded] = i;
            numExploded++;
        }
    }
    removePeople(indexExploaded, numExploded);
    return numExploded;
}

void Floor::addPerson(Person newPerson, int request) {
    if(numPeople < MAX_PEOPLE_PER_FLOOR) {
        people[numPeople] = newPerson;
        numPeople++;
    }
    if(request > 0) {
        setHasUpRequest(true);
    }
    if(request < 0) {
        setHasDownRequest(true);
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    Person tempArray[numPeople];
    int numCop = 0;
    bool keep = true;
    for(int i = 0; i  < numPeople; i++) {
        keep = true;
        for(int j = 0; j < numPeopleToRemove; j++) {
            if(i == indicesToRemove[j]){
                keep = false;
            }
        }
            if(keep) {
                tempArray[numCop] = people[i];
                numCop++;
            }
    }
    
    for(int i = 0; i < numCop; i++) {
        people[i] = tempArray[i];
    }
    numPeople = numCop;
    resetRequests();
}

void Floor::resetRequests() {
    hasUpRequest = false;
    hasDownRequest = false;
    for(int i = 0; i < numPeople; i++) {
        if(people[i].getCurrentFloor() < people[i].getTargetFloor()) {
            hasUpRequest = true;
        }
        else if(people[i].getCurrentFloor() > people[i].getTargetFloor()) {
            hasDownRequest = true;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i){
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " O   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "-|-  ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " |   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "/ \\  ";
	}
	outs << endl << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << i << "   ";
	}
	outs << endl << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
	return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
