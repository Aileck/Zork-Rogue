#include "World.h"

World::World()
{
    actualScene = 0;
    inBattle = false;
    Scene* s0 = new Scene();
    AddScene(s0);
    hero = new Hero();
    inventory = new Inventory();
    //map += "     [2] [H8]\n";
    //map += "     | |/    \n";
    //map += "[L6]=[1]=[3]=[4]  \n";
    //map += "| |  | | | | \n";
    //map += "[L9] [5] [H10]   \n";
    //map += "     | |   \n";
    //map += "     [E7]  \n";
    Scene* s1 = new Scene("Scene 1", "Level 1", 1);
    Scene* s2 = new Scene("Scene 2", "Level N", 2);
    Scene* s3 = new Scene("Scene 3", "Level W", 3);
    Scene* s4 = new Scene("Scene 4", "Level S", 4);
    Scene* s5 = new Scene("Scene 5", "Level E", 5);
    Scene* s6 = new Scene("Scene 6", "Level E", 5);
    Scene* s7 = new Scene("Scene 7", "Level E", 5);
    Scene* s8 = new Scene("Scene 8", "Level E", 5);
    Scene* s9 = new Scene("Scene 9", "Level E", 5);
    Scene* s10 = new Scene("Scene 10", "Level E", 5);
    //sn->SetLock(true);

    //s1->SetConnections(sn, se, ss, sw, s0);

    //Enemy* e1 = new Enemy("M1", "m1",9,5, 0,1);
    //Enemy* e2 = new Enemy("M2", "m1",9,90, 1, 1);

    //Item* newWeapon2 = new Weapon("Dragon Slayer", "Good", 200, 0, 0, 5, Weapon::HAND_LEFT);
    //e1->SetHold(newWeapon2);

    //s1->AddEnemy(e1);
    //s1->AddEnemy(e2);

    //Weapon* newWeapon = new Weapon("Demon Slayer", "Good", 200, 0, 0, 5, Weapon::HAND_LEFT);
    //s1->AddWeapon(newWeapon);
    //s1->AddItem(map);
    //s1->AddItem(potion);
    //s1->AddItem(key);
    //AddFirstScene(s1);
    //AddScene(sn);
    //AddScene(sw);
    //AddScene(ss);
    //AddScene(se);
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

    lastScene = actualScene;
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

Inventory* World::GetInventory()
{
    return this->inventory;
}
