#pragma once
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <ctime>


class Spikes :
    public sf::Drawable
{
public:
    Spikes(int height, int length, int pos_x, int pos_y);
    ~Spikes() = default;
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    float top();
    float bottom();
    float right();
    float left();

private:
    sf::CircleShape shape;

};

