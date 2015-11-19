//
//  Board.cpp
//  Conecta
//
//  Created by Edwin Montoya on 11/15/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#include "Board.hpp"
Board::Board(int row, int column, int number):columns(column), rows(row), n(number){
    board = new int*[rows];
    for(int i = 0; i < rows; ++i)
        board[i] = new int[columns];
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            board[i][j]=0;
        }
    }
}

void Board::set(int column, int player){
    board[(getLastRow(column))][column]=player;
}

int Board::getLastRow(int col){
    int cont=0;
    for(int i=0;i<rows;i++)
    {
        if(board[i][col]!=0)
        {
            cont++;
        }
    }
    
    return (rows-1)-cont;
}

bool Board::win(int player, int column){
    int cont=0;
    int row= getLastRow(column);
    if(rows-row>=n)
    {
        for(int i=rows-1;i>row;i--)
        {
            if(board[i][column]==player)
            {
                cont++;
                if(cont==n)
                {return true;}
            }
            else
            {
                cont=0;
            }
        }
    }
    cont=0;
    row++;
    for(int i=0;i<columns;i++)
    {
        if(board[row][i]==player)
        {
            cont++;
            if(cont==n)
            {return true;}
        }
        else
        {
            cont=0;
        }
    }
    cont=0;
    int i=row;
    int j=column;
    while(j!=0 && i<rows-1)
    {
        i++;
        j--;
    }
    for(;i>=0 && j<columns;i--,j++)
    {
        if(board[i][j]==player)
        {
            cont++;
            if(cont==n)
            {return true;}
        }
        else
        {
            cont=0;
        }
    }
    cont=0;
    i=row;
    j=column;
    while(j!=0 && i!=0)
    {
        i--;
        j--;
    }
    for(; i<rows && j<columns;i++,j++)
    {
        if(board[i][j]==player)
        {
            cont++;
            if(cont==n)
            {return true;}
        }
        else
        {
            cont=0;
        }
    }

    return false;
}

bool Board::checkColumn(int column){
    if(board[0][column]==0){
        return true;
    }else{
        return false;
    }
}

int Board::getColums() const{
    return columns;
}

int Board::getRows() const{
    return rows;
}

int Board::getNumbers() const{
    return n;
}

void Board::print(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}