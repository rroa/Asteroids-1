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
		Player( int, int );

		/* ==========================
		* PUBLIC FUNCTIONS
		* ==========================*/
		void Update      ( void );
		void Render      ( void );
		void Move        ( const Engine::Math::Vector2& unit );
		void MoveForward ( void );
		void Rotateleft  ( void );
		void RotateRight ( void );
	private:
		/* ==========================
		* MEMBERS
		* ==========================*/
		Engine::Math::Vector2* m_position;
		float m_maxWidth;
		float m_minWidth;
		float m_maxHeight;
		float m_minHeight;
	};
}

#endif // !_PLAYER_H_
