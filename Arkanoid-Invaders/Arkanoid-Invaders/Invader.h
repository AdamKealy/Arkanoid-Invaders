#pragma once
#include "SFML\Graphics.hpp"
#include "LevelLoader.h"
#include <iostream>

class Invader
{
public:

	LevelData const * m_levels;

	Invader(sf::Texture const & texture,LevelData const & levelLoader);
	void update(double dt);
	void setPosition(sf::Vector2f const & pos);
	void render(sf::RenderWindow & window);
	void moveCheck();

private:
	sf::Sprite m_body;
	std::vector<sf::Sprite> m_Sprites;
	sf::Texture const & m_texture;
	void initSprite(sf::Vector2f const & pos);
	void setUpsprites();
	sf::Vector2f m_position;
	//sf::Vector2f m_speed = { sf::Vector2f(.5f,0.f) };//sf::Vector2f(.5f,.25f)

	float m_radius;
	bool m_alive = { true };
	bool m_movingRight = { false };
};