#include "Property.h"
#include "Rent.h"
#include <iostream>

Property::Property(const std::string& name, unsigned action, unsigned cost,
                   unsigned* rents, unsigned group, unsigned house_cost):
    Tile(name, action),
    m_Cost(cost),
    m_Group(group),
    m_HouseCost(house_cost)
{
    for (unsigned i = 0; i < RENT_SLOTS; i++)
    {
        m_Rent[i] = rents[i];
    }
}

Property::~Property()
{}

unsigned Property::GetNumberHouses() const
{
    return m_Houses;
}

unsigned Property::GetGroup() const
{
    return m_Group;
}

unsigned Property::GetCost() const
{
    return m_Cost;
}

bool Property::IsMortgaged() const
{
    return m_IsMortgaged;
}

const unsigned* Property::GetRentArray() const
{
    return m_Rent;
}

void Property::BuyHouse()
{
    m_Houses++;
}

void Property::SellHouse()
{
    m_Houses--;
}

void Property::Mortgage()
{
    m_IsMortgaged = true;
}

void Property::Unmortgage()
{
    m_IsMortgaged = false;
}
