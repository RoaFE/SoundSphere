#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Input.h"
#include "MenuState.h"
#include <iostream>

sf::View calcView(const sf::Vector2u &windowsize, const sf::Vector2u &designedsize)
{
	sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);

	float screenwidth = windowsize.x / static_cast<float>(designedsize.x);
	float screenheight = windowsize.y / static_cast<float>(designedsize.y);

	if (screenwidth > screenheight)
	{
		viewport.width = screenheight / screenwidth;
		viewport.left = (1.f - viewport.width) / 2.f;
	}
	else if (screenwidth < screenheight)
	{
		viewport.height = screenwidth / screenheight;
		viewport.top = (1.f - viewport.height) / 2.f;
	}

	sf::View view(sf::FloatRect(0, 0, designedsize.x, designedsize.y));
	view.setViewport(viewport);

	return view;
}


void main(int argc, char** argv[])
{

	const sf::Vector2u designedsize(800, 600);

	Input input;
	sf::RenderWindow window(sf::VideoMode(800, 600), "CircoSound",sf::Style::Default);

	sf::View view;
	view = (calcView(window.getSize(), designedsize));
	window.setView(view);

	Game game(&window,&input);
	MenuState menu(&window, &input);

	GameState* curGameState;

	curGameState = &menu;
	//For DeltaTime
	sf::Clock clock;
	float deltaTime;

	while (window.isOpen())
	{
		//Handling window events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				//Window closes
			case sf::Event::Closed:
				window.close();
				break;
				//Window resized
			case sf::Event::Resized:
				window.setView(calcView(sf::Vector2u(event.size.width, event.size.height), designedsize));
				break;
				//Mouse movement
			case sf::Event::MouseMoved:
				input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
				break;
				//Mouse clicked
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					input.setMouseLeft(true);
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.setMouseRight(true);
				}
				break;
				//Mouse unclicked
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					input.setMouseLeft(false);
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.setMouseRight(false);
				}
				break;
				//key pressed
			case sf::Event::KeyPressed:
				input.setKeyDown(event.key.code);
				break;
				//key released
			case sf::Event::KeyReleased:
				input.setKeyUp(event.key.code);
				break;
			default:
				// don't handle other events
				break;
			}
		}
		deltaTime = clock.restart().asSeconds();
		//Game Loop
		curGameState->handleInput(deltaTime);
		curGameState = curGameState->update(deltaTime);
		curGameState->render();
	}
}