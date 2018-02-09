#include "Player.hpp"
#include "IncludeGL.hpp"

namespace Game
{
	inline float wrap(float x, float min, float max)
	{
		if (x < min) return max - (min - x);
		if (x > max) return min + (x - max);
		return x;
	}

	Player::Player(int width, int height)
	{
		m_position =
			new Engine::Math::Vector2(Engine::Math::Vector2::Origin);

		// TODO: RR: Ewww! Move this out!
		m_maxWidth = width / 2.0f;
		m_minWidth = -width / 2.0f;

		m_maxHeight = height / 2.0f;
		m_minHeight = -height / 2.0f;
	}

	void Player::Update()
	{}

	void Player::Move(const Engine::Math::Vector2& unit)
	{
		float x = m_position->x + unit.x;
		float y = m_position->y + unit.y;
		
		m_position->x = wrap(x, m_minWidth, m_maxWidth);
		m_position->y = wrap(y, m_minHeight, m_maxHeight);
	}

	void Player::Render()
	{
		glLoadIdentity();

		// Translates a vector
		glTranslatef(m_position->x, m_position->y, 0.0f);

		// Draws a square
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.0f, 20.0f);
			glVertex2f(12.0f, -10.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-12.0f, -10.0f);
		glEnd();
	}
}