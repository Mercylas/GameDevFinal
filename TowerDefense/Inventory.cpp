#include "Inventory.h"



Inventory::Inventory()
{
	this->numDamage = 0;
	this->numRange = 0;
	this->gold = 1000;
}


Inventory::~Inventory()
{
}

bool Inventory::canAfford(int price)
{
	int leftOver = this->gold - price;
	if (leftOver >= 0) {
		this->gold = leftOver;
		return true;
	}
	return false;
}

void Inventory::howMany(){
	this->numDamage = 0;
	this->numRange = 0;
	for (unsigned int i = 0; i < this->murse.size(); i++) {
		int c = this->murse.at(i);
		if (c == -1) {
			this->numDamage++;
		}
		else if (c == -2) {
			this->numRange++;
		}
		else if (c == -3) {
			this->numRange++;
		}
	}
}

bool Inventory::usePower(int which){
	if (which == 1 && this->numDamage>0) {
		this->numDamage--;
		for (unsigned int i = 0; i < this->murse.size(); i++) {
			if (this->murse.at(i) == -1) {
				this->murse.erase(this->murse.begin() + i);
				return true;
			}
		}
	}
	else if (which == 2 && this->numRange) {
		this->numRange--;
		for (unsigned int i = 0; i < this->murse.size(); i++) {
			if (this->murse.at(i) == -2) {
				this->murse.erase(this->murse.begin() + i);
				return true;
			}
		}
	}
	else if (which == 3 && this->numRate) {
		this->numRate--;
		for (unsigned int i = 0; i < this->murse.size(); i++) {
			if (this->murse.at(i) == -3) {
				this->murse.erase(this->murse.begin() + i);
				return true;
			}
		}
	}
	return false;
}

std::string Inventory::returnGoldAmount()
{
	std::string goldStr = "Gold: " + std::to_string(this->gold);
	return goldStr;
}

std::string Inventory::returnPowerUpAmount()
{
	std::string powerCounter = "Power Ups: \n\tDamage("+ std::to_string(this->numDamage)+")\n\tRange("+std::to_string(this->numRange)+")\n\tFire Rate("+std::to_string(this->numRate)+")";
	return powerCounter;
}
