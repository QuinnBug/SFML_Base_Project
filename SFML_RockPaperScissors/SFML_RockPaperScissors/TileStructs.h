#pragma once
#include "SFML/Graphics.hpp"

struct TileSheetData
{
	// The texture id will be retrieved by using our texture allocator.
	int textureId; // The id of the tile sets texture. 
	sf::Vector2u imageSize; // The size of the texture.
	int columns; // How many columns in the tile sheet.
	int rows; // How many rows in the tile sheet.
	sf::Vector2u tileSize; // The size of an individual tile.
};

// Stores common tile data.
struct TileInfo
{
	TileInfo() : tileID(-1)
	{
	}

	TileInfo(int textureID, unsigned int tileID, sf::IntRect textureRect)
		: textureID(textureID), tileID(tileID), textureRect(textureRect) { }

	int tileID;
	int textureID = 0;
	sf::IntRect textureRect;
};
