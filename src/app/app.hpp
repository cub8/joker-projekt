#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../utils/types.hpp"
#include "../utils/vector2.hpp"
#include "../perlin_utilities/perlin_noise_generator.hpp"
#include "../visualization/noise_drawer.hpp"

class App {
public:
    App(i32 width, i32 height);
    ~App();

    void program_loop();
private:
    sf::RenderWindow window;
    sf::Event event;
    f32* perlin_noise_array;
    u32 mode = 0;
    i8 drawing_mode_1d = 'k';
    PerlinNoiseGenerator perlin_noise_generator;
    NoiseDrawer noise_drawer;
    u32 octaves;
    f32 bias;

    const u32 PERLIN_1D_ARRAY_SIZE = 1024;
    const Vector2u PERLIN_2D_ARRAY_SIZE = { 512, 512 };

    void init_window(i32 width, i32 height);
    void update();
    void render();
    void poll_events();
    void handle_keyboard_events();
    void handle_modes_events();

    void handle_mode_1_keyboard_events();
    void handle_mode_2_keyboard_events(); // TO DO
    void handle_mode_3_keyboard_events(); // TO DO

    void handle_modes_drawing();
};

