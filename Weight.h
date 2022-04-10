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
//#define UNKNOWN_WEIGHT -1

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
    /// weight
    float getWeight() const;
    /// unit
    UnitOfWeight getUnitOfWeight() const;
    /// max weight
    float getMaxWeight() const;

//////// Weight validation //////////
    /// known weight? ///
    bool isWeightKnown() const noexcept;

    /// known max? ///
    bool hasMaxWeight() const noexcept;

    /// validate weight ///




//////// Weight constructors /////////
    ///default weight///
    Weight();
    /// new weight default unit ///
    Weight(float newWeight);

    /// default weight new unit ///
    Weight(UnitOfWeight newUnitOfWeight);

    /// new weight new unit ///
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);

    /// new weight with max ///
    Weight(float weight, float maxWeight);

    /// default weight, new unit, max ///
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);

    /// new weight, new unit, new max ///
    Weight(float weight, UnitOfWeight unitOfWeight, float maxWeight);


////////////////////////////// static public member functions ////////////////


///////////////////////////static public attributes//////////////////////////

    constexpr static const float 	UNKNOWN_WEIGHT = -1;
    constexpr static const float 	KILOS_IN_A_POUND = 0.453592;
    constexpr static const float 	SLUGS_IN_A_POUND = 0.031081;


private:
//////////////////////////////private attributes//////////////////////////////
    float weight;
    float maxWeight;
    enum UnitOfWeight unitOfWeight = POUND;


};



#endif //EE205_LAB12A_FATCAT_WEIGHT_H
