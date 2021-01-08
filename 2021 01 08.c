#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h>
#include <time.h>
#include <windows.h> 

struct map_initialise {
	char name[10]; //地名 
	int own;  //有沒有人買 
	int owner;  //地主代號 
	int level;  //等級 
	int tolls;  //過路費 
	int price;  //價錢
	int original_price;
};

struct player_initialise {
	int money;  //錢
	int realty;   //玩家代號  
	int move;  //可不可以移動 
	int location;  //現在位置 
	int bankrupt; //破產狀態
	char printOnMap[24];  //顯示在地圖上
	int total;  //
};

int dice();
void map_print(struct map_initialise map[], struct player_initialise player[]);
struct player_initialise chance(struct player_initialise player[],int i);
struct player_initialise fate(struct player_initialise player[],int i);
void countWinner(struct map_initialise map[], struct player_initialise player[]);
void end();


//骰子
int dice()	 
{
	printf("\n請骰骰子\n");
	puts("");
	system("pause");
	puts("");
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

//地圖 
void map_print(struct map_initialise map[], struct player_initialise player[])
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■          ■  水  星  ■  金  星  ■          ■  火  星  ■  木  星  ■  土  星  ■          ■\n");
	printf("■          ■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■地價:%05d■          ■\n", map[1].price, map[2].price, map[4].price, map[5].price, map[6].price);
	printf("■  起  點  ■等級:L%d(%d)■等級:L%d(%d)■  機  會  ■等級:L%d(%d)■等級:L%d(%d)■等級:L%d(%d)■ 小行星帶 ■\n", map[1].level, map[1].owner, map[2].level, map[2].owner, map[4].level, map[4].owner, map[5].level, map[5].owner, map[6].level, map[6].owner);
	printf("■   →→   ■toll:%04d ■toll:%04d ■          ■toll:%04d ■toll:%04d ■toll:%04d ■          ■\n", map[1].tolls, map[2].tolls, map[4].tolls, map[5].tolls, map[6].tolls);
	printf("■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■\n", player[0].printOnMap[0], player[1].printOnMap[0], player[2].printOnMap[0], player[3].printOnMap[0], player[0].printOnMap[1], player[1].printOnMap[1], player[2].printOnMap[1], player[3].printOnMap[1], player[0].printOnMap[2], player[1].printOnMap[2], player[2].printOnMap[2], player[3].printOnMap[2], player[0].printOnMap[3], player[1].printOnMap[3], player[2].printOnMap[3], player[3].printOnMap[3], player[0].printOnMap[4], player[1].printOnMap[4], player[2].printOnMap[4], player[3].printOnMap[4], player[0].printOnMap[5], player[1].printOnMap[5], player[2].printOnMap[5], player[3].printOnMap[5], player[0].printOnMap[6], player[1].printOnMap[6], player[2].printOnMap[6], player[3].printOnMap[6], player[0].printOnMap[7], player[1].printOnMap[7], player[2].printOnMap[7], player[3].printOnMap[7]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■  地  球  ■                                                                      ■  天王星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", map[23].price, map[8].price);
	printf("■等級:L%d(%d)■     press any botton to start(except 0)                              ■等級:L%d(%d)■\n", map[23].level, map[23].owner, map[8].level, map[8].owner);	
	printf("■toll:%04d ■                                                                      ■toll:%04d ■\n", map[23].tolls, map[8].tolls);	
	printf("■ %c %c %c %c  ■     @ 玩家一:目前金額%05d                                           ■ %c %c %c %c  ■\n", player[0].printOnMap[23], player[1].printOnMap[23], player[2].printOnMap[23], player[3].printOnMap[23], player[0].money, player[0].printOnMap[8], player[1].printOnMap[8], player[2].printOnMap[8], player[3].printOnMap[8]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  神秘星  ■     # 玩家二:目前金額%05d                                           ■          ■\n", player[1].money);	
	printf("■地價:%05d■                                                                      ■          ■\n", map[22].price);	
	printf("■等級:L%d(%d)■     & 玩家三:目前金額%05d                                           ■  命  運  ■\n", map[22].level, map[22].owner, player[2].money);	
	printf("■toll:%04d ■                                                                      ■          ■\n", map[22].tolls);
	printf("■ %c %c %c %c  ■     $ 玩家四:目前金額%05d                                           ■ %c %c %c %c  ■\n", player[0].printOnMap[22], player[1].printOnMap[22], player[2].printOnMap[22], player[3].printOnMap[22], player[3].money, player[0].printOnMap[9], player[1].printOnMap[9], player[2].printOnMap[9], player[3].printOnMap[9]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■          ■                                                                      ■  海王星  ■\n");	
	printf("■          ■                                                                      ■地價:%05d■\n", map[10].price);	
	printf("■  命  運  ■                                                                      ■等級:L%d(%d)■\n", map[10].level, map[10].owner);	
	printf("■          ■                                                                      ■toll:%04d ■\n", map[10].tolls);
	printf("■ %c %c %c %c  ■                                 →Pause the game please enter 1      ■ %c %c %c %c  ■\n", player[0].printOnMap[21], player[1].printOnMap[21], player[2].printOnMap[21], player[3].printOnMap[21], player[0].printOnMap[10], player[1].printOnMap[10], player[2].printOnMap[10], player[3].printOnMap[10]);
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  旺旺星  ■                                 →Restart the game please enter 2    ■  駭客星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", map[20].price, map[11].price);
	printf("■等級:L%d(%d)■                                 →Want to leave please enter 0       ■等級:L%d(%d)■\n", map[20].level, map[20].owner, map[11].level, map[11].owner);
	printf("■toll:%04d ■                                                                      ■toll:%04d ■\n", map[20].tolls, map[11].tolls);
	printf("■ %c %c %c %c  ■                                                                      ■ %c %c %c %c  ■\n", player[0].printOnMap[20], player[1].printOnMap[20], player[2].printOnMap[20], player[3].printOnMap[20], player[0].printOnMap[11], player[1].printOnMap[11], player[2].printOnMap[11], player[3].printOnMap[11]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■          ■  逢甲星  ■  美食星  ■  方塊星  ■          ■  植物星  ■  月  球  ■          ■\n");
	printf("■          ■地價:%05d■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■          ■\n", map[18].price, map[17].price, map[16].price, map[14].price, map[13].price);
	printf("■ 太空墳場 ■等級:L%d(%d)■等級:L%d(%d)■等級:L%d(%d)■  機  會  ■等級:L%d(%d)■等級:L%d(%d)■  監  獄  ■\n", map[18].level, map[18].owner, map[17].level, map[17].owner, map[16].level, map[16].owner, map[14].level, map[14].owner, map[13].level, map[13].owner);
	printf("■          ■toll:%04d ■toll:%04d ■toll:%04d ■          ■toll:%04d ■toll:%04d ■          ■\n", map[18].tolls, map[17].tolls, map[16].tolls, map[14].tolls, map[13].tolls);
	printf("■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■\n", player[0].printOnMap[19], player[1].printOnMap[19], player[2].printOnMap[19], player[3].printOnMap[19], player[0].printOnMap[18], player[1].printOnMap[18], player[2].printOnMap[18], player[3].printOnMap[18], player[0].printOnMap[17], player[1].printOnMap[17], player[2].printOnMap[17], player[3].printOnMap[17], player[0].printOnMap[16], player[1].printOnMap[16], player[2].printOnMap[16], player[3].printOnMap[16], player[0].printOnMap[15], player[1].printOnMap[15], player[2].printOnMap[15], player[3].printOnMap[15], player[0].printOnMap[14], player[1].printOnMap[14], player[2].printOnMap[14], player[3].printOnMap[14], player[0].printOnMap[13], player[1].printOnMap[13], player[2].printOnMap[13], player[3].printOnMap[13], player[0].printOnMap[12], player[1].printOnMap[12], player[2].printOnMap[12], player[3].printOnMap[12]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");	
}

//結束畫面
void end()
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
	scanf("%*c");
		exit(0);
}

struct player_initialise chance(struct player_initialise player[],int i){
	printf("\n");
	printf("+--------+\n");
	printf("|        |\n");
	printf("|   機   |\n");
	printf("|        |\n");
	printf("|   會   |\n");
	printf("|        |\n");		
	printf("+--------+\n");
	system("pause");
	int num;
	srand(time(NULL));
	num = rand() % 3 + 1;	//編號 (1-3)
	switch(num){
		case 1:
			printf("\n內容: 骰到 3 以上的的數字獲得 2000 元\n");
			if(dice() >= 3){
				player[i].money = player[i].money + 2000;
			}
			break;
		case 2:
			printf("\n內容: 支付太空船燃料費用 1000 元\n");
			player[i].money = player[i].money - 1000;
			break;
		case 3:
			printf("\n內容: 投資股票獲利，獲得 1000 元\n");
			player[i].money = player[i].money + 1000;
			break;		
	}
	printf("\n");
	return 	player[i];	
}

struct player_initialise fate(struct player_initialise player[],int i){
	printf("\n");
	printf("+--------+\n");
	printf("|        |\n");
	printf("|   命   |\n");
	printf("|        |\n");
	printf("|   運   |\n");
	printf("|        |\n");		
	printf("+--------+\n");	
	system("pause");
	int num,m;
	char symbol;	
	srand(time(NULL));
	num = rand() % 3 + 1;	//編號 (1-3)
	switch(num){
		case 1:
			printf("\n內容: 遭到外星人攻擊，損失 2000 元\n");
			player[i].money = player[i].money - 2000;
			break;
		case 2:
			printf("\n內容: 半路上意外撿到 1000 元\n");
			player[i].money = player[i].money + 1000;
			break;
		case 3:
			printf("\n內容: 退回起點\n");
			player[i].location = 0;
			for(m=0; m<24; m++){
				if(player[i].printOnMap[m] != ' '){
					symbol = player[i].printOnMap[m];
					player[i].printOnMap[m] = ' ';
				}
			}
			player[i].printOnMap[player[i].location] = symbol;
			break;		
	}
	printf("\n");
	return 	player[i];
}

void countWinner(struct map_initialise map[], struct player_initialise player[]){
	int k;
	int l,max;
	int sum[4]={0};
	for(k=0;k<4;k++){
		if(player[k].bankrupt){
			sum[k]=0;
			continue;
		}
		for(l=0;l<24;l++){
			if(map[l].owner==player[k].realty){
				sum[k] = sum[k]+map[l].price;
			}
		}
		sum[k] = sum[k]+player[k].money;
	}
	max = sum[0];
	int winner[4],n;
	for(k=1;k<4;k++){
		if(sum[k]>max){
			max = sum[k];
		}
	}
	for(k=0;k<4;k++){
		if(sum[k]==max) {
			printf("PLAYER %d WIN!\n",k+1);
			if(k + 1 == 1)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■      ■              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■    ■■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■       ■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■         ■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■   ■■■■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				system("pause");
				end();
			}
			if(k + 1 ==2)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■      ■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■   ■   ■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■        ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■        ■              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■   ■■■■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				system("pause");
				end();
			}
			if(k + 1 == 3)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■    ■■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■        ■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■      ■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■           ■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■    ■■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				system("pause");
				end();
			}
			if(k + 1 == 4)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■     ■ ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■   ■  ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■   ■■■■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■          ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■        ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");	
				system("pause");
				end();
			}
		}
	}
}



//主程式
int main() {
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
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
	printf("■         ■■  ■■     ■■     ■   ■    ■■     ■■■     ■■    ■     ■    ■       ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■■  ■  ■    ■  ■    ■  ■    ■  ■      ■  ■        ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■ ■ ■  ■    ■   ■■■   ■    ■  ■       ■■         ■\n");
	printf("■        ■  ■■  ■  ■    ■  ■  ■■  ■    ■  ■        ■    ■  ■        ■          ■\n");
	printf("■        ■  ■■  ■    ■■    ■   ■     ■■    ■          ■■    ■■■    ■          ■\n");
	printf("■           	                                                                                ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");	
	printf("■                                                                                              ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                            by 鹹魚製作                       ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	system("pause");
	system("cls");	//清除畫面
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
	system("pause");
	system("cls");	//清除畫面
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            Monopoly   RULE                                                                   ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■            遊戲開始                                                                          ■\n");
	printf("■            *遊戲人數4人                                                                      ■\n");
	printf("■            *遊戲方向為順時針進行                                                             ■\n");
	printf("■            *各玩家起始財產金額10000元                                                        ■\n");	
	printf("■                                                                                              ■\n");	
	printf("■            特殊地點                                                                          ■\n");
	printf("■            *行走過起點獲得金額1000元                                                         ■\n");
	printf("■            *行走到監獄限制行動，下一回合骰子骰到偶數時，再下一回合即可恢復行動               ■\n");
	printf("■            *行走到機會/命運，隨機發生一件事                                                  ■\n");
	printf("■                                                                                              ■\n");
	printf("■            交易                                                                              ■\n");
	printf("■            *行走到一般星球，且該星球無人佔領，則可選擇是否購買                               ■\n");
	printf("■            *若再次走到自己已佔領的星球，則可選擇是否升級該星球(升級上限為3)                  ■\n");
	printf("■            *若行走到其他玩家佔領的星球，需繳交過路費(與該星球等級相應金額)給該星球的佔領者   ■\n");
	printf("■                                                                                              ■\n");
	printf("■            破產                                                                              ■\n");
	printf("■            *玩家財產歸零，該玩家退出遊戲                                                     ■\n");
	printf("■            *若有玩家退出遊戲，則該玩家的星球轉變為空置                                       ■\n");
	printf("■                                                                                              ■\n");
	printf("■            勝利條件                                                                          ■\n");
	printf("■            *回合數太多可選擇是否繼續遊戲，若否，則該玩家退出遊戲                             ■\n");
	printf("■            *若玩家只剩一人，則倖存者獲勝，遊戲結束                                           ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                          →Back to menu please enter 1       ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                          →Want to leave please enter 0      ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	system("pause");
	system("cls");	//清除畫面
	
	struct player_initialise player[4]={
		{10000,1,0,0,0,"@                       ", 0} ,
		{10000,2,0,0,0,"#                       ", 0} ,
		{10000,3,0,0,0,"&                       ", 0} ,
		{10000,4,0,0,0,"$                       ", 0}
	};
	
	struct map_initialise map[24]={
		{"起點",0,0,0,0,0,0},
		{"水星",0,0,0,0,200,200},
		{"金星",0,0,0,0,300,300},
		{"機會",0,0,0,0,0,0},
		{"火星",0,0,0,0,500,500},
		{"木星",0,0,0,0,600,600},
		{"土星",0,0,0,0,700,700},
		{"小行星帶",0,0,0,0,0,0},
		{"天王星",0,0,0,0,800,800},
		{"命運",0,0,0,0,0,0},
		{"海王星",0,0,0,0,900,900},
		{"駭客星",0,0,0,0,1000,1000},
		{"監獄",0,0,0,0,0,0},
		{"月球",0,0,0,0,1200,1200},
		{"植物星",0,0,0,0,1400,1400},
		{"機會",0,0,0,0,0,0},
		{"方塊星",0,0,0,0,1600,1600},
		{"美食星",0,0,0,0,1800,1800},
		{"逢甲星",0,0,0,0,2000,2000},
		{"太空墳場",0,0,0,0,0,0},
		{"旺旺星",0,0,0,0,2300,2300},
		{"命運",0,0,0,0,0,0},
		{"神秘星",0,0,0,0,2500,2500},
		{"地球",0,0,0,0,3000,3000},
	};
	
	int i=0;
	int dice_num,num,m;
	char respond,ans,symbol,place;
	map_print(map,player);
	while(1){
		//檢查是不是只剩一個玩家
		int bankruptSituation = 0;
		bankruptSituation = player[0].bankrupt + player[1].bankrupt + player[2].bankrupt + player[3].bankrupt;
		if(bankruptSituation==3){   //只剩一個玩家
			//計算贏家
			countWinner(map,player);
			break;
		}
		//每個回合會問要不要繼續遊戲
		if(i==4){
			printf("是否離開遊戲(Y/y for leave)？");
			scanf("%c%*c",&respond);
			//printf("ans=%c  %d\n",respond,respond);
			printf("\n");
			if(isalpha(respond) && (respond=='Y' || respond=='y')){   //確定離開遊戲
				//計算贏家
				countWinner(map,player);
				break;
			}
			else{  //不繼續，繼續新的回合
				i=0;
			}
		}
		//跳過破產玩家	
		if(player[i].bankrupt){
			i++;
			continue;
		}
		//印出現在玩家
		printf("\n現在玩家：PLAYER %d\n",i+1);	// +
		//骰子()
		dice_num=dice();
		printf("\n");
		//移動()
		if(player[i].move){//如果現在不能動(在監獄)
			if(dice_num%2){  //骰子點數不是偶數 
				i++;  //換人 
				continue;  //離開 
			}
			else{
				player[i].move=0;  //恢復行動並繼續 
				i++;  //換人 
				continue;  //離開
			}
		}
		//玩家移動 
		player[i].location = player[i].location+ dice_num;
		//超過起點
		if(player[i].location >= 24){
			player[i].location = player[i].location-24;
			printf("\n經過(回到)起點\n\n"); //經過起點獲得1000 
			player[i].money = player[i].money + 1000;
		}
		//印地圖需要更新位置
		for(m=0; m<24; m++){
			if(player[i].printOnMap[m] != ' '){
				symbol = player[i].printOnMap[m];
				player[i].printOnMap[m] = ' ';
			}
		}
		player[i].printOnMap[player[i].location] = symbol;
		place = player[i].location;
		//印地圖
		map_print(map,player);
		//判斷
		switch(player[i].location){
			case 0://起點
				
				break;
			case 7:
			case 19://轉角
				 
				break;
			case 3:
			case 15:
				//機會
				chance(player,i);
				printf("\n");
				map_print(map,player);
				printf("\n");
				break;
			case 9:
			case 21: 
				//命運
				fate(player,i);
				printf("\n");
				map_print(map,player);
				printf("\n");
				break;
			case 12: 
				//監獄
				//印地圖
				printf("\n進到監獄\n");
				player[i].move = 1; //限制行動 
				break;
			default://其他正常地點
				if(map[place].owner != player[i].realty){  //不是自己的地 
					if(map[place].owner == 0){  //無主之地
						printf("\n要不要在這裡買房子？(Y/y for buy) ");
						scanf("%c%*c", &ans);
						//printf("ans=%c  %d\n",ans,ans);
						printf("\n");
						if(ans=='Y' || ans=='y'){  // && (player[i].money>map[place].price)
							map[place].own = 1;
							map[place].level = 1;
							map[place].owner = player[i].realty;
							player[i].money = player[i].money-map[place].price;
							map[place].tolls = map[place].price/2;
							map_print(map,player);
							printf("\n");
						}
						//else if((ans=='Y' || ans=='y') && player[i].money<map[place].price){
						//	printf("你沒有那麼多錢！\n\n");
						//}
					}
					else{
						//扣過路費
						printf("\n這裡是PLAYER %d的家，請付過路費 %d\n\n", map[place].owner, map[place].tolls);
						player[i].money = player[i].money-map[place].tolls;
						num = map[place].owner;
						player[num-1].money = player[num-1].money+map[place].tolls;
						map_print(map,player);
						printf("\n");
					}
				}
				else{   //是自己的地
					printf("\n歡迎回家\n");
					if(map[place].level!=3){
						printf("要不要升級？(Y/y for upgate) ");
						scanf("%c%*c", &ans);
						printf("\n");
						if(ans=='Y' || ans=='y'){  //確定要升級 && player[i].money>(map[place].price*2)
							player[i].money = player[i].money-map[place].price*2;
							map[place].level++;
							map[place].price = map[place].price*2;
							map[place].tolls = map[place].tolls*2;
							map_print(map,player);
							printf("\n");
						}
						//else if((ans=='Y' || ans=='y') && player[i].money<(map[place].price*2)){
						//	printf("你沒有那麼多錢！\n\n");
						//}
					}
		
			}
			break;
		}
		
		//檢查破產狀態
		if(player[i].money<=0){
			player[i].bankrupt = 1;
			player[i].money = 0;
			for(m=0; m<24; m++){
				if(player[i].printOnMap[m] != ' '){
					player[i].printOnMap[m] = ' ';
				}
			}
			for(m=0; m<24; m++){
				if(map[m].owner==player[i].realty){
					map[m].owner = 0;
					map[m].own = 0;
					map[m].level = 0;
					map[m].price = map[m].original_price;
					map[m].tolls = 0;
				}
			}
			printf("PLAYER %d 已經破產\n",i+1);
		}
		//換人
		i++;
//		printf("\n");	// -
	}
	return 0;

}
