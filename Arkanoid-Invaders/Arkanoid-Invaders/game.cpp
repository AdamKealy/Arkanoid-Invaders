#include "Game.h"
#include <iostream>

static double const MS_PER_UPDATE = 10.0;

Game::Game() :
	m_window{ sf::VideoMode{ 800, 800, 32 }, "Spoder Game" },
	m_exitGame{ false }, //when true game will exit
	m_bolt(m_boltTexture,sf::Vector2f(150.f, 600.f)),
	m_paddle(m_paddleTexture,sf::Vector2f(360.f, 750.f),m_keyHandler)
//	m_invader(m_invader,)
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	//m_window.setVerticalSyncEnabled(true);

	int currentLevel = 1;

	if (!LevelLoader::load(currentLevel, m_level))
	{
		return;
	}

	generateBricks();
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
	for (const sf::Sprite & s : m_brickSprites)
	{
		m_window.draw(s);
	}
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

	if(!m_brickTexture1.loadFromFile("ASSETS\\IMAGES\\brick1.png"))
	{
		std::cout << "Problem loading brick1.png" << std::endl;
	}
	if (!m_brickTexture2.loadFromFile("ASSETS\\IMAGES\\brick2.png"))
	{
		std::cout << "Problem loading brick2.png" << std::endl;
	}
	if (!m_brickTexture3.loadFromFile("ASSETS\\IMAGES\\brick3.png"))
	{
		std::cout << "Problem loading brick3.png" << std::endl;
	}
	if (!m_brickTexture4.loadFromFile("ASSETS\\IMAGES\\brick4.png"))
	{
		std::cout << "Problem loading brick4.png" << std::endl;
	}
	if (!m_invaderTexture.loadFromFile("ASSETS\\IMAGES\\invader.png"))
	{
		std::cout << "Problem loading invader" << std::endl;
	}

}

void Game::generateBricks()
{
	sf::IntRect brickRect(0, 0, 42, 20);
	for (BrickData const & bricks : m_level.m_bricks)
	{
		sf::Sprite sprite;
		if (bricks.m_type == 0)
		{
			sprite.setTexture(m_brickTexture1);
		}
		if (bricks.m_type == 1)
		{
			sprite.setTexture(m_brickTexture2);
		}
		if (bricks.m_type == 2)
		{
			sprite.setTexture(m_brickTexture3);
		}
		if (bricks.m_type == 3)
		{
			sprite.setTexture(m_brickTexture4);
		}
		sprite.setTextureRect(brickRect);
		sprite.setOrigin(brickRect.width / 2.f, brickRect.height / 2.f);
		sprite.setPosition(bricks.m_position);
		m_brickSprites.push_back(sprite);
	}

	sf::IntRect invaderRect(0, 0, 59, 50);
	for (InvaderData const & invader : m_level.m_invaders)
	{
		sf::Sprite sprite;
		
		sprite.setTexture(m_invaderTexture);
		sprite.setTextureRect(invaderRect);
		sprite.setOrigin(invaderRect.width / 2.f, invaderRect.height / 2.f);
		sprite.setPosition(invader.m_position);
		m_brickSprites.push_back(sprite);
	}
}