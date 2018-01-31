#include "Vector2.hpp"

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
	}
}