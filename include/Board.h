#pragma once

#include "../include/Tile.h"
#include <vector>

class Board
{
public:
    static const unsigned BOARD_SIZE = 40;
    Board();
    virtual ~Board();

    Tile* GetTileInPosition(unsigned pos);
    std::vector<Tile*>& GetBoardVtr();
private:
    std::vector<Tile*> m_Board;
};
