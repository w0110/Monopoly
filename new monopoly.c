#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h>
#include <windows.h> 

// 宣告函式  
int dice(char a);
void map(char player1[25], char player2[25], char player3[25], char player4[25], int land_value[25], int level[25], int pay[25], int money1, int money2, int money3, int money4);
int manu(int n); 
int special_land(int move, int money);
int rule(int n);
int teamMember(int n);
void end(int);

/*struct Player emplacement(struct Player player,int die) {
	if(player.move){	//如果現在不能動，離開此函式，下一局恢復能動
		player.move=0
		return player;
	}
	player.location= player.location+ dice_num;
	if(player.location>24) {
		player.location=player.location-24;
	}
	switch(player.location) {
		case 0:	//起點
			break;
		case 3:	
		case 7:
		case 9:	
		case 12: //監獄
			player.move=1; 
			break;
		case 15: //機會
			break;
		case 19:	//轉角 
			break;
		case 21: 	//命運
			break;
		default://其他正常地點
			//你買過房子嗎？ 
			//有沒有人買房，要不要過路費 
			//如果沒有人買房要不要買 
			//買過的要不要升級 
			
			break;
	}
}

void place(int num) {
	char ans;
	if(map[num].owner! = player.realty) {//不是自己的地 
		if(map[num].owner == 0) {//無主之地
			printf("要不要在這裡買房子？");
			scanf("%c",&ans);
			if(ans=='Y' || ans=='y'){
				map[num].own=1;
				map[num].owner=player.realty;
				player.money=player.money-map[num].price;
			}
		}
		else{
			//扣過路費
			player.money=player.money-map[num].tolls;	
		}
	}
	else{
		if(map[num].level!=3){
			printf("要不要升級？");
			scanf("%c",&ans);
			if(ans=='Y' || ans=='y'){
				map[num].level++;
				player.money=player.money-map[num].exp;
			}
		}
		
	}
}*/



//菜單畫面
int manu(int n) 
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
	if (enter == 1)
	{
		return 1;
	}
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
	if(enter == 0)
		end(enter);
	return enter;
}

//骰子
int dice(char a)	 
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

//機會命運 
int special_land(int move, int money){
	int num;	//機會命運編號  
	char a;  
	
	if(move == 3 || move == 15){	//機會 
		scanf("%*c");
		printf("+--------+\n");
		printf("|        |\n");
		printf("|   機   |\n");
		printf("|        |\n");
		printf("|   會   |\n");
		printf("|        |\n");		
		printf("+--------+\n");
		scanf("%*c");
		srand(time(NULL));
		num = rand() % 3 + 1;	//編號 (1-3)
		switch(num) {
			case 1:
				printf("內容: 骰到 3 以上的的數字獲得 2000 元\n");
				scanf("%c", &a); 
				if(dice(a) >= 3) {
					money = money + 2000;
				}
				return money;
				break;
			case 2:
				printf("內容: 支付太空船燃料費用 1000 元\n");
				money = money - 1000;
				return money;
				break;
			case 3:
				printf("內容: 投資股票獲利，獲得 1000 元\n");
				money = money + 1000;
				return money;
				break;		
		}
	}
	else if(move == 9 || move == 21) {    //命運 
		scanf("%*c");
		printf("+--------+\n");
		printf("|        |\n");
		printf("|   命   |\n");
		printf("|        |\n");
		printf("|   運   |\n");
		printf("|        |\n");		
		printf("+--------+\n");	
		scanf("%*c");	
		srand(time(NULL));
		num = rand() % 3 + 1;	//編號 (1-3)
		switch(num){
			case 1:
				printf("內容: 遭到外星人攻擊，損失 2000 元\n");
				money = money - 2000;
				return money;
				break;
			case 2:
				printf("內容: 半路上意外撿到 1000 元\n");
				money = money + 1000;
				return money;
				break;
			case 3:
				printf("內容: 退回起點\n");
				move = 0;
				return move;
				break;		
		}
	}
}

//成員名單 
int teamMember(int n)	
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
	if(enter == 0)
		end(enter);
	return enter;
}

//遊戲規則
int rule(int n)		 
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
	if(enter == 0)
		end(enter);
	return enter;
}

//結束畫面
void end(int enter)
{
	char n;
	system("cls");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■               ■■■■■  ■    ■      ■■      ■    ■  ■   ■    ■■■                ■\n");
	printf("■                   ■      ■    ■     ■  ■     ■■  ■  ■ ■     ■                     ■\n");
	printf("■                   ■      ■■■■    ■■■■    ■ ■ ■  ■■       ■■■                ■\n");	
	printf("■                   ■      ■    ■   ■      ■   ■  ■■  ■  ■          ■               ■\n");
	printf("■                   ■      ■    ■  ■        ■  ■   ■   ■    ■   ■■■                ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■          	                                                                                ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                  ■■■    ■■    ■■■■                                  ■\n");
	printf("■                                  ■      ■    ■  ■     ■                                 ■\n");
	printf("■                                  ■■■  ■    ■  ■■■■                                  ■\n");
	printf("■                                  ■      ■    ■  ■  ■                                    ■\n");
	printf("■                                  ■        ■■    ■    ■                                  ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■           ■■■   ■          ■■      ■    ■  ■■■■■   ■   ■   ■■■             ■\n");
	printf("■          ■    ■  ■         ■  ■      ■  ■       ■      ■■  ■  ■                  ■\n");
	printf("■           ■■■   ■        ■■■■      ■■        ■      ■ ■ ■  ■   ■■           ■\n");
	printf("■          ■        ■       ■      ■      ■         ■      ■  ■■  ■    ■■          ■\n");
	printf("■          ■        ■■■  ■        ■     ■     ■■■■■  ■   ■    ■■■ ■          ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	scanf("%c", &n);
		exit(0);
} 

//地圖 
void map(char player1[25], char player2[25], char player3[25], char player4[25], int land_value[25], int level[25], int pay[25], int money1, int money2, int money3, int money4)
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
	printf("■ %c %c %c %c  ■     @ 玩家一:目前金額%05d                                           ■ %c %c %c %c  ■\n", player1[23], player2[23], player3[23], player4[23], money1, player1[8], player2[8], player3[8], player4[8]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  神秘星  ■     # 玩家二:目前金額%05d                                           ■          ■\n", money2);	
	printf("■地價:%05d■                                                                      ■          ■\n", land_value[22]);	
	printf("■等級:L%02d  ■     & 玩家三:目前金額%05d                                           ■  命  運  ■\n", level[22], money3);	
	printf("■過路費:%03d■                                                                      ■          ■\n", pay[22]);
	printf("■ %c %c %c %c  ■     $ 玩家四:目前金額%05d                                           ■ %c %c %c %c  ■\n", player1[22], player2[22], player3[22], player4[22], money4, player1[9], player2[9], player3[9], player4[9]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■          ■                                                                      ■  海王星  ■\n");	
	printf("■          ■                                                                      ■地價:%05d■\n", land_value[10]);	
	printf("■  命  運  ■                                                                      ■等級:L%02d  ■\n", level[10]);	
	printf("■          ■                                                                      ■過路費:%03d■\n", pay[10]);
	printf("■ %c %c %c %c  ■                                 →Pause the game please enter 1      ■ %c %c %c %c  ■\n", player1[21], player2[21], player3[21], player4[21], player1[10], player2[10], player3[10], player4[10]);
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  旺旺星  ■                                 →Restart the game please enter 2    ■  駭客星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", land_value[20], land_value[11]);
	printf("■等級:L%02d  ■                                 →Want to leave please enter 0       ■等級:L%02d  ■\n", level[20], level[11]);
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
	int enter, result;	//主畫面輸入選項， result : 結果	 
	int land_value[24] = {0}, pay[24] = {0}, level[25];	//地價、過路費、等級 
	char player1[25] = {0}, player2[25] = {0}, player3[25] = {0}, player4[25] = {0};	//控制輸出骰子圖案 
	int player1_check[25] = {0}, player2_check[25] = {0}, player3_check[25] = {0}, player4_check[25] = {0};		//控制輸出骰子 
	int i;
	int check1, check2, check3, check4, num1, num2, num3, num4;	// check: 判斷監獄， num: 第一次進監獄印出的內容   
	int money1, money2, money3, money4;
	char n;
	int die = 0, move1 = 0, move2 = 0, move3 = 0, move4 = 0;		//骰子步數、玩家一移動步數、玩家二移動步數、玩家三移動步數、玩家四移動步數
	int tmcheck, start1;
	//把 level 初始化為 1 
	for(i = 0; i < 25; i++)
	{
		level[i] = 1;
	}
	// 所有人剛開始皆有 10000 元  
	money1 = money2 = money3 = money4 = 10000;
	
	check1 = check2 = check3 = check4 = 1;
	num1 = num2 = num3 = num4 = 1;
	
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

	if(enter == 1 || start1 == 1)	//當在主畫面時輸入一 
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
	if(enter == 2)
	{
		system("cls");	//清除畫面
		tmcheck = teamMember(enter);
	}
	if(enter == 3)
	{
		system("cls");
		rule(enter);
	}
	if(enter == 0)			//結束遊戲 
		end(enter);
	map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	//印出地圖 
	
	
	
/////////////////////
	
	
	while(scanf("%c", &n))
	{
		for(i = 0; i < 25; i++)
		{
			player1_check[i] = 0;	// player1 歸零 
		}
		//scanf("%*c");
		if(check1 == 1) {
			scanf("%c", &n);
			die = dice(n);
			printf("player1 move: %d", die);
			move1 = move1 + die;
			if(move1 == 12) {	//監獄 
				num1 = 1;
				check1 = 0;
			}
			else if(move1 >= 24) { 	//起點  
				move1 = move1 - 24;	   //超過 24 重新計算	 
				// player1 移動 
				player1_check[move1] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player1_check[i] == 0)
						player1[i] = ' ';
					else
						player1[i] = '@';
				}
				scanf("%*c", &n);	
				system("cls");
				map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4); 			
				 
				printf("\n內容: 通過起點加 1000 元\n");
				money1 = money1 + 1000; 
				printf("%d\n", money1);		//測試  
			}	
		}
		else{
			if(num1 == 0){
				printf("\n骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");
			} 
			printf("\n-----\n");	//測試  
			scanf("%c", &n);
			if(dice(n) % 2 == 0){
				printf("偶數，下回合可以開始移動\n");
				check1 = 1;
			}
			else{
				printf("奇數，下回合無法移動，請繼續骰骰子\n");
				num1 = 0;
				check1 = 0;
			}
		}	
		// player1 移動						
		player1_check[move1] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player1_check[i] != 1)
				player1[i] = ' ';
			else
				player1[i] = '@';
		}
		scanf("%*c", &n);	
		system("cls");
		map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	
		
		//特殊地形  
		if(move1 == 3 || move1 == 9 || move1 == 15 || move1 == 21){		//機會命運  
			result = special_land(move1, money1);
			if(result != 0){
				money1 = result;
				printf("%d\n", money1);		//測試 	
			}
			else{
				move1 = result;
				player1_check[move1] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player1_check[i] != 1)
						player1[i] = ' ';
					else
						player1[i] = '@';
				}			
			}
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);							
		}
		else if(move1 == 12 && check1 == 0 && num1 == 1){		//監獄  
			printf("\n內容: 下次自己回合時需骰骰子，骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");				
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	
		}

///////////////
	
		for(i = 0; i < 25; i++)
		{
			player2_check[i] = 0;	// player2 歸零 
		}
		//scanf("%*c");
		if(check2 == 1){
			scanf("%c", &n);
			die = dice(n);
			printf("player2 move: %d", die);
			move2 = move2 + die;
			if(move2 == 12){	//監獄 
				num2 = 1;
				check2 = 0;
			}
			else if(move2 >= 24){ 	//起點  
				move2 = move2 - 24;	   //超過 24 重新計算	 
				// player2 移動 
				player2_check[move2] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player2_check[i] == 0)
						player2[i] = ' ';
					else
						player2[i] = '#';
				}
				scanf("%*c", &n);	
				system("cls");
				map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4); 			
				 
				printf("\n內容: 通過起點加 1000 元\n");
				money2 = money2 + 1000; 
				printf("%d\n", money2);		//測試  
			}	
		}
		else{
			if(num2 == 0){
				printf("\n骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");
			} 
			printf("\n-----\n");	//測試  
			scanf("%c", &n);
			if(dice(n) % 2 == 0){
				printf("偶數，下回合可以開始移動\n");
				check2 = 1;
			}
			else{
				printf("奇數，下回合無法移動，請繼續骰骰子\n");
				num2 = 0;
				check2 = 0;
			}
		}	
		// player2 移動						
		player2_check[move2] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player2_check[i] != 1)
				player2[i] = ' ';
			else
				player2[i] = '#';
		}
		scanf("%*c", &n);	
		system("cls");
		map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);
		
		//特殊地形  
		if(move2 == 3 || move2 == 9 || move2 == 15 || move2 == 21){		//機會命運  
			result = special_land(move2, money2);
			if(result != 0){
				money2 = result;
				printf("%d\n", money2);		//測試 	
			}
			else{
				move2 = result;
				player2_check[move2] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player2_check[i] != 1)
						player2[i] = ' ';
					else
						player2[i] = '#';
				}			
			}
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);							
		}
		else if(move2 == 12 && check2 == 0 && num2 == 1){		//監獄  
			printf("\n內容: 下次自己回合時需骰骰子，骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");				
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	
		}	

	///////////////////	
		
		for(i = 0; i < 25; i++)
		{
			player3_check[i] = 0;	// player3 歸零 
		}
		//scanf("%*c");
		if(check3 == 1){
			scanf("%c", &n);
			die = dice(n);
			printf("player3 move: %d", die);
			move3 = move3 + die;
			if(move3 == 12){	//監獄 
				num3 = 1;
				check3 = 0;
			}
			else if(move3 >= 24){ 	//起點  
				move3 = move3 - 24;	   //超過 24 重新計算	 
				// player3 移動 
				player3_check[move3] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player3_check[i] == 0)
						player3[i] = ' ';
					else
						player3[i] = '&';
				}
				scanf("%*c", &n);	
				system("cls");
				map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4); 			
				 
				printf("\n內容: 通過起點加 1000 元\n");
				money3 = money3 + 1000; 
				printf("%d\n", money3);		//測試  
			}	
		}
		else{
			if(num3 == 0){
				printf("\n骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");
			} 
			printf("\n-----\n");	//測試  
			scanf("%c", &n);
			if(dice(n) % 2 == 0){
				printf("偶數，下回合可以開始移動\n");
				check3 = 1;
			}
			else{
				printf("奇數，下回合無法移動，請繼續骰骰子\n");
				num3 = 0;
				check3 = 0;
			}
		}	
		// player3 移動						
		player3_check[move3] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player3_check[i] != 1)
				player3[i] = ' ';
			else
				player3[i] = '&';
		}
		scanf("%*c", &n);	
		system("cls");
		map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);
		
		//特殊地形  
		if(move3 == 3 || move3 == 9 || move3 == 15 || move3 == 21){		//機會命運  
			result = special_land(move3, money3);
			if(result != 0){
				money3 = result;
				printf("%d\n", money3);		//測試 	
			}
			else{
				move3 = result;
				player3_check[move3] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player3_check[i] != 1)
						player3[i] = ' ';
					else
						player3[i] = '&';
				}			
			}
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);							
		}
		else if(move3 == 12 && check3 == 0 && num3 == 1){		//監獄  
			printf("\n內容: 下次自己回合時需骰骰子，骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");				
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	
		} 
		
////////////////////
		
		for(i = 0; i < 25; i++)
		{
			player4_check[i] = 0;	// player4 歸零 
		}
		//scanf("%*c");
		if(check4 == 1){
			scanf("%c", &n);
			die = dice(n);
			printf("player4 move: %d", die);
			move4 = move4 + die;
			if(move4 == 12){	//監獄 
				num4 = 1;
				check4 = 0;
			}
			else if(move4 >= 24){ 	//起點  
				move4 = move4 - 24;	   //超過 24 重新計算	 
				// player4 移動 
				player4_check[move4] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player4_check[i] == 0)
						player4[i] = ' ';
					else
						player4[i] = '$';
				}
				scanf("%*c", &n);	
				system("cls");
				map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);		
				 
				printf("\n內容: 通過起點加 1000 元\n");
				money4 = money4 + 1000; 
				printf("%d\n", money4);		//測試  
			}	
		}
		else{
			if(num4 == 0){
				printf("\n骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");
			} 
			printf("\n-----\n");	//測試  
			scanf("%c", &n);
			if(dice(n) % 2 == 0){
				printf("偶數，下回合可以開始移動\n");
				check4 = 1;
			}
			else{
				printf("奇數，下回合無法移動，請繼續骰骰子\n");
				num4 = 0;
				check4 = 0;
			}
		}	
		// player4 移動						
		player4_check[move4] = 1;
		for(i = 0; i < 25; i++)
		{
			if(player4_check[i] != 1)
				player4[i] = ' ';
			else
				player4[i] = '$';
		}
		scanf("%*c", &n);	
		system("cls");
		map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	
		
		//特殊地形  
		if(move4 == 3 || move4 == 9 || move4 == 15 || move4 == 21){		//機會命運  
			result = special_land(move4, money4);
			if(result != 0){
				money4 = result;
				printf("%d\n", money4);		//測試 	
			}
			else{
				move4 = result;
				player4_check[move4] = 1;
				for(i = 0; i < 25; i++)
				{
					if(player4_check[i] != 1)
						player4[i] = ' ';
					else
						player4[i] = '$';
				}			
			}
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);						
		}
		else if(move4 == 12 && check4 == 0 && num4 == 1){		//監獄  
			printf("\n內容: 下次自己回合時需骰骰子，骰到偶數，再下一回合才可移動 (奇數偶數只是判斷下回合是否可移動)\n");				
			//重新印地圖  
			scanf("%*c", &n);	
			system("cls");
			map(player1, player2, player3, player4, land_value, level, pay, money1, money2, money3, money4);	
		}
	}


	
}
