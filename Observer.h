//
// Created by Lorenzo Ricci on 08/07/2020.
//

#ifndef ELABORATO_OBSERVER_H
#define ELABORATO_OBSERVER_H


class Observer {
public:
    virtual ~Observer()= default;

    virtual void attach()=0;
    virtual void detach()=0;
    virtual void update()=0;
};


#endif //ELABORATO_OBSERVER_H
