#include "Player.hpp"
#include "IncludeGL.hpp"
#include <cmath>

namespace Game
{
	const float DRAG_FORCE = 0.999f;
	const float MAX_VELOCITY = 350.0f;
	const float PI = 3.141592653f;
	const float ANGLE_OFFSET = 90.f;
	const float THRUST = 3.0f;

	inline float warp(float x, float min, float max)
	{
		if (x < min) return max - (min - x);
		if (x > max) return min + (x - max);
		return x;
	}

	void Player::CalcMinMax(int width, int height)
	{
		// TODO: RR: Ewww! Move this out!
		m_maxWidth = width / 2.0f;
		m_minWidth = -width / 2.0f;

		m_maxHeight = height / 2.0f;
		m_minHeight = -height / 2.0f;
	}

	Player::Player(int width, int height)
		: m_gasOn(false)
		, m_moving(false)
		, m_angle(0.0f)
		, m_mass(1.0f)
	{
		m_position =
			Engine::Math::Vector2(Engine::Math::Vector2::Origin);

		CalcMinMax(width, height);
	}

	void Player::Update()
	{
		if(!m_moving) m_gasOn = false;
	}

	void Player::Move(const Engine::Math::Vector2& unit)
	{
		float x = m_position.x + unit.x;
		float y = m_position.y + unit.y;

		m_position.x = warp(x, m_minWidth, m_maxWidth);
		m_position.y = warp(y, m_minHeight, m_maxHeight);
	}

	void Player::Render()
	{
		glLoadIdentity();

		// Translates a vector
		glTranslatef(m_position.x, m_position.y, 0.0f);

		// Draws a square
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.0f, 20.0f);
			glVertex2f(12.0f, -10.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-12.0f, -10.0f);
		glEnd();

		if (m_gasOn)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(0.0f, -16.0f);
			glVertex2f(-6.0f, -4.0f);
			glEnd();
		}
	}

	void Player::MoveForward()
	{
		m_gasOn = true;
		m_moving = true;
		ApplyImpulse(Engine::Math::Vector2(THRUST, THRUST));
	}

	void Player::UpdateSize(int width, int height)
	{
		CalcMinMax(width, height);
	}

	void Player::ApplyImpulse(Engine::Math::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			float x = m_position.x;
			float y = m_position.y + THRUST;

			m_position.x = warp(x, m_minWidth, m_maxWidth);
			m_position.y = warp(y, m_minHeight, m_maxHeight);
		}
	}
}