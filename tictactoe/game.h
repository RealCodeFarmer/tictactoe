#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard(char board[ROW][COL], int row, int col);
void printBoard(char board[ROW][COL], int row, int col);
void gameerBoard(char board[ROW][COL], int row, int col);
void computerBoard(char board[ROW][COL], int row, int col);

//'*'-玩家赢	'#'-电脑赢		'Q'-平局	'C'-继续
char isWin(char board[ROW][COL], int row, int col);