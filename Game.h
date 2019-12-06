/// Jay Simuzingili
/// C00252490
/// This Game is about a satelite shooting lasers at other lasers
/// 25/11/2019
/// approximate time: 10 hrs
/// real time: 13 hrs
/// session 1 : 3 hours
/// session 2 : 1 hour 30 minutes
/// session 3 : 45 minutes
/// session 4: 3 hours
/// session 5 : 45 minutes
/// session 6 : 2 hours
/// session 7 : 1 hour

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

const double PI{ 3.14159265359 };
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	sf::Vertex origin{ sf::Vector2f{0.f, 0.f},sf::Color::White };//Setting up the origin vertices
	sf::Vertex laserShot{ sf::Vector2f{0.f, 0.f},sf::Color::White };//Setting up the laser shot
	float speed{ 7.5f };//Determines the speed of the line movement
	sf::Vector2f originPosition{ 400.f, 500.f };//Determines the origin of the laser
	sf::Vector2f headingVector{ 0.f, 0.f };//Where the laser is travelling to
	sf::Vector2f velocity{ 0.f, 0.f };//The speed of the vector
	sf::Vector2f mouseClick{ 0.f, 0.f };//Location of the mouse
	sf::Vector2f missileLocation{ 0.f, 0.f };	//The location of the laser after 

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text Altitude; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	sf::VertexArray lasers{ sf::Lines };
	void Game::satelliteLaser(sf::Event t_mouseEvent);
	void Game::moveSatelliteLaser(sf::Event t_mouseEvent);
	void Game::skyLaser(sf::Event t_mouseEvent);
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

