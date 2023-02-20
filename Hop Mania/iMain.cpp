# include "iGraphics.h"
#include<string.h>
#include<stdlib.h>

char strscore[20];
char bc[][100]= {"bc\\original menu.bmp"};
//int x = 300, y = 300, r = 20;
//int r,g,b;
int r=0;
int g=0;
int b=0;
int stage=0;
int *pstage=&stage;
int rx=450;
int *prx=&rx;
int ry=50;
int *pry=&ry;
int rdx=25;
int rdy=25;
int playx=150;
int playy=384;
int highx=150;
int highy=284;
int endx=850;
int endy=50;
int widthplay=150;
int heigthplay=50;
int widthend=100;
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

int blocky=100;
int *pblocky=&blocky;
int blocky1=220;
int *pblocky1=&blocky1;
int blocky2=460;
int *pblocky2=&blocky2;
int blocky3=340;
int *pblocky3=&blocky3;

int dblockx=170;
int dblocky=50;
int blockx4=85;
int *pblockx4=&blockx4;
int blockx5=495;
int *pblockx5=&blockx5;
int blockx6=905;
int *pblockx6=&blockx6;
int down=30;
int speed=15;

int movetime1=100;
int movetime2=85;
int movetime3=75;
int movetime4=60;
int movetime5=45;
int movetime6=40;

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

/*
function iDraw() is called again and again by the system.
*/
void page0()
{
    iSetColor(255,255,0);
    iFilledRectangle(namex,namey,namew,nameh);
    iSetColor(0,255,255);
    iText(395,310,"Enter Your Name Here",GLUT_BITMAP_TIMES_ROMAN_24);
}
void page1()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,1024,576);
    iSetColor(255,102,102);
    iFilledRectangle(playx,playy,widthplay,heigthplay);
    iSetColor(0, 0, 0);
    iText(190, 405, "  PLAY  ",GLUT_BITMAP_HELVETICA_18);

    iSetColor(255,102,102);
    iFilledRectangle(highx,highy,widthplay,heigthplay);
    iSetColor(0, 0, 0);
    iText(155, 305, "  HIGH SCORE  ",GLUT_BITMAP_HELVETICA_18);

    iSetColor(255,102,102);
    iFilledRectangle(endx,endy,widthend,heigthend);
    iSetColor(0, 0, 0);
    iText(870, 70, "  END  ",GLUT_BITMAP_HELVETICA_18);

    iSetColor(255,255,255);
    iText(welcomex,welcomey,"Welcome To Hop Mania",GLUT_BITMAP_HELVETICA_18);

}
void page2()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,1024,512);
    iSetColor(255,0,0);
    iRectangle(rx,ry,rdx,rdy);
    iSetColor(255,255,255);
    iText(700,500,strscore,GLUT_BITMAP_HELVETICA_10);

}
void page3()
{

}
void screencheck()
{
    if(rx<=0 || (rx+rdx)>=screenwidth || ry<=0)
    {
        exit(0);
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
    }
    if(blocky<=10)
    {
        *pblocky=550;
    }
    if(blocky1<=10)
    {
        *pblocky1=550;
    }
    if(blocky2<=10)
    {
        *pblocky2=550;
    }
    if(blocky3<=10)
    {
        *pblocky3=550;
    }
}
void createRectangle()
{
    iSetColor(255,0,255);
    iRectangle(blockx1,blocky,dblockx,dblocky);
    iSetColor(255,0,255);
    iRectangle(blockx2,blocky,dblockx,dblocky);
    iSetColor(255,0,255);
    iRectangle(blockx3,blocky,dblockx,dblocky);
    iSetColor(0,255,0);
    iRectangle(blockx4,blocky1,dblockx,dblocky);
    iSetColor(0,255,0);
    iRectangle(blockx5,blocky1,dblockx,dblocky);
    iSetColor(0,255,0);
    iRectangle(blockx6,blocky1,dblockx,dblocky);
    iSetColor(0,255,0);
    iRectangle(blockx7,blocky2,dblockx,dblocky);
    iSetColor(0,255,0);
    iRectangle(blockx8,blocky2,dblockx,dblocky);
    iSetColor(0,255,0);
    iRectangle(blockx9,blocky2,dblockx,dblocky);
    iSetColor(255,0,255);
    iRectangle(blockx10,blocky3,dblockx,dblocky);
    iSetColor(255,0,255);
    iRectangle(blockx11,blocky3,dblockx,dblocky);
    iSetColor(255,0,255);
    iRectangle(blockx12,blocky3,dblockx,dblocky);
}

void moveRectangle()
{
    *pblockx1+=10;
    *pblockx2+=10;
    *pblockx3+=10;
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

    *pblockx4-=speed;
    *pblockx5-=speed;
    *pblockx6-=speed;
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
        *prx-=speed;
    }

    *pblockx7+=speed;
    *pblockx8+=speed;
    *pblockx9+=speed;
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
        *prx+=speed;
    }

    *pblockx10-=10;
    *pblockx11-=10;
    *pblockx12-=10;
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
void moveRectangle1()
{
    if(stage==2)
    {
        moveRectangle();
    }
}
void moveRectangle2()
{
    if(stage==3)
    {
        moveRectangle();
    }
}
void moveRectangle3()
{
    if(stage==4)
    {
        moveRectangle();
    }
}
void moveRectangle4()
{
    if(stage==5)
    {
        moveRectangle();
    }
}
void moveRectangle5()
{
    if(stage==6)
    {
        moveRectangle();
    }
}
void moveRectangle6()
{
    if(stage==7)
    {
        moveRectangle();
    }
}
void check1()
{
    if(ry+rdy>=blocky && ry<=blocky+dblocky)
    {
        if(rx+rdx>=blockx1 && rx+rdx<blockx1+dblockx)
            exit(0);
        if(rx+rdx>=blockx2 && rx+rdx<blockx2+dblockx)
            exit(0);
        if(rx+rdx>=blockx3 && rx+rdx<blockx3+dblockx)
            exit(0);
        if(rx<=blockx1+dblockx && rx>blockx1)
            exit(0);
        if(rx<=blockx2+dblockx && rx>blockx2)
            exit(0);
        if(rx<=blockx3+dblockx && rx>blockx3)
            exit(0);
    }
    if(ry+rdy>=blocky3 && ry<=blocky3+dblocky)
    {
        if(rx+rdx>=blockx10 && rx+rdx<blockx10+dblockx)
            exit(0);
        if(rx+rdx>=blockx11 && rx+rdx<blockx11+dblockx)
            exit(0);
        if(rx+rdx>=blockx12 && rx+rdx<blockx12+dblockx)
            exit(0);
        if(rx<=blockx10+dblockx && rx>blockx10)
            exit(0);
        if(rx<=blockx11+dblockx && rx>blockx11)
            exit(0);
        if(rx<=blockx12+dblockx && rx>blockx12)
            exit(0);
    }

    if(ry+rdy>=blocky1 && ry<=blocky1+dblocky)
    {
        if(!((rx+rdx>=blockx4 && rx+rdx<=blockx4+dblockx)||(rx+rdx>=blockx5 && rx+rdx<=blockx5+dblockx)||(rx+rdx>=blockx6 && rx+rdx<=blockx6+dblockx)))
            exit(0);
        if(!((rx<=blockx4+dblockx && rx>blockx4)||(rx<=blockx5+dblockx && rx>blockx5)||(rx<=blockx6+dblockx && rx>blockx6)))
            exit(0);

    }
    if(ry+rdy>=blocky2 && ry<=blocky2+dblocky)
    {
        if(!((rx+rdx>=blockx7 && rx+rdx<=blockx7+dblockx)||(rx+rdx>=blockx8 && rx+rdx<=blockx8+dblockx)||(rx+rdx>=blockx9 && rx+rdx<=blockx9+dblockx)))
            exit(0);
        if(!((rx<=blockx7+dblockx && rx>blockx7)||(rx<=blockx8+dblockx && rx>blockx8)||(rx<=blockx9+dblockx && rx>blockx9)))
            exit(0);

    }
}
void scorecheck()
{
    if(score>=100 && score<200)
    {
        *pscoreplus=2;
        *pstage=3;
    }
    if(score>=200 && score<300)
    {
        *pscoreplus=3;
        *pstage=4;
    }
    if(score>=300 && score<400)
    {
        *pscoreplus=4;
        *pstage=5;
    }
    if(score>=400 && score<500)
    {
        *pscoreplus=5;
        *pstage=6;
    }
    if(score>=500)
    {
        *pscoreplus=6;
        *pstage=7;
    }
}
void iDraw()
{
    iClear();

    if(stage==0)
    {
        page0();
    }
    if(stage==1)
    {
        page1();
    }
    if(stage==2)
    {
        page2();
        createRectangle();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==3)
    {
        page2();
        createRectangle();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==4)
    {
        page2();
        createRectangle();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==5)
    {
        page2();
        createRectangle();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==6)
    {
        page2();
        createRectangle();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==7)
    {
        page2();
        createRectangle();
        check1();
        scorecheck();
        screencheck();
    }
    printf("%d %d\n",stage,score);
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    //printf("1 x = %d, y= %d\n",mx,my);
    if(stage==0)
    {
        if((mx>=namex && mx<=(namex+namew)) && (my>=namey && my<=(namey+nameh)))
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                *pstage=1;
            }
        }
    }
    if(stage==1)
    {
        if((mx>=playx && mx<=(playx+widthplay)) && (my>=playy && my<=(playy+heigthplay)))
        {
            //printf("2 x = %d, y= %d\n",mx,my);
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                *pstage=2;
            }
        }
        if((mx>=endx && mx<=(endx+widthend))&&(my>=endy && my<=(endy+heigthend)))
        {
            if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
            {
                exit(0);
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
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(stage>=2)
    {

        if(key==GLUT_KEY_UP)
        {
            *pscore+=scoreplus;
            itoa(score,strscore,10);
            *pry+=down;
            SCREENUP();
        }
        else if(key==GLUT_KEY_DOWN)
        {
            *pscore-=scoreplus;
            itoa(score,strscore,10);
            *pry-=down;
        }
        else if(key==GLUT_KEY_LEFT)
        {
            *prx-=down;
        }
        else if(key==GLUT_KEY_RIGHT)
        {
            *prx+=down;
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
    //place your own initialization codes here.
    iInitialize(screenwidth, screenheigth, "Hop Mania");
    return 0;
}
