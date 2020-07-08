#include <iostream>
#include "GameCharacter.h"
#include "Map.h"

int main() {
    auto hero = new GameCharacter;
    Map bitmap(hero,1080,640);

    hero->move(1,1);
}