#pragma once
class Wave
{
public:
	Wave(float amplitude, float speed, float frequency);
	~Wave();
	void update();
	
	float getAmplitude() { return currentHeight; };
	float getSpeed() { return speedMultiplier; };
	float getFrequency() { return freq; };
	void setPressed(bool pressed) { isPressed = pressed; };
private:
	float ampl;
	float speedMultiplier;
	float freq;
	float currentHeight;
	bool isPressed;

};

