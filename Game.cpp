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

#include "Game.h"
#include <iostream>
#include "MyVector2.h"

void setUpSquares();

sf::RectangleShape redSquare;//This sets up the red Square
sf::RectangleShape greenSquare;//This setd up the ground
sf::RectangleShape yellowSquare;//this sets up the energy bar
sf::CircleShape explosion;//This sets up the circle for the explosion


Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "loading" },
	m_exitGame{false} 
{
	setupFontAndText(); // load font 
	setupSprite(); 
    setUpSquares();//Loads the squares
}

Game::~Game()
{
	
}


void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) 
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == newEvent.type) 
		{
			if (sf::Keyboard::Escape == newEvent.key.code)
			{
				m_exitGame = true;
			}
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)
		{
			satelliteLaser(newEvent); //When the mouse is clicked the laser from the sattelite appears		
		}
	}
}



void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	moveSatelliteLaser;
}

void Game::render()
{
	
	m_window.clear(sf::Color::Black);
	m_window.draw(redSquare);//draws the sattelite
	m_window.draw(greenSquare);//Draws the ground
	m_window.draw(yellowSquare);//Dras the energy bar
	m_window.draw(lasers);//Draws the laser
	m_window.draw(Altitude);//Draws the text 
	m_window.display();
	setupFontAndText();
	
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))//Loads font file
	{
		std::cout << "problem loading arial black font" << std::endl;//If statement for if the font cannot load
	}
	Altitude.setFont(m_ArialBlackfont);
	Altitude.setString("Altitude");//The word written by the font
	Altitude.setStyle(sf::Text::Italic | sf::Text::Bold);
	Altitude.setPosition(1.f, 530.f);
	Altitude.setCharacterSize(30U);
	Altitude.setOutlineColor(sf::Color::Red);
	Altitude.setFillColor(sf::Color::Black);
	Altitude.setOutlineThickness(1.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}

void Game::satelliteLaser(sf::Event t_mouseEvent)
{
	velocity = mouseClick - originPosition;
	velocity = vectorUnitVector(velocity);
	velocity = speed * velocity;
	missileLocation = originPosition;
	
	
	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button)//If a location is clicked the line is erased
	{
		lasers.clear(); //Clears the lasers
		mouseClick = sf::Vector2f{ static_cast<float>(t_mouseEvent.mouseButton.x),static_cast<float>(t_mouseEvent.mouseButton.y) };
		//Sets the location of mouseClick to the mouse click
		laserShot = sf::Vertex{ mouseClick , sf::Color::Red };//Sets LaserShot to the mouse Click
		lasers.append(laserShot);//Shows the laserShot
		origin = sf::Vertex{ originPosition , sf::Color::Yellow };//Sets origin to its position
		lasers.append(origin);//Shows origin
		//Sets the location of mouseClick to the mouse click
	}

}

void Game::moveSatelliteLaser(sf::Event t_mouseEvent)
{
		lasers.clear(); //Clears the lasers
		origin = sf::Vertex{ originPosition , sf::Color::Yellow };//Sets origin to its position
		lasers.append(origin);//Shows origin

		missileLocation = missileLocation + velocity;
		laserShot = sf::Vertex{ missileLocation , sf::Color::Red };//Sets LaserShot to the mouse Click
		lasers.append(laserShot);//Shows the laserShot

		if (missileLocation.y <= mouseClick.y)
		{
			lasers.clear();
		}
}

void Game::skyLaser(sf::Event t_mouseEvent)
{
	sf::Vertex origin{ sf::Vector2f{0.f, 0.f},sf::Color::White };
	sf::Vertex laserShot{ sf::Vector2f{200.f, 200.f},sf::Color::White };
}

void setUpSquares()
{
	redSquare.setFillColor(sf::Color::Red);
	redSquare.setSize(sf::Vector2f(100.f , 100.f));
	redSquare.setPosition(350.f, 400.f);
	//Set up the attributes of the sattelite
	greenSquare.setFillColor(sf::Color::Green);
	greenSquare.setSize(sf::Vector2f(800.f, 100.f)); 
	greenSquare.setPosition(0.f, 500.f);
	//Set up the attributes of the ground
	yellowSquare.setFillColor(sf::Color::Yellow);
	yellowSquare.setSize(sf::Vector2f(250.f, 30.f));
	yellowSquare.setPosition(160.f, 540.f);
	//Sets up the attributes of the power bar

}
