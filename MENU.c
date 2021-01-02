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
