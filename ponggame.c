/*****Source code for the game pong*****/
/****Developed by : Saurav N Shetty****/

#include<stdio.h>
#include<conio.h>
#define MAPL 60
#define MAPH 20

int gamestatus;
enum eball {STOP,UP,UPRIGHT,RIGHT,DOWNRIGHT,DOWN,DOWNLEFT,LEFT,UPLEFT} balldir;
struct paddle
{
	int padx;
	int pady;
	int score;
	char up,down;
}player1, player2;
int ballx,bally;
const int originalX = MAPL/2 , originalY = MAPH/2;

void setpaddle()
{
	player1.padx = (const int)1;
	player2.padx = (const int)(MAPL - 2);
	player1.up = 'w'; player1.down = 's';
	player2.up = 'i'; player2.down = 'k';	
	player1.score = 0; player2.score = 0;
}

void randomdirection(int n,int m)
{
	balldir = rand()%n + m;
}

void bounce()
{
	if(balldir>3 && balldir<7 )
		balldir = (balldir==DOWNLEFT)? UPLEFT:UPRIGHT ; 
	else
		balldir = (balldir==UPRIGHT)? DOWNRIGHT:DOWNLEFT;
}

void reposition()
{
	ballx = originalX; bally = originalY;
	randomdirection(8,1);
	player1.pady = MAPH/2 - 1;
	player2.pady = MAPH/2 - 1;
}

void checkwallorpaddle()
{
	if(bally==1 || bally== MAPH-2)
	{
		bounce();
	}
	else if(ballx == player1.padx+1 && bally == player1.pady)
	{
		randomdirection(3,2);
	}
	else if(ballx == player1.padx+1 && bally == player1.pady+1)
	{
		randomdirection(3,2);
	}
	else if(ballx == player1.padx+1 && bally == player1.pady+2)
	{
		randomdirection(3,2);
	}
	else if(ballx == player2.padx-1 && bally == player2.pady)
	{
		randomdirection(3,6);
	}
	else if(ballx == player2.padx-1 && bally == player2.pady+1)
	{
		randomdirection(3,6);
	}
	else if(ballx == player2.padx-1 && bally == player2.pady+2)
	{
		randomdirection(3,6);
	}
	else if(ballx==player1.padx)	
	{
		reposition();
		player1.score++;
		sleep(1);
	}	
	else if(ballx==player2.padx)
	{
		reposition();
		player2.score++;
		sleep(1);
	}
}

void draw()
{
	system("cls");
	int i,j;
	for(i=0; i<MAPH; i++)
	{
		for(j=0; j<MAPL; j++)
		{
			if(j==0 || j==MAPL-1 || i==0 || i==MAPH-1)
			{
				printf("\xB2");
			}
			else if(i==bally && j==ballx)
			{
				printf("\xFE");
			}
			else if(i==player1.pady && j==player1.padx) 			
			{
				printf("\xDE");
			}
			else if(i==player1.pady+1 && j==player1.padx) 			
			{
				printf("\xDE");
			}
			else if(i==player1.pady+2 && j==player1.padx) 			
			{
				printf("\xDE");
			}
			else if(i==player2.pady && j==player2.padx) 			
			{
				printf("\xDD");
			}
			else if(i==player2.pady+1 && j==player2.padx) 			
			{
				printf("\xDD");
			}
			else if(i==player2.pady+2 && j==player2.padx) 			
			{
				printf("\xDD");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}		
	printf("Score : %d \t\t\t Score : %d",player1.score,player2.score);
}

void input()
{
	char current;
	if(kbhit())
	{
		current = getch();
	}
	if(current==player1.up && player1.pady!=1)
	{
		player1.pady--;
	}
	else if(current==player1.down && player1.pady+2!=MAPH-2)
	{
		player1.pady++;
	}
	else if(current==player2.up && player2.pady!=1)
	{
		player2.pady--;
	}
	else if(current==player2.down && player2.pady+2!=MAPH-2)
	{
		player2.pady++;
	}
	else if(current == 'x')
	{
		balldir = STOP;
	}
}

void logic()
{
	checkwallorpaddle();
	switch(balldir)	
	{
		case UP:
			bally--;
			break;
		case UPRIGHT:
			bally--; ballx++;
			break;
		case RIGHT:
			ballx++;
			break;
		case DOWNRIGHT:
			ballx++; bally++;
			break;
		case DOWN:
			bally++;
			break;
		case DOWNLEFT:
			bally++; ballx--;
			break;
		case LEFT:
			ballx--;
			break;
		case UPLEFT:
			ballx--; bally--;
			break;
		default :
			break;
	}
}

int main()
{
	gamestatus = 1;
	setpaddle();
	reposition();
	while(gamestatus)
	{
		draw();
		input();
		logic();
	}
	return 0;
}


























