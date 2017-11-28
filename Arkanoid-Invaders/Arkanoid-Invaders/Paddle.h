#pragma once
#include "SFML\Graphics.hpp"

class Paddle
{
public:

	Paddle();
	sf::RectangleShape m_body;
	float getHeight() const;
	float getWidth() const;
//	float setWidth(); //Power Ups later on
	sf::Vector2f getSpeed();
//	float setSpeed(); //Power Ups later on

private:
	sf::Vector2f m_position;
	sf::Vector2f m_speed;
	float m_width;
	float const m_height = {10.0f};
};