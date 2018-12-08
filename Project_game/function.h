#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#define maps_num 35//总共的关卡数量

typedef struct Map {

	char map[50][50];
	int level;
	int h;

	int x;
	int y;

	int aim_count;
	int aimx[50];
	int aimy[50];
	int last_x, last_y;
	int box_x, box_y, box_nx,box_ny;
	int edit_x, edit_y;
	int edit_nx, edit_ny;
	
}Map;

//函数前置声明

/*
简介：
初始化程序
参数：
返回值：
*/
void init();

/*
简介：
主界面循环
参数：
返回值：
*/
void mainloop();


/*
简介：
游戏循环
参数：
level:当前游戏进行的关卡
返回值：
reValue:主循环的场景
*/
int gameloop(int level);
int gameloop1(int level);

/*
简介：
读取游戏地图
参数：
level:要读取的关卡
返回值：
*/
Map* LoadMap(int level);
Map* EditMap(int level);
