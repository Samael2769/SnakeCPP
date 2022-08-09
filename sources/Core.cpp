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
    font = sf::Font();
    font.loadFromFile("asset/ASMAN.ttf");
    text = sf::Text("Score: 0", font, 30);
    text.setPosition(10, 10);
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

void Core::updateScore()
{
    int score = this->snake.getSize() - 3;
    this->text.setString("Score: " + std::to_string(score));
}

void Core::run()
{
    while (this->window.isOpen()) {
        this->window.clear();
        this->window.draw(this->images["background"].second);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->snake.getDirectionx() != 10)
            this->snake.setDirection(-10, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->snake.getDirectionx() != -10)
            this->snake.setDirection(10, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->snake.getDirectiony() != 10)
            this->snake.setDirection(0, -10);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->snake.getDirectiony() != -10)
            this->snake.setDirection(0, 10);
        updateScore();
        try {
            this->snake.update();
        } catch (std::exception &e) {
            std::cout << "Game over" << std::endl;
            std::cout << "Score = " << text.getString().toAnsiString().substr(7) << std::endl;
            this->window.close();
        }
        this->snake.print(this->window);
        this->HandleEvent();
        window.draw(text);
        this->window.display();
    }
}
