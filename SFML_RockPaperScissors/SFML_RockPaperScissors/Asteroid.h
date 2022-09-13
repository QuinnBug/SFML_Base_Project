#pragma once
#include "SpriteObject.h"
#include "AABBox.h"
#include "Player.h"

class Asteroid : public SpriteObject
{
public:
	std::shared_ptr<AABBox> collider;

	bool alive = true;

	Asteroid(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot, sf::Vector2f _dir);

	void update(sf::Time deltaTime) override;
	void collisionCheck(std::vector<std::shared_ptr<GameObject>> objects) override;
	std::shared_ptr<AABBox> getCollider() override;

protected:


private:
	sf::Vector2f direction;
	float speed = 250;
};

