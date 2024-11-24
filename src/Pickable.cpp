#include "main.hpp"

bool Pickable::pick(Actor *owner, Actor *wearer) {
    if ( wearer->container && wearer->container->add(owner) ) {
        engine.actors.remove(owner);
        return true;
    }
    return false;
}

bool Pickable::use(Actor *owner, Actor *wearer) {
    if ( wearer->container ) {
        wearer->container->remove(owner);
        delete owner;
        return true;
    }
    return false;
}

Healer::Healer(float amount) : amount(amount) {
}

bool Healer::use(Actor *owner, Actor *wearer) {
    if ( wearer->destructible ) {
        float amountHealed = wearer->destructible->heal(amount);
        if ( amountHealed > 0 ) {
            return Pickable::use(owner,wearer);
        }
    }
    return false;
}

void Pickable::drop(Actor *owner, Actor *wearer) {
    if ( wearer->container ) {
        wearer->container->remove(owner);
        engine.actors.push(owner);
        owner->x=wearer->x;
        owner->y=wearer->y;
        engine.gui->message(TCODColor::lightGrey,"%s drops a %s.",
            wearer->name,owner->name);
    }
}

