#include <SFML/Graphics.hpp>
#include "Planet.h"
#include "Star.h"
#include "Satellite.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Vector2f pos = { 100.0, 290.0 };
	Planet earht(3.0, pos, "earht.png");
	pos = { 400, 450 };
	Planet mars(400.0, pos, "mars.png", { 0, 0 }, { 6.0, 1.0 });
	pos = { 400, 300 };
	Star Sun(5000.0, "sun.png", pos);
	pos = { 400, 485 };
	Satellite moon(pos, "moon.png", { 0, 0 }, { 3.0, 0.5 });
	float want_fps = 50;
	sf::Clock loop_timer;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (earht.sun_distance < 1 || mars.sun_distance < 1) {
			return -1;
		}
		else if (earht.sun_distance > 500 || mars.sun_distance > 500) {
			return 1;
		}
		earht.update(Sun.GetWeight(), Sun.GetPosition());
		mars.update(Sun.GetWeight(), Sun.GetPosition());
		moon.update(Sun.GetWeight(), Sun.GetPosition());
		window.clear();
		window.draw(Sun.draw());
		window.draw(earht.draw());
		window.draw(mars.draw());
		window.draw(moon.draw());
		window.display();
		sf::Int32 frame_duration = loop_timer.getElapsedTime().asMilliseconds();
		sf::Int32 time_to_sleep = int(1000.f / want_fps) - frame_duration;
		if (time_to_sleep > 0) {
			sf::sleep(sf::milliseconds(time_to_sleep));
		}
		loop_timer.restart();
	}

	return 0;
}