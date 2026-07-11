#pragma once
#include <cmath>

namespace ChiefEngine {
	class Vector2 {
	public:
		float x, y;

		Vector2() = default;
		Vector2(float v) : x{ v }, y{ v } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}

		float GetX() const { return this->x; }
		float GetY() const { return this->y; }
		float LengthSqr() const { return (x * x) + (y * y); }
		float Length() const { return std::sqrt(LengthSqr()); }

		Vector2 operator+(const Vector2& other) const { return Vector2(this->x + other.x, this->y + other.y); }
		Vector2 operator-(const Vector2& other) const { return Vector2(this->x - other.x, this->y - other.y); }
		Vector2 operator*(const Vector2& other) const { return Vector2(this->x * other.x, this->y * other.y); }
		Vector2 operator/(const Vector2& other) const { return Vector2(this->x / other.x, this->y / other.y); }

		Vector2 operator+(float val) const { return Vector2(this->x + val, this->y + val); }
		Vector2 operator-(float val) const { return Vector2(this->x - val, this->y - val); }
		Vector2 operator*(float val) const { return Vector2(this->x * val, this->y * val); }
		Vector2 operator/(float val) const { return Vector2(this->x / val, this->y / val); }

		Vector2 operator+=(const Vector2& other) { this->x += other.x; this->y += other.y; return *this; }
		Vector2 operator-=(const Vector2& other) { this->x -= other.x; this->y -= other.y; return *this; }
		Vector2 operator*=(const Vector2& other) { this->x *= other.x; this->y *= other.y; return *this; }
		Vector2 operator/=(const Vector2& other) { this->x /= other.x; this->y /= other.y; return *this; }

		Vector2 operator+=(float val) { this->x += val; this->y += val; return *this; }
		Vector2 operator-=(float val) { this->x -= val; this->y -= val; return *this; }
		Vector2 operator*=(float val) { this->x *= val; this->y *= val; return *this; }
		Vector2 operator/=(float val) { this->x /= val; this->y /= val; return *this; }
	};
}