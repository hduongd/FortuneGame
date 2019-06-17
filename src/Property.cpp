#include "../include/Property.h"
#include <iostream>

Property::Property(const std::string& name, unsigned action, unsigned cost,
                   unsigned* rents, unsigned group, GenericPlayer* owner, unsigned house_cost):
    Tile(name, action),
    m_Cost(cost),
    m_Group(group),
    m_HouseCost(house_cost),
    m_pOwner(owner)
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

GenericPlayer* Property::GetOwner()
{
    return m_pOwner;
}
bool Property::PlayerOwns(GenericPlayer* player)
{
    return (player == m_pOwner);
}
unsigned Property::GetCost() const
{
    return m_Cost;
}

bool Property::IsMortgaged() const
{
    return m_IsMortgaged;
}

void Property::TransferOwnership(GenericPlayer* new_owner)
{
    m_pOwner = new_owner;
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
