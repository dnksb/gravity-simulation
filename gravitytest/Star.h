#pragma once
#include <SFML/Graphics.hpp>
class Star {
public:
	sf::Vector2f position;
	sf::Image image;
	sf::Texture texuture;
	sf::Sprite sprite;
	double weight;

	Star(double w, std::string img, sf::Vector2f pos);
	void update();
	sf::Sprite draw();
	float GetWeight();
	sf::Vector2f GetPosition();
};

