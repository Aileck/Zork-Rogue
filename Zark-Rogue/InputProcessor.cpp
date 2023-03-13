#include "InputProcessor.h"


bool InputProcessor::ProcessInput(string input, World* world)
{
    {
        //If you are noticed by monsters
        Scene* thisScene = world->GetCurrentScene();
        Hero* thisHero = world->GetHero();
        if (thisScene->GetNoticed()) {
            //Change input color
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

            for (int i = 0; i < thisScene->GetEnemy().size(); i++) {
                if (!thisScene->GetEnemy().at(i)->GetIsDead()) {
                    cout << "Before you could do anything, you were attacked by a monster!" << endl;
                    int damage = thisScene->GetEnemy().at(i)->GetCurrentAttack() - thisHero->GetCurrentDefense();

                    //Minimum damage
                    if (damage <= 0) {
                        damage = 1;
                    }

                    //Avoid show negative number
                    int currentHealth = (thisHero->GetCurrentHP() - damage);
 
                    cout << thisScene->GetEnemy().at(i)->GetName() + " deals you " + to_string(damage) + " damage (YOUR CURRENT HP: " + to_string(currentHealth) + ")." << endl << endl;

                    thisHero->BeAttacked(damage);
                
                }
  
            }
            //Restore color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }


        //Input to lowercase
        string lower_input;
        for (char c : input) {
            lower_input += tolower(c);
        }

        //Split user token to two parts, action + target
        stringstream ss(lower_input);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string action = words[0];
        string target;
        for (int i = 1; i < words.size(); ++i) {
            target += words[i];
            if (i != words.size() - 1) {
                target += " ";
            }
        }
        
        //Default value to deal GOTO action
        int destiny = 0;

        InputType actiontype = InputToAction(action);

        switch (actiontype)
        {
            case InputProcessor::CHECK:
                CheckAction(world, target);
                break;
            case InputProcessor::GOTO:
                destiny = GotoAction(world->GetCurrentScene(), target);
                if (destiny == -2) {
                    world->GotoLastScene();
                }
                else if (destiny > 0) {
                    world->GotoScene(destiny);
                }
                break;
            case InputProcessor::ATTACK:
                AttackAction(world, target);
                break;
            case InputProcessor::INVENTORY:
                InventoryAciton(world, target);
                break;
            case InputProcessor::USE:
                UseAction(world, target);
                break;
            case InputProcessor::PICK:
                PickAciton(world,target);
                break;
            case InputProcessor::DROP:
                DropAciton(world, target);
                break;
            case InputProcessor::HELP:
                HelpAction();
                break;
            case InputProcessor::NOTREGISTERED:
                cout << action +" is not a available action." << endl;
                cout << "Perhaps you can try typing 'help' to see if there are any available commands or options." << endl;
                break;
            default:
                break;
        }

        return true;
    }
}

InputProcessor::InputType InputProcessor::InputToAction(string s)
{
    if (s == "check" || s == "c") {
        return CHECK;
    }
    if (s == "goto" || s == "go") {
        return GOTO;
    }
    if (s == "attack" || s == "a") {
        return ATTACK;
    }
    if (s == "talk" || s == "c") {
        return CHECK;
    }
    if (s == "inventory" || s == "i") {
        return INVENTORY;
    }
    if (s == "use" || s == "u") {
        return USE;
    }
    if (s == "pick" || s == "p") {
        return PICK;
    }
    if (s == "drop" || s == "d") {
        return DROP;
    }
    if (s == "help" || s == "h") {
        return HELP;
    }
    return NOTREGISTERED;
}

void InputProcessor::CheckAction(World* w, string target)
{
    if (target.length() == 0) {
        cout << "What do you want to check? " << endl;
        cout << "You can check anything enclosed in square brackets[]" << endl;
        cout << "Alternatively, you can check [hero] or [me] check your stats, or check [here] to observe the scene." << endl;
        return;
    }
    if (target == "me" || target == "hero") {
        w->GetHero()->BeCheked();
        return;
    }
    if (target == "here" ) {
        w->GetCurrentScene()->BeCheked();
        return;
    }

    Checkeable* c = w->GetCurrentScene()->IfContains(target);
    if (c->GetName() == "Nothing") {
        cout << "There's no *" + target + "* here that you're looking for." << endl;
    }
    
}
int InputProcessor::GotoAction(Scene* s, string target) {
    string hint = "";
    if (target == "back") {
        return -2;
    }
    if (target == "n") {
        hint = "(north)";
    }
    if (target == "w") {
        hint = "(west)";
    }
    if (target == "s") {
        hint = "(south)";
    }
    if (target == "e") {
        hint = "(east)";
    }

    if (target.length() == 0) {
        cout << "Where would you like to go?" << endl;
        cout << "\033[3m" <<  "Tips: You can use 'goto direction' command, direction can be north, west, south or east." << "\033[0m" << endl;
        cout << endl;
        return 0;
    }

    int targetScene = s->CheckDestination(target);
    if (targetScene == -1) {
        cout << "The *" + target + "* direction does not exist.You can try going east, south, west, or north." << endl;
    }
    else {
        if (target == "hidden")
            cout << "You start to look for a *hidden* passage. " << endl;

        else if (targetScene == 0) {
            cout << "It appears that there is no road in *" + target + "* " + hint + " you are trying to go. Perhaps you could try a different direction?" << endl;
        }

        else if (target != "hidden")
            cout << "You are trying to move towards *" + target + "* " + hint + "." << endl;

    }
    cout << endl;

    return targetScene;
}

void InputProcessor::AttackAction(World* w, string target)
{
    Scene* s = w->GetCurrentScene();
    Hero* h = w->GetHero();
    //No enemy to attack
    if (s->GetEnemy().size() == 0) {
        cout << "You feel scared of the wicked thoughts in your mind. There is clearly no one here, why do you feel the urge to attack?" << endl;
        return;
    }

    //No target
    if (target.length() == 0) {
        cout << "You have made up your mind to attack, but you don't know who to attack." << endl;
        return;
    }
    Enemy* searchedEnemy = new Enemy();
    cout << "You aimed at *" + target + "* and attacked it." << endl;

    searchedEnemy = s->IfContainsEnemy(target);
    if (searchedEnemy->GetName(true) == "no enemy") {
        cout << "But you realize that what you just saw was an illusion, there is no *" + target + "* here." << endl;
    }
    else if(searchedEnemy->GetIsDead()) {
        cout << "But *" + target + "* is alredy dead." << endl;
    }
    else {
        //If critical attack
        int randNum = rand() % 100;

        int damage = 0;

        if (randNum < h->GetCriticalRate()) {
            // Critical attack!!
            damage = (h->GetCurrentAttack()*2) - searchedEnemy->GetCurrentDefense();
            searchedEnemy->BeAttacked(damage);
            cout << "You seem to feel that even your soul is attacking with you, causing double damage." << endl;
        }
        else {
            damage = h->GetCurrentAttack() - searchedEnemy->GetCurrentDefense();
        }
        if (damage <= 3) {
            cout << "Your attacks seem to have not very effective on your opponent." << endl;
        }
        else if (damage <= 10) {
            cout << "Your attack caused some damage." << endl;
        }
        else if (damage <= 20) {
            cout << "You pushed your opponent back a few steps." << endl;
        }
        else if (damage <= 30) {
            cout << "Your attack seems to have caused a lot of damage" << endl;
        }
        else {
            cout << "Your attack made the earth tremble along with it." << endl;
        }

        searchedEnemy->BeAttacked(damage);

        //When win - If drops something + level up
        if (searchedEnemy->GetIsDead() ) {
            if(searchedEnemy->DropHold()->GetType() != Item::ItemType::NO_ITEM){
                cout << searchedEnemy->GetName() + " dropped "+ searchedEnemy->DropHold()->GetName() +" after you defeated it." << endl;
                w->GetCurrentScene()->AddItem(searchedEnemy->DropHold());
            }
            h->LeveUp();

            if (searchedEnemy->GetName(true) == "evil dragon") {
                EndGame();
            }

        }
        

        if (!w->GetCurrentScene()->GetNoticed()) {
            cout << "Your attack has attracted the attention of monsters." << endl;
            w->GetCurrentScene()->NoticedYou();
        }
        
    }

}

void InputProcessor::InventoryAciton(World* w , string target)
{
    if (target.size() == 0) {
        string out = w->GetInventory()->ShowAll();
        cout << out << endl;
    }
    else {
        //Split even more target
        stringstream ss(target);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string first = words[0];
        string rest;
        for (int i = 1; i < words.size(); ++i) {
            rest += words[i];
            if (i != words.size() - 1) {
                rest += " ";
            }
        }

        //Spetial case
        if (first == "key") {
            cout << "Your start to search and use *key* in your belt." << endl;
            Item* searchedKey = w->GetInventory()->IfContainsItem("key");
            if (searchedKey->GetType() == Item::ItemType::KEY) {
                if (rest.length() == 0) {
                    cout << "You are holding a key in your hand and you don't know which door to insert it into." << endl;
                    cout << "\033[3mTips: To use the key, use the command 'inventory key door-direction', door-direction can be north, west, south or east.\033[0m" << endl;
                }
                else {
                    if (searchedKey->GetUseTime() >= 1) {
                        cout << "You were not sure whether the key could be used to open another door again..." << endl;
                    }
                    string hint = "";
                    if (rest == "n") {
                        hint = "(north)";
                    }
                    if (rest == "w") {
                        hint = "(west)";
                    }
                    if (rest == "s") {
                        hint = "(south)";
                    }
                    if (rest == "e") {
                        hint = "(east)";
                    }
                    bool unlocked = w->GetCurrentScene()->UnlockDestination(rest);

                    if (unlocked) {
                        searchedKey->BeUsed();
                        cout << "And you succefuly oppened the *" + rest + "*" + hint + " direction door." << endl;
                        if (searchedKey->GetUseTime() == 1) {
                            cout << "You looked down at the key in your hand and realized that it had not disappeared." << endl;
                            cout << "You were even surprised why you thought it would disappear." << endl;

                            searchedKey->AddDefinition("It neither disappeared nor got damaged even after its use, what a miracle.");
                        }
                        if (searchedKey->GetUseTime() == 2) {
                            cout << "You took another glance and confirmed that the key had not disappeared." << endl;
                        }

                    }
                    else {
                        cout << "But *" + rest + "*" + hint + " direction does not have any locked door." << endl;
                    }
                }
                return;
            }
        }

            cout << "Your start to search and use *" + target + "* in your belt." << endl;
        Item* searchedItem = new Item();
        Weapon* searchedWeapon = new Weapon();
        //Serarch order Inventory Item -> Inventory Weapon

        //Search scene item
        searchedItem = w->GetInventory()->IfContainsItem(target);

        if (searchedItem->GetType() == Item::ItemType::NO_ITEM) {
            //Search inven weapon
            searchedWeapon = w->GetInventory()->IfContainsWeapon(target);
            if (searchedWeapon->GetType() == Weapon::WeaponType::NO_WEAPON) {
                //Case: cannot find anything
                cout << "But you cannot find the *" + target + "* in your inventory." << endl;
                cout << "\033[3mTips: You can use'inventory' command to check your inventory.\033[0m" << endl;
            }
            else {
                //Case: Find a weapon
                if (searchedWeapon->GetType() == Weapon::WeaponType::EQUIPPED_ERROR) {
                    cout << "But you have already weared it up." << endl;
                }
                else {
                    string message = w->GetHero()->EquipWeapon(searchedWeapon);
                    cout << message << endl;
                }

            }
        }
        else {
            //Case: Find a item
            string out = w->GetHero()->UseItem(searchedItem);
            cout << out << endl;
            if (searchedItem->GetType() == Item::ItemType::MAP) {
                cout << "Your current location: Roon number " + to_string(w->GetCurrentScene()->GetSceneID()) << endl;
            }
            }
        }

}



void InputProcessor::UseAction(World * w, string target)
{
    Item* searchedItem = new Item();
    Weapon* searchedWeapon = new Weapon();


    //Serarch order Scene Item -> Scene Weapon n

    //Search scene item
    searchedItem = w->GetCurrentScene()->IfContainsItem(target);

    if (searchedItem->GetType() == Item::ItemType::NO_ITEM) {
        //Search scene weapon
        searchedWeapon = w->GetCurrentScene()->IfContainsWeapon(target);
        if (searchedWeapon->GetType() == Weapon::WeaponType::NO_WEAPON) {
            //Case: cannot find anything
            cout << "Cannot find the *" + target + "* you want to use." << endl;
            cout << "\033[3mTips: If it is in your inventory, use the command 'inventory " + target + "'.\033[0m" << endl;
        }
        else {
            //Case: Find a weapon
            w->GetInventory()->AddWeapon(searchedWeapon);
            string message = w->GetHero()->EquipWeapon(searchedWeapon);
            
            cout << "You picked up *"+ target +"* on the ground." << endl;
            cout << message << endl;
        }
    }
    else {
        //Case: Find a item
        string out = w->GetHero()->UseItem(searchedItem);
        cout << out << endl;
        if (searchedItem->GetType() == Item::ItemType::MAP) {
            cout << "Your current location: Roon number " + to_string(w->GetCurrentScene()->GetSceneID()) << endl;
            w->GetInventory()->AddItem(searchedItem);

            cout << "You picked up *" + target + "* on the ground." << endl;

        }
        if (searchedItem->GetType() == Item::ItemType::KEY) {
            cout << "Perhaps you should pick up this key and insert it into the door you want to open." << endl;
            w->GetInventory()->AddItem(searchedItem);
        }
    }

    if (!w->GetCurrentScene()->GetNoticed()) {
        cout << "Your action has attracted the attention of monsters." << endl;
        w->GetCurrentScene()->NoticedYou();
    }

     //Search inventory
}

void InputProcessor::PickAciton(World* w, string target)
{
    Item* searchedItem = new Item();
    Weapon* searchedWeapon = new Weapon();

    if (target == "money") {
        cout << "I understand that many people would like to pick up money in the dungeon." << endl;
        cout << "but unfortunately, there is no money to be found here." << endl;
        cout << "Moreover, there are no shops to be found here either." << endl;

        return;
    }
    else if (target.length() == 0) {
        cout << "You casually glanced at the ground, but didn't know what you wanted to pick up." << endl;
        return;
    }
    cout << "You are trying to search *" + target + "* on the ground." << endl;
    //Search scene item
    searchedItem = w->GetCurrentScene()->IfContainsItem(target);

    if (searchedItem->GetType() == Item::ItemType::NO_ITEM) {
        //Search scene weapon
        searchedWeapon = w->GetCurrentScene()->IfContainsWeapon(target);
        if (searchedWeapon->GetType() == Weapon::WeaponType::NO_WEAPON) {
            //Case: cannot find anything
            cout << "But cannot find the *" + target + "* you want to pick!" << endl;
        }
        else {
            //Case: Find a weapon
            w->GetInventory()->AddWeapon(searchedWeapon);
            cout << "You picked up *" + target + "* on the ground." << endl;
        }
    }
    else {
        //Case: Find a item
        w->GetInventory()->AddItem(searchedItem);
        cout << "You picked up *" + target + "* on the ground." << endl;
    }

    if (!w->GetCurrentScene()->GetNoticed()) {
        cout << "Your action has attracted the attention of monsters." << endl;
        w->GetCurrentScene()->NoticedYou();
    }
}

void InputProcessor::DropAciton(World* w, string target)
{
    Item* searchedItem = new Item();
    Weapon* searchedWeapon = new Weapon();


    if (target == "money") {
        cout << "You don't have any money to throw away." << endl;
        return;
    }
    else if (target.length() == 0) {
        cout << "You want to throw something from your belt, but can't make a decision." << endl;
        return;
    }

    //Search scene item
    searchedItem = w->GetInventory()->IfContainsItem(target,w->GetCurrentScene());

    if (searchedItem->GetType() == Item::ItemType::NO_ITEM) {
        //Search scene weapon
        searchedWeapon = w->GetInventory()->IfContainsWeapon(target, w->GetCurrentScene());
        if (searchedWeapon->GetType() == Weapon::WeaponType::NO_WEAPON) {
            //Case: cannot find anything
            cout << "Even if you want to throw *" + target + "*, you don't have it on you inventary." << endl;
        }
        else if (searchedWeapon->GetType() == Weapon::WeaponType::EQUIPPED_ERROR) {
            //Case: is equipped
            cout << "You cannot drop a weapon that is already equipped." << endl;
        }
        else {
            //Case: Find a weapon
            cout << "You dropped *"+ target +"* on the ground." << endl;
        }
    }
    else {
        //Case: Find a item
        w->GetInventory()->DropItem(searchedItem, w->GetCurrentScene());
        cout << "You dropped " + target + " on the ground." << endl;
    }

    if (!w->GetCurrentScene()->GetNoticed()) {
        cout << "Your action has attracted the attention of monsters." << endl;
        w->GetCurrentScene()->NoticedYou();
    }
}

void InputProcessor::HelpAction()
{
    cout << "{C}heck: \n\tCheck all the text enclosed in [] to get their details.\n\tSpecial usage 1: 'check me' to check yourself.\n\tSpecial usage 2: 'check here' to check the current scene." << endl;
    cout << "{Go}to: \n\tUse {n}orth, {s}outh, {e}ast, or {w}est to navigate to a discovered location. Will fail if there's no path or if it's locked.\n\tYou can also use this command to escape during a battle.\n\tSpecial usage 1: 'goto back' to go back to the previous location." << endl;
    cout << "{A}ttack:\n\t Choose the name of an enemy and attack it." << endl;
    cout << "{I}nventory: \n\tShows all the items in your belt.\n\tType 'inventory + item name' to use or equip an item,\n\tor 'inventory + key + north/south/east/west' to unlock a door in that direction." << endl;
    cout << "{U}se: \n\tUse an item in the current scene. Type 'use + item name'." << endl;
    cout << "{P}ick: \n\tPick up an item in the current scene. Type 'pick + item name'." << endl;
    cout << "{D}rop:\n\tDrop an item from your inventory into the current scene. Type 'drop + item name'." << endl;

    cout << "Action name enclosed in {} means that can type text inside {} for shortcut." << endl;
}

void InputProcessor::EndGame()
{
    cout << "After defeating the dragon, you begin to walk towards the stairs.." << endl;
    cout << "And after you step down the stairs, you feel your whole body is falling down." << endl;
    cout << "Yes, the ladder disappeared." << endl;
    cout << "You feel your body is continuously falling down, and you sense your memories slowly fading away." << endl;
    cout << "When you wake up, you find yourself sleeping next to a large clock." << endl;
    cout << "You don't remember anything else, only that you're a hero." << endl;
    cout << "You don't have time to think it through. You notice several monsters in the distance." << endl;
    cout << "You need to do something." << endl;

    cout << "__THE END__" << endl;
    cout << "__Thanks for play__" << endl;

    exit(0);

}
