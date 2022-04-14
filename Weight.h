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
    float getWeight() const noexcept;
    /// unit
    UnitOfWeight getUnitOfWeight() const noexcept;
    /// max weight
    float getMaxWeight() const noexcept;
    /// get weight in a particular unit ///
    float getWeight(UnitOfWeight weighUnits) const noexcept;

//////// Weight validation //////////
    /// known weight? ///
    bool isWeightKnown() const noexcept;

    /// known max? ///
    bool hasMaxWeight() const noexcept;

    /// is weight valid  ///
    bool 	isWeightValid (float checkWeight) const noexcept;

    /// validate ///
    bool validate();

////////// dump /////////////////////
    void dump()	const;

////////// numeric operations //////

    bool operator==(const Weight &rhs_Weight) const;

    bool operator<(const Weight &rhs_Weight) const;

    bool operator+=(float rhs_addToWeight);



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
/// KILO to POUND ///
    static float 	fromKilogramToPound (float kilogram) noexcept;
/// POUND to KILO ///
    static float 	fromPoundToKilogram (float pound) noexcept;
/// SLUG to POUND ///
    static float 	fromSlugToPound (float slug) noexcept;
/// POUND to SLUG ///
    static float 	fromPoundToSlug (float pound) noexcept;

/// conversion ///
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit);

    friend std::ostream &operator<<(std::ostream &os, const Weight::UnitOfWeight);






///////////////////////////static public attributes//////////////////////////

    constexpr static const float 	UNKNOWN_WEIGHT = -1;
    constexpr static const float 	KILOS_IN_A_POUND = 0.453592;
    constexpr static const float 	SLUGS_IN_A_POUND = 0.031081;

    /*
    const std::string POUND_LABEL = "Pound";
    const std::string 	KILO_LABEL = "Kilo";
    const std::string 	SLUG_LABEL = "Slug";
    */
private:
//////////////////////////////Private Member Functions //////////////////////
    void setMaxWeight(float newMaxWeight);


//////////////////////////////private attributes//////////////////////////////
    float weight = UNKNOWN_WEIGHT;
    float maxWeight = UNKNOWN_WEIGHT;
    enum UnitOfWeight unitOfWeight = POUND;
    bool bIsKnown = false;
    bool bHasMax = false;


};



#endif //EE205_LAB12A_FATCAT_WEIGHT_H
