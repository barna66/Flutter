
#include"myheader.h"
int main()
{
	initwindow(1000,700, "butterfly butterfly");
	 readimagefile("flutter3.jpg",0,0,1000,700);
	   delay(2500);
	while(1)
		{
	
	readimagefile("trunk.jpg",0,0,1000,700);
	char s[10000];
	 setcolor(COLOR(208,170,89));
    settextstyle(0,HORIZ_DIR,3);
	 setbkcolor(COLOR(41,18,2));
	outtextxy(406,260,"DASHBOARD");
    outtextxy(450, 200, "PLAY");
	outtextxy(450,380,"EXIT");
	outtextxy(385,320,"INSTRUCTION");
	int x,y;
			while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
    }
			getmouseclick(WM_LBUTTONDOWN,x,y);
	printf("%d\n%d",x,y);
	if(x>=406 && x<=600 && y>=260 && y<=280){
			dashboard();
		}
	else if(x>=385&&x<600&&y>=320&&y<340)
		instructions();
	else if(x>=450&&x<550&&y>200&&y<220)
		lvl1();
	else if(x>=450&&x<550&&y>=380&&y<400)
		{return 0;
		break;
	}
	}
}
   