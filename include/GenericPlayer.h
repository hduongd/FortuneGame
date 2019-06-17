#pragma once
#include "Tile.h"
#include <string>
#include <vector>
class GenericPlayer
{
public:
    enum token {HASH, LETTER_O, DOLLAR, AMPERSAND, ZERO, AT, NONE};

    GenericPlayer(std::string name, token t);
    virtual ~GenericPlayer();
    
    unsigned GetNumRailroads() const;
    unsigned GetNumUtls() const;
    unsigned GetPosition() const;
    bool GetMonopolyOf(unsigned groupID);
    std::string GetName() const;
    std::vector<Tile*>& GetPropertyVtr();
    token GetToken() const;
private:
    int m_Balance;
    unsigned m_Railroads;
    unsigned m_Utilities;
    unsigned m_Position;
    std::string m_Name;
    token m_Token;
};
