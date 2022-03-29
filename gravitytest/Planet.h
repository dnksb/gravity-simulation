#pragma once
#include<SFML/Graphics.hpp>
class Planet {
private:
	float weight;
	sf::Vector2f position;
	sf::Vector2f accel;
	sf::Vector2f speed;
	sf::Image image;
	sf::Texture texture_1, texture_2, texture_3;
public:
	int planet_num = 0;
	sf::Sprite sprite;
	float sun_distance = 5;
	Planet(float w, sf::Vector2f pos, std::string img, sf::Vector2f acc = {0, 0}, sf::Vector2f sp = {0.1, 1.5});
	void update(float sun_weight, sf::Vector2f sun_pos, int frame);
	float GetWeight();
	sf::Vector2f GetPosition();
	sf::Sprite draw();
	void SetPosition(sf::Vector2f pos);
	void SetPosition(sf::Vector2i pos);
};

