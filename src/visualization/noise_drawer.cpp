#include "noise_drawer.hpp"

void NoiseDrawer::draw_noise(u32 array_size, f32* noise_array, sf::RenderWindow& window) {
    sf::Vector2u size = window.getSize();
    f32 width = (f32)size.x / array_size;

    for (i32 x = 0; x < array_size; x++) {
        sf::RectangleShape noise_height(sf::Vector2f(width, -noise_array[x] * size.y / 1.8f));
        noise_height.setFillColor(sf::Color(66, 173, 245));
        noise_height.setPosition(sf::Vector2f(width * x, size.y * 0.75));

        window.draw(noise_height);
    }
}