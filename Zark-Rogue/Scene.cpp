#include "Scene.h"

Scene::Scene():Checkeable("No way", "No way")
{
	//Dead end scene
	id = 0;
}

void Scene::BeCheked() {
	Checkeable::BeCheked();
    string out = "You vlavla.";
    out += "\n===Scene===";

    //Items
    out += "\n*Items:";
    for (int i = 0; i < items.size(); i++) {
        out += "\n\t* " + items.at(i)->GetName();
    }
    out += "\n*Weapons:";
    for (int i = 0; i < weapons.size(); i++) {
        out += "\n\t* " + weapons.at(i)->GetName();
    }

    if (weapons.size() > 2) {
        out += "\nYou couldn't help but marvel at how many things you could fit on your belt.";
    }


    cout << out << endl;
}

Scene::Scene(string name, string definition, int id) :Checkeable(name, definition)
{
	this->id = id;

	//If is locked by a key
	this->locking = false;
	this->visited = false;

	//Initialy wihout any connection, to be set later
	SetConnections(new Scene(), new Scene(), new Scene(), new Scene(), new Scene());
}

int Scene::GetSceneID() {
	return this->id;
}

void Scene::AddEnemy(Enemy* enemy)
{
    enemies.push_back(enemy);
}

void Scene::AddItem(Item* item)
{
    items.push_back(item);
}

void Scene::AddWeapon(Weapon* weapon)
{
    weapons.push_back(weapon);
}

vector<Enemy*> Scene::GetEnemy()
{
    return this->enemies;
}


void Scene::SetLock(bool ifIsLocked)
{
	locking = ifIsLocked;
}

void Scene::SetHidden(bool ifIsHidden)
{
	this->hiding = ifIsHidden;
}

bool Scene::isLocked()
{
	return this->locking;
}

bool Scene::isHidden()
{
	return this->hiding;
}


Checkeable* Scene::IfContains(string target)
{
    // To deal check object action, check if this scene contain...

    // Enemy
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies.at(i)->GetName(true) == target) {
            enemies.at(i)->BeCheked();
            return enemies.at(i);
        }
    }

    // Item
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i)->GetName(true) == target) {
            return items.at(i);
        }
    }

    // Weapon
    for (int i = 0; i < weapons.size(); i++) {
        if (weapons.at(i)->GetName(true) == target) {
            weapons.at(i)->BeCheked();
            return weapons.at(i);
        }
    }

    Checkeable* notfound = new Checkeable();
    return notfound;
}

Item* Scene::IfContainsItem(string target)
{
    // Item
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i)->GetName(true) == target) {
            Item* copy = items.at(i);
            items.erase(items.begin() + (i));
            return copy;
        }
    }

    return new Item();
}

Enemy* Scene::IfContainsEnemy(string target)
{
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies.at(i)->GetName(true) == target) {

            return enemies.at(i);
        }
    }

    return new Enemy();
}

Weapon* Scene::IfContainsWeapon(string target)
{
    // Weapon
    for (int i = 0; i < weapons.size(); i++) {
        if (weapons.at(i)->GetName(true) == target) {
            Weapon* copy = weapons.at(i);
            weapons.erase(weapons.begin()+(i));
            return copy;
        }
    }

    return new Weapon();
}

void Scene::SetConnections(Scene* n, Scene* w, Scene* s, Scene* e, Scene* h)
{
    //Set 4 connections and a hidden room if exists
    this->north = n;
    this->east = e;
    this->south = s;
    this->west = w;

    this->hidden = h;

    //We are declaring that h is hidden room
    if (h->GetSceneID() != 0) {
        h->SetHidden(true);
    }
}

int Scene::CheckDestination(string target) {
    //To deal goto action
    if (target == "north" || target == "n") {
        return north->GetSceneID();
    }

    if (target == "west" || target == "w") {
        return west->GetSceneID();
    }

    if (target == "south" || target == "s") {
        return south->GetSceneID();
    }

    if (target == "east" || target == "e") {
        return east->GetSceneID();
    }

    if (target == "hidden" || target == "h") {
        return hidden->GetSceneID();
    }

    else
        return -1;
}

bool Scene::GetNoticed()
{
    return enemiesNoticedYou;
}

void Scene::NoticedYou()
{
    enemiesNoticedYou = true;
}
