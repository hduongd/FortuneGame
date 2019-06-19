#include "../include/HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(std::string name, token t):
    GenericPlayer(name, t)
{}

HumanPlayer::~HumanPlayer() {}

char HumanPlayer::PromptPurchase(Board& board)
{
    Property* prop = dynamic_cast<Property*>(board.GetTileInPosition(GetPosition()));
    char opt;
    std::cout << GetName() << ", (B)uy " << "[$" << prop->GetCost() << "]" << "or (A)uction property " << 
        prop->GetName() << "? ";
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

char HumanPlayer::PromptAddtlAction(Board& board)
{
    char opt;
    do
    {
        std::cout << GetName() << ", (T)rade, (V)iew Property, View (O)wned Properties, (N)ext Player: ";
        std::cin >> opt;
    } while (opt != 'T' && opt != 't' && opt != 'V' && opt != 'v' && opt != 'O' && opt != 'o'
             && opt != 'N' && opt != 'n');
    switch(opt)
    {
        case 'T':
        case 't':
            return 't';
        case 'V':
        case 'v':
            {
                unsigned number;

                do
                {
                    std::cout << "Which property to view? (input # from 0-39): ";
                    std::cin >> number;
                } while (number > 39);

                Tile* tile = board.GetTileInPosition(number);
                Property* prop = dynamic_cast<Property*>(tile);

                if (prop != NULL)
                {
                    std::cout << prop;
                }
                else
                {
                    std::cout << "Tile: " << tile->GetName() << std::endl;
                }
                break;
            }
        case 'O':
        case 'o':
            // TODO fill out this case
            return 'x';
        case 'N':
        case 'n':
            // TODO fill out this case
            return 'n';
    }
}
