
#include"GamData.h"


sfRenderWindow* window = 0;
sfEvent event;

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(NULL));

	GameData GameData = {
		{1920,1080},
		Menu,
	};
	SD_GameSound GameSound;
	SystemInit(&GameData.DataSystem);
	LoadAllSound(&GameSound);
	LoadAllMusic(&GameSound);
	SetVolumeAllSound(&GameSound);
	while (1)
	{


		switch (GameData.MainState)
		{
		case 0: menuState(&GameData, &GameSound); break;

		case 1:LAUNCH_D_PROJET(&GameData, &GameSound); break;

		default:printf("ERROR IN MAIN SWITCH");	break;
		}
	}


	return 0;
}

