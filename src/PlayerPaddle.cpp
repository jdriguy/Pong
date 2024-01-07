#include <SFML/PlayerPaddle.hpp>

PlayerPaddle::PlayerPaddle(float height, float width, sf::Color color):Paddle(height, width, color)
{
    m_paddle.setPosition(PLAYER_POS_X, PLAYER_POS_Y);
    m_up = false;
    m_down = false;
}

void PlayerPaddle::processEvents(sf::Keyboard::Key key, bool checkPressed)
{
    if(checkPressed == true)
    {
        if(key == sf::Keyboard::Up) m_up = true;
        if(key == sf::Keyboard::Down) m_down = true;
    }
    else if (checkPressed == false)
    {
        m_up = false;
        m_down = false;
    }    
}

void PlayerPaddle::updatePlayer()
{
    if(m_up) m_mov.y += 1.0f;
    if(m_down) m_mov.y -= 1.0f;
}

void PlayerPaddle::movePlayer(float x, float y)
{
    m_paddle.move(x,y);
}


PlayerPaddle::PlayerPaddle()
{

}

PlayerPaddle::~PlayerPaddle()
{

}

