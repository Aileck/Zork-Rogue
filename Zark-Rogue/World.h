#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Hero.h"
#include "Scene.h"
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
class World
{
public:
    World();
    void AddFirstScene(Scene* s);
    void AddScene(Scene* s);
    void GotoScene(int sceneid);
    Scene* GetCurrentScene();
    Hero* GetHero();

private:
    int actualScene;
    Hero* hero;
    vector<Scene*> scenes;
};


#endif

