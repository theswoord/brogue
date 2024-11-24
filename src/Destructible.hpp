#pragma once


// class Map;

class Destructible {
public :
    float maxHp; // maximum health points
    float hp; // current health points
    float defense; // hit points deflected
    const char *corpseName; // the actor's name once dead/destroyed
    Destructible(float maxHp, float defense, const char *corpseName);
    virtual ~Destructible() {};
inline bool isDead() { return hp <= 0; }
float takeDamage(Actor *owner, float damage, float mitigation);
float heal(float amount);
virtual void die(Actor *owner);
};

class MonsterDestructible : public Destructible {
public :
    MonsterDestructible(float maxHp, float defense, const char *corpseName);
    void die(Actor *owner);
};

class PlayerDestructible : public Destructible {
public :
    PlayerDestructible(float maxHp, float defense, const char *corpseName);
    void die(Actor *owner);
};