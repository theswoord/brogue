#pragma once


class Actor {
public :
    int x,y; // position on map
    int ch; // ascii code
    TCODColor col; // color
    const char *name; // the actor's name
    bool blocks; // can we walk on this actor?
    Attacker *attacker; // something that deals damage
    Destructible *destructible; // something that can be damaged
    Pickable *pickable; // something that can be picked and used
    Container *container; // something that can contain actors
    Ai *ai; // something self-updating
    // Actor(int x, int y, int ch, const TCODColor &col);
    void render() const;
    void update();
    Actor(int x, int y, int ch, const char *name, const TCODColor &col);
    ~Actor();
// bool moveOrAttack(int x,int y);
};