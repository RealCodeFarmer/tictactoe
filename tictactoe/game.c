#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void initBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void printBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("----------------------------------------------\n");
}

void gameerBoard(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		//�����������
		printf("��һ��� , ���������� :>");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x >= 1 && y >= 1 && x <= row && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			} else {
				printf("������������,����������!\n");
			}
		} else {
			printf("�Ƿ�����,����������!\n");
		}
	}
}

void computerBoard(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("���Ի��� :>\n");
	while (1) {
		//������������
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

int isFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char isWin(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	//�ж���
	for (i = 0; i < row; i++) {
		for (j = 1; j < col; j++) {
			if (board[i][j] != board[i][j - 1]) {
				break;
			}
		}
		if (j == col && board[i][j - 1] != ' ') {
			return board[i][j - 1];
		}
	}
	//�ж���
	for (i = 0; i < col; i++) {
		for (j = 1; j < row; j++) {
			if (board[j][i] != board[j - 1][i]) {
				break;
			}
		}
		if (j == row && board[j - 1][i] != ' ') {
			return board[j - 1][i];
		}
	}
	//�ж���Խ���
	i = 0;
	j = 0;
	while (1) {
		if (i + 1 < row && j + 1 < col) {
			if (board[i][j] != board[i + 1][j + 1]) {
				break;
			}
			i++;
			j++;
		} else {
			break;
		}
		if (i == row && j == col && board[i - 1][j - 1] != ' ') {
			return board[i - 1][j - 1];
		}
	}
	//�ж��ҶԽ���
	i = 0;
	j = col - 1;
	while (1) {
		if (i + 1 < row && j - 1 >= 0) {
			if (board[i][j] != board[i + 1][j - 1]) {
				break;
			}
			i++;
			j--;
		} else {
			break;
		}
		if (i == row && j == 0 && board[i - 1][j] != ' ') {
			return board[i - 1][j];
		}
	}
	//�ж��Ƿ�����
	if (isFull(board, row, col)) {
		return 'Q';
	}
	return 'C';
}
