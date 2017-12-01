#pragma once
#include "SFML\Graphics.hpp"

class Paddle
{
public:

	Paddle();
	sf::RectangleShape m_body;
	float getHeight() const;
	float getWidth() const;
	void moveL();
	void moveR();
	//void setPosition(sf::Vector2f const & pos);
	void update(double dt);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_speed;
	float m_width;
	float const m_height = {10.0f};
};