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
    protected:
    private:
      sf::CircleShape _head;
      std::vector<sf::RectangleShape> _body;
};

#endif /* !SNAKE_HPP_ */
