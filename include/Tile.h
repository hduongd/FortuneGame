#pragma once

#include <string>

class Tile
{
public:
    enum actions {NO_ACTION, CHANCE, CHEST, JAIL, INCOME_TAX, LUXURY_TAX};
    Tile(const std::string& name, unsigned int action);

    std::string GetName() const;

protected:
    std::string m_Name;

private:
    unsigned int m_Action;
};
