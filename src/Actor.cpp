#include <stdio.h>
#include "main.hpp"

Actor::Actor(int x, int y, int ch, const char *name,const TCODColor &col) : x(x),y(y),ch(ch),col(col),name(name),blocks(true),attacker(NULL), destructible(NULL),pickable(NULL),container(NULL), ai(NULL) // blocks (false)
 {

}
 

 
void Actor::render() const {
    TCODConsole::root->setChar(x,y,ch);
    TCODConsole::root->setCharForeground(x,y,col);
}

void Actor::update() {
    if (ai)
    {
        ai->update(this);
    }
    // printf ("The %s growls!\n",name);
}
Actor::~Actor() {
    if ( attacker ) delete attacker;
    if ( destructible ) delete destructible;
    if ( ai ) delete ai;
    if ( pickable ) delete pickable;
    if ( container ) delete container;
}
// bool Actor::moveOrAttack(int x,int y) {
//   if ( engine.map->isWall(x,y) ) return false;
//   for (Actor **iterator=engine.actors.begin();
//      iterator != engine.actors.end(); iterator++) {
//      Actor *actor=*iterator;
//      if ( actor->x == x && actor->y ==y ) {
//         printf("The %s laughs at your puny efforts to attack him!\n",
//             actor->name);
//         return false;
//      }
//   }
//   this->x=x;
//   this->y=y;
//   return true;
// }