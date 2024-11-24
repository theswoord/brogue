#include "main.hpp"


Engine::Engine(int screenWidth, int screenHeight) : gameStatus(STARTUP),fovRadius(10),screenWidth(screenWidth),screenHeight(screenHeight) {
    TCODConsole::initRoot(screenWidth,screenHeight,"1337rogue",false);
    player = new Actor(40,25,'*',"theswoord",TCODColor::white);
	    player->destructible=new PlayerDestructible(50,5,"jotta");
    player->attacker=new Attacker(5);
    player->ai = new PlayerAi();
    player->container = new Container(26);
    actors.push(player);
    map = new Map(80,45);
    gui = new Gui();
    gui->message(TCODColor::red,
  "Welcome theswoord!\nWelcome to your realm");
}

Engine::~Engine() {
    actors.clearAndDelete();
    delete map;
    delete gui;
}

void Engine::update() {
    // TCOD_key_t key;
        if ( gameStatus == STARTUP ) map->computeFov();
    gameStatus=IDLE;
        // printf("hh\n");

    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&lastKey,NULL);
    player->update();
    if ( gameStatus == NEW_TURN ) {
        for (Actor **iterator=actors.begin(); iterator != actors.end();
            iterator++) {
            Actor *actor=*iterator;
            if ( actor != player  ) {
                actor->update();
            }
        }
	}
}

void Engine::render() {
	TCODConsole::root->clear();
	// draw the map
	map->render();
	// draw the actors
	for (Actor **iterator=actors.begin();
	    iterator != actors.end(); iterator++) {
		Actor *actor=*iterator;
		if ( actor != player && map->isInFov(actor->x,actor->y) ) {
	        actor->render();
	    }
        
	}
	player->render();
	// show the player's stats
    gui->render();
	TCODConsole::root->print(1,screenHeight-2, "HP : %d/%d",
		(int)player->destructible->hp,(int)player->destructible->maxHp);
}


void Engine::sendToBack(Actor *actor) {
    actors.remove(actor);
    actors.insertBefore(actor,0);
}