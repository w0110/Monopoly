#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

struct map_initialise{
	char name[6]; //地名 
	int own;  //有沒有人買 
	int owner;  //地主代號 
	int level;  //等級 
	int tolls;  //過路費 
	int price;  //價錢 
	int exp;  // 升級價錢 
};



struct Player_initialise{
	int money;  
	int realty;   //
	int move;  //可不可以移動 
	int location;  //現在位置 
	int bankrupt;
};

int main(){
	struct Player player[4]={
		{10000,1,0,0,0} ,
		{10000,2,0,0,0} ,
		{10000,3,0,0,0} ,
		{10000,4,0,0,0} ,
	};
	
	struct map_initialise map[24]={
		{"起點",0,0,1,0,0,0},
		{"水星",0,0,1,0,0,0},
		{"金星",0,0,1,0,0,0},
		{"機會",0,0,1,0,0,0},
		{"火星",0,0,1,0,0,0},
		{"木星",0,0,1,0,0,0},
		{"土星",0,0,1,0,0,0},
		{"小行星帶",0,0,1,0,0,0},
		{"天王星",0,0,1,0,0,0},
		{"命運",0,0,1,0,0,0},
		{"海王星",0,0,1,0,0,0},
		{"駭客星",0,0,1,0,0,0},
		{"監獄",0,0,1,0,0,0},
		{"月球",0,0,1,0,0,0},
		{"植物星",0,0,1,0,0,0},
		{"機會",0,0,1,0,0,0},
		{"方塊星",0,0,1,0,0,0},
		{"美食星",0,0,1,0,0,0},
		{"逢甲星",0,0,1,0,0,0},
		{"太空墳場",0,0,1,0,0,0},
		{"旺旺星",0,0,1,0,0,0},
		{"命運",0,0,1,0,0,0},
		{"神秘星",0,0,1,0,0,0},
		{"地球",0,0,1,0,0,0},
	};
	 
	//印規則 
	int i=0,round=0,leave=1;
	char respond;
	while(leave){
		if(player[i].bankrupt){
			i++;
			continue;
		}
		round++;
		//印地圖
		//印出現在玩家
		printf("現在玩家：PLAYER %d\n",i+1); 
		//骰子() 
		//移動()
		//換人 
		i++;
		if(i==4){  //n是現在玩家人數 
			i=0;
		}
		//回合數太多，要不要離開 
		if(round%20==0){
			printf("已經%d回合了，是否繼續(Y/y for leave)？\n",round);
			scanf("%c",&respond);
			if(isalph(respond) && (respond=='Y' || respond=='y')){
				//計算贏家 
				leave=0;
				break;
			}
		}
	}
	return 0;
}
