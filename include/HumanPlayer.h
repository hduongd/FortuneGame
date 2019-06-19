#pragma once

#include <string>
#include "GenericPlayer.h"
#include "Board.h"

class HumanPlayer : public GenericPlayer
{
public:
    HumanPlayer(std::string name, token t);   
    virtual ~HumanPlayer();

    char PromptPurchase(Board& board);
    char PromptAddtlAction(Board& board);
};
