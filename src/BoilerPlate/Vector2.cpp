#include "Vector2.hpp"
#include <cmath>

namespace Engine
{
	namespace Math
	{
		Vector2 Vector2::Origin = Vector2();

		Vector2::Vector2()
			: x		 ( 0.0f )
			, y		 ( 0.0f )
			, length ( 0.0f )
		{}

		Vector2::Vector2(float _x, float _y)
			: x		 ( _x )
			, y		 ( _y )
			, length ( 0.0f )
		{
			// Calculate Length
			Length();
		}

		Vector2::Vector2(float _uniform)
			: x		 ( _uniform )
			, y		 ( _uniform )
			, length ( 0.0f )
		{
			// Calculate Length
			Length();
		}

		float Vector2::Length() const
		{
			return std::sqrt(x * x + y * y);
		}

		float Vector2::SquaredLength() const
		{
			return x * x + y * y;
		}

		float Vector2::Normalize()
		{
			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;

			return length;
		}

		Vector2& Vector2::operator=(const Vector2& rhs)
		{
			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;

			return *this;
		}

		Vector2& Vector2::operator+=(const Vector2& rhs)
		{
			x = x + rhs.x;
			y = y + rhs.y;

			return *this;
		}

		Vector2& Vector2::operator-=(const Vector2& rhs)
		{
			x = x - rhs.x;
			y = y - rhs.y;

			return *this;
		}

		Vector2& Vector2::operator*=(const Vector2& rhs)
		{
			x = x * rhs.x;
			y = y * rhs.y;

			return *this;
		}

		Vector2& Vector2::operator/=(const Vector2& rhs)
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;

			return *this;
		}


		Vector2 Vector2::operator+(const Vector2& rhs) const
		{
			return Vector2(
				x + rhs.x,
				y + rhs.y);			
		}

		Vector2 Vector2::operator-(const Vector2& rhs) const
		{
			return Vector2(
				x - rhs.x,
				y - rhs.y);
		}

		Vector2 Vector2::operator*(const Vector2& rhs) const
		{
			return Vector2(
				x * rhs.x,
				y * rhs.y);
		}

		Vector2 Vector2::operator/(const Vector2& rhs) const
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";

			return Vector2(
				x / rhs.x,
				y / rhs.y);
		}

		bool Vector2::operator==(const Vector2& rhs) const
		{
			return 
				x == rhs.x &&
				y == rhs.y;
		}

		bool Vector2::operator!=(const Vector2& rhs) const
		{
			return
				x != rhs.x ||
				y != rhs.y;
		}

		Vector2 operator*(float scaleUnit, const Vector2& rhs)
		{
			return Vector2(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y);
		}

		Vector2 operator*(const Vector2& lhs, float scaleUnit)
		{
			return Vector2(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y);
		}
	}
}