#include "Planet.h"
#include <iostream>
#include <math.h>

Planet::Planet(float w, sf::Vector2f pos, std::string img, sf::Vector2f acc, sf::Vector2f sp) {
	weight = w;
	position = pos;
	accel = acc;
	speed = sp;
	image.loadFromFile(img);
	texuture.loadFromImage(image);
	sprite.setTexture(texuture);
	sprite.setPosition(pos);
}

void Planet::update(float sun_weight, sf::Vector2f sun_pos) {
	sun_distance = sqrt(pow(position.x - sun_pos.x, 2.0) + pow(position.y - sun_pos.y, 2.0));
	accel.x = sun_weight * ((sun_pos - position).x / pow(sun_distance, 3.0));
	accel.y = sun_weight * ((sun_pos - position).y / pow(sun_distance, 3.0));
	speed.x += accel.x;
	speed.y += accel.y;
	position.x += speed.x;
	position.y += speed.y;
	sprite.setPosition(position);
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
