#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player(float pos_x, float pos_y);
	~Player() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	void update();
	float top();
	float bottom();
	float right();
	float left();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	sf::Vector2f getPos();

private:
	sf::RectangleShape shape;
	float dimension = 20.0f;
	sf::Vector2f velocity{ 0.0f, 0.0f };
	float acceleration = 0.06f;
	float playerVelocity{ 1.2f };
};

#endif