#pragma once
#include <string>
#include <vector>
#include "Property.h"

class GenericPlayer
{
public:
    enum token {TKN_HASH, TKN_LETTER_O, TKN_DOLLAR, TKN_AMPERSAND, TKN_X, TKN_AT, TKN_NONE};

    GenericPlayer(std::string name, token t);
    virtual ~GenericPlayer();
    
    std::string GetName() const;
    int GetBalance() const;
    unsigned GetPosition() const;
    void Move(int distance);
    bool HasProperty(Property* prop);
    std::vector<Property*>& GetPropOwnedVtr();
    token GetToken() const;
    
private:
    int m_Balance;
    unsigned m_Position;
    std::string m_Name;
    std::vector<Property*> m_PropsOwnedVtr;
    token m_Token;
};
