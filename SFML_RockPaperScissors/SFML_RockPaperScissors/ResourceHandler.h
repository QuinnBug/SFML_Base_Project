#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <iostream>
#include <filesystem>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

class ResourceHandler
{
public:
	sf::Texture& getTextureRef(std::string name);
	sf::Font& getFontRef(std::string name);

	ResourceHandler(std::string assetDirectory);

private:
	std::map<std::string, std::shared_ptr<sf::Texture>> textures;
	std::map<std::string, std::shared_ptr<sf::Font>> fonts;
};

