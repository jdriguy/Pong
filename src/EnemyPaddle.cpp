#include <SFML/EnemyPaddle.hpp>

EnemyPaddle::EnemyPaddle(float height, float width, sf::Color color):Paddle(height, width, color)
{
    m_paddle.setPosition(ENEMY_POS_X,ENEMY_POS_Y);
    m_up = false;
    m_down = false;
}

void EnemyPaddle::processEvents(sf::Keyboard::Key key, bool checkPressed)
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

void EnemyPaddle::updatePlayer()
{
    if(m_up) m_mov.y += 1.0f;
    if(m_down) m_mov.y -= 1.0f;
}

void EnemyPaddle::moveEnemy(float &paddleXvelocity, float &paddleYvelocity, sf::Vector2f &ballPosition)
{

    if (m_paddle.getPosition().y < 0 || m_paddle.getPosition().y > VIDEO_HEIGHT) paddleYvelocity*= -1; // block from going outside down and top screen


    if (ballPosition.y > m_paddle.getPosition().y + (m_paddle.getSize().y)/2) // if ball is lower than the paddle's center 
    {
        m_paddle.move(paddleXvelocity,-paddleYvelocity);
    }

    if (ballPosition.y < m_paddle.getPosition().y - (m_paddle.getSize().y)/2) // if ball is higher than the paddle's center 
    {
        m_paddle.move(paddleXvelocity,paddleYvelocity);
    }
}


EnemyPaddle::EnemyPaddle()
{

}

EnemyPaddle::~EnemyPaddle()
{

}

