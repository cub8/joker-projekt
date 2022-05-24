#pragma once
#include <random>
#include "../utils/types.hpp"
#include "../utils/vector2.hpp"

class PerlinNoiseGenerator {
public:
    ~PerlinNoiseGenerator();
    void refill_noise_array(const u32 array_size, i32* seed = nullptr);
    void refill_noise_array(const Vector2u array_size, i32* seed = nullptr); // TO DO
    f32* generate_perlin_noise(const u32 array_size, u32 octaves, f32 bias);
    f32* generate_perlin_noise(Vector2u array_size, u32 octaves, u32 bias); // TO DO
private:
    f32* noise_array;

    f32* generate_noise(u32 array_size, i32* seed);
    f32* generate_noise(Vector2u array_size, i32* seed); // TO DO
};