#pragma once
#include "SpriteObject.h"
#include "AABBox.h"
#include "TileStructs.h"

class Tile : public SpriteObject
{
public:
	std::shared_ptr<TileInfo> properties;
	int x;
	int y;

	std::shared_ptr<AABBox> collider;

	bool collidable;

	Tile();

protected:

private:

};

