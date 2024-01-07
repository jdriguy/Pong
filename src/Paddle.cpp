#include <SFML/Paddle.hpp>

Paddle::Paddle(float height, float width, sf::Color color)
{
    m_paddle.setSize(sf::Vector2f(height, width));
    m_paddle.setOutlineColor(color);
    m_paddle.setFillColor(color);
    m_paddle.setOutlineThickness(PADDLE_OUTLINE_THICKNESS);
}

void Paddle::hittingBall(sf::SoundBuffer &buffer, sf::Sound &sound)
{
    if (!buffer.loadFromFile("ogg/pingpongboard.ogg"))
    {
        std::cout << "Error sound" << std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
}

void Paddle::losing(sf::SoundBuffer &buffer, sf::Sound &sound)
{
    if (!buffer.loadFromFile("ogg/defeat.ogg"))
    {
        std::cout << "Error sound" << std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
}


void Paddle::stoppingBall(sf::Sound &sound)
{
    sound.stop();
}


void Paddle::drawTo(sf::RenderWindow &win)
{
    win.draw(m_paddle);
}


Paddle::Paddle()
{

}

Paddle::~Paddle()
{

}

