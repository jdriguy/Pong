#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define VIDEO_WIDTH 800
#define VIDEO_HEIGHT 600
#define PADDLE_OUTLINE_THICKNESS 5


class Paddle
{
    public:
        Paddle();
        Paddle(float height, float width, sf::Color color);

        void drawTo(sf::RenderWindow &win);

        virtual ~Paddle();

        sf::RectangleShape& getPaddle() { return m_paddle;};
        void hittingBall(sf::SoundBuffer &buffer, sf::Sound &sound);
        void stoppingBall(sf::Sound &sound);
        void losing(sf::SoundBuffer &buffer, sf::Sound &sound);


    protected:
        sf::RectangleShape m_paddle;

};
