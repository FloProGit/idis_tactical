#include "System.h"



void SystemInit(DataSystem* DataS)
{
	DataS->BitsBp = 32;
	debug = 0;
	sfVideoMode mode = { DataS->ScreenSize.x, DataS->ScreenSize.y, DataS->BitsBp };

	//DataS->window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	DataS->window = sfRenderWindow_create(mode, "SFML window", sfFullscreen | sfClose, NULL);

	DataS->SystemClock = sfClock_create();
	DataS->DT = 0;

}