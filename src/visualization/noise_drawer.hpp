#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../utils/types.hpp"
#include "../utils/vector2.hpp"

class NoiseDrawer {
public:
    void draw_noise(u32 array_size, f32* noise_array, sf::RenderWindow& window);
    void draw_noise(Vector2u array_size, f32* noise_array, sf::RenderWindow& window); // TO DO
};