#pragma once
#include "GameState.h"
#include "custCircle.h"
#include "Wave.h"
#include <vector>
#include <string>
//Main menu state
class MenuState :
	public GameState
{
public:
	MenuState(sf::RenderWindow* hwnd, Input* in);
	~MenuState();

	//initialise
	void init();

	void handleInput(float deltaTime);
	GameState* update(float deltaTime);
	void render();
	//set pointers to other states
	void setClientState(GameState* state) { clientGame = state; };
	void setHostState(GameState* state) { hostGame = state; };
	
private:
	void updateMenuText();
	float roundF(float num, int decimalPlaces);
private:
	GameState* clientGame;
	GameState* hostGame;

	custCircle* circle;
	custCircle* curChannelCircle;
	float time;
	int menuSelect;
	int numChannels;
	int curChannelNum;
	//text
	sf::Text menuText;
	sf::Text menuAmplitude;
	sf::Text menuFrequency;
	sf::Text menuSpeed;
	sf::Text menuChannel;
	sf::Text menuAddChannel;
	sf::Text menuQuit;
	sf::Text menuSelectSymbol;

	std::vector<Wave*> channels;

	float amplitude;
	float freq;

	Wave* curChannel;

	Wave* waveA;
	Wave* waveB;
	Wave* waveC;
	Wave* waveD;

	sf::Font font;
};

