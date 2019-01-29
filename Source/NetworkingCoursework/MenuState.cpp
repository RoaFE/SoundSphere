#include "MenuState.h"



MenuState::MenuState(sf::RenderWindow* hwnd, Input* in) : GameState(hwnd, in)
{
	amplitude = 10;
	freq = 13;

	time = 0;
	menuSelect = 0;
	if (!font.loadFromFile("font/VCR_OSD_MONO.ttf"))
	{
		printf("where is it?");
	}
	//initialise text
	menuText.setString("Menu");
	menuText.setPosition(sf::Vector2f(100, 50));
	menuText.setFont(font);
	menuText.setFillColor(sf::Color::White);
	menuText.setOutlineColor(sf::Color::White);
	menuText.setCharacterSize(50);

	menuHost.setString("Amplitude");
	menuHost.setPosition(sf::Vector2f(100, 200));
	menuHost.setFont(font);
	menuHost.setFillColor(sf::Color::White);
	menuHost.setOutlineColor(sf::Color::White);
	menuHost.setCharacterSize(25);

	menuConnect.setString("Frequency");
	menuConnect.setPosition(sf::Vector2f(100, 240));
	menuConnect.setFont(font);
	menuConnect.setFillColor(sf::Color::White);
	menuConnect.setOutlineColor(sf::Color::White);
	menuConnect.setCharacterSize(25);

	menuQuit.setString("Quit");
	menuQuit.setPosition(sf::Vector2f(100, 280));
	menuQuit.setFont(font);
	menuQuit.setFillColor(sf::Color::White);
	menuQuit.setOutlineColor(sf::Color::White);
	menuQuit.setCharacterSize(25);

	menuSelectSymbol.setString(">");
	menuSelectSymbol.setFont(font);
	menuSelectSymbol.setFillColor(sf::Color::White);
	menuSelectSymbol.setOutlineColor(sf::Color::White);
	menuSelectSymbol.setCharacterSize(25);

	circle = new custCircle(100, time * 7, freq, amplitude, 350);
	circle->setPosition(sf::Vector2f(400, 300));

	waveA = new Wave(10, 3, 4);
	waveB = new Wave(8, 6, 8);
	waveC = new Wave(6, 9, 12);
	waveD = new Wave(4, 12, 16);
}


MenuState::~MenuState()
{
	delete circle;
}

void MenuState::init()
{

}

void MenuState::handleInput(float deltaTime)
{
	//handle menu options should put this in handle input
	if (input->isKeyDown(sf::Keyboard::W))
	{
		menuSelect--;
		if (menuSelect < 0)
		{
			menuSelect = 2;
		}
		input->setKeyUp(sf::Keyboard::W);

	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		menuSelect++;
		if (menuSelect > 2)
		{
			menuSelect = 0;
		}
		input->setKeyUp(sf::Keyboard::S);
	}


	if (input->isKeyDown(sf::Keyboard::Z))
	{
		waveA->setPressed(true);
	}
	else
	{
		waveA->setPressed(false);
	}
	if (input->isKeyDown(sf::Keyboard::X))
	{
		waveB->setPressed(true);
	}
	else
	{
		waveB->setPressed(false);
	}

	if (input->isKeyDown(sf::Keyboard::C))
	{
		waveC->setPressed(true);
	}
	else
	{
		waveC->setPressed(false);
	}

	if (input->isKeyDown(sf::Keyboard::V))
	{
		waveD->setPressed(true);
	}
	else
	{
		waveD->setPressed(false);
	}

	if (menuSelect == 0)
	{
		if (input->isKeyDown(sf::Keyboard::A))
		{
			input->setKeyUp(sf::Keyboard::A);
			amplitude -= 0.2;
		}
		if (input->isKeyDown(sf::Keyboard::D))
		{
			input->setKeyUp(sf::Keyboard::D);
			amplitude += 0.2;
		}
	}
	else if (menuSelect == 1)
	{
		if (input->isKeyDown(sf::Keyboard::A))
		{
			input->setKeyUp(sf::Keyboard::A);
			freq -= 0.2;
		}
		if (input->isKeyDown(sf::Keyboard::D))
		{
			input->setKeyUp(sf::Keyboard::D);
			freq += 0.2;
		}
	}
	else if (menuSelect == 2)
	{
		if (input->isKeyDown(sf::Keyboard::Enter))
		{
			window->close();
		}
	}


	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
}

GameState* MenuState::update(float dt)
{ 
	time += dt;
	waveA->update();
	waveB->update();
	waveC->update();
	waveD->update();
	circle->applyWave(100, time * waveA->getSpeed(), waveA->getFrequency(), waveA->getAmplitude());
	circle->applyWave(100, time * waveB->getSpeed(), waveB->getFrequency(), waveB->getAmplitude());
	circle->applyWave(100, time * waveC->getSpeed(), waveC->getFrequency(), waveC->getAmplitude());
	circle->applyWave(100, time * waveD->getSpeed(), waveD->getFrequency(), waveD->getAmplitude());



	menuSelectSymbol.setPosition(sf::Vector2f(80, 200 + (menuSelect * 40)));


	return this;
}

void MenuState::render()
{
	beginDraw();
	window->draw(menuText);
	window->draw(menuHost);
	window->draw(menuConnect);
	window->draw(menuQuit);
	window->draw(menuSelectSymbol);

	window->draw(*circle);

	endDraw();

	circle->reset(100);
}
