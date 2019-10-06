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
