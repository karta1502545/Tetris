#include <iostream>
#include "object.hpp"

using namespace std;

// Functions of finding locations to put in the input. 
void T1(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if(i==row+extend-1){
            map[i][col_loc+1] = 1;
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-1][col_loc+2] = 1;           
        }
        if(map[i][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i][col_loc+2]==1)
        {
            map[i][col_loc+1] = 1;
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-1][col_loc+2] = 1;
            break;
        }
    }
}
void T2(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if(i==row+extend-1){
            map[i-1][col_loc] = 1;
            map[i][col_loc+1] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-2][col_loc+1] = 1;
        }
        if(map[i][col_loc]==1 || map[i+1][col_loc+1]==1)
        {
            map[i-1][col_loc] = 1;
            map[i][col_loc+1] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-2][col_loc+1] = 1;
            break;
        }
    }
}
void T3(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i+1][col_loc+2]==1) || i==row+extend-1){
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            map[i][col_loc+2] = 1;
            map[i-1][col_loc+1] = 1;
            break;
        }
    }
}
void T4(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i][col_loc+1]==1) || i==row+extend-1){
            map[i][col_loc] = 1;
            map[i-1][col_loc] = 1;
            map[i-2][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            break;
        }
    }
}
// L
void L1(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1) || i==row+extend-1){
            map[i-2][col_loc] = 1;
            map[i-1][col_loc] = 1;
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            break;
        }
    }
}
void L2(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i][col_loc+1]==1 || map[i][col_loc+2]==1 || map[i+1][col_loc]==1) || i==row+extend-1){
            map[i][col_loc] = 1;
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-1][col_loc+2] = 1;
            break;
        }
    }
}
void L3(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i-1][col_loc]==1 || map[i+1][col_loc+1]==1) || i==row+extend-1){
            map[i-2][col_loc] = 1;
            map[i-2][col_loc+1] = 1;
            map[i-1][col_loc+1] = 1;
            map[i][col_loc+1] = 1;
            break;
        }
    }
}
void L4(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i+1][col_loc+2]==1) || i==row+extend-1){
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            map[i][col_loc+2] = 1;
            map[i-1][col_loc+2] = 1;
            break;
        }
    }
}
// J
void J1(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1) || i==row+extend-1){
            map[i-2][col_loc+1] = 1;
            map[i-1][col_loc+1] = 1;
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            break;
        }
    }
}
void J2(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i+1][col_loc+2]==1) || i==row+extend-1){
            map[i-1][col_loc] = 1;
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            map[i][col_loc+2] = 1;
            break;
        }
    }
}
void J3(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i-1][col_loc+1]==1 || map[i+1][col_loc]==1) || i==row+extend-1){
            map[i-2][col_loc] = 1;
            map[i-1][col_loc] = 1;
            map[i][col_loc] = 1;
            map[i-2][col_loc+1] = 1;
            break;
        }
    }
}
void J4(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i][col_loc]==1 || map[i][col_loc+1]==1 || map[i+1][col_loc+2]==1) || i==row+extend-1){
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-1][col_loc+2] = 1;
            map[i][col_loc+2] = 1;
            break;
        }
    }
}
//S
void S1(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i][col_loc+2]==1) || i==row+extend-1){
            map[i-1][col_loc+1] = 1;
            map[i-1][col_loc+2] = 1;
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            break;
        }
    }
}
void S2(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i][col_loc]==1 || map[i+1][col_loc+1]==1) || i==row+extend-1){
            map[i-2][col_loc] = 1;
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i][col_loc+1] = 1;
            break;
        }
    }
}
//Z
void Z1(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+2 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i+1][col_loc+2]==1) || i==row+extend-1){
            map[i][col_loc+1] = 1;
            map[i][col_loc+2] = 1;
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            break;
        }
    }
}
void Z2(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i][col_loc+1]==1) || i==row+extend-1){
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i-2][col_loc+1] = 1;
            map[i][col_loc] = 1;
            break;
        }
    }
}
// I
void I1(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if(map[i+1][col_loc]==1 || i==row+extend-1){
            map[i][col_loc] = 1;
            map[i-1][col_loc] = 1;
            map[i-2][col_loc] = 1;
            map[i-3][col_loc] = 1;
            break;
        }
    }
}
void I2(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+3 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if(map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1 || map[i+1][col_loc+2]==1 || map[i+1][col_loc+3]==1 || i==row+extend-1){
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            map[i][col_loc+2] = 1;
            map[i][col_loc+3] = 1;
            break;
        }
    }
}
// O
void O(int col_loc, int *map[])
{
    if(col_loc < 0 || col_loc+1 >= col){
        cout << "Invalid testcase: Out of bound. Col_loc = " << col_loc+1; 
        exit(0);
    }
    for(int i=extend-1; i<=row+extend-1; i++){
        if((map[i+1][col_loc]==1 || map[i+1][col_loc+1]==1) || i==row+extend-1){
            map[i-1][col_loc] = 1;
            map[i-1][col_loc+1] = 1;
            map[i][col_loc] = 1;
            map[i][col_loc+1] = 1;
            break;
        }
    }
}
void printmap(int *map[]);
void printans(int *map[]);
void eliminate_line(int *map[], int e_row);


// test how to input and output through file.
/*
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("tetris.data.txt");//以輸入方式開啟檔案
    ofstream outfile("tetris.final.txt");//以輸出方式開啟檔案

    int row, col, input_column;
    string input;
    infile >> row >> col;
    int map[row][col] = {0};
    while(1){
        infile >> input >> input_column;
        if(input=="End") break;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            outfile << " " << map[i][j];
        }
        outfile << endl;
    }
    infile.close();
    outfile.close();

    return 0;
}
*/