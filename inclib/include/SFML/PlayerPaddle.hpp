#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"


#define PLAYER_POS_X 100
#define PLAYER_POS_Y 300


class PlayerPaddle : public Paddle
{
    public:
        PlayerPaddle();
        PlayerPaddle(float height, float width, sf::Color color);


        virtual ~PlayerPaddle();

        void movePlayer(float x, float y);

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
