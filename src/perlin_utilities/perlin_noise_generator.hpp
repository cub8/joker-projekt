#include "../utils/types.hpp"
#include "../utils/vector2.hpp"
#include <random>

class PerlinNoiseGenerator {
public:
    f32* generate_perlin_noise(u32 array_size, u32 octaves, f32 bias, i32* seed = nullptr);
    f32* generate_perlin_noise(Vector2u array_size, u32 octaves, u32 bias, i32* seed = nullptr);
private:
    f32* generate_noise(u32 array_size, i32* seed = nullptr);
    f32* generate_noise(Vector2u array_size, i32* seed = nullptr);
};