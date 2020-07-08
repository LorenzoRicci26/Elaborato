//
// Created by Lorenzo Ricci on 08/07/2020.
//
#include <iostream>
#include "memory"
#include "Map.h"

Map::Map(GameCharacter* _subject,int x, int y):subject(_subject),width(x),height(y) {
    attach();
}

Map::~Map(){
    detach();
}

int Map::getWidth() const {
    return width;
}

void Map::setWidth(int width) {
    Map::width = width;
}

int Map::getHeight() const {
    return height;
}

void Map::setHeight(int height) {
    Map::height = height;
}

void Map::attach() {

    subject->subscribe(this);

}

void Map::detach() {

    subject->unsubscribe(this);

}

void Map::update() {
    this->x=subject->getPosX();
    this->y=subject->getPosY();
    show();

}

void Map::show() {

    std::cout<<"Sto aggiornando..."<<std::endl;

}






