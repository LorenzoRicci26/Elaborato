//
// Created by Lorenzo Ricci on 08/07/2020.
//

#ifndef ELABORATO_GAMECHARACTER_H
#define ELABORATO_GAMECHARACTER_H

#include "memory"
#include "list"
#include "Subject.h"

using namespace std;

class GameCharacter: public Subject {
public:
    explicit GameCharacter(int x=0,int y=0);

    ~GameCharacter()override;

    void move(int x,int y);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;

    void notify() override;

private:
    list<Observer*> observers;
    int posX;
    int posY;
};


#endif //ELABORATO_GAMECHARACTER_H
