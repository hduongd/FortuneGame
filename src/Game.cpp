#include "../include/Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
Game::Game()
{
    unsigned num_players;
    do
    {
        std::cout << "How many are playing (1-6)? ";
        std::cin >> num_players;
    } while (num_players > 6);

    m_NumPlayers = num_players;

    m_pGameBoard = new Board();
    m_PlayerVtr.reserve(m_NumPlayers);
}

Game::~Game()
{
    delete m_pGameBoard;
}

unsigned Game::RollDice()
{
    std::cout << "Rolling the dice!\n";
    
    unsigned die1 = rand() % 6 + 1;
    unsigned die2 = rand() % 6 + 1;

    return die1 + die2;
}
void Game::Play()
{
    std::string name;
    GenericPlayer::token t;

    // Initialize human players, ask for their name and preferred token (game piece)
    for (unsigned i = 0; i < m_NumPlayers; i++)
    {
        std::cout << "Player " << (i + 1) << ", what is your name? ";
        std::cin >> name;

        char input;
        std::vector<char> tokens_used;
        bool token_in_use = true;
        do
        {
            std::cout << "Very well, " << name << ", what token would you like?\n\n";
            std::cout << "#, O, $, &, X, or @ ";
            std::cin >> input;
            for (auto iter = tokens_used.begin(); iter != tokens_used.end(); ++iter)
            {
                std::cout << *iter << std::endl;
                if (*iter == input)
                {
                    std::cout << "That token has already been taken, try a different one.\n";
                    token_in_use = true;
                    break;
                }
                else if (iter == tokens_used.end())
                {
                    token_in_use = false;
                }
            }
        } while (token_in_use && (input != '#' && input != 'O' && input != '$' && input != '&' && input != 'X' && input != '@'));

        switch (input)
        {
            case '#':
                tokens_used.push_back('#');
                t = GenericPlayer::TKN_HASH;
                break;
            case 'O':
                tokens_used.push_back('O');
                t = GenericPlayer::TKN_LETTER_O;
                break;
            case '$':
                tokens_used.push_back('$');
                t = GenericPlayer::TKN_DOLLAR;
                break;
            case '&':
                tokens_used.push_back('&');
                t = GenericPlayer::TKN_AMPERSAND;
                break;
            case 'X':
                tokens_used.push_back('X');
                t = GenericPlayer::TKN_X;
                break;
            case '@':
                tokens_used.push_back('@');
                t = GenericPlayer::TKN_AT;
                break;
        }
        m_PlayerVtr.push_back(new HumanPlayer(name, t));
    }

    // Now that players have been initialized,
    // determine who goes first
    
    srand(static_cast<unsigned>(time(0)));
    
    unsigned highest_roll = 2;
    GenericPlayer* highest_player = m_PlayerVtr[0];
    for (auto player = m_PlayerVtr.begin(); player != m_PlayerVtr.end(); player++)
    {
        std::cout << (*player)->GetName() << " is rolling!\n";
        unsigned result = RollDice();
        std::cout << (*player)->GetName() << " rolled a " << result << std::endl;

        if (result > highest_roll)
        {
            highest_player = *player;
        }
    }
    std::cout << highest_player->GetName() << " rolled the highest!\n";
}
