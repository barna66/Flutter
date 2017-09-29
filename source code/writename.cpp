#include "myheader.h"
int srt[10]= {0};
struct file
    {
       char name[100];
        int scr;
    } listo[8],tm;
char tempo[100];
	
void writename(int scr)
{
	char c;
	char name1[100]={0};
    int j, i=0,p;
	readimagefile("over.gif",300,250,700,450);
    delay(2000);
	readimagefile("lb3.jpg",0,0,1000,700);
    FILE *m1;
	setbkcolor(WHITE);
    settextstyle(6,HORIZ_DIR,5);
	setcolor(BLUE);
	sprintf(tempo,"%d",scr);
	 outtextxy(260,150,"Your Score is ");
    outtextxy(642,150,tempo);
	settextstyle(0,HORIZ_DIR,3);
    outtextxy(260,270,"ENTER YOUR NAME...");
    m1=fopen("rank.txt","r");
	for(i=0;i<7;i++){

        fscanf(m1,"%s%d",listo[i].name,&listo[i].scr);

		}
	fclose(m1);
	for(j=0;;){
		c=getch();
    settextstyle(1,HORIZ_DIR,4);
		delay(100);
		if(c==13){

			break;
		}
		if(c==8){
			j--;
			name1[j]=' ';
			name1[j+1]=' ';
			outtextxy(320, 370, name1);
			continue;
		}
		if(c!=32)
	   name1[j++]=c;
	   outtextxy(320, 370, name1);
	}
	name1[j]=0;

		strcpy(listo[7].name,name1);
     listo[7].scr=scr;
	int count=0;
	
		count=i;

    for(j=0; j<8; j++)
    {
        for(p=0; p<7; p++)
        {
            if(listo[p].scr<listo[p+1].scr)
            {
                tm=listo[p];
                listo[p]=listo[p+1];
                listo[p+1]=tm;
            }
        }
    }

	int p1=1;
	m1=fopen("rank.txt","w");
    for(i=0;i<8;i++){
				
        fprintf(m1,"%s %d",listo[i].name,listo[i].scr);
	}
	fclose(m1);
	readimagefile("lb4.jpg",0,0,1000,700);
	setcolor(BLUE);
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
	while(!(x>=675 && x<=775 && y>=555 && y<=580)){
		delay(100);
		getmouseclick(WM_LBUTTONDOWN,x,y);
		}
}
