#include <SFML/Graphics.hpp>
#include "Planet.h"
#include "Star.h"
#include "Satellite.h"
#include <set>

int main() {
	//initilezate window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space");
	//make Earht
	sf::Vector2f pos = { 100.0, 290.0 };
	Planet earht(3.0, pos, "earht.png");
	//make Mars
	pos = { 400, 450 };
	Planet mars(400.0, pos, "mars.png", { 0, 0 }, { 6.0, 1.0 });
	//make Sun
	pos = { 400, 300 };
	Star Sun(5000.0, "sun.png", pos);
	//make Moon
	pos = { 400, 485 };
	Satellite moon(pos, "moon.png", { 0, 0 }, { 3.0, 0.5 });
	//max fps
	float want_fps = 50;
	sf::Clock loop_timer;
	//count frames
	int frame = 0;
	while (window.isOpen()) {
		frame++;
		if (frame > 40) {
			frame = 0;
		}
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// if planet in Sun
		if (earht.sun_distance < 1 || mars.sun_distance < 1) {
			return -1;
		}
		// if planet output sustem
		else if (earht.sun_distance > 500 || mars.sun_distance > 500) {
			return 1;
		}
		earht.update(Sun.GetWeight(), Sun.GetPosition(), frame);
		mars.update(Sun.GetWeight(), Sun.GetPosition(), frame);
		Sun.update(frame);
		moon.update(Sun.GetWeight(), Sun.GetPosition());
		window.clear();
		//draw all
		window.draw(Sun.draw());
		window.draw(earht.draw());
		window.draw(mars.draw());
		window.draw(moon.draw());
		window.display();
		//count fps
		sf::Int32 frame_duration = loop_timer.getElapsedTime().asMilliseconds();
		sf::Int32 time_to_sleep = int(1000.f / want_fps) - frame_duration;
		if (time_to_sleep > 0) {
			sf::sleep(sf::milliseconds(time_to_sleep));
		}
		loop_timer.restart();
	}
	return 0;
}