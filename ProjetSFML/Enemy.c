	#include "Enemy.h"

///////////////////////////////////////////////////
///----------------------UTILS------------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES PETITE FONCTION UTILITAIRE POUR SIMPLIFIER LE TRAVAIL

//Set the struct ennemy, the position x and y (in the map no float), the type of mob, the number of case he can advance, and the sprite
void INITENEMY(D_Map2D **map, D_Enemy *Enemy, int nb, int _X, int _Y, enum TYPEIA _IA)
{

	Enemy[nb].Stat.PVMax = 100;
	Enemy[nb].Stat.PV = Enemy[nb].Stat.PVMax;


	Enemy[nb].map.x = _X;
	Enemy[nb].map.y = _Y;

	Enemy[nb].pos.x = map[Enemy[nb].map.y][Enemy[nb].map.x].Pos.x;
	Enemy[nb].pos.y = map[Enemy[nb].map.y][Enemy[nb].map.x].Pos.y;

	Enemy[nb].I_A = _IA;

	Enemy[nb].nbCase = 0;

	Enemy[nb].dir = UpLeft;

	Enemy[nb].Stat.PA = 1;

	Enemy[nb].Stat.def = 5;
	Enemy[nb].Stat.ATK = 20;
	Enemy[nb].Stat.crit = 0;

	Enemy[nb].pause = 0;
	Enemy[nb].pauseMax = 0.5;// 1 + rand()%2;
	Enemy[nb].Current = 0;
	Enemy[nb].TotTabPath = 100;

	Enemy[nb].TabPath = calloc(Enemy[nb].TotTabPath, sizeof(sfVector2i));

	Enemy[nb].CurrentCaseMove = 0;
	Enemy[nb].Target = 0;

	Enemy[nb].SidePlayer = 0;
	Enemy[nb].AsAtk = 0;
	Enemy[nb].isStun = 0;
}

void InitStat(D_Enemy *Enemy, int nb, int PA, int def, int atk, int crit, int life, int _NbCase, int atkSpe)
{
	Enemy[nb].Stat.PA = PA;

	Enemy[nb].Stat.def = def;
	Enemy[nb].Stat.ATK = atk;
	Enemy[nb].Stat.crit = crit;

	Enemy[nb].Stat.PVMax = life;
	Enemy[nb].Stat.PV = Enemy[nb].Stat.PVMax;

	Enemy[nb].Stat.PMMax = _NbCase;
	Enemy[nb].Stat.PM = Enemy[nb].Stat.PMMax;

	Enemy[nb].Stat.SpecialMax = atkSpe;
	Enemy[nb].Stat.Special = 0;
}
///////////////////////////////////////////////////
///----------------------INIT-----------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES FONCTION INIT

//Initialisation Enemy
//Create Many Enemy By Level  
D_Enemy* Generate_Ennemy(D_Enemy *Data_Enemy, int nb)
{

	if (Data_Enemy == NULL)
	{
		printf("Allocation impossible \n");
		exit(0);
	}
	return Data_Enemy;
}

//NB se fait en fonction de nombre d'enemy généré dans Generate_Enemy
void LoadEnemy(D_MapCombat *map, M_Enemy *Enemy, int nb)
{
	int count = 0;


	for (int i = 0; i < map->Size.y; i++)
	{
		for (int j = 0; j < map->Size.x; j++)
		{
			for (int k = map->Size.z - 1; k >= 0; k--)
			{
				if (map->CaseMap[i][j][k].PlacementState == EnemyTypeA)
				{
					count++;
				}
				if (map->CaseMap[i][j][k].PlacementState == enemyTypeB)
				{
					count++;
				}
				if (map->CaseMap[i][j][k].PlacementState == enemyTypeC)
				{
					count++;
				}
				if (map->CaseMap[i][j][k].PlacementState == enemyTypeD)
				{
					count++;
				}
			}

		}
	}
	Enemy->TotEnemy = count;

	printf("count = %d \n", count);

	Enemy->Data_Enemy = calloc(count, sizeof(D_Enemy));




	Enemy->IA_Anime[0].ToTalMouvement = 2;
	InitAnimData(&Enemy->IA_Anime[0].Animation, Enemy->IA_Anime[0].ToTalMouvement);

	strcpy(Enemy->IA_Anime[0].Animation.AnimAndPath[0].Path, "Images/Enemy/Squelette/Idle/");
	Enemy->IA_Anime[0].Animation.AnimAndPath[0].TotalFrames = 3;
	Enemy->IA_Anime[0].Animation.AnimAndPath[0].FrameTime = 0.4;
	Enemy->IA_Anime[0].Animation.AnimAndPath[0].Loop = 1;

	strcpy(Enemy->IA_Anime[0].Animation.AnimAndPath[1].Path, "Images/Enemy/Squelette/atk/");
	Enemy->IA_Anime[0].Animation.AnimAndPath[1].TotalFrames = 7;
	Enemy->IA_Anime[0].Animation.AnimAndPath[1].FrameTime = 0.1;
	Enemy->IA_Anime[0].Animation.AnimAndPath[1].Loop = 0;

	Enemy->IA_Anime[1].ToTalMouvement = 2;
	InitAnimData(&Enemy->IA_Anime[1].Animation, Enemy->IA_Anime[1].ToTalMouvement);
	strcpy(Enemy->IA_Anime[1].Animation.AnimAndPath[0].Path, "Images/Enemy/Magma lezard/Idle/");
	Enemy->IA_Anime[1].Animation.AnimAndPath[0].TotalFrames = 3;
	Enemy->IA_Anime[1].Animation.AnimAndPath[0].FrameTime = 0.3;
	Enemy->IA_Anime[1].Animation.AnimAndPath[0].Loop = 1;

	strcpy(Enemy->IA_Anime[1].Animation.AnimAndPath[1].Path, "Images/Enemy/Magma lezard/atk/");
	Enemy->IA_Anime[1].Animation.AnimAndPath[1].TotalFrames = 5;
	Enemy->IA_Anime[1].Animation.AnimAndPath[1].FrameTime = 0.3;
	Enemy->IA_Anime[1].Animation.AnimAndPath[1].Loop = 0;

	Enemy->IA_Anime[2].ToTalMouvement = 2;
	InitAnimData(&Enemy->IA_Anime[2].Animation, Enemy->IA_Anime[2].ToTalMouvement);
	strcpy(Enemy->IA_Anime[2].Animation.AnimAndPath[0].Path, "Images/Enemy/DRUKE/idle/");
	Enemy->IA_Anime[2].Animation.AnimAndPath[0].TotalFrames = 8;
	Enemy->IA_Anime[2].Animation.AnimAndPath[0].FrameTime = 0.3;
	Enemy->IA_Anime[2].Animation.AnimAndPath[0].Loop = 1;

	strcpy(Enemy->IA_Anime[2].Animation.AnimAndPath[1].Path, "Images/Enemy/DRUKE/atk/");
	Enemy->IA_Anime[2].Animation.AnimAndPath[1].TotalFrames = 8;
	Enemy->IA_Anime[2].Animation.AnimAndPath[1].FrameTime = 0.3;
	Enemy->IA_Anime[2].Animation.AnimAndPath[1].Loop = 0;

	Enemy->IA_Anime[3].ToTalMouvement = 3;
	InitAnimData(&Enemy->IA_Anime[3].Animation, Enemy->IA_Anime[3].ToTalMouvement);
	strcpy(Enemy->IA_Anime[3].Animation.AnimAndPath[0].Path, "Images/Enemy/Boss/Idle/");
	Enemy->IA_Anime[3].Animation.AnimAndPath[0].TotalFrames = 2;
	Enemy->IA_Anime[3].Animation.AnimAndPath[0].FrameTime = 0.3;
	Enemy->IA_Anime[3].Animation.AnimAndPath[0].Loop = 1;

	strcpy(Enemy->IA_Anime[3].Animation.AnimAndPath[1].Path, "Images/Enemy/Boss/atk/");
	Enemy->IA_Anime[3].Animation.AnimAndPath[1].TotalFrames = 6;
	Enemy->IA_Anime[3].Animation.AnimAndPath[1].FrameTime = 0.3;
	Enemy->IA_Anime[3].Animation.AnimAndPath[1].Loop = 0;

	strcpy(Enemy->IA_Anime[3].Animation.AnimAndPath[2].Path, "Images/Enemy/Boss/atkspe/");
	Enemy->IA_Anime[3].Animation.AnimAndPath[2].TotalFrames = 8;
	Enemy->IA_Anime[3].Animation.AnimAndPath[2].FrameTime = 0.1;
	Enemy->IA_Anime[3].Animation.AnimAndPath[2].Loop = 0;

	count = 0;



	for (int i = 0; i < map->Size.y; i++)
	{
		for (int j = 0; j < map->Size.x; j++)
		{

			for (int k = map->Size.z - 1; k >= 0; k--)
			{


				if (map->CaseMap[i][j][k].PlacementState == EnemyTypeA)
				{

					INITENEMY(map->Map2D, Enemy->Data_Enemy, count, j, i, 0);
					InitStat(Enemy->Data_Enemy, count, 1, 5, 50, 10, 200, 3, 0);
					Enemy->Data_Enemy[count].Animation = Enemy->IA_Anime[0].Animation;
					printf(" test = 1\n");
					printf(" %d   PosX = %d ,  Posy = %d\n", count, j, i);
					Enemy->Data_Enemy[count].Stat.Alive = 1;
					Enemy->Data_Enemy[count].timerdead = 0;
					Enemy->Data_Enemy[count].deadState = 0;

					count++;

				}

				if (map->CaseMap[i][j][k].PlacementState == enemyTypeB)
				{
					printf(" test = 2\n");
					printf(" %d   PosX = %d ,  Posy = %d\n", count, j, i);


					INITENEMY(map->Map2D, Enemy->Data_Enemy, count, j, i, 1);
					InitStat(Enemy->Data_Enemy, count, 1, 2, 70, 30, 120, 4, 1);
					Enemy->Data_Enemy[count].Stat.Alive = 1;
					Enemy->Data_Enemy[count].timerdead = 0;
					Enemy->Data_Enemy[count].deadState = 0;
					Enemy->Data_Enemy[count].Animation = Enemy->IA_Anime[1].Animation;

					count++;
				}

				if (map->CaseMap[i][j][k].PlacementState == enemyTypeC)
				{
					printf(" test = 3\n");
					printf(" %d   PosX = %d ,  Posy = %d\n", count, j, i);


					INITENEMY(map->Map2D, Enemy->Data_Enemy, count, j, i, 2);
					InitStat(Enemy->Data_Enemy, count, 3, 8, 70, 40, 500, 6, 4);
					Enemy->Data_Enemy[count].Stat.Alive = 1;
					Enemy->Data_Enemy[count].timerdead = 0;
					Enemy->Data_Enemy[count].deadState = 0;					
					Enemy->Data_Enemy[count].Animation = Enemy->IA_Anime[2].Animation;

					count++;

				}

				if (map->CaseMap[i][j][k].PlacementState == enemyTypeD)
				{
					printf(" test = 3\n");
					printf(" %d   PosX = %d ,  Posy = %d\n", count, j, i);


					INITENEMY(map->Map2D, Enemy->Data_Enemy, count, j, i, 3, 4);
					InitStat(Enemy->Data_Enemy, count, 3, 10, 100, 80, 800, 3, 3);
					Enemy->Data_Enemy[count].Stat.Alive = 1;
					Enemy->Data_Enemy[count].timerdead = 0;
					Enemy->Data_Enemy[count].deadState = 0;
					Enemy->Data_Enemy[count].Animation = Enemy->IA_Anime[3].Animation;

					count++;

				}
			}
		}
	}



	printf(" 1   PosX = %d ,  Posy = %d\n", Enemy->Data_Enemy[0].map.x, Enemy->Data_Enemy[0].map.y);
	printf(" 1   PosX = %d ,  Posy = %d\n", Enemy->Data_Enemy[1].map.x, Enemy->Data_Enemy[1].map.y);

}

void LoadSpriteEnemy(A_Enemy *A_Enemy)
{
	//A_Enemy->Sprite[0] = LoadSprite("Images/Enemy/enemy.png", 1, NULL, NULL);
}

///////////////////////////////////////////////////
///----------------------UPDATE-----------------///
///////////////////////////////////////////////////


//ICI UNIQUEMENT DES FONCTION UTILISER DANS DES UPDATES




//A appeler a chaque fois que l'on rentre en combat
void Destroy_Ennemy(D_Enemy *D_Enemy)
{
	free(D_Enemy);
}

//Affichage des ennemies
void DisplayEnemy(D_Enemy *D_Enemy, int nb, A_Enemy A_Enemy, sfVector2f Camera, sfRenderWindow* window)
{

	//blitSprite(A_Enemy.Sprite[0], D_Enemy[nb].pos.x + Camera.x, D_Enemy[nb].pos.y + Camera.y, 0.f, window);

}