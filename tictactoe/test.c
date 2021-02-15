#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void choice() {
	printf("#################################\n");
	printf("###### 1.play       2.退出 ######\n");
	printf("#################################\n");
}

void game() {
	//接收结果
	char ret = 0;
	//创建棋盘
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	initBoard(board, ROW, COL);
	//打印棋盘
	printBoard(board, ROW, COL);
	//下棋
	while (1) {
		//玩家下棋
		gameerBoard(board, ROW, COL);
		//打印棋盘
		printBoard(board, ROW, COL);
		//判断输赢
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		computerBoard(board, ROW, COL);
		//打印棋盘
		printBoard(board, ROW, COL);
		//判断输赢
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("玩家赢,游戏结束\n");
	} else if (ret == '#') {
		printf("电脑赢,游戏结束\n");
	} else {
		printf("平局,游戏结束\n");
	}
}

int main() {
	int i = 0;
	srand((unsigned int)time(NULL));
	while (1) {
		//输出选择框
		choice();
		printf("请输入指令 :>");
		scanf("%d", &i);
		switch (i) {
			case 1:
				game();
				break;
			case 2:
				i = -1;
				break;
			default:
				printf("输入错误,请重新输入\n");
				break;
		}
		if (i == -1) {
			break;
		}
	}
	return 0;
}