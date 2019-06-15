#include "Board.h"
#include "Rent.h"
#include <iostream>
Board::Board()
{
    /*
     *  There will be a lot of constants assigned here.
     *  These represent the prices for each property as
     *  an array of integers.
     */
    unsigned katie[Property::RENT_SLOTS] = {10, 30, 50, 100, 200, 450};
    Tile* p_Go = new Tile("GO", Tile::GO);
    Tile* p_Katie = new Property("Katie Avenue", Tile::NO_ACTION, 60, katie, 4);
    Tile* p_Null = new Tile("Null", Tile::NO_ACTION);

    m_Board.push_back(p_Go);
    m_Board.push_back(p_Katie);
    m_Board.push_back(p_Null);
}

Board::~Board()
{
    for (unsigned i = 0; i < 3; i++)
    {
        delete m_Board[i];
    }
}

Tile* Board::GetTileInPosition(unsigned pos)
{
    if (pos > 36)
    {
        std::cout << "Invalid position!\n";
        return m_Board[0];
    }
    return m_Board[pos];
}
