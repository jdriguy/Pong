#include <SFML/Ball.hpp>

Ball::Ball(sf::CircleShape &shape, float angle, sf::Color color)
{
    shape.setRadius(angle);
    shape.setFillColor(color);
}

void Ball::moveBall(sf::CircleShape &shape, float &xVelocity, float &yVelocity, sf::Vector2f &circlePosition)
{
    if (circlePosition.x < 0 || circlePosition.x > VIDEO_WIDTH-CIRCLE_RADIUS) xVelocity*= -1; // invert velocity
    if (circlePosition.y < 0 || circlePosition.y > VIDEO_HEIGHT-CIRCLE_RADIUS) yVelocity*= -1; // invert velocity

    circlePosition.x += xVelocity; // x = x0 +v*t constant velocity motion rectilinear uniform motion with x = position
    circlePosition.y += yVelocity;
    shape.setPosition(circlePosition);
}


Ball::Ball()
{

}

Ball::~Ball()
{

}