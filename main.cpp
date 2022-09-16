#include<graphics.h>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<fstream>
#include<mmsystem.h>
using namespace std;


const int screen_width = GetSystemMetrics(SM_CXSCREEN);
const int screen_height = GetSystemMetrics(SM_CYSCREEN);

void endgame()
{
	PlaySound(TEXT("mixkit-long-game-over-notification-276.wav"),NULL,SND_ASYNC);
	int page=0;

		do{  
		   	setactivepage(page);
	        setvisualpage(1-page);
	
		     cleardevice();
		     
			setcolor(RED);
	        setbkcolor(BLACK);
	        settextstyle(6,0,8);
	        outtextxy(screen_width/2-350,screen_height/2-100,"GAME OVER");
	        
	        setcolor(RED);
	        settextstyle(6,0,3);
	        outtextxy(screen_width/2-200,screen_height/2+20,"PRESS 'a' TO RESTART.");
	        
	        
	        
            getch();
			page=1-page;		
		   }while(getch()!='a');
		   
		   setactivepage(0);  //To change page from endgame to gameplay.
		   setvisualpage(0);
	   
}

void gameplay()
{
	
	cleardevice();
	int page = 0;
 
	
	int enemyDir_left = screen_width / 2 -150, enemyDir_right = screen_width / 2-100, enemy_Up = screen_height - 600, enemy_Down = screen_height - 560;
	int enemy2Dir_left = screen_width/2, enemy2Dir_right = screen_width/2+50, enemy2_Up = screen_height - 600, enemy2_Down = screen_height - 560;
	int enemy3Dir_left = 50, enemy3Dir_right = 100, enemy3_Up = screen_height - 600, enemy3_Down = screen_height - 560;
	int enemy4Dir_left = 100, enemy4Dir_right = 150, enemy4_Up = screen_height - 600, enemy4_Down = screen_height - 560;
	int enemy5Dir_left = 130, enemy5Dir_right = 180, enemy5_Up = screen_height - 600, enemy5_Down = screen_height - 560;
    int value_saver = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4=0, temp5=0, temp6=0, temp7=0,temp8=0,temp9=0,temp10=0,temp11=0,temp12=0,temp13=0,temp14=0,temp15=0;
    int arc_x = 22;
    int circle_y = -100;
    int rec_left = -50, rec_right = 100;
    int rec_top = screen_height - 100;
    int rec_bottom = screen_height - 85;
    int floodfill_x = 50;
    int enemy_floodfill_y = -590;
    int enemy2_floodfill_y= -590;
    int enemy3_floodfill_y= -590;
    int enemy4_floodfill_y= -590;
    int enemy5_floodfill_y= -590;
    int x = 0,x1=0,x2=0,x3=0,x4=0,counter=0;
    char score_array[50];
    char lives_array[20];
    char level_array[30];
    int lives = 3;
    int level = 1;
    int score = 0;
    int tempscore=0;
    int highscore=0;
    
    fstream infile("highscore1.txt");
	infile>>highscore;
   

    while (1)
    {
    
    	if(counter==1)
    	{
    		counter++;
    		int page=0;
		}
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        setcolor(RED);
        settextstyle(6, 0, 5);
        sprintf(score_array, "Score : %d", score);
        outtextxy(3, 0, score_array);

        setcolor(RED);
        settextstyle(6, 0, 5);
        sprintf(lives_array, "Lives : %d", lives);
        outtextxy(screen_width / 2 - 85, 0, lives_array);

        setcolor(RED);
        settextstyle(6, 0, 5);
        sprintf(level_array, "Level : %d", level);
        outtextxy(screen_width - 250, 0, level_array);

        //	setbkcolor(BLUE);
        setcolor(RED);
        rectangle((screen_width / 2) + rec_left, rec_top, (screen_width / 2) + rec_right, rec_bottom);
        setfillstyle(SOLID_FILL, RED);
        floodfill(screen_width / 2 + floodfill_x, screen_height - 95, RED);

        setcolor(WHITE);
        arc(screen_width / 2 + arc_x, screen_height - 100, 0, 180, 15);
        setfillstyle(SOLID_FILL, BLUE);
        
        if(score>10 && level==1)
        {
        	score=0;
        	level=2;
		}
		else if(score>20 && level==2)
		{
			score=0;
			level=3;
		}
		else if(score>30 && level==3)
		{
			score=0;
			level=4;
		}
		else if(score>40 && level==4)
		{
			score=0;
			level=5;
		}

        if (enemy_Down <= screen_height)
        {
            setcolor(GREEN);
            rectangle(enemyDir_left + x, enemy_Up, enemyDir_right + x, enemy_Down);
            setfillstyle(SOLID_FILL, GREEN);
            floodfill((screen_width / 2 - 120) + x, screen_height + enemy_floodfill_y, GREEN);

            if(level==2 || level==3 || level==4 || level==5)
            {
            setcolor(RED);
            rectangle(enemy2Dir_left + x1, enemy2_Up, enemy2Dir_right + x1, enemy2_Down);
            setfillstyle(SOLID_FILL, RED);
            floodfill((screen_width / 2 + 20) + x1, screen_height + enemy2_floodfill_y, RED);
			}
			if(level==3 || level==4 || level==5)
			{
			setcolor(YELLOW);
            rectangle(enemy3Dir_left + x2, enemy3_Up, enemy3Dir_right + x2, enemy3_Down);
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(60 + x2, screen_height + enemy3_floodfill_y, YELLOW);
			}
			if(level==4 || level==5)
			{
			setcolor(BLUE);
            rectangle(enemy4Dir_left + x3, enemy4_Up, enemy4Dir_right + x3, enemy4_Down);
            setfillstyle(SOLID_FILL, BLUE);
            floodfill(110 + x3, screen_height + enemy4_floodfill_y, BLUE);	
			}
			if(level==5)
			{
			setcolor(8);
            rectangle(enemy5Dir_left + x4, enemy5_Up, enemy5Dir_right + x4, enemy5_Down);
            setfillstyle(SOLID_FILL, 8);
            floodfill(140 + x4, screen_height + enemy5_floodfill_y, 8);
				
			}
			
            if (value_saver == 0) 
            {
                temp1 = enemy_Up;
                temp2 = enemy_Down;
                temp3 = enemy_floodfill_y;
                temp4 = enemy2_Up;
                temp5 = enemy2_Down;
                temp6 = enemy2_floodfill_y;
                temp7 = enemy3_Up;
                temp8 = enemy3_Down;
                temp9 = enemy3_floodfill_y;
                temp10 = enemy4_Up;
                temp11 = enemy4_Down;
                temp12 = enemy4_floodfill_y;
                temp13 = enemy5_Up;
                temp14 = enemy5_Down;
                temp15 = enemy5_floodfill_y;
                
            }
            value_saver = value_saver + 1;
            enemy_Up = enemy_Up + 10;
            enemy_Down = enemy_Down + 10;
            enemy_floodfill_y = enemy_floodfill_y + 10;
            
            if(level==2 || level==3 || level==4 || level==5)
            {
            enemy2_Up = enemy2_Up + 10;
            enemy2_Down = enemy2_Down + 10;
            enemy2_floodfill_y = enemy2_floodfill_y + 10;
			}
			
			if(level==3 || level==4 || level==5)
			{
			enemy3_Up = enemy3_Up + 10;
            enemy3_Down = enemy3_Down + 10;
            enemy3_floodfill_y = enemy3_floodfill_y + 10;	
			}
			if(level==4 || level==5)
			{
			enemy4_Up = enemy4_Up + 10;
            enemy4_Down = enemy4_Down + 10;
            enemy4_floodfill_y = enemy4_floodfill_y + 10;	
			}
			if(level==5)
			{
			enemy5_Up = enemy5_Up + 10;
            enemy5_Down = enemy5_Down + 10;
            enemy5_floodfill_y = enemy5_floodfill_y + 10;	
			}
           

            if (enemy_Down == screen_height)
            {
                x = rand() % ((screen_width / 2) - 20) + 1;
                enemy_Up = temp1;
                enemy_Down = temp2;
                enemy_floodfill_y = temp3;
               
            }
            else if (enemy_Down == rec_top && (enemyDir_left + x) >= (screen_width / 2) + rec_left && (screen_width / 2) + rec_right >= enemyDir_right + x)
            {
                x = rand() % ((screen_width / 2) - 20) + 1;
                enemy_Up = temp1;
                enemy_Down = temp2;
                enemy_floodfill_y = temp3;
                lives--;
                PlaySound(TEXT("Spaceshiphit.wav"),NULL,SND_ASYNC);
            }
            if (enemy2_Down == screen_height)
            {
                x1 = rand() % ((screen_width / 2) - 150) + 1;
                enemy2_Up = temp4;
                enemy2_Down = temp5;
                enemy2_floodfill_y = temp6;   
            }
            else if (enemy2_Down == rec_top && (enemy2Dir_left + x1) >= (screen_width / 2) + rec_left && (screen_width / 2) + rec_right >= enemy2Dir_right + x1)
            {
                x1 = rand() % ((screen_width / 2) - 150) + 1;
                enemy2_Up = temp4;
                enemy2_Down = temp5;
                enemy2_floodfill_y = temp6;
                lives--;
                PlaySound(TEXT("Spaceshiphit.wav"),NULL,SND_ASYNC);
            }
            if (enemy3_Down == screen_height)
            {
                x2 = rand() % ((screen_width-110) + 1);
                enemy3_Up = temp7;
                enemy3_Down = temp8;
                enemy3_floodfill_y = temp9;   
            }
            else if (enemy3_Down == rec_top && (enemy3Dir_left + x2) >= (screen_width / 2) + rec_left && (screen_width / 2) + rec_right >= enemy3Dir_right + x2)
            {
                x2 = rand() % ((screen_width)-110) + 1;
                enemy3_Up = temp7;
                enemy3_Down = temp8;
                enemy3_floodfill_y = temp9;
                lives--;
                PlaySound(TEXT("Spaceshiphit.wav"),NULL,SND_ASYNC);
            }
            if (enemy4_Down == screen_height)
            {
                x3 = rand() % ((screen_width-170) + 1);
                enemy4_Up = temp10;
                enemy4_Down = temp11;
                enemy4_floodfill_y = temp12;   
            }
            else if (enemy4_Down == rec_top && (enemy4Dir_left + x3) >= (screen_width / 2) + rec_left && (screen_width / 2) + rec_right >= enemy4Dir_right + x3)
            {
                x3 = rand() % ((screen_width)-170) + 1;
                enemy4_Up = temp10;
                enemy4_Down = temp11;
                enemy4_floodfill_y = temp12;
                lives--;
                PlaySound(TEXT("Spaceshiphit.wav"),NULL,SND_ASYNC);
            }
            if (enemy5_Down == screen_height)
            {
                x4 = rand() % ((screen_width-200) + 1);
                enemy5_Up = temp13;
                enemy5_Down = temp14;
                enemy5_floodfill_y = temp15;   
            }
            else if (enemy5_Down == rec_top && (enemy5Dir_left + x4) >= (screen_width / 2) + rec_left && (screen_width / 2) + rec_right >= enemy5Dir_right + x4)
            {
                x4 = rand() % ((screen_width)-200) + 1;
                enemy5_Up = temp13;
                enemy5_Down = temp14;
                enemy5_floodfill_y = temp15;
                lives--;
                PlaySound(TEXT("Spaceshiphit.wav"),NULL,SND_ASYNC);
            }
          
            if(level==1)
            {
            	delay(20);
	    	}
            else if(level==2)
            {
            	delay(18);
			}
			else if(level==3)
			{
				delay(16);
			}
			else if(level==4)
			{
				delay(14);
			}
			else if(level==5)
			{
				delay(12);
			}
            
        } 

        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (rec_right < screen_width / 2)
            {

                rec_left = rec_left + 10;
                rec_right = rec_right + 10;
                arc_x = arc_x + 10;
                floodfill_x = floodfill_x + 10;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (rec_left >= (-screen_width) / 2)
            {
                rec_left = rec_left - 10;
                rec_right = rec_right - 10;
                arc_x = arc_x - 10;
                floodfill_x = floodfill_x - 10;
            }
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            int circle_y = -100;
            while (circle_y >= -screen_height - 100)
            {
                setactivepage(page);
                setvisualpage(1 - page);
                cleardevice();
                
                setcolor(RED);
                settextstyle(6, 0, 5);
         	    sprintf(score_array, "Score : %d", score);
        		outtextxy(3, 0, score_array);

        		setcolor(RED);
        		settextstyle(6, 0, 5);
        		sprintf(lives_array, "Lives : %d", lives);
        		outtextxy(screen_width / 2 - 85, 0, lives_array);

       			setcolor(RED);
        		settextstyle(6, 0, 5);
        		sprintf(level_array, "Level : %d", level);
        		outtextxy(screen_width - 250, 0, level_array);
                
                setcolor(WHITE);
                circle(screen_width / 2 + arc_x, screen_height + circle_y, 8);
                circle_y = circle_y - 10;

                setcolor(RED);
                rectangle(screen_width / 2 + rec_left, screen_height - 100, screen_width / 2 + rec_right, screen_height - 85);
                setfillstyle(SOLID_FILL, RED);
                floodfill(screen_width / 2 + floodfill_x, screen_height - 95, RED);

                setcolor(BLUE);
                arc(screen_width / 2 + arc_x, screen_height - 100, 0, 180, 15);
                setfillstyle(SOLID_FILL, BLUE);

                setcolor(GREEN);
                rectangle(enemyDir_left + x, enemy_Up, enemyDir_right + x, enemy_Down);
                setfillstyle(SOLID_FILL, GREEN);
                floodfill((screen_width / 2 - 120) + x, screen_height + enemy_floodfill_y, GREEN);
                
                if(level==2 || level==3 || level==4 || level==5)
                {
                setcolor(RED);
                rectangle(enemy2Dir_left + x1, enemy2_Up, enemy2Dir_right + x1, enemy2_Down);
                setfillstyle(SOLID_FILL, RED);
                floodfill((screen_width / 2 + 20) + x1, screen_height + enemy2_floodfill_y, RED);
				}
				if(level==3 || level==4 || level==5)
				{
					setcolor(YELLOW);
            		rectangle(enemy3Dir_left + x2, enemy3_Up, enemy3Dir_right + x2, enemy3_Down);
            		setfillstyle(SOLID_FILL, YELLOW);
            		floodfill(60 + x2, screen_height + enemy3_floodfill_y, YELLOW);
				}
				if(level==4 || level==5)
				{
				  setcolor(BLUE);
                  rectangle(enemy4Dir_left + x3, enemy4_Up, enemy4Dir_right + x3, enemy4_Down);
                  setfillstyle(SOLID_FILL, BLUE);
                  floodfill(110 + x3, screen_height + enemy4_floodfill_y, BLUE);	
				}
				if(level==5)
				{
				  setcolor(8);
                  rectangle(enemy5Dir_left + x4, enemy5_Up, enemy5Dir_right + x4, enemy5_Down);
                  setfillstyle(SOLID_FILL, 8);
                  floodfill(140 + x4, screen_height + enemy5_floodfill_y,8);	
				}
				
               if ((screen_height + circle_y) == enemy_Down && (screen_width / 2 + arc_x) >= (enemyDir_left + x) && (screen_width / 2 + arc_x) <= (enemyDir_right + x))
                {
                    x = rand() % ((screen_width / 2 - 20) + 1);
                    score = score + 1;
                    tempscore=tempscore+1;
                    enemy_Up = temp1;
                    enemy_Down = temp2;
                    enemy_floodfill_y = temp3;
                    PlaySound(TEXT("mixkit-unlock-game-notification-253.wav"),NULL,SND_ASYNC);
                    break;
                }
                else if ((screen_height + circle_y) == enemy2_Down && (screen_width / 2 + arc_x) >= (enemy2Dir_left + x1) && (screen_width / 2 + arc_x) <= (enemy2Dir_right + x1))
                {
                    x1 = rand() % ((screen_width / 2 - 150) + 1);
                    score = score + 1;
                    tempscore=tempscore+1;
                    enemy2_Up = temp4;
                    enemy2_Down = temp5;
                    enemy2_floodfill_y = temp6;
                    PlaySound(TEXT("mixkit-unlock-game-notification-253.wav"),NULL,SND_ASYNC);
                    break;
                }
                 else if ((screen_height + circle_y) == enemy3_Down && (screen_width / 2 + arc_x) >= (enemy3Dir_left + x2) && (screen_width / 2 + arc_x) <= (enemy3Dir_right + x2))
                {
                    x2 = rand() % ((screen_width-110) + 1);
                    score = score + 1;
                    tempscore=tempscore+1;
                    enemy3_Up = temp7;
                    enemy3_Down = temp8;
                    enemy3_floodfill_y = temp9;
                    PlaySound(TEXT("mixkit-unlock-game-notification-253.wav"),NULL,SND_ASYNC);
                    break;
                }
                  else if ((screen_height + circle_y) == enemy4_Down && (screen_width / 2 + arc_x) >= (enemy4Dir_left + x3) && (screen_width / 2 + arc_x) <= (enemy4Dir_right + x3))
                {
                    x3 = rand() % ((screen_width-170) + 1);
                    score = score + 1;
                    tempscore=tempscore+1;
                    enemy4_Up = temp10;
                    enemy4_Down = temp11;
                    enemy4_floodfill_y = temp12;
                    PlaySound(TEXT("mixkit-unlock-game-notification-253.wav"),NULL,SND_ASYNC);
                    break;
                }
                else if ((screen_height + circle_y) == enemy5_Down && (screen_width / 2 + arc_x) >= (enemy5Dir_left + x4) && (screen_width / 2 + arc_x) <= (enemy5Dir_right + x4))
                {
                    x4 = rand() % ((screen_width-200) + 1);
                    score = score + 1;
                    tempscore=tempscore+1;
                    enemy5_Up = temp13;
                    enemy5_Down = temp14;
                    enemy5_floodfill_y = temp15;
                    PlaySound(TEXT("mixkit-unlock-game-notification-253.wav"),NULL,SND_ASYNC);
                    break;
                }

                page = 1 - page;
            }
        }
        else if(GetAsyncKeyState(VK_ESCAPE))
        {
        	exit(0);
		}
		
		if(lives==0)
		{
		  break;
		}
		if(score>50 && level==5)
		{
	      break;
		}
		if(tempscore>highscore)
		{
			fstream infile("highscore1.txt",ios::out);
			infile<<tempscore;
		}
		
		

        page = 1 - page;

       
    }
}
	


void instructions()
{
	cleardevice();
	
	
	setcolor(BLUE);
	settextstyle(6,0,6);
	
	outtextxy(screen_width/2-260,screen_height/2-100,"INSTRUCTIONS");
	
	setcolor(RED);
	settextstyle(4,0,2);
	outtextxy(screen_width/2-400,screen_height/2,"Press Arrow Keys to move Spaceship Left and right.");
	
	setcolor(RED);
	settextstyle(4,0,2);
	outtextxy(screen_width/2-400,screen_height/2+50,"Press Space Bar To Shoot");
	
	setcolor(RED);
	settextstyle(4,0,2);
	outtextxy(screen_width/2-400,screen_height/2+100,"Complete All 5 Levels to Win.");
	
	setcolor(RED);
	settextstyle(4,0,2);
	outtextxy(screen_width/2-400,screen_height/2+150,"Hit Enemy to gain score.Don't Get hit by enemy.");
	
	setcolor(RED);
	settextstyle(4,0,2);
	outtextxy(screen_width/2-400,screen_height/2+200,"If It happens You will lose one life.");
	
	outtextxy(screen_width/2-400,screen_height/2+250,"Press any Key To Continue.");
	
	getch();
	PlaySound(TEXT("optionvoice.wav"),NULL,SND_ASYNC);
	
	
	
	
}

int main()
{
	
	initwindow(screen_width,screen_height,"The Spaceshooter",0,0,true,true);
	
	
	
	
	srand(time(0));
	int highscore=0;
	char Highscore[20];
	
	fstream infile("highscore1.txt",ios::in | ios::out);
	infile>>highscore;
	do{
	
		cleardevice();
		
		setcolor(YELLOW);
		settextstyle(6,0,3);
		sprintf(Highscore,"Highscore : %d",highscore);
		outtextxy(0,0,Highscore);
		
	    setcolor(BLUE);
	    setbkcolor(BLACK);
	    settextstyle(6,0,8);
	    outtextxy(screen_width/2-450,screen_height/2-100,"SPACE SHOOTER");
	
	    setcolor(RED);
	    settextstyle(4,0,2);
	    outtextxy(screen_width/2-150,screen_height/2+50,"1.START THE GAME.");
	
	    setcolor(RED);
	    settextstyle(4,0,2);
	    outtextxy(screen_width/2-150,screen_height/2+100,"2.INSTRUCTIONS.");
	
	    setcolor(RED);
	    settextstyle(4,0,2);
	    outtextxy(screen_width/2-150,screen_height/2+150,"3.EXIT THE GAME.");
	
        char op=getch();
	
   
	
	if(op=='2')
	{
		PlaySound(TEXT("optionvoice.wav"),NULL,SND_ASYNC);
        instructions();
	}
	else if(op=='3')
	{
		PlaySound(TEXT("optionvoice.wav"),NULL,SND_ASYNC);
		exit(0);
	}
	else if(op=='1')
	{
		PlaySound(TEXT("optionvoice.wav"),NULL,SND_ASYNC);
	do{
		
		instructions();
		gameplay();
		endgame();
	  }while(1);
	}
	
		
	}while(1);
   
	system("pause");
	return 0;
	
	
	
}
