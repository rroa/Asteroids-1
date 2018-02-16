#include "Player.hpp"
#include "IncludeGL.hpp"
#include <cmath>

namespace Game
{
	const float DRAG_FORCE = 0.999f;
	const float MAX_SPEED = 350.0f;
	// TODO: RR: Use Math utils PI
	const float PI = 3.141592653f;
	const float ANGLE_OFFSET = 90.f;
	const float ROTATION_SPEED = 50.f;
	const float THRUST = 3.0f;

	Player::Player(int width, int height)
		: m_gasOn(false)
		, m_moving(false)
		, m_angle(0.0f)
		, Entity(width, height)
	{
		m_position =
			Engine::Math::Vector2(Engine::Math::Vector2::Origin);

		ChangeShip();
	}

	void Player::ChangeShip()
	{
		m_points.push_back(Engine::Math::Vector2(0.0f, 20.0f));
		m_points.push_back(Engine::Math::Vector2(12.0f, -10.0f));
		m_points.push_back(Engine::Math::Vector2(6.0f, -4.0f));
		m_points.push_back(Engine::Math::Vector2(-6.0f, -4.0f));
		m_points.push_back(Engine::Math::Vector2(-12.0f, -10.0f));
	}

	void Player::Update(float deltaTime)
	{
		if(!m_moving) m_gasOn = false;
		// Velocity is a vector but we want to clamp speed as a scalar
		float speed =
			std::fabs(std::sqrtf(
					   m_velocity.x * m_velocity.x + 
					   m_velocity.y * m_velocity.y)
					  );

		if (speed > MAX_SPEED)
		{
			// TODO: RR: Change this for clamp
			m_velocity.x = (m_velocity.x / speed) * MAX_SPEED;
			m_velocity.y = (m_velocity.y / speed) * MAX_SPEED;
		}

		m_currentSpeed = speed;

		Entity::Update(deltaTime);
	}

	void Player::Render()
	{
		glLoadIdentity();

		// Translates a vector
		glTranslatef(m_position.x, m_position.y, 0.0f);
		
		// Change the orientation
		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
			std::vector<Engine::Math::Vector2>::iterator it = 
				m_points.begin();
			for (; it != m_points.end(); ++it)
			{
				glVertex2f((*it).x, (*it).y);
			}
		glEnd();

		if (m_gasOn)
		{
			// TODO: RR: Move this out
			glBegin(GL_LINE_LOOP);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(0.0f, -16.0f);
			glVertex2f(-6.0f, -4.0f);
			glEnd();
		}
	}

	void Player::ApplyImpulse(Engine::Math::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			/* 
			 * Apply angle OFFSET upon creation of object rather than 
			 * every time impulse is applied 
			 */
			m_velocity.x += 
				(impulse.x / m_mass) * cosf((m_angle + ANGLE_OFFSET) * (PI / 180));
			m_velocity.y += 
				(impulse.y / m_mass) * sinf((m_angle + ANGLE_OFFSET) * (PI / 180));
		}
	}

	void Player::MoveForward()
	{
		m_gasOn = true;
		m_moving = true;
		ApplyImpulse(Engine::Math::Vector2(THRUST, THRUST));
	}

	void Player::Rotateleft()
	{
		m_angle += ROTATION_SPEED;
	}

	void Player::RotateRight()
	{
		m_angle -= ROTATION_SPEED;
	}
}