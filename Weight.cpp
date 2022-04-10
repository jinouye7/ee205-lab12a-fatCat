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
void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    Weight::weight = newWeight;
    unitOfWeight = weightUnits;
}

/// set max weight ///
void Weight::setMaxWeight(float newMaxWeight) {
    maxWeight = newMaxWeight;
}


////////////////////////////////////weight getters ////////////////////////
///weight///
float Weight::getWeight() const noexcept{
    return weight;
}

///unit///
Weight::UnitOfWeight Weight::getUnitOfWeight() const noexcept{
    return unitOfWeight;
}
///max weight///
float Weight::getMaxWeight() const noexcept{
    return maxWeight;
}

/// get weight in a specific unit ///
float Weight::getWeight(UnitOfWeight weighUnits) const noexcept{
    // conversions //
    return weight;
}

///////////////////////////////////constructors //////////////////////////
///default values

Weight::Weight() {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
}
//// new weight default unit ///
Weight::Weight(float newWeight) {
    setWeight(newWeight);
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
}

//// default weight new unit ///
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight)  {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
}

//// new weight new unit ////
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    setWeight(newWeight, newUnitOfWeight);
    maxWeight = UNKNOWN_WEIGHT;
}

//// new weight with maximum ///
Weight::Weight(float newWeight, float newMaxWeight)  {
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}

/// default weight, new unit, max ///
Weight::Weight( Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    maxWeight = newMaxWeight;
}

/// new weight, new unit, new max ///
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight){
    setWeight(newWeight, newUnitOfWeight);
    maxWeight = newMaxWeight;
}


/////////////////static member functions (conversion functions)///////////////////
/// KILO to POUND ///
static float 	fromKilogramToPound (float kilogram) noexcept{
    return kilogram/Weight::KILOS_IN_A_POUND;
}
/// POUND to KILO ///
static float 	fromPoundToKilogram (float pound) noexcept{
    return pound*Weight::KILOS_IN_A_POUND;
}
/// SLUG to POUND ///
static float 	fromSlugToPound (float slug) noexcept{
    return slug/Weight::SLUGS_IN_A_POUND;
}
/// POUND to SLUG ///
static float 	fromPoundToSlug (float pound) noexcept{
    return pound*Weight::SLUGS_IN_A_POUND;
}

/// conversion ///
float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit){
    float commonValue = 0;
    float toWeight;
    // convert to a common unit
    switch( fromUnit ) {
        case POUND                      : commonValue = fromWeight; // No conversion necessary
            break;
        case KILO                       : commonValue = ::fromKilogramToPound( fromWeight );
            break;
        case SLUG                       : commonValue = ::fromSlugToPound( fromWeight );
            break;
        default                         : printf("Unknown fromUnit (no conversion)\n");
            return fromWeight;
    }
    // convert common unit to desired unit
    switch( toUnit ){
        case POUND                      : toWeight = commonValue; // No conversion necessary
            break;
        case KILO                       : toWeight = ::fromPoundToKilogram( commonValue );
            break;
        case SLUG                       : toWeight = ::fromPoundToSlug( commonValue );
            break;
        default                         : printf("Unknown to Unit (no conversion)\n");
            return fromWeight;
    }

    return toWeight;
}

//////////////////////////////////validation//////////////////////////////////////
/// known weight? ///
bool Weight::isWeightKnown() const noexcept{
    if (weight == UNKNOWN_WEIGHT) {
        return false;
    }
        return true;
}

/// known max? ///
bool Weight::hasMaxWeight() const noexcept {
    if (maxWeight == UNKNOWN_WEIGHT) {
        return false;
    }
    return true;
}