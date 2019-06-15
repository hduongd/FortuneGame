#include "Board.h"
#include "Rent.h"
#include <iostream>
Board::Board()
{
    /*
     *  There will be a lot of constants assigned here.
     *  These represent the prices for each property as
     *  an array of integers.
     *
     *  Property::RENT_SLOTS = 6
     */
    unsigned tile_brown_low[Property::RENT_SLOTS]   = {2,   10,  30,   90,  160,  250};
    unsigned tile_brown_high[Property::RENT_SLOTS]  = {4,   20,  60,  180,  320,  450};
    unsigned tile_lblue_low[Property::RENT_SLOTS]   = {6,   30,  90,  270,  400,  550};
    unsigned tile_lblue_high[Property::RENT_SLOTS]  = {8,   40, 100,  300,  450,  600};
    unsigned tile_pink_low[Property::RENT_SLOTS]    = {10,  50, 150,  450,  625,  750};
    unsigned tile_pink_high[Property::RENT_SLOTS]   = {12,  60, 180,  500,  700,  900};
    unsigned tile_orange_low[Property::RENT_SLOTS]  = {14,  70, 200,  550,  750,  950};
    unsigned tile_orange_high[Property::RENT_SLOTS] = {16,  80, 220,  600,  800, 1000};
    unsigned tile_red_low[Property::RENT_SLOTS]     = {18,  90, 250,  700,  875, 1050};
    unsigned tile_red_high[Property::RENT_SLOTS]    = {20, 100, 300,  750,  925, 1100};
    unsigned tile_yellow_low[Property::RENT_SLOTS]  = {22, 110, 330,  800,  975, 1150};
    unsigned tile_yellow_high[Property::RENT_SLOTS] = {24, 120, 360,  850, 1025, 1200};
    unsigned tile_green_low[Property::RENT_SLOTS]   = {26, 130, 390,  900, 1100, 1275};
    unsigned tile_green_high[Property::RENT_SLOTS]  = {28, 150, 450, 1000, 1200, 1400};
    unsigned tile_blue_low[Property::RENT_SLOTS]    = {35, 175, 500, 1100, 1300, 1500};
    unsigned tile_blue_high[Property::RENT_SLOTS]   = {50, 200, 600, 1400, 1700, 2000};
    unsigned tile_railroad[Property::RENT_SLOTS]    = {25,   0,   0,    0,    0,    0};

    const unsigned BROWN_COST = 0;

    /*
     *  Now the tiles will be added to the vector in order
     *  according to the Monopoly board
     */

    m_Board.push_back(new Tile("GO", Tile::GO));
    m_Board.push_back(new Property("Andy Avenue", Tile::NO_ACTION, 60, tile_brown_low, 0));
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
