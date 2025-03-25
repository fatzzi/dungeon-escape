#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Treasure.h"
#include "Enemy.h"

using namespace std;

class Player {
private:
    string name;
    int health;
    int moves; 
    vector<Treasure> inventory;

public:
    Player(string name, int health = 100, int moves = 10);  

    void fight(Enemy& enemy);
    void takeDamage(int damage);
    bool isAlive() const;
    
    void collectTreasure(const Treasure& treasure);
    void showInventory() const;

    int getHealth() const;
    int getMoves() const;        
    void decreaseMoves();        
};

#endif
