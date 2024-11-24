#include <stdio.h>
#include "main.hpp"
#include <math.h>

Destructible::Destructible(float maxHp, float defense, const char *corpseName) : maxHp(maxHp),hp(maxHp),defense(defense),corpseName(corpseName) {
}


float Destructible::heal(float amount) {
    hp += amount;
    if ( hp > maxHp ) {
        amount -= hp-maxHp;
        hp=maxHp;
    }
    return amount;
}

float Destructible::takeDamage(Actor *owner, float damage, float mitigation) { // AC system 
    

    // TCODRandom *rng = TCODRandom::getInstance();
    // float new_def = round(rng->getFloat(0,defense));
    
    // float new_def =  random
    // printf("%f \n ",  new_def);
    
    damage -= mitigation;
    if ( damage > 0 ) {
        hp -= damage;
        if ( hp <= 0 ) {
            die(owner);
        }
    } else {
        damage=0;
    }
    return damage;
}

void Destructible::die(Actor *owner) {
    // transform the actor into a corpse!
    owner->ch='%';
    owner->col=TCODColor::darkRed;   
    owner->name=corpseName;
    owner->blocks=false;
    // make sure corpses are drawn before living actors
    engine.sendToBack(owner);
}

MonsterDestructible::MonsterDestructible(float maxHp, float defense, const char *corpseName) :
    Destructible(maxHp,defense,corpseName) {
}

PlayerDestructible::PlayerDestructible(float maxHp, float defense, const char *corpseName) :
    Destructible(maxHp,defense,corpseName) {
}



void MonsterDestructible::die(Actor *owner) {
    // transform it into a nasty corpse! it doesn't block, can't be
    // attacked and doesn't move
engine.gui->message(TCODColor::lightGrey,"%s is dead\n",owner->name);

    Destructible::die(owner);
    Map::addItem(owner->x,owner->y);

}

void PlayerDestructible::die(Actor *owner) {
engine.gui->message(TCODColor::red,"You died!\n");
    Destructible::die(owner);
    engine.gameStatus=Engine::DEFEAT;
}
