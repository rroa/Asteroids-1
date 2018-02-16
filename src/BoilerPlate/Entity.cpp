#include "Entity.hpp"

namespace Game
{
	inline float wrap(float axis, float min, float max)
	{
		if (axis < min) return max - (min - axis);
		if (axis > max) return min + (axis - max);
		return axis;
	}

	Entity::Entity(int width, int height)
		: m_mass(1.0f)
	{
		CalcMinMax(width, height);
	}

	void Entity::CalcMinMax(int width, int height)
	{
		// TODO: RR: Ewww! Move this out!
		float halfWidth = width / 2.0f;
		float halfHeight = height / 2.0f;

		m_maxWidth = halfWidth;
		m_minWidth = -halfWidth;

		m_maxHeight = halfHeight;
		m_minHeight = -halfHeight;
	}

	void Entity::Update(float deltaTime)
	{
		m_position.x += m_velocity.x * static_cast<float>(deltaTime);
		m_position.y += m_velocity.y * static_cast<float>(deltaTime);

		m_position.x = wrap(m_position.x, m_minWidth, m_maxWidth);
		m_position.y = wrap(m_position.y, m_minHeight, m_maxHeight);
	}

	void Entity::Teleport(float newX, float newY)
	{
		m_position.x = newX;
		m_position.y = newY;
	}
}