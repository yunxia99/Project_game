#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#define maps_num 35//�ܹ��Ĺؿ�����

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

//����ǰ������

/*
��飺
��ʼ������
������
����ֵ��
*/
void init();

/*
��飺
������ѭ��
������
����ֵ��
*/
void mainloop();


/*
��飺
��Ϸѭ��
������
level:��ǰ��Ϸ���еĹؿ�
����ֵ��
reValue:��ѭ���ĳ���
*/
int gameloop(int level);
int gameloop1(int level);

/*
��飺
��ȡ��Ϸ��ͼ
������
level:Ҫ��ȡ�Ĺؿ�
����ֵ��
*/
Map* LoadMap(int level);
Map* EditMap(int level);
