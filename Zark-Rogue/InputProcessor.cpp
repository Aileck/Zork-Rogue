#include "InputProcessor.h"
#include <cctype>

bool InputProcessor::ProcessInput(string input, World* world)
{
    {
        //If you are noticed by monsters
        Scene* thisScene = world->GetCurrentScene();
        Hero* thisHero = world->GetHero();
        if (thisScene->GetNoticed()) {
            for (int i = 0; i < thisScene->GetEnemy().size(); i++) {
                cout << "Before you could do anything, you were attacked." << endl;
                int damage = thisScene->GetEnemy().at(i)->GetCurrentAttack() - thisHero->GetCurrentDefense();

                if (damage <= 0) {
                    cout << thisScene->GetEnemy().at(i)->GetName() + " deals you 1 damage (NOW: " + to_string(thisHero->GetCurrentHP()) + " )." << endl;
                }          
                else {
                    cout << thisScene->GetEnemy().at(i)->GetName() + " deals you " + to_string(damage) + " damage(NOW: " + to_string(thisHero->GetCurrentHP()) + ")." << endl << endl;
                }
                thisHero->BeAttacked(damage);
            }
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
                if (destiny > 0) {
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
                break;
            case InputProcessor::NOTREGISTERED:
                cout << "This is not a valid command." << endl;
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
        cout << to_string(damage) << endl;
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

        if (!w->GetCurrentScene()->GetNoticed()) {
            cout << "Your attack has attracted the attention of monsters." << endl;
            w->GetCurrentScene()->NoticedYou();
        }
        //Attack all

        //searchedEnemy->BeAttacked();
    }

}

void InputProcessor::InventoryAciton(World* w , string target)
{
    if (target.size() == 0) {
        string out = w->GetInventory()->ShowAll();
        cout << out << endl;
    }
    else {
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
                cout << "You can yse'inventory' command to check your inventory." << endl;
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
            if (searchedItem->GetType() == Item::ItemType::KEY) {
                //Split even more target
                cout << "Use case key." << endl;
            }
        }

        stringstream ss(target);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string first = words[0];
        string rest;
        for (int i = 1; i < words.size(); ++i) {
            target += words[i];
            if (i != words.size() - 1) {
                target += " ";
            }
        }

        if (first == "key") {
            cout << "Looks for a key?" << endl;

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
            cout << "If it is in your inventory, use the command 'inventory " + target + "'." << endl;
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
        }
        if (searchedItem->GetType() == Item::ItemType::KEY) {
            cout << "Perhaps you should pick up this key and insert it in the direction of the door you want to open." << endl;
        }
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
}
