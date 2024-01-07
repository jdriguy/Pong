#include <SFML/Theme.hpp>


/*
    play_theme pass by reference
    display error if music not found in directory
    volume
    Title Screen theme
*/
void Theme::playScreenTheme(sf::Music &play_theme)
{
    // Plays music, always after the render

    if(!play_theme.openFromFile("ogg/maintheme.ogg"))
    {
        std::cout << "Error file music not found" << std::endl;
    }
    play_theme.setVolume(50.0f);
    play_theme.play();
}

void Theme::stoppingPlayTheme(sf::Music &play_theme)
{
    play_theme.stop();
}


/*
    Constructor and destructor
*/
Theme::Theme()
{

}

Theme::~Theme()
{
     //to avoid memory leak
}
