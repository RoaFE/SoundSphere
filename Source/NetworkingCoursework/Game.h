#pragma once

//default game for testing

#include "Sprite.h"
#include "GameState.h"

class Game : public GameState {
public:
	Game(sf::RenderWindow* hwnd, Input* in);
	~Game();

	void init();
	void handleInput(float deltaTime);
	GameState* update(float deltaTime);
	void render();
private:

};
