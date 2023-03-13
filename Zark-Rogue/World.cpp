#include "World.h"

World::World()
{
    actualScene = 0;
    lastScene = 0;

    Scene* s0 = new Scene();
    AddScene(s0);
    hero = new Hero();
    inventory = new Inventory();
    //Initial weapon
    Weapon* toySword = new Weapon("Toy sword", "A wooden sword, at least can use for self-defense", 3, 0, 0, 2, Weapon::WeaponType::HAND_LEFT);
    inventory->AddWeapon(toySword);

    //map += "     [2] [H8]\n";
    //map += "     | |/    \n";
    //map += "[L6]=[1]=[3]=[4]  \n";
    //map += "| |  | |  \n";
    //map += "[L9] [5]    \n";
    //map += "     | |   \n";
    //map += "     [E7]  \n";
    Scene* s1 = new Scene("Scene 1", "There is a big bell in the middle of the place where you fell.", 1); //Check, pick
    Scene* s2 = new Scene("Scene 2", "There are many exposed ores on the walls here, but you are unable to obtain them as you do not have any tools.", 2); //c p
    Scene* s3 = new Scene("Scene 3", "At first glance, you can see a conspicuous man-made gate to the east, and there are many corpses on the ground.", 3); //c p
    Scene* s4 = new Scene("Scene 4", "This place is a huge colosseum filled with of monstrous creatures.", 4);
    Scene* s5 = new Scene("Scene 5", "In the middle, there is a sand dune tower that is protected by a force field, making it impossible to approach. \nAdditionally, there is a terrifying energy emanating from the south.", 5); //c p a
    Scene* s6 = new Scene("Scene 6", "At a glance, you can see a conspicuous man-made gate to the south from here.", 6);
    s6->SetLock(true);
    Scene* s7 = new Scene("Scene 7", "You see a staircase leading downwards, but a giant dragon is guarding it, making it impossible for you to approach. \nWithout a doubt, it's a terrifying and powerful enemy. \nYou should prepare yourself before attempting to face it.", 7);
    Scene* s8 = new Scene("Scene 8", "There is nothing here but a sword on the floor.", 8); //c
    Scene* s9 = new Scene("Scene 9", "This is an ancient and dilapidated laboratory, with many bottles and jars and strange liquids scattered on the ground.", 9);
    s9->SetLock(true);
    
    string hiddenExplication("\033[3mTips: If you neet to go back, just use command go back.\033[0m");
    s8->AddDefinition(hiddenExplication);

    AddFirstScene(s1);
    AddScene(s2);
    AddScene(s3);
    AddScene(s4);
    AddScene(s5);
    AddScene(s6);
    AddScene(s7);
    AddScene(s8);
    AddScene(s9);


    //Connections
    s1->SetConnections(s2, s3, s5, s6, s8);
    s2->SetConnections(s0, s0, s1, s0);
    s3->SetConnections(s0, s4, s0, s1);
    s4->SetConnections(s0, s0, s0, s3);
    s5->SetConnections(s1, s0, s7, s0);
    s6->SetConnections(s0, s1, s9, s0);
    s7->SetConnections(s5, s0, s0, s0);
    //S8 hidden, no connection
    s8->SetConnections(s0, s0, s0, s0);
    s9->SetConnections(s6, s0, s0, s0);
    
    //Scene 1
    Enemy* e1_1 = new Enemy("Bat", "Harmless little bats.", 10, 2, 0, 0);
    Enemy* e1_2 = new Enemy("Slim", "Harmless little slim.", 8, 3, 0, 0);
    
    Item* p_1_1 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);
    Item* toyShield = new Weapon("Toy shield", "A wooden shield, at least can use for self-defense.", 0, 5, 0, 2, Weapon::WeaponType::HAND_RIGHT);
    e1_1->SetHold(p_1_1);
    e1_2->SetHold(toyShield);

    s1->AddEnemy(e1_1);
    s1->AddEnemy(e1_2);

    //S2
    Enemy* e2_1 = new Enemy("Bat", "Harmless little bats.", 11, 7, 3, 0);
    Enemy* e2_2 = new Enemy("Slim A", "Harmless little slim.", 9, 5, 1, 0);
    Enemy* e2_3 = new Enemy("Slim B", "Harmless little slim.", 9, 5, 1, 0);

    Item* p_2_1 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);
    Item* p_2_2 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);
    Item* p_2_3 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);

    s2->AddEnemy(e2_1);
    s2->AddEnemy(e2_2);
    s2->AddEnemy(e2_3);

    s2->AddItem(p_2_1);
    s2->AddItem(p_2_2);
    s2->AddItem(p_2_3);

    //S3
    Item* shoe = new Weapon("Sky Trailers", "These shoes allow the wearer to move quickly and walk in the air for a few seconds.", 0, 5, 0, 20, Weapon::WeaponType::FOOT);
    Enemy* e3_1 = new Enemy("Bat", "Harmless little bats.", 15, 8, 3, 0);
    Enemy* e3_2 = new Enemy("Goblin", "Harmless little goblin.", 9, 4, 0, 0);
    Enemy* e3_3 = new Enemy("Slim", "Pretty strong little slim.", 12, 12, 12, 0);

    e3_1->SetHold(shoe);

    s3->AddEnemy(e3_1);
    s3->AddEnemy(e3_2);
    s3->AddEnemy(e3_3);

    //S4    
    Enemy* e4_1 = new Enemy("Bat A", "Harmless little bats.", 20, 6, 3, 0);
    Enemy* e4_2 = new Enemy("Goblin A", "Harmless little goblin.", 21, 6, 0, 0);
    Enemy* e4_3 = new Enemy("Slim A", "Harmless little slim.", 22, 7, 1, 0);
    Enemy* e4_4 = new Enemy("Bat B", "Harmless little bats.", 25, 4, 0, 0);
    Enemy* e4_5 = new Enemy("Goblin B", "Harmless little goblin.", 19, 7, 0, 0);
    Enemy* e4_6 = new Enemy("Slim B", "Harmless little slim.", 12, 12, 1, 0);

    Item* map = new Item("Map", "The ancient map depicts the layout of this place.", Item::ItemType::MAP);
    e4_1->SetHold(map);
    Item* p_4_1 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);


    s4->AddEnemy(e4_1);
    s4->AddEnemy(e4_2);
    s4->AddEnemy(e4_3);
    s4->AddEnemy(e4_4);
    s4->AddEnemy(e4_5);
    s4->AddEnemy(e4_6);

    s4->AddItem(p_4_1);


    //S5
    Enemy* e5_1 = new Enemy("Bat", "Quite strong bat.", 35, 10, 10, 0);
    Enemy* e5_2 = new Enemy("Goblin", "Quite strong goblin.", 41, 15, 4, 0);
    
    Item* key = new Item("Key", "A little key.", Item::ItemType::KEY);

    e5_1->SetHold(key);

    s5->AddEnemy(e5_1);
    s5->AddEnemy(e5_2);

    //S6

    //S7
    Enemy* boss = new Enemy("Evil Dragon", "A huge, terrifying, and powerful dragon.", 135, 25, 15, 0);
    s7->AddEnemy(boss);

    //S8
    Weapon* sword = new Weapon("Dragon Slayer", "A mitical sword.", 30, 0, 0, 15, Weapon::WeaponType::HAND_LEFT);
    s8->AddWeapon(sword);
    //S9
    Enemy* e9_1 = new Enemy("Bat", "Quite strong bat.", 35, 19, 10, 0);
    Enemy* e9_2 = new Enemy("Goblin", "Quite strong goblin.", 41, 19, 4, 0);
    Enemy* e9_3 = new Enemy("Slim", "Very strong slim.", 60, 21, 0, 0);

    Item* shield = new Weapon("Yggdrasil Shield", "A shield made of wood from a mythical tree.",0,30,0,5, Weapon::WeaponType::HAND_RIGHT);
    e9_2->SetHold(shield);
    Item* p_9_1 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);
    Item* p_9_2 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);
    Item* p_9_3 = new Item("Potion", "Potion, gain 20 HP when consumed.", Item::ItemType::Potion);

    s9->AddEnemy(e9_1);
    s9->AddEnemy(e9_2);
    s9->AddEnemy(e9_3);

    s9->AddItem(p_9_1);
    s9->AddItem(p_9_2);
    s9->AddItem(p_9_3);
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
        cout << "And you found a hidden path!" << endl;
    }

    lastScene = actualScene;
    actualScene = sceneid;

    scenes.at(sceneid)->BeCheked();
}

void World::GotoLastScene()
{
    if (lastScene == 0) {
        cout << "The is no way to go back" << endl;
    }
    else {
        int tmpLast = lastScene;
        actualScene = lastScene;
        lastScene = tmpLast;

        cout << "You just gone back." << endl << endl;
        scenes.at(actualScene)->BeCheked();
    }


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
