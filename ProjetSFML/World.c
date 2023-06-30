#include"World.h"

void LAUNCH_D_PROJET(GameData * GD, SD_GameSound* GameSound)
{

	D_WorldMap WorldMap = {
		//Camera
		{ 0,0 },
		"save.txt",
		Unload,
		NullSW,
	};
	INITWORLD(&WorldMap, GD, GameSound);
	UPDATEPROJECT(&WorldMap, GD, GameSound);
}
void INITWORLD(D_WorldMap* WorldMap, GameData * GD, SD_GameSound* GameSound)
{
	initWorld(&WorldMap->MapExplo);
	initInventory(&WorldMap->Inventory);
	//initParticles(&WorldMap->Particles);

	sfMusic_stop(GameSound->SoundTrack.SoutrackList[2]);
	PlayMusic(GameSound->SoundTrack.SoutrackList[0]);
}

void UPDATEPROJECT(D_WorldMap* WorldMap, GameData * GD, SD_GameSound* GameSound)
{
	while (GD->MainState == World)
	{
		////DELTA TIME
		GD->DataSystem.DT = sfTime_asSeconds(sfClock_restart(GD->DataSystem.SystemClock));
		////MOUSE POSITION ----->SFVECTOR2I<------------------
		GD->DataSystem.Mouse.x = sfMouse_getPositionRenderWindow(GD->DataSystem.window).x;
		GD->DataSystem.Mouse.y = sfMouse_getPositionRenderWindow(GD->DataSystem.window).y;


		/////UPDATE BEFORE EVENT/////
		updateWorld(&WorldMap->MapExplo);
		//updateParticles(&WorldMap->Particles, GD->DataSystem.DT);
		//////////////////////EVENT LOOP/////////////////////////////////
		sfEvent event;
		while (sfRenderWindow_pollEvent(GD->DataSystem.window, &event))
		{
			if (event.type == sfEvtClosed) exit(0);
			if (event.type == sfEvtKeyReleased)
			{
				if (event.key.code == sfKeyEscape)
				{
					WorldMap->MapExplo.isDisplayingInventory = FALSE;
				}
				inputWorld(&WorldMap->MapExplo, event);
				if (event.key.code == sfKeyA)////GIVE A SAVE NAME TO WORLD MAP
				{


				}
			};
			if (event.type == sfEvtMouseButtonPressed)
			{

				if (event.mouseButton.button == sfMouseLeft)
				{
					if (WorldMap->MapExplo.isDisplayingInventory == TRUE)
					{

						if (WorldMap->Inventory.tempRuneIsSelected == 1)
						{
							releaseRune(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);
						}
						else if (WorldMap->Inventory.tempRuneIsSelected == 0)
						{
							selectRuneInInventory(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);
							selectRuneInBag(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);
						}

					};
					eventOpenInventory(&WorldMap->MapExplo, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);

					eventSwitchInventoryPage(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);
					if (WorldMap->Inventory.RuneIsDropped == TRUE)
					{
						WorldMap->Inventory.RuneIsDropped = FALSE;
					};
				}
				if (event.mouseButton.button == sfMouseRight)
				{
					sfMusic_stop(GameSound->SoundTrack.SoutrackList[0]);
					sfSound_play(GameSound->Interface.IntefaceSoundList[0]);
					WorldMap->SaveName = WorldMap->MapExplo.balises[WorldMap->MapExplo.perso.currentBalise].MapLVL;
					WorldMap->StatusWorldMap = MapIsSelected;
				}
			}
			if (event.type == sfEvtMouseButtonReleased)
			{

	
			}
		}

		//////////////////////// SWITCH CONTAIN ALL OTHER STATE OF GAME 
		switch (WorldMap->StatusWorldMap)
		{

		case MapIsSelected: LAUNCHCOMBAT(WorldMap->SaveName, GD, &WorldMap->StatusWorldMap, &WorldMap->Inventory, GameSound); break;



		default:break;// printf("-->ERROR WORLD SWITCH STATUS\n");
		}

		if (WorldMap->StatusWorldMap == EndFightWin)
		{
			dropRune(&WorldMap->Inventory);
			sfMusic_stop(GameSound->SoundTrack.SoutrackList[1]);
			PlayMusic(GameSound->SoundTrack.SoutrackList[0]);
			sfSound_play(GameSound->ActionSound.ActionSound[17]);
			WorldMap->StatusWorldMap = NullSW;
			WorldMap->MapExplo.balises[WorldMap->MapExplo.perso.currentBalise + 1].isUnlocked = TRUE;
			FILE *ptrFichier;
			if (!(ptrFichier = fopen("SAVE/LastLevel.txt", "wt"))) {
				printf("Erreur d'acces au fichier...\n");
				exit(EXIT_FAILURE);
			}
			if (WorldMap->MapExplo.perso.currentBalise < 21 && WorldMap->MapExplo.perso.currentBalise + 1 >= WorldMap->MapExplo.perso.lastBalise)
			{
				int numéro = WorldMap->MapExplo.perso.lastBalise + 1;
				fprintf(ptrFichier, "%d", numéro);
				WorldMap->MapExplo.perso.lastBalise = numéro;
			}
			else
			{
				fprintf(ptrFichier, "%d", WorldMap->MapExplo.perso.lastBalise);
			}
			fclose(ptrFichier);

			FILE *fichierSac;
			if (!(fichierSac = fopen("SAVE/bag.bin", "wb"))) {
				printf("Erreur d'acces au fichier...\n");
				exit(EXIT_FAILURE);
			}
			fwrite(&WorldMap->Inventory.bag, sizeof(RUNE), 30, fichierSac);
			fclose(fichierSac);

			FILE *fichierInventaire;
			if (!(fichierInventaire = fopen("SAVE/inventory.bin", "wb"))) {
				printf("Erreur d'acces au fichier...\n");
				exit(EXIT_FAILURE);
			}
			fwrite(&WorldMap->Inventory.player, sizeof(D_PersoCombat), 4, fichierInventaire);
			fclose(fichierInventaire);
		}
		if (WorldMap->StatusWorldMap == EndFightLoose)
		{
			sfMusic_stop(GameSound->SoundTrack.SoutrackList[1]);
			PlayMusic(GameSound->SoundTrack.SoutrackList[0]);
			WorldMap->StatusWorldMap = NullSW;
			sfSound_play(GameSound->ActionSound.ActionSound[18]);
		}

		updateSwitchInventoryPage(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);
		updateLittleWindow(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);
		////////////////////////////DISPLAY WORLD///////////////////////////////
		sfRenderWindow_clear(GD->DataSystem.window, sfBlack);

		displayWorld(&WorldMap->MapExplo, GD->DataSystem.window);
		//displayParticlesBack(&WorldMap->Particles, GD->DataSystem.window);
		//displayParticlesFront(&WorldMap->Particles, GD->DataSystem.window);
		if (WorldMap->MapExplo.isDisplayingInventory == TRUE)
		{
			displayFullInventory(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y, GD->DataSystem.window);
		}
		else
		{
			displayButtonInventory(&WorldMap->Inventory, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y, GD->DataSystem.window);
		}
		if (WorldMap->Inventory.RuneIsDropped == TRUE)
		{
			displayDroppedRune(&WorldMap->Inventory, GD->DataSystem.window);
		};
		sfRenderWindow_display(GD->DataSystem.window);
	};
}



