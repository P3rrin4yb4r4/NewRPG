#include "Player.h"

Player::Player(float pos_x, float pos_y)
{
    shape.setSize(sf::Vector2f(this->dimension, this->dimension));
    shape.setFillColor(sf::Color::Cyan);
    shape.setOutlineThickness(1.5f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setPosition(sf::Vector2f(pos_x/2, pos_y/2));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}

void Player::update()
{
    shape.move(this->velocity);

    // Ruch w gore
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        velocity.y -= acceleration;
        if (std::abs(velocity.y) >= playerVelocity)
            velocity.y = -playerVelocity;
    }

    // Ruch w dol
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        velocity.y += acceleration;
        if (std::abs(velocity.y) >= playerVelocity)
            velocity.y = playerVelocity;
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)))
    {
        if (velocity.y > 0.1)
            velocity.y -= acceleration;
        if (velocity.y < -0.1)
            velocity.y += acceleration;
        if (velocity.y < 0.1 && velocity.y > -0.1)
            velocity.y = 0.0f;
    }

    // Ruch w prawo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        velocity.x += acceleration;
        if (std::abs(velocity.x) >= playerVelocity)
            velocity.x = playerVelocity;
    }

    // Ruch w lewo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        velocity.x -= acceleration;
        if (std::abs(velocity.x) >= playerVelocity)
            velocity.x = -playerVelocity;
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
    {
        if (velocity.x > 0.1)
            velocity.x -= acceleration;
        if (velocity.x < -0.1)
            velocity.x += acceleration;
        if (velocity.x < 0.1 && velocity.x > -0.1)
            velocity.x = 0.0f;
    }
}

sf::Vector2f Player::getPos()
{
    return shape.getPosition();
}
float Player::top()
{
    return shape.getPosition().y;
}

float Player::bottom()
{
    return shape.getPosition().y + this->dimension;
}

float Player::right()
{
    return shape.getPosition().x + this->dimension;
}

float Player::left()
{
    return shape.getPosition().x;
}

void Player::stopLeft()
{
    this->shape.setPosition(sf::Vector2f(shape.getPosition().x + 1.5, shape.getPosition().y));
}

void Player::stopRight()
{
    this->shape.setPosition(sf::Vector2f(shape.getPosition().x - 1.5, shape.getPosition().y));
}

void Player::stopUp()
{
    this->shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y + 1.5));
}

void Player::stopDown()
{
    this->shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y - 1.5));
}