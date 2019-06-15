#pragma once

#include "Tile.h"
#include "Property.h"
#include <vector>

const unsigned BOARD_SIZE = 36;

class Board
{
public:
    Board();
    virtual ~Board();

    Tile* GetTileInPosition(unsigned pos);
private:
    std::vector<Tile*> m_Board;

};
