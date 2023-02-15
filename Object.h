#pragma once
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <ctime>


class Object :
    public sf::Drawable
{
public:
    Object(int height, int length, int pos_x, int pos_y);
    ~Object() = default;
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    float top();
    float bottom();
    float right();
    float left();

private:
    sf::RectangleShape shape;

};

