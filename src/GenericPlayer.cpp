#include "../include/GenericPlayer.h"

GenericPlayer::GenericPlayer(std::string name, token t):
    m_Balance(1500),
    m_Position(0),
    m_Name(name),
    m_Token(t)
{}

GenericPlayer::~GenericPlayer() {}

int GenericPlayer::GetBalance() const
{
    return m_Balance;
}


unsigned GenericPlayer::GetPosition() const
{
    return m_Position;
}
void GenericPlayer::Move(int distance)
{
    // there are only 40 positions on the board,
    // wrap around once the end is reached
    m_Position = (m_Position + distance) % 40;
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


