
#include"myheader.h"

void readimagefile(
    const char* title,
    int left, int top, int right, int bottom
);
void flower(int n,int i,int b)
{
    pieslice(n,i,45,107,80);
    pieslice(n,i,117,179,80);
    pieslice(n,i,189,251,80);
    pieslice(n,i,261,323,80);
    pieslice(n,i,333,35,80);

    setfillstyle(SOLID_FILL,b);
    fillellipse(n,i,20,20);
}
void score_again(int scr)
{

    char s[100];
    setcolor(15);
    sprintf(s,"SCORE: %d",scr);
    outtextxy(10, 10, s);

}
void butterfly(int x,int y)
{
    y=y+20;
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
    y=y-20;
}

void leaves(int n,int i,int j)
{
    //flower
    setcolor(15);
    setfillstyle(SOLID_FILL,13);
    flower(n,50+i,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+300,50+i-j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n,50+i-2*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+350,50+i-3*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+450,50+i-4*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+150,50+i-5*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+600,50+i-6*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+150,50+i-7*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+300,50+i-8*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+600,50+i-9*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+450,50+i-10*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+150,50+i-11*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+450,50+i-12*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+300,50+i-13*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+150,50+i-14*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+600,50+i-15*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+300,50+i-16*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+150,50+i-17*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+750,50+i-18*j,4);
    setfillstyle(SOLID_FILL,13);
    flower(n+900,50+i-19*j,4);
    setfillstyle(SOLID_FILL,12);
    flower(n+150,50+i-20*j,4);
}
void time(int t)
{
    char s[100];
    setcolor(WHITE);
    settextstyle(0,HORIZ_DIR,3);
    sprintf(s,"TIME: %d",t);
    outtextxy(750,10,s);
}

void lvl1()
{
    int x,y,i,j,p=0,l,z,mscr=0,flag=0,n,t=1;
    char s[110],b;
    n=rand()%250;

    setcolor(WHITE);
    settextstyle(0,HORIZ_DIR,3);
    sprintf(s,"SCORE: %d",mscr);
    outtextxy(10, 10, s);
    for(; flag!=1;)
    {
        for(i=0,j=100; i<=2600; i+=35,p++)
        {
            readimagefile("c.jpg",0,0,1000,700);
            score_again(mscr);
            time(t);
            leaves(n,i,j);
            delay(30);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                z=getpixel(x,y);
                printf("%d ",z);
                if(z==12)
                {
                    mscr++;
                    setcolor(15);
                    sprintf(s,"SCORE: %d",mscr);
                    outtextxy(10, 10, s);
                    setcolor(9);
                    butterfly(x,y);
                    delay(200);
                }

                else if(z==13)
                {
                    flag=1;
                    break;
                }

            }
            if(p%5==0)
                t++;
            if(t==20)
            {
                flag=1;
                break;
            }
        }
        n=rand()%250;
    }
    if(mscr>=10)
    {
        readimagefile("lb1.jpg",0,0,1000,700);
        settextstyle(4,HORIZ_DIR,8);
        setbkcolor(COLOR(218,174,111));
        outtextxy(280, 290, "LEVEL 2");
        delay(3000);
        lvl2(mscr);
    }

    else
        writename(mscr);
}
