#pragma once
#include "Board.h"
#include "GenericPlayer.h"
#include <vector>
class Game
{
public:
    Game();
    virtual ~Game();

    void PlayGame();
private:
    unsigned m_NumPlayers;
    Board* m_pGameBoard;
    std::vector<GenericPlayer> m_PlayerVtr;
};
