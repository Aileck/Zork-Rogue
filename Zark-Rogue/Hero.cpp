#include "Hero.h"

Hero::Hero():Creature("Hero", "The only thing you remember is that you are a hero.", 50,3,0,0) {
    Weapon* nullHandLeft = new Weapon(Weapon::HAND_LEFT);
    Weapon* nullHandRight = new Weapon(Weapon::HAND_RIGHT);
    Weapon* nullFoot = new Weapon(Weapon::FOOT);

    this->handLeft = nullHandLeft;
    this->handRight = nullHandRight;
    this->foot = nullFoot;

    attackWeapon = 0;
    defenseWeapon = 0;
    speedWeapon = 0;

    criticalRate = 10;
}

void Hero::BeCheked() {
    string attackByWeapon = (this->attackWeapon <= 0) ? "":" + (" + std::to_string(this->attackWeapon) + ")";
    string defenseByWeapon = (this->defenseWeapon <= 0) ? "" : " + (" + std::to_string(this->defenseWeapon) + ")";

    cout << "=== " << Checkeable::GetName() << " ===" << endl;
    cout << "=== " << this->currentHP << " ===" << endl;
    cout << "* " << "Attack: " << this->attack  << attackByWeapon << endl; 
    cout << "* " << "Defense: " << this->defense << defenseByWeapon << endl;
    cout << endl;
    cout << "Your equipments "<< endl;
    cout << "* " << "Sword: " << handLeft->GetName() << " attack +" << handLeft->GetAttack() << endl;
    cout << "* " << "Shield: " << handRight -> GetName() << " defense +" << handRight ->GetDefense() << endl;
    cout << "* " << "Foot: " << foot -> GetName()  << endl;

    cout << "" << endl;
}

string Hero::EquipWeapon(Weapon* newWeapon)
{
    newWeapon->BeEquiped();
    Weapon::WeaponType newWeaponType = newWeapon->GetType();
    string out = "Then you equipped " + newWeapon->GetName() + ".";
    switch (newWeaponType)
    {
    case Weapon::HAND_LEFT:
        if (this->handLeft->GetName(true) == "not equipped") {
            out += "\nGreat! You happen to need equip a sword, and then you won't be afraid of the monster in front of you.";
        }
        else {

            out += "\nAnd put " + this->handLeft->GetName()+ " in your inventory that was in your left hand.";
        }
        this->handLeft = newWeapon;
        ChangePowerByWeapon(newWeapon);
        break;
    case Weapon::HAND_RIGHT:
        if (this->handRight->GetName(true) == "not equipped") {
            out += "\nGreat! You happen to need equip a shield, that way it's harder for monsters to hurt you.";

        }
        else {
            out += "\nAnd put " + this->handRight->GetName() + " in your inventory that was in your right hand.";
        }
        //out += "\nAnd put " + this->handLeft->GetName() + " in your inventory that was in your left hand.";
        this->handRight = newWeapon;
        ChangePowerByWeapon(newWeapon);
        break;
    case Weapon::FOOT:
        if (this->foot->GetName(true) == "not equipped") {
        }
        else {
            out += "\nAnd put " + this->handLeft->GetName() + " in your inventory that was in your foot.";
        }
        this->foot = newWeapon;
        ChangePowerByWeapon(newWeapon);
        break;
    default:
        break;
    }

    return out;
}

void Hero::UnEquipWeapon(Weapon* newWeapon)
{
    this->attackWeapon -= newWeapon->GetAttack();
    this->defenseWeapon -= newWeapon->GetDefense();
    this->speedWeapon -= newWeapon->GetSpeed();
    this->criticalRate -= newWeapon->GetCritical();

}

string Hero::UseItem(Item* item)
{
    string out = "You tried to ";
    string map = "\n";

    switch (item->GetType())
    {
    case Item::ItemType::Potion:
        out += "drink the *potion*";
        //Could contruct another class or struct, to simplify project, i decided to add hp directly
        this->currentHP += 20;
        out += "\nYou feel more energetic. ";
        
        if (item->GetLocation() == Item::ItemLocation::FLOOR) {
            out += "\n\nAnd at the moment you finished drinking the potion, the empty bottle disappeared.";
        }
        if (item->GetLocation() == Item::ItemLocation::INVENTORY) {
            out += "\n\Then you tied the empty bottle to your belt.";
        }
            
        item->BeConsumed();
        break;
    case Item::ItemType::BOTTLE:
        out += "fill the empty *bottle*, but there is nothing to put it in.";
        break;
    case Item::ItemType::MAP:
        //if(item.get)
        out += "unfold the *map*.";


            map += "     [2] [H8]\n";
            map += "     | |/    \n";
            map += "[L6]=[1]=[3]=[4]  \n";
            map += "| |  | |  \n";
            map += "[L9] [5]    \n";
            map += "     | |   \n";
            map += "     [E7]  \n";
        out += map;
        out += "\nMap symbol:";
        out += "\n\tNumber: Room ID";
        out += "\n\tH: Hidden Room";
        out += "\n\tL: Locked Room";
        out += "\n\tE: Exit Room";
        out += "\n\033[3mTips:";
        out += "\nYou can use the 'goto hidden' command to go to the hidden room.";
        out += "\nYou can use the 'inventory key (door-direction (n|w|s|e))' command to go open locked room (you must have a key).\033[0m";
        item->BeUsed();
        if (item->GetUseTime() >= 3) {
            out += "\nThe map started to wrinkle after being used too many times.";
            item->AddDefinition("The map started to wrinkle after being used too many times.");
        }
        if (item->GetUseTime() >= 10) {
            out += "\nThe map started to deteriorate after being used too many times.";
            item->AddDefinition("Upon closer inspection, signs of damage were already starting to show");
        }
        break;
    case Item::ItemType::KEY:
        out += "then you found it.";
        break;
    case Item::ItemType::WEAPON:
        out += "wear a *weapon*";
        break;
    default:
        break;
    }

    return out;
}

int Hero::GetCurrentAttack()
{
    return this->attack + attackWeapon;
}

int Hero::GetCurrentDefense()
{
    return this->defense + this->defenseWeapon;
}

int Hero::GetCurrentSpeed()
{
    return this->speed + this->speedWeapon;
}

int Hero::GetCriticalRate()
{

    return this->criticalRate;
}

void Hero::CheckIfDead()
{
    if (currentHP <= 0) {
        currentHP = 50; 
        cout << endl;
        cout << this->GetName() << " is dead." << endl;
        cout << "GAME OVER" << endl;
        cout << "This sentence flashed through your mind..." << endl;
        cout << "You snapped out of it and realized that you hadn't died, and you weren't even injured. " << endl;
        cout << "Not having time to think about whether it was all a daydream, you had to keep fighting." << endl << endl;
    }
}

void Hero::LeveUp()
{
    int up1 = rand() % 3;
    int up2 = rand() % 3;

    int hpUp = 0;
    int attackUp = 0;
    int defenseUp = 0;

    if (up1 == 0) {
        hpUp += 10;
    }
    if (up1 == 1) {
        attackUp++;
    }
    if (up1 == 2) {
        defenseUp++;
    }

    if (up2 == 0) {
        hpUp += 10;
    }
    if (up2 == 1) {
        attackUp++;
    }
    if (up2 == 2) {
        defenseUp++;
    }

    cout << "===LEVEL UP===" << endl;

    cout << "* Helth point:" << to_string(currentHP) << " + " << to_string(hpUp) << endl;
    cout << "* Attack     :"<< to_string(attack) << " + " << to_string(attackUp) << endl;
    cout << "* Defense    :" <<to_string(defense) << " + " << to_string(defenseUp) << endl;

    currentHP += hpUp;
    attack += attackUp;
    defense += defenseUp;
 
}


void Hero::ChangePowerByWeapon(Weapon* newWeapon) {
    this->attackWeapon += newWeapon->GetAttack();
    this->defenseWeapon += newWeapon->GetDefense();
    this->speedWeapon += newWeapon->GetSpeed();
    this->criticalRate += newWeapon->GetCritical();
}
