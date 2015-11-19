//
//  Game.cpp
//  Conecta
//
//  Created by Edwin Montoya on 11/17/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#include <stdio.h>
#include "Board.hpp"
#include "Player.hpp"
int columns, rows, number,option,humanos,maquinas,jugadores,fichas;
int i,j;
bool win=false;
int main(void){
    //    Human Humano1 = *new Human(identification);
    //    identification++;
    //    Human Humano2 = *new Human(identification);
    
    cout<<"Ingrese el numero de fichas consecutivas para ganar: ";
    cin>>number;
    rows=2*number-2;
    columns=2*number-1;
    do{
        cout<<"ingrese el numero de jugadores Humanos: ";
        cin>>humanos;
        cout<<"ingrese el numero de jugadores maquina: ";
        cin>>maquinas;
        cout<<endl;
        jugadores=maquinas+humanos;
    }while(rows*columns%jugadores!=0 || jugadores==1);
    
    fichas=((2*number-1)*(2*number-2))/jugadores;
    Player* players[jugadores];
    
    Board board = *new Board(rows,columns,number);
    for(i=0;i<jugadores;i++){
        if(i<humanos){
            players[i]= new Human(i+1);
            
        }else{
            players[i]= new Machine(i+1);
        }
    }
    board.print();
    cout<<endl;
    j=0;
    int later=columns/2;
    int winner = -1;
    int player=0;
    for(i=0;i<fichas*jugadores && win==false;i++){
        while(!board.checkColumn(players[j]->move(board,later,player))){
            cout<<"la columna esta llena"<<endl;
        }
        later=players[j]->getLastMove();
        board.set(players[j]->getLastMove(),players[j]->getId());
        board.print();
        cout<<endl;
        if(board.win(players[j]->getId(), players[j]->getLastMove())){
            win=true;
            winner=j;
        }
        j++;
        j=j%jugadores;
    }
    cout<<"el jugador "<<winner+1<<" gano!!"<<endl;

    return 0;
}
