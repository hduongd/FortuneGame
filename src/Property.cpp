#include "Property.h"

Property::Property(const std::string& name, unsigned int action, unsigned int cost,
                   unsigned int* rents, unsigned int houses, unsigned int house_cost):
    Tile(name, action),
    m_Cost(cost),
    m_Houses(houses),
    m_HouseCost(house_cost)
{
    for (int i = 0; i < 7; i++)
    {
        m_Rent[i] = rents[i];
    }
}

unsigned int Property::GetNumberHouses() const
{
    return m_Houses;
}

unsigned int Property::GetCost() const
{
    return m_Cost;
}

bool Property::IsMortgaged() const
{
    return m_IsMortgaged;
}

const unsigned int* Property::GetRentArray() const
{
    return m_Rent;
}
