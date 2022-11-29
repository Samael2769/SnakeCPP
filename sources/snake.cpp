/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Snake
*/

#include "Snake.hpp"
#include <iostream>
#include <cstdlib>


std::vector<sf::Color> colors = {sf::Color::Yellow, sf::Color::Green, sf::Color::Cyan, sf::Color::Blue, sf::Color::Magenta, sf::Color::Red};
int color = 0;

Snake::Snake()
{
    _head = sf::CircleShape(15);
    _head.setFillColor(colors[color]);
    color++;
    if (color >= colors.size())
        color = 0;
    _head.setPosition(sf::Vector2f(400, 300));
    _head.setOrigin(sf::Vector2f(_head.getRadius(), _head.getRadius()));

    for (int i = 0; i < 3; ++i) {
        sf::RectangleShape body;
        int pad = 1 * 40;
        if (i == 0)
            pad = 1 * 40;
        else
            pad = (i + 1) * 20;
        body.setSize(sf::Vector2f(20, 20));
        body.setFillColor(colors[color]);
        color++;
        if (color >= colors.size())
            color = 0;
        body.setPosition(sf::Vector2f(400, 300 + pad));
        body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
        _body.push_back(body);
    }
    _food = sf::CircleShape(7);
    _food.setFillColor(sf::Color::Blue);
    randomFoodPos();
}

Snake::~Snake()
{
}

void Snake::randomFoodPos()
{
    int x = rand() % 800;
    int y = rand() % 600;
    _food.setPosition(sf::Vector2f(x, y));
}

static bool Collide(sf::Vector2f vec1, sf::Vector2f vec2)
{
    if ((vec1.x > vec2.x - 15 && vec1.x < vec2.x + 15) && (vec1.y > vec2.y - 15 && vec1.y < vec2.y + 15))
        return true;
    return false;
}

void Snake::update()
{
    sf::Vector2f Hpos = _head.getPosition();
    sf::Vector2f newpos;
    _head.move(sf::Vector2f(_directionx, _directiony));
    if (_head.getPosition().x > 800)
        _head.setPosition(sf::Vector2f(0, _head.getPosition().y));
    if (_head.getPosition().x < 0)
        _head.setPosition(sf::Vector2f(800, _head.getPosition().y));
    if (_head.getPosition().y > 600)
        _head.setPosition(sf::Vector2f(_head.getPosition().x, 0));
    if (_head.getPosition().y < 0)
        _head.setPosition(sf::Vector2f(_head.getPosition().x, 600));
    for (int i = 0; i < _body.size(); ++i) {
        sf::Vector2f Bpos = _body[i].getPosition();
        if (i == 0)
            _body[i].setPosition(sf::Vector2f(Hpos.x, Hpos.y));
        else
            _body[i].setPosition(sf::Vector2f(newpos.x, newpos.y));
        newpos = Bpos;
        if (_body[i].getPosition().x >= 800)
            _body[i].setPosition(sf::Vector2f(0, Bpos.y));
        if (_body[i].getPosition().x <= 0)
            _body[i].setPosition(sf::Vector2f(800, Bpos.y));
        if (_body[i].getPosition().y >= 600)
            _body[i].setPosition(sf::Vector2f(Bpos.x, 0));
        if (_body[i].getPosition().y <= 0)
            _body[i].setPosition(sf::Vector2f(Bpos.x, 600));
        if (_head.getPosition().x == _body[i].getPosition().x && _head.getPosition().y == _body[i].getPosition().y) {
            if (_head.getPosition().x > 0 && _head.getPosition().x < 800 && _head.getPosition().y > 0 && _head.getPosition().y < 600)
                throw std::runtime_error("Collision");
                
        }
    }
    if (Collide(_head.getPosition(), _food.getPosition())) {
        sf::RectangleShape body;
        body.setSize(sf::Vector2f(20, 20));
        int k = std::rand() % colors.size();
        body.setFillColor(colors[color]);
        color++;
        if (color >= colors.size())
            color = 0;
        body.setPosition(sf::Vector2f(newpos.x, newpos.y));
        body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
        _body.push_back(body);
        randomFoodPos();
    }
}

void Snake::print(sf::RenderWindow &window)
{
    window.draw(_food);
    window.draw(_head);
    for (auto &body : _body)
        window.draw(body);
}