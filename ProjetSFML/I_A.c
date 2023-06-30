#include"I_A.h"

///////////////////////////////////////////////////
///----------------------UTILS------------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES PETITE FONCTION UTILITAIRE POUR SIMPLIFIER LE TRAVAIL

////I-A\\\\
//Option I_A
void Healing(D_Enemy *D_Enemy, int nb, float minLife)
{
	//MinLife représente un POURCENTAGE
	//Si il y un tiers de ses pv, et qu'il à un point d'action
	if (D_Enemy[nb].Stat.PV <= ((minLife)*D_Enemy[nb].Stat.PV) && D_Enemy[nb].Stat.PA > 0)
	{
		D_Enemy[nb].action = heal;
	}

	//Healing
	if (D_Enemy[nb].action == heal)
	{
		//Give 20% of this life at the enemy
		D_Enemy[nb].Stat.PA--;
		D_Enemy[nb].Stat.PV += D_Enemy[nb].Stat.PVMax / 5;
	}
}

//Calcul la distance entre lui et les joueurs
int DistancePlayer(D_Personnage *perso, D_Enemy *D_Enemy, int nb)
{
	//Calculer la distance qui sépare les joueurs de l'enemy choisi.
	int Distance = sqrt((pow(D_Enemy[nb].map.x - perso->Column, 2) + (pow(D_Enemy[nb].map.y - perso->Line, 2))));
	return Distance;
}

//Calcul la distance entre deux enemis
int DistanceEnemy(D_Enemy *D_Enemy, int nb, int nb2)
{
	//Calculer la distance qui sépare les joueurs de l'enemy choisi.
	int Distance = sqrt((pow(D_Enemy[nb].map.x - D_Enemy[nb2].map.x, 2) + (pow(D_Enemy[nb].map.y - D_Enemy[nb2].map.y, 2))));
	return Distance;
}

//Check si il se trouve à côté d'un Joueur
int BesidePlayer(D_Personnage *perso, D_Enemy *D_Enemy, int nb)
{
	//Direction à côté
	int droit = 0;
	int gauche = 0;
	int bas = 0;
	int haut = 0;

	//à droite
	if ((D_Enemy[nb].map.x == perso->Column + 1) && (D_Enemy[nb].map.y == perso->Line))
	{
		droit = 1;
	}
	else
	{
		droit = 0;
	}
	//à gauche
	if ((D_Enemy[nb].map.x == perso->Column - 1) && (D_Enemy[nb].map.y == perso->Line))
	{
		gauche = 1;
	}
	else
	{
		gauche = 0;
	}
	//en haut
	if ((D_Enemy[nb].map.x == perso->Column) && (D_Enemy[nb].map.y == perso->Line - 1))
	{
		haut = 1;
	}
	else
	{
		haut = 0;
	}
	//en bas
	if ((D_Enemy[nb].map.x == perso->Column) && (D_Enemy[nb].map.y == perso->Line + 1))
	{
		bas = 1;
	}
	else
	{
		bas = 0;
	}

	if (droit == 1 || gauche == 1 || haut == 1 || bas == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int BesideAtkPlayer(D_Personnage *perso, D_Enemy *D_Enemy, int nb)
{
	//Direction à côté
	int droit = 0;
	int gauche = 0;
	int bas = 0;
	int haut = 0;

	//à droite
	if ((D_Enemy[nb].map.x == perso->Column + 1) && (D_Enemy[nb].map.y == perso->Line))
	{
		droit = 1;
	}
	else
	{
		droit = 0;
	}
	//à gauche
	if ((D_Enemy[nb].map.x == perso->Column - 1) && (D_Enemy[nb].map.y == perso->Line))
	{
		gauche = 1;
	}
	else
	{
		gauche = 0;
	}
	//en haut
	if ((D_Enemy[nb].map.x == perso->Column) && (D_Enemy[nb].map.y == perso->Line - 1))
	{
		haut = 1;
	}
	else
	{
		haut = 0;
	}
	//en bas
	if ((D_Enemy[nb].map.x == perso->Column) && (D_Enemy[nb].map.y == perso->Line + 1))
	{
		bas = 1;
	}
	else
	{
		bas = 0;
	}

	if (droit == 1 || gauche == 1 || haut == 1 || bas == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//Choisi le joueur le plus proche (A FAIRE : Choisir aussi en fonction du nombre de PV)
D_Personnage *ChoosePlayer(D_Perso *personnage, D_MapPath* MapPath, D_Enemy *_Enemy, int nb)
{
	D_Personnage *TempPlayer;
	//TempPlayer = &personnage->player[0];
	int Dist = 1000;//GetDistancePF(_Enemy[nb].map.x, _Enemy[nb].map.y, personnage->player[0].Column, personnage->player[0].Line, 0, MapPath);
	int Number = 0;
	int tempdistance = 0;

	for (int i = 0; i < 4; i++)
	{
		tempdistance = GetDistancePF(_Enemy[nb].map.x, _Enemy[nb].map.y, personnage->player[i].Column, personnage->player[i].Line, 0, MapPath);

		if (Dist > tempdistance)
		{
			Dist = tempdistance;
			Number = i;
		}

	}
	//printf("chooose = %d\n",  GetDistancePF(_Enemy[nb].map.x, _Enemy[nb].map.y, personnage->player[Number].Column, personnage->player[Number].Line, 0, MapPath));
	TempPlayer = &personnage->player[Number];

	return TempPlayer;
}

void ResearchPlayer(D_Personnage *perso, D_Enemy *D_Enemy, int nb)
{
	//Look Where is the player and set if a move is possible for go on her (if nobody is on)
	if (perso->Column > D_Enemy[nb].map.x)
	{
		D_Enemy[nb].Move[DownRight] = 1;
	}
	else if (perso->Column < D_Enemy[nb].map.x)
	{
		D_Enemy[nb].Move[UpLeft] = 1;
	}
	if (perso->Line > D_Enemy[nb].map.y)
	{
		D_Enemy[nb].Move[DownLeft] = 1;
	}
	else if (perso->Line < D_Enemy[nb].map.y)
	{
		D_Enemy[nb].Move[UpRight] = 1;
	}

	if (perso->Line < D_Enemy[nb].map.y)
	{
		D_Enemy[nb].Move[UpRight] = 1;
	}
	//If Ennemy beside Player, Ennemy Don't Move, no move possible
	if (BesidePlayer(perso, D_Enemy, nb))
	{
		for (int i = 0; i < POSSIBLE_MOVE; i++)
		{
			D_Enemy[nb].Move[i] = 0;
			D_Enemy[nb].Stat.PM = 0;
			//If he can move but he has an attack available so he attack else he do nogthing
			if (D_Enemy[nb].Stat.PA > 0)
			{
				D_Enemy[nb].action = hit;
			}
			else
			{
				D_Enemy[nb].action = nothing;
			}
		}
	}
}

//Position l'enemi à une nouvelle position
void NewPos(D_Map2D **map, D_Enemy *D_Enemy, int nb, int _X, int _Y)
{
	D_Enemy[nb].map.x = _X;
	D_Enemy[nb].map.y = _Y;

	D_Enemy[nb].pos.x = map[D_Enemy[nb].map.y][D_Enemy[nb].map.x].Pos.x;
	D_Enemy[nb].pos.y = map[D_Enemy[nb].map.y][D_Enemy[nb].map.x].Pos.y;
}

//Déplace l'enemi jusqu'au joueur
void MoveEnemy(D_Personnage *perso, D_Perso* personnage, D_Map2D **map, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb)
{
	//If a direction is available then he gonna in this direction
	if (D_Enemy[nb].action == move && D_Enemy[nb].Stat.PM > 0)
	{
		if (D_Enemy[nb].pause >= D_Enemy[nb].pauseMax)
		{
			D_Filling tempFilling = { 0,0,0 };

			sfVector2i PosPlayer = { perso->Column, perso->Line };
			tempFilling.Target = MouverEnemy;
			tempFilling.ATK = NOATK;
			tempFilling.Zone = NOZONE;
			if (M_Enemy->Data_Enemy[nb].Target != -1)
			{
				GeneralFillingAndPath(&tempFilling, MapPath, map, M_Enemy, personnage, PosPlayer, nb, 0, 0, 0); /////A FAIRE
			}
			M_Enemy->Data_Enemy[nb].Stat.Special++;
		}
	}
	D_Enemy[nb].action = hit;

}

//Fuis le joueur
void EscapePlayer(D_Personnage *perso, D_Map2D **map, D_MapCombat *MapCombat, D_Enemy *_Enemy, int nb)
{
	if (_Enemy[nb].action == escape && _Enemy[nb].Stat.PM > 0)
	{
		if (_Enemy[nb].pause >= _Enemy[nb].pauseMax)
		{
			int luckMove;
			//Choose a random direction available
			luckMove = rand() % 4;
			//Tant qu'une direction n'est pas accessible il en piochent une au harsard
			while (_Enemy[nb].Move[luckMove] != 1)
			{
				luckMove = rand() % 4;
			}
			//Si l'enemy se trouve près du joueur il fuira, et après il attaquera
			if (DistancePlayer(perso, _Enemy, nb) <= 2)
			{
				//Sécurité pour être sur que si on a pas de déplacement possible on ne fait rien
				int Move = 3;
				switch (luckMove)
				{
				case UpRight:
					//Indique la direction pour le sprite
					_Enemy[nb].dir = DownLeft;
					//Diminie les point de déplacements
					_Enemy[nb].Stat.PM--;
					//NE PAS TOUCHER (Vérifie si l'on ne sort pas de la map //Empêche le crash du jeu);
					while (perso->Line + Move >= MapCombat->Size.y)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					//Diminie la porté tant que la case n'est pas vide.
					if (MapCombat->Map2D[perso->Line + Move][perso->Column].OnOffCase2D == OFF)
					{
						Move--;
						if (Move <= 0)
						{
							//Si on a plus de marge on passe directement en mode Shoot
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					//Si la case est disponible on s'y déplace et on passe en mode shoot
					if (MapCombat->Map2D[perso->Line + Move][perso->Column].OnOffCase2D == ON)
					{
						NewPos(map, _Enemy, nb, perso->Column, perso->Line + Move);
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					else
					{
						//Sécurité
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					break;
				case UpLeft:
					_Enemy[nb].dir = DownRight;
					_Enemy[nb].Stat.PM--;
					while (perso->Column + Move >= MapCombat->Size.x)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					if (MapCombat->Map2D[perso->Line][perso->Column + Move].OnOffCase2D == OFF)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					if (MapCombat->Map2D[perso->Line][perso->Column + Move].OnOffCase2D == ON)
					{
						NewPos(map, _Enemy, nb, perso->Column + Move, perso->Line);
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					else
					{
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					break;
				case DownRight:
					_Enemy[nb].dir = UpLeft;
					_Enemy[nb].Stat.PM--;
					while (perso->Column - Move < 0)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					if (MapCombat->Map2D[perso->Line][perso->Column - Move].OnOffCase2D == OFF)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					if (MapCombat->Map2D[perso->Line][perso->Column - Move].OnOffCase2D == ON)
					{
						NewPos(map, _Enemy, nb, perso->Column - Move, perso->Line);
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					else
					{
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					break;
				case DownLeft:
					_Enemy[nb].dir = UpRight;
					_Enemy[nb].Stat.PM--;
					while (perso->Line - Move < 0)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					if (MapCombat->Map2D[perso->Line - Move][perso->Column].OnOffCase2D == OFF)
					{
						Move--;
						if (Move <= 0)
						{
							_Enemy[nb].action = shoot;
							Move = 0;
							_Enemy[nb].pause = 0;
						}
					}
					if (MapCombat->Map2D[perso->Line - Move][perso->Column].OnOffCase2D == ON)
					{
						NewPos(map, _Enemy, nb, perso->Column, perso->Line - Move);
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					else
					{
						_Enemy[nb].action = shoot;
						_Enemy[nb].pause = 0;
					}
					break;
				}
			}
			//Sinon si nous sommes hors de portés, ils restera à deux cases d'écarts du joueur
			else if (DistancePlayer(perso, _Enemy, nb) > 2)
			{
				_Enemy[nb].action = move;
			}
		}
	}
	else if (_Enemy[nb].action == escape && _Enemy[nb].Stat.PM <= 0)
	{
		_Enemy[nb].action = shoot;
	}
}

void HitPlayer(D_Personnage *perso, D_Enemy *_Enemy, int nb)
{
	//Body (Attack the player)
	if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA > 0)
	{
		if (_Enemy[nb].pause >= _Enemy[nb].pauseMax)
		{
			if (_Enemy[nb].SidePlayer == 1 && _Enemy[nb].AsAtk == 1)
			{
				_Enemy[nb].Stat.PA--;
				int Attaque = _Enemy[nb].Stat.ATK - (perso->Stat.def + perso->Stat.bonusDEF); // ATKENEMIS - (defperso + DefBonus perso) si < 0 = 0
				int RandomCritique = rand() % 100;
				if (RandomCritique <= _Enemy[nb].Stat.crit)
				{
					_Enemy[nb].Stat.inCrit = 1;
				}
				if (_Enemy[nb].Stat.inCrit == 1)
				{
					Attaque = (_Enemy[nb].Stat.ATK + _Enemy[nb].Stat.ATK / 4) - (perso->Stat.def + perso->Stat.bonusDEF); // ATKENEMIS - (defperso + DefBonus perso) si < 0 = 0
				}

				if (Attaque < 0)
				{
					Attaque = 0;
					_Enemy[nb].action = nothing;
				}
				if (_Enemy[nb].Stat.PV <= 0)
				{
					_Enemy[nb].Stat.Alive = 0;
				}
				perso->Stat.PV -= Attaque;
				_Enemy[nb].action = nothing;
				//_Enemy[nb].pause = 0;
			}
			else
			{
				_Enemy[nb].action = nothing;

				//_Enemy[nb].pause = 0;

			}
		}
		else if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA <= 0)
		{
			_Enemy[nb].action = nothing;
			//_Enemy[nb].pause = 0;
		}
	}
	else if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA <= 0)
	{
		_Enemy[nb].action = nothing;
	}
}

void KingHitPlayer(D_Perso *personnage, D_Enemy *_Enemy, int nb)
{
	//Body (Attack the player)
	if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA > 0)
	{
		if (_Enemy[nb].pause >= _Enemy[nb].pauseMax)
		{
			if (_Enemy[nb].SidePlayer == _Enemy[nb].Stat.SpecialMax && _Enemy[nb].AsAtk == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					if (i != 2)
					{
						int Attaque = (_Enemy[nb].Stat.ATK / 4) - (personnage->player[i].Stat.def + personnage->player[i].Stat.bonusDEF); // ATKENEMIS - (defperso + DefBonus perso) si < 0 = 0
						int RandomCritique = rand() % 100;
						if (RandomCritique <= _Enemy[nb].Stat.crit)
						{
							_Enemy[nb].Stat.inCrit = 1;
						}
						if (_Enemy[nb].Stat.inCrit == 1)
						{
							Attaque = (_Enemy[nb].Stat.ATK / 2) - (personnage->player[i].Stat.def + personnage->player[i].Stat.bonusDEF); // ATKENEMIS - (defperso + DefBonus perso) si < 0 = 0
						}

						if (Attaque < 0)
						{
							Attaque = 0;
						}
						if (_Enemy[nb].Stat.PV <= 0)
						{
							_Enemy[nb].Stat.Alive = 0;
						}
						personnage->player[i].Stat.PV -= Attaque;
					}
				}
				_Enemy[nb].Stat.PA--;
				_Enemy[nb].action = nothing;
			}
			else
			{
				_Enemy[nb].action = nothing;
			}
		}
		else if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA <= 0)
		{
			_Enemy[nb].action = nothing;
		}
	}
	else if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA <= 0)
	{
		_Enemy[nb].action = nothing;
	}
}

void ShootPlayer(D_Personnage *perso, D_Enemy *_Enemy, int nb)
{
	//Body (Attack the player)
	if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA > 0)
	{
		if (_Enemy[nb].pause >= _Enemy[nb].pauseMax)
		{
			if ((_Enemy[nb].SidePlayer == _Enemy[nb].Stat.SpecialMax && _Enemy[nb].AsAtk == 1))
			{
				_Enemy[nb].Stat.PA--;
				int Attaque = _Enemy[nb].Stat.ATK - (perso->Stat.def + perso->Stat.bonusDEF); // ATKENEMIS - (defperso + DefBonus perso) si < 0 = 0
				int RandomCritique = rand() % 100;
				if (RandomCritique <= _Enemy[nb].Stat.crit)
				{
					_Enemy[nb].Stat.inCrit = 1;
				}
				if (_Enemy[nb].Stat.inCrit == 1)
				{
					Attaque = (_Enemy[nb].Stat.ATK + _Enemy[nb].Stat.ATK / 4) - (perso->Stat.def + perso->Stat.bonusDEF); // ATKENEMIS - (defperso + DefBonus perso) si < 0 = 0
				}

				if (Attaque < 0)
				{
					Attaque = 0;
					_Enemy[nb].action = nothing;
				}
				if (_Enemy[nb].Stat.PV <= 0)
				{
					_Enemy[nb].Stat.Alive = 0;
				}
				perso->Stat.PV -= Attaque;
				_Enemy[nb].action = nothing;
			}
			else
			{
				_Enemy[nb].action = nothing;
			}

		}
		else if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA <= 0)
		{
			_Enemy[nb].action = nothing;
		}
	}
	else if (_Enemy[nb].action == EndAnimAtk && _Enemy[nb].Stat.PA <= 0)
	{
		_Enemy[nb].action = nothing;
	}
}

void Reset_EnemyTurn(D_Enemy *D_Enemy, int nb)
{
	D_Enemy[nb].Stat.PM = D_Enemy[nb].Stat.PMMax;
	D_Enemy[nb].Stat.PA = 1;
	D_Enemy[nb].pause = 0;
	D_Enemy[nb].Current = 0;
	D_Enemy[nb].AsAtk = 0;
	D_Enemy[nb].Animation.currentAnimation = 0;
	D_Enemy[nb].SidePlayer = 0;
	D_Enemy[nb].isStun = 0;
	D_Enemy[nb].Stat.inCrit = 0;
	if (D_Enemy[nb].Stat.Special >= D_Enemy[nb].Stat.SpecialMax)
	{
		D_Enemy[nb].Stat.Special = 0;
	}
	for (int i = 0; i < POSSIBLE_MOVE; i++)
	{
		D_Enemy[nb].Move[i] = 0;
	}
}


//Nécéssaire PARTOUT (POUR EVITER LES CRASH)!!!
void NextTurn(struct GAMEDATA *_GameData, struct TURN *turn, D_Enemy *D_Enemy, int nb, D_Perso* perso, int NBRENEMY)
{
	//Next turn
	//printf("NextTurn ");

	if (D_Enemy[nb].action == nothing)
	{
		//printf("FIN DE TOUR\n");
		//printf("NextTurn = %d\n ", D_Enemy[nb].SidePlayer);

		_GameData->enemyTurn++;
		Reset_EnemyTurn(D_Enemy, nb);
		//D_Enemy[_GameData->enemyTurn].Current = 1;
		D_Enemy[nb].TabPathSave = 0;

		if (_GameData->enemyTurn >= NBRENEMY)
		{
			_GameData->turn = character;
			_GameData->enemyTurn = 0;
			turn->turnPlayer = 1;

			for (int i = 0; i < 4; i++)
			{
				perso->player[i].Stat.PA = 6;
				perso->player[i].Stat.PM = 3;
				perso->player[i].StateDeplacement = 1;
			}
		}
	}

}

int SaveDataTabPathfindind(M_Enemy * Enemy, D_MapPath* MapPath, D_Map2D **map, D_Perso* Perso, int NbEnemy)
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


	/*for (int i = 0; i < 4; i++)
	{
	MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column = Unavailable;
	};*/
	for (int i = 0; i < Enemy->TotEnemy; i++)
	{
		if (Enemy->Data_Enemy[i].Stat.PV > 0)
		{

			if (i != NbEnemy)
			{
				//printf("NOT %d \n", i);
				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].State = Unavailable;
				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].nbr = 999;

			}
			else
			{
				//printf(" %d \n", i);

				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].State = Available;
				MapPath->MapP[Enemy->Data_Enemy[i].map.y][Enemy->Data_Enemy[i].map.x].nbr = 999;
			}
		}

	};

	for (int k = 0; k < 100; k++)
	{
		Enemy->Data_Enemy[NbEnemy].TabPath[k].x = 999;
	}

	FillingPath(Enemy->Data_Enemy[NbEnemy].map.x, Enemy->Data_Enemy[NbEnemy].map.y, 0, MapPath);
	//printf("FillingPath");

	int Distance = 999;
	int NbrSelect = 5;

	for (int i = 0; i < 4; i++)
	{

		if (Perso->player[i].Stat.PV > 0)
		{
			int countTestNoPlace = 0;

			////TEST 1
			if (Perso->player[i].Line + 1 >= MapPath->SizeMap.y)
			{
				countTestNoPlace++;
			}
			else
			{

				if (MapPath->MapP[Perso->player[i].Line + 1][Perso->player[i].Column].nbr >= 999)
				{
					countTestNoPlace++;
				}
			}

			////TEST 2
			if (Perso->player[i].Line - 1 < 0)
			{
				countTestNoPlace++;
			}
			else
			{

				if (MapPath->MapP[Perso->player[i].Line - 1][Perso->player[i].Column].nbr >= 999)
				{
					countTestNoPlace++;
				}
			}
			////TEST 3


			if (Perso->player[i].Column + 1 >= MapPath->SizeMap.x)
			{
				countTestNoPlace++;
			}
			else
			{

				if (MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column + 1].nbr >= 999)
				{
					countTestNoPlace++;
				}
			}


			////TEST 3

			if (Perso->player[i].Column - 1 < 0)
			{
				countTestNoPlace++;
			}
			else
			{

				if (MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column - 1].nbr >= 999)
				{
					countTestNoPlace++;
				}
			}


			if (Distance > MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column].nbr && countTestNoPlace != 4)
			{
				Distance = MapPath->MapP[Perso->player[i].Line][Perso->player[i].Column].nbr;
				NbrSelect = i;
			}
		}


	}
	if (NbrSelect == 5)
	{
		NbrSelect = -1;
	}
	if (NbrSelect != -1)
	{

		sfVector2i tempPosTarget = { Perso->player[NbrSelect].Column ,Perso->player[NbrSelect].Line };



		//printf("_____________________________FILLING________________________________\n");
		for (int i = 0; i < MapPath->SizeMap.y; i++)
		{
			for (int j = 0; j < MapPath->SizeMap.x; j++)
			{
				//printf("%d/", MapPath->MapP[i][j].nbr);
			}
			//printf("\n");
		}



		ComeBackEnemy(MapPath, tempPosTarget, map, Enemy, NbEnemy, Enemy->Data_Enemy[NbEnemy].Stat.PM);




		Enemy->Data_Enemy[NbEnemy].TabPath[(MapPath->MapP[Perso->player[NbrSelect].Line][Perso->player[NbrSelect].Column].nbr) - 1].x = Enemy->Data_Enemy[NbEnemy].map.x;
		Enemy->Data_Enemy[NbEnemy].TabPath[(MapPath->MapP[Perso->player[NbrSelect].Line][Perso->player[NbrSelect].Column].nbr) - 1].y = Enemy->Data_Enemy[NbEnemy].map.y;

		Enemy->Data_Enemy[NbEnemy].CurrentCaseMove = MapPath->MapP[Perso->player[NbrSelect].Line][Perso->player[NbrSelect].Column].nbr - 1;

	}


	for (int i = 0; i < 100; i++)
	{
		//printf(" _%d_ X = %d \t Y = %d \n", i, Enemy->Data_Enemy[NbEnemy].TabPath[i].x, Enemy->Data_Enemy[NbEnemy].TabPath[i].y);
	}

	///	printf("_____________________________FILLING2________________________________\n");
	for (int i = 0; i < MapPath->SizeMap.y; i++)
	{
		for (int j = 0; j < MapPath->SizeMap.x; j++)
		{
			if (Perso->player[NbrSelect].Column == j && Perso->player[NbrSelect].Line == i)
			{
				//printf("%d/", MapPath->MapP[i][j].nbr);
			}
			else
			{
				//printf("X/");

			}
			for (int k = 0; k < 100; k++)
			{
				if (Enemy->Data_Enemy[NbEnemy].TabPath[k].x == j && Enemy->Data_Enemy[NbEnemy].TabPath[k].y == i && Enemy->Data_Enemy[NbEnemy].TabPath[k].x != 0 && Enemy->Data_Enemy[NbEnemy].TabPath[k].y != 0)
				{
					//printf("%d->%d", k, Enemy->Data_Enemy[NbEnemy].TabPath[k].x);

				}

			}

		}
		//printf("\n");
	}
	return NbrSelect;
}

//Si l'ennemy peut jouer
int Valide(D_Enemy *_Enemy, int nb)
{
	if (_Enemy[nb].isStun == 1 || _Enemy[nb].Stat.PV <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
///////////////////////////////////////////////////
///----------------------INIT-----------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES FONCTION INIT


///////////////////////////////////////////////////
///----------------------UPDATE-----------------///
///////////////////////////////////////////////////


//ICI UNIQUEMENT DES FONCTION UTILISER DANS DES UPDATES

/*Berserk run to the player, he never use attack distance.
If he has %50 of pv he gonna's heal, and after he can heal if he has 20% of pv*/
void Berserk(struct GAMEDATA *_GameData, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Personnage *perso, D_Perso* personnage, D_Map2D **map, struct TURN *turn, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb, D_Perso* _perso, float dt, int NBRENEMY)
{
	if (Valide(D_Enemy, nb))
	{
		D_Enemy[nb].pause += dt;
		if (D_Enemy[nb].AsAtk == 0)
		{
			D_Enemy[nb].action = move;
			ResearchPlayer(perso, D_Enemy, nb);
			MoveEnemy(perso, personnage, map, MapCombat, MapPath, D_Enemy, M_Enemy, nb);
			if (D_Enemy[nb].action == hit)
			{
				D_Enemy[nb].SidePlayer = BesideAtkPlayer(perso, D_Enemy, nb);
			}
		}

		if (D_Enemy[nb].SidePlayer == 0 )
		{
			D_Enemy[nb].action = nothing;
		
		}
		if (D_Enemy[nb].action == EndAnimAtk && D_Enemy[nb].AsAtk == 1)
		{
			HitPlayer(perso, D_Enemy, nb);
			M_Enemy->CurrentSpellUse = 6;
			M_Enemy->spellAnimUse = 1;
			perso->SpellAnimTouch = 1;
		}

		if (D_Enemy[nb].action == nothing && D_Enemy[nb].pause >= D_Enemy[nb].pauseMax)
		{
			NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
		}
	}
	else
	{
		D_Enemy[nb].AsAtk = 0;
		D_Enemy[nb].action = nothing;
		NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
	}
}

void King(struct GAMEDATA *_GameData, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Personnage *perso, D_Perso* personnage, D_Map2D **map, struct TURN *turn, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb, D_Perso* _perso, float dt, int NBRENEMY)
{
	//printf("attaque Spéciale = %d \n", D_Enemy[nb].Stat.Special);
	if (Valide(D_Enemy, nb))
	{
		D_Enemy[nb].pause += dt;
		if (D_Enemy[nb].AsAtk == 0)
		{
			D_Enemy[nb].action = move;
			ResearchPlayer(perso, D_Enemy, nb);
			MoveEnemy(perso, personnage, map, MapCombat, MapPath, D_Enemy, M_Enemy, nb);
			if (D_Enemy[nb].action == hit)
			{
				D_Enemy[nb].SidePlayer = BesideAtkPlayer(perso, D_Enemy, nb);
				if (D_Enemy[nb].Stat.Special == D_Enemy[nb].Stat.SpecialMax)
				{
					D_Enemy[nb].SidePlayer = D_Enemy[nb].Stat.SpecialMax;
				}
			}
		}

		if (D_Enemy[nb].SidePlayer == 0)
		{
			D_Enemy[nb].action = nothing;
		}
		if (D_Enemy[nb].action == EndAnimAtk && D_Enemy[nb].AsAtk == 1 && D_Enemy[nb].SidePlayer == 1)
		{
			HitPlayer(perso, D_Enemy, nb);
		}
		else if (D_Enemy[nb].action == EndAnimAtk && D_Enemy[nb].AsAtk == 1 && D_Enemy[nb].SidePlayer == D_Enemy[nb].Stat.SpecialMax)
		{
			KingHitPlayer(personnage, D_Enemy, nb);
		}

		if (D_Enemy[nb].action == nothing && D_Enemy[nb].pause >= D_Enemy[nb].pauseMax)
		{
			NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
		}
	}
	else
	{
		D_Enemy[nb].AsAtk = 0;
		D_Enemy[nb].action = nothing;
		NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
	}
}

void Drake(struct GAMEDATA *_GameData, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Personnage *perso, D_Perso* personnage, D_Map2D **map, struct TURN *turn, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb, D_Perso* _perso, float dt, int NBRENEMY)
{
	//printf("attaque Spéciale = %d \n", D_Enemy[nb].Stat.Special);
	if (Valide(D_Enemy, nb))
	{
		D_Enemy[nb].pause += dt;
		if (D_Enemy[nb].AsAtk == 0)
		{
			D_Enemy[nb].action = move;
			ResearchPlayer(perso, D_Enemy, nb);
			MoveEnemy(perso, personnage, map, MapCombat, MapPath, D_Enemy, M_Enemy, nb);
			if (D_Enemy[nb].action == hit)
			{
				D_Enemy[nb].SidePlayer = BesideAtkPlayer(perso, D_Enemy, nb);
			}
		}

		if (D_Enemy[nb].SidePlayer == 0)
		{
			D_Enemy[nb].action = nothing;
		}
		if (D_Enemy[nb].action == EndAnimAtk && D_Enemy[nb].AsAtk == 1 && D_Enemy[nb].SidePlayer == 1)
		{
			HitPlayer(perso, D_Enemy, nb);
			M_Enemy->CurrentSpellUse = 9;
			M_Enemy->spellAnimUse = 1;
			perso->SpellAnimTouch = 1;
		}

		if (D_Enemy[nb].action == nothing && D_Enemy[nb].pause >= D_Enemy[nb].pauseMax)
		{
			NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
		}
	}
	else
	{
		D_Enemy[nb].AsAtk = 0;
		D_Enemy[nb].action = nothing;
		NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
	}
}

/*Running run away the player and attack's distance.
He gonna heal if he has 50% of pv.
If the player can attack him at distance, he gonna attack and AFTER MOVE.
If he can't run away, he gonna become a berserker*/
void Running(struct GAMEDATA *_GameData, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Personnage *perso, D_Perso* personnage, D_Map2D **map, struct TURN *turn, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb, D_Perso* _perso, float dt, int NBRENEMY)
{
	//printf("attaque Spéciale = %d \n", D_Enemy[nb].Stat.Special);
	if (Valide(D_Enemy, nb))
	{
		D_Enemy[nb].pause += dt;
		if (D_Enemy[nb].AsAtk == 0)
		{
			D_Enemy[nb].action = move;
			ResearchPlayer(perso, D_Enemy, nb);
			MoveEnemy(perso, personnage, map, MapCombat, MapPath, D_Enemy, M_Enemy, nb);
			if (D_Enemy[nb].action == hit)
			{
				D_Enemy[nb].SidePlayer = BesideAtkPlayer(perso, D_Enemy, nb);
			}
		}

		if (D_Enemy[nb].SidePlayer == 0)
		{
			D_Enemy[nb].action = nothing;
		}
		if (D_Enemy[nb].action == EndAnimAtk && D_Enemy[nb].AsAtk == 1 && D_Enemy[nb].SidePlayer == 1)
		{
			HitPlayer(perso, D_Enemy, nb);
			M_Enemy->CurrentSpellUse = 2;
			M_Enemy->spellAnimUse = 1;
			perso->SpellAnimTouch = 1;
		}

		if (D_Enemy[nb].action == nothing && D_Enemy[nb].pause >= D_Enemy[nb].pauseMax)
		{
			NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
		}
	}
	else
	{
		D_Enemy[nb].AsAtk = 0;
		D_Enemy[nb].action = nothing;
		NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
	}
}

void UpdateEnemy(struct GAMEDATA *_GameData, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Personnage *perso, D_Perso* personnage, D_Map2D **map, struct TURN *turn, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb, D_Perso* _perso, float dt, int NBRENEMY)
{
	if (D_Enemy[nb].Stat.Alive == 1 && D_Enemy[nb].Stat.PV > 0)
	{
		switch (D_Enemy[nb].I_A)
		{
		case berserk:Berserk(_GameData, MapCombat, MapPath, perso, personnage, map, turn, D_Enemy, M_Enemy, nb, _perso, dt, NBRENEMY);
			break;
		case running:Running(_GameData, MapCombat, MapPath, perso, personnage, map, turn, D_Enemy, M_Enemy, nb, _perso, dt, NBRENEMY);
			break;
		case boss:Drake(_GameData, MapCombat, MapPath, perso, personnage, map, turn, D_Enemy, M_Enemy, nb, _perso, dt, NBRENEMY);
			break;
		case hard:King(_GameData, MapCombat, MapPath, perso, personnage, map, turn, D_Enemy, M_Enemy, nb, _perso, dt, NBRENEMY);
			break;
		}
	}
	else
	{
		D_Enemy[nb].action = nothing;


		NextTurn(_GameData, turn, D_Enemy, nb, _perso, NBRENEMY);
	}
}