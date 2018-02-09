#include "Player.hpp"
#include "IncludeGL.hpp"

namespace Game
{
	Player::Player()
	{
		m_position =
			new Engine::Math::Vector2(Engine::Math::Vector2::Origin);
	}

	void Player::Update()
	{}

	void Player::Move(const Engine::Math::Vector2& unit)
	{
		m_position->x += unit.x;
		m_position->y += unit.y;
	}

	void Player::Render()
	{
		glLoadIdentity();

		// Translates a vector
		glTranslatef(m_position->x, m_position->y, 0.0f);

		// Draws a square
		glBegin(GL_LINE_LOOP);
			glVertex2f(50.0, 50.0);
			glVertex2f(50.0, -50.0);
			glVertex2f(-50.0, -50.0);
			glVertex2f(-50.0, 50.0);
		glEnd();
	}
}