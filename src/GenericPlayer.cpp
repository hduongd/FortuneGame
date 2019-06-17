#include "../include/GenericPlayer.h"
#include "../include/Property.h"

GenericPlayer::GenericPlayer(std::string name, token t):
    m_Balance(1500),
    m_Railroads(0),
    m_Utilities(0),
    m_Position(0),
    m_Name(name),
    m_Token(t)
{}

GenericPlayer::~GenericPlayer() {}

unsigned GenericPlayer::GetNumRailroads() const
{
    return m_Railroads;
}
unsigned GenericPlayer::GetNumUtls() const
{
    return m_Utilities;
}
unsigned GenericPlayer::GetPosition() const
{
    return m_Position;
}
/*
bool GetMonopolyOf(unsigned groupID)
{
    int count = 0;
    for (auto iter = m_Properties.begin(); iter != m_Properties.end();
            iter++)
    {
        Property* p = static_cast<Property*>(iter);
        if ()
    }
}
*/
std::string GenericPlayer::GetName() const
{
    return m_Name;
}

GenericPlayer::token GenericPlayer::GetToken() const
{
    return m_Token;
}
