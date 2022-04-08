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
    cout << testCat.getWeight() << endl;
    cout << testCat.getUnitOfWeight() << endl;
    testCat = Weight(35);
    cout << testCat.getWeight() << endl;
    cout << testCat.getUnitOfWeight() << endl;
    testCat = Weight( Weight::KILO);
    cout << testCat.getWeight() << endl;
    cout << testCat.getUnitOfWeight() << endl;
};