#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

#include "World.h"
#include "Scene.h"
#include "Creature.h"
#include "Enemy.h"
#include "Hero.h"
#include "Weapon.h"
#include "InputProcessor.h"

using namespace std;


int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << "You feel your body is continuously falling down, and you sense your memories slowly fading away.." << endl;
    cout << "When you wake up, you find yourself sleeping next to a [big bell]." << endl;
    cout << "You don't remember anything else, only that you're a [hero]." << endl;
    cout << "You don't have time to think it through. You notice several monsters in the distance." << endl;
    cout << "You need to do something." << endl << endl;

    cout << "After you hide and observe, you find out that your targets are a [bat] and a [slime]." << endl << endl;

    cout << "You can initiate an {attack} against them." << endl;
    cout << "You can also check your {inventory} to see what you have." << endl;
    cout << "Or gather more information." << endl;
    cout << "For example, {check here} to find something you can {pick} or {use}." << endl;
    cout << "Or {check hero}, to see your current stat. Or {check them-name} to see their information." << endl;
    cout << "Or directly {goto} another way to run away from this monsters." << endl << endl;
    cout << "Time to decide." << endl;

    World* w = new World();
    while (true) {
        cout << endl;
        //cout << "Available actions: {Check}{Goto}{Attack}{Inventory}{Use}{Pick}{Drop}{Help}" << endl;
        cout << "---------------------------- Your next action ----------------------------" << endl;
        cout << "> ";

        //Set gree to user input

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        string input;
        getline(std::cin, input);

        //Restore color
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl;
        InputProcessor::ProcessInput(input, w);
    }

    return 0;
}