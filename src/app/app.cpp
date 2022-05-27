#include "app.hpp"

App::App(i32 width, i32 height) {
    init_window(width,  height);
    perlin_noise_array = nullptr;
}

App::~App() {
    delete[] perlin_noise_array;
}

void App::program_loop() {
    while(window.isOpen()) {
        update();
        render();
    }
}

void App::init_window(i32 width, i32 height) {
    sf::VideoMode video_mode;
    video_mode.height = width;
    video_mode.width = height; 

    window.create(video_mode, "Perlin noise visualization", sf::Style::Default);
    window.setFramerateLimit(30);
}

void App::update() {
    poll_events();
}

void App::render() {
    window.clear(sf::Color::Black);
    handle_modes_drawing();
    window.display();
}

void App::poll_events(){
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                handle_keyboard_events();
                handle_modes_events();
                break;
            default: break;
        }
    }
}

void App::handle_keyboard_events() {
    switch(event.key.code) {
        case sf::Keyboard::Escape:
            window.close();
            break;
        case sf::Keyboard::Num0:
            delete[] perlin_noise_array;
            perlin_noise_array = nullptr;
            mode = 0;
            bias = 0.0f;
            octaves = 0;            
            break;
        case sf::Keyboard::Num1:
            mode = 1;
            delete[] perlin_noise_array;
            perlin_noise_array = nullptr;
            perlin_noise_generator.refill_noise_array(PERLIN_1D_ARRAY_SIZE);
            bias = 2.0f;
            octaves = 4;
            perlin_noise_array = perlin_noise_generator.generate_perlin_noise(PERLIN_1D_ARRAY_SIZE, octaves, bias);
            break;
        case sf::Keyboard::Num2:
            mode = 2;
            if (perlin_noise_array != nullptr) {
                delete[] perlin_noise_array;
                perlin_noise_array = nullptr;
            }
            bias = 2.0f;
            octaves = 4;
            // refill array
            break;
        case sf::Keyboard::Num3:
            mode = 3;
            delete[] perlin_noise_array;
            perlin_noise_array = nullptr;
            bias = 2.0f;
            octaves = 4;
            // refill array
            break;
        default: break;
    }
}

void App::handle_modes_events() {
    switch (mode) {
        case 1:
            handle_mode_1_keyboard_events();
            break;
        case 2:
            handle_mode_2_keyboard_events();
            break;
        case 3:
            handle_mode_3_keyboard_events();
            break;
    }
}

void App::handle_mode_1_keyboard_events() {
    switch(event.key.code) {
        case sf::Keyboard::R:
            perlin_noise_generator.refill_noise_array(PERLIN_1D_ARRAY_SIZE);
            break;
        case sf::Keyboard::Q:
            octaves--;
            break;
        case sf::Keyboard::E:
            octaves++;
            break;
        case sf::Keyboard::Z:
            bias -= 0.2f;
            break;
        case sf::Keyboard::C:
            bias += 0.2f;
            break;
        case sf::Keyboard::K:
            drawing_mode_1d = 'k';
            break;
        case sf::Keyboard::L:
            drawing_mode_1d = 'l';
            break;
        default: break;
    }
    if (bias < 0.2f) bias = 0.2f;
    if (octaves == 0) octaves = 1;
    if (octaves == 9) octaves = 8;

    perlin_noise_array = perlin_noise_generator.generate_perlin_noise(PERLIN_1D_ARRAY_SIZE, octaves, bias);
}

void App::handle_mode_2_keyboard_events() {

}

void App::handle_mode_3_keyboard_events() {

}

void App::handle_modes_drawing() {
    switch(mode) {
        case 1:
            if (drawing_mode_1d == 'k')
                noise_drawer.draw_1d_block_noise(PERLIN_1D_ARRAY_SIZE, perlin_noise_array, window);
            else
                noise_drawer.draw_1d_lines_noise(PERLIN_1D_ARRAY_SIZE, perlin_noise_array, window);
            break;
        case 2: break;
        case 3: break;
    }
}
