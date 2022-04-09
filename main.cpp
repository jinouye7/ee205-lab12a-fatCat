///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   07_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iostream>
#include <exception>

using namespace std;

int main() {
    Weight testCat;
    cout <<"default\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() << endl;
    testCat = Weight(35);
    cout <<"new weight default unit\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() << endl;
    testCat = Weight( Weight::KILO);
    cout <<"default weight new unit\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() << endl;
    testCat = Weight(50, Weight::SLUG);
    cout <<"new weight new unit\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() << endl;
    testCat = Weight(70, 80);
    cout <<"new weight new unit\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() <<", " <<
    testCat.getMaxWeight();

};