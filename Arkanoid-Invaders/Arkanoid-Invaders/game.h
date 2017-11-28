// author Peter Lowe
#ifndef GAME
#define GAME
#include "Bolt.h"
#include "Paddle.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	Paddle m_paddle;
	Bolt m_bolt;
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	//sf::Texture m_logoTexture; // texture used for sfml logo
	//sf::Sprite m_logoSprite; // sprite used for sfml logo
	sf::Text m_text;
	bool m_exitGame; // control exiting game

};

#endif // !GAME

