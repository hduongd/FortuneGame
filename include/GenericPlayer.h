#pragma once
#include <string>
#include <vector>
#include "Property.h"

class GenericPlayer
{
public:
    enum token {HASH, LETTER_O, DOLLAR, AMPERSAND, ZERO, AT, NONE};

    GenericPlayer(std::string name, token t);
    virtual ~GenericPlayer();
    
    int GetBalance() const;
    unsigned GetNumRailroads() const;
    unsigned GetPosition() const;
    void Move(int moves);
    bool HasMonopolyOfGroup(unsigned groupID);
    std::string GetName() const;
    token GetToken() const;
private:
    int m_Balance;
    unsigned m_Railroads;
    unsigned m_Position;
    std::string m_Name;
    std::vector<Property*> m_PropsOwnedVtr;
    token m_Token;
};
