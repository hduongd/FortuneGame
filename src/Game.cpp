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
    unsigned die1 = rand() % 6 + 1;
    unsigned die2 = rand() % 6 + 1;

    return die1 + die2;
}
void Game::Play()
{
    std::string name;

    // Initialize human players, ask for their name and preferred token (game piece)
    std::vector<char> tokens_used;
    char input;
    for (unsigned i = 0; i < m_NumPlayers; i++)
    {
        std::cout << "Player " << (i + 1) << ", what is your name? ";
        std::cin >> name;

        bool token_in_use;

        do
        {
            token_in_use = false;
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
            }
        } while (token_in_use || (input != '#' && input != 'O' && input != '$' && input != '&' && input != 'X' && input != '@'));

        switch (input)
        {
            case '#':
                tokens_used.push_back('#');
                m_PlayerVtr.push_back(new HumanPlayer(name, GenericPlayer::TKN_HASH));
                token_in_use = false;
                break;
            case 'O':
                tokens_used.push_back('O');
                m_PlayerVtr.push_back(new HumanPlayer(name, GenericPlayer::TKN_LETTER_O));
                token_in_use = false;
                break;
            case '$':
                tokens_used.push_back('$');
                m_PlayerVtr.push_back(new HumanPlayer(name, GenericPlayer::TKN_DOLLAR));
                token_in_use = false;
                break;
            case '&':
                tokens_used.push_back('&');
                m_PlayerVtr.push_back(new HumanPlayer(name, GenericPlayer::TKN_AMPERSAND));
                token_in_use = false;
                break;
            case 'X':
                tokens_used.push_back('X');
                m_PlayerVtr.push_back(new HumanPlayer(name, GenericPlayer::TKN_X));
                token_in_use = false;
                break;
            case '@':
                tokens_used.push_back('@');
                m_PlayerVtr.push_back(new HumanPlayer(name, GenericPlayer::TKN_AT));
                token_in_use = false;
                break;
        }
    }

    // Add a CPU
    // m_PlayerVtr.push_back(new ComputerPlayer("CPU 1", GenericPlayer::TKN_LETTER_O));

    // Now that players have been initialized,
    // determine who goes first
    
    srand(static_cast<unsigned>(time(0)));
    
    unsigned highest_roll = 2;
    GenericPlayer* highest_player = m_PlayerVtr[0];
    for (auto player = m_PlayerVtr.begin(); player != m_PlayerVtr.end(); player++)
    {
        std::cout << (*player)->GetName() << " is rolling!\n";
        unsigned result = RollDice();
        std::cout << (*player)->GetName() << " rolled a " << result << std::endl << std::endl;

        if (result > highest_roll)
        {
            highest_roll = result;
            highest_player = *player;
        }
    }
    std::cout << highest_player->GetName() << " rolled the highest!\n";

    // Begin game loop
    
    unsigned num_active_players = m_NumPlayers;
    while (num_active_players > 1)
    {
        for (auto iter = m_PlayerVtr.begin(); iter != m_PlayerVtr.end(); iter++)
        {
            HumanPlayer* current_player = dynamic_cast<HumanPlayer*>(*iter);
            if (current_player != NULL)
            {
                std::cout << current_player->GetName() << ", press enter to roll!\n\n";
                std::cin.get();

                unsigned roll = RollDice();

                std::cout << "You rolled " << roll << std::endl;
                current_player->Move(roll);

                Tile* current_tile = m_pGameBoard->GetTileInPosition(current_player->GetPosition());
                Property* current_property = dynamic_cast<Property*>(current_tile);

                std::cout << "\t\tYou have landed on " << current_tile->GetName() << std::endl;
                if (current_property != NULL)
                {
                    std::cout << *current_property << std::endl;
                }

            }
            else
            {
                std::cout << "This is a CPU.\n\n";
            }

        }
        for (auto iter = m_PlayerVtr.begin(); iter != m_PlayerVtr.end(); iter++)
        {
            if ((*iter)->GetBalance() <= 0)
            {
                num_active_players--;
            }
        }

    }
    std::cout << "Game over!\n";
}
