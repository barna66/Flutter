
#include"myheader.h"
void flower1(int n,int i,int b)
{
	pieslice(n,i,45,107,80);
	pieslice(n,i,117,179,80);
	pieslice(n,i,189,251,80);
	pieslice(n,i,261,323,80);
	pieslice(n,i,333,35,80);

	setfillstyle(SOLID_FILL,b);
	fillellipse(n,i,20,20);
	
	
}
void leaves1(int nx,int ny)
{
	
		setfillstyle(SOLID_FILL,13);
    flower1(nx,ny,4);
 
}
