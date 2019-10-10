#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

extern int row, col, extend;

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

#endif // OBJECT_H_INCLUDED