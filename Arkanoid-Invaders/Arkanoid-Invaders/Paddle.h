#pragma once
#include "SFML\Graphics.hpp"
#include "KeyHandler.h"

class Paddle
{
public:

	KeyHandler const * m_keys;
	Paddle(sf::Texture const & texture, sf::Vector2f const & pos, KeyHandler const & keyHandler);
	void update(double dt);
	void setPosition(sf::Vector2f const & pos);
	void render(sf::RenderWindow & window);
	void handleKeyInput();
	
private:

	sf::Sprite m_body;
	sf::Texture const & m_texture;
	void initSprite(sf::Vector2f const & pos);
	sf::Vector2f m_position;
	float m_speed = 5.f;
	float m_width = { 150.f };
	float const m_height = {10.0f};
};