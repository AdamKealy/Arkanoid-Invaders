#pragma once
#include "SFML\Graphics.hpp"

class Bolt
{
public:
	Bolt();
	Bolt(float r, sf::Vector2f p, sf::Vector2f s);
	sf::CircleShape m_ball;
	sf::Vector2f getSpeed() const;
	sf::Vector2f getPosition() const;

private:
	sf::Vector2f m_position;
	sf::Vector2f m_speed;
	float m_radius;
	bool m_alive;
	
};