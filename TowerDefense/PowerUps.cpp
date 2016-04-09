#include "PowerUps.hpp"

PowerUps::PowerUps() {
}

PowerUps::PowerUps(int which, int xx, int yy) {		//7,10

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(xx), float(yy));
	quad[1].position = sf::Vector2f(float(xx + 64), float(yy));
	quad[2].position = sf::Vector2f(float(xx + 64), float(yy + 64));
	quad[3].position = sf::Vector2f(float(xx), float(yy + 64));

	this->value = which*-1;

	quad[0].texCoords = sf::Vector2f(float(64 * (8 - which)), float(64 * 3) + 1);
	quad[1].texCoords = sf::Vector2f(float(64 * (9 - which)), float(64 * 3) + 1);
	quad[2].texCoords = sf::Vector2f(float(64 * (9 - which)), float(64 * 4) + 1);
	quad[3].texCoords = sf::Vector2f(float(64 * (8 - which)), float(64 * 4) + 1);
}
PowerUps::~PowerUps() {
}

void PowerUps::setTextSheet(sf::Texture * textSheet)
{
	this->texSheet = textSheet;
}

void PowerUps::movePower(int xx, int yy) {
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(quad[0].position.x + xx), float(quad[0].position.y + yy));
	quad[1].position = sf::Vector2f(float(quad[1].position.x + xx), float(quad[1].position.y + yy));
	quad[2].position = sf::Vector2f(float(quad[2].position.x + xx), float(quad[2].position.y + yy));
	quad[3].position = sf::Vector2f(float(quad[3].position.x + xx), float(quad[3].position.y + yy));
}

sf::Vector2f PowerUps::positionPlayer() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}

void PowerUps::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}
