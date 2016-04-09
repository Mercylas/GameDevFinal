#pragma once
#include "Model.hpp"
#include "ShopBox.hpp"

class View {
public:
	View(Model* m);
	~View();
	bool talking;
	void render();
	void loadPlayerText();
	void loadTowerText();
	void loadShopKeepText();
	void loadPowerUps();
	void loadEnemiesText();
	void setNewTowerTexture();
	void setNewPowerUpTexture();
	void setNewWaveTextur();
	void setText(int who);
	sf::Text sell;
	sf::Text gold;
	sf::Text towerInfo;
	sf::Font fonterino;
	sf::CircleShape rangeOfTower;
	Model* model;
	ShopBox dialogueBox;
	sf::RenderWindow window;
	sf::Texture playerText, towersText, shopKeeperText, powerUpsText;
	std::vector<sf::Texture> enemiesText;
};