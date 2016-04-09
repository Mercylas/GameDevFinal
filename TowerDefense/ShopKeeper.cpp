#include "ShopKeeper.hpp"

ShopKeeper::ShopKeeper() {
}

ShopKeeper::ShopKeeper(int which, int xx, int yy, int dir) {		//7,10
	this->direction = dir;
	if (which == 7) {
		this->prices.push_back(50);
		this->prices.push_back(200);
		this->prices.push_back(200);
		this->prices.push_back(500);
		this->shopMenu = "\t\t\t\t\t\t\tPowerUps\n\t\t\t\t\t1) Damage+ ("+std::to_string(this->prices.at(0))+")\n\t\t\t\t\t2) Range+ ("+std::to_string(this->prices.at(1))+")\n\t\t\t\t\t3) Fire Rate+ ("+std::to_string(this->prices.at(2))+")\n\t\t\t\t\t4) HP+ (" + std::to_string(this->prices.at(3)) + ")";
	}
	else if (which == 10) {
		this->shopMenu = "\t\t\t\t\t\t  Tower Shop\n\t1) Tower of Doom\t\t\t2) Tower of The Fallen\n\t3) Towers of Towers\t\t 4) Towers of Redundance\n\t5) Towers of Towers\t\t 6) Towers of Towers";
		this->prices.push_back(100);
		this->prices.push_back(200);
		this->prices.push_back(500);
		this->prices.push_back(1000);
		this->prices.push_back(1000);
		this->prices.push_back(1500);
		this->shopMenu += "\n\n\tPrices: ";
		for (unsigned int i = 0; i < this->prices.size(); i++) {
			this->shopMenu += std::to_string(i + 1) + ")" + std::to_string(this->prices.at(i)) + "  ";
		}
	}

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(xx), float(yy));
	quad[1].position = sf::Vector2f(float(xx + 64), float(yy));
	quad[2].position = sf::Vector2f(float(xx + 64), float(yy + 64));
	quad[3].position = sf::Vector2f(float(xx), float(yy + 64));

	quad[0].texCoords = sf::Vector2f(float((which - 1) * 64), float(64 * 4));
	quad[1].texCoords = sf::Vector2f(float(which * 64), float(64 * 4));
	quad[2].texCoords = sf::Vector2f(float(which * 64), float(64 * 5));
	quad[3].texCoords = sf::Vector2f(float((which - 1) * 64), float(64 * 5));
}
ShopKeeper::~ShopKeeper() {
}

void ShopKeeper::setTextSheet(sf::Texture * textSheet)
{
	this->texSheet = textSheet;
}

void ShopKeeper::movePlayer(int xx, int yy) {
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(quad[0].position.x + xx), float(quad[0].position.y + yy));
	quad[1].position = sf::Vector2f(float(quad[1].position.x + xx), float(quad[1].position.y + yy));
	quad[2].position = sf::Vector2f(float(quad[2].position.x + xx), float(quad[2].position.y + yy));
	quad[3].position = sf::Vector2f(float(quad[3].position.x + xx), float(quad[3].position.y + yy));
}

sf::Vector2f ShopKeeper::positionPlayer() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}

void ShopKeeper::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}
