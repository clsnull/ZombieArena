#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    enum class State
    {
        PAUSED,
        LEVELING_UP,
        GAME_OVER,
        PLAYING
    };

    State state = State::GAME_OVER;

    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().size.x;
    resolution.y = sf::VideoMode::getDesktopMode().size.y;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(resolution.x, resolution.y)), "title", sf::Style::Default);
    sf::View mainView(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(0, 0)));

    sf::Clock clock;

    sf::Time gameTimeTotal;

    sf::Vector2i mouseWorldPosition;
    sf::Vector2i mouseScreenPosition;
    Player player;

    sf::IntRect arena;
    while (window.isOpen())
    {
        
        while (std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::KeyPressed>())
            {
                sf::Keyboard::Key code = event->getIf<sf::Event::KeyPressed>()->code;
                if (code == sf::Keyboard::Key::Enter && state == State::PLAYING)
                {
                    state = State::PAUSED;
                    std::cout << "游戏暂停\n";
                }
                else if (code == sf::Keyboard::Key::Enter && state == State::PAUSED)
                {
                    state = State::PLAYING;
                    clock.restart();
                    std::cout << "游戏PLAYING\n";
                }
                else if (code == sf::Keyboard::Key::Enter && state == State::GAME_OVER)
                {
                    std::cout << "游戏LEVELING_UP\n";
                    state = State::LEVELING_UP;
                }
                if (state == State::PLAYING)
                {
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }
        if (state == State::PLAYING)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                std::cout << "moveUp\n";
                player.moveUp();
            }
            else
            {
                std::cout << "stopUp\n";
                player.stopUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                std::cout << "moveDown\n";
                player.moveDown();
            }
            else
            {
                std::cout << "stopDown\n";
                player.stopDown();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                std::cout << "moveLeft\n";
                player.moveLeft();
            }
            else
            {
                std::cout << "stopLeft\n";
                player.stopLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                std::cout << "moveRight\n";
                player.moveRight();
            }
            else
            {
                std::cout << "stopRight\n";
                player.stopRight();
            }
        }
    }
    return 0;
}