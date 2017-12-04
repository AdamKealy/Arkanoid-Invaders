#include "Paddle.h"


Paddle::Paddle(sf::Texture const & texture, sf::Vector2f const & pos, KeyHandler const & keyHandler) :
	m_texture(texture),
	m_keys(&keyHandler),
	m_position(pos)
{
	initSprite(pos);
}

void Paddle::setPosition(sf::Vector2f const & pos)
{
	initSprite(pos);
}

void Paddle::render(sf::RenderWindow & window)
{
	window.draw(m_body);
}

void Paddle::update(double dt)
{
	handleKeyInput();
	setPosition(sf::Vector2f(m_position.x, m_body.getPosition().y));
}

void Paddle::handleKeyInput()
{
	if (m_keys->isPressed(sf::Keyboard::Right))
	{
		if (m_position.x < 690.f)
		{
		m_position.x += m_speed;
		}
	}
	if (m_keys->isPressed(sf::Keyboard::Left))
	{
		if (m_position.x > 0.f)
		{
		m_position.x -= m_speed;
		}
	}
}

void Paddle::initSprite(sf::Vector2f const & pos)
{
	m_body.setTexture(m_texture);
	sf::IntRect bodyRect(0,0,110,24);
	m_body.setTextureRect(bodyRect);
	m_body.setPosition(pos);
}
