/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Core
*/

#include "Core.hpp"

static void init_texture(std::pair<sf::Texture, sf::Sprite> &texture, std::string path, int x, int y, int width, int height)
{
    texture.first.loadFromFile(path);
    texture.second.setTexture(texture.first);
    texture.second.setPosition(x, y);
    texture.second.setTextureRect(sf::IntRect(0, 0, width, height));
}

Core::Core()
{
    this->window.create(sf::VideoMode(800, 600), "Snake");
    this->window.setFramerateLimit(60);
    this->event = sf::Event();
    images["background"] = std::make_pair(sf::Texture(), sf::Sprite());
    init_texture(images["background"], "asset/Background.png", 0, 0, 800, 600);
    //snake = Snake();
}

Core::~Core()
{
}

void Core::HandleEvent()
{
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window.close();
    }
}

void Core::run()
{
    while (this->window.isOpen()) {
        this->window.clear();
        this->window.draw(this->images["background"].second);
        //this->snake.print(this->window);
        this->HandleEvent();
        this->window.display();
    }
}
