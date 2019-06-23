#pragma once
#include "Board.h"
#include "GenericPlayer.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include <vector>
class Game
{
public:
    Game();
    virtual ~Game();

    friend std::ostream& operator<<(std::ostream& os, std::vector<GenericPlayer*>& player_vtr);
    void Play();
    unsigned RollDice();
private:
    unsigned m_NumPlayers;
    Board* m_pGameBoard;
    std::vector<GenericPlayer*> m_PlayerVtr;
};
