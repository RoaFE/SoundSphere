#pragma once
#include "GameState.h"
#include "custCircle.h"
#include "Wave.h"
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
	GameState* clientGame;
	GameState* hostGame;

	custCircle* circle;
	float time;
	int menuSelect;
	//text
	sf::Text menuText;
	sf::Text menuHost;
	sf::Text menuConnect;
	sf::Text menuQuit;
	sf::Text menuSelectSymbol;

	float amplitude;
	float freq;

	Wave* waveA;
	Wave* waveB;
	Wave* waveC;
	Wave* waveD;

	sf::Font font;
};

