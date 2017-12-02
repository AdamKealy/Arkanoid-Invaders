#ifndef GAME
#define GAME
#include "Bolt.h"
#include "Paddle.h"
#include "KeyHandler.h"

class Game
{
public:

	Paddle m_paddle;
	Bolt m_bolt;
	KeyHandler m_keyHandler;

	Game();
	void run();
	

private:
	void processEvents();
	void processGameEvents(sf::Event&);
	void update(double dt);
	void render();
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_text;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_exitGame; // control exiting game
};

#endif // !GAME

