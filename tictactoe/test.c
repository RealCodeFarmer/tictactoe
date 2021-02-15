#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void choice() {
	printf("#################################\n");
	printf("###### 1.play       2.�˳� ######\n");
	printf("#################################\n");
}

void game() {
	//���ս��
	char ret = 0;
	//��������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	initBoard(board, ROW, COL);
	//��ӡ����
	printBoard(board, ROW, COL);
	//����
	while (1) {
		//�������
		gameerBoard(board, ROW, COL);
		//��ӡ����
		printBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//��������
		computerBoard(board, ROW, COL);
		//��ӡ����
		printBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("���Ӯ,��Ϸ����\n");
	} else if (ret == '#') {
		printf("����Ӯ,��Ϸ����\n");
	} else {
		printf("ƽ��,��Ϸ����\n");
	}
}

int main() {
	int i = 0;
	srand((unsigned int)time(NULL));
	while (1) {
		//���ѡ���
		choice();
		printf("������ָ�� :>");
		scanf("%d", &i);
		switch (i) {
			case 1:
				game();
				break;
			case 2:
				i = -1;
				break;
			default:
				printf("�������,����������\n");
				break;
		}
		if (i == -1) {
			break;
		}
	}
	return 0;
}