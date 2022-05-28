#pragma once
#include "types.hpp"

template<typename T>
struct Vector2 {
    T x, y;
    Vector2(T _x, T _y) : x(_x), y(_x) {};
    template<typename U>
    explicit Vector2(Vector2<U> const& other_vector) : x(other_vector.x), y(other_vector.y) {}
    Vector2<T> operator+(Vector2<T> const& other_vector) const {
        return { x + other_vector.x, y + other_vector.y };
    }
};

using Vector2i = Vector2<i32>;
using Vector2u = Vector2<u32>;
using Vector2f = Vector2<f32>;
