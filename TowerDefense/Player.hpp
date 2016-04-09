#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Inventory.h"
class Player : public sf::Drawable, public sf::Transformable
{

public:
	Player();
	~Player();
	void setTextSheet(sf::Texture *textSheet);
	int sequenceIndex;
	int state; //standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	bool driving;
	void update(sf::Time delta);
	void movePlayer(int xx, int yy);
	void setTexCord();
	void addFrame(sf::IntRect rect);
	Inventory inventory;
	sf::Vector2f positionPlayer();
	int inThisTower;

private:
	float frameTime;
	float frameRate;
	std::vector<sf::IntRect> playerFrames;
	sf::Texture* texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};