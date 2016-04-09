#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
#include <fstream>

class PowerUps : public sf::Drawable, public sf::Transformable
{

public:
	PowerUps();
	PowerUps(int which, int xx, int yy);
	~PowerUps();
	void setTextSheet(sf::Texture *textSheet);
	void movePower(int xx, int yy);
	int value;
	sf::Vector2f positionPlayer();

private:
	sf::Texture* texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};