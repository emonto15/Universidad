//
//  Huffman's Algorithm.cpp
//  Huffman's Algorithm
//
//  Created by Edwin Montoya on 10/10/15.
//  Copyright © 2015 Edwin Montoya. All rights reserved.
//

#include "Huffman's Algorithm.hpp"
int n;
int half,i,cont,temp=255,temporary[255];
int m1,m2,h;
int d,r;
int maxlength,l;
char character;
int main(){
    phaseOne();
}
//This method will read the file and count the frecuency of each letter.
void phaseOne(){
    ifstream file;
    file.open("prueba.txt");
    while (!file.eof()) {
        file.get(character);
        temporary[character]++;
    }
    temporary[character]--;
    
    n=0;
    //this for loop it's use for dismiss the letteres whose frecuency is zero.
    for (i=1; i<temp;i++)
    {
        if(temporary[i]!=0){
            n++;
        }
    }
    //this will be the main array.
    int A[n*2+1];
    
    half=n;
    
    cont=1;
    for (i=1; i<=temp-1 ;i++)
    {
        if(temporary[i]!=0){
            A[cont+half]=temporary[i];
            A[cont]=i;
            cont++;
        }
    }
    //data will be the half that holds the frecuency data
    int data[half+1];
    
    //index will be the half that holds the aims to the frecuency
    int index[half+1];
    
    //this for loop it's use to extract the data from A and their pointers
    for (i=1;i<=half;i++)
    {
        data[i]=A[i+half];
        index[i]=i+half;
    }
    
    build_minheap(data,half, index);
    HeapSort(data,half,index);
    
    for (i=1;i<=half;i++)
    {
        A[i]=index[i];
    }
    phaseTwo(A,half);
}
//this method it's where the comparisons between the children and the parent.
void min_heapify(int *a, int i, int n,int *b)
{
    int j, temp,tempc;
    temp = a[i];
    tempc = b[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            b[j/2] = b[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    b[j/2] = tempc;
    return;
}
//this method is where the min-value is taked off
void HeapSort(int *a, int n,int * b)
{
    int i, temp, tempc;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        tempc = b[i];
        a[i] = a[1];
        b[i] = b[1];
        a[1] = temp;
        b[1] = tempc;
        min_heapify(a, 1, i - 1,b);
    }
}
//this method calls min_heapify to start the heap comparison
void build_minheap(int *a, int n, int *b)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(a, i, n, b);
    }
}
void organize(int *B,int half, int n){
    //data will be the half that holds the frecuency data
    int data[half+1];
    
    //index will be the half that holds the aims to the frecuency
    int index[half+1];
    
    //this for loop it's use to extract the data from A and their pointers
    for (i=1;i<=half;i++)
    {
        index[i]=B[i];
        data[i]=B[index[i]];
    }
    build_minheap(data,half, index);
    HeapSort(data,half,index);
    
    for (i=1;i<=half;i++)
    {
        B[i]=index[i];
    }
}
void phaseTwo(int *A, int n){
    h=n;
    while(h>1){
        //stage a
        m1=A[1];
        A[1]=A[h];
        h--;
        //stage b
        organize(A, h, n);
        m2=A[1];
        //stage c
        A[h+1]=A[m1]+A[m2];
        A[1]=h+1;
        A[m1]=h+1;
        A[m2]=A[m1];
        //stage d
        organize(A, h, n);
    }
    phaseThree(A, n);
}
void phaseThree(int *A, int n){
    for(i=n+1;i<=2*n;i++){
        d=0;
        r=i;
        while (r > 2) {
            d++;
            r=A[r];
        }
        A[i]=d;
    }
    int sizes[n];
    for(i=n+1;i<=2*n;i++){
        sizes[i-n]=A[i];
    }
    maxlength=0;
    for(int i=1;i<=n;i++){
        if(sizes[i]>maxlength){
            maxlength=sizes[i];
        }
    }
    Allocation(sizes, maxlength, n);
//    //revised phase three
//    A[2]=0;
//    for (i=3;i<=2*n;i++){
//        A[i]=A[A[i]]+1;
//    }
//    for(i=1;i<=n*2;i++)
//    {
//        cout << A[i]<<" ";
//    }
//    cout<<endl;
    
}
void Allocation(int *sizes, int maxlength, int n){
    int numl[maxlength];
    int firstcode[maxlength];
    int nextcode[maxlength];
    int codeword[n];
    int symbol[n][maxlength];
    //1
    for(l=1;l<=maxlength;l++){
        numl[l]=0;
        for(i=0;i<=n;i++) {
            numl[sizes[i]]=numl[sizes[i]]+1;
        }
    }
    //2
    firstcode[maxlength]=0;
    for (l=maxlength-1;l>=1;l--){
        firstcode[l]=firstcode[l+1]+numl[l+1];
    }
    //3
    for (l=1;l<=maxlength;l++){
        nextcode[l]=firstcode[l];
    }
    //4
    for(i=1;i<=n;i++){
        codeword[i]=nextcode[sizes[i]];
        symbol[sizes[i]][nextcode[sizes[i]-firstcode[sizes[i]]]]=i;
        nextcode[sizes[i]]=nextcode[sizes[i]]+1;
    }
    for(i=1;i<=maxlength;i++){
        for(int j=1;j<=n;j++){
            cout<<symbol[i][j]<<" ";
        }
        cout<<endl;
    }
}
