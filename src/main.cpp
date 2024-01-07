#include <SFML/Game.hpp>
#include <SFML/Theme.hpp>
#include <SFML/PlayerPaddle.hpp>
#include <SFML/EnemyPaddle.hpp>
#include <SFML/Ball.hpp>
#include <SFML/Score.hpp>
#include <SFML/Menu.hpp>

int main()
{

    Game game;
    game.getWindow().create(sf::VideoMode(VIDEO_WIDTH, VIDEO_HEIGHT), "Pong", sf::Style::Titlebar | sf::Style::Close);

    Menu menu(game.getWindow().getSize().x, game.getWindow().getSize().y);

    Theme theme;

    sf::Music title_theme;
    sf::Music play_theme;

    game.titleScreenTheme(title_theme);

    sf::SoundBuffer sound_buffer;
    sf::Sound bonk;

    game.m_active = true;

    sf::Text m_menu[NB_MENU_ITEMS_SELECTED];
    sf::Font m_menu_font;

    while (game.getWindow().isOpen())
    {
        sf::Event event;
        while (game.getWindow().pollEvent(event))
        {
            switch (event.type)
            {
                // Close window : exit button or escape key
                case sf::Event::Closed:
                    game.getWindow().close();
                break;
                
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                        case sf::Keyboard::PageUp:
                            menu.moveUpMenu();
                        break;
                    
                        case sf::Keyboard::Down:
                        case sf::Keyboard::PageDown:
                            menu.moveDownMenu();
                        break;

                        case sf::Keyboard::Return:
                            sf::RenderWindow Play(sf::VideoMode(VIDEO_WIDTH, VIDEO_HEIGHT), "Play", sf::Style::Titlebar | sf::Style::Close);
                            
                            sf::CircleShape circle;
                            Ball ball(circle, 15.f, sf::Color::White);
                            sf::Vector2f circlePosition(400, 100);
                            circle.setRadius(10);

                            float xVelocity = 4;
                            float yVelocity = 4;

                            PlayerPaddle player_paddle(10,80,sf::Color::Cyan);
                            EnemyPaddle enemy_paddle(10,80, sf::Color::Red);
                            float enemyXvelocity = 0;
                            float enemyYvelocity = 10;
                            
                            int score_player = 0;
                            int score_enemy = 0;
                            Score score_board(score_player, score_enemy);
                            
                            sf::RectangleShape net(sf::Vector2f(5, VIDEO_HEIGHT));
                            net.setPosition(VIDEO_WIDTH/2, 0);
                            
                            sf::Event play_event;

                            switch(menu.getSelectedItem())
                            {
                                case 0:
                                    std::cout << "Play pressed" << std::endl;

                                    if (score_player < 4 || score_enemy < 4)
                                        game.stoptitleScreenTheme(title_theme);
                                        game.playScreenTheme(play_theme);
                                        while(Play.isOpen())
                                        {
                                            Play.setFramerateLimit(60);

                                            while(Play.pollEvent(play_event))
                                                {
                                                        if(play_event.type == sf::Event::Closed) Play.close();
                                                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Play.close();
                                                        
                                                        if(play_event.key.code == sf::Keyboard::Up) player_paddle.movePlayer(0,-10);

                                                        if(play_event.key.code == sf::Keyboard::Down)   player_paddle.movePlayer(0,10);
                                                }
                                                // physics
                                                ball.moveBall(circle, xVelocity, yVelocity, circlePosition);
                                                enemy_paddle.moveEnemy(enemyXvelocity, enemyYvelocity, circlePosition);

                                                /*
                                                    Add CIRCLE_RADIUS to avoid glitches with the paddles' extremities
                                                */


                                                if(circlePosition.x < player_paddle.getPaddle().getPosition().x + player_paddle.getPaddle().getSize().x 
                                                    && circlePosition.x > player_paddle.getPaddle().getPosition().x
                                                    && circlePosition.y + CIRCLE_RADIUS < player_paddle.getPaddle().getPosition().y + player_paddle.getPaddle().getSize().y
                                                    && circlePosition.y + CIRCLE_RADIUS > player_paddle.getPaddle().getPosition().y
                                                    
                                                    ||

                                                    circlePosition.x > enemy_paddle.getPaddle().getPosition().x - enemy_paddle.getPaddle().getSize().x
                                                    && circlePosition.x < enemy_paddle.getPaddle().getPosition().x 
                                                    && circlePosition.y + CIRCLE_RADIUS < enemy_paddle.getPaddle().getPosition().y + enemy_paddle.getPaddle().getSize().y 
                                                    && circlePosition.y + CIRCLE_RADIUS > enemy_paddle.getPaddle().getPosition().y
                                                    )
                                                {
                                                    // Collisions
                                                    player_paddle.hittingBall(sound_buffer, bonk);
                                                    enemy_paddle.hittingBall(sound_buffer, bonk);
                                                    xVelocity *= -1;
                                                }

                                                if(circlePosition.x < player_paddle.getPaddle().getPosition().x + player_paddle.getPaddle().getSize().x 
                                                    && circlePosition.x > player_paddle.getPaddle().getPosition().x
                                                    && circlePosition.y + CIRCLE_RADIUS < player_paddle.getPaddle().getPosition().y + player_paddle.getPaddle().getSize().y
                                                    && circlePosition.y + CIRCLE_RADIUS > player_paddle.getPaddle().getPosition().y)
                                                {
                                                    xVelocity = xVelocity+0.2; // speeds up the ball's speed each time the ball hits the player paddle
                                                }


                                                if(circlePosition.x < player_paddle.getPaddle().getPosition().x)
                                                {
                                                    score_enemy++;
                                                    score_board.updateEnemy(score_enemy);
                                                    circlePosition.x = 400;
                                                    circlePosition.y = 100;
                                                    xVelocity = 4;
                                                    yVelocity = 4;
                                                    ball.moveBall(circle, xVelocity, yVelocity, circlePosition);
                                                }

                                                if(circlePosition.x > enemy_paddle.getPaddle().getPosition().x)
                                                {
                                                    score_player++;
                                                    score_board.updatePlayer(score_player);
                                                    circlePosition.x = 400;
                                                    circlePosition.y = 100;
                                                    xVelocity = 4;
                                                    yVelocity = 4;
                                                    ball.moveBall(circle, xVelocity, yVelocity, circlePosition);
                                                }

                                                // To close the unecessary windows
                                                game.getWindow().close();

                                                // clear play window
                                                Play.clear();

                                                // draw elements in backbuffer
                                                player_paddle.drawTo(Play);
                                                enemy_paddle.drawTo(Play);
                                                score_board.drawScore(Play);

                                                Play.draw(circle);
                                                Play.draw(net);

                                                if (score_enemy > 3)
                                                    {
                                                        Play.clear();
                                                        theme.stoppingPlayTheme(play_theme);
                                                        player_paddle.stoppingBall(bonk);
                                                        enemy_paddle.stoppingBall(bonk);
                                                        score_board.loser(Play);
                                                    }

                                                if(score_player > 3)
                                                    {
                                                        Play.clear();
                                                        theme.stoppingPlayTheme(play_theme);
                                                        player_paddle.stoppingBall(bonk);
                                                        enemy_paddle.stoppingBall(bonk);
                                                        score_board.winner(Play);
                                                    }

                                                // display elements in play window
                                                Play.display();
                                        }
                                break;

                                case 1:
                                    game.getWindow().close();
                                break;
                            }
                        break;
                    }
                break;
            }
        }
            game.getWindow().clear();
            game.initBkgSprite();
            menu.drawMenu(game.getWindow());
            game.renderGame();
    }

    return 0;
}
