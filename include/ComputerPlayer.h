#pragma once
#include "GenericPlayer.h"
#include "Board.h"
#include <string>
class ComputerPlayer : public GenericPlayer
{
public:
    ComputerPlayer(std::string name, GenericPlayer::token t);
    virtual ~ComputerPlayer();

    void Roll(unsigned roll, Board& board, GenericPlayer** player_array, unsigned num_players);
    void AnnounceRoll();
};
