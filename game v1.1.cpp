#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include <dir.h>
#include <iostream>
#include <windows.h>
#include<unistd.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);//gotoxy related
COORD CursorPosition;//gotoxy related
void gotoXY(int x, int y);
void ClearConsoleToColors(int ForgC, int BackC);//change console and text colour
void SetColor(int Forgc); //change text colour only
void draw_board();
void zero(int a,int b);
void cross(int a,int b);
void instruction();
void player1(); //turn of player one
void player2(); //turn of player two
void player();  //graphics of player
void one();    //graphics of one
void two();    //graphics of two
void result(); //player result
void winner(); //Winner text
void draw();   //draws board
void vline(int); // draws a vertical line
void tic_tac_toe(); // game function
void big_rect();   // welcome animated big rectangle
void nabig_rect(); // no animated big rectangle
void small_rect();  // menu rectangle
void clear_small_rect(); // clear small rectangle
void wrong_input();
void clear_screen(); 
char loc[10]={'a','b','c','d','e','f','g','h','i'}, temp;
int menu,counter=0,score1,score2,return_to_menu=0,start_again=0,a=219,i,x1=45,x2=13,yl=2,yr=2,ch1,ch2,check_score;

main()
{   menu:
	loc[0]='a';loc[1]='b';loc[2]='c';loc[3]='d';loc[4]='e';loc[5]='f';loc[6]='g';loc[7]='h';loc[8]='i';
	score1=0;score2=0;
	counter=0;
    system("cls");
    ClearConsoleToColors(0,15);
    tic_tac_toe();
    small_rect();
    big_rect();
	select:
		gotoXY(45,x2);printf("<=");	
	    ch1=getch();
        ch2=0;
        if(ch1 == 0XE0){}
        ch2 = getch();
        switch(ch2)
    {
    	case 72: {      if(x2==13){gotoXY(45,13);printf("  ");x2=19;gotoXY(45,x2);printf("<=");goto select;}
    	           else if(x2==19){gotoXY(45,19);printf("  ");x2=17;gotoXY(45,x2);printf("<=");goto select;}
    	           else if(x2==17){gotoXY(45,17);printf("  ");x2=15;gotoXY(45,x2);printf("<=");goto select;}
    	                      else{gotoXY(45,15);printf("  ");x2=13;gotoXY(45,x2);printf("<=");goto select;}
			break;}
		case 80: {      if(x2==13){gotoXY(45,13);printf("  ");x2=15;gotoXY(45,x2);printf("<=");goto select;}
    	           else if(x2==19){gotoXY(45,19);printf("  ");x2=13;gotoXY(45,x2);printf("<=");goto select;}
    	           else if(x2==17){gotoXY(45,17);printf("  ");x2=19;gotoXY(45,x2);printf("<=");goto select;}
    	                      else{gotoXY(45,15);printf("  ");x2=17;gotoXY(45,x2);printf("<=");goto select;}
			break;}
		case 13:{    if(x2==13){menu='a';}
                     if(x2==15){menu='b';}
                     if(x2==17){menu='c';}
                     if(x2==19){menu='d';}
			break;
		}
	
		
	}
	switch(menu)
	{
		case 'a':
			{   start_again:
				loc[0]='a';loc[1]='b';loc[2]='c';loc[3]='d';loc[4]='e';loc[5]='f';loc[6]='g';loc[7]='h';loc[8]='i';
				return_to_menu=0;start_again=0;
			    system("cls");
			    counter=0;
			    check_score=0;
			    nabig_rect();
			    draw_board();
			    vline(35);
			    instruction();
			    while(counter!=9)
			    {
			    	player1();
			    	
			    	if(return_to_menu==1){goto menu;}
			    	if(start_again==1){goto start_again;}
			    	if(counter>2)
			    	{result();
					  if(check_score==1)
					  {SetColor(13);score1++;winner();one();if(getch()=='r'){goto menu;}else goto start_again;}
					}
			    	player2();
					if(counter>2)
					{ result();
					  if(check_score==2)
					  {SetColor(13);score2++;winner();two();if(getch()=='r'){goto menu;}else goto start_again;}
					}
					
			    }
				
				break;
			}
		case 'b':{nabig_rect();tic_tac_toe();clear_small_rect();
		          gotoXY(3,11);printf("Press key 'a' to add  cross or zero  of 1st player \n");
				  gotoXY(3,12);printf("then second player press a key from a-i to add his key on board\n");
	              gotoXY(3,13);printf("if three of corresponding figures is matched in  a row,column,\n ");
	              gotoXY(3,14);printf("or diagonally then the player win \n");
	              SetColor(12);gotoXY(3,20);printf("Press anykey to goto main menu\n");
	              getch();
	              goto menu;
			      break;
		          }
		case 'c':{nabig_rect();tic_tac_toe();clear_small_rect();
		          gotoXY(3,11);printf("+++++++++++++++Hi There ++++++++++++++++\n");
	              gotoXY(3,12);printf("I'm Gaurav , developer of this program .\n");
	              gotoXY(3,13);printf("Currently i'm pursuing a BE from Ies College OF technology\n");
	              gotoXY(3,14);printf("Email: gauravsinghmr.g@gmail.com");
	              SetColor(12);gotoXY(3,20);printf("Press any key to goto menu");
	              getch();
	              goto menu;
			      break;
		          }
		case 'd':{exit(0);break;}
		default:{printf("Wrong Input, Try Again\n");goto menu;
			break;
		}
	}
}


void draw_board()
{SetColor(2);
gotoXY(2,2);printf("          %c         %c         \n",219,219);
gotoXY(2,3);printf("          %c         %c         \n",219,219);
gotoXY(2,4);printf("          %c         %c         \n",219,219);
gotoXY(2,5);printf("     A    %c    B    %c    C    \n",219,219);
gotoXY(2,6);printf("          %c         %c         \n",219,219);
gotoXY(2,7);printf("          %c         %c         \n",219,219);
gotoXY(2,8);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoXY(2,9);printf("          %c         %c         \n",219,219);
gotoXY(2,10);printf("          %c         %c         \n",219,219);
gotoXY(2,11);printf("          %c         %c         \n",219,219);
gotoXY(2,12);printf("    D     %c    E    %c    F    \n",219,219);
gotoXY(2,13);printf("          %c         %c         \n",219,219);
gotoXY(2,14);printf("          %c         %c         \n",219,219);
gotoXY(2,15);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoXY(2,16);printf("          %c         %c         \n",219,219);
gotoXY(2,17);printf("          %c         %c         \n",219,219);
gotoXY(2,18);printf("          %c         %c         \n",219,219);
gotoXY(2,19);printf("    G     %c    H    %c    I    \n",219,219);
gotoXY(2,20);printf("          %c         %c         \n",219,219);
gotoXY(2,21);printf("          %c         %c         \n",219,219);
}

void player1()
{player1:
 gotoXY(37,2);
 SetColor(12);
 player();one();
 gotoXY(37,10);
 temp=getch();
 if(temp=='q'){exit(0);}
 switch(temp)
 {
			    case 'a' :{if(loc[0]!='o'){if(loc[0]!='x'){loc[0]='x';counter++;cross(5,3);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'b' :{if(loc[1]!='o'){if(loc[1]!='x'){loc[1]='x';counter++;cross(16,3);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'c' :{if(loc[2]!='o'){if(loc[2]!='x'){loc[2]='x';counter++;cross(26,3);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'd' :{if(loc[3]!='o'){if(loc[3]!='x'){loc[3]='x';counter++;cross(5,10);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
						   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'e' :{if(loc[4]!='o'){if(loc[4]!='x'){loc[4]='x';counter++;cross(16,10);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'f' :{if(loc[5]!='o'){if(loc[5]!='x'){loc[5]='x';counter++;cross(26,10);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'g' :{if(loc[6]!='o'){if(loc[6]!='x'){loc[6]='x';counter++;cross(5,17);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'h' :{if(loc[7]!='o'){if(loc[7]!='x'){loc[7]='x';counter++;cross(16,17);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
						case 'i' :{if(loc[8]!='o'){if(loc[8]!='x'){loc[8]='x';counter++;cross(26,17);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player1;}break;}
					    case 'r':{return_to_menu=1;break;}
					    case 's':{start_again=1;break;}
					    default:{gotoXY(37,2);wrong_input();sleep(2);clear_screen();goto player1;}

					 }

					}

void player2()
{player2:
 gotoXY(37,2);
 SetColor(1);
 player();two();
 temp=getch();
 if(temp=='q'){exit(0);}
 switch(temp)
	{
						case 'a' :{if(loc[0]!='x'){if(loc[0]!='o'){loc[0]='o';counter++;zero(5,3);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'b' :{if(loc[1]!='x'){if(loc[1]!='o'){loc[1]='o';counter++;zero(16,3);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'c' :{if(loc[2]!='x'){if(loc[2]!='o'){loc[2]='o';counter++;zero(26,3);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'd' :{if(loc[3]!='x'){if(loc[3]!='o'){loc[3]='o';counter++;zero(5,10);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'e' :{if(loc[4]!='x'){if(loc[4]!='o'){loc[4]='o';counter++;zero(16,10);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'f' :{if(loc[5]!='x'){if(loc[5]!='o'){loc[5]='o';counter++;zero(26,10);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'g' :{if(loc[6]!='x'){if(loc[6]!='o'){loc[6]='o';counter++;zero(5,17);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'h' :{if(loc[7]!='x'){if(loc[7]!='o'){loc[7]='o';counter++;zero(16,17);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'i' :{if(loc[8]!='x'){if(loc[8]!='o'){loc[8]='o';counter++;zero(16,26);}
							   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}}
								   else{gotoXY(37,10);printf("Error ,Choose Another\n"); goto player2;}break;}
						case 'r':{return_to_menu=1;break;}
					    case 's':{start_again=1;break;}
					    default:{gotoXY(37,2);wrong_input();sleep(2);clear_screen();goto player2;}
					 }
					 }
void result(){	    if(loc[0]=='x' && loc[1]=='x' && loc[2]=='x')
					check_score=1;
					if(loc[3]=='x' &&loc[4]=='x' && loc[5]=='x')
					check_score=1;
					if(loc[6]=='x' &&loc[7]=='x' && loc[8]=='x')
					check_score=1;
					if(loc[0]=='x' &&loc[3]=='x' && loc[6]=='x')
					check_score=1;
					if(loc[1]=='x' &&loc[4]=='x' && loc[7]=='x')
					check_score=1;
					if(loc[2]=='x' &&loc[5]=='x' && loc[8]=='x')
					check_score=1;
					if(loc[0]=='x' &&loc[4]=='x' && loc[8]=='x')
					check_score=1;
					if(loc[2]=='x' &&loc[4]=='x' && loc[6]=='x')
					check_score=1;
					//2nd winner
					if(loc[0]=='o' && loc[1]=='o' && loc[2]=='o')
					check_score=2;
					if(loc[3]=='o' &&loc[4]=='o' && loc[5]=='o')
					check_score=2;
					if(loc[6]=='o' &&loc[7]=='o' && loc[8]=='o')
					check_score=2;
					if(loc[0]=='o' &&loc[3]=='o' && loc[6]=='o')
					check_score=2;
					if(loc[1]=='o' &&loc[4]=='o' && loc[7]=='o')
					check_score=2;
					if(loc[2]=='o' &&loc[5]=='o' && loc[8]=='o')
					check_score=2;
					if(loc[0]=='o' &&loc[4]=='o' && loc[8]=='o')
					check_score=2;
					if(loc[2]=='o' &&loc[4]=='o' && loc[6]=='o')
					check_score=2;


}
void big_rect()
{   SetColor(10);
	gotoXY(0,0);printf("%c",201);
	for(i=0;i<78;i++){printf("%c",205);Sleep(1);}printf("%c",187);
	for(i=1;i<23;i++){gotoXY(79,i);printf("%c",186);Sleep(1);}
	gotoXY(79,23);printf("%c",188);
	for(i=78;i!=0;i--){gotoXY(i,23);printf("%c",205);Sleep(1);}
	gotoXY(0,23);printf("%c",200);
	for(i=22;i!=0;i--){gotoXY(0,i);printf("%c",186);Sleep(1);}
}
void nabig_rect()
{   SetColor(10);
	gotoXY(0,0);printf("%c",201);
	for(i=0;i<78;i++){printf("%c",205);}printf("%c",187);
	for(i=1;i<23;i++){gotoXY(79,i);printf("%c",186);}
	gotoXY(79,23);printf("%c",188);
	for(i=78;i!=0;i--){gotoXY(i,23);printf("%c",205);}
	gotoXY(0,23);printf("%c",200);
	for(i=23;i!=0;i--){gotoXY(0,i);printf("%c",186);}
}
void small_rect()
{SetColor(2);
gotoXY(22,10);printf("  ===============================  \n");
gotoXY(22,11);printf("||         | GAME MENU |         ||\n");
gotoXY(22,12);printf("||                               ||\n");
gotoXY(22,13);printf("||          1. PLAY              ||\n");
gotoXY(22,14);printf("||                               ||\n");
gotoXY(22,15);printf("||          2. HELP              ||\n");
gotoXY(22,16);printf("||                               ||\n");
gotoXY(22,17);printf("||          3. ABOUT             ||\n");
gotoXY(22,18);printf("||                               ||\n");
gotoXY(22,19);printf("||          4. EXIT              ||\n");
gotoXY(22,20);printf("||                               ||\n");
gotoXY(22,21);printf("  ===============================  \n");
}
void clear_small_rect(){for(i=10;i<22;i++){
gotoXY(22,i);printf("                                     \n");
}
}
void tic_tac_toe()
{SetColor(10);
gotoXY(8,2);printf("%c%c%c%c%c %c%c%c%c%c  %c%c%c%c%c   %c%c%c%c%c  %c%c%c%c%c  %c   %c   %c%c%c%c%c   %c%c%c%c%c   %c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoXY(8,3);printf("  %c     %c    %c         %c    %c   %c  %c  %c      %c     %c   %c   %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoXY(8,4);printf("  %c     %c    %c         %c    %c%c%c%c%c  %c%c%c       %c     %c   %c   %c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoXY(8,5);printf("  %c     %c    %c         %c    %c   %c  %c  %c      %c     %c   %c   %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoXY(8,6);printf("  %c   %c%c%c%c%c  %c%c%c%c%c     %c    %c   %c  %c   %c     %c     %c%c%c%c%c   %c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

}
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
 DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
} 

void cross(int a,int b){
SetColor(12);
gotoXY(a,b+0);	printf("%c  %c\n",219,219);
gotoXY(a,b+1);	printf(" %c%c \n",219,219);
gotoXY(a,b+2);	printf(" %c%c \n",219,219);
gotoXY(a,b+3);	printf("%c  %c\n",219,219);
}
void zero(int a,int b){
SetColor(1);
gotoXY(a,b+0);	printf(" %c%c%c \n",219,219,219);
gotoXY(a,b+1);	printf("%c   %c\n",219,219);
gotoXY(a,b+2);	printf("%c   %c\n",219,219);
gotoXY(a,b+3);	printf(" %c%c%c \n",219,219,219);
}
void vline(int j){
	for(i=1;i<23;i++)
	{
		gotoXY(j,i);printf("%c",178);
		
	}
}
void instruction(){
SetColor(4);
gotoXY(36,21); printf(" Q=> Quit Game S=> Start Again R=> Return \n");
gotoXY(36,20); printf(" Cross[x] Score =%d Zero[o] Score =%d\n",score1,score2);
}

void player(){
gotoXY(37,2);printf("%c%c%c %c   %c%c%c %c %c %c%c%c %c%c%c \n ",201,205,187,186,201,205,187,186,186,201,205,205,201,205,187);
gotoXY(37,3);printf("%c %c %c   %c %c %c %c %c   %c %c      \n",186,186,186,186,186,186,186,186,186,186);
gotoXY(37,4);printf("%c%c%c %c   %c%c%c %c%c%c %c%c%c %c%c%c\n",204,205,188,186,204,205,185,200,203,188,204,205,205,204,203,188);
gotoXY(37,5);printf("%c   %c   %c %c  %c  %c   %c%c%c       \n",186,186,186,186,186,186,186,200,187);
gotoXY(37,6);printf("%c   %c%c%c %c %c  %c  %c%c%c %c %c    \n",186,200,205,205,186,186,186,200,205,205,186,186);
}
void one(){
	
gotoXY(65,2);printf("%c%c \n",201,187);
gotoXY(65,3);printf("%c%c \n",186,186);
gotoXY(65,4);printf(" %c \n",186);
gotoXY(65,5);printf(" %c \n",186);
gotoXY(65,6);printf("%c%c%c\n",205,202,205);
}
void two(){
gotoXY(65,2);printf("%c%c%c\n",201,205,187);
gotoXY(65,3);printf("  %c\n",186);
gotoXY(65,4);printf("%c%c%c\n",201,205,188);
gotoXY(65,5);printf("%c    \n",186);
gotoXY(65,6);printf("%c%c%c\n",200,205,188);
}
void winner(){
gotoXY(37,2);printf("%c %c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c   \n",186,186,201,203,187,201,187,186,201,187,186,201,205,187,201,205,187);
gotoXY(37,3);printf("%c %c  %c  %c%c%c %c%c%c %c   %c %c \n",186,186,186,186,186,186,186,186,186,186,186,186);
gotoXY(37,4);printf("%c%c%c  %c  %c%c%c %c%c%c %c%c  %c%c%c    \n",186,186,186,186,186,186,186,186,186,186,204,185,204,203,188);
gotoXY(37,5);printf("%c%c%c  %c  %c%c%c %c%c%c %c   %c%c%c \n",186,186,186,186,186,186,186,186,186,186,186,186,200,187);
gotoXY(37,6);printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c %c    \n",200,202,188,200,202,188,186,200,188,186,200,188,200,205,188,186,186,186);

}
void draw(){
gotoXY(37,2);printf("%c%c%c%c %c%c%c %c%c%c %c %c\n",205,203,205,187,201,205,187,201,205,187,203,203);
gotoXY(37,3);printf(" %c %c %c %c %c %c %c %c\n",186,186,186,186,186,186,186,186);
gotoXY(37,4);printf(" %c %c %c%c%c %c%c%c %c%c%c\n",186,186,204,203,188,204,205,185,186,186,186);
gotoXY(37,5);printf(" %c %c %c%c%c %c %c %c%c%c\n",186,186,186,200,187,186,186,186,186,186);
gotoXY(37,6);printf("%c%c%c%c %c %c %c %c %c%c%c\n",205,202,205,188,202,202,202,202,200,202,188);

}
void wrong_input()
{
	gotoXY(37,2);printf("You Have Pressed a Wrong key ,Please  \n");
    gotoXY(37,3);printf("press key between a-e. Also, if you   \n");
    gotoXY(37,4);printf("face problems get help from mainmenu  \n");
    gotoXY(37,5);printf("or you can press 'r' to goto Mainmenu.\n");
    gotoXY(37,6);printf("Note:Toggle capslock                  \n");
    
}
void clear_screen()
{
	gotoXY(37,2);printf("                                      \n");
    gotoXY(37,3);printf("                                      \n");
    gotoXY(37,4);printf("                                      \n");
    gotoXY(37,5);printf("                                      \n");
    gotoXY(37,6);printf("                                      \n");
}
