#pragma once
#include "SFML/Graphics.hpp"
#include "rapidxml.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Tile.h"
#include <unordered_map>

using Layer = std::vector<std::shared_ptr<Tile>>;
// Stores layer names with layer.
using MapTiles =
std::map<std::string, std::shared_ptr<Layer>>;
// Stores the different tile types that can be used.
using TileSet =
std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;

class TileMapParser
{
public:
	/*TileMapParser(ResourceHandler textureAllocator);
	std::vector<std::shared_ptr<>>
		Parse(const std::string& file, sf::Vector2i offset);
private:
	std::shared_ptr<TileSheetData> BuildTileSheetData(xml_node<>* rootNode);
	std::shared_ptr<MapTiles> BuildMapTiles(xml_node<>* rootNode);
	std::pair<std::string, std::shared_ptr<Layer>>
		BuildLayer(
			xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData
		);
	ResourceAllocator<sf::Texture>& textureAllocator;*/
};



