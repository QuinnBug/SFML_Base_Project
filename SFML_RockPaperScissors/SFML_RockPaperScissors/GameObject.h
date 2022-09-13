#pragma once
#include "SFML/Graphics.hpp"
#include "ResourceHandler.h"
#include "AABBox.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void setPos(sf::Vector2f _pos);
	void setRot(float _rot);
	void setSize(sf::Vector2f _size);
	void setActive(bool _active);
	void setDestructionFlag(bool _flag);
	void setTag(std::string _tag);

	sf::Vector2f getPos();
	float getRot();
	sf::Vector2f getSize();
	bool getActive();
	bool getDestructionFlag();
	std::string getTag();

	virtual std::shared_ptr<AABBox> getCollider();

	virtual void update(sf::Time deltaTime);
	virtual void lateUpdate(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow& window);
	virtual void collisionCheck(std::vector<std::shared_ptr<GameObject>> objects);

protected:
	sf::Vector2f position;
	sf::Vector2f size;
	float rotation = 0;
	bool active = true;
	bool destructionFlag = false;
	std::string tag;

private:


};

