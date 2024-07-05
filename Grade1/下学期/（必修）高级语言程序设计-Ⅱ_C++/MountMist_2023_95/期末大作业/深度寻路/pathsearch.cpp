/*
--------READ ME FIRST-------
功能：
本程序使用了深度优先搜索与栈实现迷宫自动寻路
（不是用户走迷宫游戏，是程序自动寻路）
迷宫由程序中的二维数组决定，可以进行修改，寻路功能仍然生效
使用easyX构造了简单的图形界面，可以显示所经过的路径，也可以在字符界面中用坐标表示
（本程序图形素材均由作者手绘 hhhh）
为了增加用户的互动体验感，程序设置为成功寻路后用户按键一次走一步直到走到终点
如果所给地图与起始点无解，则会显示“未找到路径”

不足：
本程序只能寻找一条可行的路径，不保证在多条路径共存的情况下寻找到最优路径
本程序的行文过程中可能存在一些奇怪的地方，是为了正常运行而做的特殊性修改
本程序在某些地方保留了较多作者更为熟悉的C语言风格，C++的封装性有待提高
----------------------
*/
#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include"mystack.h"
using namespace std;
//定义地图大小，行数与列数
#define ROWS 10
#define COLS 10
//定义每一个格子的大小
#define SPACE 70
//定义图片
IMAGE road, path, wall,start,finish;
//枚举寻路方向便于表达，0123上下左右
enum direct{tup,tdown,tleft,tright};
//标记变量用于记录是否成功寻路
bool successfind = false;
bool flag = false;
struct pathnode {
	int dir;	//寻路方向
	bool vis;	//是否已经访问过
};
struct cpoint {
	int row;
	int col;
};
void printmap(int map[ROWS][COLS]){
	//字符界面显示地图
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (map[i][j] == 0)
				cout << "  ";
			else if (map[i][j] == 1)
				cout << "墙";
		}
		cout << endl;
	}
};
void showmap(int map[ROWS][COLS]) {
	//图形界面显示地图
	for (int i = 0; i < ROWS; i++) {		//y轴坐标
		for (int j = 0; j < ROWS; j++) {	//x轴坐标
			if (map[i][j] == 0)
				putimage(j * SPACE, i * SPACE, &road);
			else if (map[i][j] == 1)
				putimage(j * SPACE, i * SPACE, &wall);
			else if (map[i][j] == 2)
				putimage(j * SPACE, i * SPACE, &path);
			else if (map[i][j] == 3)
				putimage(j * SPACE, i * SPACE, &finish);
			else if (map[i][j] == 4)
				putimage(j * SPACE, i * SPACE, &start);
		}
		cout << endl;
	}
};
int main()
{
	//制作图形窗口
	initgraph(COLS*SPACE,ROWS*SPACE,1);
	loadimage(&road,"road.png", SPACE, SPACE, true);
	loadimage(&wall, "wall.png", SPACE, SPACE, true);
	loadimage(&path, "path.png", SPACE/2, SPACE/2, true);
	loadimage(&start, "start.png", SPACE, SPACE, true);
	loadimage(&finish, "finish.png", SPACE, SPACE, true);
	//定义地图，1表示墙，0表示路
	int map[ROWS][COLS] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,1,1,0,0,0,1},
		{1,0,1,0,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,1,1,0,1,0,1},
		{1,0,1,1,1,1,0,1,0,1},
		{1,0,1,0,1,0,0,1,0,1},
		{1,0,1,0,1,0,1,1,0,1},
		{1,0,1,0,0,0,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	pathnode vismap[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			vismap[i][j].dir = 0;
			vismap[i][j].vis = false;
		}
	}
	//先初始化地图的每个点，设置为未访问，且初始寻路方向为上
	cpoint beginpoint = { 1,1 };

	cpoint endpoint = { 8,8 };
	
	//将起点设置为已访问
	vismap[beginpoint.row][beginpoint.col].vis = true;
	cpoint current = beginpoint;
	cpoint next;
	//创建一个point类型的栈，准备后续回溯使用
	mystack<cpoint>stack;
	stack.push(beginpoint);//起点入栈
	printmap(map);
	showmap(map);
	
	while (1) {
		//确定当前寻路起始点
		next = current;
		//遍历下一步寻路方向
		
		switch (vismap[current.row][current.col].dir)
		{
		case tup:	
			next.row--;//移动点坐标
			vismap[current.row][current.col].dir++;//当前方向已寻找，准备下一个方向
			if (map[next.row][next.col] == 0 && vismap[next.row][next.col].vis == false)
			{
				//如果下一步是可行走路径（0）且未被访问过（vis==false）
				current = next;//则走到下一步
				vismap[current.row][current.col].vis = true;//标记当前点为已访问
				stack.push(current);//入栈保存当前现场
				
			}
			break;
		case tdown:
			next.row++;
			vismap[current.row][current.col].dir++;//当前方向已寻找，准备下一个方向
			if (map[next.row][next.col] == 0 && vismap[next.row][next.col].vis == false)
			{
				//如果下一步是可行走路径（0）且未被访问过（vis==false）
				current = next;//则走到下一步
				vismap[current.row][current.col].vis = true;//标记当前点为已访问
				stack.push(current);//入栈保存当前现场
				
			}
			break;
		case tleft:	
			next.col--;
			vismap[current.row][current.col].dir++;//当前方向已寻找，准备下一个方向
			if (map[next.row][next.col] == 0 && vismap[next.row][next.col].vis == false)
			{
				//如果下一步是可行走路径（0）且未被访问过（vis==false）
				current = next;//则走到下一步
				vismap[current.row][current.col].vis = true;//标记当前点为已访问
				stack.push(current);//入栈保存当前现场
				
			}
			break;
			
			//前三个方向逻辑为“能走则走到下一步，不能走则换到下一个寻路方向”
			//最后一个方向的逻辑为“能走则走到下一步，不能走则说明此处为死路，不再换到下一个方向”

		case tright:
			next.col++;
			
			if (map[next.row][next.col] == 0 && vismap[next.row][next.col].vis == false)
			{
				//如果下一步是可行走路径（0）且未被访问过（vis==false）
				current = next;//则走到下一步
				vismap[current.row][current.col].vis = true;//标记当前点为已访问
				stack.push(current);//入栈保存当前现场
			
			}
			else {//死路，需要回溯读档
				stack.pop();
				current = stack.gettop();
			}
			break;
		
		default:
			break;
		}
		if (current.row == endpoint.row && current.col == endpoint.col) {
			successfind = true;
			flag = true;
			//如果当前点就是终点，则寻路成功，结束寻找
		}
		if (stack.empty())flag = true;//如果最终为空，则未找到路径，也结束寻找

		if(flag==true)break;
		
	}
	if (successfind == true) {
		
		cout << "成功找到路径:" << endl;
		//路径点都存放在栈中，输出栈中元素即为路径上各个点的坐标
		cout << "起点";
		while (!stack.empty()) {
			map[stack.gettop().row][stack.gettop().col] = 2;
			map[1][1] = 3;
			map[8][8] = 4;
			//为了显示“始”与“终”二字所做的特殊性修改，放在前面设置会产生错误
			showmap(map);
			cout << "(" << stack.gettop().row << "," << stack.gettop().col << ")->";
			stack.pop();
			system("pause");
		}
		cout << "终点" << endl;
	}
	else {
		map[1][1] = 3;
		map[8][8] = 4;
		//为了显示“始”与“终”二字所做的特殊性修改，放在前面设置会产生错误
		showmap(map);
		cout << "未找到路径。" << endl;
	} 
	system("pause");
	return 0;
}