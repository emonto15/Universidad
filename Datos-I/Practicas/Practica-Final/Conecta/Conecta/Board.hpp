//
//  Board.hpp
//  Conecta
//
//  Created by Edwin Montoya on 11/15/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Board{
public:
    Board(int row, int column,int number);
    void set(int column,int player);
    int getLastRow(int column);
    bool win(int player, int column);
    bool checkColumn(int column);
    int getRows() const;
    int getColums() const;
    int getNumbers() const;
    void print();
private:
    int** board;
    const int rows;
    const int columns;
    const int n;
    
};
#endif /* Board_hpp */
