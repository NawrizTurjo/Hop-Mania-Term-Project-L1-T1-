#include<iostream>
using namespace std;
#include<windows.h>
#include<mmsystem.h>
# include "iGraphics.h"
#include<string.h>
#include<stdlib.h>
#define NUMBER_OF_BACKGROUND_ROWS 10
#define MAX_LENGTH 30

char strscore[20]="0";
char bc[][100]= {"bc\\original menu.bmp"};
char bg[][100]= {"bg\\car.bmp","bg\\opening.bmp","bg\\truck.bmp","bg\\block.bmp","bg\\car2.bmp","bg\\car3.bmp","bg\\ending.bmp","bg\\barrier.bmp","bg\\road.bmp","bg\\water.bmp","bg\\main_bg.bmp","bg\\difficulty.bmp","bg\\flash_screen.bmp","bg\\help.bmp","bg\\name.bmp"};
char buttons[][100]= {"buttons\\PLAY.bmp","buttons\\HIGH.bmp","buttons\\END.bmp","buttons\\over.bmp","buttons\\score.bmp","buttons\\about.bmp","buttons\\help.bmp","buttons\\menu.bmp"};
char game[][50]= {"game\\1.bmp","game\\2.bmp","game\\3.bmp","game\\4.bmp","game\\5.bmp","game\\6.bmp","game\\7.bmp","game\\8.bmp","game\\9.bmp","game\\10.bmp"};
int start=0,totalBg=0;
int gameX=0;
int gameY=0;
int game_index=0;
char character_move[][50]= {"character\\d1.bmp","character\\u1.bmp","character\\l1.bmp","character\\r2.bmp"};
int character_Index=1;

int r=0;
int g=0;
int b=0;
int stage=-2;
int *pstage=&stage;
int rx=600;
int *prx=&rx;
int ry=50;
int *pry=&ry;
int rdx=25;
int rdy=25;
int playx=150;
int playy=384;
int highx=150;
int highy=284;
int aboutx=150;
int abouty=184;
int helpx=150;
int helpy=84;
int endx=850;
int endy=50;
int widthplay=150;
int heigthplay=50;
int widthend=150;
int heigthend=50;
int halfx=512;
int halfy=288;
int namex=362;
int namey=188;
int namew=300;
int nameh=100;
int screenwidth=1024;
int screenheigth=576;
int welcomex=375;
int welcomey=500;
int blockx1=0;
int *pblockx1=&blockx1;
int blockx2=410;
int *pblockx2=&blockx2;
int blockx3=820;
int *pblockx3=&blockx3;

int blocky=87;
int *pblocky=&blocky;
int blocky1=187;
int *pblocky1=&blocky1;
int blocky2=387;
int *pblocky2=&blocky2;
int blocky3=287;
int *pblocky3=&blocky3;

int dblockx=170;
int dblocky=50;
int blockx4=85;
int *pblockx4=&blockx4;
int blockx5=495;
int *pblockx5=&blockx5;
int blockx6=905;
int *pblockx6=&blockx6;
int down=50;
int speed1;
int *pspeed1=&speed1;
int speed2;
int *pspeed2=&speed2;

int movetime1=100;
int movetime2=85;
int movetime3=75;
int movetime4=60;
int movetime5=45;
int movetime6=40;
int movetime7=15;

int score=0;
int *pscore=&score;
int scoreplus=1;
int *pscoreplus=&scoreplus;
int blockx7=blockx1;
int *pblockx7=&blockx7;
int blockx8=blockx2;
int *pblockx8=&blockx8;
int blockx9=blockx3;
int *pblockx9=&blockx9;
int blockx10=blockx4;
int *pblockx10=&blockx10;
int blockx11=blockx5;
int *pblockx11=&blockx11;
int blockx12=blockx6;
int *pblockx12=&blockx12;

int life=3;
int *plife=&life;
char strlife[10];

int level=1;
int *plevel=&level;
char strlevel[10]="1";
char god[10]="GODMOD";

int difficulty_level_x_coordinate[]= {100,387,674};
int difficulty_level_y_coordinate=200;
int difficulty_level_width=250;
int difficulty_level_height=60;

int isplayermove=1;
int ispausetimer=0;
int opening=1;
int opening_call=0;

int mode=0;
int len=0;
char str[100],name[100];
int difficulty;
int isPlaybgm=0;
char ScoreString[6][100];
char temp_string[100];

int back_to_menu_x=670;
int back_to_menu_y=0;
int width_back_to_menu_x=354;
int width_back_to_menu_y=50;

///time_t current,lastclick=time(0),last_down_click;

#define MAX_SIZE 6

typedef struct PLAYER
{
    char playerName[100];
    int playerScore;
} PLAYER;

PLAYER leaderboard[MAX_SIZE];

void showLeaderboard()
{
    printf("Current Leaderboard:\n");
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        printf("%d. %s: %d\n", i + 1, leaderboard[i].playerName, leaderboard[i].playerScore);
    }
}

void readFromFile(int difficulty)
{
    FILE *f1;
    FILE *f2;
    if (difficulty == 1)
    {
        f1 = fopen("EasyName.txt", "r");
        f2 = fopen("EasyScore.txt", "r");
    }
    else if (difficulty == 2)
    {
        f1 = fopen("MediumName.txt", "r");
        f2 = fopen("MediumScore.txt", "r");
    }
    else if (difficulty == 3)
    {
        f1 = fopen("HardName.txt", "r");
        f2 = fopen("HardScore.txt", "r");
    }

    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        fgets(leaderboard[i].playerName, 100, f1);
        fscanf(f2, "%d", &leaderboard[i].playerScore);
    }

    fclose(f1);
    fclose(f2);
}

void saveToFile(int difficulty)
{
    FILE *f1;
    FILE *f2;
    if (difficulty == 1)
    {
        f1 = fopen("EasyName.txt", "w");
        f2 = fopen("EasyScore.txt", "w");
    }
    else if (difficulty == 2)
    {
        f1 = fopen("MediumName.txt", "w");
        f2 = fopen("MediumScore.txt", "w");
    }
    else if (difficulty == 3)
    {
        f1 = fopen("HardName.txt", "w");
        f2 = fopen("HardScore.txt", "w");
    }

    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        fprintf(f1, "%s", leaderboard[i].playerName);
        fprintf(f2, "%d\n", leaderboard[i].playerScore);
    }

    fclose(f1);
    fclose(f2);
    showLeaderboard();
}

void addPlayer(char *name, int score, int difficulty)
{
    // Add the new player to the end of the array
    strcpy(leaderboard[MAX_SIZE - 1].playerName, name);
    leaderboard[MAX_SIZE - 1].playerScore = score;

    // Sort the array in descending order based on playerScore
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            if (leaderboard[j].playerScore > leaderboard[i].playerScore)
            {
                PLAYER temp = leaderboard[i];
                leaderboard[i] = leaderboard[j];
                leaderboard[j] = temp;
            }
        }
    }

    // Save the updated leaderboard to file
    saveToFile(difficulty);
}

char* convert_to_string(int i)
{
    char *str=(char*)malloc(sizeof(char)*10);
    sprintf(str,"%d",i);
    return str;
}

/*
function iDraw() is called again and again by the system.
*/
int iscrash=0;
void detect_crash()
{
    if(iscrash)
    {
        PlaySound("crash.wav",NULL,SND_ASYNC);
        iscrash=0;
    }
}

int is_button_pressed=0;
void button_check()
{
    if(is_button_pressed)
    {
        PlaySound("Button.wav",NULL,SND_ASYNC);
        is_button_pressed=0;
    }
}

int opening_music=1;
void opening_screen()
{
    iShowBMP(0,0,bg[12]);
    iSetColor(255,255,255);
    iText(350,200,"H   O   P       M   A   N   I   A",GLUT_BITMAP_TIMES_ROMAN_24);
    opening_call++;
    if(opening_call>=125)
    {
        *pstage=1;
    }
    if(opening_music)
    {
        PlaySound("opening.wav",NULL,SND_ASYNC);
        opening_music=0;
    }
}
void difficulty_level()
{
    iShowBMP(0,0,bg[11]);
    iSetColor(0,0,0);
    iText(400,300,"Choose a difficuly level",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,0,255);
    iFilledRectangle(100,200,250,60);
    iSetColor(0,0,0);
    iText(200,225,"Easy",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,0,255);
    iFilledRectangle(387,200,250,60);
    iSetColor(0,0,0);
    iText(477,225,"Medium",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,0,255);
    iFilledRectangle(674,200,250,60);
    iSetColor(0,0,0);
    iText(774,225,"Hard",GLUT_BITMAP_HELVETICA_18);
    //iShowBMP2(endx,endy,buttons[7],0);
}

void high_score_screen()
{
    iShowBMP(0,0,bg[11]);
    iSetColor(0,0,0);
    iRectangle(31,450,300,100);
    iSetColor(0,0,0);
    iText(150,490,"Easy",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,0,0);
    iRectangle(362,450,300,100);
    iSetColor(0,0,0);
    iText(460,490,"Medium",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,0,0);
    iRectangle(693,450,300,100);
    iSetColor(0,0,0);
    iText(820,490,"Hard",GLUT_BITMAP_TIMES_ROMAN_24);
    //iShowBMP2(endx,endy,buttons[7],0);
}
void Easy()
{
    high_score_screen();
    iSetColor(0,0,0);
    iText(70,400,ScoreString[0],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,380,leaderboard[0].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,350,ScoreString[1],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,330,leaderboard[1].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,300,ScoreString[2],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,280,leaderboard[2].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,250,ScoreString[3],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,230,leaderboard[3].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,200,ScoreString[4],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(70,180,leaderboard[4].playerName,GLUT_BITMAP_HELVETICA_18);
}

void Medium()
{
    high_score_screen();
    iSetColor(0,0,0);
    iText(400,400,ScoreString[0],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,380,leaderboard[0].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,350,ScoreString[1],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,330,leaderboard[1].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,300,ScoreString[2],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,280,leaderboard[2].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,250,ScoreString[3],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,230,leaderboard[3].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,200,ScoreString[4],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(400,180,leaderboard[4].playerName,GLUT_BITMAP_HELVETICA_18);
}

void Hard()
{
    high_score_screen();
    iSetColor(0,0,0);
    iText(735,400,ScoreString[0],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,380,leaderboard[0].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,350,ScoreString[1],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,330,leaderboard[1].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,300,ScoreString[2],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,280,leaderboard[2].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,250,ScoreString[3],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,230,leaderboard[3].playerName,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,200,ScoreString[4],GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(735,180,leaderboard[4].playerName,GLUT_BITMAP_HELVETICA_18);
}

void page0()
{
    iShowBMP(0,0,bg[14]);
    iSetColor(255,0,0);
    iRectangle(namex,namey,namew,nameh);
    iSetColor(255,0,255);
    iText(395,310,"Enter Your Name Here",GLUT_BITMAP_TIMES_ROMAN_24);
}
void page1()
{
    iShowBMP(0,0,bg[1]);
    iShowBMP2(playx,playy,buttons[0],0);
    iShowBMP2(highx,highy,buttons[1],0);
    iShowBMP2(endx,endy,buttons[2],0);
    iShowBMP2(aboutx,abouty,buttons[5],0);
    iShowBMP2(helpx,helpy,buttons[6],0);
    iSetColor(255,255,255);
    iText(welcomex,welcomey,"Welcome To Hop Mania",GLUT_BITMAP_HELVETICA_18);
}
///about and help stage=-100 and -101
void about()
{
    iShowBMP(0,0,bg[1]);
    iSetColor(123,55,236);
    iText(200,400,"Created By Nawriz Ahmed Turjo",GLUT_BITMAP_HELVETICA_18);
    iShowBMP2(endx,endy,buttons[7],0);
}
void help()
{
    iShowBMP(0,0,bg[13]);
    iShowBMP2(endx,endy,buttons[7],0);
}
void page2()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,screenwidth,screenheigth);
}
void page3()
{
    iShowBMP(0,0,bg[6]);
}
void initialstage()
{
    *prx=600 ;
    *pry=50;
    *pblockx1=0;
    *pblockx2=410;
    *pblockx3=820;
    *pblocky=87;
    *pblocky1=187;
    *pblocky2=387;
    *pblocky3=287;
    *pblockx4=85;
    *pblockx5=495;
    *pblockx6=905;
}
void screencheck()
{
    if(rx<=155 || (rx+rdx)>=screenwidth || ry<=0)
    {
        initialstage();
        *plife-=1;
        ispausetimer=1;
        isplayermove=1;
        iscrash=1;
        itoa(life,strlife,10);
        if(score>0)
        {
            if(stage==2)
            {
                *pscore-=1;
            }
            else if(stage==3)
            {
                *pscore-=1;
            }
            else if(stage==4)
            {
                *pscore-=1;
            }
            else if(stage==5)
            {
                *pscore-=1;
            }
            else if(stage==6)
            {
                *pscore-=1;
            }
            else if(stage==7)
            {
                *pscore-=1;
            }
            else if(stage==8)
            {
                *pscore-=1;
            }
        }
        itoa(score,strscore,10);
    }
}
void SCREENUP()
{
    if((ry+rdy)>=halfy)
    {
        *pry-=down;
        *pblocky-=down;
        *pblocky1-=down;
        *pblocky2-=down;
        *pblocky3-=down;
        gameY-=57;
    }
    if(blocky<=60)
    {
        *pblocky=487;
    }
    if(blocky1<=60)
    {
        *pblocky1=487;
    }
    if(blocky2<=60)
    {
        *pblocky2=487;
    }
    if(blocky3<=60)
    {
        *pblocky3=487;
    }
}
void forceup()
{

    *pry-=down;
    *pblocky-=down;
    *pblocky1-=down;
    *pblocky2-=down;
    *pblocky3-=down;
    if(blocky<=60)
    {
        *pblocky=487;
    }
    if(blocky1<=60)
    {
        *pblocky1=487;
    }
    if(blocky2<=60)
    {
        *pblocky2=487;
    }
    if(blocky3<=60)
    {
        *pblocky3=487;
    }
}
void createCharacter()
{
    iShowBMP2(rx,ry,character_move[character_Index],0);
}
void create_gamebg()
{
    iShowBMP(0,0,bg[10]);
    ///MOVING BACKGROUND
    if(gameY<=-57)
    {
        gameY=0;
        start++;
    }

    if(start==NUMBER_OF_BACKGROUND_ROWS)
    {
        start=0;
    }
    totalBg=0;
    for(int i=start;; i++)
    {
        if(i==NUMBER_OF_BACKGROUND_ROWS)
        {
            i=0;
        }
        if(totalBg == NUMBER_OF_BACKGROUND_ROWS)
        {
            break;
        }
        iShowBMP(0, totalBg * 57 + gameY, game[i]);
        totalBg++;
    }
}

void createRectangle()
{
    iShowBMP2(blockx1,blocky,bg[4],0);
    iShowBMP2(blockx2,blocky,bg[5],0);
    iShowBMP2(blockx3,blocky,bg[4],0);
    iShowBMP(blockx4,blocky1,bg[3]);
    iShowBMP(blockx5,blocky1,bg[3]);
    iShowBMP(blockx6,blocky1,bg[3]);
    iShowBMP(blockx7,blocky2,bg[3]);
    iShowBMP(blockx8,blocky2,bg[3]);
    iShowBMP(blockx9,blocky2,bg[3]);
    iShowBMP2(blockx10,blocky3,bg[2],0);
    iShowBMP2(blockx11,blocky3,bg[0],0);
    iShowBMP2(blockx12,blocky3,bg[2],0);
}

void createBarrier()
{
    iShowBMP(0,0,bg[7]);
    iShowBMP2(0,400,buttons[4],0);
    iShowBMP2(0,300,buttons[4],0);
    iShowBMP2(0,200,buttons[4],0);
    iSetColor(58,72,248);
    iFilledRectangle(10,100,135,50);
    if(!ispausetimer)
    {
        iSetColor(255,255,255);
        iText(25,118,"Pause Game",GLUT_BITMAP_HELVETICA_18);
    }
    else
    {
        iSetColor(255,255,255);
        iText(20,118,"Resume Game",GLUT_BITMAP_HELVETICA_18);
    }
    iSetColor(255,0,0);
    iText(50,30,"END",GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,255);
    iText(50,500,"Menu",GLUT_BITMAP_HELVETICA_18);
}
void createBarrierGODMOD()
{
    iShowBMP(0,0,bg[7]);
    iSetColor(245,44,7);
    iFilledRectangle(0,400,155,50);
    iSetColor(245,44,7);
    iFilledRectangle(0,300,155,50);
    iSetColor(245,44,7);
    iFilledRectangle(0,200,155,50);
    iSetColor(255,0,0);
    iText(50,30,"END",GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,255);
    iText(50,500,"Menu",GLUT_BITMAP_HELVETICA_18);
}


void showscore()
{
    iSetColor(255,255,255);
    iText(35,418,"Score:",GLUT_BITMAP_HELVETICA_18);
    iText(90,418,strscore,GLUT_BITMAP_HELVETICA_18);
}
void show_level()
{
    iSetColor(255,255,255);
    iText(35,318,"Level:",GLUT_BITMAP_HELVETICA_18);
    iText(90,318,strlevel,GLUT_BITMAP_HELVETICA_18);
}
void show_levelGODMOD()
{
    iSetColor(255,255,255);
    iText(5,318,"Level:",GLUT_BITMAP_HELVETICA_18);
    iText(60,318,strlevel,GLUT_BITMAP_HELVETICA_18);
}
void show_life()
{
    iSetColor(255,255,255);
    iText(35,218,"Life:",GLUT_BITMAP_HELVETICA_18);
    iText(75,218,strlife,GLUT_BITMAP_HELVETICA_18);
}


void show_road_water()
{
    iShowBMP(0,blocky,bg[8]);
    iShowBMP(0,blocky3,bg[8]);
    iShowBMP(0,blocky1,bg[9]);
    iShowBMP(0,blocky2,bg[9]);
}

void moveRectangle()
{
    if(!ispausetimer)
    {
        *pblockx1+=speed2;
        *pblockx2+=speed2;
        *pblockx3+=speed2;
        if((blockx1)>=1024)
        {
            (*pblockx1)=-dblockx;
        }
        if((blockx2)>=1024)
        {
            (*pblockx2)=-dblockx;
        }
        if((blockx3)>=1024)
        {
            (*pblockx3)=-dblockx;
        }

        *pblockx4-=speed1;
        *pblockx5-=speed1;
        *pblockx6-=speed1;
        if((blockx4+dblockx)<=0)
        {
            *pblockx4=1024;
        }
        if((blockx5+dblockx)<=0)
        {
            *pblockx5=1024;
        }
        if((blockx6+dblockx)<=0)
        {
            *pblockx6=1024;
        }
        if((ry+rdy>=blocky1 && ry<=blocky1+dblocky))
        {
            *prx-=speed1;
        }

        *pblockx7+=speed1;
        *pblockx8+=speed1;
        *pblockx9+=speed1;
        if((blockx7)>=1024)
        {
            *pblockx7=-dblockx;
        }
        if((blockx8)>=1024)
        {
            *pblockx8=-dblockx;
        }
        if((blockx9)>=1024)
        {
            *pblockx9=-dblockx;
        }
        if((ry+rdy>=blocky2 && ry<=blocky2+dblocky))
        {
            *prx+=speed1;
        }

        *pblockx10-=speed2;
        *pblockx11-=speed2;
        *pblockx12-=speed2;
        if((blockx10+dblockx)<=0)
        {
            (*pblockx10)=1024;
        }
        if((blockx11+dblockx)<=0)
        {
            (*pblockx11)=1024;
        }
        if((blockx12+dblockx)<=0)
        {
            (*pblockx12)=1024;
        }
    }
}


void moveRectangle1()
{
    if(stage==2)
    {
        moveRectangle();
        *plevel=1;
        itoa(level,strlevel,10);
    }
}
void moveRectangle2()
{
    if(stage==3)
    {
        moveRectangle();
        *plevel=2;
        itoa(level,strlevel,10);
    }
}
void moveRectangle3()
{
    if(stage==4)
    {
        moveRectangle();
        *plevel=3;
        itoa(level,strlevel,10);
    }
}
void moveRectangle4()
{
    if(stage==5)
    {
        moveRectangle();
        *plevel=4;
        itoa(level,strlevel,10);
    }
}
void moveRectangle5()
{
    if(stage==6)
    {
        moveRectangle();
        *plevel=5;
        itoa(level,strlevel,10);
    }
}
void moveRectangle6()
{
    if(stage==7)
    {
        moveRectangle();
        *plevel=6;
        itoa(level,strlevel,10);
    }
}
void moveRectangle7()
{
    if(stage==8)
    {
        moveRectangle();
        strcpy(strlevel,god);
    }
}


void check1()
{
    if(ry+rdy>=blocky && ry<=blocky+dblocky)
    {
        if(rx+rdx>=blockx1 && rx+rdx<blockx1+dblockx)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx+rdx>=blockx2 && rx+rdx<blockx2+dblockx)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx+rdx>=blockx3 && rx+rdx<blockx3+dblockx)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx<=blockx1+dblockx && rx>blockx1)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx<=blockx2+dblockx && rx>blockx2)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx<=blockx3+dblockx && rx>blockx3)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
    }
    else if(ry+rdy>=blocky3 && ry<=blocky3+dblocky)
    {
        if(rx+rdx>=blockx10 && rx+rdx<blockx10+dblockx)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx+rdx>=blockx11 && rx+rdx<blockx11+dblockx)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx+rdx>=blockx12 && rx+rdx<blockx12+dblockx)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx<=blockx10+dblockx && rx>blockx10)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx<=blockx11+dblockx && rx>blockx11)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(rx<=blockx12+dblockx && rx>blockx12)
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
    }

    else if(ry+rdy>=blocky1 && ry<=blocky1+dblocky)
    {
        if(!((rx+rdx>=blockx4 && rx+rdx<=blockx4+dblockx)||(rx+rdx>=blockx5 && rx+rdx<=blockx5+dblockx)||(rx+rdx>=blockx6 && rx+rdx<=blockx6+dblockx)))
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(!((rx<=blockx4+dblockx && rx>blockx4)||(rx<=blockx5+dblockx && rx>blockx5)||(rx<=blockx6+dblockx && rx>blockx6)))
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }

    }
    else if(ry+rdy>=blocky2 && ry<=blocky2+dblocky)
    {
        if(!((rx+rdx>=blockx7 && rx+rdx<=blockx7+dblockx)||(rx+rdx>=blockx8 && rx+rdx<=blockx8+dblockx)||(rx+rdx>=blockx9 && rx+rdx<=blockx9+dblockx)))
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
        else if(!((rx<=blockx7+dblockx && rx>blockx7)||(rx<=blockx8+dblockx && rx>blockx8)||(rx<=blockx9+dblockx && rx>blockx9)))
        {
            initialstage();
            *plife-=1;
            ispausetimer=1;
            isplayermove=1;
            itoa(life,strlife,10);
            *pscore-=1;
            iscrash=1;
        }
    }
    itoa(score,strscore,10);
}

int pseudo_score=0;
void forcemove()
{
    if(!ispausetimer)
    {
        if(isplayermove==0 && stage>=2)
        {
            forceup();
        }
        else if(stage>=2 && isplayermove==1)
        {
            isplayermove=0;
        }
        //pseudo_score=score;
    }
}


void scorecheck()
{
    if(score>=100 && score<200)
    {
        *pscoreplus=2;
        *pstage=3;
    }
    else if(score>=200 && score<300)
    {
        *pscoreplus=3;
        *pstage=4;
    }
    else if(score>=300 && score<400)
    {
        *pscoreplus=4;
        *pstage=5;
    }
    else if(score>=400 && score<500)
    {
        *pscoreplus=5;
        *pstage=6;
    }
    else if(score>=500 && score<1000)
    {
        *pscoreplus=6;
        *pstage=7;
    }
    if(score>=1000)
    {
        *pscoreplus=10;
        *pstage=8;
        ispausetimer=0;
    }
    if(life<=0)
    {
        *pstage=0;
    }
}


void callidraw()
{
    page2();
    create_gamebg();
    show_road_water();
    createRectangle();
    createCharacter();
    createBarrier();
    showscore();
    show_level();
    show_life();
    check1();
    scorecheck();
    screencheck();
    detect_crash();
    button_check();
    /*current=time(0);
    if(current-lastclick>=5)
    {
        forceup();
        lastclick=time(0);
    }
    if(!ispausetimer)
    {
        current=time(0);
    }*/
}
void callidrawGODMOD()
{
    page2();
    create_gamebg();
    show_road_water();
    createRectangle();
    createCharacter();
    createBarrierGODMOD();
    showscore();
    show_levelGODMOD();
    show_life();
    check1();
    scorecheck();
    screencheck();
    detect_crash();
    button_check();
    /*current=time(0);
    if(current-lastclick>=5)
    {
        forceup();
        lastclick=time(0);
    }
    if(!ispausetimer)
    {
        current=time(0);
    }*/
}


void iDraw()
{
    iClear();
    if(stage==-2)
    {
        opening_screen();
        button_check();
    }

    if(stage==1)
    {
        page1();
        button_check();
    }
    if(stage==-1)
    {
        difficulty_level();
        button_check();
    }
    if(stage==2)
    {
        callidraw();
    }
    if(stage==3)
    {
        callidraw();
    }
    if(stage==4)
    {
        callidraw();
    }
    if(stage==5)
    {
        callidraw();
    }
    if(stage==6)
    {
        callidraw();
    }
    if(stage==7)
    {
        callidraw();
    }
    if(stage==8)
    {
        callidrawGODMOD();
    }
    if(stage==0)
    {
        button_check();
        page0();
        if(mode==1)
        {
            iSetColor(255,0,255);
            iText(420,235,str,GLUT_BITMAP_HELVETICA_18);
        }
    }
    if(stage==-3)
    {
        page3();
        button_check();
    }
    if(stage==-100)
    {
        about();
        button_check();
    }
    if(stage==-101)
    {
        help();
        button_check();
    }
    if(stage==-4)
    {
        high_score_screen();
        button_check();
    }
    if(stage==-5)
    {
        Easy();
        button_check();
    }
    if(stage==-6)
    {
        Medium();
        button_check();
    }
    if(stage==-7)
    {
        Hard();
        button_check();
    }
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(stage==0)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if((mx>=namex && mx<=(namex+namew)) && (my>=namey && my<=(namey+nameh)))
            {
                mode=1;
                is_button_pressed=1;
            }
        }
    }
    else if(stage==1)
    {
        if((mx>=playx && mx<=(playx+widthplay)) && (my>=playy && my<=(playy+heigthplay)))
        {
            //printf("2 x = %d, y= %d\n",mx,my);
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                *pstage=-1;
                is_button_pressed=1;
            }
        }
        if((mx>=endx && mx<=(endx+widthend))&&(my>=endy && my<=(endy+heigthend)))
        {
            if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
            {
                {
                    is_button_pressed=1;///doesn't work
                    exit(0);
                }
            }
        }
        if((mx>=aboutx && mx<=(aboutx+widthplay)) && (my>=abouty && my<=(abouty+heigthplay)))
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                *pstage=-100;
                is_button_pressed=1;
            }
        }
        if((mx>=helpx && mx<=(helpx+widthplay)) && (my>=helpy && my<=(helpy+heigthplay)))
        {
            //printf("2 x = %d, y= %d\n",mx,my);
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                *pstage=-101;
                is_button_pressed=1;
            }
        }
        if((mx>=highx && mx<=(highx+widthplay)) && (my>=highy && my<=(highy+heigthplay)))
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                *pstage=-4;
                is_button_pressed=1;
            }
        }
    }
    else if(stage==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            for(int i=0; i<3; i++)
            {
                if(mx>=difficulty_level_x_coordinate[i] && mx<=(difficulty_level_x_coordinate[i]+difficulty_level_width) && my>=difficulty_level_y_coordinate && my<=(difficulty_level_y_coordinate+difficulty_level_height))
                {
                    ispausetimer=0;
                    isplayermove=1;
                    is_button_pressed=1;
                    *pstage=2;
                    if(i==0)
                    {
                        difficulty=1;
                        *plife=5;
                        itoa(life,strlife,10);
                        speed1=15;
                        speed2=10;
                    }
                    else if(i==1)
                    {
                        difficulty=2;
                        *plife=3;
                        itoa(life,strlife,10);
                        speed1=20;
                        speed2=15;
                    }
                    else if(i==2)
                    {
                        difficulty=3;
                        *plife=2;
                        itoa(life,strlife,10);
                        speed1=25;
                        speed2=20;
                    }
                }
            }
            if((mx>=back_to_menu_x && mx<=(back_to_menu_x+width_back_to_menu_x))&&(my>=back_to_menu_y && my<=(back_to_menu_y+width_back_to_menu_y)))
            {
                *pstage=1;
                is_button_pressed=1;
            }
        }
    }
    else if(stage>=2)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(stage!=8)
            {
                if((mx>=10 && mx<=145)&&(my>=100 && my<=150))
                {
                    ispausetimer=!ispausetimer;
                    is_button_pressed=1;
                }
            }
            if((mx>=0 && mx<=155) && (my>=0 && my<=50))
            {
                *pstage=0;
                is_button_pressed=1;
                initialstage();
            }
            if((mx>=0 && mx<=155) && (my>=480 && my<=530))
            {
                *pstage=1;
                *pscore=0;
                itoa(score,strscore,10);
                is_button_pressed=1;
                initialstage();
                ///!!game will not be saved
            }
        }
    }
    else if(stage<=-100)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if((mx>=endx && mx<=(endx+widthend))&&(my>=endy && my<=(endy+heigthend)))
            {
                *pstage=1;
                is_button_pressed=1;
            }
        }
    }
    else if(stage==-3)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if((mx>=130 && mx<=500)&&(my>=195 && my<=260))
            {
                ///Restart logic
                initialstage();
                *pstage=-1;
                *pscore=0;
                itoa(score,strscore,10);
                isplayermove=1;
                is_button_pressed=1;
            }
            else if((mx>=130 && mx<=500)&&(my>=125 && my<=190))
            {
                ///MENU
                *pstage=1;
                *pscore=0;
                itoa(score,strscore,10);
                //isplayermove=1;
                is_button_pressed=1;
            }
            else if(((mx>=130 && mx<=500)&&(my>=65 && my<=120)))
            {
                ///HIGH SCORE
                *pstage=-4;
                *pscore=0;
                itoa(score,strscore,10);
                //isplayermove=1;
                is_button_pressed=1;
            }
            else if((mx>=780 && mx<=1024)&& (my>=40 && my<=140))
            {
                ///END
                is_button_pressed=1;
                exit(0);
            }
        }
    }
    else if(stage==-4 || stage==-5 || stage==-6 || stage==-7)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if((mx>=31 && mx<=(31+300))&&(my>=450 && my<=(550)))
            {
                ///Easy
                is_button_pressed=1;
                difficulty=1;
                readFromFile(difficulty);
                for(int i=0; i<MAX_SIZE-1; i++)
                {
                    strcpy(temp_string,convert_to_string(leaderboard[i].playerScore));
                    strcpy(ScoreString[i],temp_string);
                    free(temp_string);
                }
                *pstage=-5;
            }
            if((mx>=362 && mx<=(362+300))&&(my>=450 && my<=(550)))
            {
                ///Medium
                is_button_pressed=1;
                difficulty=2;
                readFromFile(difficulty);
                for(int i=0; i<MAX_SIZE-1; i++)
                {
                    strcpy(temp_string,convert_to_string(leaderboard[i].playerScore));
                    strcpy(ScoreString[i],temp_string);
                    free(temp_string);
                }
                *pstage=-6;
            }
            if((mx>=693 && mx<=(693+300))&&(my>=450 && my<=(550)))
            {
                ///Hard
                is_button_pressed=1;
                difficulty=3;
                readFromFile(difficulty);
                for(int i=0; i<MAX_SIZE-1; i++)
                {
                    strcpy(temp_string,convert_to_string(leaderboard[i].playerScore));
                    strcpy(ScoreString[i],temp_string);
                    free(temp_string);
                }
                *pstage=-7;
            }
            if((mx>=back_to_menu_x && mx<=(back_to_menu_x+width_back_to_menu_x))&&(my>=back_to_menu_y && my<=(back_to_menu_y+width_back_to_menu_y)))
            {
                *pstage=1;
                is_button_pressed=1;
            }
        }
    }
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    //place your codes for other keys here
    if(stage>=2 && (key=='p' || key=='P') && stage!=8)
    {
        is_button_pressed=1;
        ispausetimer=!ispausetimer;
    }
    if(stage==0 && mode==1)
    {
        if(key=='\r')
        {
            mode = 0;
            strcpy(name, str);
            strcat(name,"\n");
            printf("%s", name);
            ///add linker to file
            readFromFile(difficulty);
            addPlayer(name, score, difficulty);
            *pstage=-3;
            for(int i = 0; i < len; i++)
                str[i] = 0;
            len = 0;
        }
        else if(key=='\b')
        {
            if(len>=0)
            {
                len--;
                str[len]='\0';
            }
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
int isjump=0;
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(stage>=2 && ispausetimer==0 && stage<=8)
    {

        if(key==GLUT_KEY_UP)
        {
            *pscore+=scoreplus;
            itoa(score,strscore,10);
            *pry+=down;
            character_Index=1;
            SCREENUP();
            isplayermove=1;
            isjump=1;
            if(isjump)
            {
                PlaySound("jump.wav",NULL,SND_ASYNC);
                isjump=0;
            }
            /*if(last_down_click-current>2)
            {
                lastclick=time(0);
            }*/
        }
        else if(key==GLUT_KEY_DOWN)
        {
            *pscore-=scoreplus;
            itoa(score,strscore,10);
            *pry-=down;
            character_Index=0;
            //last_down_click=time(0);
        }
        else if(key==GLUT_KEY_LEFT)
        {
            *prx-=down;
            character_Index=2;
        }
        else if(key==GLUT_KEY_RIGHT)
        {
            *prx+=down;
            character_Index=3;
        }
    }
    //place your codes for other keys here
}


void moveText()
{
    if(stage==1)
    {
        if(welcomex>=screenwidth)
        {
            welcomex=0;
        }
        welcomex+=10;
    }
}

int main()
{
    iSetTimer(100,moveText);
    iSetTimer(movetime1,moveRectangle1);
    iSetTimer(movetime2,moveRectangle2);
    iSetTimer(movetime3,moveRectangle3);
    iSetTimer(movetime4,moveRectangle4);
    iSetTimer(movetime5,moveRectangle5);
    iSetTimer(movetime6,moveRectangle6);
    iSetTimer(movetime7,moveRectangle7);
    iSetTimer(4000,forcemove);
    //if(stage>=2)

    //place your own initialization codes here.
    iInitialize(screenwidth, screenheigth, "Hop Mania");
    return 0;
}
