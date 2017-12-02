#pragma once
#include "SFML\Graphics.hpp"

class Bolt
{
public:
	Bolt(sf::Texture const & texture, sf::Vector2f p);
	void update(double dt);
	void setPosition(sf::Vector2f const & pos);
	void render(sf::RenderWindow & window);

private:

	sf::Sprite m_body;
	sf::Texture const & m_texture;
	void initSprite(sf::Vector2f const & pos);
	sf::Vector2f m_position;
	float m_speed;
	float m_radius;
	bool m_alive = {true};
	
};