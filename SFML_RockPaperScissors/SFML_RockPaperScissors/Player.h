#pragma once
#include <iostream>
#include "SpriteObject.h"
#include "AABBox.h"

class Player : public SpriteObject
{
public:
    enum class Input { Left = 0, Right = 1, Up = 2, Down = 3};

    std::shared_ptr<AABBox> collider;

    Player(sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, float _rotation);
    Player();

    void update(sf::Time deltaTime) override;
    void collisionCheck(std::vector<std::shared_ptr<GameObject>> objects) override;
    std::shared_ptr<AABBox> getCollider() override;

    void setInput(Input index, sf::Keyboard::Key key);

    sf::Vector2f getMovement();
    int health = 5;

protected:


private:
    std::vector<sf::Keyboard::Key> inputsList;
    sf::Vector2f movementInput;
    sf::FloatRect bounds;
    
    float iTimer = 0;

    float speed = 150;

    void inputReading();
};

