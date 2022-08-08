/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Snake {
    public:
      Snake();
      ~Snake();
      void print(sf::RenderWindow &window);
      void update();
      void setDirection(float x, float y) {_directionx = x; _directiony = y;}
    protected:
    private:
      sf::CircleShape _head;
      std::vector<sf::RectangleShape> _body;
      float _directionx = 10;
      float _directiony = 0;
};

#endif /* !SNAKE_HPP_ */
