#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int manu(int n)		//菜單畫面 
{
	int enter;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            Monopoly     MENU                                                                 ■\n");
	printf("■                                                                                              ■\n");
	printf("■         ■■  ■■     ■■     ■   ■    ■■     ■■■     ■■    ■     ■    ■       ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■■  ■  ■    ■  ■    ■  ■    ■  ■      ■  ■        ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■ ■ ■  ■    ■   ■■■   ■    ■  ■       ■■         ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■  ■■  ■    ■  ■        ■    ■  ■        ■          ■\n");
	printf("■        ■  ■■  ■    ■■    ■   ■     ■■    ■          ■■    ■■■    ■          ■\n");
	printf("■           	                                                                                ■\n");
	printf("■                      ■■  ■■     ■■■     ■   ■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■        ■■  ■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■■■    ■ ■ ■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■        ■  ■■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■■■    ■   ■      ■■■                            ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            →Start playing please enter 1                                                    ■\n");
	printf("■                                                                                              ■\n");	
	printf("■            →Check who made this game please enter 2                                         ■\n");
	printf("■                                                                                              ■\n");
	printf("■            →How to play please enter 3                                                      ■\n");
	printf("■                                                                                              ■\n");	
	printf("■            →Want to leave please enter 0                                                    ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	scanf("%d", &enter);
	if(enter == 2)
	{
		system("cls");	//清除畫面 
		teamMember(enter);
	}
	if(enter == 3)
	{
		system("cls");	//清除畫面 
		rule(enter);
	}

	return enter;
}

int dice(char a)	//骰子 
{
	srand(time(NULL)); //產生亂數，參數以目前的時間傳入
	int die = 1 + rand() % 6;//有六個數，從一開始(1~6)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
	printf("■■■■■■■\n");
	switch(die)
	{
		case 1:
			printf("■          ■\n");
			printf("■          ■\n");
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 1;
		case 2:
			printf("■          ■\n");
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 2;
		case 3:
			printf("■          ■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 3;
		case 4:
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 4;
		case 5:
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 5;
		case 6:
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 6;
	}	
	printf("%d", die);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
}

int teamMember(int n)	//成員名單 
{
	int enter;
	int check;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            Monopoly                                                                          ■\n");
	printf("■                                                                                              ■\n");
	printf("■           	                                                                                ■\n");
	printf("■            製 作 成 員 :                                                                     ■\n");
	printf("■                                                                                              ■\n");	
	printf("■                  §D0915696黃湘紜                                                             ■\n");
	printf("■                                                                                              ■\n");	
	printf("■                  §D0915725賴螢葶                                                             ■\n");
	printf("■                                                                                              ■\n");
	printf("■          	    §D0948329陳昕伶                                                             ■\n");
	printf("■                                                                                              ■\n");
	printf("■          	    §D0948524陳彥勻                                                             ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            §製作日期 : 2020 / 12 / 5 ~                                                       ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                          →Back to menu please enter 1       ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                          →Want to leave please enter 0      ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	scanf("%d", &enter); 
	if(enter == 1)
	{
		system("cls");	//清除畫面 
		check = manu(enter);	//回到菜單 
		if(check == 0)
			return 0;
	}
	return enter;
}

int rule(int n)		//遊戲規則 
{
	int enter;
	int check;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            Monopoly   RULE                                                                   ■\n");
	printf("■                                                                                              ■\n");
	printf("■           	                                                                                ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■          	                                                                                ■\n");
	printf("■                                                                                              ■\n");
	printf("■          	                                                                                ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                          →Back to menu please enter 1       ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                          →Want to leave please enter 0      ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	scanf("%d", &enter); 
	if(enter == 1)
	{
		system("cls");	//清除畫面 
		check = manu(enter);	//回到菜單 
		if(check == 0)
			return 0;
	}
	return enter;
}

int main()		//主程式 
{
	int enter;
	int check2, check3;
	//初始畫面 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            Monopoly     MENU                                                                 ■\n");
	printf("■                                                                                              ■\n");
	printf("■         ■■  ■■     ■■     ■   ■    ■■     ■■■     ■■    ■     ■    ■       ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■■  ■  ■    ■  ■    ■  ■    ■  ■      ■  ■        ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■ ■ ■  ■    ■   ■■■   ■    ■  ■       ■■         ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■  ■■  ■    ■  ■        ■    ■  ■        ■          ■\n");
	printf("■        ■  ■■  ■    ■■    ■   ■     ■■    ■          ■■    ■■■    ■          ■\n");
	printf("■           	                                                                                ■\n");
	printf("■                      ■■  ■■     ■■■     ■   ■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■        ■■  ■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■■■    ■ ■ ■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■        ■  ■■    ■    ■                           ■\n");
	printf("■                     ■  ■■  ■    ■■■    ■   ■      ■■■                            ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            →Start playing please enter 1                                                    ■\n");
	printf("■                                                                                              ■\n");	
	printf("■            →Check who made this game please enter 2                                         ■\n");
	printf("■                                                                                              ■\n");	
	printf("■            →How to play please enter 3                                                      ■\n");
	printf("■                                                                                              ■\n");
	printf("■            →Want to leave please enter 0                                                    ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	scanf("%d", &enter);
	
	if(enter == 1)	//輸入1進入遊戲畫面 
	{
		system("cls"); //清除畫面 
		int land_value[24] = {0}, pay[24] = {0};
		char player1[25][2] = {0}, player2[25][2] = {0}, player3[25][2] = {0};
		char n;
		int i, die;
		
		
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("■          ■  水  星  ■  金  星  ■          ■  火  星  ■  木  星  ■  土  星  ■  天王星  ■\n");
		printf("■          ■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■地價:%05d■地價:%05d■\n", land_value[0], land_value[1], land_value[2], land_value[3], land_value[4], land_value[5], land_value[6]);
		printf("■  起  點  ■等級:L%02d  ■等級:L%02d  ■  機  會  ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■\n", 1, 2, 3, 4, 5, 6);
		printf("■   →→   ■過路費:%03d■過路費:%03d■          ■過路費:%03d■過路費:%03d■過路費:%03d■過路費:%03d■\n", pay[0], pay[1], pay[2], pay[3], pay[4], pay[5], pay[6]);
		printf("■          ■ %c       ■ %c         ■ %c         ■ %c         ■ %c         ■ %c         ■ %c        ■\n", player1[0][1], player1[1][1], player1[2][1], player1[3][1], player1[4][1], player1[5][1]);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("■          ■                                                                      ■  海王星  ■\n");
		printf("■地價:%05d■                                                                      ■地價:%05d■\n", land_value[7]);
		printf("■等級:L%02d  ■     press any botton to start(except 0)                              ■等級:L%02d  ■\n");	
		printf("■          ■                                                                      ■--------- ■\n");	
		printf("■          ■     ★玩家一:                                                        ■          ■\n");	
		printf("■■■■■■■                                                                      ■■■■■■■\n");
		printf("■          ■     ⊕玩家二:                                                        ■          ■\n");	
		printf("■地價:%05d■                                                                      ■          ■\n");	
		printf("■等級:L%02d  ■     ◆玩家三:                                                        ■  命  運  ■\n");	
		printf("■          ■                                                                      ■          ■\n");
		printf("■          ■     ▲玩家四:                                                        ■          ■\n");	
		printf("■■■■■■■                                                                      ■■■■■■■\n");
		printf("■          ■                                                                      ■  北極星  ■\n");	
		printf("■地價:%05d■                                                                      ■地價:%05d■\n");	
		printf("■等級:L%02d  ■                                                                      ■等級:L%02d  ■\n");	
		printf("■          ■                                                                      ■--------- ■\n");
		printf("■          ■                                                                      ■          ■\n");
		printf("■■■■■■■                                                                      ■■■■■■■\n");
		printf("■          ■                                                                      ■  天狼星  ■\n");
		printf("■地價:%05d■                                                                      ■地價:%05d■\n");
		printf("■等級:L%02d  ■                                                                      ■等級:L%02d  ■\n");
		printf("■          ■                                                                      ■--------- ■\n");
		printf("■          ■                                                                      ■          ■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("■          ■          ■          ■          ■          ■  冥王星  ■  月  球  ■          ■\n");
		printf("■地價:%05d■地價:%05d■地價:%05d■地價:%05d■地價:%05d■地價:%05d■地價:%05d■          ■\n");
		printf("■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■          ■  監獄    ■\n");
		printf("■          ■          ■          ■          ■          ■          ■          ■          ■\n");
		printf("■          ■          ■          ■          ■          ■          ■          ■          ■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		scanf("%*c%c", &n);
		die = dice(n);
		printf("%d", die);
		player1[die - 1][0] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player1[i][0] == 0)
			{
				player1[i][1] = '   ';
			}
			else
				player1[i][1] = '$';
		}
		if(n == 1)
			system("cls");
	}
	
	else if(enter == 2)	//輸入2查看成員名單 
	{
		system("cls");
		check2 = teamMember(enter);	 
	}	
	else if(enter == 3)	//輸入3查看規則頁 
	{
		system("cls");
		check3 = rule(enter);	 
	}
	
	printf("\n");
	//test by alco99

	
	
	if(enter == 0 || check2 == 0 || check3 == 0)	//當在初始畫面輸入0或在成員名單頁輸入0或在規則頁輸入0 離開遊戲 
		return 0;
	
}
