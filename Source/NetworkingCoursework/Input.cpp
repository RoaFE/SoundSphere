#include "Input.h"



Input::Input()
{
}


Input::~Input()
{
}

void Input::setKeyDown(int key)
{
	keys[key] = true;
}

void Input::setKeyUp(int key)
{
	keys[key] = false;

}

bool Input::isKeyDown(int key)
{
	return keys[key];
}

void Input::setMouseX(int lx)
{
	mouse.x = lx;
}

void Input::setMouseY(int ly)
{
	mouse.y = ly;

}

void Input::setMousePosition(int lx, int ly)
{
	mouse.x = lx;
	mouse.y = ly;

}

void Input::setMouseLeft(bool left)
{
	mouse.left = left;
}

void Input::setMouseRight(bool right)
{
	mouse.right = right;
}

int Input::getMouseX()
{
	return mouse.x;
}

int Input::getMouseY()
{
	return mouse.y;
}
