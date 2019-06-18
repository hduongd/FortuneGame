#include "../include/ComputerPlayer.h"
ComputerPlayer::ComputerPlayer(std::string name, GenericPlayer::token t):
    GenericPlayer(name, t)
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::Roll(unsigned roll, Board& board, GenericPlayer** player_array, unsigned num_players)
{
    Move(roll);
    Tile* current_tile = board.GetTileInPosition(GetPosition());
    Property* current_prop = dynamic_cast<Property*>(current_tile);

    if (current_prop != NULL)
    {
        // Determine if the property is unowned (not in any player's collection)
        bool isOwned = false;
        for (unsigned i = 0; i < num_players; i++)
        {
            if (player_array[i]->HasProperty(current_prop))
            {
                isOwned = true;
            }
        }
        const unsigned* rents = current_prop->GetRentArray();
        // --TODO-- 
        if (!isOwned && GetBalance() > 1.5 * rents[Property::RENT])
        {
            current_prop;
        }
    }
}
