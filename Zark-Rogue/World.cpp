#include "World.h"

World::World()
{
    actualScene = 0;
    Scene* s0 = new Scene();
    AddScene(s0);
    hero = new Hero();

    Scene* s1 = new Scene("Scene 1", "Level 1", 1);
    Scene* sn = new Scene("Scene N", "Level N", 2);
    Scene* sw = new Scene("Scene W", "Level W", 3);
    Scene* ss = new Scene("Scene S", "Level S", 4);
    Scene* se = new Scene("Scene E", "Level E", 5);
    sn->SetLock(true);

    s1->SetConnections(sn, se, ss, sw, s0);

    Weapon* newWeapon = new Weapon("Demon Slayer", "Good", 200, 0, 0, 5, Weapon::HAND_LEFT);
    s1->AddWeapon(newWeapon);
    AddFirstScene(s1);
    AddScene(sn);
    AddScene(sw);
    AddScene(ss);
    AddScene(se);
}


void World::AddFirstScene(Scene* s)
{
    actualScene = s->GetSceneID();
    scenes.push_back(s);
}

void World::AddScene(Scene* s)
{
    scenes.push_back(s);
}

void World::GotoScene(int sceneid)
{
    if (scenes.at(sceneid)->isLocked()) {
        cout << "You find a door, but it is locked. Maybe you need a key." << endl;
        cout << "You cannot move forward, so you returned to the original place." << endl;
        cout << endl;
        return;
    }
    if (scenes.at(sceneid)->isHidden()) {
        cout << "But you can't seem to find any hidden paths." << endl;
        cout << "So you returned to the original place." << endl;
        cout << endl;
        return;
    }

    actualScene = sceneid;

    scenes.at(sceneid)->BeCheked();
}


Scene* World::GetCurrentScene()
{
    return scenes.at(actualScene);
}

Hero * World::GetHero()
{
    return this->hero;
}