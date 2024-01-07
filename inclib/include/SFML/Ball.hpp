#pragma once

#include "Graphics.hpp"

#define CIRCLE_POS_X 600
#define CIRCLE_POS_Y 350
#define CIRCLE_RADIUS 10

#define VIDEO_WIDTH 800
#define VIDEO_HEIGHT 600


class Ball
{
    public:
        Ball();
        Ball(sf::CircleShape &shape, float angle, sf::Color color);

        virtual ~Ball();

        void moveBall(sf::CircleShape &shape, float &xVelocity, float &yVelocity, sf::Vector2f &circlePosition);

    private:
        sf::CircleShape m_ball;
};
