#include "Game.h"
Game::Game(sf::RenderWindow* hwnd,Input* in) : GameState(hwnd, in)
{

}
Game::~Game()
{
}
void Game::init()
{
}
void Game::handleInput(float dt)
{

}

GameState* Game::update(float dt)
{

	return this;
}

void Game::render()
{
	beginDraw();
	endDraw();
}
