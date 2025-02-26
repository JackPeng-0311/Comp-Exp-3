#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void generate_problem(int *n1, int *n2, char *operator) {
	*n1 = rand() % 10;
	*n2 = rand() % 10;
	
	char operators[4] = { '+', '-', '×', '÷' };
	*operator = operators[rand() % 4];
	
	if (*operator == '÷') {
		while (*n2 == 0 || *n1 % *n2 != 0) {
			*n1 = rand() % 10;
			*n2 = rand() % 10;
		}
	}
}

void check_answer(int user_answer, int correct_answer) {
	if (user_answer == correct_answer) {
		printf("\n回答正确！\n");
	} else {
		printf("\n回答错误！请再试一次。\n");
	}
}

void clear_screen() {
	system("cls");
}

void set_text_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void set_cursor_visibility(int visibility) {
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.dwSize = sizeof(cursor_info);
	cursor_info.bVisible = visibility;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void show_intro() {
	set_text_color(11);
	printf("***********************************\n");
	printf("    欢迎来到儿童四则运算游戏\n");
	printf("***********************************\n\n");
	set_text_color(7);
}

void show_problem(int n1, int n2, char operator) {
	set_text_color(14);
	printf("题目：%d %c %d\n", n1, operator, n2);
	set_text_color(7);
}

int main() {
	srand(time(NULL));
	
	int n1, n2, user_answer, correct_answer;
	char operator;
	char input[100];
	
	set_cursor_visibility(0);
	clear_screen();
	show_intro();
	
	while (1) {
		generate_problem(&n1, &n2, &operator);
		show_problem(n1, n2, operator);
		
		printf("请输入答案：");
		fgets(input, sizeof(input), stdin);
		user_answer = atoi(input);
		
		correct_answer = 0;
		switch (operator) {
		case '+':
			correct_answer = n1 + n2;
			break;
		case '-':
			correct_answer = n1 - n2;
			break;
		case '×':
			correct_answer = n1 * n2;
			break;
		case '÷':
			correct_answer = n1 / n2;
			break;
		}
		
		check_answer(user_answer, correct_answer);
		
		printf("按任意键继续，或按ESC键退出...\n");
		if (_getch() == 27) {
			break;
		}
		
		clear_screen();
	}
	
	return 0;
}
