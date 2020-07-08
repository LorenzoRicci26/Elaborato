//
// Created by Lorenzo Ricci on 08/07/2020.
//

#ifndef ELABORATO_SUBJECT_H
#define ELABORATO_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual ~Subject()=0;

    virtual void subscribe(Observer* o)=0;
    virtual void unsubscribe(Observer* o)=0;
    virtual void notify()=0;
};


#endif //ELABORATO_SUBJECT_H
