#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Game.hpp>


#define VIDEO_WIDTH 800
#define VIDEO_HEIGHT 600


class Theme : public Game
{
    public:
        Theme();
        virtual ~Theme();

        void playScreenTheme(sf::Music &play_theme);
        void stoppingPlayTheme(sf::Music &play_theme);

    private:
};
