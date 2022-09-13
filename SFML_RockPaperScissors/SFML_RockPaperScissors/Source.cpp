#pragma once
#include "Engine.h"

int main()
{
	Engine engine;
	engine.Init();

	sf::Clock clock;

	while (engine.running)
	{
		engine.Tick(clock.restart());
	}
}