#ifndef ROOM_H
#define ROOM_H

#include "Enemy.h"
#include "Challenge.h"
#include "Treasure.h"
#include "Player.h"
#include "Queue.h"
#include <string>

using namespace std;

class Room {
private:
    string name;
    Queue enemies;
    vector<Enemy> originalEnemies;  
    Challenge challenge;
    Treasure treasure;
    Room* next;
    Room* prev;

public:
    Room(const string& name, const Challenge& challenge, const Treasure& treasure);
    
    void addEnemy(const Enemy& enemy);
    bool hasEnemies() const;
    Enemy& getNextEnemy();
    void removeDefeatedEnemy();
    
    Room* getNext() const;
    Room* getPrev() const;
    void setNext(Room* nextRoom);
    void setPrev(Room* prevRoom);

    bool triggerRoomEvents(Player& player);
    string getName() const; 
    void resetEnemies();
};

#endif
