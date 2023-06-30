#ifndef __SYSTEM_H__
#define __SYSTEM_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <tchar.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include "time.h"
#include "windows.h"
#include "math.h"

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


char debug;




///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////



struct D_SYSTEM 
{
	sfVector2i ScreenSize;
	int BitsBp;
	sfVideoMode mode ;
	sfRenderWindow* window;
	sfClock* SystemClock;
	float DT;
	sfVector2i Mouse;
};
//////////////////////////////
//"necessary Data System SFML"
//////////////////////////////
//--> sfVideoMode  mode
//--> sfRenderWindow* window
//--> sfClock* SystemClock
//--> float DT
//--> sfVector2f Mouse
//--> sfVector2i ScreenSize
/////////////////////////////
typedef struct D_SYSTEM DataSystem;




///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////

void SystemInit(DataSystem* DataS);

#endif // !__SYSTEM_H__

