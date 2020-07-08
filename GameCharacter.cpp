//
// Created by Lorenzo Ricci on 08/07/2020.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(int x, int y):posX(x),posY(y) {}

void GameCharacter::move(int x, int y) {
    posX+=x;
    posY+=y;
    if(x<0)
        posX=0;
    if(y<0)
        posY=0;
    notify();
}

void GameCharacter::subscribe(Observer* o) {

    observers.push_back(o);

}

void GameCharacter::unsubscribe(Observer* o) {

    observers.remove(o);

}

void GameCharacter::notify() {

    for(auto observer:observers)
        observer->update();

}

int GameCharacter::getPosX() const {
    return posX;
}

void GameCharacter::setPosX(int posX) {
    GameCharacter::posX = posX;
    notify();
}

int GameCharacter::getPosY() const {
    return posY;
}

void GameCharacter::setPosY(int posY) {
    GameCharacter::posY = posY;
    notify();
}

GameCharacter::~GameCharacter()=default;
