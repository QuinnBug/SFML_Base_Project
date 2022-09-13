#pragma once
#include "Player.h"
#include <iostream>

SpriteObject::SpriteObject(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot)
{
	Init(_texture, _pos, _size, _rot);
}

SpriteObject::SpriteObject()
{

}

void SpriteObject::update(sf::Time deltaTime)
{
	//Pos
	spritePos = position;
	spritePos.x -= size.x / 2;
	spritePos.y -= size.y / 2;
	sprite.setPosition(spritePos);

	//Scale/Size
	if (size.x <= 0) size.x = textureSize.x;
	if (size.y <= 0) size.y = textureSize.y;
	sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);

	//Rotation
	sprite.setRotation(rotation);
}

void SpriteObject::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void SpriteObject::Init(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rot)
{
	setSprite(_texture);
	position = _pos;
	size = _size;
	rotation = _rot;
}

bool SpriteObject::setSprite(sf::Texture& _textureRef)
{
	sprite = sf::Sprite(_textureRef);
	textureSize = _textureRef.getSize();
	return true;
}
