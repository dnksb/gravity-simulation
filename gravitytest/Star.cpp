#include "Star.h"

Star::Star(double w, std::string img, sf::Vector2f pos) {
    position = pos;
    image.loadFromFile(img);
    texuture.loadFromImage(image);
    sprite.setTexture(texuture);
    sprite.setPosition(position);
    weight = w;
}

void Star::update() {
}

sf::Sprite Star::draw() {
    return sprite;
}

float Star::GetWeight() {
    return weight;
}

sf::Vector2f Star::GetPosition() {
    return position;
}
