#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Object.h"
#include "Spikes.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>

class Shot : public sf::Drawable
{
public:
    Shot()
    {
        shape.setSize(sizeSetting);
        shape.setFillColor(sf::Color::White);
        shape.move(0.0f, velocity);
    }
    ~Shot() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const
    {
        target.draw(this->shape, state);
    }

    void pif(sf::Vector2f posit)
    {
        shape.setPosition(posit);
    }

private:
    sf::Vector2f sizeSetting{ 5.0f, 2.0f };
    sf::RectangleShape shape;
    float velocity = 5.0f;
};
class HealthBar : public sf::Drawable
{
public:
    HealthBar()
    {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Red);
        shape.setOutlineThickness(1.0f);
        shape.setOutlineColor(sf::Color::Black);
    }
    ~HealthBar() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const
    {
        target.draw(this->shape, state);
    }
    void intersecting()
    {
        shape.setSize(sf::Vector2f(size.x - 20.0f, size.y));
    }

private:
    sf::Vector2f position{ 10.0f, 10.0f };
    sf::Vector2f size{ 100.0f, 10.0f };
    sf::RectangleShape shape;
};

template <class T1, class T2>
bool isIntersecting(T1& player, T2& obiekt)
{
    return player.top() <= obiekt.bottom() && player.bottom() >= obiekt.top() && player.left() <= obiekt.right() && player.right() >= obiekt.left();
}

bool collisionTest(Player& player, Object& obiekt)
{
    if (!isIntersecting(player, obiekt)) return false;

    //std::cout << "collision" << std::endl;
    if (player.top() <= obiekt.bottom() && player.bottom() > obiekt.bottom())
        player.stopUp();
    if (player.bottom() >= obiekt.top() && player.top() < obiekt.top())
        player.stopDown();
    if (player.left() <= obiekt.right() && player.right() > obiekt.right())
        player.stopLeft();
    if (player.right() >= obiekt.left() && player.left() < obiekt.left())
        player.stopRight();
}

bool collisionTest(Player& player, Spikes& obiekt, HealthBar& health)
{
    if (!isIntersecting(player, obiekt)) return false;
    health.intersecting();
    //std::cout << "collision" << std::endl;
    if (player.top() <= obiekt.bottom() && player.bottom() > obiekt.bottom())
        player.stopUp();
    if (player.bottom() >= obiekt.top() && player.top() < obiekt.top())
        player.stopDown();
    if (player.left() <= obiekt.right() && player.right() > obiekt.right())
        player.stopLeft();
    if (player.right() >= obiekt.left() && player.left() < obiekt.left())
        player.stopRight();
}

int main()
{
    srand(time(NULL));

    const float windowHeight = 1080.0f;
    const float windowLength = 1920.0f;

    //Tworzenie okna

    sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "NewRPG Game");
    window.setFramerateLimit(120);

    // Tworzenie t³a
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./Pictures/Background.png");

    sf::Sprite background;
    background.setTexture(backgroundTexture);

    HealthBar bar;

    // Tworzenie gracza
    Player player(windowLength, windowHeight);

    // Tworzenie obiektu
    int objectsData[6][4];

    for (int i = 0; i <= 5; i++)
    {
        objectsData[i][0] = rand() % 20 + 10;
        objectsData[i][1] = rand() % 20 + 10;
        objectsData[i][2] = rand() % 800 + 100;
        objectsData[i][3] = rand() % 1600 + 100;
    }

    std::vector<Object> objects;

    for (int i = 0; i <= 5; i++)
    {
        objects.emplace_back(objectsData[i][0], objectsData[i][1], objectsData[i][2], objectsData[i][3]);
    }

    // Tworzenie gwiazdeczek
    int spikesData[6][4];

    for (int i = 0; i <= 5; i++)
    {
        spikesData[i][0] = rand() % 20 + 10;
        spikesData[i][1] = rand() % 6 + 4;
        spikesData[i][2] = rand() % 800 + 100;
        spikesData[i][3] = rand() % 1600 + 100;
    }

    std::vector<Spikes> spikes;

    for (int i = 0; i <= 5; i++)
    {
        spikes.emplace_back(spikesData[i][0], spikesData[i][1], spikesData[i][2], spikesData[i][3]);
    }

    // Tworzenie strza³ów
    Shot bullet;
    

    // Glowna petla gry
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(bar);
        window.draw(player);
        for (auto& obiekt : objects)
        {
            window.draw(obiekt);
        }
        for (auto& spike : spikes)
        {
            window.draw(spike);
        }
        player.update();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            bullet.pif(player.getPos());
            window.draw(bullet);
        }
        for (auto& obiekt : objects)
        {
            collisionTest(player, obiekt);
        }
        
        for (auto& spike : spikes)
        {
            collisionTest(player, spike, bar);
        }
        window.display();
    }

    return 0;
}