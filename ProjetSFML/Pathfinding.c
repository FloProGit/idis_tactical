#include"Pathfinding.h"


/////////////////////////////////*****************README**********************////////////////////////////////////////////////////
//fonctionement du patfinding 
// a l'init la fonction  "CreatemapPath" crée une map de la taille de la map actuellement charger.
////
//a chaque fois que vous allez utiliser le pathfiding:.
// 1 --> fonction  "CleanMap" remplie les case de "999" et "Unavailable".
// 2--> effectuer un "UpdateMapPath" qui va detecté si les case sont praticable grace au donnée de la "Map2D" pour l'actualisé voir si dessous.
// 3--> ensuite vous pouver utilisé vos fonctions tel que Remplissage.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////
//A NOTER "displayCACA" et temporaire il permet de voir les case "Available" sur la map La 
//METTRE EN COMMETAIRE CAR ELLE AFFICHE TOUT LES BLOC EN ROUGE AINSI QUE CELLE DE SELECTION.
////
// pour actualiser la map2D il faut le faire aprés chaque deplacement de personnage cette fonction ce trouve dans "COMBAT.C" en bas du code
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////EXEMPLE DE REMPLISSAGE READAPTER AU CODE ACTUEL/////////////////////////
//int Remplissage(D_MapPath * Map, int X, int Y, int pas)
//{
//	if (X >= 0 && X < X && //Si les coordonnées sont valides
//		Y >= 0 && Y < Map->SizeMap.y)
//	{
//		if (Map->MapP[Y][X].nbr > pas && Map->MapP[Y][X].StateCase == Available) //Et si il n'y a pas d'obstacle et qu'on peut "creuser"
//		{
//			Map->MapP[Y][X].nbr = pas; //On creuse
//
//			Remplissage(Map, X, Y - 1, pas + 1); //haut
//			Remplissage(Map, X, Y + 1, pas + 1); //Bas
//			Remplissage(Map, X - 1, Y, pas + 1); //Gauche
//			Remplissage(Map, X + 1, Y, pas + 1); //Droite
//		}
//	}
//}
////////////////////////////////////////////////////////////////////////

////////////////////UTILS/////////////////////////
void CleanMap(D_MapPath* Map)
{
	for (int i = 0; i < Map->SizeMap.y; i++)
	{
		for (int j = 0; j < Map->SizeMap.x; j++)
		{
			Map->MapP[i][j].nbr = 999;
			Map->MapP[i][j].State = Unavailable;
			Map->MapP[i][j].isColored = 0;
		}
	}
}
void CleanMap2DandPath(D_MapPath* Map, D_Map2D **Map2D)
{
	for (int i = 0; i < Map->SizeMap.y; i++)
	{
		for (int j = 0; j < Map->SizeMap.x; j++)
		{
			Map->MapP[i][j].nbr = 999;
			Map->MapP[i][j].State = Unavailable;
			Map->MapP[i][j].isColored = 0;
			Map2D[i][j].isColored = 0;
			//Map2D[i][j].OnOffCase2D = ON;
		}
	}
}
///////////////////INIT///////////////////////////
void CreatemapPath(D_MapPath* Map, sfVector3i MapSize)
{
	sfVector2i SizeMap = { MapSize.x,MapSize.y };
	Map->SizeMap = SizeMap;

	Map->MapP = calloc(Map->SizeMap.y, sizeof(D_MapPath*));
	Map->TabReturn = calloc(Map->SizeMap.y, sizeof(int*));
	for (int i = 0; i < Map->SizeMap.y; i++)
	{
		Map->MapP[i] = calloc(Map->SizeMap.x, sizeof(D_MapPath));
		Map->TabReturn[i] = calloc(Map->SizeMap.x, sizeof(int));
	}
	CleanMap(Map);
}


//////////////////////////UPADATE/////////////////////////////////
void UpdateMapPath(D_MapPath* MapPath, D_Map2D **Map2D)
{
	CleanMap(MapPath);

	for (int i = 0; i < MapPath->SizeMap.y; i++)
	{
		for (int j = 0; j < MapPath->SizeMap.x; j++)
		{
			
			if (Map2D[i][j].StateCase == NullC2d)
			{
				MapPath->MapP[i][j].State = Unavailable;
			}
			else
			{
				MapPath->MapP[i][j].State = Unavailable;
			}
		}
	}
}


int FillingPath(int _x, int _y, int pas, D_MapPath* MapPath)
{

	//printf("TEST_____________%d_______%d______________",_x,_y);
	//printf("TEST_____________%d_______%d______________", MapPath->SizeMap.x, MapPath->SizeMap.y);



	//printf("X = %d  \t Y = %d", _x, _y);

	if (_x >= 0 && _x < MapPath->SizeMap.x  && //Si les coordonnées sont valides
		_y >= 0 && _y < MapPath->SizeMap.y)
	{
		//printf(" \nSTATE = %d \n", MapPath->MapP[_y][_x].State);

		//&&  MapPath->MapP[_y][_x].State != Unavailable
		if (MapPath->MapP[_y][_x].nbr > pas &&  MapPath->MapP[_y][_x].State != Unavailable) //Et si il n'y a pas d'obstacle et qu'on peut "creuser"
		{
			//printf("FILLING\n");

			MapPath->MapP[_y][_x].nbr = pas; //On creuse

			FillingPath(_x, _y - 1, pas + 1, MapPath); //haut
			FillingPath(_x, _y + 1, pas + 1, MapPath); //Bas
			FillingPath(_x - 1, _y, pas + 1, MapPath); //Gauche	
			FillingPath(_x + 1, _y, pas + 1, MapPath); //Droite
		}
	}

}

void ComeBackWay(D_MapPath* MapPath, sfVector2i Pos, int max)
{
	////mettre securité au cas ou il est entouré
	if (MapPath->MapP[Pos.y][Pos.x].nbr != 999) //Chemin trouvé
	{

		int x = Pos.x;
		int y = Pos.y;
		while (MapPath->MapP[y][x].nbr != 0 && MapPath->MapP[y][x].nbr <= max)
		{

			if (x > 0)
			{
				if (MapPath->MapP[y][x - 1].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					x--;
					MapPath->MapP[y][x].isColored = 4;
				}
			}
			if (x < MapPath->SizeMap.x - 1)
			{
				if (MapPath->MapP[y][x + 1].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					x++;
					MapPath->MapP[y][x].isColored = 4;
				}
			}

			if (y > 0)
			{
				if (MapPath->MapP[y - 1][x].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					y--;
					MapPath->MapP[y][x].isColored = 4;
				}
			}
			if (y < MapPath->SizeMap.y - 1)
			{
				if (MapPath->MapP[y + 1][x].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					y++;
					MapPath->MapP[y][x].isColored = 4;
				}
			}

		}
	}
}

int GetDistancePF(int _x, int _y, int _x2, int _y2, int pas, D_MapPath* MapPath)
{

	FillingPath(_x, _y, pas, MapPath);
	//printf("_____________________________FILLING________________________________\n");
	for (int i = 0; i < MapPath->SizeMap.y; i++)
	{
		for (int j = 0; j < MapPath->SizeMap.x; j++)
		{
			//printf("%d/", MapPath->MapP[i][j].nbr);
		}
		//printf("\n");
	}
	return MapPath->MapP[_y2][_x2].nbr;
}

void ComeBackEnemy(D_MapPath* MapPath, sfVector2i Pos, D_Map2D **map, M_Enemy *Enemy, int nb, int max)
{

	////mettre securité au cas ou il est entouré
	if (MapPath->MapP[Pos.y][Pos.x].nbr != 999) //Chemin trouvé
	{
		int maximum = max;
		int x = Pos.x;
		int y = Pos.y;
		int number = MapPath->MapP[y][x].nbr - 1;

		if (maximum > number)
		{
			maximum = number;
		}

		int Count = 0;
		while (MapPath->MapP[y][x].nbr != 1 && MapPath->MapP[y][x].nbr != 0)
		{
			//printf("X = %d \t Y = %d", x, y);

			if (x > 0)
			{
				if (MapPath->MapP[y][x - 1].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					x--;
					//MapPath->MapP[y][x].isColored = 4;

					Enemy->Data_Enemy[nb].TabPath[Count].x = x;
					Enemy->Data_Enemy[nb].TabPath[Count].y = y;
					Count++;
				}
			}
			if (x < MapPath->SizeMap.x - 1)
			{
				if (MapPath->MapP[y][x + 1].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					x++;
					//MapPath->MapP[y][x].isColored = 4;

					Enemy->Data_Enemy[nb].TabPath[Count].x = x;
					Enemy->Data_Enemy[nb].TabPath[Count].y = y;
					Count++;

				}
			}
			if (y > 0)
			{
				if (MapPath->MapP[y - 1][x].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					y--;
					//MapPath->MapP[y][x].isColored = 4;

					Enemy->Data_Enemy[nb].TabPath[Count].x = x;
					Enemy->Data_Enemy[nb].TabPath[Count].y = y;
					Count++;
				}
			}
			if (y < MapPath->SizeMap.y - 1)
			{
				if (MapPath->MapP[y + 1][x].nbr == MapPath->MapP[y][x].nbr - 1)
				{
					y++;
					//MapPath->MapP[y][x].isColored = 4;

					Enemy->Data_Enemy[nb].TabPath[Count].x = x;
					Enemy->Data_Enemy[nb].TabPath[Count].y = y;
					Count++;

				}
			}
		}
	}
}

int**  GeneralFillingAndPath(D_Filling *Filling, D_MapPath* MapPath, D_Map2D **map, M_Enemy *Enemy, D_Perso *Perso, sfVector2i Currentcase, int Turn, int PoSpell, int FilingSpell, int WhoPlay)
{
	for (int i = 0; i < MapPath->SizeMap.y; i++)
	{
		for (int j = 0; j < MapPath->SizeMap.x; j++)
		{
			MapPath->MapP[i][j].isColored = 0;

			if (map[i][j].OnOffCase2D == ON)
			{
				MapPath->MapP[i][j].State = Available;
				MapPath->MapP[i][j].nbr = 999;
			}
			else
			{
				MapPath->MapP[i][j].State = Unavailable;
				MapPath->MapP[i][j].nbr = 1000;
			}
			//printf("%d/", MapPath->MapP[i][j].State);
		}
		//printf("\n");
	}



	//// ETAPE 1 REMPLISSAGE DE LA MAP PATH SELON TARGETING////

	switch (Filling->Target)
	{
	case TargetPlayer: //// CIBLAGE UNIQUEMENT JOUEUR 
		for (int i = 0; i < Enemy->TotEnemy; i++)
		{
			if (Enemy->Data_Enemy[i].Stat.PV > 0)
			{
				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].State = Unavailable;
			}
		};

		break;
	case TargetEnemy://// CIBLAGE UNIQUEMENT ENEMY 
		for (int i = 0; i < 4; i++)
		{
			if (Perso->player[i].Stat.PV > 0)
			{
				MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column].State = Unavailable;
			}
		};
		break;

	case MouvePLayer:
		for (int i = 0; i < 4; i++)
		{
			if (Turn != i)
			{
				MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column].State = Unavailable;
			}

		};
		for (int i = 0; i < Enemy->TotEnemy; i++)
		{
			if (Enemy->Data_Enemy[i].Stat.PV > 0)
			{
				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].State = Unavailable;
			}
		};


		for (int i = 0; i < MapPath->SizeMap.y; i++)
		{
			for (int j = 0; j < MapPath->SizeMap.x; j++)
			{

				if (MapPath->MapP[i][j].State == Available)
				{
					MapPath->MapP[i][j].isColored = 0;
				}
				else
				{
					MapPath->MapP[i][j].isColored = 10;
				}

			}
		}





		MapPath->MapP[Perso->player[Turn].Line][Perso->player[Turn].Column].isColored = 1;

		for (int d = 0; d < Perso->player[Turn].Stat.PM + 1; d++)
		{
			for (int i = 0; i < MapPath->SizeMap.y; i++)
			{
				for (int j = 0; j < MapPath->SizeMap.x; j++)
				{

					if (MapPath->MapP[i][j].isColored == 1)
					{
						if (j - 1 >= 0 && j - 1 < MapPath->SizeMap.x && MapPath->MapP[i][j - 1].isColored != -1 && MapPath->MapP[i][j - 1].isColored != 1 && MapPath->MapP[i][j - 1].isColored != 10)
						{
							MapPath->MapP[i][j - 1].isColored = 3;
						}
						if (j + 1 >= 0 && j + 1 < MapPath->SizeMap.x && MapPath->MapP[i][j + 1].isColored != -1 && MapPath->MapP[i][j + 1].isColored != 1 && MapPath->MapP[i][j + 1].isColored != 10)
						{
							MapPath->MapP[i][j + 1].isColored = 3;
						}
						if (i - 1 >= 0 && i - 1 < MapPath->SizeMap.y && MapPath->MapP[i - 1][j].isColored != -1 && MapPath->MapP[i - 1][j].isColored != 1 && MapPath->MapP[i - 1][j].isColored != 10)
						{
							MapPath->MapP[i - 1][j].isColored = 3;
						}
						if (i + 1 >= 0 && i + 1 < MapPath->SizeMap.y && MapPath->MapP[i + 1][j].isColored != -1 && MapPath->MapP[i + 1][j].isColored != 1 && MapPath->MapP[i + 1][j].isColored != 10)
						{
							MapPath->MapP[i + 1][j].isColored = 3;
						}
					}

				}
			}

			for (int i = 0; i < MapPath->SizeMap.y; i++)////CHANGE LES  3 en 1 et les 1 en - 1
			{
				for (int j = 0; j < MapPath->SizeMap.x; j++)
				{
					if (MapPath->MapP[i][j].isColored != 10)
					{
						if (MapPath->MapP[i][j].isColored == 1)
						{
							MapPath->MapP[i][j].isColored = -1;
						}

						if (MapPath->MapP[i][j].isColored == 3)
						{
							MapPath->MapP[i][j].isColored = 1;
						}
					}
				}
			}
		}

		for (int i = 0; i < MapPath->SizeMap.y; i++)////COLORISATION - 1 en 2
		{
			for (int j = 0; j < MapPath->SizeMap.x; j++)
			{
				if (MapPath->MapP[i][j].isColored == -1)
				{
					MapPath->MapP[i][j].isColored = 2;
				}
			}

		}
		MapPath->MapP[Perso->player[Turn].Line][Perso->player[Turn].Column].isColored = -1;
		FillingPath(Perso->player[Turn].Column, Perso->player[Turn].Line, 0, MapPath);
		ComeBackWay(MapPath, Currentcase, Perso->player[Turn].Stat.PM);

		if (MapPath->MapP[Currentcase.y][Currentcase.x].isColored == 2)
		{
			MapPath->MapP[Currentcase.y][Currentcase.x].isColored = 4;

		}

		break;
	case MouverEnemy: ////PREPARATION POUR LE PATHFINDING POUR LE DEPLACEMENT 
					  //Positon Enemy et Joueur Invalide (pas de déplacemenet dessus)

		if (Enemy->Data_Enemy[Turn].CurrentCaseMove >= Enemy->Data_Enemy[Turn].Stat.PM && Enemy->Data_Enemy[Turn].CurrentCaseMove < 900)
		{
			Enemy->Data_Enemy[Turn].CurrentCaseMove -= Enemy->Data_Enemy[Turn].Stat.PM;


		}
		else
		{
			if (Enemy->Data_Enemy[Turn].CurrentCaseMove != 0)
			{
				Enemy->Data_Enemy[Turn].CurrentCaseMove = 0;
			}
			else
			{
				Enemy->Data_Enemy[Turn].CurrentCaseMove = -1;
			}
		}

		if (Enemy->Data_Enemy[Turn].CurrentCaseMove != -1)
		{
			Enemy->Data_Enemy[Turn].map.y = Enemy->Data_Enemy[Turn].TabPath[Enemy->Data_Enemy[Turn].CurrentCaseMove].y;
			Enemy->Data_Enemy[Turn].map.x = Enemy->Data_Enemy[Turn].TabPath[Enemy->Data_Enemy[Turn].CurrentCaseMove].x;
			Enemy->Data_Enemy[Turn].pos.x = map[Enemy->Data_Enemy[Turn].map.y][Enemy->Data_Enemy[Turn].map.x].Pos.x;
			Enemy->Data_Enemy[Turn].pos.y = map[Enemy->Data_Enemy[Turn].map.y][Enemy->Data_Enemy[Turn].map.x].Pos.y;
			Enemy->Data_Enemy[Turn].Stat.PM = 0;
			switch (Enemy->Data_Enemy[Turn].I_A)
			{
			case berserk: Enemy->Data_Enemy[Turn].action = 2;
				break;
			case running: Enemy->Data_Enemy[Turn].action = 3;
				break;
			}
			Enemy->Data_Enemy[Turn].pause = 0;
		}



		break;

	default:
		break;
	}




	//printf("_____________________________________________________________\n");
	for (int i = 0; i < MapPath->SizeMap.y; i++)
	{
		for (int j = 0; j < MapPath->SizeMap.x; j++)
		{
			//printf("%d/", MapPath->MapP[i][j].nbr);
		}
		//printf("\n");
	}






	if (Filling->Target == TargetPlayer || Filling->Target == TargetEnemy)
	{
		////ETAPE 2 SELECTION DU PREMIER REMPLISSAGE DE LA MAP SI ATTACK

		sfVector2i TempPos;

		if (WhoPlay == 0)//// 0 = PLAYER TURN
		{
			TempPos.x = Perso->player[Turn].Column;
			TempPos.y = Perso->player[Turn].Line;

		}
		else
		{
			TempPos.x = Enemy->Data_Enemy[Turn].map.x;
			TempPos.y = Enemy->Data_Enemy[Turn].map.y;



		}
		if (Perso->player[2].spell[1].inUse == 1 || Perso->player[2].spell[2].inUse == 1 || Perso->player[2].spell[3].inUse == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column].State = Available;
			};
		}

		if (Perso->player[1].spell[1].inUse == 1 )
		{
			for (int i = 0; i < 4; i++)
			{
				MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column].State = Unavailable;
			};
		}
		if (Perso->player[3].spell[2].inUse == 1)
		{

			for (int i = 0; i < Enemy->TotEnemy; i++)
			{

				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].State = Unavailable;


			};

		}

		if (Filling->ATK == ATKFull)
		{

			for (int i = 0; i < MapPath->SizeMap.y; i++)
			{
				for (int j = 0; j < MapPath->SizeMap.x; j++)
				{

					if (MapPath->MapP[i][j].State == Available)
					{
						MapPath->MapP[i][j].isColored = 0;
					}
					else
					{
						MapPath->MapP[i][j].isColored = 10;
					}

				}
			}





			MapPath->MapP[TempPos.y][TempPos.x].isColored = 1;


			for (int d = 0; d < PoSpell; d++)
			{
				for (int i = 0; i < MapPath->SizeMap.y; i++)
				{
					for (int j = 0; j < MapPath->SizeMap.x; j++)
					{

						if (MapPath->MapP[i][j].isColored == 1)
						{
							if (j - 1 >= 0 && j - 1 < MapPath->SizeMap.x && MapPath->MapP[i][j - 1].isColored != -1 && MapPath->MapP[i][j - 1].isColored != 1 && MapPath->MapP[i][j - 1].isColored != 10)
							{
								MapPath->MapP[i][j - 1].isColored = 3;
							}
							if (j + 1 >= 0 && j + 1 < MapPath->SizeMap.x && MapPath->MapP[i][j + 1].isColored != -1 && MapPath->MapP[i][j + 1].isColored != 1 && MapPath->MapP[i][j + 1].isColored != 10)
							{
								MapPath->MapP[i][j + 1].isColored = 3;
							}
							if (i - 1 >= 0 && i - 1 < MapPath->SizeMap.y && MapPath->MapP[i - 1][j].isColored != -1 && MapPath->MapP[i - 1][j].isColored != 1 && MapPath->MapP[i - 1][j].isColored != 10)
							{
								MapPath->MapP[i - 1][j].isColored = 3;
							}
							if (i + 1 >= 0 && i + 1 < MapPath->SizeMap.y && MapPath->MapP[i + 1][j].isColored != -1 && MapPath->MapP[i + 1][j].isColored != 1 && MapPath->MapP[i + 1][j].isColored != 10)
							{
								MapPath->MapP[i + 1][j].isColored = 3;
							}
						}

					}
				}

			
				for (int i = 0; i < MapPath->SizeMap.y; i++)////CHANGE LES  3 en 1 et les 1 en - 1
				{
					for (int j = 0; j < MapPath->SizeMap.x; j++)
					{
						if (MapPath->MapP[i][j].isColored != 10)
						{
							if (MapPath->MapP[i][j].isColored == 1)
							{
								MapPath->MapP[i][j].isColored = -1;
							}

							if (MapPath->MapP[i][j].isColored == 3)
							{
								MapPath->MapP[i][j].isColored = 1;
							}
						}
					}
				}
			}

			for (int i = 0; i < MapPath->SizeMap.y; i++)////COLORISATION - 1 en 2
			{
				for (int j = 0; j < MapPath->SizeMap.x; j++)
				{
					if (MapPath->MapP[i][j].isColored == -1)
					{
						MapPath->MapP[i][j].isColored = 2;
					}

				}
			}
			MapPath->MapP[TempPos.y][TempPos.x].isColored = -1;


			
		}
		if (Filling->ATK == ATKCross)//////Creation de la ligne de Colorisation pour spell
		{



			for (int i = 0; i < PoSpell; i++)
			{
				if (TempPos.y + i <= MapPath->SizeMap.y - 1)
				{
					if (MapPath->MapP[TempPos.y + i][TempPos.x].State == Available)
					{
						MapPath->MapP[TempPos.y + i][TempPos.x].isColored = 2;

					}
				}

				if (TempPos.y - i >= 0)
				{
					if (MapPath->MapP[TempPos.y - i][TempPos.x].State == Available)
					{
						MapPath->MapP[TempPos.y - i][TempPos.x].isColored = 2;
					}
				}

				if (TempPos.x + i <= MapPath->SizeMap.x - 1)
				{
					if (MapPath->MapP[TempPos.y][TempPos.x + i].State == Available)
					{
						MapPath->MapP[TempPos.y][TempPos.x + i].isColored = 2;
					}
				}

				if (TempPos.x - i >= 0)
				{
					if (MapPath->MapP[TempPos.y][TempPos.x - i].State == Available)
					{
						MapPath->MapP[TempPos.y][TempPos.x - i].isColored = 2;
					}
				}
			}
		}

		////ETAPE 3 SELECTION DU DEUXIEME REMPLISSAGE DE LA MAP SI ATTACK




		if (Filling->Zone == Cross)
		{

			if (MapPath->MapP[Currentcase.y][Currentcase.x].isColored == 2)
			{
				MapPath->MapP[Currentcase.y][Currentcase.x].isColored = 3;
				if (MapPath->MapP[Currentcase.y][Currentcase.x].isColored == 3)
				{
					for (int i = 0; i < FilingSpell; i++)
					{
						if (Currentcase.y + i <= MapPath->SizeMap.y - 1)
						{
							MapPath->MapP[Currentcase.y + i][Currentcase.x].isColored = 3;
						}

						if (Currentcase.y - i >= 0)
						{
							MapPath->MapP[Currentcase.y - i][Currentcase.x].isColored = 3;
						}

						if (Currentcase.x + i <= MapPath->SizeMap.x - 1)
						{
							MapPath->MapP[Currentcase.y][Currentcase.x + i].isColored = 3;
						}

						if (Currentcase.x - i >= 0)
						{
							MapPath->MapP[Currentcase.y][Currentcase.x - i].isColored = 3;
						}
					}
				}
			}

		}



		if (Filling->Zone == AOE)
		{

			/*for (int i = 0; i < MapPath->SizeMap.y; i++)
			{
			for (int j = 0; j < MapPath->SizeMap.x; j++)
			{

			if (MapPath->MapP[i][j].State == Available)
			{
			MapPath->MapP[i][j].isColored = 0;
			}
			else
			{
			MapPath->MapP[i][j].isColored = 10;
			}

			}
			}
			*/

			if (MapPath->MapP[Currentcase.y][Currentcase.x].isColored == 2)
			{


				MapPath->MapP[Currentcase.y][Currentcase.x].isColored = 1;


				for (int d = 0; d < FilingSpell + 1; d++)
				{
					for (int i = 0; i < MapPath->SizeMap.y; i++)
					{
						for (int j = 0; j < MapPath->SizeMap.x; j++)
						{

							if (MapPath->MapP[i][j].isColored == 1)
							{
								if (j - 1 >= 0 && j - 1 < MapPath->SizeMap.x && MapPath->MapP[i][j - 1].isColored != -1 && MapPath->MapP[i][j - 1].isColored != 1 && MapPath->MapP[i][j - 1].isColored != 10)
								{
									MapPath->MapP[i][j - 1].isColored = 3;
								}
								if (j + 1 >= 0 && j + 1 < MapPath->SizeMap.x && MapPath->MapP[i][j + 1].isColored != -1 && MapPath->MapP[i][j + 1].isColored != 1 && MapPath->MapP[i][j + 1].isColored != 10)
								{
									MapPath->MapP[i][j + 1].isColored = 3;
								}
								if (i - 1 >= 0 && i - 1 < MapPath->SizeMap.y && MapPath->MapP[i - 1][j].isColored != -1 && MapPath->MapP[i - 1][j].isColored != 1 && MapPath->MapP[i - 1][j].isColored != 10)
								{
									MapPath->MapP[i - 1][j].isColored = 3;
								}
								if (i + 1 >= 0 && i + 1 < MapPath->SizeMap.y && MapPath->MapP[i + 1][j].isColored != -1 && MapPath->MapP[i + 1][j].isColored != 1 && MapPath->MapP[i + 1][j].isColored != 10)
								{
									MapPath->MapP[i + 1][j].isColored = 3;
								}
							}

						}
					}

					for (int i = 0; i < MapPath->SizeMap.y; i++)////CHANGE LES  3 en 1 et les 1 en - 3
					{
						for (int j = 0; j < MapPath->SizeMap.x; j++)
						{
							if (MapPath->MapP[i][j].isColored != 10)
							{
								if (MapPath->MapP[i][j].isColored == 1)
								{
									MapPath->MapP[i][j].isColored = -1;
								}

								if (MapPath->MapP[i][j].isColored == 3)
								{
									MapPath->MapP[i][j].isColored = 1;
								}
							}
						}
					}
				}

				for (int i = 0; i < MapPath->SizeMap.y; i++)////COLORISATION - 1 en 2
				{
					for (int j = 0; j < MapPath->SizeMap.x; j++)
					{
						if (MapPath->MapP[i][j].isColored == -1)
						{
							MapPath->MapP[i][j].isColored = 3;
						}

					}
				}
			}
		}


		/*for (int i = 0; i < PoSpell; i++)
		{
			if (TempPos.y + i <= MapPath->SizeMap.y - 1)
			{
				if (MapPath->MapP[TempPos.y + i][TempPos.x].State == Available && MapPath->MapP[TempPos.y + i][TempPos.x].isColored == 1)
				{
					MapPath->MapP[TempPos.y + i][TempPos.x].isColored = 2;

				}
			}

			if (TempPos.y - i >= 0)
			{
				if (MapPath->MapP[TempPos.y - i][TempPos.x].State == Available && MapPath->MapP[TempPos.y - i][TempPos.x].isColored == 1)
				{
					MapPath->MapP[TempPos.y - i][TempPos.x].isColored = 2;
				}
			}

			if (TempPos.x + i <= MapPath->SizeMap.x - 1)
			{
				if (MapPath->MapP[TempPos.y][TempPos.x + i].State == Available && MapPath->MapP[TempPos.y][TempPos.x + i].isColored == 1)
				{
					MapPath->MapP[TempPos.y][TempPos.x + i].isColored = 2;
				}
			}

			if (TempPos.x - i >= 0)
			{
				if (MapPath->MapP[TempPos.y][TempPos.x - i].State == Available && MapPath->MapP[TempPos.y][TempPos.x - i].isColored == 1)
				{
					MapPath->MapP[TempPos.y][TempPos.x - i].isColored = 2;
				}
			}
		}*/

	}
	if (MapPath->MapP[Currentcase.y][Currentcase.x].isColored == 3)
	{
	}

	//printf("____________________FIN FUNCTION ______________________________");
	for (int i = 0; i < MapPath->SizeMap.y; i++)////COLORISATION - 1 en 2
	{
		for (int j = 0; j < MapPath->SizeMap.x; j++)
		{

			map[i][j].isColored = MapPath->MapP[i][j].isColored;


			if (map[i][j].isColored == 4)
			{
				//printf("Trouvé");
			}


		}
	}
	

	return MapPath->TabReturn;



}




