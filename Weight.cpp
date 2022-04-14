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
#define FORMAT_LINE( className, member ) std::cout \
                                      << std::setw(8) << (className) \
                                      << std::setw(20) << (member)   \
                                      << std::setw(52)  /* (data) */
/////////////////////////////////////weight setters///////////////////////////
/// default unit ///
void Weight::setWeight(float newWeight) {
    if (bIsKnown == true && newWeight == -1) {
        throw std::invalid_argument("you cannot 'unknow' a weight");
    }
    if(newWeight <= 0) {
        throw std::invalid_argument("setWeight(float newWeight) Weight can never be <=0\n");
    }
    weight = newWeight;
    bIsKnown = true;

}
/// set unit and value ///
void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    if (bIsKnown == true && newWeight == -1) {
        throw std::invalid_argument("you cannot 'unknow' a weight");
    }
    if(newWeight <= 0) {
        throw std::invalid_argument("Weight can never be <=0\n");
    }
    weight = newWeight;
    bIsKnown = true;
    unitOfWeight = weightUnits;
}

/// set max weight ///
void Weight::setMaxWeight(float newMaxWeight) {
    if (bHasMax == true) {
        throw std::invalid_argument("Max Weight cannot be changed once set");
    }
    maxWeight = newMaxWeight;
    bHasMax = true;
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
    float convertedWeight = convertWeight(Weight::getWeight(), Weight::getUnitOfWeight(), weighUnits);
    return convertedWeight;
}

///////////////////////////////////constructors //////////////////////////
///default values

Weight::Weight() {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    bIsKnown = false;
    bHasMax = false;
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
    setMaxWeight(newMaxWeight);
}

/// new weight, new unit, new max ///
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight){
    setWeight(newWeight, newUnitOfWeight);
    setMaxWeight(newMaxWeight);
}


/////////////////public member functions /////////////////////////////////////////


//// numeric operators////

bool Weight::operator==(const Weight &rhs_Weight) const {
    /// Remember to convert the two weight's units into a common unit!
    /// Treat unknown weights as 0 (so we can sort them without dealing
    /// with exceptions)
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

bool Weight::operator+=(float rhs_addToWeight){
    if (bIsKnown) {
        return weight += rhs_addToWeight;
    }
    else{
        throw std::out_of_range("you cannot add to an unknown weight");
    }
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

/// is weight valid ///
bool Weight::isWeightValid (float checkWeight) const noexcept{
    if(bHasMax){
        if(checkWeight > maxWeight) {
            return false;
        }
    }
    if(checkWeight <= 0){
        return false;
    }
    return true;

}

/// validate ///
bool Weight::validate() {
    if(isWeightKnown()!= bIsKnown){
        printf("weight bools disagree");
        return false;
    }
    if(hasMaxWeight() != bHasMax) {
        printf("max bools disagree");
        return false;
    }
    if(bIsKnown){
        if(weight <= 0){
            printf("known weight cannot be <=0");
            return false;
        }
    }
    if(bHasMax){
        if(weight > maxWeight) {
            printf("weight cannot be greater than max");
            return false;
        }
    }
    return true;

}

/////////////////////////////////dump/////////////////////////////////////////////
void Weight::dump()	const{
    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl ;
    std::cout << std::setfill( ' ' ) ;
    std::cout << std::left ;
    std::cout << std::boolalpha ;
    FORMAT_LINE( "Weight", "isKnown" )         <<isWeightKnown()    << std::endl;
    FORMAT_LINE( "Weight", "weight" )       << weight << std::endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" )        << getUnitOfWeight()   << std::endl ;
    FORMAT_LINE( "Weight", "hasMax" )      << hasMaxWeight()   << std::endl ;
    FORMAT_LINE( "Weight", "maxWeight" )       << getMaxWeight() << std::endl ;
}

/////////////////////////// Stream Output Operator ///////////////////////////////
std::ostream &operator<<(std::ostream &os, const Weight::UnitOfWeight originalStream) {
    switch( originalStream ) {
        case Weight::POUND: return os << "Pound" ;
        case Weight::KILO: return os << "Kilo" ;
        case Weight::SLUG: return os << "Slug" ;
        default:
            throw std::out_of_range( "The unit can’t be mapped to a string" );
    }
}


