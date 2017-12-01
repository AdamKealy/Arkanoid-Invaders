#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 800, 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_bolt(5.0f, sf::Vector2f(500.f, 500.0f), sf::Vector2f(0.0f, 0.0f))
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	
}


Game::~Game()
{
}


void Game::run()
{	
	sf::Event event;
	while (m_window.isOpen())
	{
		processEvents(event);
		render();
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		m_keyHandler.updateKey(event.key.code, true);
		break;
	case sf::Event::KeyReleased:
		m_keyHandler.updateKey(event.key.code, false);
		break;
	default:
		break;
	}

	switch (event.key.code)
	{
	case sf::Keyboard::Escape:
		m_window.close();
		break;
	default:
		break;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(double dt)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	m_paddle.update(dt);
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(m_bolt.m_ball);
	m_window.draw(m_paddle.m_body);
	//m_window.draw(m_logoSprite);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_text.setFont(m_ArialBlackfont);
	m_text.setString("SFML Game");
	m_text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_text.setPosition(40.0f, 40.0f);
	m_text.setCharacterSize(80);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setFillColor(sf::Color::Black);
	m_text.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	//if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	//{
	//	// simple error message if previous call fails
	//	std::cout << "problem loading logo" << std::endl;
	//}
	//m_logoSprite.setTexture(m_logoTexture);
	//m_logoSprite.setPosition(300.0f, 180.0f);
}
