#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class App{

    private:
     int window_height;
     int window_width;

     //WindowThings
     sf::RenderWindow* window;
     sf::VideoMode video_mode;
     sf::Event ev;

    void init_variables();
    void init_window(int width, int height);

    public:
    App(int d, int d2);
    virtual ~App();

    const bool get_window_is_open() const;

    void poll_events();
    void update();
    void render();
};

