#include "World.h"

World::World()
{
	actualScene = 0;
	scenes = {};
}

void World::AddScene(Scene* s)
{
	scenes.push_back(s);
}

void World::GotoScene(int sceneid)
{
	actualScene = sceneid;
}

Scene* World::GetCurrentScene()
{
	return scenes.at(actualScene);
}
