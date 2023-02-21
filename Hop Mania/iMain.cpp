# include "iGraphics.h"
#include<string.h>
#include<stdlib.h>

char strscore[20];
char bc[][100]= {"bc\\original menu.bmp"};
char bg[][100]={"bg\\car.bmp","bg\\opening.bmp","bg\\truck.bmp","bg\\block.bmp","bg\\car2.bmp","bg\\car3.bmp","bg\\ending.bmp"};
char buttons[][100]={"buttons\\PLAY.bmp","buttons\\HIGH.bmp","buttons\\END.bmp","buttons\\over.bmp"};
char road[][100]={"road\\1.bmp","road\\2.bmp","road\\3.bmp","road\\4.bmp","road\\5.bmp","road\\6.bmp","road\\7.bmp","road\\8.bmp","road\\9.bmp","road\\10.bmp","road\\11.bmp","road\\12.bmp","road\\13.bmp","road\\14.bmp","road\\15.bmp"};
char game[][100]={"game\\1.bmp","game\\2.bmp","game\\3.bmp","game\\4.bmp","game\\5.bmp","game\\6.bmp","game\\7.bmp","game\\8.bmp","game\\9.bmp","game\\10.bmp"};
char water[][50]={"water\\1.bmp","water\\2.bmp","water\\3.bmp","water\\4.bmp","water\\5.bmp","water\\6.bmp","water\\7.bmp","water\\8.bmp","water\\9.bmp","water\\10.bmp"};
char cdown[][50]={"chracter\\d1.bmp","chracter\\d2.bmp","chracter\\d3.bmp","chracter\\d4.bmp"};
char cup[][50]={"character\\u1.bmp","character\\u2.bmp","character\\u3.bmp","character\\u4.bmp"};
char cleft[][50]={"character\\l1.bmp","character\\l2.bmp","character\\l3.bmp","character\\l4.bmp"};
char cright[][50]={"character\\r1.bmp","character\\r2.bmp","character\\r3.bmp","character\\r4.bmp"};

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

int life=3;
int *plife=&life;


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
    iShowBMP(0,0,bg[1]);
    iShowBMP2(playx,playy,buttons[0],0);
    iShowBMP2(highx,highy,buttons[1],0);
    iShowBMP2(endx,endy,buttons[2],0);
    iSetColor(255,255,255);
    iText(welcomex,welcomey,"Welcome To Hop Mania",GLUT_BITMAP_HELVETICA_18);

}
void page2()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,screenwidth,screenheigth);
    iSetColor(255,255,255);
    iText(700,500,strscore,GLUT_BITMAP_HELVETICA_10);

}
void page3()
{
    iShowBMP(0,0,bg[6]);
}
void initialstage()
{
    *prx=450;
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
    if(rx<=0 || (rx+rdx)>=screenwidth || ry<=0)
    {
        initialstage();
        *plife-=1;
        *pscore-=1;
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
    iSetColor(255,0,0);
    iRectangle(rx,ry,rdx,rdy);
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
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx+rdx>=blockx2 && rx+rdx<blockx2+dblockx)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx+rdx>=blockx3 && rx+rdx<blockx3+dblockx)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx<=blockx1+dblockx && rx>blockx1)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx<=blockx2+dblockx && rx>blockx2)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx<=blockx3+dblockx && rx>blockx3)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
    }
    else if(ry+rdy>=blocky3 && ry<=blocky3+dblocky)
    {
        if(rx+rdx>=blockx10 && rx+rdx<blockx10+dblockx)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx+rdx>=blockx11 && rx+rdx<blockx11+dblockx)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx+rdx>=blockx12 && rx+rdx<blockx12+dblockx)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx<=blockx10+dblockx && rx>blockx10)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx<=blockx11+dblockx && rx>blockx11)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(rx<=blockx12+dblockx && rx>blockx12)
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
    }

    else if(ry+rdy>=blocky1 && ry<=blocky1+dblocky)
    {
        if(!((rx+rdx>=blockx4 && rx+rdx<=blockx4+dblockx)||(rx+rdx>=blockx5 && rx+rdx<=blockx5+dblockx)||(rx+rdx>=blockx6 && rx+rdx<=blockx6+dblockx)))
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(!((rx<=blockx4+dblockx && rx>blockx4)||(rx<=blockx5+dblockx && rx>blockx5)||(rx<=blockx6+dblockx && rx>blockx6)))
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }

    }
    else if(ry+rdy>=blocky2 && ry<=blocky2+dblocky)
    {
        if(!((rx+rdx>=blockx7 && rx+rdx<=blockx7+dblockx)||(rx+rdx>=blockx8 && rx+rdx<=blockx8+dblockx)||(rx+rdx>=blockx9 && rx+rdx<=blockx9+dblockx)))
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }
        else if(!((rx<=blockx7+dblockx && rx>blockx7)||(rx<=blockx8+dblockx && rx>blockx8)||(rx<=blockx9+dblockx && rx>blockx9)))
        {
            initialstage();
            *plife-=1;
            *pscore-=1;
        }

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
        createCharacter();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==3)
    {
        page2();
        createRectangle();
        createCharacter();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==4)
    {
        page2();
        createRectangle();
        createCharacter();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==5)
    {
        page2();
        createRectangle();
        createCharacter();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==6)
    {
        page2();
        createRectangle();
        createCharacter();
        check1();
        scorecheck();
        screencheck();
    }
    if(stage==7)
    {
        page2();
        createRectangle();
        createCharacter();
        check1();
        scorecheck();
        screencheck();
    }
    if(life<=0)
    {
        page3();
    }
    printf("%d %d %d\n",stage,score,life);
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
                {
                    exit(0);
                }
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
