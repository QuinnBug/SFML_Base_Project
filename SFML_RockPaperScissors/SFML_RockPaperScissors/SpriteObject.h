#pragma once
#include "GameObject.h"
#include <string>

class SpriteObject : public GameObject
{
public:
	sf::Sprite sprite;
	sf::Vector2u textureSize;

	SpriteObject(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot);
	SpriteObject();

	bool setSprite(sf::Texture& _textureRef);

	void update(sf::Time deltaTime) override;
	void draw(sf::RenderWindow& window) override;

protected:
	void Init(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot);
	sf::Vector2f spritePos;

private:

};