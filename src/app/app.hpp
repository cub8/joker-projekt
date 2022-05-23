#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../utils/types.hpp"
#include "../utils/vector2.hpp"


class App {
public:
    App(i32 width, i32 height);
    ~App();

    void program_loop();
private:
    sf::RenderWindow* window;
    sf::Event event;

    void init_window(i32 width, i32 height);
    void update();
    void render();
    void poll_events();
    void handle_keyboard_events(sf::Keyboard::Key pressed_key);
};

