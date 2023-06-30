#include "FightSystem.h"



///////////////////////////////////////////////////
///----------------------UTILS------------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES PETITE FONCTION UTILITAIRE POUR SIMPLIFIER LE TRAVAIL


///////////////////////////////////////////////////
///----------------------INIT-----------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES FONCTION INIT



void InitFightSystem(D_FightSystem* fightSystem, D_MapCombat* Map)
{
	//Sprite des case pour le pathFiding
	//fightSystem->caseSprite.PathFidingHori = LoadSprite("Images/PathFiding/pathFidingHori.png", 0, 0, 0);
	//fightSystem->caseSprite.PathFidingVerti = LoadSprite("Images/PathFiding/PathFidingVerti.png", 0, 0, 0);

	fightSystem->caseSprite.isoGreen = LoadSprite("caseIsoGreen.png", 0, 0, 0);
	fightSystem->caseSprite.isoRed = LoadSprite("caseIsoRed.png", 0, 0, 0);




	fightSystem->mapIscreate = 0;

	fightSystem->SizeMapF.x = Map->Size.x;
	fightSystem->SizeMapF.y = Map->Size.y;

	fightSystem->pathFiding.tabPo = calloc(Map->Size.y, sizeof(int*));

	for (int i = 0; i < Map->Size.y; i++)
	{
		fightSystem->pathFiding.tabPo[i] = calloc(Map->Size.x, sizeof(int));
	}
	fightSystem->pathFiding.chemin = calloc(Map->Size.y, sizeof(int*));

	for (int i = 0; i < Map->Size.y; i++)
	{
		fightSystem->pathFiding.chemin[i] = calloc(Map->Size.x, sizeof(int));
	}


	fightSystem->CaseSelect.x = 0;
	fightSystem->CaseSelect.y = 0;


	fightSystem->caseX = 0;
	fightSystem->caseY = 0;
	fightSystem->turn.turnPlayer = 1;

	fightSystem->spellAnimUse = 0;
	fightSystem->CurrentSpellUse = 0;
}

//reset les attaque et clean la map 
void resetAttackMode(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map)
{
	//Attack
	if (perso->player[fightSystem->turn.turnPlayer - 1].attackMode == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			perso->player[fightSystem->turn.turnPlayer - 1].spell[i].inUse = 0;
		}
		//SpellTabInit(fightSystem, map);
	}
	//Deplacement
	if (perso->player[fightSystem->turn.turnPlayer - 1].mooveMode == 1)
	{
		perso->player[fightSystem->turn.turnPlayer - 1].attackMode = 0;
		for (int i = 0; i < 4; i++)
		{
			perso->player[fightSystem->turn.turnPlayer - 1].spell[i].inUse = 0;
		}
		//SpellTabInit(fightSystem, map);
	}
}


void MouveSystem(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, D_MapPath* MapPath, D_Enemy * Enemy, sfVector2i Currentcase)
{

	D_Filling tempFilling = { 0,0,0 };

	tempFilling.Target = MouvePLayer;
	tempFilling.ATK = NOATK;
	tempFilling.Zone = NOZONE;
	GeneralFillingAndPath(&tempFilling, MapPath, map, Enemy, perso, Currentcase, fightSystem->turn.turnPlayer - 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, 0); /////A FAIRE
}

//Fonction envoyé dans l'update du jeux
void FightSystem(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, D_MapPath* MapPath, M_Enemy * Enemy, sfVector2i Currentcase)
{
	D_Filling tempFilling = { 0,0,0 };
	//Attaque
	if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].inUse == 1)
	{
		for (int i = 0; i < fightSystem->SizeMapF.y; i++)
		{
			for (int j = 0; j < fightSystem->SizeMapF.x; j++)
			{
				map[i][j].isColored = 0;
			}
		}
		//Po qui s'étale autour du joueur
		if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].type == 1)
		{

			tempFilling.Target = TargetEnemy;
			tempFilling.ATK = ATKFull;
			tempFilling.Zone = Single;
			GeneralFillingAndPath(&tempFilling, MapPath, map, Enemy, perso, Currentcase, fightSystem->turn.turnPlayer - 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, 0); /////A FAIRE


																																																																															 //Spell(fightSystem, perso, perso->player[fightSystem->turn.turnPlayer - 1].Column, perso->player[fightSystem->turn.turnPlayer - 1].Line, 0, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, map, Enemy);
		}
		//Po en Ligne
		if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].type == 2)
		{

			tempFilling.Target = TargetEnemy;
			tempFilling.ATK = ATKCross;
			tempFilling.Zone = Single;
			GeneralFillingAndPath(&tempFilling, MapPath, map, Enemy, perso, Currentcase, fightSystem->turn.turnPlayer - 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, 0); /////A FAIRE
																																																																															 //LineSpell(fightSystem, perso, map, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].Column, perso->player[fightSystem->turn.turnPlayer - 1].Line, 2);
		}
		//Po en Ligne puis s'étale
		if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].type == 3)
		{
			tempFilling.Target = TargetEnemy;
			tempFilling.ATK = ATKCross;
			tempFilling.Zone = AOE;

			GeneralFillingAndPath(&tempFilling, MapPath, map, Enemy, perso, Currentcase, fightSystem->turn.turnPlayer - 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, 2, 0); /////A FAIRE


																																																								 //LineSpell(fightSystem, perso, map, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].Column, perso->player[fightSystem->turn.turnPlayer - 1].Line, 2);
																																																								 //SpellSpécial(fightSystem, perso, Currentcase.x, Currentcase.y, 0, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po, map, Enemy, Currentcase);
		}
		//Po en ligne puis en ligne
		if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].type == 4)
		{

			tempFilling.Target = TargetEnemy;
			tempFilling.ATK = ATKCross;
			tempFilling.Zone = Cross;
			GeneralFillingAndPath(&tempFilling, MapPath, map, Enemy, perso, Currentcase, fightSystem->turn.turnPlayer - 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, 0); /////A FAIRE																																																																										 //LineSpell(fightSystem, perso, map, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, perso->player[fightSystem->turn.turnPlayer - 1].Column, perso->player[fightSystem->turn.turnPlayer - 1].Line, 2);
																																																																															 //LineSpellSpecial(fightSystem, perso, map, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].po + 1, Currentcase.x, Currentcase.y, 3);
		}

	}
	//Deplacement
	if (perso->player[fightSystem->turn.turnPlayer - 1].mooveMode == 1)
	{
		for (int i = 0; i < fightSystem->SizeMapF.y; i++)
		{
			for (int j = 0; j < fightSystem->SizeMapF.x; j++)
			{
				map[i][j].isColored = 0;
			}
		}

	}
}



///////////////////////////////////////////////////
///----------------------EVENT-----------------///
///////////////////////////////////////////////////

void MoovePlayer(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, sfVector2i Currentcase, sfVector2i Mouse)
{
	//Deplacement du joueur
	if (Mouse.y < 900)
	{
		fightSystem->pathFiding.pathFidingPersoX = Currentcase.x;
		fightSystem->pathFiding.pathFidingPersoY = Currentcase.y;

		if (perso->player[fightSystem->turn.turnPlayer - 1].mooveMode == 1 && map[Currentcase.y][Currentcase.x].isColored == 4)
		{
			perso->player[fightSystem->turn.turnPlayer - 1].Column = fightSystem->pathFiding.pathFidingPersoX;
			perso->player[fightSystem->turn.turnPlayer - 1].Line = fightSystem->pathFiding.pathFidingPersoY;

			perso->player[fightSystem->turn.turnPlayer - 1].x = map[perso->player[fightSystem->turn.turnPlayer - 1].Line][perso->player[fightSystem->turn.turnPlayer - 1].Column].Pos.x;
			perso->player[fightSystem->turn.turnPlayer - 1].y = map[perso->player[fightSystem->turn.turnPlayer - 1].Line][perso->player[fightSystem->turn.turnPlayer - 1].Column].Pos.y;
			perso->player[fightSystem->turn.turnPlayer - 1].mooveMode = 0;

		}
	}
}




void SpellRegroup(D_Map2D **map, D_FightSystem* fightSystem, D_Perso* perso, M_Enemy *Enemy, sfVector2i Currentcase, int mode, int nb)
{
	if (mode == 1)
	{
		Enemy->Data_Enemy[nb].map.x = fightSystem->caseX;
		Enemy->Data_Enemy[nb].map.y = fightSystem->caseY;
		Enemy->Data_Enemy[nb].pos = map[Enemy->Data_Enemy[nb].map.y][Enemy->Data_Enemy[nb].map.x].Pos;
	
		Enemy->Data_Enemy[nb].Stat.isSelected = 0;

		fightSystem->caseX = 0;
		fightSystem->caseY = 0;
		printf("\nJebougel'ennemi\n");
	}
	if (mode == 2)
	{
		
		perso->player[nb].Column = fightSystem->caseX;
		perso->player[nb].Line = fightSystem->caseY;
		perso->player[nb].x = map[perso->player[nb].Line][perso->player[nb].Column].Pos.x;
		perso->player[nb].y = map[perso->player[nb].Line][perso->player[nb].Column].Pos.y;
	

		perso->player[nb].Stat.isSelected = 0;

		fightSystem->caseX = 0;
		fightSystem->caseY = 0;

	}
}


void Attack(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, D_MapCombat *MapCombat, sfVector2i Mouse, M_Enemy *Enemy, sfVector2i Currentcase, SD_GameSound* GameSound)
{


	sfVector2i tempTablePos[13];
	int count = 0;
	for (int i = 0; i < Enemy->TotEnemy; i++)
	{
		if (map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].isColored == 3)
		{
			tempTablePos[count].x = Enemy->Data_Enemy[i].map.x;
			tempTablePos[count].y = Enemy->Data_Enemy[i].map.y;
			count++;
		}
	}




	//Fonction appliquant les effet de l'attaque (pas d'affichage ici)
	if (map[Mouse.y][Mouse.x].isColored == 2 || map[Mouse.y][Mouse.x].isColored == 3)
	{
		//Si le Player est en mode attack (1 spell in use) 
		if (perso->player[fightSystem->turn.turnPlayer - 1].attackMode == 1)
		{
			//Check si le joueur à asser de PA pour faire le spell 
			if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].inUse == 1 && perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA >= perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa)
			{
				//Trap Du Voleur Manque une condition qui check si la case est valid et si elle est occupé par un ennemi
				if (perso->player[3].spell[2].inUse == 1)
				{
					map[Mouse.y][Mouse.x].trap = 1;
				}

				//Boucle des ennemies 
				for (int i = 0; i < Enemy->TotEnemy; i++)
				{
					//Tous les sors de dégat  de Zone  



					//Spell de zone du mage 
					if (perso->player[1].spell[2].inUse == 1)
					{

						if (map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].isColored == 3)
						{
							if (perso->player[1].spell[2].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[6]);
								fightSystem->spellAnimUse = 1;
								fightSystem->CurrentSpellUse = 2;
							}
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);
							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, 0,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage
							);
							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;

						}
					}

					//Si le sort cible un ennemies sur une case ROUGE ou ORANGE 
					if (Enemy->Data_Enemy[i].map.x == Mouse.x && Enemy->Data_Enemy[i].map.y == Mouse.y && perso->player[2].spell[1].inUse == 0)
					{
						//Spell du WARRIOR visans directement un ennemi
						//Coup d'épée
						if (perso->player[0].spell[0].inUse == 1)
						{
							printf("CHANCE TO CRITE = %d \n ", perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit);
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);
							printf("DEFENCE DE LENNEMI BUGUE : %d \n ", &Enemy->Data_Enemy[i].Stat.def);
							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage
							);
							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 6;

							//Son spell warrior
							if (perso->player[0].spell[0].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[0]);
							}
						}
						//Grab du warrior
						if (perso->player[0].spell[2].inUse == 1)
						{
							if (perso->player[0].spell[2].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[2]);
							}

							Attract(&Enemy->Data_Enemy[i].map.x, &Enemy->Data_Enemy[i].map.y, perso->player[fightSystem->turn.turnPlayer - 1].Column, perso->player[fightSystem->turn.turnPlayer - 1].Line, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa);
							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;
					
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
						}
						//Coup de Boul
						if (perso->player[0].spell[3].inUse == 1)
						{
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);
							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit
								, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage);
							Enemy->Data_Enemy[i].isStun = 1;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 5;
						}

						//SPELL MAGE visans directement l'ennemi
						//Poussé du mage 
						if (perso->player[1].spell[0].inUse == 1)
						{


							for (int i = 0; i < 4; i++)
							{
								map[perso->player[i].Line][perso->player[i].Column].OnOffCase2D = OFF;
							}

							Push(&Enemy->Data_Enemy[i].map.x, &Enemy->Data_Enemy[i].map.y, perso->player[fightSystem->turn.turnPlayer - 1].Column, perso->player[fightSystem->turn.turnPlayer - 1].Line, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa, 1, MapCombat, map);
							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 5;
						}

						//Sors Monocible de base
						if (perso->player[1].spell[1].inUse == 1)
						{
							if (perso->player[1].spell[1].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[7]);
							}
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);
							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit
								, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage);

							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 0;


						}
						//Sors Monocible qui fait mal 
						if (perso->player[1].spell[3].inUse == 1)
						{
							if (perso->player[1].spell[3].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[5]);
								fightSystem->spellAnimUse = 1;
								fightSystem->CurrentSpellUse = 0;
							}
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);
							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit
								, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage);

							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 7;
						}
						//SPELL DU VOLEUR 
						//Spell pretre 
						//Messe blanche pretre
						if (perso->player[2].spell[0].inUse == 1)
						{
							printf("\n Debuff \n");
							DebuffAtk(&Enemy->Data_Enemy[i].Stat.ATK, perso->player[2].spell[0].debuff);
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 1;
						}
						
						//Lancé de couteaux
						if (perso->player[3].spell[0].inUse == 1)
						{
							//Son spell Voleur
							if (perso->player[3].spell[0].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[12]);
							}
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);
							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit
								, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage);

							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 6;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
						}

						//COUP DE JARNAC OMG TRO OP CE SORT
						if (perso->player[3].spell[3].inUse == 1)
						{
							if (perso->player[3].spell[3].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[15]);
							}
							Critic(&perso->player[fightSystem->turn.turnPlayer - 1].Stat.crit, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit);

							SpellAttack(
								&Enemy->Data_Enemy[i].Stat.PV,
								&Enemy->Data_Enemy[i].Stat.def,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].dammage,
								&perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa,
								perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].debuff, perso->player[fightSystem->turn.turnPlayer - 1].Stat.bonusATK, &perso->player[fightSystem->turn.turnPlayer - 1].Stat.inCrit
								, &perso->player[fightSystem->turn.turnPlayer - 1].lastDomage);

							Enemy->Data_Enemy[i].pos = map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].Pos;

							Enemy->Data_Enemy[i].deadState = 1;
							Enemy->Data_Enemy[i].SpellAnimTouch = 1;
							fightSystem->spellAnimUse = 1;
							fightSystem->CurrentSpellUse = 6;
						}
					}
				}
				//Boucle des Persos
				for (int i = 0; i < 4; i++)
				{
					//Si un joueur est sur une case ROUGE ou ORANGE 
					if (perso->player[i].Column == Mouse.x && perso->player[i].Line == Mouse.y)
					{
						if (map[perso->player[i].Line][perso->player[i].Column].isColored == 2)
						{
					
							//Heal du prêtre
							if (perso->player[2].spell[1].inUse == 1)
							{
								//Son Spell Pretre 
								if (perso->player[2].spell[1].inUse == 1)
								{
									sfSound_play(GameSound->ActionSound.ActionSound[9]);
								}

								SpellBuff(&perso->player[i].Stat.PV, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].buff);
								fightSystem->spellAnimUse = 1;
								fightSystem->CurrentSpellUse = 3;

								perso->player[i].SpellAnimTouch = 1;
							}
						}
					}
					if (map[perso->player[i].Line][perso->player[i].Column].isColored == 3)
					{

						//Buff de def du Warrior
						if (perso->player[0].spell[1].inUse == 1)
						{
							if (perso->player[0].spell[1].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[1]);
								fightSystem->spellAnimUse = 1;
								fightSystem->CurrentSpellUse = 4;

								perso->player[i].SpellAnimTouch = 1;
							}
							printf("\nJe lance le Shield \n");
							BuffDef(&perso->player[i].Stat.bonusDEF, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].buff);
						}

						//Buff Pm du prêtre 
						if (perso->player[2].spell[3].inUse == 1)
						{
							if (perso->player[2].spell[3].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[11]);
								fightSystem->spellAnimUse = 1;
								fightSystem->CurrentSpellUse = 4;

								perso->player[i].SpellAnimTouch = 1;
							}
							perso->player[i].Stat.PM = 4;
						}
						//Buff ATK Voleur
						if (perso->player[3].spell[1].inUse == 1)
						{
							if (perso->player[3].spell[1].inUse == 1)
							{
								sfSound_play(GameSound->ActionSound.ActionSound[13]);
								fightSystem->spellAnimUse = 1;
								fightSystem->CurrentSpellUse = 4;

								perso->player[i].SpellAnimTouch = 1;
							}
							printf("\nJe lance le Boost attack \n");
							BuffAtk(&perso->player[i].Stat.bonusATK, perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].buff);
						}
					}



				}
				perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA -= perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].CostPa;
			}
		}
	}
	resetAttackMode(fightSystem, perso, map);
	for (int i = 0; i < 4; i++)
	{
		perso->player[i].attackMode = 0;
	}
}



void selectPlayer(sfVector2i CaseSelect, D_Perso* perso, D_FightSystem* fightsystem, sfVector2i Mouse)
{
	if (Mouse.y < 900)
	{
		for (int i = 0; i < 4; i++)
		{

			if (CaseSelect.x == perso->player[i].Column && CaseSelect.y == perso->player[i].Line && perso->player[i].Stat.PV > 0)
			{
				fightsystem->spellAnimUse = 0;
				fightsystem->CurrentSelectSpell = 0;

				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						perso->player[j].spell[k].inUse = 0;
					}
				}
				fightsystem->turn.turnPlayer = (i + 1);
			}
		}
	}
};

///////////////////////////////////////////////////
///----------------------UPDATE-----------------///
///////////////////////////////////////////////////
void MooveEnemiesDead(M_Enemy *Enemy)
{
	for (int i = 0; i < Enemy->TotEnemy; i++)
	{
		if (Enemy->Data_Enemy[i].deadState == 2)
		{
			Enemy->Data_Enemy[i].Stat.Alive = 0;
		}
	}
}

void UpdateFightSystem(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map)
{
	fightSystem->pathFiding.pathFidingPersoX = fightSystem->CaseSelect.x;
	fightSystem->pathFiding.pathFidingPersoY = fightSystem->CaseSelect.y;

	for (int i = 0; i < NBPERSO; i++)
	{
		perso->player[i].x = map[perso->player[i].Line][perso->player[i].Column].Pos.x;
		perso->player[i].y = map[perso->player[i].Line][perso->player[i].Column].Pos.y;
	}
}

void UpdateMapFight(D_FightSystem* fightSystem, D_Map2D **map)
{
	for (int i = 0; i < fightSystem->SizeMapF.y; i++)
	{
		for (int j = 0; j < fightSystem->SizeMapF.x; j++)
		{
			int compteur = 0;
			compteur++;
			if (compteur >= 1 && map[i][j].isColored == 1)
			{
				map[i][j].isColored = 0;
				compteur = 0;
			}
		}
	}
}

void UpdtateStateAttMouve(D_Perso* perso, E_StateSTF* State, D_FightSystem* fightSystem)
{
	if (debug == 1)
	{
	}
	if (perso->player[fightSystem->turn.turnPlayer - 1].attackMode == 1 && perso->player[fightSystem->turn.turnPlayer - 1].mooveMode == 0)
	{
		*State = Att;
	}
	else if (perso->player[fightSystem->turn.turnPlayer - 1].mooveMode == 1 && perso->player[fightSystem->turn.turnPlayer - 1].attackMode == 0)
	{
		*State = Mouve;
	}
	else
	{
		*State = NullSTF;
	}
}

int ItsATrap(D_Map2D **map, D_Perso* perso, M_Enemy *Enemy, D_FightSystem* fightSystem, SD_GameSound* GameSound)
{
	for (int i = 0; i < Enemy->TotEnemy; i++)
	{
		if (map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].trap == 1)
		{
			map[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].trap = 0;
			Enemy->Data_Enemy[i].Stat.PV -= perso->player[3].spell[2].dammage;

			sfSound_play(GameSound->ActionSound.ActionSound[6]);
			fightSystem->spellAnimUse = 1;
			fightSystem->CurrentSpellUse = 2;

			//State de mort de l'énnemie 
			//Enemy->Data_Enemy[i].deadState = 1;
			Enemy->Data_Enemy[i].isStun = 1;

			Enemy->Data_Enemy[i].SpellAnimTouch = 1;
			return perso->player[3].spell[2].dammage;

		}
	}

}

//Condition de défaite quand tous les personnages son mort
void PersoDead(D_Perso* perso)
{
	char done = 0;


	while (done)
	{

		char count = 0;
		for (int i = 0; i < 4; i++)
		{
			if (perso->player[i].Stat.PV == 0)
			{
				count++;
			}
		}

		if (count == 4)
		{

			done = 1;
		}
	}
}
//ICI UNIQUEMENT DES FONCTION UTILISER DANS DES UPDATES
