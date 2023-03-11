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
    World* w = new World();
    while (true) {
        cout << endl;
        //cout << "Available actions: {Check}{Goto}{Attack}{Talk}{Inventory}{Use}{Pick}{Help}" << endl;
        cout << "---------------------------- Your next action ----------------------------" << endl;
        cout << "> ";

        //Set gree to user input
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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