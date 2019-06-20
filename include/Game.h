#pragma once
#include "Board.h"
#include "GenericPlayer.h"
#include "HumanPlayer.h"
#include <vector>
class Game
{
public:
    Game();
    virtual ~Game();

    void Play();
    unsigned RollDice();
private:
    unsigned m_NumPlayers;
    Board* m_pGameBoard;
    std::vector<GenericPlayer*> m_PlayerVtr;
};
