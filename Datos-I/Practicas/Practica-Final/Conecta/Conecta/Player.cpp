//
//  Player.cpp
//  Conecta
//
//  Created by Edwin Montoya on 11/15/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#include "Player.hpp"
Player::Player(int id): identification(id)
{}


Human::Human(int id):Player(id)
{}

int Human::getId() const{
    return identification;
}

int Human::getLastMove() const{
    return last;
}

int Human::move(Board board,int lastMove,int player){
    cout<<"Jugador "<<getId()<<" ingrese la columna: ";
    cin>>last;
    return last;
}

Machine::Machine(int id):Player(id)
{}

int Machine::getId() const{
    return identification;
}

int Machine::getLastMove() const{
    return last;
}

int Machine::move(Board board,int lastMove, int player){
    int col=board.getColums();
    last=(rand()+lastMove)%col;
    return last;
}


