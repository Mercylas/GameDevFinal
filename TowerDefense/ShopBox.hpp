#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class ShopBox : public sf::Drawable, public sf::Transformable
{

public:
	ShopBox();
	~ShopBox();
	void movePlayer(int xx, int yy);
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