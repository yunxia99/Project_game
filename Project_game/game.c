#include"function.h"

void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}
void mainloop() {
	int level;//��ǰ�ؿ�
	int level_option;//ѡ��Ĺؿ�
	int scenes;//����
	char option;//����ָ��
	int isEnd;//�Ƿ����

	//��ʼ������
	level = 0;//��ʼ����ǰ�ؿ�Ϊ��һ�أ���0���𣬷�ΧΪ0-maps_num��
	level_option = 1;//��ʼ��ѡ��ؿ�Ϊ��һ�أ���1����
	scenes = 0;//��ʼ������Ϊ������
	isEnd = 0;//��ʼ�������жϱ���Ϊ0��false��

	//��ʼ������
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ��ʼ(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   �˳�(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//���˵�2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   ��ͷ��ʼ(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ѡ��(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ����(R)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};
	while (1) {
		//��ӡ������
		system("cls");
		switch (scenes) {
		case 0:
			for (int i = 0; i < 11; i++)
				puts(main_interface[i]);
			break;
		case 1:
			for (int i = 0; i < 11; i++)
				puts(menu2[i]);
			break;
		case 2:
			//��ӡ�ؿ�ѡ�����
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t");
			printf("��ѡ��ؿ�(1-%d):%d", maps_num, level_option);
			break;
		default:
			break;
		}
		//event
		option = getch();
		switch (scenes) {
		case 0:
			if (option == 's')
				scenes = 1;
			if (option == 27)

				isEnd = 1;

			break;
		case 1:
			if (option == 'r' || option == 27)
				scenes = 0;
			if (option == 'a')
				scenes = 3;
			if (option == 'x')
				scenes = 2;

			

		}
		//isEnd
		if (isEnd) {
			break;
		}
	}

	 
	
	 
	//update

	//render

	

	//clver

}