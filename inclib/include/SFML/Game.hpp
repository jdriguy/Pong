#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define VIDEO_WIDTH 800
#define VIDEO_HEIGHT 600
#define TXT_POS_X 250
#define TXT_POS_Y 50

/*
    Class that acts as my game's engine
    Wrapper class
*/

class Game
{
    private:
        // Member variables
        sf::RenderWindow m_window;

        sf::VideoMode m_videomode;

        //Resources
        sf::Font m_font;

        // Private functions
        void initWin();

    public:
        Game();
        virtual ~Game();

        bool m_active = false;

        //Accessors/getter
        sf::RenderWindow& getWindow() { return m_window;};

        // Public functions

        void renderGame(); // visualizing positions, points and everything (pixels on screens)
        
        void titleScreenTheme(sf::Music &main_theme);
        void stoptitleScreenTheme(sf::Music &main_theme);
        void playScreenTheme(sf::Music &play_theme);
        void stoppingPlayTheme(sf::Music &play_theme);

        void initBkgSprite();
};
