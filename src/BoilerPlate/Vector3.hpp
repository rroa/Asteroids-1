#pragma once

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace Engine
{
	namespace Math
	{
		struct Vector3
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static Vector3 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			Vector3();
			Vector3(float, float, float);
			Vector3(float);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   Length() const;
			float   SquaredLength() const;
			float	Normalize();

			/* ==========================
			* OPERATORS
			* ==========================*/
			Vector3& operator= (const Vector3&);
			Vector3& operator+=(const Vector3&);
			Vector3& operator-=(const Vector3&);
			Vector3& operator*=(const Vector3&);
			Vector3& operator/=(const Vector3&);
			Vector3  operator+(const Vector3&) const;
			Vector3  operator-(const Vector3&) const;
			Vector3  operator*(const Vector3&) const;
			Vector3  operator/(const Vector3&) const;
			bool     operator==(const Vector3&) const;
			bool     operator!=(const Vector3&) const;
			friend Vector3 operator*(float, const Vector3&);
			friend Vector3 operator*(const Vector3&, float);

			/* ==========================
			* MEMBERS
			* ==========================*/
			float x;
			float y;
			float z;
			float length;
		};
	}
}

#endif // !_VECTOR3_H_