#include"function.h"

void init() {

	//该段代码功能是隐藏光标，调用了win32编程接口，不需要掌握
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title 推箱子1.0");//设定窗口名称
	system("mode con cols=120 lines=30");//设定窗口大小
}
void mainloop() {
	int level;//当前关卡
	int level_option;//选择的关卡
	int scenes;//场景
	char option;//操作指令
	int isEnd;//是否结束

	//初始化参数
	level = 0;//初始化当前关卡为第一关（从0算起，范围为0-maps_num）
	level_option = 1;//初始化选择关卡为第一关（从1算起）
	scenes = 0;//初始化场景为主界面
	isEnd = 0;//初始化结束判断变量为0（false）

	//初始化界面
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t 推箱子",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    开始(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   退出(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//主菜单2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t 推箱子\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   从头开始(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    选关(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    返回(R)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};
	while (1) {
		//打印主界面
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
			//打印关卡选择界面
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t");
			printf("请选择关卡(1-%d):%d", maps_num, level_option);
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