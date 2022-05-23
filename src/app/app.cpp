#include "app.hpp"

App::App(i32 width, i32 height) {
    init_window(width,  height);
}

App::~App() {
    delete this->window;
}

void App::program_loop() {
    while(window->isOpen()) {
        update();
        render();
    }
}

void App::init_window(i32 width, i32 height) {
    window = nullptr;
    sf::VideoMode video_mode;
    video_mode.height = width;
    video_mode.width = height; 

    window = new sf::RenderWindow(video_mode, "Perlin noise visualization", sf::Style::Titlebar | sf::Style::Close);
}

void App::update() {
    poll_events();
}

void App::render() {
    window->clear(sf::Color::Black);
    window->display();
}

void App::poll_events(){
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                handle_keyboard_events(event.key.code);
                break;
        }
    }
}

void App::handle_keyboard_events(sf::Keyboard::Key pressed_key) {
    switch(pressed_key) {
        case sf::Keyboard::Escape:
            window->close();
            break;
    }
}
