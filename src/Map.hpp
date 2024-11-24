#pragma once


struct Tile {
    bool explored; // has the player already seen this tile ?
    Tile() : explored(false) {}
};
 
class Map {
public :
    int width,height;
 
    Map(int width, int height);
    ~Map();
    bool isWall(int x, int y) const;
	bool isInFov(int x, int y) const;
    bool isExplored(int x, int y) const;
    bool canWalk(int x, int y) const;
    void addMonster(int x, int y);
    static void addItem(int x, int y);
    void computeFov();
    void render() const;
protected :
    Tile *tiles;
    TCODMap *map;
    friend class BspListener;
 
    void dig(int x1, int y1, int x2, int y2);
    void createRoom(bool first, int x1, int y1, int x2, int y2);
};