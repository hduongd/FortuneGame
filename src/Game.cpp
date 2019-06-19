#include "../include/Game.h"
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

void PlayGame()
{
    std::string name;
    GenericPlayer::token t;
    for (unsigned i = 0; i < m_NumPlayers; i++)
    {
        std::cout << "Player " << (i + 1) << ", what is your name? ";
        std::cin >> name;

        char input;
        std::vector<char> tokens_used;
        std::cout << "Very well, " << name << ", what token would you like?\n\n";
        std::cout << "#, O, $, &, X, or @ ";
        std::cin >> input;

        switch (input)
        {
            case '#':
                tokens_used.push_back('#');
                break;
            case 'O':
                tokens_used.push_back('O');
                break;
            case '$':
                tokens_used.push_back('$');
                break;
            case '&':
                tokens_used.push_back('&');
                break;
            case 'X':
                tokens_used.push_back('X');
                break;
            case '@':
                tokens_used.push_back('@');
                break;
        }
    }
}
