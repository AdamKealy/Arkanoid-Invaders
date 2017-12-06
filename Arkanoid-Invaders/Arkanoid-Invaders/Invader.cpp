#include "Invader.h"

Invader::Invader(sf::Texture const & texture, LevelData const & levelLoader) :
	m_texture(texture),
	m_levels(&levelLoader)
{
}

void Invader::update(double dt)
{
	moveCheck();
	setPosition(m_position);
}

void Invader::setPosition(sf::Vector2f const & pos)
{
	initSprite(pos);
}

void Invader::render(sf::RenderWindow & window)
{
	for (const auto & m_ptrSprites : m_Sprites)
	{
		window.draw(m_ptrSprites);
	}
}

void Invader::moveCheck()
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

void Invader::initSprite(sf::Vector2f const & pos)
{
	for (InvaderData const & invader : m_levels->m_invaders)
	{
		sf::Sprite sprite;
		sprite.setPosition(pos);
	//	m_Sprites.push_back(sprite);
	}
}

void Invader::setUpsprites(LevelData const  &t_levels)
{
	sf::IntRect invaderRect(0, 0, 59, 50);
	for (InvaderData const & invader : t_levels.m_invaders)
	{
		sf::Sprite sprite;

		sprite.setTexture(m_texture);
		sprite.setTextureRect(invaderRect);
		sprite.setPosition(invader.m_position);
		m_Sprites.push_back(sprite);
	}
}
