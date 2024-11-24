#pragma once

class Attacker {
public :
    float power; // hit points given

    Attacker(float power);
    void attack(Actor *owner, Actor *target);
};
