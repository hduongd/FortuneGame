#pragma once

#include <string>
#include "GenericPlayer.h"

class HumanPlayer : public GenericPlayer
{
public:
    HumanPlayer(std::string name, token t);   
    virtual ~HumanPlayer();

    char PromptPurchase();
    char PromptAddtlAction();
};
