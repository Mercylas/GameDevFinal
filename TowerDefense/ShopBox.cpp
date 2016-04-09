#include "ShopBox.hpp"

ShopBox::ShopBox() {		//7,10

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(0), float(600));
	quad[0].color = sf::Color(238, 203, 173, 255);
	quad[1].position = sf::Vector2f(float(1280), float(600));
	quad[1].color = sf::Color(238, 203, 173, 255);
	quad[2].position = sf::Vector2f(float(1280), float(960));
	quad[2].color = sf::Color(246, 216, 178, 255);
	quad[3].position = sf::Vector2f(float(0), float(960));
	quad[3].color = sf::Color(246, 216, 178, 255);
}
ShopBox::~ShopBox() {
}

void ShopBox::movePlayer(int xx, int yy) {
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(quad[0].position.x + xx), float(quad[0].position.y + yy));
	quad[1].position = sf::Vector2f(float(quad[1].position.x + xx), float(quad[1].position.y + yy));
	quad[2].position = sf::Vector2f(float(quad[2].position.x + xx), float(quad[2].position.y + yy));
	quad[3].position = sf::Vector2f(float(quad[3].position.x + xx), float(quad[3].position.y + yy));
}

sf::Vector2f ShopBox::positionPlayer() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}

void ShopBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}
