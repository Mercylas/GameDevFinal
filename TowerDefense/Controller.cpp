#include "Controller.hpp"

Controller::Controller(Model * m, View * v) {
	this->model = m;
	this->view = v;
	this->ready = true;
	start();
}

Controller::~Controller() {
}

void Controller::inputs() {
	sf::Event event;

	while (this->view->window.pollEvent(event))
	{
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			this->view->window.close();
			break;
			// key pressed
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				this->view->window.close();
				break;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				if (this->model->player.driving && this->model->player.inventory.usePower(1)) {
					this->model->towers.at(this->model->player.inThisTower).powerUpTower(1);
				}
				else{
					if (this->view->talking) {
						if (this->model->whoTalking) {
							if (this->model->player.inventory.canAfford(this->model->shops.at(1).prices.at(0))) {
								this->model->addTower(1);
								this->view->setNewTowerTexture();
							}
						}
						else {
							if (this->model->player.inventory.canAfford(this->model->shops.at(0).prices.at(0))) {
								this->model->addPowerUp(1);
								this->view->setNewPowerUpTexture();
							}
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				if (this->model->player.driving && this->model->player.inventory.usePower(2)) {
					this->model->towers.at(this->model->player.inThisTower).powerUpTower(2);
				}
				else{
					if (this->view->talking) {
						if (this->model->whoTalking) {
							if (this->model->player.inventory.canAfford(this->model->shops.at(1).prices.at(1))) {
								this->model->addTower(2);
								this->view->setNewTowerTexture();
							}
						}
						else {
							if (this->model->player.inventory.canAfford(this->model->shops.at(0).prices.at(1))) {
								this->model->addPowerUp(2);
								this->view->setNewPowerUpTexture();
							}
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				if (this->model->player.driving && this->model->player.inventory.usePower(3)) {
					this->model->towers.at(this->model->player.inThisTower).powerUpTower(3);
				}
				else{
					if (this->view->talking) {
						if (this->model->whoTalking) {
							if (this->model->player.inventory.canAfford(this->model->shops.at(1).prices.at(2))) {
								this->model->addTower(3);
								this->view->setNewTowerTexture();
							}
						}
						else {
							if (this->model->player.inventory.canAfford(this->model->shops.at(0).prices.at(2))) {
								this->model->addPowerUp(4);
								this->view->setNewPowerUpTexture();
							}
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
				if (this->view->talking) {
					if (this->model->whoTalking) {
						if (this->model->player.inventory.canAfford(this->model->shops.at(1).prices.at(3))) {
							this->model->addTower(4);
							this->view->setNewTowerTexture();
						}
					}
					else {
						if (this->model->player.inventory.canAfford(this->model->shops.at(0).prices.at(3))) {
							this->model->addPowerUp(3);
							this->view->setNewPowerUpTexture();
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
				if (this->view->talking) {
					if (this->model->whoTalking) {
						if (this->model->player.inventory.canAfford(this->model->shops.at(1).prices.at(4))) {
							this->model->addTower(5);
							this->view->setNewTowerTexture();
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
				if (this->view->talking) {
					if (this->model->whoTalking) {
						if (this->model->player.inventory.canAfford(this->model->shops.at(1).prices.at(5))) {
							this->model->addTower(6);
							this->view->setNewTowerTexture();
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				this->view->talking = false;
				if (!model->checkPlayerCollision(0)) {
					if (this->model->player.driving) {
						model->mapY += 4;
						model->dispY += 4;
					}
					else {
						model->mapY += 4;
						model->dispY += 4;
					}
				}
				model->player.state = 5;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				this->view->talking = false;
				if (!model->checkPlayerCollision(1)) {
					if (this->model->player.driving) {
						model->mapY -= 4;
						model->dispY -= 4;
					}
					else {
						model->mapY -= 4;
						model->dispY -= 4;
					}
				}
				model->player.state = 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				this->view->talking = false;
				if (!model->checkPlayerCollision(2)) {
					if (this->model->player.driving) {
						model->mapX += 4;
						model->dispX += 4;
					}
					else {
						model->mapX += 4;
						model->dispX += 4;
					}
				}
				model->player.state = 3;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				this->view->talking = false;
				if (!model->checkPlayerCollision(3)) {
					if (this->model->player.driving) {
						model->mapX -= 4;
						model->dispX -= 4;
					}
					else {
						model->mapX -= 4;
						model->dispX -= 4;
					}
				}
				model->player.state = 4;
			}
			break;
			//Key Released
		case sf::Event::KeyReleased:
			model->player.state = 1;
			this->ready = true;
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			this->model->startWave();
			this->view->setNewWaveTextur();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (this->ready) {
				if (this->model->player.driving) {
					//std::cout << this->model->mapX << ", " << this->model->mapY << std::endl;
					this->model->exitTower();
				}
				else {
					int pickUp=this->model->pickUpPower(this->model->player.state);
					if (pickUp == -1) {
						int talk = this->model->talking(this->model->player.state);
						if (talk == -1) {
							this->model->enterTower(this->model->player.state);
						}
						else {
							this->view->talking = true;
							this->view->setText(talk);
							this->model->whoTalking = talk;
						}
					}
					else {
						int valuePower = this->model->powerUps.at(pickUp).value;
						//std::cout << valuePower << std::endl;
						this->model->powerUps.erase(this->model->powerUps.begin() + pickUp);
						if (valuePower == -3) {
							this->model->lives += 50;
						}
						else if (valuePower == -4) {
							this->model->player.inventory.murse.push_back(-3);
							this->model->player.inventory.numRate++;
						}
						else if (valuePower == -2) {
							this->model->player.inventory.murse.push_back(-2);
							this->model->player.inventory.numRange++;
						}
						else if (valuePower==-1) {
							this->model->player.inventory.murse.push_back(-1);
							this->model->player.inventory.numDamage++;
						}
					}
				}
				this->ready = false;
			}
		}
	}
}
void Controller::start() {
	std::cout << "-------- Drive By Defense -------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	while (model->gameMode != 1 || model->gameMode != 2) {
		std::cout << "------ Choose a game type -------" << std::endl;
		std::cout << "1. Sandbox" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cin >> model->gameMode;
		if (std::cin.fail() || !(model->gameMode >= 1 && model->gameMode <= 2))
		{
			std::cout << "invalid selection!" << std::endl;
			std::cout << "selection: " << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		if (model->gameMode == 1 || model->gameMode == 2) {
			std::cout << "-------- Enjoy the game! --------" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			break;
		}
		std::cout << "You entered: " << model->gameMode << std::endl;
		std::cout << "That is not a valid input! " << model->gameMode << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
}