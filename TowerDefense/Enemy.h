#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Inventory.h"
class Enemy : public sf::Drawable, public sf::Transformable
{
public:
	Enemy(int, int);
	~Enemy();
	int sequenceIndex;
	int state; //standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	int level;
	void update(sf::Time delta);
	void setTexCord();
	void move(int);
	void addFrame(sf::IntRect rect);
	bool isDead();
	void UpdatePos(int mapX, int mapY);
	void attacked(int, int);
	int checkPointUpdate(int);
	void setTextSheet(sf::Texture* enemyText);
	int  posX, posY;
	sf::Vector2f positionEnemy();
	Inventory inventory;
	int type;
	bool texSet();
private:
	float frameTime;
	float frameRate;
	int checkpoint, health, speed;
	std::vector<sf::IntRect> playerFrames;
	sf::Texture* texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};