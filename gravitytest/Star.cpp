#include "Star.h"

Star::Star(double w, std::string img, sf::Vector2f pos) {
    position = pos;
    image.loadFromFile(img);
    texture_1.loadFromImage(image, sf::IntRect(0, 0, 40, 40));
    texture_2.loadFromImage(image, sf::IntRect(40, 0, 40, 40));
    texture_3.loadFromImage(image, sf::IntRect(80, 0, 40, 40));
    texture_4.loadFromImage(image, sf::IntRect(120, 0, 40, 40));
    texture_5.loadFromImage(image, sf::IntRect(160, 0, 40, 40));
    sprite.setTexture(texture_1);
    sprite.setPosition(position);
    weight = w;
}

void Star::update(int frame) {
    if (frame < 5) {
        sprite.setTexture(texture_1);
    }
    else if (frame < 10) {
        sprite.setTexture(texture_2);
    }
    else if (frame < 15) {
        sprite.setTexture(texture_3);
    }
    else if (frame < 20) {
        sprite.setTexture(texture_4);
    }
    else if (frame < 25) {
        sprite.setTexture(texture_5);
    }
    else if (frame < 30) {
        sprite.setTexture(texture_4);
    }
    else if (frame < 35) {
        sprite.setTexture(texture_3);
    }
    else {
        sprite.setTexture(texture_2);
    }
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
