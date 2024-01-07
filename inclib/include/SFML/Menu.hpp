#pragma once

#include <SFML/Graphics.hpp>

#define NB_MENU_ITEMS_SELECTED 2
#define OFFSET_PLAY 50
#define OFFSET_QUIT 100
#define VIDEO_WIDTH 800
#define VIDEO_HEIGHT 600


class Menu
{
    public:
        Menu();
        Menu(float width, float height);
        virtual ~Menu();

        void drawMenu(sf::RenderWindow &window);

        void moveUpMenu();
        void moveDownMenu();
        
        //Accessors/getter
        int getSelectedItem() {return m_selected_item;}

    private:
        sf::Font m_menu_font;
        sf::Text m_menu[NB_MENU_ITEMS_SELECTED];
        int m_selected_item; // expression m_menu must have integral or unscoped enum type so no float
};

