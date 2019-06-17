#include "../include/ComputerPlayer.h"
#include "../include/Board.h"
#include "../include/Tile.h"
#include "../include/Property.h"
#include <random>
ComputerPlayer::ComputerPlayer(std::string name, GenericPlayer::token t):
    GenericPlayer(name, t)
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::Roll(unsigned roll, Board& board)
{
    Move(roll);
    Tile* current_tile = board.GetTileInPosition(GetPosition());
    Property* current_prop = dynamic_cast<Property*>(current_tile);

    if (current_prop != NULL)
    {
        
    }
}
