#include <iostream>
#include <fstream>
#include <string>
#include "object.hpp"

using namespace std;

int row, col, extend;

ifstream infile("Tetris.data");//以輸入方式開啟檔案
ofstream outfile("Tetris.output");//以輸出方式開啟檔案

void printmap(int *map[]);
void printans(int *map[]);
void eliminate_line(int *map[], int e_row);

int main()
{
    // Input row and column
    infile >> row >> col;

    // Check if row and column are valid value.
    if(row>40 || col>15){
        cout << "Invalid row or column" << endl;
        return 0;
    }

    // Add extend row to help detect the elimination of top row.
    extend = 5;
    int* map [row+extend];
    for(int i=0; i<row+extend; i++){
        map[i] = new int [col];
        for(int j=0; j<col; j++){
            map[i][j] = 0;
        }
    }
    
    // Input tetris's style and location.
    string input;
    int input_column;
    while(1)
    {
        // Read data into program.
        infile >> input;
        if(input == "End") break;
        infile >> input_column;
        input_column -= 1;
        // Try to put tetris into map.
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

        // Line elimination.
        for(int i=extend; i<row+extend; i++){
            // Judge if lines can be eliminated.
            bool all_one = true;
            for(int j=0; j<col; j++){
                if(map[i][j] == 0){
                    all_one = false;
                    break;
                }
            }
            // Eliminate the line if all_one is true.
            if(all_one){
                eliminate_line(map, i-extend);
                i--;
            }
        }
        

        /* Check that after the input is placed, the map should be valid.
           If invalid, then the program should output the result of map.  */
        for(int i=0; i<col; i++){
            if (map[extend-1][i]==1){
                //printmap(map);
                printans(map);
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
    // Let the last row be zero
    for(int i=0; i<col; i++){
        map[0][i] = 0;
    }
}
void printans(int *map[])
{
    for(int i=extend; i<row+extend; i++){
        // elements
        for(int j=0; j<col; j++){
            outfile << map[i][j] /* << " " */;
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