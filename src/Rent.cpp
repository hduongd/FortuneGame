#include "Rent.h"

Rent::Rent(unsigned single, unsigned one_house, unsigned two_houses,
           unsigned three_houses, unsigned four_houses, unsigned hotel)
{
    m_Rents[0] = single;
    m_Rents[1] = one_house;
    m_Rents[2] = two_houses;
    m_Rents[3] = three_houses;
    m_Rents[4] = four_houses;
    m_Rents[5] = hotel;
}
