/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

// declare your test functions here
void test_Person();
void test_Elevator();
void test_Floor();
void test_move();

void start_tests() {
    // call your test functions here
    //test_Person();
    //test_Elevator();
    //test_Floor();
    test_move();
}

// write test functions here
void test_Person() {
    //test constructor
    Person Danny("7f4t8a3");
    cout << Danny.getTurn() << " " << Danny.getCurrentFloor() << " " << Danny.getTargetFloor() << " " << Danny.getAngerLevel() << endl;
    
    //test print
    Danny.print(cout);
    //test tick
    cout << Danny.tick(10) << " " << Danny.getAngerLevel() << endl;
    Danny.tick(5);
    Danny.tick(5);
    Danny.tick(5);
    Danny.tick(5);
    Danny.tick(5);
    Danny.tick(5);
    cout << Danny.tick(5) << endl;
}

void test_Elevator() {
    // test tick and serviceRequest
    Elevator elevator;
    Elevator elevator2;
    elevator.print(cout);
    cout << endl;
    elevator.serviceRequest(5);
    elevator.print(cout);
    cout << endl;
    elevator.tick(1);
    elevator.print(cout);
    cout << endl;
    elevator.tick(2);
    elevator.print(cout);
    cout << endl;
    elevator.tick(3);
    elevator.print(cout);
    cout << endl;
    elevator.serviceRequest(1);
    elevator.tick(4);
    elevator.print(cout);
    elevator2.tick(1);
    elevator2.print(cout);
    cout << endl;
}

void test_Floor() {
    //test remove people and add person
    Floor floor;
    Person Danny("7f4t0a3");
    Person Eliana("7f4t2a9");
    Person Justin("7f4t1a3");
    Person Eliza("7f4t6a3");
    floor.addPerson(Danny, -4);
    floor.addPerson(Eliana, -2);
    floor.addPerson(Justin, -3);
    floor.addPerson(Eliza, 2);
    floor.printFloorPickupMenu(cout);
    int arr[] = {0,2};
    floor.removePeople(arr, 2);
    floor.printFloorPickupMenu(cout);
    floor.addPerson(Danny, 2);
    floor.addPerson(Justin, -3);
    floor.printFloorPickupMenu(cout);
    floor.tick(10);
    floor.printFloorPickupMenu(cout);
    cout << endl;
    cout << floor.getHasUpRequest() << endl;
    int arr1[] = {0};
    floor.removePeople(arr1, 1);
    floor.printFloorPickupMenu(cout);
    cout << endl;
    cout << floor.getHasUpRequest() << endl;
}
void test_move() {
    //testing constructor
    Move move1("e1f4");
    cout << move1.getTargetFloor() << endl;
    cout << move1.getElevatorId() << endl;
    cout << move1.isPassMove() << endl;
    cout << move1.isQuitMove() << endl;
    cout << move1.isSaveMove() << endl;
    cout << move1.isPickupMove() << endl;
    Move move2("e1p");
    cout << "Next Move" << endl << endl;
    cout << move2.getTargetFloor() << endl;
    cout << move2.getElevatorId() << endl;
    cout << move2.isPassMove() << endl;
    cout << move2.isQuitMove() << endl;
    cout << move2.isSaveMove() << endl;
    cout << move2.isPickupMove() << endl;
    Move move3("");
    cout << "Next Move" << endl << endl;
    cout << move3.getTargetFloor() << endl;
    cout << move3.getElevatorId() << endl;
    cout << move3.isPassMove() << endl;
    cout << move3.isQuitMove() << endl;
    cout << move3.isSaveMove() << endl;
    cout << move3.isPickupMove() << endl;
    Move move4("s");
    cout << "Next Move" << endl << endl;
    cout << move4.getTargetFloor() << endl;
    cout << move4.getElevatorId() << endl;
    cout << move4.isPassMove() << endl;
    cout << move4.isQuitMove() << endl;
    cout << move4.isSaveMove() << endl;
    cout << move4.isPickupMove() << endl;
    Move move5("e4f4");
    cout << "Next Move" << endl << endl;
    cout << move5.getTargetFloor() << endl;
    cout << move5.getElevatorId() << endl;
    cout << move5.isPassMove() << endl;
    cout << move5.isQuitMove() << endl;
    cout << move5.isSaveMove() << endl;
    cout << move5.isPickupMove() << endl;
    //test isValidMove
    cout << endl << endl << endl;
    Elevator elevators[NUM_ELEVATORS];
    cout << move1.isValidMove(elevators) << endl;
    cout << move5.isValidMove(elevators) << endl;
    Move move6("e1f11");
    cout << move6.isValidMove(elevators) << endl;
    // test setPeopleToPickUp not right yet
    Floor floor;
    Person Danny("7f4t0a3");
    Person Eliana("7f4t2a9");
    Person Justin("7f4t1a3");
    Person Eliza("7f4t6a3");
    floor.addPerson(Eliana, 2);
    floor.addPerson(Danny, 4);
    floor.addPerson(Justin, 3);
    floor.addPerson(Eliza, 4);
    floor.printFloorPickupMenu(cout);
    move2.setPeopleToPickup("0123", 4, floor);
    floor.printFloorPickupMenu(cout);
}
