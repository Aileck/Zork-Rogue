#ifndef WORLD_H
#define WORLD_H

#include <vector>

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
	void AddScene(Scene* s);
	void GotoScene(int sceneid);
	Scene* GetCurrentScene();
private:
	int actualScene;
	vector <Scene*> scenes;
};

#endif

