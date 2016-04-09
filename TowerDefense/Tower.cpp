#include "Tower.hpp"

Tower::Tower()
{
}

Tower::Tower(int which, int xx, int yy) {
	mapX = xx;
	mapY = yy;
	lastShot = this->clock.restart();
	if (which == 1) {
		this->attack = 50;
		this->addAttack = 20;
		this->range = 100;
		this->addRange = 20;
		this->fireRate = 1;
		this->addFireRate = 5;
	}
	else if (which == 2) {
		this->attack = 50;
		this->addAttack = 20;
		this->range = 150;
		this->addRange = 20;
		this->fireRate = 1;
		this->addFireRate = 5;
	}
	else if (which == 3) {
		this->attack = 50;
		this->addAttack = 20;
		this->range = 150;
		this->addRange = 20;
		this->fireRate = 1;
		this->addFireRate = 5;
	}
	else if (which == 4) {
		this->attack = 50;
		this->addAttack = 20;
		this->range = 150;
		this->addRange = 20;
		this->fireRate = 1;
		this->addFireRate = 5;
	}
	else if (which == 5) {
		this->attack = 50;
		this->addAttack = 20;
		this->range = 150;
		this->addRange = 20;
		this->fireRate = 1;
		this->addFireRate = 5;
	}
	else if (which == 6) {
		this->attack = 50;
		this->addAttack = 20;
		this->range = 150;
		this->addRange = 20;
		this->fireRate = 1;
		this->addFireRate = 5;
	}
	else {
		this->attack = 1;
		this->addAttack = 1;
		this->range = 50;
		this->addRange = 1;
		this->fireRate = 1;
		this->addFireRate = 1;
	}

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	this->moving = false;
	this->type = which;
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(xx), float(yy));
	quad[1].position = sf::Vector2f(float(xx + 64), float(yy));
	quad[2].position = sf::Vector2f(float(xx + 64), float(yy + 64));
	quad[3].position = sf::Vector2f(float(xx), float(yy + 64));

	quad[0].texCoords = sf::Vector2f(float((which - 1) * 64), float(0));
	quad[1].texCoords = sf::Vector2f(float(which * 64), float(0));
	quad[2].texCoords = sf::Vector2f(float(which * 64), float(128));
	quad[3].texCoords = sf::Vector2f(float((which - 1) * 64), float(128));
}

Tower::~Tower() {
}

void Tower::moveTower(int xx, int yy) {
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(quad[0].position.x + xx), float(quad[0].position.y + yy));
	quad[1].position = sf::Vector2f(float(quad[1].position.x + xx), float(quad[1].position.y + yy));
	quad[2].position = sf::Vector2f(float(quad[2].position.x + xx), float(quad[2].position.y + yy));
	quad[3].position = sf::Vector2f(float(quad[3].position.x + xx), float(quad[3].position.y + yy));
}

sf::Vector2f Tower::positionTower() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}

void Tower::setTowerText(sf::Texture* towerTextSheet)
{
	this->texSheet = towerTextSheet;
}

void Tower::powerUpTower(int which){
	std::cout << this->attack << std::endl;
	if (which == 1) {
		this->attack += this->addAttack;
		this->addAttack -= 5;
		if (this->addAttack < 5) {
			this->addAttack = 5;
		}
	}
	else if (which == 2) {
		this->range += this->addRange;
		this->addRange -= 5;
		if (this->addRange < 10) {
			this->addRange = 10;
		}
	}
	else if (which == 3) {
		this->fireRate+=this->addFireRate;
		this->addFireRate -=1;
		if (this->addFireRate < 1) {
			this->addFireRate = 1;
		}
	}
}

std::string Tower::getTowerStats()
{
	std::string stats = "---Tower Stats---\nDamade["+std::to_string(this->attack)+"]\nRange["+std::to_string(this->range)+"]\nFire Rate["+std::to_string(this->fireRate)+"]";
	return stats;
}

bool Tower::update(sf::Time delta, std::vector<Enemy> &bad)
{
	sf::Time target = sf::milliseconds(1000/this->fireRate);
	lastShot = this->clock.getElapsedTime();
	//std::cout << "Cords  " << this->vertices[0].position.x<< ", " << this->vertices[0].position.y << std::endl;
	//std::cout << target.asMilliseconds() << " < " << lastShot.asMilliseconds() << ", "<< delta.asMilliseconds()<< std::endl;
	if (target < lastShot) {
		for (unsigned int i = 0; i < bad.size(); i++) {
			//std::cout << 2496 - (64 * 7)-bad.at(i).posX << ", " << 512 - 64-bad.at(i).posY << " Baddy" << std::endl;
			//std::cout << this->mapX << ", " << this->mapY << " Tower" << std::endl;
			float dx = bad.at(i).getPosition().x - this->vertices[0].position.x;
			float dy = bad.at(i).getPosition().y - this->vertices[0].position.y;
			//std::cout << this->mapX << ", " << this->mapY << " Tower" << std::endl;
			//std::cout << this->mapX << ", " << this->mapY << " Enemy" << std::endl;
			dx *= dx;
			dy *= dy;
			double distance = sqrt(dx + dy);
			//std::cout << dx << " X" << std::endl;
			//std::cout << dy << " Y" << std::endl;
			//std::cout << distance << " Distance" << std::endl;
			if (distance < this->range) {
				bad.at(i).attacked(this->attack, this->type);
				lastShot = this->clock.restart();
				return true;
			}
		}
	}
	return false;
}
void Tower::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}
