#pragma once

class Rent
{
public:
    Rent(unsigned single, unsigned monopoly, unsigned one_house,
         unsigned two_houses, unsigned three_houses, unsigned four_houses,
         unsigned hotel);
    unsigned* GetRents();
private:
    unsigned m_Rents[RENT_SLOTS];
};
