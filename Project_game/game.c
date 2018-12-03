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

	//init

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	int cheat = 0;

	char cheat1[10];

	//主界面
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
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    返回(ESC)  |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};


	while (1)
	{

		//render
		system("cls");//清空屏幕
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 11; i++)
				puts(main_interface[i]);
			break;
		case 1:
			for (int i = 0; i < 11; i++)
				puts(menu2[i]);
			break;
		default:
			break;
		}


		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'S':
			case 's':
				scenes = 1;
				break;
			case 27:

				isEnd = 1;
				break;
			default:
				break;
			}
			break;
		case 1://处理主场景2
			switch (key)
			{
			case 'A':
			case 'a':
				gameloop(1);
				
				break;
			case 27:
				scenes = 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


		//update
		switch (scenes)
		{
		case 0:

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	}


	//clear

}


int gameloop(int level) {

	//init
	int x = 0;
	int y = 0;

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	int cheat = 0;

	char cheat1[10];
	int root = 0;
	

	Map *map;
	map = LoadMap(level);
	x = map->x;
	y = map->y;

	while (1)
	{

		//render
		system("cls");//清空屏幕
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < map->h; i++)
				puts(map->map[i]);
			break;
		case 1:
			printf("good game!");
			break;
		case 2:
			//打印关卡选择界面
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t");
			printf("请选择关卡(1-%d):%d", maps_num, level);
			break;
		default:
			break;
		}


		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'W':
			case 'w':
				switch (map->map[y - 1][x])
				{
				case ' ':
				case 'X':
					
					map->map[y - 1][x] = '@';
					map->map[y][x] = ' ';
					y = y - 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y - 2][x] != '#'&&map->map[y - 2][x] != 'O'&&map->map[y - 2][x] != 'Q') {
						if (map->map[y - 2][x] == 'X')
							map->map[y - 2][x] = 'Q';
						else
							map->map[y - 2][x] = 'O';
						map->map[y - 1][x] = '@';
						map->map[y][x] = ' ';
						y = y - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'S':
			case 's':

				switch (map->map[y + 1][x])
				{
				case ' ':
				case 'X':
					map->map[y + 1][x] = '@';
					map->map[y][x] = ' ';
					y = y + 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y + 2][x] != '#'&&map->map[y + 2][x] != 'O'&&map->map[y + 2][x] != 'Q') {
						if (map->map[y + 2][x] == 'X')
							map->map[y + 2][x] = 'Q';
						else
							map->map[y + 2][x] = 'O';

						map->map[y + 1][x] = '@';
						map->map[y][x] = ' ';
						y = y + 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'A':
			case 'a':
				switch (map->map[y][x - 1])
				{
				case ' ':
				case 'X':
					map->map[y][x - 1] = '@';
					map->map[y][x] = ' ';
					x = x - 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y][x - 2] != '#'&&map->map[y][x - 2] != 'O'&&map->map[y][x - 2] != 'Q') {
						if (map->map[y][x - 2] == 'X')
							map->map[y][x - 2] = 'Q';
						else
							map->map[y][x - 2] = 'O';
						map->map[y][x - 1] = '@';
						map->map[y][x] = ' ';
						x = x - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'D':
			case 'd':
				switch (map->map[y][x + 1])
				{
				case ' ':
				case 'X':
					map->map[y][x + 1] = '@';
					map->map[y][x] = ' ';
					x = x + 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y][x + 2] != '#'&&map->map[y][x + 2] != 'O'&&map->map[y][x + 2] != 'Q') {
						if (map->map[y][x + 2] == 'X')
							map->map[y][x + 2] = 'Q';
						else
							map->map[y][x + 2] = 'O';
						map->map[y][x + 1] = '@';
						map->map[y][x] = ' ';
						x = x + 1;
					}
					break;

				default:
					break;
				}
				break;
			
				//重置关卡
			case 'R':
			case'r':
				scenes = 0;
				map = LoadMap(map->level);
				x = map->x;
				y = map->y;

				break;
			case 27:
				scenes = 1;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (key)
			{
			case 'R':
			case'r':
				scenes = 0;
				map = LoadMap(map->level);
				x = map->x;
				y = map->y;

				break;
			case 'N':
			case 'n':
				scenes = 0;
				map = LoadMap(map->level + 1);
				x = map->x;
				y = map->y;
				break;
			case 13:
				gets(cheat1);
				if (strcmp(cheat1, "root") == 0) {
					cheat = 1;
				}
				else if (strcmp(cheat1, "fallback") == 0)
					cheat = 2;
				switch (cheat)
				{
				case 1:
					scenes=2;
					break;
				case 2:
					isEnd = 1;
					root = 1;
					break;
				}
				break;

			case 27:
				isEnd = 1;
				break;
			default:
				break;
			}
			break;
			case 2:
				if ((key == 'a') && level > 1)
					level--;
				else if ((key == 'd') && level < maps_num)
					level++;
				else if ((key == 13 || key == 32)) {
					scenes = 0;
					map = LoadMap(level);
					x = map->x;
					y = map->y;
					break;
				}
					
			default:
			break;
		}


		//update
		int isOver = 1;
		switch (scenes)
		{
		case 0:


			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] != 'Q')
					isOver = 0;
			}
			if (isOver)
				scenes = 1;

			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] == ' ')
					map->map[map->aimy[i]][map->aimx[i]] = 'X';
			}//恢复终点的功能

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	
}
	if(root)
		gameloop1(level+1);
   
	//clear



}


int gameloop1(int level) {

	//init
	int x = 0;
	int y = 0;

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	int cheat = 0;

	char cheat1[10];

	int root = 0;

	Map *map;
	map = LoadMap(level);
	x = map->x;
	y = map->y;

	while (1)
	{

		//render
		system("cls");//清空屏幕
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < map->h; i++)
				puts(map->map[i]);
			break;
		case 1:
			printf("good game!");
			break;
		case 2:
			//打印关卡选择界面
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t");
			printf("请选择关卡(1-%d):%d", maps_num, level);
			break;
		default:
			break;
		}


		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'W':
			case 'w':
				switch (map->map[y - 1][x])
				{
				case ' ':
				case 'X':
					map->last_x = x;
					map->last_y = y;
					map->map[y - 1][x] = '@';
					map->map[y][x] = ' ';
					y = y - 1;
					break;
				case 'O':
				case 'Q':
					map->last_x = x;
					map->last_y = y;
					if (map->map[y - 2][x] != '#'&&map->map[y - 2][x] != 'O'&&map->map[y - 2][x] != 'Q') {
						if (map->map[y - 2][x] == 'X')
							map->map[y - 2][x] = 'Q';
						else
							map->map[y - 2][x] = 'O';
						map->map[y - 1][x] = '@';
						map->map[y][x] = ' ';
						y = y - 1;
						map->box_x = x;
						map->box_y = y;
						map->box_nx = x;
						map->box_ny = y - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'S':
			case 's':
				
				switch (map->map[y + 1][x])
				{
				case ' ':
				case 'X':
					map->last_x = x;
					map->last_y = y;
					map->map[y + 1][x] = '@';
					map->map[y][x] = ' ';
					y = y + 1;
					break;
				case 'O':
				case 'Q':
					map->last_x = x;
					map->last_y = y;
					if (map->map[y + 2][x] != '#'&&map->map[y + 2][x] != 'O'&&map->map[y + 2][x] != 'Q') {
						if (map->map[y + 2][x] == 'X')
							map->map[y + 2][x] = 'Q';
						else
							map->map[y + 2][x] = 'O';

						map->map[y + 1][x] = '@';
						map->map[y][x] = ' ';
						y = y + 1;
						map->box_x = x;
						map->box_y = y;
						map->box_nx = x;
						map->box_ny = y + 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'A':
			case 'a':
				
				switch (map->map[y][x - 1])
				{
				case ' ':
				case 'X':
					map->last_x = x;
					map->last_y = y;
					map->map[y][x - 1] = '@';
					map->map[y][x] = ' ';
					x = x - 1;
					break;
				case 'O':
				case 'Q':
					map->last_x = x;
					map->last_y = y;
					if (map->map[y][x - 2] != '#'&&map->map[y][x - 2] != 'O'&&map->map[y][x - 2] != 'Q') {
						if (map->map[y][x - 2] == 'X')
							map->map[y][x - 2] = 'Q';
						else
							map->map[y][x - 2] = 'O';
						map->map[y][x - 1] = '@';
						map->map[y][x] = ' ';
						x = x - 1;
						map->box_x = x;
						map->box_y = y;
						map->box_nx = x - 1;
						map->box_ny = y;
					}
					break;
				default:
					break;
				}

				break;
			case 'D':
			case 'd':
				
				switch (map->map[y][x + 1])
				{
				case ' ':
				case 'X':
					map->last_x = x;
					map->last_y = y;
					map->map[y][x + 1] = '@';
					map->map[y][x] = ' ';
					x = x + 1;
					break;
				case 'O':
				case 'Q':
					map->last_x = x;
					map->last_y = y;
					if (map->map[y][x + 2] != '#'&&map->map[y][x + 2] != 'O'&&map->map[y][x + 2] != 'Q') {
						if (map->map[y][x + 2] == 'X')
							map->map[y][x + 2] = 'Q';
						else
							map->map[y][x + 2] = 'O';
						map->map[y][x + 1] = '@';
						map->map[y][x] = ' ';
						x = x + 1;
						map->box_x = x;
						map->box_y = y;
						map->box_nx = x + 1;
						map->box_ny = y;
					}
					break;

				default:
					break;
				}
				break;
			case'u':
			case'U':
				map->map[y][x] = ' ';
				x = map->last_x;
				y = map->last_y;
				map->map[y][x] = '@';
				map->map[map->box_y][map->box_x] = 'O';
				map->map[map->box_ny][map->box_nx] = ' ';
				break;
				//重置关卡
			case 'R':
			case'r':
				scenes = 0;
				map = LoadMap(map->level);
				x = map->x;
				y = map->y;

				break;
			case 27:

				scenes = 1;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (key)
			{
			case 'R':
			case'r':
				scenes = 0;
				map = LoadMap(map->level);
				x = map->x;
				y = map->y;

				break;
			case 'N':
			case 'n':
				scenes = 0;
				map = LoadMap(map->level + 1);
				x = map->x;
				y = map->y;
				break;
			case 13:
				gets(cheat1);
				if (strcmp(cheat1, "root") == 0) 
					cheat = 1;
				else if(strcmp(cheat1, "cancel")==0)
					cheat=2;
				switch (cheat)
				{
				case 1:
					scenes = 2;
					break;
				case 2:
					isEnd = 1;
					root = 1;
				}
				break;

			case 27:
				isEnd= 1;
				break;
			default:
				break;
			}
			break;
		case 2:
			if ((key == 'a') && level > 1)
				level--;
			else if ((key == 'd') && level < maps_num)
				level++;
			else if ((key == 13 || key == 32)) {
				scenes = 0;
				map = LoadMap(level);
				x = map->x;
				y = map->y;
				break;
			}

		default:
			break;
		}


		//update
		int isOver = 1;
		switch (scenes)
		{
		case 0:


			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] != 'Q')
					isOver = 0;
			}
			if (isOver)
				scenes = 1;

			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] == ' ')
					map->map[map->aimy[i]][map->aimx[i]] = 'X';
			}//恢复终点的功能

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	}
	if(root)
	gameloop(level);

	//clear



}

Map* LoadMap(int level) {

	Map *temp = (Map*)malloc(sizeof(Map));
	char buffer[256];

	FILE *fp;
	sprintf(buffer, "data/Map/%d.txt", level);
	fp = fopen(buffer, "r");

	temp->level = level;
	temp->aim_count = 0;

	for (int i = 0;; i++) {//循环读取文件内容，直到达到退出条件
		fgets(temp->map[i], 256, fp);//读取一行字符串

		temp->map[i][strlen(temp->map[i]) - 1] = '\0';//在字符串末尾手动加上结束符'\0'

		for (int j = 0; temp->map[i][j] != '\0'; j++) {
			switch (temp->map[i][j]) {
			case '@':
				temp->x = j;
				temp->y = i;
				break;
			case 'X':
			case 'Q':
				temp->aimx[temp->aim_count] = j;
				temp->aimy[temp->aim_count] = i;

				temp->aim_count++;
				break;
			}

		}

		if (temp->map[i][1] == '|') {//当字符串第二位出现'|'时表示该行为最后一行，文件读取结束
			temp->map[i][1] = '=';//将该位字符设置为'='
			temp->h = i + 1;
			break;//跳出循环
		}
	}

	fclose(fp);
	return temp;
}