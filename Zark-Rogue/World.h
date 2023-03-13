#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Inventory.h"
#include "Hero.h"
#include "Scene.h"
#include "BattleField.h"

//Scene manager and game manager
class World
{
public:
    World();
    void AddFirstScene(Scene* s);
    void AddScene(Scene* s);
    void GotoScene(int sceneid);
    void GotoLastScene();
    Scene* GetCurrentScene();
    Hero* GetHero();
    Inventory* GetInventory();

private:
    int actualScene;
    int lastScene;

    Hero* hero;
    vector<Scene*> scenes;
    Inventory* inventory;
};


#endif

