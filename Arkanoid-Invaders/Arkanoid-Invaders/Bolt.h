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
	void deflect();

private:

	sf::Sprite m_body;
	sf::Texture const & m_texture;
	void initSprite(sf::Vector2f const & pos);
	sf::Vector2f m_position;
	sf::Vector2f m_speed = {sf::Vector2f(22.5f,22.5f)};//sf::Vector2f(.5f,.25f)
	float m_radius;
	bool m_alive = {true};
	
};