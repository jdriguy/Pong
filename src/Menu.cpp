#include <SFML/Menu.hpp>

Menu::Menu()
{
    //ctor
}

Menu::Menu(float width, float height)
{
    if(!m_menu_font.loadFromFile("fonts/starwars.TTF"))
    {
        // error
    }

    m_menu[0].setFont(m_menu_font);
    m_menu[0].setString("PLAY");
    m_menu[0].setFillColor(sf::Color::Cyan);
    m_menu[0].setPosition((VIDEO_WIDTH/2) - m_menu[0].getGlobalBounds().width/2 , VIDEO_HEIGHT/2 - m_menu[0].getGlobalBounds().height/2 - OFFSET_PLAY);

    m_menu[1].setFont(m_menu_font);
    m_menu[1].setString("QUIT");
    m_menu[1].setFillColor(sf::Color::White);
    m_menu[1].setPosition((VIDEO_WIDTH/2) - m_menu[1].getGlobalBounds().width/2 , VIDEO_HEIGHT/2 + m_menu[1].getGlobalBounds().height/2 + OFFSET_QUIT);

    m_selected_item = 0;
}

void Menu::drawMenu(sf::RenderWindow &window)
{
    for(int i = 0; i < NB_MENU_ITEMS_SELECTED; i++)
    {
        window.draw(m_menu[i]);
    }
}

void Menu::moveUpMenu()
{
    if(m_selected_item -1 >= 0)
    {
        m_menu[m_selected_item].setFillColor(sf::Color::White);
        m_selected_item--;

        if(m_selected_item == -1)
        {
            m_selected_item = 1;
        }

        m_menu[m_selected_item].setFillColor(sf::Color::Cyan);
    }
}

void Menu::moveDownMenu()
{
    if(m_selected_item +1 < NB_MENU_ITEMS_SELECTED)
    {
        m_menu[m_selected_item].setFillColor(sf::Color::White);
        m_selected_item++;

        if(m_selected_item == 3)
        {
            m_selected_item = 0;
        }

        m_menu[m_selected_item].setFillColor(sf::Color::Cyan);
    }
}


Menu::~Menu()
{
    //dtor
}
