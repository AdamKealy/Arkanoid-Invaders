#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Bolt
{
public:
	Bolt(sf::Texture const & texture, sf::Vector2f const & pos);
	void update(double dt);
	void setPosition(sf::Vector2f const & pos);
	void render(sf::RenderWindow & window);

private:

	sf::Sprite m_body;
	sf::Texture const & m_texture;
	void initSprite(sf::Vector2f const & pos);
	sf::Vector2f m_position;
	sf::Vector2f m_speed = {sf::Vector2f(4.f,2.f)};
	float m_radius;
	bool m_alive = {true};
	
};