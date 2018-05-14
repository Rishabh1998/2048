#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<process.h>
#include<fstream.h>
int grid[4][4]={0},hs=0,x,y,i,j,k,p,q,fup,fleft,fright,fdown,sc=0,lastscore=0;
int next[15]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},count=0;
char key,*out;
void hsc()  //TO CALCULATE & STORE HIGH SCORE
{
	ofstream fout("High.txt"); //DATA HANDLING USED
	fout<<sc;
	fout.close();
	settextstyle(1,0,1);
	setcolor(0);
	itoa(hs,out,10);
	outtextxy(500,150,out);
	setcolor(YELLOW);
	itoa(sc,out,10);
	outtextxy(500,150,out);
	hs=sc;
}

void change();
void generate();
void clrsc()
{
		itoa(sc,out,10);
	setcolor(0);
	outtextxy(500,250,out);
}
void up()
{
fup=0;
for(i=0;i<3;i++)
{
	for(j=0;j<4;j++)
	{
		if(grid[i][j]==0)
			for(k=i+1;k<4;k++)
			{
				if(grid[k][j])
				{
					grid[i][j]=grid[k][j];
					grid[k][j]=0;
					--j;
					fup=1;
					break;
					
				}
			}
		else if(grid[i][j]){
			for(k=i+1;k<4;k++)
			{
				if(!grid[k][j])continue;
				else if(grid[i][j]==grid[k][j])
				{
					grid[i][j]+=grid[k][j];
					grid[k][j]=0;
					fup=1;
					clrsc();
					sc+=grid[i][j];
				}break;
			}
		}
	}
	
	
}	
 if(fup){ change();delay(100); generate(); }
}


void right()
{
	fright=0;
for(i=3;i>0;i--)
{
	for(j=0;j<4;j++)
	{
		if(grid[j][i]==0)
			for(k=i-1;k>=0;k--)
			{
				if(grid[j][k])
				{
					grid[j][i]=grid[j][k];
					grid[j][k]=0;
					--j;
					fright=1;
					break;
					
				}
			}
		else if(grid[j][i]){
			for(k=i-1;k>=0;k--)
			{
				if(!grid[j][k])continue;
				else if(grid[j][i]==grid[j][k])
				{
					grid[j][i]+=grid[j][k];
					grid[j][k]=0;
					fright=1;
					clrsc();
					sc+=grid[j][i];
				}
				break;
			}
		}
	}
	
	
} 
if(fright){
	change();
	delay(100);
	generate(); 
	}
}


void left()
{
	fleft=0;
for(i=0;i<3;i++)
{
	for(j=0;j<4;j++)
	{
		if(grid[j][i]==0)
			for(k=i+1;k<4;k++)
			{
				if(grid[j][k])
				{
					grid[j][i]=grid[j][k];
					grid[j][k]=0;
					--j;
					fleft=1;
					break;
					
				}
			}
		else if(grid[j][i]){
			for(k=i+1;k<4;k++)
			{
				if(!grid[j][k])continue;
				else if(grid[j][i]==grid[j][k])
				{
					grid[j][i]+=grid[j][k];
					grid[j][k]=0;
					fleft=1;
					clrsc();
					sc+=grid[j][i];
				}
				break;
			}
		}
	}
	
	
}			
 if(fleft){
	 change();
	 delay(100);
	 generate(); 
	 }
}

void down()
{
fdown=0;
for(i=3;i>0;i--)
{
	for(j=0;j<4;j++)
	{
		if(grid[i][j]==0)
			for(k=i-1;k>=0;k--)
			{
				if(grid[k][j])
				{
					grid[i][j]=grid[k][j];
					grid[k][j]=0;
					--j;
					fdown=1;
					break;
					
				}
			}
		else if(grid[i][j]){
			for(k=i-1;k>=0;k--)
			{
				if(!grid[k][j])continue;
				else if(grid[i][j]==grid[k][j])
				{
					grid[i][j]+=grid[k][j];
					grid[k][j]=0;
					fdown=1;
					clrsc();
					sc+=grid[i][j];
				}
				break;
			}
		}
	}
	
	
}	

if(fdown){
	change();
	delay(100);
	generate();
	}
}

void draw()
{
	ifstream fin("HIGH.TXT");
	fin.seekg(0);
	fin>>hs;
	fin.close();
	settextstyle(3,0,1);
	outtextxy(200,50,"2048");
	outtextxy(500,100,"HIGH SCORE");
	itoa(hs,out,10);
	outtextxy(500,150,out);
	outtextxy(500,200,"SCORE");
	outtextxy(500,250,"0");
	outtextxy(500,280,"Use directional");
	outtextxy(500,305,"keys to play.");
	outtextxy(500,350,"Press 'e' to exit");
	line(200,100,440,100);
	line(440,100,440,340);
	line(440,340,200,340);
	line(200,340,200,100);
	line(200,160,440,160);
	line(200,220,440,220);
	line(200,280,440,280);
	line(260,100,260,340);
	line(320,100,320,340);
	line(380,100,380,340);
}
void change()
{ 
	itoa(lastscore,out,10);
	setcolor(0);
	outtextxy(500,250,out);
	itoa(sc,out,10);
	setcolor(YELLOW);
	outtextxy(500,250,out);
	if(hs<sc)
		hsc();
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(grid[i][j])
			{
				setcolor(YELLOW);
				p=210+j*60;
				q=110+i*60;
				bar(p,q,p+40,q+40);
				itoa(grid[i][j],out,10);
//floodfill(p+20,q+20,YELLOW);
				setcolor(BLACK);
				outtextxy(p+5,q+5,out);
			}
			else{
//setcolor(BLACK);
			p=210+j*60;
			q=110+i*60;
			bar(p,q,p+40,q+40);
//itoa(grid[i][j],out,10);
//floodfill(p+20,q+20,WHITE);

//setcolor(WHITE);
//outtextxy(p+15,q+10,out);
				}
}
void generate()
{
	count=0;
	srand(time(0));
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(!grid[i][j]){
				next[count++]=i;
				next[count++]=j;
			}
			if(count){
				x=rand()%count;
				if(x%2==0)grid[next[x]][next[x+1]]=2;
				else      grid[next[x-1]][next[x]]=2;
				change();
			}
			for(i=0;i<count;i++)next[i]=-1;
}

play(){
	while(1)
		{
		while(kbhit()){
		key=getch();
		switch(key)
		{
			case(72):  up();        //up
			break;
			case(77):   right();          //right
			break;
			case(80):    down();         //down
			break;
			case(75):  left();            //left
			break;
			case('e'):exit(0);
		default:break;
}

}
}
}
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setbkcolor(BLACK);
//setcolor(WHITE);
	draw();
	settextstyle(1,0,1);
	generate();
	generate();
	play();
	getch();
	closegraph();
}