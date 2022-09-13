#include "AABBox.h"

AABBox::AABBox(sf::Vector2f _pos, sf::Vector2f _size)
{
	updateValues(_pos, _size);
}

AABBox::AABBox()
{
}

bool AABBox::doesIntersect(AABBox other)
{
	if (min.x > other.max.x ||
		max.x < other.min.x ||
		min.y > other.max.y ||
		max.y < other.min.y)
	{
		return false;
	}
	
	return true;
}

void AABBox::updateValues(sf::Vector2f _pos, sf::Vector2f _size)
{
	position = _pos;
	size = _size;

	min.x = position.x - (_size.x/2);
	min.y = position.y - (_size.y/2);
	max.x = position.x + (_size.x / 2);
	max.y = position.y + (_size.y / 2);
}


