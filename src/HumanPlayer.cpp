#include "../include/HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(std::string name, token t):
    GenericPlayer(name, t)
{}

HumanPlayer::~HumanPlayer() {}

char HumanPlayer::PromptPurchase()
{
    char opt;
    std::cout << GetName() << ", (B)uy or (A)uction property ? ";
    std::cin >> opt;

    switch (opt)
    {
        case 'b':
        case 'B':
            return 'b';
        case 'a':
        case 'A':
            return 'a';
        default:
            return 0;
    }
}

char HumanPlayer::PromptAddtlAction()
{
    char opt;
    do
    {
        std::cout << GetName() << ", (T)rade, (V)iew Property, View (O)wned Properties, (N)ext Player: ";
        std::cin >> opt;
    } while (opt != 'T' && opt != 't' && opt != 'V' && opt != 'v' && opt != 'O' && opt != 'o'
             && opt != 'N' && opt != 'n');
    return opt;
}
