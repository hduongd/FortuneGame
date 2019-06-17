#pragma once
#include "Board.h"
#include <string>
#include <vector>

class GenericPlayer
{
public:
    enum token {HASH, LETTER_O, DOLLAR, AMPERSAND, ZERO, AT, NONE};

    GenericPlayer(std::string name, token t);
    virtual ~GenericPlayer();
    
    unsigned GetNumRailroads() const;
    unsigned GetPosition() const;
    void Move(int moves);
    bool HasMonopolyOfGroup(unsigned groupID, Board& board);
    std::string GetName() const;
    token GetToken() const;
private:
    int m_Balance;
    unsigned m_Railroads;
    unsigned m_Position;
    std::string m_Name;
    token m_Token;
};
