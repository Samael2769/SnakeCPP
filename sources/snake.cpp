/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake()
{
    _head = sf::CircleShape(5);
    _head.setFillColor(sf::Color::Red);
    _head.setPosition(sf::Vector2f(450, 300));

    for (int i = 0; i < 3; ++i) {
        sf::RectangleShape body;
        body.setSize(sf::Vector2f(5, 5));
        body.setFillColor(sf::Color::Red);
        body.setPosition(sf::Vector2f(450, 300 + i * 5));
        _body.push_back(body);
    }
}

Snake::~Snake()
{
}

void Snake::print(sf::RenderWindow &window)
{
    window.draw(_head);
    for (auto &body : _body)
        window.draw(body);
}