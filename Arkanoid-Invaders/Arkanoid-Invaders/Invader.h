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
	void setUpsprites(LevelData const  &levels);
private:
	std::vector<sf::Sprite> m_Sprites;
	std::vector<sf::Sprite*> m_ptrSprites;
	sf::Texture const & m_texture;
	void initSprite(sf::Vector2f const & pos);
	
	sf::Vector2f m_position;
	bool m_alive = { true };
	bool m_movingRight = { false };
};