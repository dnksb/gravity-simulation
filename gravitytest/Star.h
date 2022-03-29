#pragma once
#include <SFML/Graphics.hpp>
class Star {
public:
	sf::Vector2f position;
	sf::Image image;
	sf::Texture texture_1, texture_2, texture_3, texture_4, texture_5;
	sf::Sprite sprite;
	double weight;

	Star(double w, std::string img, sf::Vector2f pos);
	void update(int frame);
	sf::Sprite draw();
	float GetWeight();
	sf::Vector2f GetPosition();
};

