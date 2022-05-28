#pragma once

#include "widget.hpp"
#include <vector>

class GUI{

    public:
    GUI();
    void draw(sf::RenderWindow & window) const;
    void update();
    void handle_events(sf::Event & event);


    private:
    std::vector<Widget *> widgets;
};