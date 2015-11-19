//
//  Player.hpp
//  Conecta
//
//  Created by Edwin Montoya on 11/15/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Board.hpp"
#include <cstdlib>
using namespace std;
class Player{
public:
    Player(int id);
    virtual int move(Board board,int lastMove, int player)=0;
    virtual int getId() const = 0;
    virtual int getLastMove() const = 0;
protected:
    int identification;
    int last;
};

class Human: public Player{
public:
    Human(int id);
    int move(Board board,int lastMove, int player);
    int getId() const;
    int getLastMove() const;

    
    
};

class Machine: public Player{
public:
    Machine(int id);
    int move(Board board,int lastMove, int player);
    int getId() const;
    int getLastMove() const;
};
#endif /* Player_hpp */
