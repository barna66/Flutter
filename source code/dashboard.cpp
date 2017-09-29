
#include"myheader.h"
void dashboard()
{ char tempo[100];
struct file
    {
       char name[100];
        int scr;
    } listo[8];
	int p1=1,i,j;
	FILE *m1;
	
	 m1=fopen("rank.txt","r");
	for(i=0;i<=8;i++){

        fscanf(m1,"%s%d",listo[i].name,&listo[i].scr);

		}
	readimagefile("lb4.jpg",0,0,1000,700);
	setcolor(BLUE);
	setbkcolor(15);
	 settextstyle(1,HORIZ_DIR,3);
    for(j=0; j<7; j++)
    {
		if(j==0){
                sprintf(tempo,"%s",listo[j].name);
                outtextxy(280,200,tempo);
                sprintf(tempo,"%d",listo[j].scr);
                outtextxy(580,200,tempo);
				p1=p1+4;}
		else{
		sprintf(tempo,"%s",listo[j].name);
                outtextxy(280,50*p1,tempo);
                sprintf(tempo,"%d",listo[j].scr);
                outtextxy(580,50*p1,tempo);
                p1=p1+1;
		}
            }
			   int x,y;
	setbkcolor(COLOR(253,202,23));
	setcolor(COLOR(252,68,44));
	outtextxy(675,555,"Menu");
	while(1){
		while(!ismouseclick(WM_LBUTTONDOWN))
				delay(100);
		getmouseclick(WM_LBUTTONDOWN,x,y);
			if(x>=675 && x<=775 && y>=555 && y<=580)
				break;
		}	
}
