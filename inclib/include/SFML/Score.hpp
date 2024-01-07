#pragma once

#include "Graphics.hpp"
#include <string.h>
#include <iostream>

#define VIDEO_WIDTH 800
#define VIDEO_HEIGHT 600
#define OFFSET_PLY_SCORE 40
#define OFFSET_ENM_SCORE 30
#define SCORE_SIZE 24
#define ENDGAME_MSG_SIZE 60

class Score// : public Paddle // to get the drawTo method
{
    public:
        Score();
        Score(int &score_p1, int &score_p2);


        virtual ~Score();

        void drawScore(sf::RenderWindow &window);
        void updatePlayer(int &score_player);
        void updateEnemy(int &score_enemy);
        void winner(sf::RenderWindow &window);
        void loser(sf::RenderWindow &window);

    private:
    sf::Font m_numbers;
    sf::Font m_victory_or_defeat;
    sf::Text m_txt_score_player;
    sf::Text m_txt_score_enemy;
    sf::Text m_winner;
    sf::Text m_game_over;
};
