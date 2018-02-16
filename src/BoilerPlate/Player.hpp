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
		void UpdateSize  ( int, int );
		inline void ToggleMove() { m_moving = !m_moving; }
	private:
		/* ==========================
		* MEMBERS
		* ==========================*/
		Engine::Math::Vector2 m_position;
		Engine::Math::Vector2 m_velocity;
		float m_angle;
		float m_mass;
		float m_maxWidth;
		float m_minWidth;
		float m_maxHeight;
		float m_minHeight;
		bool  m_gasOn;
		bool  m_moving;

		/*
		 * PRIVATE FUNCTIONS
		 */
		void CalcMinMax( int, int );
		void ApplyImpulse(Engine::Math::Vector2);
	};
}

#endif // !_PLAYER_H_
