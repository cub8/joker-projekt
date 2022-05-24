#include "perlin_noise_generator.hpp"
#include <random>

PerlinNoiseGenerator::~PerlinNoiseGenerator() {
    delete[] noise_array;
}

void PerlinNoiseGenerator::refill_noise_array(const u32 array_size, i32* seed) {
    delete[] noise_array;
    noise_array = generate_noise(array_size, seed);
}

f32* PerlinNoiseGenerator::generate_perlin_noise(const u32 array_size, u32 octaves, f32 bias) {
    f32* perlin_noise = new f32[array_size];

    for (i32 x = 0; x < array_size; x++) {
        f32 noise = 0.0f;
        f32 scale = 1.0f;
        f32 scale_accumulator = 0.0f;

        for (i32 o = 0; o < octaves; o++) {
            i32 pitch    = array_size >> o;
            i32 sample_1 = (x / pitch) * pitch;
            i32 sample_2 = (sample_1 + pitch) % array_size;
            f32 blend    = static_cast<f32>(x - sample_1) / static_cast<f32>(pitch);
            f32 sample   = (1.0f - blend) * this->noise_array[sample_1] + blend * this->noise_array[sample_2];

            noise += sample * scale;
            scale_accumulator += scale;
            scale /= bias;
        }
        perlin_noise[x] = noise / scale_accumulator; 
    }

    return perlin_noise;
}

f32* PerlinNoiseGenerator::generate_noise(u32 array_size, i32* seed) {
    std::mt19937_64 gen(seed ? std::mt19937_64(*seed) : std::mt19937_64(std::random_device()()));
    std::uniform_real_distribution<f32> dist(0, 1);
    f32* noise_array = new f32[array_size];

    for (u32 x = 0; x < array_size; x++) {
        noise_array[x] = dist(gen);
    }

    return noise_array;
}
