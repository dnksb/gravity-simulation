#include "Satellite.h"


Satellite::Satellite(sf::Vector2f pos, std::string img, sf::Vector2f acc, sf::Vector2f sp) {
	position = pos;
	accel = acc;
	speed = sp;
	image.loadFromFile(img);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(pos);
}

void Satellite::update(float planet_weight, sf::Vector2f planet_pos) {
	planet_distance = sqrt(pow(position.x - planet_pos.x, 2.0) + pow(position.y - planet_pos.y, 2.0));
	accel.x = planet_weight * ((planet_pos - position).x / pow(planet_distance, 3.0));
	accel.y = planet_weight * ((planet_pos - position).y / pow(planet_distance, 3.0));
	speed.x += accel.x;
	speed.y += accel.y;
	position.x += speed.x;
	position.y += speed.y;
	sprite.setPosition(position);
}

sf::Vector2f Satellite::GetPosition() {
    return position;
}


sf::Sprite Satellite::draw() {
    return sprite;
}
