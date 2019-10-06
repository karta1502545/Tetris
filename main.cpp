#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int row, col, extend;
ifstream infile("tetris.data.txt");//以輸入方式開啟檔案
ofstream outfile("tetris.final.txt");//以輸出方式開啟檔案
/*
T1 L1 J1 S1 I1
T2 L2 J2 S2 I2
T3 L3 J3 Z1 O
T4 L4 J4 Z2

max used space: 4*4
*/

// Functions of finding locations to put in the input. 
void T1(int col_loc, int *map[]);
void T2(int col_loc, int *map[]);
void T3(int col_loc, int *map[]);
void T4(int col_loc, int *map[]);
void L1(int col_loc, int *map[]);
void L2(int col_loc, int *map[]);
void L3(int col_loc, int *map[]);
void L4(int col_loc, int *map[]);
void J1(int col_loc, int *map[]);
void J2(int col_loc, int *map[]);
void J3(int col_loc, int *map[]);
void J4(int col_loc, int *map[]);
void S1(int col_loc, int *map[]);
void S2(int col_loc, int *map[]);
void Z1(int col_loc, int *map[]);
void Z2(int col_loc, int *map[]);
void I1(int col_loc, int *map[]);
void I2(int col_loc, int *map[]);
void O(int col_loc, int *map[]);

void printmap(int *map[]);
void printans(int *map[]);
void eliminate_line(int *map[], int e_row);

int main()
{
    // Create a map
    extend = 5;
    infile >> row >> col;
    if(row>40 || col>15){
        cout << "Invalid row or column" << endl;
        return 0;
    }

    int* map [row+extend];
    for(int i=0; i<row+extend; i++){
        map[i] = new int [col];
        for(int j=0; j<col; j++){
            map[i][j] = 0;
        }
    }
    
    string input;
    int input_column;
    while(1)
    {
        // Read data into program.
        infile >> input;
        if(input == "End") break;
        infile >> input_column;
        input_column -= 1;
        // Try to put input into map.
        if(input == "T1") T1(input_column, map);
        else if(input == "T2") T2(input_column, map);
        else if(input == "T3") T3(input_column, map);
        else if(input == "T4") T4(input_column, map);

        else if(input == "L1") L1(input_column, map);
        else if(input == "L2") L2(input_column, map);
        else if(input == "L3") L3(input_column, map);
        else if(input == "L4") L4(input_column, map);

        else if(input == "J1") J1(input_column, map);
        else if(input == "J2") J2(input_column, map);
        else if(input == "J3") J3(input_column, map);
        else if(input == "J4") J4(input_column, map);

        else if(input == "S1") S1(input_column, map);
        else if(input == "S2") S2(input_column, map);
        else if(input == "Z1") Z1(input_column, map);
        else if(input == "Z2") Z2(input_column, map);

        else if(input == "I1") I1(input_column, map);
        else if(input == "I2") I2(input_column, map);
        else if(input == "O")  O(input_column, map);

        // Judge if lines can be eliminated.
        for(int i=0; i<row+extend; i++){
            bool all_one = true;
            for(int j=0; j<col; j++){
                if(map[i][j] == 0){
                    all_one = false;
                    break;
                }
            }
            if(all_one) eliminate_line(map, i-extend);
        }
        

        /* Check that after the input is placed, the map should be valid.
           If invalid, then the program should output "Gameover"         */
        for(int i=0; i<col; i++){
            if (map[extend-1][i]==1){
                //printmap(map);
                printans(map);
                outfile << "You lose." << endl;
                exit(0);
            }
        }
        // After each input, show the new map.
        //printmap(map);
    }

    //printmap(map);
    printans(map);
    return 0;
}
void eliminate_line(int *map[], int e_row) // e_row = 0 ~ row-1
{
    for(int i=e_row+extend; i>=1; i--){
        for(int j=0; j<col; j++){
            map[i][j] = map[i-1][j];
        }
    }
}
void printans(int *map[])
{
    for(int i=extend; i<row+extend; i++){
        // elements
        for(int j=0; j<col; j++){
            outfile << map[i][j] << " ";
        }
        outfile << endl;
    }
}
void printmap(int *map[])
{
    for(int i=0; i<row+extend; i++){
        // Out-of-bound line
        if(i==extend){
            cout << "------";
            for(int j=0; j<2*col-1; j++){
                cout << "-";
            }
            cout << endl;
        }

        // Row index
        if(row+extend-i > 9)
            cout << row+extend-i << " ";
        else
            cout << row+extend-i << "  ";
        // elements
        for(int j=0; j<col; j++){
            cout << " | " << map[i][j];
        }
        cout << endl;
    }
    
    // Column index
    cout << "      ";
    for(int i=0; i<2*col-1; i++){
        cout << "-";
    }
    cout << endl;

    cout << "      ";
    for(int i=0; i<col; i++){
        cout << i+1 << " ";
    }
}

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