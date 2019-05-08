#pragma once
class Wave
{
public:
	Wave(float amplitude, float speed, float frequency);
	~Wave();
	void update(float dt);
	
	float getAmplitude() { return currentHeight; };
	void setAmplitude(float amp) { ampl = amp; };
	void addAmplitude(float amp) { ampl += amp; };
	float getStep() { return step; };
	float getSpeed() { return speedMultiplier; };
	void setSpeed(float speed) { speedMultiplier = speed; };
	void addSpeed(float speed) { speedMultiplier += speed; };
	float getFrequency() { return freq; };
	void setFrequency(float frequency) { freq = frequency; };
	void addFrequency(float frequency) { freq += frequency; };
	void setPressed(bool pressed) { isPressed = pressed; };
private:
	float ampl;
	float speedMultiplier;
	float freq;
	float step;
	float currentHeight;
	bool isPressed;

};

