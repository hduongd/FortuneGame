#include "../include/Board.h"
#include "../include/GenericPlayer.h"
#include "../include/Property.h"

GenericPlayer::GenericPlayer(std::string name, token t):
    m_Balance(1500),
    m_Railroads(0),
    m_Position(0),
    m_Name(name),
    m_Token(t)
{}

GenericPlayer::~GenericPlayer() {}

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

bool GenericPlayer::HasMonopolyOfGroup(unsigned groupID, Board& board)
{
    int count = 0;
    std::vector<Tile*>& board_vtr = board.GetBoardVtr();
    for (auto iter = board_vtr.begin(); iter != board_vtr.end();
            iter++)
    {
        Property* prop = dynamic_cast<Property*>(*iter);
        if (prop != NULL)
        {
            if (prop->GetGroup() == groupID)
                {
                    count++;
                }
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

std::string GenericPlayer::GetName() const
{
    return m_Name;
}

GenericPlayer::token GenericPlayer::GetToken() const
{
    return m_Token;
}
