#pragma once

#include "Property.h"

class Rent
{
public:
    Rent(unsigned single, unsigned one_house, unsigned two_houses,
         unsigned three_houses, unsigned four_houses, unsigned hotel);
    unsigned m_Rents[Property::RENT_SLOTS];
};
