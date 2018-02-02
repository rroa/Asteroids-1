#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Vector2.hpp"

namespace Game
{

	class Player
	{
	public:
		/* ==========================
		* CTOR
		* ==========================*/
		Player( );

		/* ==========================
		* PUBLIC FUNCTIONS
		* ==========================*/
		void Update( );
		void Render( );
		void Move( const Engine::Math::Vector2& unit );
	private:
		/* ==========================
		* MEMBERS
		* ==========================*/
		Engine::Math::Vector2* m_position;
	};
}

#endif // !_PLAYER_H_
