#include "Bolt.h"

Bolt::Bolt(sf::Texture const & texture, sf::Vector2f const & pos):
	m_texture(texture),
	m_position(pos)
{
	initSprite(pos);
}

void Bolt::update(double dt)
{
//	m_position += m_speed;
	deflect();
	setPosition(m_position);
}

void Bolt::setPosition(sf::Vector2f const & pos)
{
	initSprite(pos);
}

void Bolt::render(sf::RenderWindow & window)
{
	window.draw(m_body);
}

void Bolt::deflect()
{
	if (m_position.x <= 0 || m_position.x >= 790)
	{
		m_speed.x = (m_speed.x * -1.f);
	}
	if (m_position.y <= 0 || m_position.y >= 770)
	{
		m_speed.y = (m_speed.y * -1.f);
	}
}

void Bolt::initSprite(sf::Vector2f const & pos)
{
	m_body.setTexture(m_texture);
	sf::IntRect bodyRect(0, 0, 24, 24);
	m_body.setTextureRect(bodyRect);
	m_body.setPosition(pos);
}