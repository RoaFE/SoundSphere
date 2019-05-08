#include "MenuState.h"



MenuState::MenuState(sf::RenderWindow* hwnd, Input* in) : GameState(hwnd, in)
{
	amplitude = 10;
	freq = 13;
	numChannels = 1;
	time = 0;
	curChannelNum = 0;
	menuSelect = 0;
	if (!font.loadFromFile("font/VCR_OSD_MONO.ttf"))
	{
		printf("where is it?");
	}
	//initialise text
	menuText.setString("Menu");
	menuText.setPosition(sf::Vector2f(30, 50));
	menuText.setFont(font);
	menuText.setFillColor(sf::Color::White);
	menuText.setOutlineColor(sf::Color::White);
	menuText.setCharacterSize(50);

	menuChannel.setString("Channel: 0");
	menuChannel.setPosition(sf::Vector2f(30, 200));
	menuChannel.setFont(font);
	menuChannel.setFillColor(sf::Color::White);
	menuChannel.setOutlineColor(sf::Color::White);
	menuChannel.setCharacterSize(25);

	menuAmplitude.setString("Amplitude");
	menuAmplitude.setPosition(sf::Vector2f(30, 240));
	menuAmplitude.setFont(font);
	menuAmplitude.setFillColor(sf::Color::White);
	menuAmplitude.setOutlineColor(sf::Color::White);
	menuAmplitude.setCharacterSize(25);

	menuFrequency.setString("Frequency");
	menuFrequency.setPosition(sf::Vector2f(30, 280));
	menuFrequency.setFont(font);
	menuFrequency.setFillColor(sf::Color::White);
	menuFrequency.setOutlineColor(sf::Color::White);
	menuFrequency.setCharacterSize(25);

	menuSpeed.setString("Speed");
	menuSpeed.setPosition(sf::Vector2f(30, 320));
	menuSpeed.setFont(font);
	menuSpeed.setFillColor(sf::Color::White);
	menuSpeed.setOutlineColor(sf::Color::White);
	menuSpeed.setCharacterSize(25);

	menuAddChannel.setString("AddChannel");
	menuAddChannel.setPosition(sf::Vector2f(30, 360));
	menuAddChannel.setFont(font);
	menuAddChannel.setFillColor(sf::Color::White);
	menuAddChannel.setOutlineColor(sf::Color::White);
	menuAddChannel.setCharacterSize(25);

	menuQuit.setString("Quit");
	menuQuit.setPosition(sf::Vector2f(30, 400));
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

	curChannelCircle = new custCircle(50, time * 7, freq, amplitude, 350);
	curChannelCircle->setPosition(sf::Vector2f(570, 300));

	waveA = new Wave(10, 3, 4);
	waveB = new Wave(8, 6, 8);
	waveC = new Wave(6, 9, 12);
	waveD = new Wave(4, 12, 16);

	Wave* newWave; 
	for (int i = 0; i < numChannels; i++)
	{
		newWave = new Wave(0, 6, 0);
		newWave->setPressed(true);
		channels.push_back(newWave);
	}
	

	curChannel = channels[curChannelNum];
}


MenuState::~MenuState()
{
	delete circle;
	delete curChannelCircle;
	for (int i = 0; i < channels.size(); i++)
	{
		delete channels[i];
	}
	channels.clear();

	delete waveA;
	delete waveB;
	delete waveC;
	delete waveD;

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
			menuSelect = 5;
		}
		input->setKeyUp(sf::Keyboard::W);

	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		menuSelect++;
		if (menuSelect > 5)
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
		if (input->isKeyDown(sf::Keyboard::D))
		{
			input->setKeyUp(sf::Keyboard::D);
			curChannelNum += 1;
			if (curChannelNum > numChannels - 1)
			{
				curChannelNum = 0;
			}
			menuChannel.setString("Channel: " + std::to_string(curChannelNum));
			curChannel = channels[curChannelNum];
		}
		if (input->isKeyDown(sf::Keyboard::A))
		{
			input->setKeyUp(sf::Keyboard::A);
			curChannelNum -= 1;
			if (curChannelNum < 0)
			{
				curChannelNum = numChannels - 1;
			}
			menuChannel.setString("Channel: " + std::to_string(curChannelNum));
			curChannel = channels[curChannelNum];
		}
	}

	if (menuSelect == 1)
	{
		if (input->isKeyDown(sf::Keyboard::A))
		{
			input->setKeyUp(sf::Keyboard::A);
			curChannel->addAmplitude(-0.1f);
		}
		if (input->isKeyDown(sf::Keyboard::D))
		{
			input->setKeyUp(sf::Keyboard::D);
			curChannel->addAmplitude(0.1f);
		}
	}
	else if (menuSelect == 2)
	{
		if (input->isKeyDown(sf::Keyboard::A))
		{
			input->setKeyUp(sf::Keyboard::A);
			curChannel->addFrequency(-0.1f);

		}
		if (input->isKeyDown(sf::Keyboard::D))
		{
			input->setKeyUp(sf::Keyboard::D);
			curChannel->addFrequency(0.1f);

		}
	}
	else if (menuSelect == 3)
	{
		if (input->isKeyDown(sf::Keyboard::A))
		{
			input->setKeyUp(sf::Keyboard::A);
			curChannel->addSpeed(-0.1f);
		}
		if (input->isKeyDown(sf::Keyboard::D))
		{
			input->setKeyUp(sf::Keyboard::D);
			curChannel->addSpeed(0.1f);

		}
	}
	else if (menuSelect == 4)
	{
		if (input->isKeyDown(sf::Keyboard::Enter))
		{
			input->setKeyUp(sf::Keyboard::Enter);
			numChannels++;
			Wave* newWave = new Wave(0, 6, 0);
			newWave->setPressed(true);
			channels.push_back(newWave);
		}
	}
	else if (menuSelect == 5)
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
	waveA->update(dt);
	waveB->update(dt);
	waveC->update(dt);
	waveD->update(dt);
	//circle->applyContinousWave(time * waveA->getSpeed(), waveA->getFrequency(), waveA->getAmplitude());
	circle->applyWave(30, waveA->getFrequency(), waveA->getAmplitude(), waveA->getSpeed());
	circle->applyContinousWave(waveB->getStep(), waveB->getFrequency(), waveB->getAmplitude());
	circle->applyContinousWave(waveC->getStep(), waveC->getFrequency(), waveC->getAmplitude());
	circle->applyContinousWave(waveD->getStep(), waveD->getFrequency(), waveD->getAmplitude());
	for (int i = 0; i < numChannels; i++)
	{
		Wave* wavePointer = channels[i];
		wavePointer->update(dt);
		circle->applyContinousWave(wavePointer->getStep(), wavePointer->getFrequency(), wavePointer->getAmplitude());
	}
	//curChannelCircle->applyContinousWave(time * waveD->getSpeed(), waveD->getFrequency(), waveD->getAmplitude());
	curChannelCircle->applyContinousWave(curChannel->getStep(), curChannel->getFrequency(), curChannel->getAmplitude());

	menuSelectSymbol.setPosition(sf::Vector2f(10, 200 + (menuSelect * 40)));

	updateMenuText();

	return this;
}

void MenuState::render()
{
	beginDraw();
	window->draw(menuText);
	window->draw(menuAmplitude);
	window->draw(menuFrequency);
	window->draw(menuChannel);
	window->draw(menuSpeed);
	window->draw(menuAddChannel);
	window->draw(menuQuit);
	window->draw(menuSelectSymbol);

	window->draw(*circle);
	window->draw(*curChannelCircle);

	endDraw();

	circle->reset(100);
	curChannelCircle->reset(50);
}

void MenuState::updateMenuText()
{
	menuChannel.setString("Channel: " + std::to_string(curChannelNum));
	menuAmplitude.setString("Amplitude:" + std::to_string(roundF(curChannel->getAmplitude(),2)));
	menuFrequency.setString("Frequency:" + std::to_string(roundF(curChannel->getFrequency(),2)));
	menuSpeed.setString("Speed:" + std::to_string(roundF(curChannel->getSpeed(),2)));
}

float MenuState::roundF(float num, int decimalPlaces)
{
	for (int i = 0; i < decimalPlaces; i++)
	{
		num *= 10;
	}
	int numi = (int)round(num);
	num = numi;
	for (int i = 0; i < decimalPlaces; i++)
	{
		num /= 10;
	}
	return num;
}
