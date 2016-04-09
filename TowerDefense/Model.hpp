#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.hpp"
#include "Tower.hpp"
#include "Enemy.h"
#include "ShopKeeper.hpp"
#include "PowerUps.hpp"
#include "Wave.h"



class Model {
public:
	Model();
	~Model();
	sf::SoundBuffer buffer;
	sf::Sound attackSound;
	void update(sf::Time);
	bool checkPlayerCollision(int);
	int talking(int direc);
	int pickUpPower(int direc);
	int whoTalking;
	int waveNumber, totalWaves;
	int enemiesLeft;
	int enterTower(int direc);
	void addTower(int which, int xx, int yy);
	void addTower(int which);
	void addPowerUp(int which);
	void addShopKeeper(int which, int xx, int yy, int dir);
	void addEnemy(int which, int level);
	void addWave(int which, int size, int level);
	void exitTower();
	void startWave();
	void monsterNeedTex();
	std::map<int, std::map<int, bool>> unpassable;
	sf::VertexArray map;
	sf::RenderStates state;
	Player player;
	sf::Texture tileset;
	std::vector<Tower> towers;
	std::vector<Wave> waves;
	std::vector<ShopKeeper> shops;
	std::vector<Enemy> enemies;
	std::vector<PowerUps> powerUps;
	bool newEnemyAdd;
	int winh, winw, gameMode, mapRows, mapCols, lives, mapX, mapY;
	std::map<int, std::map<int, bool>> checkPoint;
	float mapRotation, dispX, dispY;
};