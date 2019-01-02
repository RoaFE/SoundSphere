#include "custCircle.h"


custCircle::custCircle(float radius, float time,float freq, float amplitude, int resolution)
{
	float angle = 360 / float(resolution);
	for (int i = 0; i < resolution; i++) {

		//first vertice
		vertices.push_back(sf::Vertex(sf::Vector2f(0, 0),sf::Color::White,sf::Vector2f(0, 0)));

		//calcuate x and y coord for second vertex
		float x = cos((i * angle) * 3.142 / 180) * radius;
		float y = sin((i * angle) * 3.142 / 180) * radius;

		//find the normalise componenet
		float normalise = 1 / sqrt((x*x) + (y*y));

		float x_displace;
		float y_displace;
		//calculate the displacement of the wave
		if (i * angle > 180)
		{
			float invAngle = float(180) - ((float(i) * angle) - 180);
			float amplitudeMod = (90 - abs(90 - invAngle))/90;
			x_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
			y_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
		}
		else
		{
			float amplitudeMod = (90 - abs(90 - (i * angle))) / 90;
			x_displace = sin(((i * angle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
			y_displace = sin(((i * angle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
		}

		//apply the displacement
		x = x + x_displace;
		y = y + y_displace;
		//push the second vertex
		vertices.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::White,sf::Vector2f(abs(x), y)));

		//repeat for the next vertex
		x = cos(((i + 1) * angle) * 3.142 / 180) * radius;
		y = sin(((i + 1) * angle) * 3.142 / 180) * radius;

		normalise = 1 / sqrt((x*x) + (y*y));

		if ((i + 1) * angle > 180)
		{
			float invAngle = float(180) - (float((i + 1)) * angle - 180);
			float amplitudeMod = (90 - abs(90 - invAngle)) / 90;
			x_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
			y_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
		}
		else
		{

			float amplitudeMod = (90 - abs(90 - ((i + 1) * angle))) / 90;
			x_displace = sin((((i + 1) * angle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
			y_displace = sin((((i + 1) * angle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
		}

		x = x + x_displace;
		y = y + y_displace;

		vertices.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::White , sf::Vector2f(abs(x), y)));
	}
}

custCircle::~custCircle()
{
}
