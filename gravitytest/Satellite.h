#pragma once
#include <SFML/Graphics.hpp>
class Satellite {
private:
	sf::Vector2f position;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f accel;
	sf::Vector2f speed;
	float planet_distance;
public:
	Satellite(sf::Vector2f pos, std::string img, sf::Vector2f acc = { 0, 0 }, sf::Vector2f sp = { 0.1, 1.5 });
	void update(float planet_weight, sf::Vector2f plsnet_pos);
	sf::Vector2f GetPosition();
	sf::Sprite draw();
};

