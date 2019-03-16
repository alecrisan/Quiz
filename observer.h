#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

using namespace std;

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {}

};

class Observable
{
private:
    vector<Observer*> observers;

public:
    void addObserver(Observer* o)
    {
        observers.push_back(o);
    }

    void removeObserver(Observer* o)
    {
        observers.erase(remove(observers.begin(), observers.end(), o));
    }

    void notify()
    {
        for (auto o: observers)
            o->update();
    }

    virtual ~Observable() {}

};

#endif // OBSERVER_H
