#include "Player.hpp"

Player::Player() {
	this->frameRate = float(0.6);
	//stand
	addFrame(sf::IntRect(0, 2, 64, 64));
	addFrame(sf::IntRect(64, 2, 64, 64));
	addFrame(sf::IntRect(128, 2, 64, 64));
	//walk down
	addFrame(sf::IntRect(0, 66, 64, 64));
	addFrame(sf::IntRect(64, 66, 64, 64));
	addFrame(sf::IntRect(128, 66, 64, 64));
	//walk left
	addFrame(sf::IntRect(0, 130, 64, 64));
	addFrame(sf::IntRect(64, 130, 64, 64));
	addFrame(sf::IntRect(128, 130, 64, 64));
	//walk right
	addFrame(sf::IntRect(0, 194, 64, 64));
	addFrame(sf::IntRect(64, 194, 64, 64));
	addFrame(sf::IntRect(128, 194, 64, 64));
	//walk up
	addFrame(sf::IntRect(0, 258, 64, 64));
	addFrame(sf::IntRect(64, 258, 64, 64));
	addFrame(sf::IntRect(128, 258, 64, 64));
	this->state = 1;
	this->sequenceIndex = 0;
	this->frameTime = 0;
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	this->driving = false;
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(0), float(0));
	quad[1].position = sf::Vector2f(float(64), float(0));
	quad[2].position = sf::Vector2f(float(64), float(64));
	quad[3].position = sf::Vector2f(float(0), float(64));

	quad[0].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).left), float(this->playerFrames.at(this->sequenceIndex).top));
	quad[1].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).width), float(this->playerFrames.at(this->sequenceIndex).top));
	quad[2].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).width), float(this->playerFrames.at(this->sequenceIndex).height));
	quad[3].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).left), float(this->playerFrames.at(this->sequenceIndex).height));
}

Player::~Player() {
}

void Player::setTextSheet(sf::Texture * textSheet)
{
	this->texSheet = textSheet;
}

void Player::update(sf::Time delta) {
	this->frameTime += delta.asSeconds();
	if (this->frameTime > this->frameRate) {
		if (this->sequenceIndex % 3 == 2) {
			this->sequenceIndex -= 2;
			setTexCord();
			this->frameTime = 0;
		}
		else {
			this->sequenceIndex++;
			setTexCord();
			this->frameTime = 0;
		}
	}
}
void Player::movePlayer(int xx, int yy) {
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(quad[0].position.x + xx), float(quad[0].position.y + yy));
	quad[1].position = sf::Vector2f(float(quad[1].position.x + xx), float(quad[1].position.y + yy));
	quad[2].position = sf::Vector2f(float(quad[2].position.x + xx), float(quad[2].position.y + yy));
	quad[3].position = sf::Vector2f(float(quad[3].position.x + xx), float(quad[3].position.y + yy));
}

sf::Vector2f Player::positionPlayer() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}
void Player::setTexCord() {
	sf::Vertex* quad = &this->vertices[0];
	int here = this->sequenceIndex - 3 + 3 * this->state;
	quad[0].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left), float(this->playerFrames.at(here).top));
	quad[1].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left + this->playerFrames.at(here).width), float(this->playerFrames.at(here).top));
	quad[2].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left + this->playerFrames.at(here).width), float(this->playerFrames.at(here).top + this->playerFrames.at(here).height));
	quad[3].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left), float(this->playerFrames.at(here).top + this->playerFrames.at(here).height));
}

void Player::addFrame(sf::IntRect rect) {
	this->playerFrames.push_back(rect);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}
