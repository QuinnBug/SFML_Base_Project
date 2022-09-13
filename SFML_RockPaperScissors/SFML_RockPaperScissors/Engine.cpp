#pragma once
#include "Engine.h"

Engine::Engine()
{
	running = true;
}

void Engine::Init()
{
	resources = std::make_shared<ResourceHandler>("Assets");
	resources->getTextureRef("background.jpg").setRepeated(true);

	background = sf::Sprite(resources->getTextureRef("background.jpg"),
		sf::IntRect(-screenSize.x / 2, -screenSize.y / 2, screenSize.x, screenSize.y));
	background.setPosition(-screenSize.x / 2, -screenSize.y / 2);

	player = std::make_shared<Player>(
		resources->getTextureRef("SpaceMan.png"), sf::Vector2f(0, 0), sf::Vector2f(75, 100), 0);

	player->setInput(Player::Input::Right, sf::Keyboard::Key::D);
	player->setInput(Player::Input::Left, sf::Keyboard::Key::A);
	player->setInput(Player::Input::Up, sf::Keyboard::Key::W);
	player->setInput(Player::Input::Down, sf::Keyboard::Key::S);

	gameObjects.push_back(player);

	scoreText.setFont(resources->getFontRef("Kenney Pixel.ttf"));
	scoreText.setCharacterSize(50);

	playerView.reset(sf::FloatRect(-screenSize.x / 2, -screenSize.y / 2, screenSize.x, screenSize.y));
	playerView.setViewport(sf::FloatRect(0, 0, 1, 1));

	window = std::make_unique<sf::RenderWindow>();
	window->create(sf::VideoMode(screenSize.x, screenSize.y), "Asteroids");
	window->setView(playerView);

	running = true;
}

void Engine::Tick(sf::Time deltaTime)
{
	if (window->isOpen())
	{
#pragma region Update
		
		playerView.setCenter(player->getPos());
		window->setView(playerView);

		spawnTimer += deltaTime.asSeconds();
		if (spawnTimer >= spawnDelay)
		{
			spawnAsteroid();
		}

		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i]->getActive()) gameObjects[i]->update(deltaTime);
		}

		scoreText.setPosition(player->getPos() + sf::Vector2f(-screenSize.x/2 + 10, -screenSize.y / 2 + 10));

		std::string hpString = std::to_string(player->health);
		scoreText.setString("HP: " + hpString);

		if (player->health <= 0) running = false;
#pragma endregion

#pragma region Collisions
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if(gameObjects[i]->getActive()) gameObjects[i]->collisionCheck(gameObjects);
		}
#pragma endregion

#pragma region LateUpdate
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i]->getDestructionFlag())
			{
				gameObjects[i].reset();
				gameObjects.erase(gameObjects.begin() + i);
				i--;
			}
		}
		gameObjects.shrink_to_fit();

#pragma endregion

#pragma region Draw
		window->clear(sf::Color::Black);

		window->draw(background);
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if(gameObjects[i]->getActive()) gameObjects[i]->draw(*window);
		}
		window->draw(scoreText);

		window->display();
#pragma endregion

	}
	else
	{
		running = false;
	}
}

void Engine::spawnAsteroid()
{
	sf::Vector2f randomPos = player->getPos();
	sf::Vector2f angle = sf::Vector2f(
		((rand() % 100) - 50)/100.0f,
		((rand() % 100) - 50)/100.0f
	);
	angle = normalizeV2F(angle);

	//move a certain distance in the direction of the angle
	randomPos.x += angle.x * 500;
	randomPos.y += angle.y * 500;

	sf::Vector2f randomDir = normalizeV2F(player->getPos() - randomPos);
	
	gameObjects.push_back(std::make_shared<Asteroid>
		(resources->getTextureRef("Asteroid.png"), randomPos, sf::Vector2f(25, 25), rand() % 360, randomDir));

	spawnTimer = 0;
}

sf::Vector2f Engine::normalizeV2F(sf::Vector2f source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}
