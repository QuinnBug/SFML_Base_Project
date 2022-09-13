#include "ResourceHandler.h"

sf::Texture& ResourceHandler::getTextureRef(std::string name)
{
	if (textures.count(name) == 1)
	{
		return *textures[name];
	}
	
	return *textures["NULL_TEXTURE.png"];
}

sf::Font& ResourceHandler::getFontRef(std::string name)
{
	if (fonts.count(name) == 1)
	{
		return *fonts[name];
	}

	return *fonts["Kenney Pixel.ttf"];
}

ResourceHandler::ResourceHandler(std::string assetDirectory)
{
	std::string filename = "";
	std::string texturePath = assetDirectory + "/Textures/";
	std::string fontPath = assetDirectory + "/Fonts/";

	//Texture Loading
	for (const auto& dirEntry : recursive_directory_iterator(texturePath))
	{
		filename = dirEntry.path().filename().string();
		std::shared_ptr<sf::Texture> txtPtr = std::make_shared<sf::Texture>();
		if(txtPtr->loadFromFile(texturePath + filename))
		{
			std::cout << "Loaded " + filename  << std::endl;
			textures[filename] = txtPtr;
		}
		else
		{
			std::cout << "Failed to Load " + texturePath  << std::endl;
		}
	}

	//Font loading
	for (const auto& dirEntry : recursive_directory_iterator(fontPath))
	{
		filename = dirEntry.path().filename().string();
		std::shared_ptr<sf::Font> fntPtr = std::make_shared<sf::Font>();
		if (fntPtr->loadFromFile(fontPath + filename))
		{
			std::cout << "Loaded " + filename << std::endl;
			fonts[filename] = fntPtr;
		}
		else
		{
			std::cout << "Failed to Load " + filename << std::endl;
		}
	}

	std::cout << "Loading Complete" << std::endl;
}
