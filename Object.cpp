#include "Object.h"

Object::Object(int height, int length, int pos_x, int pos_y)
{
	shape.setFillColor(sf::Color::Blue);
	shape.setSize(sf::Vector2f(height, length));
	shape.setOutlineThickness(1.0f);
	shape.setOutlineColor(sf::Color::Black);
	shape.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

float Object::top()
{
	return shape.getPosition().y;
}

float Object::bottom()
{
	return shape.getPosition().y + shape.getGlobalBounds().height;
}

float Object::right()
{
	return shape.getPosition().x + shape.getGlobalBounds().width;
}

float Object::left()
{
	return shape.getPosition().x;
}
