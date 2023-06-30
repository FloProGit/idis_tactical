#include "menuState.h"
#include "stdio.h"
#include "fmutils.h"





void menuStateInit(struct COMMON* Common, struct MENU* MenuData, SD_GameSound* GameSound)
{
	////INIT FUNCTION POINTER
	MenuData->ButtonData[0].Ptr_fct = PlayButton;
	MenuData->ButtonData[1].Ptr_fct = OptionButton;
	MenuData->ButtonData[2].Ptr_fct = ExitButton;
	MenuData->ButtonData[3].Ptr_fct = ReturnButton;


	////Declaration Temporary DataMenu for using in function "InitDataButton" destroy a the end;////
	int temp_PosX_Menu = 780;
	int temp_PosY_Menu = 300;
	int temp_DecalY_Menu = 100;

	/////////////Declaration position et flotement ile
	MenuData->DataIle.pos.x = 0;
	MenuData->DataIle.pos.y = 220;
	MenuData->DataIle.Amplitude = 100.f;
	MenuData->DataIle.Frequence = 1.f;
	MenuData->DataIle.horloge = sfClock_create();
	MenuData->DataIle.timer = 0;
	////////////////////////////////////////////////////////////////////////////////////////////////
	////INIT BUTTON SPRITES/// 
	MenuData->TabSpriteOff[0] = LoadSprite("IMG/MENU/playOff.png", 0, 0, 0);
	MenuData->TabSpriteOn[0] = LoadSprite("IMG/MENU/playOn.png", 0, 0, 0);

	MenuData->TabSpriteOff[1] = LoadSprite("IMG/MENU/histoireOff.png", 0, 0, 0);
	MenuData->TabSpriteOn[1] = LoadSprite("IMG/MENU/histoireON.png", 0, 0, 0);

	MenuData->TabSpriteOff[2] = LoadSprite("IMG/MENU/quitterOff.png", 0, 0, 0);
	MenuData->TabSpriteOn[2] = LoadSprite("IMG/MENU/quitterOn.png", 0, 0, 0);

	MenuData->TabSpriteOff[3] = LoadSprite("IMG/MENU/menuOff.png", 0, 0, 0);
	MenuData->TabSpriteOn[3] = LoadSprite("IMG/MENU/menuON.png", 0, 0, 0);


	MenuData->Background = LoadSprite("IMG/MENU/FOND.png", 0, 0, 0);
	MenuData->title = LoadSprite("IMG/MENU/YDISTACTICAL.png", 0, 0, 0);

	MenuData->Ile = LoadSprite("IMG/MENU/ILE.png", 0, 0, 0);
	MenuData->logo = LoadSprite("IMG/MENU/logo.png", 0, 0, 0);
	MenuData->crea = LoadSprite("IMG/MENU/creajeux.png", 0, 0, 0);
	/////////////////////////////

////////HISTOIRE
	MenuData->histoire = LoadSprite("IMG/MENU/Histoire.png", 0, 0, 0);
	InitDataButton(MenuData, TOTBUTTON, temp_PosX_Menu, temp_PosY_Menu, temp_DecalY_Menu);

	printf("MUSIC IN %d\n", GameSound->SoundTrack.SoutrackList[2]);
	PlayMusic(GameSound->SoundTrack.SoutrackList[2]);
}

void menuStateUpdate(GameData* Common, struct MENU* MenuData, SD_GameSound* GameSound)
{
	while (Common->MainState == Menu)
	{
		MenuData->DataIle.dt = sfTime_asSeconds(sfClock_restart(MenuData->DataIle.horloge));

		MenuData->DataIle.timer += MenuData->DataIle.dt;

		MenuData->DataIle.pos.y = (MenuData->DataIle.Amplitude * cos(MenuData->DataIle.Frequence * MenuData->DataIle.timer));

		////Mouse Update on Window
		Common->DataSystem.Mouse.x = sfMouse_getPositionRenderWindow(Common->DataSystem.window).x;
		Common->DataSystem.Mouse.y = sfMouse_getPositionRenderWindow(Common->DataSystem.window).y;

		for (int i = 0; i < TOTBUTTON - 1; i++)
		{
			MenuData->ButtonData[i].On = (MouseCollideOnButton(MenuData->ButtonData[i], Common->DataSystem.Mouse) ? 1 : 0);
		}

		sfEvent event;

		while (sfRenderWindow_pollEvent(Common->DataSystem.window, &event)) // boucle d'interaction avec Menu
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(Common->DataSystem.window);
			else if (event.type == sfEvtMouseMoved)// Si état de jeu = Menu, alors parcourir les options du menu à la souris ou avec les flèches
			{

			}
			if (event.type == sfEvtMouseButtonPressed)
			{
				for (int i = 0; i < TOTBUTTON - 1; i++)
				{
					if (MouseCollideOnButton(MenuData->ButtonData[i], Common->DataSystem.Mouse))
					{
						sfSound_play(GameSound->Interface.IntefaceSoundList[0]);
						MenuData->ButtonData[i].Ptr_fct(&(Common->MainState));
					}
				}
			}
		}
		DisplayMenu(Common, MenuData);
	};
	printf("OUT");
}

void menuHistory(GameData* Common, struct MENU* MenuData, SD_GameSound* GameSound)
{
	while (Common->MainState == Option)
	{
		MenuData->DataIle.dt = sfTime_asSeconds(sfClock_restart(MenuData->DataIle.horloge));

		MenuData->DataIle.timer += MenuData->DataIle.dt;

		MenuData->DataIle.pos.y = (MenuData->DataIle.Amplitude * cos(MenuData->DataIle.Frequence * MenuData->DataIle.timer));

		////Mouse Update on Window
		Common->DataSystem.Mouse.x = sfMouse_getPositionRenderWindow(Common->DataSystem.window).x;
		Common->DataSystem.Mouse.y = sfMouse_getPositionRenderWindow(Common->DataSystem.window).y;

		MenuData->ButtonData[3].Pos.x = 50;
		MenuData->ButtonData[3].Pos.y = 50;
		MenuData->ButtonData[3].On = (MouseCollideOnButton(MenuData->ButtonData[3], Common->DataSystem.Mouse) ? 1 : 0);



		sfEvent event;

		while (sfRenderWindow_pollEvent(Common->DataSystem.window, &event)) // boucle d'interaction avec Menu
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(Common->DataSystem.window);
			else if (event.type == sfEvtMouseMoved)// Si état de jeu = Menu, alors parcourir les options du menu à la souris ou avec les flèches
			{


			}
			if (event.type == sfEvtMouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta < 0)
				{
					if (MenuData->histoirePosition.y <= 0)
					{
						MenuData->histoirePosition.y += 50 + MenuData->DataIle.dt;
					}
				}
				else if (event.mouseWheelScroll.delta > 0)
				{
					if (MenuData->histoirePosition.y > -(10000 - 1080))
					{
						MenuData->histoirePosition.y -= 50 + MenuData->DataIle.dt;
					}
				}
			}
			if (event.type == sfEvtMouseButtonPressed)
			{

				if (MouseCollideOnButton(MenuData->ButtonData[3], Common->DataSystem.Mouse))
				{
					sfSound_play(GameSound->Interface.IntefaceSoundList[0]);
					MenuData->ButtonData[3].Ptr_fct(&(Common->MainState));
				}
			}
		}
		DisplayHistoire(Common, MenuData);
	};
	printf("OUT");
}
void menuStateExit(GameData* Common, struct MENU* MenuData)
{
	//DestroySprite(MenuData->TabSprite[0]);
}
void menuState(GameData* Common, SD_GameSound* GameSound)
{
	struct MENU MenuData;

	menuStateInit(Common, &MenuData, GameSound);
	menuStateUpdate(Common, &MenuData, GameSound);
	menuHistory(Common, &MenuData, GameSound);
	menuStateExit(Common, &MenuData);
}


void DisplayMenu(GameData* Common, struct MENU* MenuData)
{
	sfRenderWindow_clear(Common->DataSystem.window, sfBlack);///CLEAR WINDOW IN GREEN
	blitSprite(MenuData->Background, 0, 0, 0, Common->DataSystem.window);
	blitSprite(MenuData->Ile, MenuData->DataIle.pos.x, MenuData->DataIle.pos.y, 0, Common->DataSystem.window);
	blitSprite(MenuData->logo, 1750, 900, 0, Common->DataSystem.window);
	blitSprite(MenuData->crea, 0, 850, 0, Common->DataSystem.window);
	blitSprite(MenuData->title, 0, 0, 0, Common->DataSystem.window);
	for (int i = 0; i < TOTBUTTON - 1; i++)
	{

		switch (MenuData->ButtonData[i].On)/////BUTTON DISPLAY
		{
		case 0: blitSprite(MenuData->TabSpriteOff[i], MenuData->ButtonData[i].Pos.x, MenuData->ButtonData[i].Pos.y, 0, Common->DataSystem.window); break;

		case 1: blitSprite(MenuData->TabSpriteOn[i], MenuData->ButtonData[i].Pos.x, MenuData->ButtonData[i].Pos.y, 0, Common->DataSystem.window); break;

		default:printf("ERREUR AFFICHAGE DISPLAY MENU SWITCH1 "); break;
		}
	}
	sfRenderWindow_display(Common->DataSystem.window);///DISPLAY ALL SPRITE ON SCREEN
}

void DisplayHistoire(GameData* Common, struct MENU* MenuData)
{
	sfRenderWindow_clear(Common->DataSystem.window, sfBlack);///CLEAR WINDOW IN GREEN
	blitSprite(MenuData->Background, 0, 0, 0, Common->DataSystem.window);
	blitSprite(MenuData->Ile, MenuData->DataIle.pos.x, MenuData->DataIle.pos.y, 0, Common->DataSystem.window);
	blitSprite(MenuData->logo, 1750, 900, 0, Common->DataSystem.window);
	blitSprite(MenuData->crea, 0, 850, 0, Common->DataSystem.window);
	blitSprite(MenuData->histoire, 0, MenuData->histoirePosition.y, 0, Common->DataSystem.window);

	blitSprite(MenuData->TabSpriteOff[3], MenuData->ButtonData[3].Pos.x, MenuData->ButtonData[3].Pos.y, 0, Common->DataSystem.window);
	for (int i = 3; i < 4; i++)
	{

		switch (MenuData->ButtonData[i].On)/////BUTTON DISPLAY
		{
		case 0: blitSprite(MenuData->TabSpriteOff[i], MenuData->ButtonData[i].Pos.x, MenuData->ButtonData[i].Pos.y, 0, Common->DataSystem.window); break;

		case 1: blitSprite(MenuData->TabSpriteOn[i], MenuData->ButtonData[i].Pos.x, MenuData->ButtonData[i].Pos.y, 0, Common->DataSystem.window); break;

		default:printf("ERREUR AFFICHAGE DISPLAY MENU SWITCH1 "); break;
		}
	}
	sfRenderWindow_display(Common->DataSystem.window);///DISPLAY ALL SPRITE ON SCREEN
}

void PlayButton(StateM** State)
{
	*State = World;
	printf("World1");
}
void OptionButton(StateM** State)
{
	printf("OPTION");
	*State = Option;
	//*State = Option;
}
void ExitButton(StateM** State)
{
	printf("EXIT");
	exit(0);
}

void ReturnButton(StateM** State)
{
	*State = Menu;
}

