#include "custCircle.h"


custCircle::custCircle(float radius, float time,float freq, float amplitude, int resolution)
{
	float angle = 360 / float(resolution);
	radi = radius;
	for (int i = 0; i < resolution; i++) {

		//first vertice
		vertices.push_back(sf::Vertex(sf::Vector2f(0, 0),sf::Color::White,sf::Vector2f(0, 0)));

		//calcuate x and y coord for second vertex
		float x = cos((i * angle) * 3.142 / 180) * radi;
		float y = sin((i * angle) * 3.142 / 180) * radi;

		//apply the displacement
		x = x;
		y = y;
		//push the second vertex
		vertices.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::White,sf::Vector2f(abs(x), y)));

		//repeat for the next vertex
		x = cos(((i + 1) * angle) * 3.142 / 180) * radi;
		y = sin(((i + 1) * angle) * 3.142 / 180) * radi;		

		x = x;
		y = y;

		vertices.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::White , sf::Vector2f(abs(x), y)));
	}
}

void custCircle::applyContinousWave(float time, float freq, float amplitude)
{
	float angle = 360 / float(vertices.size() / 3);

	for (int i = 0; i < (vertices.size() / 3); i++) {
		int pos = i * 3;
		//calcuate x and y coord for second vertex
		float x = cos((i * angle) * 3.142 / 180) * radi;
		float y = sin((i * angle) * 3.142 / 180) * radi;

		//find the normalise componenet
		float normalise = 1 / sqrt((x*x) + (y*y));

		float x_displace;
		float y_displace;
		//calculate the displacement of the wave
		if (i * angle > 180)
		{
			float invAngle = float(180) - ((float(i) * angle) - 180);
			float amplitudeMod = (90 - abs(90 - invAngle)) / 90;
			x_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
			y_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
		}
		else
		{
			float amplitudeMod = (90 - abs(90 - (i * angle))) / 90;
			x_displace = sin(((i * angle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
			y_displace = sin(((i * angle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
		}

		//push the second vertex
		vertices[pos + 1].position += sf::Vector2f(x_displace, y_displace);


		//repeat for the next vertex
		x = cos(((i + 1) * angle) * 3.142 / 180) * radi;
		y = sin(((i + 1) * angle) * 3.142 / 180) * radi;

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


		vertices[pos + 2].position += sf::Vector2f(x_displace, y_displace);
	}

}

void custCircle::applyWave(float angle, float freq, float amplitude, float time)
{
	angle = 360 / float(vertices.size() / 3);
	freq = 14;
	float length = time / freq;
	float ang = length /  radi;
	for (int i = 0; i < (vertices.size() / 3); i++) 
	{
		int pos = i * 3;
		if ((angle * i > (90 - ang/4)  && angle * (i + 1) < (90 + ang/4)) || (angle * i > (270 - ang / 4) && angle * (i + 1) < (270 + ang / 4)))
		{
			//calcuate x and y coord for second vertex
			float x = cos((i * angle) * 3.142 / 180) * radi;
			float y = sin((i * angle) * 3.142 / 180) * radi;

			//find the normalise componenet
			float normalise = 1 / sqrt((x*x) + (y*y));

			float x_displace;
			float y_displace;
			//calculate the displacement of the wave
			if (i * angle > 180)
			{
				float invAngle = float(180) - ((float(i) * angle) - 180);
				float amplitudeMod = (90 - abs(90 - invAngle)) / 90;
				x_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
				y_displace = sin(((invAngle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
			}
			else
			{
				float amplitudeMod = (90 - abs(90 - (i * angle))) / 90;
				x_displace = sin(((i * angle) * 3.142 / 180 * freq) + time) * x * normalise * amplitude * amplitudeMod;
				y_displace = sin(((i * angle) * 3.142 / 180 * freq) + time) * y * normalise * amplitude * amplitudeMod;
			}

			//push the second vertex
			vertices[pos + 1].position += sf::Vector2f(x_displace, y_displace);


			//repeat for the next vertex
			x = cos(((i + 1) * angle) * 3.142 / 180) * radi;
			y = sin(((i + 1) * angle) * 3.142 / 180) * radi;

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


			vertices[pos + 2].position += sf::Vector2f(x_displace, y_displace);
		}
	}

}

void custCircle::reset(float radius)
{
	float angle = 360 / float(vertices.size() / 3);

	for (int i = 0; i < (vertices.size() / 3); i++) {
		int pos = i * 3;
		//calcuate x and y coord for second vertex
		float x = cos((i * angle) * 3.142 / 180) * radius;
		float y = sin((i * angle) * 3.142 / 180) * radius;

		vertices[pos + 1].position = sf::Vector2f(x, y);

		//repeat for the next vertex
		x = cos(((i + 1) * angle) * 3.142 / 180) * radius;
		y = sin(((i + 1) * angle) * 3.142 / 180) * radius;

		vertices[pos + 2].position = sf::Vector2f(x, y);
	}

}

custCircle::~custCircle()
{
}
