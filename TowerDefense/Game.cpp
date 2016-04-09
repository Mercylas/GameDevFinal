#include "Game.hpp"

Game::Game(){
	this->m = new Model();
	this->v = new View(m);
	this->c = new Controller(m, v);
}

Game::~Game(){
}

void Game::loop(){
	sf::Time target = sf::milliseconds(20);
	sf::Time passed;
	int framesSkiped = 0;
	while (this->v->window.isOpen()) {
		this->deltaTime = this->clock.restart();
		this->timePassed.restart();

		this->c->inputs();
		this->m->update(this->deltaTime);
		passed = this->timePassed.restart();
		if (passed < target && framesSkiped < 10) {
			this->v->render();
			framesSkiped = 0;
			passed += this->timePassed.restart();
			if (passed < target) {
				//int i;
				//for (i = 0; i < 60; i++) { //this is to figure out how many frames per second
					sf::sleep(target - passed);
				//}
			}
		}
		else {
			framesSkiped++;
		}
	}
}
