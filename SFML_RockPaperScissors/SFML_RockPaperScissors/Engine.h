#pragma once
#include "SpriteObject.h"
#include "Player.h"
#include "Asteroid.h"
#include <vector>

#define PI 3.14159265358979323846

class Engine
{
public:
	Engine();

	bool running = true;

	void Init();
	void Tick(sf::Time deltaTime);

protected:
	

private:
	sf::Vector2i screenSize = sf::Vector2i(1600, 900);
	sf::Sprite background;
	sf::Text scoreText;

	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<GameObject>> gameObjects;

	std::shared_ptr<ResourceHandler> resources;
	sf::View playerView;
	std::unique_ptr<sf::RenderWindow> window;
	float spawnDelay = 3;
	float spawnTimer = 0;

	void spawnAsteroid();
	sf::Vector2f normalizeV2F(sf::Vector2f source);
};