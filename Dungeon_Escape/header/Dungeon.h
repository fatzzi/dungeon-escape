#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "Player.h"
#include "Stack.h"

class Dungeon {
private:
    Room* head;
    Room* tail;
    Room* currentRoom;
    Stack roomStack; // Stack for backtracking

public:
    Dungeon();
    ~Dungeon();

    void addRoom(Room* newRoom); 
    void move(Player& player, bool forward);
    void displayCurrentRoom() const;
    bool isEscaped() const;
    Room* getCurrentRoom() const;
    Stack& getRoomStack();
};

#endif
