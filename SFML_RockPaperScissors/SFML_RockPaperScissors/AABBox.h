#pragma once
#include <SFML/Graphics.hpp>

class AABBox
{

public:
    AABBox(sf::Vector2f pos, sf::Vector2f size);
    AABBox();

    bool doesIntersect(AABBox otherBox);
    void updateValues(sf::Vector2f pos, sf::Vector2f size);

protected:


private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f min;
    sf::Vector2f max;
};

