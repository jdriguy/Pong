#include <SFML/Game.hpp>

void Game::initWin()
{
    this->m_videomode.width = VIDEO_WIDTH;
    this->m_videomode.height = VIDEO_HEIGHT;
}

void Game::initBkgSprite()
{
    sf::Texture texture;

    if(!texture.loadFromFile("img/pingpong.png"))
    {
        std::cout << "Error file texture not found" << std::endl;
    }

    // Draw the sprite
    sf::Sprite sprite(texture);
    sprite.setPosition((VIDEO_WIDTH/2) - sprite.getGlobalBounds().width/2 , VIDEO_HEIGHT/2 - sprite.getGlobalBounds().height/2);

    m_window.draw(sprite);
}


/*
    clear window
    draw
    display
    Rendering objects
*/
void Game::renderGame()
{

    if(m_font.loadFromFile("fonts/starwars.TTF"))
    {

    }

    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setString("PONG");
    text.setPosition(TXT_POS_X, TXT_POS_Y);
    m_window.draw(text);

    // Update the window
    m_window.display(); // always clear the windows first then display it

}

/*
    main_theme pass by reference
    display error if music not found in directory
    volume
    Title Screen theme
*/
void Game::titleScreenTheme(sf::Music &main_theme)
{
    // Plays music, always after the render

    if(!main_theme.openFromFile("ogg/titlescreentheme.ogg"))
    {
        std::cout << "Error file music not found" << std::endl;
    }
    main_theme.setVolume(50.0f);
    main_theme.play();
}

void Game::stoptitleScreenTheme(sf::Music &main_theme)
{
    main_theme.stop();
}

/*
    play_theme pass by reference
    display error if music not found in directory
    volume
    Title Screen theme
*/
void Game::playScreenTheme(sf::Music &play_theme)
{
    // Plays music, always after the render

    if(!play_theme.openFromFile("ogg/maintheme.ogg"))
    {
        std::cout << "Error file music not found" << std::endl;
    }
    play_theme.setVolume(50.0f);
    play_theme.play();
}

void Game::stoppingPlayTheme(sf::Music &play_theme)
{
    play_theme.stop();
}

/*
    Constructor and destructor
*/
Game::Game()
{
    this->initWin();
}

Game::~Game()
{
     //to avoid memory leak
}
