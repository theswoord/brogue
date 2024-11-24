#include <stdio.h>
#include "main.hpp"

Attacker::Attacker(float power) : power(power)
{
}

void Attacker::attack(Actor *owner, Actor *target)
{

    if (target->destructible && !target->destructible->isDead())
    {
        float rnddef = round(rnadomfloat(0, target->destructible->defense));
        if (power - rnddef > 0)
        {
            engine.gui->message(owner == engine.player ? TCODColor::red : TCODColor::lightGrey,
                                "%s attacks %s for %g hit points.\n", owner->name, target->name,
                                power - rnddef);
        }
        else
        {
            engine.gui->message(TCODColor::lightGrey,
                                "%s attacks %s but it has no effect!\n", owner->name, target->name);
        }
        target->destructible->takeDamage(target, power, rnddef); // logic to be fixed
    }
    else
    {
        engine.gui->message(TCODColor::lightGrey,"%s attacks %s in vain.\n", owner->name, target->name);
    }
}