#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h>

struct Player emplacement(struct Player player,int dice_num){
	if(player.move){//如果現在不能動，離開此函式，下一局恢復能動
		player.move=0
		return player;
	}
	player.location= player.location+ dice_num;
	if(player.location>24){
		player.location=player.location-24;
	}
	switch(player.location){
		case 0://起點
			break;
		case 7:
		case 19://轉角 
			break;
		case 3:
		case 15:
			//機會
			break;
		case 9:
		case 21: 
			//命運
			break;
		case 12: 
			//監獄
			player.move=1; 
			break;
		default://其他正常地點
			//你買過房子嗎？ 
			//有沒有人買房，要不要過路費 
			//如果沒有人買房要不要買 
			//買過的要不要升級 
			
			break;
	}
}

void place(int num,){
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
