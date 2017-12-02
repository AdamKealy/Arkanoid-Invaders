#include "Bolt.h"

Bolt::Bolt(sf::Texture const & texture, sf::Vector2f pos):
	m_texture(texture)
{
	initSprite(pos);
}

void Bolt::update(double dt)
{
}

void Bolt::setPosition(sf::Vector2f const & pos)
{
	initSprite(pos);
}

void Bolt::render(sf::RenderWindow & window)
{
	window.draw(m_body);
}

void Bolt::initSprite(sf::Vector2f const & pos)
{
	m_body.setTexture(m_texture);
	sf::IntRect bodyRect(0, 0, 110, 24);
	m_body.setTextureRect(bodyRect);
	m_body.setPosition(pos);
}