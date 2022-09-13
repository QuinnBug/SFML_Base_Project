#include "Player.h"
Player::Player(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot)
{
	SpriteObject::Init(_texture, _pos, _size, _rot);
	collider = std::make_shared<AABBox>(_pos, _size);

	//default limited to 500 from the center
	bounds = sf::FloatRect(-500, -500, 1000, 1000);

	for (size_t i = 0; i < 4; i++)
	{
		inputsList.push_back(sf::Keyboard::Unknown);
	}
}

Player::Player()
{

}

void Player::update(sf::Time deltaTime)
{
	inputReading();

	//movement
	sf::Vector2f newPos = position + (movementInput * speed * deltaTime.asSeconds());
	if (bounds.contains(newPos)) position = newPos;

	//iFrames
	if (iTimer > 0) iTimer -= deltaTime.asSeconds();

	SpriteObject::update(deltaTime);
	collider->updateValues(position, size);
}

void Player::collisionCheck(std::vector<std::shared_ptr<GameObject>> objects)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getTag() == "asteroid" && objects[i]->getCollider()->doesIntersect(*getCollider()))
		{
			//std::cout << std::to_string(objects[i]->getPos().x) + " : " + std::to_string(objects[i]->getPos().y) << std::endl;

			if (iTimer <= 0)
			{
				health -= 1;
				iTimer = 0.15f;
			}
			objects[i]->setDestructionFlag(true);
		}
	}
}

std::shared_ptr<AABBox> Player::getCollider()
{
	return collider;
}

void Player::setInput(Input index, sf::Keyboard::Key key)
{
	inputsList[(int)index] = key;
}

sf::Vector2f Player::getMovement()
{
	return movementInput * speed;
}

void Player::inputReading()
{
	if (sf::Keyboard::isKeyPressed(inputsList[(int)Player::Input::Up])) movementInput.y = -1;
	else if (sf::Keyboard::isKeyPressed(inputsList[(int)Player::Input::Down])) movementInput.y = 1;
	else movementInput.y = 0;

	if (sf::Keyboard::isKeyPressed(inputsList[(int)Player::Input::Right])) movementInput.x = 1;
	else if (sf::Keyboard::isKeyPressed(inputsList[(int)Player::Input::Left])) movementInput.x = -1;
	else movementInput.x = 0;
}
