#pragma once

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

namespace Engine
{
	namespace Math
	{
		struct Vector2
		{
			/* ==========================
			 * STATIC
			 * ==========================*/
			static Vector2 Origin;

			 /* ==========================
			 * CTOR
			 * ==========================*/
			Vector2( );
			Vector2( float, float );
			Vector2( float );

			 /* ==========================
			 * PUBLIC FUNCTIONS
			 * ==========================*/
			float   Length( ) const;
			float   SquaredLength( ) const;
			float	Normalize( );
			
			/* ==========================
			 * OPERATORS
			 * ==========================*/
			Vector2& operator= ( const Vector2& );
			Vector2& operator+=( const Vector2& );
			Vector2& operator-=( const Vector2& );
			Vector2& operator*=( const Vector2& );
			Vector2& operator/=( const Vector2& );
			Vector2  operator+( const Vector2& ) const;
			Vector2  operator-(const Vector2& ) const;
			Vector2  operator*(const Vector2& ) const;
			Vector2  operator/(const Vector2& ) const;
			bool     operator==( const Vector2& ) const;
			bool     operator!=(const Vector2& ) const;
			friend Vector2 operator*(float, const Vector2&);
			friend Vector2 operator*(const Vector2&, float);

			 /* ==========================
			 * MEMBERS
			 * ==========================*/
			float x;
			float y;
			float length;
		};
	}
}

#endif // !_VECTOR2_H_
