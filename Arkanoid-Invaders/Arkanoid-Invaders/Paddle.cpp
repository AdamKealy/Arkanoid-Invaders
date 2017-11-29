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

sf::Vector2f Paddle::getSpeed()
{
	return m_speed;
}

sf::Vector2f Paddle::setPosition()
{
	return  m_position;
}

sf::Vector2f Paddle::getPosition() const
{
	return m_position;
}
