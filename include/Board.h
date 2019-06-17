#pragma once

#include "Tile.h"
#include "Property.h"
#include <vector>

class Board
{
public:
    static const unsigned BOARD_SIZE = 40;
    Board();
    virtual ~Board();

    Tile* GetTileInPosition(unsigned pos);
private:
    std::vector<Tile*> m_Board;
};
