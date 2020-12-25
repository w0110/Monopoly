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

void map(char player1[25], char player2[25], char player3[25], char player4[25], int land_value[25], int level[25], int pay[25])
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■          ■  水  星  ■  金  星  ■          ■  火  星  ■  木  星  ■  土  星  ■          ■\n");
	printf("■          ■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■地價:%05d■          ■\n", land_value[1], land_value[2], land_value[4], land_value[5], land_value[6]);
	printf("■  起  點  ■等級:L%02d  ■等級:L%02d  ■  機  會  ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■ 小行星帶 ■\n", level[1], level[2], level[4], level[5], level[6]);
	printf("■   →→   ■過路費:%03d■過路費:%03d■          ■過路費:%03d■過路費:%03d■過路費:%03d■          ■\n", pay[1], pay[2], pay[4], pay[5], pay[6]);
	printf("■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■\n", player1[0], player2[0], player3[0], player4[0], player1[1], player2[1], player3[1], player4[1], player1[2], player2[2], player3[2], player4[2], player1[3], player2[3], player3[3], player4[3], player1[4], player2[4], player3[4], player4[4], player1[5], player2[5], player3[5], player4[5], player1[6], player2[6], player3[6], player4[6], player1[7], player2[7], player3[7], player4[7]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■  地  球  ■                                                                      ■  天王星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", land_value[23], land_value[8]);
	printf("■等級:L%02d  ■     press any botton to start(except 0)                              ■等級:L%02d  ■\n", level[23], level[8]);	
	printf("■過路費:%03d■                                                                      ■過路費:%03d■\n", pay[23], pay[8]);	
	printf("■ %c %c %c %c  ■     @ 玩家一:                                                        ■ %c %c %c %c  ■\n", player1[23], player2[23], player3[23], player4[23], player1[8], player2[8], player3[8], player4[8]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  神秘星  ■     # 玩家二:                                                        ■          ■\n");	
	printf("■地價:%05d■                                                                      ■          ■\n", land_value[22]);	
	printf("■等級:L%02d  ■     & 玩家三:                                                        ■  命  運  ■\n", level[22]);	
	printf("■過路費:%03d■                                                                      ■          ■\n", pay[22]);
	printf("■ %c %c %c %c  ■     $ 玩家四:                                                        ■ %c %c %c %c  ■\n", player1[22], player2[22], player3[22], player4[22], player1[9], player2[9], player3[9], player4[9]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■          ■                                                                      ■  海王星  ■\n");	
	printf("■          ■                                                                      ■地價:%05d■\n", land_value[10]);	
	printf("■  命  運  ■                                                                      ■等級:L%02d  ■\n", level[10]);	
	printf("■          ■                                                                      ■過路費:%03d■\n", pay[10]);
	printf("■ %c %c %c %c  ■                                                                      ■ %c %c %c %c  ■\n", player1[21], player2[21], player3[21], player4[21], player1[10], player2[10], player3[10], player4[10]);
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  旺旺星  ■                                                                      ■  駭客星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", land_value[20], land_value[11]);
	printf("■等級:L%02d  ■                                                                      ■等級:L%02d  ■\n", level[20], level[11]);
	printf("■過路費:%03d■                                                                      ■過路費:%03d■\n", pay[20], pay[11]);
	printf("■ %c %c %c %c  ■                                                                      ■ %c %c %c %c  ■\n", player1[20], player2[20], player3[20], player4[20], player1[11], player2[11], player3[11], player4[11]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■          ■  逢甲星  ■  美食星  ■  方塊星  ■          ■  植物星  ■  月  球  ■          ■\n");
	printf("■          ■地價:%05d■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■          ■\n", land_value[18], land_value[17], land_value[16], land_value[14], land_value[13]);
	printf("■ 太空墳場 ■等級:L%02d  ■等級:L%02d  ■等級:L%02d  ■  機  會  ■等級:L%02d  ■等級:L%02d  ■  監  獄  ■\n", level[18], level[17], level[16], level[14], level[13]);
	printf("■          ■過路費:%03d■過路費:%03d■過路費:%03d■          ■過路費:%03d■過路費:%03d■          ■\n", pay[18], pay[17], pay[16], pay[14], pay[13]);
	printf("■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■\n", player1[19], player2[19], player3[19], player4[19], player1[18], player2[18], player3[18], player4[18], player1[17], player2[17], player3[17], player4[17], player1[16], player2[16], player3[16], player4[16], player1[15], player2[15], player3[15], player4[15], player1[14], player2[14], player3[14], player4[14], player1[13], player2[13], player3[13], player4[13], player1[12], player2[12], player3[12], player4[12]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");	
}
//主程式 
int main()		
{
	int enter;	//主畫面輸入選項 
	int check2, check3;
	int land_value[24] = {0}, pay[24] = {0}, level[25];	//地價、過路費、等級 
	char player1[25] = {0}, player2[25] = {0}, player3[25] = {0}, player4[25] = {0};	//控制輸出骰子圖案 
	int player1_check[25] = {0}, player2_check[25] = {0}, player3_check[25] = {0}, player4_check[25] = {0};		//控制輸出骰子 
	int i;
	char n;
	int die = 0, move1 = 0, move2 = 0, move3 = 0, move4 = 0;		//骰子步數、玩家一移動步數、玩家二移動步數、玩家三移動步數、玩家四移動步數
	
	for(i = 0; i < 25; i++)
	{
		level[i] = 1;
	}
	//初始畫面 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
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
	
	
	if(enter == 1)	//當在主畫面時輸入一 
	{
		system("cls");	//清除畫面
		move1 = move1 + die;	//計算玩家一移動步數 
		player1_check[move1] = 1;	//把要移動到數值 
		for(i = 0; i < 25; i++)
		{
			if(player1_check[i] == 0)
				player1[i] = ' ';
			else
				player1[i] = '@';			
		} 
		
		move2 = move2 + die;
		player2_check[move2] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player2_check[i] == 0)
				player2[i] = ' ';
			else
				player2[i] = '#';			
		} 
		
		move3 = move3 + die;
		player3_check[move3] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player3_check[i] == 0)
				player3[i] = ' ';
			else
				player3[i] = '&';			
		} 
		
		move4 = move4 + die;
		player4_check[move4] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player4_check[i] == 0)
				player4[i] = ' ';
			else
				player4[i] = '$';			
		} 
	}

	map(player1, player2, player3, player4, land_value, level, pay);
	for(i = 0; i < 25; i++)
	{
		player1_check[i] = 0;	//player1歸零 
	}
	scanf("%*c%c", &n);
	die = dice(n);
	move1 = move1 + die;
	player1_check[move1] = 1;
	for(i = 0; i < 25; i++)
	{
		if(player1_check[i] == 0)
			player1[i] = ' ';
		else
			player1[i] = '@';
	}
	scanf("%c", &n);	
	system("cls");
	map(player1, player2, player3, player4, land_value, level, pay);		//player1移動 
	
	for(i = 0; i < 25; i++)
	{
		player2_check[i] = 0;	//player2歸零
	}
	scanf("%c", &n);
	die = dice(n);
	move2 = move2 + die;
	player2_check[move2] = 1;
	for(i = 0; i < 25; i++)
	{
		if(player2_check[i] == 0)
			player2[i] = ' ';
		else
			player2[i] = '#';
	}
	scanf("%c", &n);	
	system("cls");
	map(player1, player2, player3, player4, land_value, level, pay);		//player2移動 
	
	for(i = 0; i < 25; i++)
	{
		player3_check[i] = 0;	//player3歸零
	}
	scanf("%c", &n);
	die = dice(n);
	move3 = move3 + die;
	player3_check[move3] = 1;
	for(i = 0; i < 25; i++)
	{
		if(player3_check[i] == 0)
			player3[i] = ' ';
		else
			player3[i] = '&';
	}
	scanf("%c", &n);	
	system("cls");
	map(player1, player2, player3, player4, land_value, level, pay);		//player3移動 
	
	for(i = 0; i < 25; i++)
	{
		player4_check[i] = 0;	//player4歸零
	}
	scanf("%c", &n);
	die = dice(n);
	move4 = move4 + die;
	player4_check[move4] = 1;
	for(i = 0; i < 25; i++)
	{
		if(player4_check[i] == 0)
			player4[i] = ' ';
		else
			player4[i] = '$';
	}
	scanf("%c", &n);	
	system("cls");
	map(player1, player2, player3, player4, land_value, level, pay);		//player4移動 */
	
	
	if(enter == 0 || check2 == 0 || check3 == 0)	//當在初始畫面輸入0或在成員名單頁輸入0或在規則頁輸入0 離開遊戲 
		return 0;
	
}
