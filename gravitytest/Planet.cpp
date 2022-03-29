#include "Planet.h"
#include <iostream>
#include <math.h>

Planet::Planet(float w, sf::Vector2f pos, std::string img, sf::Vector2f acc, sf::Vector2f sp) {
	weight = w;
	position = pos;
	accel = acc;
	speed = sp;
	image.loadFromFile(img);
	texture_1.loadFromImage(image, sf::IntRect(0, 0, 20, 20));
	texture_2.loadFromImage(image, sf::IntRect(20, 00, 20, 20));
	texture_3.loadFromImage(image, sf::IntRect(40, 00, 20, 20));
	sprite.setTexture(texture_1);
	sprite.setPosition(pos);
}

void Planet::update(float sun_weight, sf::Vector2f sun_pos, int frame) {
	sun_distance = sqrt(pow(position.x - sun_pos.x, 2.0) + pow(position.y - sun_pos.y, 2.0));
	accel.x = sun_weight * ((sun_pos - position).x / pow(sun_distance, 3.0));
	accel.y = sun_weight * ((sun_pos - position).y / pow(sun_distance, 3.0));
	speed.x += accel.x;
	speed.y += accel.y;
	position.x += speed.x;
	position.y += speed.y;
	sprite.setPosition(position);
	if (frame < 10) {
		sprite.setTexture(texture_1);
	}
	else if (frame < 20) {
		sprite.setTexture(texture_2);
	}
	else if (frame < 30) {
		sprite.setTexture(texture_3);
	}
	else {
		sprite.setTexture(texture_2);
	}
	return;
}

sf::Sprite Planet::draw() {
	return sprite;
}

float Planet::GetWeight() {
	return weight;
}

sf::Vector2f Planet::GetPosition() {
	return position;
}

void Planet::SetPosition(sf::Vector2f pos) {
	position = pos;
}
void Planet::SetPosition(sf::Vector2i pos) {
	position.x = pos.x;
	position.y = pos.y;
}
