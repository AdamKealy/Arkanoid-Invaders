#include "Invader.h"

Invader::Invader(sf::Texture const & texture, sf::Vector2f const & pos) :
	m_texture(texture),
	m_position(pos)
{
}

void Invader::update(double dt)
{
	m_position.x++;
	setPosition(m_position);
}

void Invader::setPosition(sf::Vector2f const & pos)
{
	initSprite(pos);
}

void Invader::render(sf::RenderWindow & window)
{
	window.draw(m_body);
}

void Invader::moveCheck()
{

}

void Invader::initSprite(sf::Vector2f const & pos)
{
	m_body.setTexture(m_texture);
	sf::IntRect bodyRect(0, 0, 24, 24);
	m_body.setTextureRect(bodyRect);
	m_body.setPosition(pos);
}