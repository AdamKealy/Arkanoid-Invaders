#include "Bolt.h"

Bolt::Bolt() :
	m_alive(true),
	m_position(0.0f, 0.0f),
	m_speed(0.0f, 0.0f),
	m_radius(50.0f)
{
	m_ball.setPosition(m_position);
	m_ball.setFillColor(sf::Color::Yellow);
	m_ball.setRadius(m_radius);
}

Bolt::Bolt(float r, sf::Vector2f p , sf::Vector2f s):
	m_alive(true),
	m_position(p),
	m_speed(s),
	m_radius(r)
{
	m_ball.setPosition(m_position);
	m_ball.setFillColor(sf::Color::Yellow);
	m_ball.setRadius(m_radius);
}

sf::Vector2f Bolt::getSpeed() const
{
	return m_speed;
}

sf::Vector2f Bolt::getPosition() const
{
	return m_position;
}
