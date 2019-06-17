#pragma once

#include <string>

class Tile
{
public:
    enum actions {NO_ACTION, CHANCE, CHEST, JAIL, INCOME_TAX, LUXURY_TAX, UTILITY, GO};

    Tile(const std::string& name, unsigned action);
    virtual ~Tile();

    std::string GetName() const;

protected:
    std::string m_Name;
private:
    unsigned m_Action;
};
