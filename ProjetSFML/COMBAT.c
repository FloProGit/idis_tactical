#include"COMBAT.h"

void ApplyInventoryStats(D_Personnage* _Perso, D_PersoCombat _player)
{
	_Perso->Stat.PA = _player.pa;
	_Perso->Stat.PM = _player.pm;
	_Perso->Stat.PV = _player.pv;
	_Perso->Stat.ATK = _player.atk;
	_Perso->Stat.def = _player.def;
	//_Perso->Stat.crit = _player.crit;
	_Perso->Stat.bonusCRIT = _player.boostCrit;
	_Perso->Stat.bonusATK = _player.boostAtk;
	_Perso->Stat.bonusDEF = _player.boostDef;
}


void LAUNCHCOMBAT(D_Str * Name, GameData * GD, E_StateWorld *STATE, D_Inventory* _Inventory, SD_GameSound* GameSound)
{
	//printf("MUSIC IN %d\n", &GameSound->SoundTrack.SoutrackList[1]);
	PlayMusic(GameSound->SoundTrack.SoutrackList[1]);

	D_InCombat InGameCombat = {
		//Camera
		{ 10,150 },
	};

	InGameCombat.CameraMC.x = 900;
	InGameCombat.CameraMC.y = -150;

	GD->DataSystem.Mouse.x = 0;
	GD->DataSystem.Mouse.y = 0;


	INITCOMBAT(Name, &InGameCombat, _Inventory, GameSound);
	InGameCombat.AllSprite.textDisplay = sfText_create();
	sfText_setFont(InGameCombat.AllSprite.textDisplay, InGameCombat.FightHud.fontStats.font);

	//alphaApplyInventoryStats(_team, &InGameCombat.Perso);
	UPDATECOMBAT(&InGameCombat, GD, GameSound, STATE);
}


void INITCOMBAT(D_Str * Name, D_InCombat* InGameCombat, D_Inventory* _Inventory)
{
	INITMapCombat(&InGameCombat->MapCombat, Name);
	LoadBackgroundsSprite(&InGameCombat->MapCombat);
	initTexte(&InGameCombat->FightHud.HudCombat);
	VectorCase(&InGameCombat->MapCombat, InGameCombat->CameraMC);
	srand(time(NULL));
	int random = rand() % 100;
	if (random > 50)
	{
		initParticles(&InGameCombat->MapCombat.particles);
	}
	CreatemapPath(&InGameCombat->MapPathfinding, InGameCombat->MapCombat.Size);
	ConvertMapto2DMap(&InGameCombat->MapCombat, InGameCombat->CameraMC);
	InitPlayer(&InGameCombat->Perso, &InGameCombat->MapCombat);
	InitFightSystem(&InGameCombat->Fightsystem, &InGameCombat->MapCombat);
	InitHud(&InGameCombat->FightHud.HudCombat, &InGameCombat->FightHud.AllSprite, &InGameCombat->FightHud);
	//////ENNEMY/////
	for (int i = 0; i < 4; i++)
	{
		ApplyInventoryStats(&InGameCombat->Perso.player[i], _Inventory->player[i]);
	}
	InGameCombat->ManagerEnemy.TOt_IA = 3;
	//InGameCombat->ManagerEnemy.Data_Enemy = Generate_Ennemy(&InGameCombat->ManagerEnemy.Data_Enemy, NBENEMY);
	LoadEnemy(&InGameCombat->MapCombat, &InGameCombat->ManagerEnemy, NBENEMY);
	////////////////
	LoadSpriteEnemy(&InGameCombat->ManagerEnemy.Affichage_Enemy);
	LoadALLSprite(&InGameCombat->Perso, &InGameCombat->ManagerEnemy, &InGameCombat->AllSprite);
	InGameCombat->teleport = 0;


	if (strcmp(Name->Name, "LVLMAP/Map22/map.txt") == 0)
	{
		//// mettre ici la variable qui permet de savoir que c'est la fin du jeu
		printf("FIN DU JEU");
	}
}

void UPDATECOMBAT(D_InCombat* InGameCombat, GameData * GD, SD_GameSound* GameSound, E_StateWorld *STATE)
{
	int done = 1;
	while (done)
	{
		GD->DataSystem.DT = sfTime_asSeconds(sfClock_restart(GD->DataSystem.SystemClock));

		int countE = 0;
		int countP = 0;

		for (int i = 0; i < InGameCombat->ManagerEnemy.TotEnemy; i++)
		{
			if (InGameCombat->ManagerEnemy.Data_Enemy[i].Stat.Alive == 0)
			{
				countE++;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (InGameCombat->Perso.player[i].Stat.PV <= 0)
			{
				countP++;
			}
		}

		if (countE >= InGameCombat->ManagerEnemy.TotEnemy)
		{
			InGameCombat->TimerStateLV += GD->DataSystem.DT;

			if (InGameCombat->TimerStateLV > 2.5)
			{
				*STATE = EndFightWin;
				done = 0;
			}

			countE = 0;
		}

		if (countP == 4 || InGameCombat->Perso.player[0].Stat.PV <= 0 && InGameCombat->Perso.player[1].Stat.PV <= 0 && InGameCombat->Perso.player[2].Stat.PV <= 0 && InGameCombat->Perso.player[3].Stat.PV <= 0)
		{
			InGameCombat->TimerStateLV += GD->DataSystem.DT;
			if (InGameCombat->TimerStateLV > 2.5)
			{
				*STATE = EndFightLoose;
				done = 0;
			}
			countP = 0;
			InGameCombat->Out = 1;
		}

		//CHEAT WIN
		if (sfKeyboard_isKeyPressed(sfKeyP))
		{
			done = 0;
			*STATE = EndFightWin;
		}

		////DELTA TIME
		////MOUSE POSITION ----->SFVECTOR2I<------------------
		GD->DataSystem.Mouse.x = sfMouse_getPositionRenderWindow(GD->DataSystem.window).x;
		GD->DataSystem.Mouse.y = sfMouse_getPositionRenderWindow(GD->DataSystem.window).y;
		//////////////CLEAN MAPPATHFDING
		UpdateMapPath(&InGameCombat->MapPathfinding, InGameCombat->MapCombat.Map2D);
		UpdateMapFight(&InGameCombat->Fightsystem, InGameCombat->MapCombat.Map2D);
		updateParticles(&InGameCombat->MapCombat.particles, GD->DataSystem.DT);
		updateLifeGaugeEnemy(&InGameCombat->FightHud, InGameCombat->CurrentCaseSelect, &InGameCombat->ManagerEnemy);
		PersoDead(&InGameCombat->Perso);
		///////CAMERA SPEED AND INPUT
		float speed = 1000 * GD->DataSystem.DT;
		if (sfKeyboard_isKeyPressed(sfKeyD))
		{
			InGameCombat->CameraMC.x -= speed;
		}
		if (sfKeyboard_isKeyPressed(sfKeyQ))
		{
			InGameCombat->CameraMC.x += speed;
		}
		if (sfKeyboard_isKeyPressed(sfKeyZ))
		{
			InGameCombat->CameraMC.y += (speed / 2);
		}
		if (sfKeyboard_isKeyPressed(sfKeyS))
		{
			InGameCombat->CameraMC.y -= (speed / 2);
		}
		////UMPDATE VECTOR POSITION ON MAP
		VectorCase(&InGameCombat->MapCombat, InGameCombat->CameraMC);
		/////// CURRENT CASE SELECT WITH A SCALAR CALCUL
		CurrentCaseSelect(&InGameCombat->MapCombat, GD->DataSystem.Mouse, &InGameCombat->CurrentCaseSelect);

		//Recup de la case select pour le fightSystem
		if (InGameCombat->Fightsystem.turn.turnPlayer == 5)
		{
			InGameCombat->GameDataEnemy.turn = vilain;
		}


		if (InGameCombat->GameDataEnemy.turn == vilain)
		{
			D_Personnage *ChooserPlayer = 0;

			if (InGameCombat->ManagerEnemy.Data_Enemy[InGameCombat->GameDataEnemy.enemyTurn].TabPathSave != 1)
			{

				InGameCombat->ManagerEnemy.Data_Enemy[InGameCombat->GameDataEnemy.enemyTurn].Target = SaveDataTabPathfindind(&InGameCombat->ManagerEnemy, &InGameCombat->MapPathfinding, InGameCombat->MapCombat.Map2D, &InGameCombat->Perso, InGameCombat->GameDataEnemy.enemyTurn);
				InGameCombat->ManagerEnemy.Data_Enemy[InGameCombat->GameDataEnemy.enemyTurn].TabPathSave = 1;
			}

			if (InGameCombat->ManagerEnemy.Data_Enemy[InGameCombat->GameDataEnemy.enemyTurn].Target == -1)
			{
				ChooserPlayer = &InGameCombat->Perso.player[0];
			}
			else
			{
				ChooserPlayer = &InGameCombat->Perso.player[InGameCombat->ManagerEnemy.Data_Enemy[InGameCombat->GameDataEnemy.enemyTurn].Target]; //ChoosePlayer(&InGameCombat->Perso, &InGameCombat->MapPathfinding, InGameCombat->ManagerEnemy.Data_Enemy, InGameCombat->GameDataEnemy.enemyTurn);
			}






			UpdateEnemy(&InGameCombat->GameDataEnemy, &InGameCombat->MapCombat, &InGameCombat->MapPathfinding, ChooserPlayer, &InGameCombat->Perso, InGameCombat->MapCombat.Map2D, &InGameCombat->Fightsystem.turn, InGameCombat->ManagerEnemy.Data_Enemy, &InGameCombat->ManagerEnemy, InGameCombat->GameDataEnemy.enemyTurn, &InGameCombat->Perso, GD->DataSystem.DT, InGameCombat->ManagerEnemy.TotEnemy);


		}



		ItsATrap(InGameCombat->MapCombat.Map2D, &InGameCombat->Perso, &InGameCombat->ManagerEnemy, &InGameCombat->Fightsystem, GameSound);


		if (InGameCombat->Perso.player[InGameCombat->Fightsystem.turn.turnPlayer - 1].Stat.PV <= 0 && InGameCombat->Fightsystem.turn.turnPlayer < 5)
		{
			InGameCombat->Fightsystem.turn.turnPlayer++;
		}

		//////////////////////EVENT LOOP/////////////////////////////////
		sfEvent event;
		while (sfRenderWindow_pollEvent(GD->DataSystem.window, &event))
		{
			if (event.type == sfEvtClosed) exit(0);

			if (event.type == sfEvtKeyReleased)
			{
				if (event.key.code == sfKeyEscape)
				{
					exit(0);
				}
			}

			if (event.type == sfEvtMouseButtonPressed)
			{
				if (event.mouseButton.button == sfMouseLeft)
				{

					for (int i = 0; i < InGameCombat->ManagerEnemy.TotEnemy; i++)
					{
						InGameCombat->ManagerEnemy.Data_Enemy[i].SpellAnimTouch = 0;

					}

					for (int i = 0; i < 4; i++)
					{
						InGameCombat->Perso.player[i].SpellAnimTouch = 0;
					}
					//printf("\n----------------------------\n");
					//printf("1---  WIDTH : %d\n 2  HEIGHT : %d\n", InGameCombat->FightHud.HudCombat[2].HudWidth, InGameCombat->FightHud.HudCombat[2].HudHeight);
					CleanMap2DandPath(&InGameCombat->MapPathfinding, InGameCombat->MapCombat.Map2D);

					ClickHud(InGameCombat->FightHud.HudCombat, &GD->DataSystem, &InGameCombat->Fightsystem, &InGameCombat->Perso);
					ClickMoove(&GD->DataSystem, &InGameCombat->Fightsystem, &InGameCombat->FightHud, &InGameCombat->Perso);
					ChangeTurn(&GD->DataSystem, &InGameCombat->Fightsystem, &InGameCombat->FightHud, &InGameCombat->MapCombat.StateSTF);
					//	printf("2 ---- WIDTH : %d\n 2  HEIGHT : %d\n", InGameCombat->FightHud.HudCombat[2].HudWidth,  InGameCombat->FightHud.HudCombat[2].HudHeight);

					if (InGameCombat->Fightsystem.turn.turnPlayer <= 4)
					{
						selectPlayer(InGameCombat->CurrentCaseSelect, &InGameCombat->Perso, &InGameCombat->Fightsystem, GD->DataSystem.Mouse);
					}


				}
				if (event.mouseButton.button == sfMouseRight)
				{

					if (InGameCombat->MapCombat.StateSTF == Mouve)
					{
						MoovePlayer(&InGameCombat->Fightsystem, &InGameCombat->Perso, InGameCombat->MapCombat.Map2D, InGameCombat->CurrentCaseSelect, GD->DataSystem.Mouse);
						InGameCombat->Perso.player[InGameCombat->Fightsystem.turn.turnPlayer - 1].StateDeplacement = 0;
						CleanMap2DandPath(&InGameCombat->MapPathfinding, InGameCombat->MapCombat.Map2D);
					}
					if (InGameCombat->MapCombat.StateSTF == Att)
					{
						InGameCombat->Perso.player[InGameCombat->Fightsystem.turn.turnPlayer - 1].Animation.currentAnimation = 0;
						SwitchAnimation(&InGameCombat->Perso.player[InGameCombat->Fightsystem.turn.turnPlayer - 1].Animation, InGameCombat->Fightsystem.CurrentSelectSpell + 1);
						InGameCombat->CaseSaveSpell = InGameCombat->CurrentCaseSelect;

					}
					InGameCombat->MapCombat.StateSTF = NullSTF;
					if (InGameCombat->Perso.player[2].spell[2].inUse == 1)
					{


						printf("TELEPORT %d \n", InGameCombat->teleport);

						for (int i = 0; i < 4; i++)
						{

							if (InGameCombat->Perso.player[i].Stat.isSelected == 1 && InGameCombat->teleport == 1)
							{
								int testpos = 0;


								for (int j = 0; j < 4; j++)
								{
									if (InGameCombat->Perso.player[j].Line == InGameCombat->CurrentCaseSelect.y && InGameCombat->Perso.player[j].Column == InGameCombat->CurrentCaseSelect.x)
									{
										testpos = 1;
									}
								}
								for (int j = 0; j < InGameCombat->ManagerEnemy.TotEnemy; j++)
								{
									if (InGameCombat->ManagerEnemy.Data_Enemy[j].map.y == InGameCombat->CurrentCaseSelect.y && InGameCombat->ManagerEnemy.Data_Enemy[j].map.x == InGameCombat->CurrentCaseSelect.x)
									{
										testpos = 1;
									}
								}

								if ( InGameCombat->MapCombat.Map2D[InGameCombat->CaseSaveSpell.y][InGameCombat->CaseSaveSpell.x].isColored == 2 && testpos == 0)
								{
									InGameCombat->Fightsystem.caseX = InGameCombat->CurrentCaseSelect.x;
									InGameCombat->Fightsystem.caseY = InGameCombat->CurrentCaseSelect.y;

									SpellRegroup(InGameCombat->MapCombat.Map2D, &InGameCombat->Fightsystem, &InGameCombat->Perso, &InGameCombat->ManagerEnemy, InGameCombat->CurrentCaseSelect, 2, i);
									InGameCombat->Perso.player[i].Stat.isSelected = 0;
									InGameCombat->teleport = 0;
								}

							}
							else if(InGameCombat->Perso.player[i].Stat.isSelected == 0 && InGameCombat->teleport == 0)
							{
								if (InGameCombat->Perso.player[2].spell[2].inUse == 1 && InGameCombat->CurrentCaseSelect.x == InGameCombat->Perso.player[i].Column && InGameCombat->CurrentCaseSelect.y == InGameCombat->Perso.player[i].Line)
								{
									printf("c'est de la merde");
									InGameCombat->Perso.player[i].Stat.isSelected = 1;
									InGameCombat->teleport = 1;
									printf("\n i : %d \n\n Select : %d \n", i, InGameCombat->Perso.player[i].Stat.isSelected);

								}
							}

						}

						for (int j = 0; j < InGameCombat->ManagerEnemy.TotEnemy; j++)
						{
							if (InGameCombat->ManagerEnemy.Data_Enemy[j].Stat.isSelected == 1 && InGameCombat->teleport == 1)
							{

								int testpos = 0;


								for (int j = 0; j < 4; j++)
								{
									if (InGameCombat->Perso.player[j].Line == InGameCombat->CurrentCaseSelect.y && InGameCombat->Perso.player[j].Column == InGameCombat->CurrentCaseSelect.x)
									{
										testpos = 1;
									}
								}
								for (int j = 0; j < InGameCombat->ManagerEnemy.TotEnemy; j++)
								{
									if (InGameCombat->ManagerEnemy.Data_Enemy[j].map.y == InGameCombat->CurrentCaseSelect.y && InGameCombat->ManagerEnemy.Data_Enemy[j].map.x == InGameCombat->CurrentCaseSelect.x)
									{
										testpos = 1;
									}
								}

								if ( InGameCombat->MapCombat.Map2D[InGameCombat->CaseSaveSpell.y][InGameCombat->CaseSaveSpell.x].isColored == 2 && testpos == 0)
								{
									InGameCombat->Fightsystem.caseX = InGameCombat->CurrentCaseSelect.x;
									InGameCombat->Fightsystem.caseY = InGameCombat->CurrentCaseSelect.y;

									if (InGameCombat->ManagerEnemy.Data_Enemy[j].Stat.isSelected == 1)
									{
										SpellRegroup(InGameCombat->MapCombat.Map2D, &InGameCombat->Fightsystem, &InGameCombat->Perso, &InGameCombat->ManagerEnemy, InGameCombat->CurrentCaseSelect, 1, j);
										InGameCombat->ManagerEnemy.Data_Enemy[j].Stat.isSelected = 0;
										InGameCombat->teleport = 0;
									}
								}
							}
							else if (InGameCombat->ManagerEnemy.Data_Enemy[j].Stat.isSelected == 0 && InGameCombat->teleport == 0)
							{
								if (InGameCombat->Perso.player[2].spell[2].inUse == 1 && InGameCombat->CurrentCaseSelect.x == InGameCombat->ManagerEnemy.Data_Enemy[j].map.x && InGameCombat->CurrentCaseSelect.y == InGameCombat->ManagerEnemy.Data_Enemy[j].map.y)
								{
									printf("c'est trop cool");
									InGameCombat->ManagerEnemy.Data_Enemy[j].Stat.isSelected = 1;
									InGameCombat->teleport = 1;
								}
							}

						}

					}


					//system("pause");
				}
			}
		}

		InGameCombat->Fightsystem.pathFiding.pathFidingPersoX = InGameCombat->CurrentCaseSelect.x;
		InGameCombat->Fightsystem.pathFiding.pathFidingPersoY = InGameCombat->CurrentCaseSelect.y;

		if (InGameCombat->Fightsystem.turn.turnPlayer < 5)
		{

			FightSystem(&InGameCombat->Fightsystem, &InGameCombat->Perso, InGameCombat->MapCombat.Map2D, &InGameCombat->MapPathfinding, &InGameCombat->ManagerEnemy, InGameCombat->CurrentCaseSelect);
			UpdtateStateAttMouve(&InGameCombat->Perso, &InGameCombat->MapCombat.StateSTF, &InGameCombat->Fightsystem);


		}

		if (InGameCombat->MapCombat.StateSTF == Mouve)
		{
			MouveSystem(&InGameCombat->Fightsystem, &InGameCombat->Perso, InGameCombat->MapCombat.Map2D, &InGameCombat->MapPathfinding, &InGameCombat->ManagerEnemy, InGameCombat->CurrentCaseSelect);
		}

		//InGameCombat->FightHud.HudCombat[2].HudWidth = 66;
		BackgroundUpdate(&InGameCombat->MapCombat, GD->DataSystem.DT);
		updateDisplayWindow(&InGameCombat->FightHud, &InGameCombat->Fightsystem, &InGameCombat->Perso, GD->DataSystem.Mouse.x, GD->DataSystem.Mouse.y);

		for (int i = 0; i < 4; i++)
		{
			if (UpdateAnimation(&InGameCombat->Perso.player[i].Animation, GD->DataSystem.DT))
			{

				Attack(&InGameCombat->Fightsystem, &InGameCombat->Perso, InGameCombat->MapCombat.Map2D, &InGameCombat->MapCombat, InGameCombat->CaseSaveSpell, &InGameCombat->ManagerEnemy, InGameCombat->CaseSaveSpell, GameSound);//<-- ADD in function   	 

				sprintf(InGameCombat->AllSprite.PrintDamage.Name, "%d", InGameCombat->Perso.player[InGameCombat->Fightsystem.turn.turnPlayer - 1].lastDomage);
				InGameCombat->Perso.player[InGameCombat->Fightsystem.turn.turnPlayer - 1].lastDomage = 0;
				CleanMap2DandPath(&InGameCombat->MapPathfinding, InGameCombat->MapCombat.Map2D);


			}
		}

		for (int i = 0; i < 22; i++)
		{
			UpdateAnimationG(&InGameCombat->AllSprite.DecortsAnim[i], GD->DataSystem.DT);
		}

		if (InGameCombat->Fightsystem.spellAnimUse == 1)
		{
			if (UpdateAnimationG(&InGameCombat->AllSprite.AnimSpell[InGameCombat->Fightsystem.CurrentSpellUse], GD->DataSystem.DT))
			{
				InGameCombat->Fightsystem.spellAnimUse = 0;
				InGameCombat->Fightsystem.spellAnimUse = 0;
				for (int i = 0; i < InGameCombat->ManagerEnemy.TotEnemy; i++)
				{
					InGameCombat->ManagerEnemy.Data_Enemy[i].SpellAnimTouch = 0;

				}
				InGameCombat->ManagerEnemy.spellAnimUse = 0;
				InGameCombat->ManagerEnemy.spellAnimUse = 0;
				for (int j = 0; j < 4; j++)
				{
					InGameCombat->Perso.player[j].SpellAnimTouch = 0;
				}
			}
		}
		if (InGameCombat->ManagerEnemy.spellAnimUse == 1)
		{

			if (UpdateAnimationG(&InGameCombat->AllSprite.AnimSpell[InGameCombat->ManagerEnemy.CurrentSpellUse], GD->DataSystem.DT))
			{
				InGameCombat->Fightsystem.spellAnimUse = 0;
				InGameCombat->Fightsystem.spellAnimUse = 0;
				for (int i = 0; i < InGameCombat->ManagerEnemy.TotEnemy; i++)
				{
					InGameCombat->ManagerEnemy.Data_Enemy[i].SpellAnimTouch = 0;

				}
				InGameCombat->ManagerEnemy.spellAnimUse = 0;
				InGameCombat->ManagerEnemy.spellAnimUse = 0;

				for (int j = 0; j < 4; j++)
				{
					InGameCombat->Perso.player[j].SpellAnimTouch = 0;
				}

			}
		}
		for (int i = 0; i < InGameCombat->ManagerEnemy.TotEnemy; i++)
		{
			if (InGameCombat->ManagerEnemy.Data_Enemy[i].SidePlayer == 1 && InGameCombat->ManagerEnemy.Data_Enemy[i].AsAtk == 0 && InGameCombat->ManagerEnemy.Data_Enemy[i].isStun == 0)
			{
				SwitchAnimation(&InGameCombat->ManagerEnemy.Data_Enemy[i].Animation, 1);
				InGameCombat->ManagerEnemy.Data_Enemy[i].AsAtk = 1;
				/*printf("\n----------------------------\n");
				printf("3---  WIDTH : %d\n 2  HEIGHT : %d\n", InGameCombat->FightHud.HudCombat[2].HudWidth, InGameCombat->FightHud.HudCombat[2].HudHeight);*/
			}
			else if (InGameCombat->ManagerEnemy.Data_Enemy[i].SidePlayer == InGameCombat->ManagerEnemy.Data_Enemy[i].Stat.SpecialMax && InGameCombat->ManagerEnemy.Data_Enemy[i].AsAtk == 0 && InGameCombat->ManagerEnemy.Data_Enemy[i].isStun == 0)
			{
				switch (InGameCombat->ManagerEnemy.Data_Enemy[i].I_A)
				{
				case running:
					SwitchAnimation(&InGameCombat->ManagerEnemy.Data_Enemy[i].Animation, 1);
					InGameCombat->ManagerEnemy.Data_Enemy[i].AsAtk = 1;
					break;
				case boss:
					SwitchAnimation(&InGameCombat->ManagerEnemy.Data_Enemy[i].Animation, 1);
					InGameCombat->ManagerEnemy.Data_Enemy[i].AsAtk = 1;
					break;
				case hard:
					SwitchAnimation(&InGameCombat->ManagerEnemy.Data_Enemy[i].Animation, 2);
					InGameCombat->ManagerEnemy.Data_Enemy[i].AsAtk = 1;
					break;
				}
			}

			if (InGameCombat->ManagerEnemy.Data_Enemy[i].Stat.Alive == 1)
			{

				if (InGameCombat->ManagerEnemy.Data_Enemy[i].deadState >= 1)
				{
					InGameCombat->ManagerEnemy.Data_Enemy[i].timerdead += GD->DataSystem.DT;
				}
				if (InGameCombat->ManagerEnemy.Data_Enemy[i].deadState == 1 && InGameCombat->ManagerEnemy.Data_Enemy[i].timerdead > 2.5)
				{
					if (InGameCombat->ManagerEnemy.Data_Enemy[i].Stat.PV <= 0)
					{
						InGameCombat->ManagerEnemy.Data_Enemy[i].deadState = 2;
						InGameCombat->ManagerEnemy.Data_Enemy[i].timerdead = 0;
					}
					else
					{
						InGameCombat->ManagerEnemy.Data_Enemy[i].deadState = 0;
						InGameCombat->ManagerEnemy.Data_Enemy[i].timerdead = 0;
					}
				}
				if (InGameCombat->ManagerEnemy.Data_Enemy[i].deadState == 2)
				{
					InGameCombat->ManagerEnemy.Data_Enemy[i].Stat.Alive = 0;
				}
			}

			if (UpdateAnimation(&InGameCombat->ManagerEnemy.Data_Enemy[i].Animation, GD->DataSystem.DT) && InGameCombat->ManagerEnemy.Data_Enemy[i].SidePlayer != 0)
			{
				InGameCombat->ManagerEnemy.Data_Enemy[i].action = EndAnimAtk;
				InGameCombat->ManagerEnemy.Data_Enemy[i].Animation.currentAnimation = 0;
			}


		}



		MooveEnemiesDead(&InGameCombat->ManagerEnemy);


		//////////////////DISPLAY///////////////////////////
		sfRenderWindow_clear(GD->DataSystem.window, sfBlack);
		//
		BackgroundDisplay(&InGameCombat->MapCombat, GD->DataSystem.window);
		displayParticlesBack(&InGameCombat->MapCombat.particles, GD->DataSystem.window);


		__DISPLAY_GENERAL__(&InGameCombat->MapCombat, InGameCombat->CurrentCaseSelect, &InGameCombat->Fightsystem, &InGameCombat->Perso, &InGameCombat->ManagerEnemy, InGameCombat->CameraMC, &InGameCombat->AllSprite, InGameCombat->Fightsystem.turn.turnPlayer, GD->DataSystem.window);
		displayParticlesFront(&InGameCombat->MapCombat.particles, GD->DataSystem.window);
		if (InGameCombat->Out == 0)
		{

			DisplayHudPlayers(&InGameCombat->FightHud, &GD->DataSystem, &InGameCombat->Fightsystem, &InGameCombat->Perso, InGameCombat->CameraMC);
			DisplaySpellInUse(&InGameCombat->FightHud, &InGameCombat->Perso, &GD->DataSystem);
			if (InGameCombat->Fightsystem.turn.turnPlayer <= 4)
			{
				DisplayHud(&InGameCombat->FightHud.HudCombat, &InGameCombat->FightHud.AllSprite, &InGameCombat->Fightsystem, &GD->DataSystem, &InGameCombat->Perso);
				DisplayStatsHud(&InGameCombat->Perso.player, &InGameCombat->FightHud, &GD->DataSystem);
				DisplayPassTurn(&InGameCombat->FightHud.HudCombat, &GD->DataSystem);
				DisplayMoove(&InGameCombat->FightHud, &GD->DataSystem);
			}
			displayInfoWindow(&InGameCombat->FightHud, &InGameCombat->Perso, &InGameCombat->Fightsystem, GD->DataSystem.window);
			DisplayEnemyLife(&InGameCombat->FightHud, &InGameCombat->ManagerEnemy, InGameCombat->CameraMC, GD->DataSystem.window);
		}

		if (InGameCombat->Out == 1)
		{

			blitSprite(InGameCombat->AllSprite.GameOver, 0, 0, 0, GD->DataSystem.window);
		}

		sfRenderWindow_display(GD->DataSystem.window);
	}
}

/////////////////////////////////////////////////////////////////////
//FONCTION TEMPORAIREMENT PLACER ICI EN ATTENTE DE TABLE DE PERSO
/////////////////////////////////////////////////////////////////////
