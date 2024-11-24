#pragma once


class Engine {
public :
	enum GameStatus {
		STARTUP,
		IDLE,
		NEW_TURN,
		VICTORY,
		DEFEAT
	} gameStatus;
	TCOD_key_t lastKey;
TCOD_mouse_t mouse;
    TCODList<Actor *> actors;
    Actor *player;
    Map *map;
    int fovRadius;
    int screenWidth;
    int screenHeight;
    Gui *gui;

 
    Engine(int screenWidth, int screenHeight);
    ~Engine();
    void update();
    void render();
    void sendToBack(Actor *actor);
};
 
extern Engine engine;
