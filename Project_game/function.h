#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>

#define maps_num 35//�ܹ��Ĺؿ�����

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

/*
��飺
	��ȡ��Ϸ��ͼ
������
	level:Ҫ��ȡ�Ĺؿ�
	map_hight:�洢�ؿ��ĸ߶�
	map:�洢�ؿ��Ķ�ά����
����ֵ��
*/
void LoadMap(int level, char(*map)[50]);
