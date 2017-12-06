#ifndef GAME
#define GAME

#include "Bolt.h"
#include "Paddle.h"
#include "KeyHandler.h"
#include "LevelLoader.h"
#include "Invader.h"

class Game
{
public:

	Paddle m_paddle;
	Bolt m_bolt;
	KeyHandler m_keyHandler;
	LevelData m_level;
	Invader m_invader;

	Game();
	void run();
	

private:
	void processEvents();
	void processGameEvents(sf::Event&);
	void update(double dt);
	void render();
	void setupFontAndText();
	void setupSprite();
	void generateEnemies();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_text;
	sf::Sprite m_paddleSprite;
	sf::Texture m_paddleTexture;
	sf::Sprite m_boltSprite;
	sf::Texture m_boltTexture;
	sf::Sprite m_bgSprite;
	sf::Texture m_bgTexture;
	std::vector<sf::Sprite> m_brickSprites;
	std::vector<sf::Sprite> m_invaderSprites;
	sf::Texture m_brickTexture1;
	sf::Texture m_brickTexture2;
	sf::Texture m_brickTexture3;
	sf::Texture m_brickTexture4;
	sf::Texture m_invaderTexture;
	bool m_exitGame; // control exiting game
};

#endif // !GAME

