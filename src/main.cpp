#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::VideoMode vm(sf::Vector2u(1920, 1080));
    sf::RenderWindow window(vm, "Zombie Arena");

    Player Player;
    while (window.isOpen()) {
        window.display();
    }
    std::cout << "Hello World!\n";
}