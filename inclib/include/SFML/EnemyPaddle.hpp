#pragma once

#include "Graphics.hpp"
#include "Paddle.hpp"

#define ENEMY_POS_X 700
#define ENEMY_POS_Y 300

class EnemyPaddle : public Paddle
{
    public:
        EnemyPaddle();
        EnemyPaddle(float height, float width, sf::Color color);


        virtual ~EnemyPaddle();

        void moveEnemy(float &paddleXvelocity, float &paddleYvelocity, sf::Vector2f &ballPosition);

        int getPlayerPaddle() { return m_pos_y_player; };
        sf::Vector2f getMov() { return m_mov; };

        void processEvents(sf::Keyboard::Key key, bool checkPressed);
        void updatePlayer();

    private:
    sf::RectangleShape m_pad;

    int m_pos_y_player;
    bool m_up;
    bool m_down;
    sf::Vector2f m_mov;
};
