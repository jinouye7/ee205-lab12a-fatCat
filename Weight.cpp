///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   07_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
/////////////////////////////////////weight setters///////////////////////////
/// default unit ///
void Weight::setWeight(float newWeight) {
    Weight::weight = newWeight;
}
/// set unit and value ///
void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {
    Weight::weight = newWeight;
    unitOfWeight = weightUnits;
}


////////////////////////////////////weight getters ////////////////////////
float Weight::getWeight() const {
    return weight;
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const {
    return unitOfWeight;
}


///////////////////////////////////constructors //////////////////////////
///default values

Weight::Weight() {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
}
//// weight with a value ///
Weight::Weight(float newWeight) {
    setWeight(newWeight);
    unitOfWeight = POUND;
}

//// weight with UnitOfWeight ///
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight)  {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
}


