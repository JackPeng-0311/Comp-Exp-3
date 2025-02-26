/*
 * @author: Jack Peng
 * @description:This code shows an object-oriented four arithmetic game for elementary school students up to 100. 
 * This game allows children to freely choose addition, subtraction, multiplication, division, or end the game, 
 * and tests their computational ability by randomly setting questions. At the end of the game, the number of 
 * correct answers for each question in this game will be given.
 * @version: v1.0
 * @date: 2023-12-16 11:16:10
 */

#include <stdio.h>															//调用函数库
#include <stdlib.h>
#include <time.h>
/*
  定义一个随机生成数函数，生成数范围为N1~N2
 */
int randN1N2(int N1, int N2) {
	return (rand() % (N2 - N1 + 1)) + N1;									//返回随机生成数
}
/*
  定义一个随机产生四则运算函数（在此代码可以舍去）
 */
char randOperator() {
	char operators[] = {'+', '-', '*', '/'};								//构造一个运算符数组
	int index = randN1N2(0,3);												//定义整形变量index，使用randN1N2函数随机选择运算符
	return operators[index];												//返回运算符
}
/*
  定义一个函数随机生成0~99内的数字
 */
int randLmt100() {
	return randN1N2(0, 99);													//调用randN1N2函数进行生成并返回
}
/*
  定义加法函数，输入参数num1、num2进行加法运算
 */
int addLmt100(int num1, int num2) {
	int answer;																//定义整型变量answer
	printf("%d + %d = ", num1, num2);										//输出加法运算式
	scanf("%d", &answer);													//读入读者计算的answer
		
	if (answer == (num1 + num2)) {											//判断答案是否等于标准值
		printf("回答正确！你太棒了！\n\n");						
		return 1;															//返回1用于累计
	} else {
		printf("要多多练习加法运算噢！正确答案是 %d\n\n", num1 + num2);
		return 0;
	}
}
/*
  定义减法函数，输入参数num1、num2进行减法运算
 */
int subLmt100(int num1, int num2) {										
	int numMax = (num1 > num2) ? num1 : num2;								//使用三目运算符进行最大值、最小值判断
	int numMin = (num1 > num2) ? num2 : num1;
	int answer;																//定义整型变量answer
	printf("%d - %d = ", numMax, numMin);									//输出减法运算式
	scanf("%d", &answer);													//读入读者计算的answer
	
	if (answer == (numMax - numMin)) {										//判断答案是否等于标准值
		printf("回答正确！你太棒了！\n\n");
		return 1;															//返回1用于累计
	} else {
		printf("要多多练习减法运算噢！正确答案是 %d\n\n", numMax - numMin);
		return 0;
	}
}
/*
  定义乘法函数，输入参数num1、num2进行乘法运算
 */
int mulLmt100(int num1, int num2) {											
	int answer;																//定义整型变量answer
	printf("%d × %d = ", num1, num2);										//输出乘法运算式
	scanf("%d", &answer);													//读入读者计算的answer
	
	if (answer == (num1 * num2)) {											//判断答案是否等于标准值
		printf("回答正确！太棒了！\n\n");
		return 1;															//返回1用于累计
	} else {
		printf("要多多练习乘法运算噢！正确答案是 %d\n\n", num1 * num2);
		return 0;
	}
}
/*
  定义除法函数，输入参数num1、num2进行除法运算
 */
int divLmt100() {											
	int num1, num2;
	int answer;																//定义整型变量answer
	
	do {
		num1 = randLmt100();												//调用randLmt100函数进行随机生成num1、num2
		num2 = randLmt100();
	} while (num2 == 0 || num1 % num2 != 0);								//判断随机生成的num2是否不为0，且num1是否可以被num2整除
	
	printf("%d ÷ %d = ", num1, num2);										//输出除法运算式
	scanf("%d", &answer);													//读入读者计算的answer
	
	if (answer == (num1 / num2)) {											//判断答案是否等于标准值
		printf("回答正确！太棒了！\n\n");
		return 1;															//返回1用于累计
	} else {
		printf("回答错误！没关系！正确答案是 %d\n\n", num1 / num2);
		return 0;
	}
}
/*
  定义函数用于清空键盘缓冲区
 */
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {							//通过循环将输入缓冲区的所有字符读取出来并删除，读取到换行符或文件结束符则停止读取
	}
}
/*
  定义一个初始页面函数用于第一次初始化页面
 */
void displayWelcomeMessage() {
	printf("欢迎来到儿童四则运算小游戏！\n");
	printf("请准备好，准备开始你的数学冒险吧！\n\n");
}
/*
  定义一个显示菜单函数，在继续游戏时输出
 */
void displayMenu() {
	printf("请选择题目类型：\n");
	printf("1. 加法\n");
	printf("2. 减法\n");
	printf("3. 乘法\n");
	printf("4. 除法\n");
	printf("0. 退出游戏\n");
	printf("请输入选项：");
}
/*
  定义一个选择函数
 */
int getMenuChoice() {
	int choice;																//定义一个整型变量choice
	scanf("%d", &choice);													//读入choice的值
	clearInputBuffer();														//调用clearInputBuffer函数
	printf("\n");
	return choice;
}
/*
  定义计数函数
 */
void playGame() {
	int probNum[4] = {0}; 													//记录题目类型出现的次数
	int ansNum[4] = {0};  													//记录题目答对的次数
	
	while (1) {
		displayMenu();														//展示菜单
		int choice = getMenuChoice();										//获取读者选择choice值
		
		if (choice == 0) {													//若读者选择0则结束程序
			printf("游戏结束，谢谢参与！\n");
			break;
		} else if (choice < 1 || choice > 4) {								//排除读者错误输入的情况
			printf("无效的选项，请重新选择。\n\n");
			continue;
		}
		
		int num1 = randLmt100();											//调用randLmt函数随机产生num1、num2
		int num2 = randLmt100();
		int result;
		
		switch (choice) {													//使用switch-case语句进行四则运算选择

			case 1: 														//加法运算
			result = addLmt100(num1, num2);
			probNum[0]++;													//回答数+1
			ansNum[0] += result;											//答对数+1
			break;
			
			case 2: 														//减法运算
			result = subLmt100(num1, num2);
			probNum[1]++;													//回答数+1
			ansNum[1] += result;											//答对数+1
			break;	
			
			case 3: 														//乘法运算
			result = mulLmt100(num1, num2);
			probNum[2]++;													//回答数+1
			ansNum[2] += result;											//答对数+1
			break;
			
			case 4: 														//除法运算
			result = divLmt100();
			probNum[3]++;													//回答数+1
			ansNum[3] += result;											//答对数+1
			break;
		}
	}
	
	printf("本次答题统计：\n");												//统计结果并显示
	printf("加法题目总数：%d，答对题目数：%d\n", probNum[0], ansNum[0]);
	printf("减法题目总数：%d，答对题目数：%d\n", probNum[1], ansNum[1]);
	printf("乘法题目总数：%d，答对题目数：%d\n", probNum[2], ansNum[2]);
	printf("除法题目总数：%d，答对题目数：%d\n", probNum[3], ansNum[3]);
	printf("感谢参与游戏！\n");
}
/*
  定义主函数用于调用所有子函数
 */
int main() {
	srand(time(NULL)); 														//初始化随机数生成器
	displayWelcomeMessage();												//首次初始化页面
	playGame();																//调用playgame函数进行游戏
	return 0;																//返回0
}
