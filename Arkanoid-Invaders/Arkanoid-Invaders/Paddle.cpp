#include "Paddle.h"


Paddle::Paddle() :
	m_position(355.f,750.f),
	m_speed(0.0f,0.0f),
	m_width(100.f)
{
	m_body.setPosition(m_position);
	m_body.setFillColor(sf::Color::Red);
	m_body.setSize(sf::Vector2f(100,10));
}

float Paddle::getHeight() const
{
	return m_height;
}

float Paddle::getWidth() const
{
	return m_width;
}

void Paddle::moveL()
{
	if (m_position.x != 0)
	{
		m_position -= m_speed;
	}
}

void Paddle::moveR()
{
	if (m_position.x != 800 - getWidth())
	{
		m_position += m_speed;
	}
}

void Paddle::update(double dt)
{
	m_body.setPosition(m_position);
}
