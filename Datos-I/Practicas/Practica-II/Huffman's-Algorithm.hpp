//
//  Huffman's Algorithm.hpp
//  Huffman's Algorithm
//
//  Created by Edwin Montoya on 10/10/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#ifndef Huffman_s_Algorithm_hpp
#define Huffman_s_Algorithm_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void phaseOne();
void organize(int *b,int h, int n);
void min_heapify(int *a, int i, int n,int *b);
void HeapSort(int *a,int n, int *b);
void build_minheap(int *a, int n, int *b);
void phaseTwo(int *A,int half);
void phaseThree(int *A, int n);
void Allocation(int *A, int maxlength, int n);

#endif /* Huffman_s_Algorithm_hpp */
