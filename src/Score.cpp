#include <SFML/Score.hpp>

Score::Score(int &score_p1, int &score_p2)
{
    if(!m_numbers.loadFromFile("fonts/numbers.ttf"))
    {
        // error
    }

    m_txt_score_player.setFont(m_numbers);
    m_txt_score_player.setCharacterSize(SCORE_SIZE);
    m_txt_score_player.setPosition((VIDEO_WIDTH/2) - OFFSET_PLY_SCORE, 0);
    m_txt_score_player.setString(std::to_string(score_p1));

    m_txt_score_enemy.setFont(m_numbers);
    m_txt_score_enemy.setCharacterSize(SCORE_SIZE);
    m_txt_score_enemy.setPosition((VIDEO_WIDTH/2) + OFFSET_ENM_SCORE, 0);
    m_txt_score_enemy.setString(std::to_string(score_p2));
}

void Score::drawScore(sf::RenderWindow &window)
{
    window.draw(m_txt_score_player);
    window.draw(m_txt_score_enemy);
}

void Score::updatePlayer(int &score_player)
{
    m_txt_score_player.setString(std::to_string(score_player));
}

void Score::updateEnemy(int &score_enemy)
{
    m_txt_score_enemy.setString(std::to_string(score_enemy));
}

void Score::winner(sf::RenderWindow &window)
{
    if(!m_victory_or_defeat.loadFromFile("fonts/starwars.TTF"))
    {
        // error
    }

    m_winner.setFont(m_victory_or_defeat);
    m_winner.setCharacterSize(ENDGAME_MSG_SIZE);
    m_winner.setPosition((VIDEO_WIDTH/2) - m_winner.getGlobalBounds().width/2 , VIDEO_HEIGHT/2 - m_winner.getGlobalBounds().height/2);
    m_winner.setFillColor(sf::Color::Cyan);
    m_winner.setString("Congratulations !");
    window.draw(m_winner);
}

void Score::loser(sf::RenderWindow &window)
{
    if(!m_victory_or_defeat.loadFromFile("fonts/starwars.TTF"))
    {
        // error
    }
    
    m_game_over.setFont(m_victory_or_defeat);
    m_game_over.setCharacterSize(ENDGAME_MSG_SIZE);
    m_game_over.setPosition((VIDEO_WIDTH/2) - m_game_over.getGlobalBounds().width/2 , VIDEO_HEIGHT/2 - m_game_over.getGlobalBounds().height/2);
    m_game_over.setFillColor(sf::Color::Red);
    m_game_over.setString("Game over !");
    window.draw(m_game_over);
}

Score::Score()
{
}

Score::~Score()
{
}

