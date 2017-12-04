#include "Game.h"
#include <iostream>

static double const MS_PER_UPDATE = 10.0;

Game::Game() :
	m_window{ sf::VideoMode{ 800, 800, 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_bolt(m_boltTexture,sf::Vector2f(150.f, 600.f)),
	m_paddle(m_paddleTexture,sf::Vector2f(360.f, 750.f),m_keyHandler)
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	//m_window.setVerticalSyncEnabled(true);
	
}


void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::run()
{	
	sf::Clock clock;
	double lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processGameEvents(sf::Event& event)
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

void Game::update(double dt)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	m_paddle.update(dt);
	m_bolt.update(dt);
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_bgSprite);
	m_paddle.render(m_window);
	m_bolt.render(m_window);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message
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
/// load the texture and setup the sprite
/// </summary>
void Game::setupSprite()
{
	if (!m_paddleTexture.loadFromFile("ASSETS\\IMAGES\\paddle.png"))
	{
		std::cout << "problem loading paddle texture" << std::endl;
	}

	m_paddleSprite.setTexture(m_paddleTexture);

	if (!m_boltTexture.loadFromFile("ASSETS\\IMAGES\\bolt.png"))
	{
		std::cout << "Problem loading bolt texture" << std::endl;
	}

	m_boltSprite.setTexture(m_boltTexture);

	if (!m_bgTexture.loadFromFile("ASSETS\\IMAGES\\background.png"))
	{
		std::cout << "Problem loading background" << std::endl;
	}
	m_bgSprite.setTexture(m_bgTexture);
}
