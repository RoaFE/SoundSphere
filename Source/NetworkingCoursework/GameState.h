#pragma once
#include <SFML/Graphics.hpp>

#include "Input.h"
#include <windows.h>
#include <string.h>

//abstract game state class
class GameState
{
public:
	GameState(sf::RenderWindow* hwnd, Input* in);
	~GameState();
	virtual void init() = 0;
	virtual void handleInput(float deltaTime) = 0;
	virtual GameState* update(float deltaTime) = 0;
	virtual void render() = 0;
protected:
	sf::RenderWindow* window;
	void beginDraw();
	void endDraw();

	sf::Vector2f lerp(sf::Vector2f start, sf::Vector2f end, float lerpVal);

	Input* input;
};

