#include "../include/GenericPlayer.h"

GenericPlayer::GenericPlayer(std::string name, token t):
    m_Balance(1500),
    m_Railroads(0),
    m_Position(0),
    m_Name(name),
    m_Token(t)
{}

GenericPlayer::~GenericPlayer() {}

int GenericPlayer::GetBalance() const
{
    return m_Balance;
}
unsigned GenericPlayer::GetNumRailroads() const
{
    return m_Railroads;
}
unsigned GenericPlayer::GetPosition() const
{
    return m_Position;
}
void GenericPlayer::Move(int moves)
{
    m_Position = (m_Position + moves) % 40;
}

bool GenericPlayer::HasMonopolyOfGroup(unsigned groupID)
{
    int count = 0;
    for (auto iter = m_PropsOwnedVtr.begin(); iter != m_PropsOwnedVtr.end();
            iter++)
    {
        if ((*iter)->GetGroup() == groupID)
        {
            count++;
        }
    }
    switch (groupID)
    {
        case Property::BROWN:
            return (count == 2);
        case Property::LBLUE:
            return (count == 3);
        case Property::PINK:
            return (count == 3);
        case Property::ORANGE:
            return (count == 3);
        case Property::RED:
            return (count == 3);
        case Property::YELLOW:
            return (count == 3);
        case Property::GREEN:
            return (count == 3);
        case Property::BLUE:
            return (count == 2);
        case Property::UTIL:
            return (count == 2);
        default:
            return false;
    }
}

bool GenericPlayer::HasProperty(Property* prop)
{
    for (auto iter = m_PropsOwnedVtr.begin(); iter != m_PropsOwnedVtr.end(); iter++)
    {
        if (prop == *iter)
        {
            return true;
        }
    }
    return false;
}

std::vector<Property*>& GenericPlayer::GetPropOwnedVtr()
{
    return m_PropsOwnedVtr;
}

std::string GenericPlayer::GetName() const
{
    return m_Name;
}

GenericPlayer::token GenericPlayer::GetToken() const
{
    return m_Token;
}

void GenericPlayer::BuyProperty(Property* prop)
{
    m_Balance -= prop->GetCost();
    m_PropsOwnedVtr.push_back(prop);
}
void GenericPlayer::MortgageProperty(Property* prop)
{
    m_Balance += prop->GetCost() / 2;
    prop->Mortgage();
}
bool GenericPlayer::BuyHouseOnProp(Property* prop)
{
    unsigned groupID = prop->GetGroup();
    std::vector<Property*> group;
    group.reserve(3);
    for (auto iter = m_PropsOwnedVtr.begin(); iter != m_PropsOwnedVtr.end(); iter++)
    {
        if ((*iter)->GetGroup() == groupID)
        {
            group.push_back(*iter);
        }
    }
    if (HasMonopolyOfGroup(groupID))
    {
        unsigned min_houses = 0;
        for (auto iter = group.begin(); iter != group.end(); iter++)
        {
            unsigned num_houses = (*iter)->GetNumberHouses();
            if (num_houses > min_houses)
            {
                min_houses = num_houses;
            }
        }
        if (prop->GetNumberHouses() + 1 < min_houses + 2)
        {
            m_Balance -= prop->GetRentArray()[6];
            prop->BuyHouse();
            return true;
        }
    }
    return false;
}
