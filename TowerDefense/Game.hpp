#pragma once
#include "View.hpp"
#include "Model.hpp"
#include "Controller.hpp"


class Game {
public:
	Game();
	~Game();
	void loop();
	sf::Time deltaTime;
	sf::Clock clock;
	sf::Clock timePassed;
private:
	Model* m;
	View* v;
	Controller* c;
};