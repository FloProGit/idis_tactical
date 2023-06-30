#include"MapCombat.h"
#include <stdio.h>
#include "windows.h"




void INITMapCombat(D_MapCombat * Map, D_Str* _saveName)
{

	Map->CellSize.x = 128;
	Map->CellSize.y = 64;

	Put_Data_On_MapCombat(Map, _saveName);
}

void Put_Data_On_MapCombat(D_MapCombat * Map, D_Str* _saveName)
{
	FILE* file = fopen(_saveName->Name, "r");
	if (file == NULL)
	{
		printf("PAS DE FICHIER SAUVEGARDE\n");
	}
	fscanf(file, "%d", &Map->Size.y);
	fscanf(file, "%d", &Map->Size.x);
	fscanf(file, "%d", &Map->Size.z);


	

	Create_Empty_MapCombat_From_Data_Lvl(Map);

	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			

			for (int k = Map->Size.z - 1; k >= 0; k--)
			{
				fscanf(file, "%d", &Map->CaseMap[i][j][k].Ident);
				fscanf(file, "%d ", &Map->CaseMap[i][j][k].ValidCase);
				fscanf(file, "%d ", &Map->CaseMap[i][j][k].IDShadow);
				fscanf(file, "%d ", &Map->CaseMap[i][j][k].OpacityShadow);
				fscanf(file, "%d ", &Map->CaseMap[i][j][k].IDDecorts);
				fscanf(file, "%d ", &Map->CaseMap[i][j][k].PlacementState);


			}
		
		}
	

	}
	fclose(file);

	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			int first = 0;
			for (int k = 0; k < Map->Size.z; k++)
			{

				if (first == 0)
				{
					if (Map->CaseMap[i][j][k].Ident != 0 )
					{
						first = 1;
						//Map->CaseMap[i][j][valide].ValidCase = InvalidCase;
						Map->CaseMap[i][j][k].ValidCase++;

					}
					
				}
			

			}
		
		}
	}




}

void LoadBackgroundsSprite(D_MapCombat* map)
{
	map->background.YbackGround = LoadSprite("Images/combat/Bback.png", 0, 0, 0);
	map->background.Yclouds = LoadSprite("Images/combat/Bclouds.png", 0, 0, 0);
	map->background.RbackGround = LoadSprite("Images/combat/Bback.png", 0, 0, 0);
	map->background.Rclouds = LoadSprite("Images/combat/Bclouds.png", 0, 0, 0);
	map->background.BbackGround = LoadSprite("Images/combat/Bback.png", 0, 0, 0);
	map->background.Bclouds = LoadSprite("Images/combat/Bclouds.png", 0, 0, 0);
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
	{
		map->background.backGround = map->background.BbackGround;
		map->background.clouds = map->background.Bclouds;
	}
	else if (random == 1)
	{
		map->background.backGround = map->background.RbackGround;
		map->background.clouds = map->background.Rclouds;
	}
	else if (random == 2)
	{
		map->background.backGround = map->background.YbackGround;
		map->background.clouds = map->background.Yclouds;
	};
	map->background.speed = 20;
	map->background.pos1.x = 0;
	map->background.pos1.y = 0;
	map->background.pos2.x = 1920;
	map->background.pos1.y = 0;
}


void Create_Empty_MapCombat_From_Data_Lvl(D_MapCombat* Map)
{
	Map->CaseMap = 0;
	Map->CaseMap = calloc(Map->Size.y, sizeof(D_Bloc**));

	for (int i = 0; i < Map->Size.y; i++)
	{
		Map->CaseMap[i] = calloc(Map->Size.x, sizeof(D_Bloc*));
		for (int j = 0; j < Map->Size.x; j++)
		{
			Map->CaseMap[i][j] = calloc(Map->Size.z, sizeof(D_Bloc));
		}
	}
}
void Createmap2d(D_MapCombat* Map)
{
	printf("2MAP = %d \n ", Map);
	Map->Map2D = calloc(Map->Size.y, sizeof(D_Map2D*));

	for (int i = 0; i < Map->Size.y; i++)
	{
		Map->Map2D[i] = calloc(Map->Size.x, sizeof(D_Map2D));
	}


}


void ConvertMapto2DMap(D_MapCombat* Map,sfVector2f Camera)
{

	//printf("1MAP = %d \n ", Map->Size.z);

	Createmap2d(Map);


	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			Map->Map2D[i][j].OnOffCase2D = OFF;
			Map->Map2D[i][j].StateCase = NullC2d;
			for (int k = 0; k < Map->Size.z; k++)
			{

				if (Map->CaseMap[i][j][k].ValidCase == ValidCase)
				{
					Map->Map2D[i][j].Pos.x = Map->CaseMap[i][j][k].VectorPos[0].x - Camera.x;
					Map->Map2D[i][j].Pos.y = Map->CaseMap[i][j][k].VectorPos[0].y - Camera.y;

					Map->Map2D[i][j].StateCase = ValidC2d;
					Map->Map2D[i][j].OnOffCase2D = ON;
					Map->Map2D[i][j].trap = 0;
					Map->Map2D[i][j].useForSpell = 0;
				}
				
			}
			
		}
	}



}
void VectorCase(D_MapCombat* Map, sfVector2f Camera)
{
	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			for (int k = 0; k < Map->Size.z; k++)
			{

				Map->CaseMap[i][j][k].VectorPos[0].x = (Map->CellSize.x / 2) + Map->CellSize.x / 2 * (j - i) + Camera.x;

				Map->CaseMap[i][j][k].VectorPos[0].y = (Map->CellSize.y / 2 * (j + i)) + (Map->CellSize.y / 2 * k) + Camera.y;


				Map->CaseMap[i][j][k].VectorPos[1].x = Map->CaseMap[i][j][k].VectorPos[0].x + Map->CellSize.x / 2;
				Map->CaseMap[i][j][k].VectorPos[1].y = Map->CaseMap[i][j][k].VectorPos[0].y + Map->CellSize.y / 2;

				Map->CaseMap[i][j][k].VectorPos[2].x = Map->CaseMap[i][j][k].VectorPos[0].x;
				Map->CaseMap[i][j][k].VectorPos[2].y = Map->CaseMap[i][j][k].VectorPos[0].y + Map->CellSize.y;

				Map->CaseMap[i][j][k].VectorPos[3].x = Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2;
				Map->CaseMap[i][j][k].VectorPos[3].y = Map->CaseMap[i][j][k].VectorPos[0].y + Map->CellSize.y / 2;

				Map->CaseMap[i][j][k].VectorPos[4].x = Map->CaseMap[i][j][k].VectorPos[0].x;
				Map->CaseMap[i][j][k].VectorPos[4].y = Map->CaseMap[i][j][k].VectorPos[0].y;

			}
		}
	}
}


void CurrentCaseSelect(D_MapCombat* Map, sfVector2i Mouse, sfVector2i * caseSelect)
{

	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{

			for (int k = Map->Size.z; k >= 0; k--)
			{

				
				if (Map->CaseMap[i][j][k].ValidCase == ValidCase)
				{
					if (CalculScalaire(Mouse, &Map->CaseMap[i][j][k]))
					{
						caseSelect->y = i;
						caseSelect->x = j;
					}
				}
			}
		}
	}

}



int CalculScalaire(sfVector2i Mouse, D_Bloc * _case)
{
	int total = 0;
	for (int k = 0; k < TOTVECTORCASE - 1; k++)
	{
		sfVector2f temp1 = { -(_case->VectorPos[k + 1].y - _case->VectorPos[k].y)  , _case->VectorPos[k + 1].x - _case->VectorPos[k].x };


		sfVector2f temp2 = { Mouse.x - _case->VectorPos[k].x, Mouse.y - _case->VectorPos[k].y };

		int result;
		result = (temp2.x*temp1.x) + (temp2.y*temp1.y);

		if (result >= 0)
		{
			total++;
		}

	}
	if (total == TOTVECTORCASE - 1)
	{
		return 1;
	}

	return 0;
}
void BackgroundUpdate(D_MapCombat* Map, float dt)
{
	Map->background.pos1.x += Map->background.speed*dt;
	if (Map->background.pos1.x >= 1920)
	{
		Map->background.pos1.x = -1920;
	};
	Map->background.pos2.x += Map->background.speed*dt;
	if (Map->background.pos2.x >= 1920)
	{
		Map->background.pos2.x = -1920;
	};
};
void BackgroundDisplay(D_MapCombat* Map, sfRenderWindow* window)
{
	blitSprite(Map->background.backGround, 0, 0, 0, window);
	blitSprite(Map->background.clouds, Map->background.pos1.x, Map->background.pos1.y, 0, window);
	blitSprite(Map->background.clouds, Map->background.pos2.x, Map->background.pos2.y, 0, window);
};