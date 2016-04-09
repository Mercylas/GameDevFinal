#include "Enemy.h"



Enemy::Enemy(int t, int l)
{
	this->frameRate = float(0.6);
	this->type = t;
	this->level = l;
	this->inventory.gold = 0;
	this->checkpoint = -1;//spawns on checkpoint -1
	switch (type) {
	case 1:
		this->inventory.gold = 10*level;
		this->health = 100 * level;
		this->speed = 1*level;
		if (this->speed == 3) {
			this->speed = 2;
		}
		else if (this->speed > 4) {
			this->speed = 4;
		}
		break;
	default:
		this->health = 100;
		this->speed = 1;
		break;
	}
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
	this->state = 2;
	this->sequenceIndex = 0;
	this->frameTime = 0;
	this->texSheet = 0;
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(0), float(0));
	quad[1].position = sf::Vector2f(float(64), float(0));
	quad[2].position = sf::Vector2f(float(64), float(64));
	quad[3].position = sf::Vector2f(float(0), float(64));

	quad[0].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).left), float(this->playerFrames.at(this->sequenceIndex).top));
	quad[1].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).width), float(this->playerFrames.at(this->sequenceIndex).top));
	quad[2].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).width), float(this->playerFrames.at(this->sequenceIndex).height));
	quad[3].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).left), float(this->playerFrames.at(this->sequenceIndex).height));
	this->posX = 0;
	this->posY = 0;
}


Enemy::~Enemy()
{
}

void Enemy::update(sf::Time delta)
{
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
	switch (checkpoint) {
		case -1:
			this->state = 2;
		break;
		case 0:
			//spawns next enemy here on normal wave
			this->state = 2;
		break;
		case 1:
			this->state = 4;
		break;
		case 2:
			this->state = 3;
		break;
		case 3:
			this->state = 4;
		break;
		case 4:
			this->state = 2;
		break;
		case 5:
			this->state = 1;
		break;
		case 6:
			this->state = 3;
		break;
		case 7:
			this->state = 1;
		break;
		case 8:
			this->state = 2;
		break;
		case 9:
			this->state = 4;
		break;
		case 10:
			this->state = 3;
		break;
		case 11:
			this->state = 4;
		break;
		case 12:
			this->state = 2;
		break;
		case 13:
			this->state = 1;
		break;
		case 14:
			this->state = 2;
		break;
		default:
			//broken
		break;
	}
	//1 = down, 2 = left, 3 = right, 4 = up
	this->move(this->state);
}

void Enemy::setTexCord()
{
	sf::Vertex* quad = &this->vertices[0];
	int here = this->sequenceIndex - 3 + 3 * this->state;
	quad[0].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left), float(this->playerFrames.at(here).top));
	quad[1].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left + this->playerFrames.at(here).width), float(this->playerFrames.at(here).top));
	quad[2].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left + this->playerFrames.at(here).width), float(this->playerFrames.at(here).top + this->playerFrames.at(here).height));
	quad[3].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left), float(this->playerFrames.at(here).top + this->playerFrames.at(here).height));
}

void Enemy::addFrame(sf::IntRect rect)
{
	this->playerFrames.push_back(rect);
}

sf::Vector2f Enemy::positionEnemy() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}
bool Enemy::texSet()
{
	if (this->texSheet == 0) {
		return false;
	}
	else {
		return true;
	}
}
void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}

bool Enemy::isDead() {
	return (health < 1);
}

void Enemy::UpdatePos(int mapX, int mapY) {
	mapX += 3776 - 32;
	mapY += 896;
	this->setPosition(float(this->posX + mapX), float(this->posY + mapY));
	//std::cout << "Enemy  " << this->getPosition().x << ", " << this->getPosition().y << std::endl;

}

void Enemy::attacked(int damage, int type)
{
	this->health -= damage;
	//std::cout << "HP down to " << this->health << std::endl;
}

void Enemy::move(int direction) {
	//0 = down, 1 = left, 2 = right, 3 = up
	switch (direction) {
		case 1:
			this->posY += speed;
		break;
		case 2:
			this->posX -= speed;
		break;
		case 3:
			this->posX += speed;
		break;
		case 4:
			this->posY -= speed;
		break;
	}
}

int Enemy::checkPointUpdate(int update) {
	this->checkpoint+=update;
	return checkpoint;
}

void Enemy::setTextSheet(sf::Texture * enemyText)
{
	this->texSheet = enemyText;
}
