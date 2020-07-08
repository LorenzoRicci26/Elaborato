//
// Created by Lorenzo Ricci on 08/07/2020.
//

#ifndef ELABORATO_MAP_H
#define ELABORATO_MAP_H


#include "Observer.h"
#include "GameCharacter.h"
#include "Display.h"

class Map: public Observer,public Display {
public:
    Map(GameCharacter* _subject,int x,int y);

    ~Map()override;

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    void attach() override;

    void detach() override;

    void update() override;

    void show() override;


private:
    int width;
    int height;
    int x;
    int y;
    GameCharacter* subject;



};


#endif //ELABORATO_MAP_H
