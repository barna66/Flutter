
#include"myheader.h"

void butterfly3(int x,int y)
{
	setcolor(1);
	setfillstyle(SOLID_FILL,COLOR(43,51,162));
	pieslice(x,y,25,165,80);
	setfillstyle(SOLID_FILL,COLOR(79,88,208));
	pieslice(x,y,20,160,62);
	setfillstyle(SOLID_FILL,COLOR(44,44,237));
	pieslice(x,y,20,160,44);
	setfillstyle(SOLID_FILL,COLOR(0,0,196));
	pieslice(x,y,20,160,26);
	setfillstyle(SOLID_FILL,1);
	fillellipse(x-3,y,35,5);
	fillellipse(x+34,y,6,6);
}
void lvl3(int score)
{
	int x,y,i=0,j,x1=270,y1=600,p,q,r,s1,t,scr=0;
	char c,s[100];
	x=400;
	y=0;
	setcolor(0);
	p=x;
	q=x+500;
	r=x+1000;
	s1=x+1500;
	t=x+2000;
	readimagefile("sky.jpg",0,0,1000,700);
		butterfly1(x1,y1);
		setfillstyle(SOLID_FILL,1);
		bar(p,y,p+120,y+350);
		bar(q,y+350,q+120,y+700);
	while(!kbhit())
		delay(100);
	for(;;p-=10,q-=10,r-=10,s1-=10,t-=10,y1+=5)
	{
		readimagefile("sky.jpg",0,0,1000,700);
		 setcolor(15);
		 setbkcolor(9);
			settextstyle(4,HORIZ_DIR,5);
            sprintf(s,"SCORE: %d",scr);
            outtextxy(10, 10, s);
		butterfly3(x1,y1);
		setfillstyle(SOLID_FILL,1);
		bar(p,y,p+120,y+350);
		bar(q,y+350,q+120,y+700);
		bar(r,y,r+120,y+360);
		bar(t,y+310,t+120,y+700);
		bar(s1,y+200,s1+120,y+700);
		delay(30);
		if(kbhit())
		{
			c=getch();
			if(c==32)
		{
				y1-=17;
			}
		}
		
		if(p+120 ==x1 || q+ 120 ==x1 || r+120 ==x1 || s1+ 120 ==x1 || t+ 120 ==x1)
			scr+=5;
		if(p==-150)
			p=2500;
		if(q==-150)
			q=2500;
		if(r==-150)
			r=2500;
		if(s1==-150)
			s1=2500;
		if(t==-150)
			t=2500;
		if((x1+65>p)&&(x1-55<p+120)&&(y1<y+400))
			break;
		if((x1+60>q)&&(x1-50<q+120)&&(y1>y+350))
			break;
		if((x1+60>r)&&(x1-55<r+120)&&(y1<y+410))
			break;
		if((x1+60>t)&&(x1-50<t+120)&&(y1>y+310))
			break;
		if((x1+60>s1)&&(x1-50<s1+120)&&(y1>y+200))
			break;
	}
	writename(score+scr);
}
