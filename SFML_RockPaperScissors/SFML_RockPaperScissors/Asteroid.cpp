#include "Asteroid.h"

Asteroid::Asteroid(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot, sf::Vector2f _dir)
{
	position = _pos;
	SpriteObject::Init(_texture, position, _size, _rot);
	collider = std::make_shared<AABBox>(position, _size);


	direction = _dir;
	tag = "asteroid";
}

void Asteroid::update(sf::Time deltaTime)
{
	//position += speed * direction * deltaTime.asSeconds();
	position = position + (speed * direction * deltaTime.asSeconds());

	SpriteObject::update(deltaTime);
	collider->updateValues(position, size);
}

void Asteroid::collisionCheck(std::vector<std::shared_ptr<GameObject>> objects)
{

}

std::shared_ptr<AABBox> Asteroid::getCollider()
{
	return collider;
}
