#include "GameState.h"



GameState::GameState(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
}

GameState::~GameState()
{
}

void GameState::beginDraw()
{
	window->clear(sf::Color::Black);
}

void GameState::endDraw()
{
	window->display();
}

//lerpp code should probably
sf::Vector2f GameState::lerp(sf::Vector2f start, sf::Vector2f end, float lerpVal)
{
	sf::Vector2f newPos = start + ((end - start) * lerpVal);
	return newPos;
}
