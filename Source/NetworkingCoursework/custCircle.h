#pragma once

#include <SFML/Graphics.hpp>
class custCircle : public sf::Drawable , public sf::Transformable
{
public:
	custCircle(float radius, float time, float freq, float amplitude, int resolution = 20);
	void applyContinousWave(float time, float freq, float amplitude);
	void applyWave(float angle, float freq, float amplitude, float speed);
	void reset(float radius);
	~custCircle();


private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the entity's transform -- combine it with the one that was passed by the caller
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

		// apply the texture
		states.texture = &m_texture;

		// you may also override states.shader or states.blendMode if you want

		// draw the vertex array
		target.draw(&vertices[0], vertices.size(), sf::Triangles, states);
	}

	std::vector<sf::Vertex> vertices;
	sf::Texture m_texture;
	float radi;

};

