#include "Wave.h"

Wave::Wave(float amplitude, float speed, float frequency)
{
	ampl = amplitude;
	speedMultiplier = speed;
	freq = frequency;
	currentHeight = 0;
	isPressed = false;
}

Wave::~Wave()
{
}

void Wave::update()
{
	if (isPressed)
	{
		if (currentHeight != ampl)
		{
			currentHeight += ampl / 20;
		}
		if (currentHeight > ampl)
		{
			currentHeight = ampl;
		}
	}
	else
	{
		if (currentHeight != 0)
		{
			currentHeight -= ampl / 80;
		}
		if (currentHeight < 0)
		{
			currentHeight = 0;
		}
	}
}
