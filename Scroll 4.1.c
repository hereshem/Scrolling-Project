//;-----------------
//;------created--MARCH/15/2009-----------------------
// Created by : Hem Kumar Shrestha

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<alloc.h>
#define COLS 35

void main()
{
		FILE *fp;
		int *dispreg;//[200];	  //data sizes  //control size
		char dispstr[200],ch,fname[15];
		int i,j,k=0,cursorcount=0,len;
		int st,powr,lim,speed=200;
		char defnum[10][4]={
					{0x1E,0x21,0x21,0x1E},	   //0
					{0x02,0x3F,0x00,0x00},     //1
					{0x22,0x31,0x29,0x26},     //2
					{0x11,0x25,0x25,0x1B},     //3
					{0x0F,0x08,0x08,0x3F},     //4
					{0x27,0x25,0x25,0x19},     //5
					{0x1E,0x25,0x25,0x19},     //6
					{0x31,0x09,0x05,0x03},     //7
					{0x1A,0x25,0x25,0x1A},     //8
					{0x26,0x29,0x29,0x1E}      //9
					};


		char defALPH[26][5]={
					{0x3E,0x09,0x09,0x3E,0x00},    //A
					{0x3F,0x25,0x25,0x1A,0x00},    //B
					{0x1E,0x21,0x21,0x00,0x00},    //C
					{0x3F,0x21,0x21,0x1e,0x00},    //D
					{0x3F,0x25,0x25,0x25,0x00},    //E
					{0x3F,0x05,0x05,0x05,0x00},    //F
					{0x1E,0x21,0x25,0x3D,0x00},    //G
					{0x3F,0x04,0x04,0x3F,0x00},    //H
					{0x3F,0x00,0x00,0x00,0x00},    //I
					{0x30,0x20,0x1F,0x00,0x00},    //J
					{0x3F,0x0C,0x12,0x21,0x00},    //K
					{0x3F,0x20,0x20,0x00,0x00},    //L
					{0x3F,0x02,0x0C,0x02,0x3F},    //M
					{0x3F,0x04,0x08,0x3F,0x00},    //N          //N
					{0x1E,0x21,0x21,0x1E,0x00},    //O
					{0x3F,0x09,0x09,0x06,0x00},    //P
					{0x1E,0x21,0x29,0x11,0x2E},    //Q          //
					{0x3F,0x09,0x19,0x26,0x00},    //R
					{0x22,0x25,0x25,0x19,0x00},    //S
					{0x01,0x3F,0x01,0x01,0x00},    //T
					{0x1F,0x20,0x20,0x1F,0x00},    //U
					{0x0F,0x10,0x20,0x10,0x0F},    //V
					{0x1F,0x20,0x1C,0x20,0x1F},    //W
					{0x33,0x0C,0x0C,0x33,0x00},    //X
					{0x03,0x04,0x38,0x04,0x03},    //Y
					{0x31,0x29,0x25,0x23,0x00}     //Z
					};

		unsigned char defalpha[26][5]={
					{0x18,0x24,0x24,0x18,0x20},	//a
					{0x3f,0x24,0x24,0x18,0x00},     //b
					{0x18,0x24,0x24,0x00,0x00},     //c
					{0x18,0x24,0x24,0x3f,0x00},     //d
					{0x38,0x34,0x2c,0x00,0x00},     //e
					{0x08,0x3e,0x09,0x00,0x00},     //f
					{0x98,0xa4,0xa4,0x78,0x00},     //g
					{0x3f,0x04,0x04,0x38,0x00},     //h
					{0x3d,0x00,0x00,0x00,0x00},     //i
					{0x80,0x80,0x7d,0x00,0x00},     //j
					{0x3f,0x18,0x24,0x00,0x00},     //k
					{0x3f,0x00,0x00,0x00,0x00},     //l
					{0x3c,0x04,0x38,0x04,0x38},     //m
					{0x3c,0x04,0x04,0x38,0x00},     //n
					{0x18,0x24,0x24,0x18,0x00},     //o
					{0xfc,0x24,0x24,0x18,0x00},     //p
					{0x18,0x24,0x24,0xfc,0x00},     //q
					{0x38,0x04,0x04,0x00,0x00},     //r
					{0x28,0x2c,0x34,0x14,0x00},     //s
					{0x04,0x3f,0x24,0x00,0x00},     //t
					{0x1c,0x20,0x20,0x1c,0x00},     //u
					{0x0c,0x10,0x20,0x10,0x0c},     //v
					{0x1c,0x20,0x1c,0x20,0x1c},     //w
					{0x24,0x18,0x18,0x24,0x00},     //x
					{0x9c,0xa0,0x7c,0x00,0x00},     //y				{0x,0x,0x,0x,0x,}
					{0x24,0x34,0x2c,0x24,0x00}      //z
					};
/////////////////////////////////////////////////////////////////////////////////
////////////////////// Declaration Finished /////////////////////////////////////////

		clrscr();
		gotoxy(1,10);
		printf("Enter Characters to print: ");
		scanf("%[^\n]",dispstr);
//////////////////////////////////////////////////////////////////////////

		len=strlen(dispstr);
		strncpy(fname,dispstr,6);
		fname[6]='\0';
		if(strlen(fname)<6)
		  strcat(fname,".txt");
		else
		  strcat(fname,"___.txt");
		dispreg=(int*)malloc((40+len*5)*2);
		if(len>190){strcpy(dispstr,"Sorry");len=5;}
///////////////////////////////////////////////////////////////////////////

		for(i=0;i<COLS;i++,cursorcount++)				 // initial no of spaces
			*(dispreg+cursorcount)=0;

		for(i=0;i<len;i++)							 // no of letters of user string
		{       if((st=dispstr[i])==32)
			{	*(dispreg+cursorcount++)=0;
				*(dispreg+cursorcount++)=0;
			}
			else if((st=dispstr[i])<58&&st>47)			   	// check if string is number
			{	for(j=0;j<4;j++,cursorcount++)				// width of a character
				{	*(dispreg+cursorcount)=defnum[st-48][j];		// assigns the hex num to the temp string
					if (*(dispreg+cursorcount)==0) break;
			//		printf("%d\t",dispreg[cursorcount]);
				}
				*(dispreg+cursorcount++)=0;					// 1 space in each charqacter
			//	printf("\n");
			}

			else if(st<91&&st>64)			   	// check if string is number
			{	for(j=0;j<5;j++,cursorcount++)				// width of a character
				{	*(dispreg+cursorcount)=defALPH[st-65][j];		// assigns the hex num to the temp string
					if (*(dispreg+cursorcount)==0) break;
				}
				*(dispreg+cursorcount++)=0;					// 1 space in each charqacter

			}

			else if(st<123&&st>96)			   	// check if string is number
			{	for(j=0;j<5;j++,cursorcount++)				// width of a character
				{	*(dispreg+cursorcount)=defalpha[st-97][j];		// assigns the hex num to the temp string
					if (*(dispreg+cursorcount)==0) break;
			//			printf("%d\t",dispreg[cursorcount]);
				}
				*(dispreg+cursorcount++)=0;					// 1 space in each charqacter
			//	printf("\n");
			}


		 }
	//for(i=0;i<COLS;i++,cursorcount++)
	//	dispreg[cursorcount]=0;						//remaining space 0
	//printf("\nTotal Lines=%d\n",cursorcount);
/////////////////////////////////////////////////////////////////////////////
///////////////////// File Handling ////////////////////////////////////////
      if((fp=fopen(fname,"w"))==NULL)
	{	printf("File Creation Error:");getch();
	}
      else
      {
	k=COLS;
	fputs("OUTPUT:",fp);
	fputs(dispstr,fp);
	fputs("               Created By: Hem Kr.Shrestha(065/BEX/26)\n",fp);
	for(i=0;i<len+65;i++)
		fputs("-",fp);
	fputs("\n",fp);
	for(i=0;i<8;i++)
	{
		//fputs(" |",fp);
		for(j=0;j+k<cursorcount;j++)
		{	st=*(dispreg+j+k);
			powr=pow(2,i);
			if(((st%(powr*2))/powr)==1)
				fputs("##",fp);
			else
				fputs("  ",fp);
		}
		fputs(" \n",fp);
		//fputs(" |",fp);
		  for(j=0;j+k<cursorcount;j++)
		{	st=*(dispreg+j+k);
			//powr=pow(2,i);
			if(((st%(powr*2))/powr)==1)
				fputs("##",fp);
			else
				fputs("  ",fp);
		}

		fputs(" \n",fp);
	}
	fclose(fp);
      }
//////////////////////////////////////////////////////////////////////////
////////////////////////////// OUTPUT ////////////////////////////////////
	gotoxy(1,1);
	printf("\n\nThe Output is %s: \n\n\tPress (+/-) to inc/dec Speed :\n\tPress (Space) to Pause:\n\tPress (Enter) to Exit:\n ----------------------------------------------------------------------\n",dispstr);
	gotoxy(1,25);
	printf(" -----------------------------------------------------------------------");
	gotoxy(1,9);
	//len=1;
	k=0;
	highvideo();
	while(1)
{
	//for(lim=30;dispreg[k+lim]!=0&&lim<cursorcount;lim++){}
	for(i=0;i<8;i++)
	{
		printf(" |");
		for(j=0;j<35&&j+k<cursorcount;j++)
		{	st=*(dispreg+j+k);
			powr=pow(2,i);
			if(((st%(powr*2))/powr)==1)
				printf("##");
			else
				printf("  ");
		}
		printf(" \n");
	printf(" |");
		  for(j=0;j<35&&j+k<cursorcount;j++)
		{	st=*(dispreg+j+k);
			//powr=pow(2,i);
			if(((st%(powr*2))/powr)==1)
				printf("##");
			else
				printf("  ");
		}

		printf(" \n");
    }

	k++;
	if(k==cursorcount) k=0;
	gotoxy(1,9);
	delay(speed);
	if(kbhit())
	{	ch=getch();
		if(ch==13) break;
		else if(ch==32) getch();
		else if(ch==45) {if(speed>1500) speed=1500; else speed+=25;}
		else if(ch==43) {if(speed<=25) speed=0; else speed-=25;}
	}
	//if(len++%3==2)getch();
}
     //	printf("----------------------------------------------------");
     //	getch();

 }
////////////////////////////////////////////////////////////////////////////
//////////////////////// End Of Program ////////////////////////////////////
