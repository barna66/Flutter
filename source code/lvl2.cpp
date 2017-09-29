
#include"myheader.h"

void butterfly1(int x,int y)
{
    y=y+10;
    setfillstyle(SOLID_FILL,COLOR(43,51,162));
    pieslice(x,y,110,250,80);
    pieslice(x,y,290,70,80);
    setfillstyle(SOLID_FILL,COLOR(79,88,208));
    pieslice(x,y,110,250,60);
    pieslice(x,y,290,70,60);
    setfillstyle(SOLID_FILL,COLOR(44,44,237));
    pieslice(x,y,110,250,45);
    pieslice(x,y,290,70,45);
    setfillstyle(SOLID_FILL,COLOR(0,0,196));
    pieslice(x,y,110,250,30);
    pieslice(x,y,290,70,30);
    setcolor(1);
    setfillstyle(SOLID_FILL,COLOR(9,1,52));
    fillellipse(x,y,8,35);
    fillellipse(x,y-37,9,9);
}

void lvl2(int marks)
{
    int x,y,i,j,p=0,scr=0,z=0,flag=0,n,x1,x2,x3,x4,p1,p2,p3,p4,f1,f2,f3,f4,c1,c2,c3,c4,i1=0,pscr=0,pg;
    char s[20],b;
    readimagefile("cloud.jpg",0,0,1000,700);
    for(pg=1; pg<=5; pg++)
    {
        f1=0;
        f2=0;
        f3=0;
        f4=0;
        p1=270;
        p2=270;
        p3=420;
        p4=420;
        pscr=0;
        x1=rand()%1000;
        if(x1<=500)
            f1=1;
        x2=rand()%1000;
        if(x2<=500)
            f2=1;
        x3=rand()%1000;
        if(x3<=500)
            f3=1;
        x4=rand()%1000;
        if(x4<=500)
            f4=1;

        for(; p1<=700 && p2<=700 && p3>=0 && p4>=0 ;)
        {
            readimagefile("sky2.jpg",0,0,1000,700);
            setcolor(15);
            settextstyle(4,HORIZ_DIR,5);
            sprintf(s,"SCORE: %d",scr);
            outtextxy(10, 10, s);
            if(f1==1)
            {
                leaves1(x1,p1);
                x1=x1+5;
                p1=p1+5;
            }
            else if(f1==0)
            {
                leaves1(x1,p1);
                x1=x1-5;
                p1=p1+5;
            }
            if(f2==1)
            {
                leaves1(x2,p2);
                x2=x2+5;
                p2=p2+5;
            }
            else if(f2==0)
            {
                leaves1(x2,p2);
                x2=x2-5;
                p2=p2+5;
            }
            if(f3==1)
            {
                leaves1(x3,p3);
                x3=x3+5;
                p3=p3-5;
            }
            else if(f3==0)
            {
                leaves1(x3,p3);
                x3=x3-5;
                p3=p3-5;
            }
            if(f4==1)
            {
                leaves1(x4,p4);
                x4=x4+5;
                p4=p4-5;
            }
            else if(f4==0)
            {
                leaves1(x4,p4);
                x4=x4-5;
                p4=p4-5;
            }
            delay(20);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                z=getpixel(x,y);

                if((x>=x1-15&&x<=x1+15)&&(y>=p1-15&&y<=p1+15)&&z==4)
                {
                    f1=2;
                    x1=-40;
                }
                else if((x>=x2-15&&x<=x2+15)&&(y>=p2-15&&y<=p2+15)&&z==4)
                {
                    f2=2;
                    x2=-40;
                }
                else if((x>=x3-15&&x<=x3+15)&&(y>=p3-15&&y<=p3+15)&&z==4)
                {
                    f3=2;
                    x3=-40;
                }
                else if((x>=x4-15&&x<=x4+15)&&(y>=p4-15&&y<=p4+15)&&z==4)
                {
                    f4=2;
                    x4=-40;
                }
                if((f1==2||f2==2||f3==2||f4==2)&&z==4)
                {
                    scr++;

                    pscr++;

                    //setcolor(10);
                    butterfly1(x,y);
                    delay(100);
                }
            }
            if(f1==2&&f2==2&&f3==2&&f4==2)
                break;
        }
        if(pscr<2)
            break;
    }
    if(pg==6)
     {
		 readimagefile("lb1.jpg",0,0,1000,700);
		settextstyle(4,HORIZ_DIR,8);
		setbkcolor(COLOR(218,174,111));
		outtextxy(280, 290, "LEVEL 3");
		delay(3000);
		 lvl3(scr+marks);
	}
    if(pscr<2)
        writename(scr+marks);
   
}
