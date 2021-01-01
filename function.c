#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h>
#include <time.h>

struct Player emplacement(struct Player player,int dice_num){
	if(player.move){//如果現在不能動，離開此函式，下一局恢復能動
		player.move=0;
		return player;
	}
	//玩家移動 
	player.location= player.location+ dice_num;
	//回起點 
	if(player.location>24){
		player.location=player.location-24;
	}
	//判斷 
	switch(player.location){
		case 0://起點
			//印地圖
			printf("回到起點\n"); //經過起點獲得2000 
			player.money = player.money + 2000;
			break;
		case 7:
		case 19://轉角
			//印地圖 
			break;
		case 3:
		case 15:
			//機會
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
			switch(num){
				case 1:
					printf("內容: 骰到 3 以上的的數字獲得 2000 元\n");
					scanf("%c", &a);
					if(dice(a) >= 3){
						player.money = player.money + 2000;
					}
					break;
				case 2:
					printf("內容: 支付太空船燃料費用 1000 元\n");
					player.money = player.money - 1000;
					break;
				case 3:
					printf("內容: 投資股票獲利，獲得 1000 元\n");
					player.money = player.money + 1000;
					break;		
			}
			break;
		case 9:
		case 21: 
			//命運
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
					player.money = player.money - 2000;
					break;
				case 2:
					printf("內容: 半路上意外撿到 1000 元\n");
					player.money = player.money + 1000;
					break;
				case 3:
					printf("內容: 退回起點\n");
					player.location = 0;
					break;		
			}
			break;
		case 12: 
			//監獄
			//印地圖
			printf("進到監獄，暫停一輪\n");
			player.move=1; 
			break;
		default://其他正常地點
			place_move(player.location,)
			//你買過房子嗎？ 
			//有沒有人買房，要不要過路費 
			//如果沒有人買房要不要買 
			//買過的要不要升級 
			
			break;
	}
}

void place_move(int num,){
	char ans;
	if(map[num].owner!=player.realty){//不是自己的地 
		if(map[num].owner==0){//無主之地
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
}
