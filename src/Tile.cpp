#include "Tile.h"

Tile::Tile(const std::string& name, unsigned int action):
    m_Name(name),
    m_Action(action)
{}

std::string Tile::GetName() const
{
    return m_Name;
}
