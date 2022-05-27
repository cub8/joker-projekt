#include "noise_drawer.hpp"
#include <SFML/Graphics/PrimitiveType.hpp>

void NoiseDrawer::draw_1d_block_noise(u32 array_size, f32* noise_array, sf::RenderWindow& window) {
    sf::Vector2u size = window.getSize();
    f32 width = (f32)size.x / array_size;

    for (i32 x = 0; x < array_size; x++) {
        sf::RectangleShape noise_height(sf::Vector2f(width, -noise_array[x] * size.y / 1.8f));
        noise_height.setFillColor(sf::Color(66, 173, 245));
        noise_height.setPosition(sf::Vector2f(width * x, size.y * 0.75));

        window.draw(noise_height);
    }
}

void NoiseDrawer::draw_1d_lines_noise(u32 array_size, f32 *noise_array, sf::RenderWindow &window) {
    sf::Vector2u size = window.getSize();
    f32 width = (f32)size.x / array_size;

    for (i32 x = 0; x < array_size - 1; x++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(width * x, size.y * 0.75 - noise_array[x] * size.y / 1.8f), sf::Color::Red),
            sf::Vertex(sf::Vector2f(width * (x + 1), size.y * 0.75 - noise_array[x + 1] * size.y / 1.8f), sf::Color::Red)
        };
        
        window.draw(line, 2, sf::Lines);
    }

    sf::Vertex bottom_line[] = {
        sf::Vertex(sf::Vector2f(0, size.y * 0.75), sf::Color::Red),
        sf::Vertex(sf::Vector2f(size.x - 1, size.y * 0.75), sf::Color::Red)
    };

    window.draw(bottom_line, 2, sf::Lines);
}
