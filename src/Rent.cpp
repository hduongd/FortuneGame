#include "Board.h"
#include "Rent.h"

Rent::Rent(unsigned single, unsigned monopoly, unsigned one_house,
           unsigned two_houses, unsigned three_houses, unsigned four_houses,
           unsigned hotel)
{
    m_Rents[0] = single;
    m_Rents[1] = monopoly;
    m_Rents[2] = one_house;
    m_Rents[3] = two_houses;
    m_Rents[4] = three_houses;
    m_Rents[5] = four_houses;
    m_Rents[6] = hotel;
}

unsigned* Rent::GetRents()
{
    return m_Rents;
}
