#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 

class Inventory
{
public:
	Inventory();
	~Inventory();
	int gold;
	bool canAfford(int price);
	int numDamage, numRange, numRate;
	void howMany();
	bool usePower(int which);
	std::vector<int> murse;
	std::string returnGoldAmount();
	std::string returnPowerUpAmount();
};

