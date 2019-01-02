#pragma once
#include "SFML\Graphics.hpp"


//Default sprite class for objects to inherit from
class Sprite : public sf::RectangleShape
{
public:
	Sprite(const sf::Vector2f & size = sf::Vector2f(0, 0));
	~Sprite();

	virtual void update(float dt) = 0;

	//set and get velocity
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity();

	void setAlive(bool aliveValue) { alive = aliveValue; };
	bool getAlive() { return alive; };
protected:
	sf::Vector2f velocity;
	int tag;
	bool alive;
};