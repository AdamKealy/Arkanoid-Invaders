#ifndef GAME
#define GAME

#include "Bolt.h"
#include "Paddle.h"
#include "KeyHandler.h"
#include "LevelLoader.h"

class Game
{
public:

	Paddle m_paddle;
	Bolt m_bolt;
	KeyHandler m_keyHandler;
	LevelData m_level;



	Game();
	void run();
	

private:
	void processEvents();
	void processGameEvents(sf::Event&);
	void update(double dt);
	void render();
	void setupFontAndText();
	void setupSprite();
	void generateBricks();

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
	sf::Texture m_brickTexture;
	bool m_exitGame; // control exiting game
};

#endif // !GAME

