#include "Sprite.h"

Sprite::~Sprite()
{}
Sprite::Sprite(const sf::Vector2f & size) : RectangleShape(size)
{}
//set velocity
void Sprite::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}
void Sprite::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}
//get velocity
sf::Vector2f Sprite::getVelocity()
{
	return velocity;
}