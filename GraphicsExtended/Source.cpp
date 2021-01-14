/*
	Author: Adil Ahnaf  ID - 011 151 054
	last modified: Decemer 26, 2015
*/
# include "iGraphics.h"
# include <stdio.h>
# include <string.h>


int wLen = 800;			// Window's length
int wHig = 600;			// Window's hight
double time1 = 15;		// bullet animation time
double time2 = 30;		// ball animation time

int bRad = 5 ;		// shooted ball's radius
int x = 355;		// shooted ball's coordinate x
int y = 120;		// shooted ball'scoordinate x

int bx = 350, by = 0, bWid = 32, bLen=128;		// gun's coordinate & gun's width & length

int fbR = 10;			// Fixed ball's Radius

int fbX[100] = {1*fbR, 5*fbR, 10*fbR, 15*fbR, 20*fbR, 25*fbR, 30*fbR, 35*fbR, 40*fbR, 45*fbR, 50*fbR,
				55*fbR, 60*fbR, 65*fbR, 70*fbR, 75*fbR, 80*fbR, 85*fbR, 90*fbR, 95*fbR, 100*fbR};

int fbY[100] = {590,590,590,590,590,590,590,590,590,590};		// Fixed ball's Co-ordinate
														// we didn't used the full array fbY[]; but we only used fbY[0]
												
int life = 3; 

int i, j; 
int shoot = 0;			// bullet shooting
int pause = 0;			// when pause = 0 ---- game play
						//		pause = 1 ---- game pause
						//		pause = 2 ---- game over

int score = 0;			// score counting
char scoreText[100];	// array for score screen



void animateBullet()			// shooting bullet
{
	if(shoot == 1)  {			
		
		y = y+ 10;		

		if(y == 600){
			shoot = 0;
			y = 0;	}
					}
}	

	

void animateBall()			// animating ball horizontally
{
	for(i = 0; i<100 ; i++){
	fbX[i] += 5;
	if(fbX[i] == 810){
		fbX[i] = 0; }	}
}



void iDraw()
{

if(pause == 0)				// game play
{
	iClear();	
	iShowBMP(0, 0, "pic\\back.bmp");


iSetColor(220, 10, 220);
	for(i = 0; i<5 ; i = i+2)	{
	iFilledCircle(fbX[i],fbY[0],fbR);
	if(x >= (fbX[i] - fbR) && x <= (fbX[i] + fbR)  && y >= (fbY[0]-fbR) && y <= (fbY[0]+fbR)){
		fbX[i]=1000;
		score += 5;	}
								}

iSetColor(20, 10, 220);
	for(i = 1; i<5 ; i = i+2)	{
	iFilledCircle(fbX[i],fbY[0],fbR);
	if(x >= (fbX[i] - fbR) && x <= (fbX[i] + fbR)  && y >= (fbY[0]-fbR) && y <= (fbY[0]+fbR)){
		fbX[i]=1000;
		score += 15;	}
								}

iSetColor(255, 255, 204);
	for(i = 5; i<10 ; i = i+2)	{
	iFilledCircle(fbX[i],fbY[0],fbR);
	if(x >= (fbX[i] - fbR) && x <= (fbX[i] + fbR)  && y >= (fbY[0]-fbR) && y <= (fbY[0]+fbR)){
		fbX[i]=1000;
		score += 25;	}
								}

iSetColor(255, 0, 0);
	for(i = 6; i<10 ; i = i+2)	{
	iFilledCircle(fbX[i],fbY[0],fbR);
	if(x >= (fbX[i] - fbR) && x <= (fbX[i] + fbR)  && y >= (fbY[0]-fbR) && y <= (fbY[0]+fbR)){
		fbX[i]=1000;
		pause = 2;	}
								}

 iSetColor(16, 120, 0);
	for(i = 10; i<16 ; i = i+2)	{
	iFilledCircle(fbX[i],fbY[0],fbR);
	if(x >= (fbX[i] - fbR) && x <= (fbX[i] + fbR)  && y >= (fbY[0]-fbR) && y <= (fbY[0]+fbR)){
		fbX[i]=1000;
		score += 35;	}
								}

 iSetColor(20, 20, 20);
	for(i = 11; i< 16; i = i+2)	{
	iFilledCircle(fbX[i],fbY[0],fbR);
	if(x >= (fbX[i] - fbR) && x <= (fbX[i] + fbR)  && y >= (fbY[0]-fbR) && y <= (fbY[0]+fbR)){
		fbX[i]=1000;
		score += 45;	}
								}




	
	iSetColor(0, 0, 0);
	iFilledCircle(x,y,bRad);

	iShowBMP(bx, by, "pic\\gun.bmp");		// Bullet's co ordinate

	
	iSetColor(0, 255, 0);					// score display
	iRectangle(0,337,70,30);
	iSetColor(0, 0, 0);
	iText(5,350,"Score:");
	_itoa(score,scoreText,10);				//Convert integer to string.It is a C++ function
	iText(50,350,scoreText);
}




if(pause==1)						// pause & resume 
{
	
	iShowBMP(0, 0, "pic\\back2.bmp");
	iSetColor(255, 255, 255);
	iText(300,70,"PRESS 'r' TO RESUME GAME", GLUT_BITMAP_TIMES_ROMAN_24);
}



				
if(pause == 2)						// game over
{
	iShowBMP(0, 0, "pic\\over.bmp");
	iSetColor(255, 255, 255);
	iText(30,50,"PRESS 'Insert' button TO RESTART GAME and 'End' buntton to exit", GLUT_BITMAP_TIMES_ROMAN_24);}
									

}



void iMouseMove(int mx, int my)
{
	
}




void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
			
	}
}




void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		pause = 1;
	}
	if(key == 'r')
	{
		pause = 0;
	}
	if(key == 'g')
	{
		shoot = 1;
		PlaySound("pic\\gun",NULL,SND_ASYNC);
			
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
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_INSERT)
	{
		pause = 0;
		score = 0;
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(bx>=0){
		bx = bx - 5;	
		x = x-5;}
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(bx< (wLen-bWid) ){
		bx = bx + 5;	
		x = x+5;}
	}
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
}



int main()
{
	
	iSetTimer(time1,  animateBullet);

	iSetTimer(time2,  animateBall);
	
	iInitialize(wLen, wHig, "Ball Bursting");
	return 0;
}	