
#include"myheader.h"
void level1()
{
	readimagefile("ins2.jpg",100,0,900,700);
	readimagefile("sign.jpg",820,480,985,680);
}
void level2()
{
	readimagefile("ins2a.jpg",100,0,900,700);
	readimagefile("sign.jpg",820,480,985,680);
}
void level3()
{
	readimagefile("ins3.jpg",100,0,900,700);
	readimagefile("sign.jpg",820,480,985,680);
}
void instructions()
{
	setfillstyle(SOLID_FILL,15);
	bar(0,0,1000,700);
	readimagefile("ins2.jpg",100,0,900,700);
	readimagefile("sign.jpg",820,480,985,680);
	int x,y;
	while(1)
		{
			while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
    }
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(x>820&&x<985&&y>585&&y<605)
				level2();
			else if(x>820&&x<985&&y>555&&y<585)
				level1();
			else if(x>820&&x<985&&y>605&&y<635)
				level3();
			else if(x>120&&x<250&&y>580&&y<615)
				break;
	}
}