#include <iostream>
#include "Creature.h"
#include "Enemie.h"
#include "Hero.h"

using namespace std;


int main() {
    Creature* c1 = new Enemie();
    Creature* c2 = new Enemie("Angel",200,9,9,9);

    c1->BeCheked();
    c2->BeCheked();
    return 0;
}