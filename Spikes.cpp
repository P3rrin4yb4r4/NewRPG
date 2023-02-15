#include "Spikes.h"

Spikes::Spikes(int rad, int point, int pos_x, int pos_y)
{
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(rad);
	shape.setPointCount(point);
	shape.setOutlineThickness(1.0f);
	shape.setOutlineColor(sf::Color::Black);
	shape.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Spikes::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

float Spikes::top()
{
	return shape.getPosition().y;
}

float Spikes::bottom()
{
	return shape.getPosition().y + shape.getGlobalBounds().height;
}

float Spikes::right()
{
	return shape.getPosition().x + shape.getGlobalBounds().width;
}

float Spikes::left()
{
	return shape.getPosition().x;
}
