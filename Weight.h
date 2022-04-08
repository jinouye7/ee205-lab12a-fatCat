///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   07_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H
#define UNKNOWN_WEIGHT -1

#include <string>
#include <ostream>

class Weight {

public:
//////////////////////////////public types ///////////////////////////////////
    enum UnitOfWeight { POUND , KILO , SLUG };

/////////////////////////////public member functions //////////////////////////

/////// Weight setters //////////////
    /// default unit ////
    void setWeight(float newWeight);
    /// set weight and unit ///
    void setWeight(float newWeight, UnitOfWeight weightUnits);

/////// Weight getters //////////////
///weight
    float getWeight() const;
    /// unit
    UnitOfWeight getUnitOfWeight() const;

//////// Weight validation //////////
    /// validate weight ///




//////// Weight constructors /////////
    ///default weight///
    Weight();
    /// weight with value ///
    Weight(float newWeight);

    /// weight with unit ///
    Weight(UnitOfWeight newUnitOfWeight);


private:
//////////////////////////////private attributes//////////////////////////////
    float weight;
    float maxWeight;
    enum UnitOfWeight unitOfWeight = POUND;


};



#endif //EE205_LAB12A_FATCAT_WEIGHT_H
