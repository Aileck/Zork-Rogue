#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Inventory.h"
#include "Hero.h"
#include "Scene.h"
#include "BattleField.h"
/* World map
* Scene 0 = no route
*          [2]   [8]
           | | Hidden
		   | | /
* [3]=LOCK=[1]==[4]
  | |      | |
 Hidden	   [5]
  [9]	   | |
		   [7]

*/

//Scene manager and game manager
class World
{
public:
    World();
    void AddFirstScene(Scene* s);
    void AddScene(Scene* s);
    void GotoScene(int sceneid);
    Scene* GetCurrentScene();
    Hero* GetHero();
    Inventory* GetInventory();

private:
    int actualScene;
    int lastScene;

    Hero* hero;
    vector<Scene*> scenes;
    Inventory* inventory;
    bool inBattle;
};


#endif

