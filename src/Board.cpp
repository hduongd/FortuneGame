#include "../include/Board.h"
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
    unsigned tile_utility[Property::RENT_SLOTS]    = {0,   0,   0,    0,    0,    0};

    /*
     *  Now the tiles will be added to the vector in order
     *  according to the Monopoly board
     */
    m_Board.push_back(new Tile("GO", Tile::GO));
    m_Board.push_back(new Property("Andy Avenue", Tile::NO_ACTION, 60, tile_brown_low, 0));
    m_Board.push_back(new Tile("Community Chest", Tile::CHEST));
    m_Board.push_back(new Property("Evan Street", Tile::NO_ACTION, 60, tile_brown_high, 0));
    m_Board.push_back(new Tile("Income Tax", Tile::INCOME_TAX));
    m_Board.push_back(new Property("Byrnesville Depot", Tile::NO_ACTION, 200, tile_railroad, 8));
    m_Board.push_back(new Property("Vista View Park", Tile::NO_ACTION, 100, tile_lblue_low, 1));
    m_Board.push_back(new Tile("Chance", Tile::CHANCE));
    m_Board.push_back(new Property("Nicollet Avenue", Tile::NO_ACTION, 100, tile_lblue_low, 1));
    m_Board.push_back(new Property("Highway 13", Tile::NO_ACTION, 120, tile_lblue_high, 1));
    m_Board.push_back(new Tile("Just Visiting/Jail", Tile::NO_ACTION));
    m_Board.push_back(new Property("Unicorn Path", Tile::NO_ACTION, 140, tile_pink_low, 2));
    m_Board.push_back(new Property("Nuclear Power", Tile::UTILITY, 150, tile_utility, 9));
    m_Board.push_back(new Property("Dragon Street", Tile::NO_ACTION, 140, tile_pink_low, 2));
    m_Board.push_back(new Property("Troll Lane", Tile::NO_ACTION, 160, tile_pink_high, 2));
    m_Board.push_back(new Property("Great Station", Tile::NO_ACTION, 200, tile_railroad, 8));
    m_Board.push_back(new Property("Nvidia Way", Tile::NO_ACTION, 180, tile_orange_low, 3));
    m_Board.push_back(new Tile("Community Chest", Tile::CHEST));
    m_Board.push_back(new Property("Dragon Street", Tile::NO_ACTION, 180, tile_orange_low, 3));
    m_Board.push_back(new Property("Graphics Boulevard", Tile::NO_ACTION, 200, tile_orange_high, 3));
    m_Board.push_back(new Tile("Free Parking", Tile::NO_ACTION));
    m_Board.push_back(new Property("Katie Lane", Tile::NO_ACTION, 220, tile_red_low, 4));
    m_Board.push_back(new Tile("Chance", Tile::CHANCE));
    m_Board.push_back(new Property("Artist's Corner", Tile::NO_ACTION, 220, tile_red_low, 4));
    m_Board.push_back(new Property("Digital Way", Tile::NO_ACTION, 240, tile_red_high, 4));
    m_Board.push_back(new Property("Manifest Destiny", Tile::NO_ACTION, 200, tile_railroad, 8));
    m_Board.push_back(new Property("Vermillion Avenue", Tile::NO_ACTION, 260, tile_yellow_low, 5));
    m_Board.push_back(new Property("Maroon Way", Tile::NO_ACTION, 260, tile_yellow_low, 5));
    m_Board.push_back(new Property("Solar Energy", Tile::UTILITY, 150, tile_utility, 9));
    m_Board.push_back(new Property("Yellow Street", Tile::NO_ACTION, 280, tile_yellow_high, 5));
    m_Board.push_back(new Tile("Go to Jail", Tile::JAIL));
    m_Board.push_back(new Property("Baby Court", Tile::NO_ACTION, 280, tile_green_low, 6));
    m_Board.push_back(new Property("Tom Street", Tile::NO_ACTION, 280, tile_green_low, 6));
    m_Board.push_back(new Tile("Community Chest", Tile::CHEST));
    m_Board.push_back(new Property("Neil Boulevard", Tile::NO_ACTION, 300, tile_green_high, 6));
    m_Board.push_back(new Property("New World Express", Tile::NO_ACTION, 200, tile_railroad, 8));
    m_Board.push_back(new Tile("Chance", Tile::CHANCE));
    m_Board.push_back(new Property("Harvey Avenue", Tile::NO_ACTION, 350, tile_blue_low, 7));
    m_Board.push_back(new Tile("Luxury Tax", Tile::LUXURY_TAX));
    m_Board.push_back(new Property("Byrnesville", Tile::NO_ACTION, 400, tile_blue_high, 7));
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
    if (pos > Board::BOARD_SIZE - 1)
    {
        std::cout << "Invalid position!\n";
        return m_Board[0];
    }
    return m_Board[pos];
}
