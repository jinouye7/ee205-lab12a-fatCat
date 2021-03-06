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
    cout <<"new weight with max\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() <<", " <<
    testCat.getMaxWeight() << endl;


    testCat = Weight(Weight::KILO, 80);
    cout <<"default weight, new unit with max\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() <<", " <<
    testCat.getMaxWeight() << endl;
    testCat = Weight(10, Weight::KILO, 80);
    cout <<"new weight, new unit with max\n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() <<", " <<
    testCat.getMaxWeight() << endl;

    cout << "testing hasMax and weight known: " << endl;
    Weight testCat2;
    cout <<"default values (hasMaxWeight and Weight know should both return false)" << endl;
    cout << "hasMaxWeight: " <<testCat2.hasMaxWeight() << endl;
    cout << "isWeightKnown: " <<testCat2.isWeightKnown() << endl;
    Weight testCat3 = Weight(35, Weight::POUND, 60);
    cout <<"set values (hasMaxWeight and Weight know should both return true)" << endl;
    cout << "hasMaxWeight: " <<testCat3.hasMaxWeight() << endl;
    cout << "isWeightKnown: " <<testCat3.isWeightKnown() << endl;


    cout <<"testing conversion" <<endl;
    /*Weight testCatPOUND = Weight(1, POUND);
    cout <<"weight and unit KILOS: \n" <<testCat.getWeight() << ", " << testCat.getUnitOfWeight() <<", " <<
         testCat.getMaxWeight() << endl;
    */

    cout << "one pound to kilo: " <<Weight::convertWeight(1, Weight::POUND, Weight::KILO)<<endl;
    cout << "one kilo to pound: " <<Weight::convertWeight(1, Weight::KILO, Weight::POUND)<<endl;
    cout << "one pound to slug: " <<Weight::convertWeight(1, Weight::POUND, Weight::SLUG)<<endl;
    cout << "one slug to pound: " <<Weight::convertWeight(1, Weight::SLUG, Weight::POUND)<<endl;
    Weight testCat4 = Weight(1, Weight::POUND, 60);
    cout << "testing unit specific getter for getting 1 set pound weight:" <<testCat4.getWeight(Weight::KILO) << endl;

    cout <<"testing operators" << endl;
    Weight testCat5;
    try {
        testCat5.operator+=(2);
        assert(false);
    } catch (exception const &e) {}
    try {
        testCat5.operator+=(2);
        assert(false);
    } catch (exception const &e) {}

    cout << "unknown weight < return true:" << testCat5.operator<(1) << endl;
    cout << "unknown weight == return false:" << testCat5.operator==(1) << endl;
    cout << "weight 35 pounds < return true:" << testCat3.operator<(36) << endl;
    cout << "weight 35 pounds < return false:" << testCat3.operator<(34) << endl;
    cout << "weight 35 pounds == return true:" << testCat3.operator==(35) << endl;


    cout<<"testing isWeightValid"<<endl;
    cout<<"return false (checkWeight higher than max): " << testCat4.isWeightValid(61) << endl;
    cout<<"return false (checkWeight <= 0): " << testCat4.isWeightValid(0) << endl;
    cout<<"return true (checkWeight in valid range): " << testCat4.isWeightValid(30) << endl;


    testCat.dump();
    cout <<"validate: "<< testCat.validate() <<endl;
    cout <<"validate: "<< testCat2.validate() <<endl;
    cout <<"validate: "<< testCat3.validate() <<endl;
    cout <<"validate: "<< testCat4.validate() <<endl;
    cout <<"validate: "<< testCat5.validate() <<endl;





    ///validation tests

    /// test numeric operators
};