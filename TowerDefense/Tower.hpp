#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Enemy.h"
#include <cmath>

class Tower : public sf::Drawable, public sf::Transformable
{

public:
	Tower();
	Tower(int which, int xx, int yy);
	~Tower();
	void moveTower(int xx, int yy);
	sf::Vector2f positionTower();
	sf::Time lastShot;
	sf::Clock clock;
	int sequenceIndex;
	int state; //standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	bool moving;
	int type;
	void setTowerText(sf::Texture* towerTextSheet);
	void powerUpTower(int which);
	std::string getTowerStats();
	int attack, range, fireRate, addAttack, addRange, addFireRate, mapX, mapY;
	bool update(sf::Time delta, std::vector<Enemy>& bad);
private:
	sf::Texture* texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};