/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Snake.hpp"

class Core {
    public:
        Core();
        ~Core();
        void run();
        void HandleEvent();
        Snake snake;
        sf::RenderWindow window;
        sf::Event event;
        std::map<std::string, std::pair<sf::Texture, sf::Sprite>> images;
    protected:
    private:
};

#endif /* !CORE_HPP_ */
