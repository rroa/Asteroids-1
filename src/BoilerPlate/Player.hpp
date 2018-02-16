#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>

#include "Vector2.hpp"
#include "Entity.hpp"

namespace Game
{

	class Player : Entity
	{
	public:
		/* ==========================
		* CTOR
		* ==========================*/
		Player							   ( int, int );

		/* ==========================
		* PUBLIC FUNCTIONS
		* ==========================*/
		void Update						   ( float deltaTime );
		void Render						   ( void );
		void MoveForward				   ( void );
		void Rotateleft					   ( void );
		void RotateRight				   ( void );
		inline void ToggleMove			   ( ) { m_moving = !m_moving; }
	private:
		/* ==========================
		* MEMBERS
		* ==========================*/
		float							   m_angle;
		float							   m_currentSpeed;
		bool							   m_gasOn;
		bool							   m_moving;
		std::vector<Engine::Math::Vector2> m_points;
		/*
		 * PRIVATE FUNCTIONS
		 */
		void ApplyImpulse				   ( Engine::Math::Vector2 );
		void ChangeShip					   ( );
	};
}

#endif // !_PLAYER_H_
