#pragma once

#include <cmath>
namespace nsflow {
struct Vec2 {
    double x, y;
    bool operator==(const Vec2 &) const = default;
};
inline Vec2 operator+(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; };

inline Vec2 operator-(Vec2 a, Vec2 b) { return {a.x - b.x, a.y - b.y}; };

inline Vec2 operator-(Vec2 a) { return {-a.x, -a.y}; };

inline Vec2 operator*(double s, Vec2 b) { return {s * b.x, s * b.y}; };

inline Vec2 operator*(Vec2 b, double s) { return {s * b.x, s * b.y}; };

inline Vec2 operator/(Vec2 b, double s) { return {b.x / s, b.y / s}; };

inline double norm_squared(Vec2 v) { return v.x*v.x +v.y*v.y; };

inline double norm(Vec2 v) { return std::sqrt(norm_squared(v)); };

inline double dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; };

struct Index2 {
    int i, j;
};
inline Index2 operator+(Index2 a, Index2 b) { return {a.i + b.i, a.j + b.j}; }

inline Index2 operator-(Index2 a, Index2 b) { return {a.i - b.i, a.j - b.j}; }

} // namespace nsflow