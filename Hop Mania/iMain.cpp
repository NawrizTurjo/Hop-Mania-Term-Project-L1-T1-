# include "iGraphics.h"


char bc[][100]= {"bc\\original menu.bmp"};
//int x = 300, y = 300, r = 20;
//int r,g,b;
int r=0;
int g=0;
int b=0;
int stage=0;
int *pstage=&stage;
int rx=450;
int ry=50;
int rdx=100;
int rdy=50;
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
int blockx2=410;
int blockx3=820;
int blocky=220;
int dblockx=170;
int dblocky=50;
int blockx4=85;
int blockx5=495;
int blockx6=905;
int blocky2=400;
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
    //iShowBMP(0,0,bc[0]);
    iSetColor(0,0,0);
    //iRectangle(259,649,152,52);
    iFilledRectangle(0,0,1024,576);
    iSetColor(255,102,102);
    iFilledRectangle(playx,playy,widthplay,heigthplay);
    iSetColor(0, 0, 0);
    iText(190, 405, "  PLAY  ",GLUT_BITMAP_HELVETICA_18);

    //iSetColor(0,0,0);
    //iRectangle(259,549,152,52);
    iSetColor(255,102,102);
    iFilledRectangle(highx,highy,widthplay,heigthplay);
    iSetColor(0, 0, 0);
    iText(155, 305, "  HIGH SCORE  ",GLUT_BITMAP_HELVETICA_18);

    //iSetColor(0,0,0);
    //iRectangle(1299,49,102,52);
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
}
void check()
{
    if(rx<=0 || (rx+rdx)>=screenwidth || ry<=0)
    {
        exit(0);
    }
}
void UP()
{
    if((ry+rdy)>=halfy)
    {
        ry-=50;
        blocky-=50;
        blocky2-=50;
    }
    if(blocky<=10)
    {
        blocky=530;
    }
    if(blocky2<=10)
    {
        blocky2=530;    }
}
void createRectangle1()
{
    iSetColor(255,0,255);
    iRectangle(blockx1,blocky,dblockx,dblocky);
}
void createRectangle2()
{
    iSetColor(255,0,255);
    iRectangle(blockx2,blocky,dblockx,dblocky);
}
void createRectangle3()
{
    iSetColor(255,0,255);
    iRectangle(blockx3,blocky,dblockx,dblocky);
}
void createRectangle4()
{
    iSetColor(255,0,255);
    iRectangle(blockx4,blocky2,dblockx,dblocky);
}
void createRectangle5()
{
    iSetColor(255,0,255);
    iRectangle(blockx5,blocky2,dblockx,dblocky);
}
void createRectangle6()
{
    iSetColor(255,0,255);
    iRectangle(blockx6,blocky2,dblockx,dblocky);
}
void moveRectangle()
{
    if(stage==2)
    {
        blockx1-=10;
        blockx2-=10;
        blockx3-=10;
        if((blockx1+dblockx)<=0)
        {
            blockx1=1024;
        }
        if((blockx2+dblockx)<=0)
        {
            blockx2=1024;
        }
        if((blockx3+dblockx)<=0)
        {
            blockx3=1024;
        }

    }
}
void moveRectangle1()
{
    if(stage==2)
    {
        blockx4-=10;
        blockx5-=10;
        blockx6-=10;
        if((blockx4+dblockx)<=0)
        {
            blockx4=1024;
        }
        if((blockx5+dblockx)<=0)
        {
            blockx5=1024;
        }
        if((blockx6+dblockx)<=0)
        {
            blockx6=1024;
        }
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
}
void downscreen()
{

}
void iDraw()
{
    //place your drawing codes here
    //iFilledCircle(x, y, r);
    iClear();

    //iSetColor(0, 255, 255);
    //iFilledRectangle(0, 0, 1440, 810);
    //if(state==0)
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
        createRectangle1();
        createRectangle2();
        createRectangle3();
        createRectangle4();
        createRectangle5();
        createRectangle6();
        check1();
        //checkRectangle();

    }
    //printf("%d",state);
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
            *pstage=1;
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
/*if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	//place your codes here
	x -= 10;
	y -= 10;
}*/


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    /*if (key == 'm') {
    	exit(0);
    }*/
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
    if(stage==2)
    {

        if(key==GLUT_KEY_UP)
        {
            ry+=35;
            check();
            UP();
        }
        else if(key==GLUT_KEY_DOWN)
        {
            ry-=35;
            check();
        }
        else if(key==GLUT_KEY_LEFT)
        {
            rx-=35;
            check();
        }
        else if(key==GLUT_KEY_RIGHT)
        {
            rx+=35;
            check();
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
            welcomex=-100;
        }
        welcomex+=10;
    }
}

int main()
{
    iSetTimer(100,moveText);
    iSetTimer(100,moveRectangle);
    iSetTimer(100,moveRectangle1);
    //place your own initialization codes here.
    iInitialize(screenwidth, screenheigth, "Hop Mania");
    return 0;
}
