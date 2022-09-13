#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::setPos(sf::Vector2f _pos)
{
	position = _pos;
}

void GameObject::setRot(float _rot)
{
	rotation = _rot;
}

void GameObject::setSize(sf::Vector2f _size)
{
	size = _size;
}

void GameObject::setActive(bool _active)
{
	active = _active;
}

void GameObject::setDestructionFlag(bool _flag)
{
	destructionFlag = _flag;
}

void GameObject::setTag(std::string _tag)
{
	tag = _tag;
}

sf::Vector2f GameObject::getPos()
{
	return position;
}

float GameObject::getRot()
{
	return rotation;
}

sf::Vector2f GameObject::getSize()
{
	return size;
}

bool GameObject::getActive()
{
	return active;
}

bool GameObject::getDestructionFlag()
{
	return destructionFlag;
}

std::string GameObject::getTag()
{
	return tag;
}

std::shared_ptr<AABBox> GameObject::getCollider()
{
	return nullptr;
}

void GameObject::update(sf::Time deltaTime)
{
}

void GameObject::lateUpdate(sf::Time deltaTime)
{
}

void GameObject::draw(sf::RenderWindow& window)
{
}

void GameObject::collisionCheck(std::vector<std::shared_ptr<GameObject>> objects)
{
}


