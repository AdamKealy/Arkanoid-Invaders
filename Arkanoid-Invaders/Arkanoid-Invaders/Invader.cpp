#include "Invader.h"

Invader::Invader(sf::Texture const & texture, LevelData const & levelLoader) :
	m_texture(texture),
	m_levels(&levelLoader)
{
	setUpsprites();
}

void Invader::update(double dt)
{
	moveCheck();

	if (!m_movingRight)
	{
		for (InvaderData const &invader : m_levels->m_invaders)
		{
			float pos = invader.m_position.x;
			pos++;
			m_position.x = pos;
		}
	
	}
	else
	{
		for (InvaderData const &invader : m_levels->m_invaders)
		{
			float pos = invader.m_position.x;
			pos--;
			m_position.x = pos;
		}

	}
	setPosition(m_position);
}

void Invader::setPosition(sf::Vector2f const & pos)
{
	initSprite(pos);
}

void Invader::render(sf::RenderWindow & window)
{
	for (const sf::Sprite & s : m_Sprites)
	{
	window.draw(s);
	}
}

void Invader::moveCheck()
{
	for (int i = 0; i < 24; i++)
	{
		if (m_position.x == 0.f)
		{
			m_movingRight = true;
		}
		if (m_position.x == 745.f)
		{
			m_movingRight = false;
		}
	}
}

void Invader::initSprite(sf::Vector2f const & pos)
{
	m_Sprites.setPosition(pos);
}

void Invader::setUpsprites()
{
	sf::IntRect invaderRect(0, 0, 59, 50);
	for (InvaderData const & invader : m_levels->m_invaders)
	{
		sf::Sprite sprite;

		sprite.setTexture(m_texture);
		sprite.setTextureRect(invaderRect);
		sprite.setPosition(invader.m_position);
		m_Sprites.push_back(sprite);
	}
}
