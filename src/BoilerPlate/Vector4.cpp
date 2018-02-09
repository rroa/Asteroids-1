#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#include <cmath>

namespace Engine
{
	namespace Math
	{
		Vector4 Vector4::Origin = Vector4();

		Vector4::Vector4()
			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
			, w(0.0f)
			, length(0.0f)
		{}

		Vector4::Vector4(float _x, float _y, float _z, float _w)
			: x(_x)
			, y(_y)
			, z(_z)
			, w(_w)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		Vector4::Vector4(float _uniform)
			: x(_uniform)
			, y(_uniform)
			, z(_uniform)
			, w(_uniform)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		Vector4::Vector4(const Vector2& vec2)
			: x(vec2.x)
			, y(vec2.y)
			, z(0.0f)
			, w(0.0f)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		Vector4::Vector4(const Vector3& vec3)
			: x(vec3.x)
			, y(vec3.y)
			, z(vec3.z)
			, w(0.0f)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		float Vector4::Length() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		float Vector4::SquaredLength() const
		{
			return x * x + y * y + z * z;
		}

		float Vector4::Normalize()
		{
			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;
			z *= inverseScale;

			return length;
		}

		Vector4& Vector4::operator=(const Vector4& rhs)
		{
			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}

		Vector4& Vector4::operator+=(const Vector4& rhs)
		{
			x = x + rhs.x;
			y = y + rhs.y;
			z = z + rhs.z;

			return *this;
		}

		Vector4& Vector4::operator-=(const Vector4& rhs)
		{
			x = x - rhs.x;
			y = y - rhs.y;
			z = z - rhs.z;

			return *this;
		}

		Vector4& Vector4::operator*=(const Vector4& rhs)
		{
			x = x * rhs.x;
			y = y * rhs.y;
			z = z * rhs.z;

			return *this;
		}

		Vector4& Vector4::operator/=(const Vector4& rhs)
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;
			z = z / rhs.z;

			return *this;
		}


		Vector4 Vector4::operator+(const Vector4& rhs) const
		{
			return Vector4(
				x + rhs.x,
				y + rhs.y,
				z + rhs.z,
				w + rhs.w);
		}

		Vector4 Vector4::operator-(const Vector4& rhs) const
		{
			return Vector4(
				x - rhs.x,
				y - rhs.y,
				z - rhs.z,
				w - rhs.w);
		}

		Vector4 Vector4::operator*(const Vector4& rhs) const
		{
			return Vector4(
				x * rhs.x,
				y * rhs.y,
				z * rhs.z,
				w * rhs.w);
		}

		Vector4 Vector4::operator/(const Vector4& rhs) const
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			return Vector4(
				x / rhs.x,
				y / rhs.y,
				z / rhs.z,
				w / rhs.w);
		}

		bool Vector4::operator==(const Vector4& rhs) const
		{
			return
				x == rhs.x &&
				y == rhs.y &&
				z == rhs.z &&
				w == rhs.w;
		}

		bool Vector4::operator!=(const Vector4& rhs) const
		{
			return
				x != rhs.x ||
				y != rhs.y ||
				z != rhs.z ||
				w != rhs.w;
		}

		Vector4 operator*(float scaleUnit, const Vector4& rhs)
		{
			return Vector4(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y,
				scaleUnit * rhs.z,
				scaleUnit * rhs.w);
		}

		Vector4 operator*(const Vector4& lhs, float scaleUnit)
		{
			return Vector4(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y,
				scaleUnit * lhs.z,
				scaleUnit * lhs.w);
		}
	}
}