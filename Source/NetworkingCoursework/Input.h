#pragma once

class Input
{
private:
	struct Mouse
	{
		int x, y;
		bool left{ false };
		bool right{ false };
	};
public:
	Input();
	~Input();

	void setKeyDown(int key);
	void setKeyUp(int key);
	bool isKeyDown(int key);

	void setMouseX(int lx);
	void setMouseY(int ly);
	void setMousePosition(int lx, int ly);
	void setMouseLeft(bool left);
	void setMouseRight(bool right);
	int getMouseX();
	int getMouseY();
	bool getMouseLeft() { return mouse.left; };
	bool getMouseRight() { return mouse.right; };

private:
	bool keys[256]{ false };
	Mouse mouse;
};

