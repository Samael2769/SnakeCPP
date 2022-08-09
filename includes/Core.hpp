/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>


#include "Snake.hpp"

class Core {
    public:
        Core();
        ~Core();
        void run();
        void HandleEvent();
        void updateScore();
        Snake snake;
        sf::RenderWindow window;
        sf::Event event;
        std::map<std::string, std::pair<sf::Texture, sf::Sprite>> images;
        sf::Text text;
        sf::Font font;
    protected:
    private:
};

#endif /* !CORE_HPP_ */
