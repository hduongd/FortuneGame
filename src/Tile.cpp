#include "../include/Tile.h"
#include <iostream>
Tile::Tile(const std::string& name, unsigned action):
    m_Name(name),
    m_Action(action)
{}


Tile::~Tile()
{}

std::string Tile::GetName() const
{
    return m_Name;
}
