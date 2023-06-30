#include "Perso.h"



///////////////////////////////////////////////////
///----------------------UTILS------------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES PETITE FONCTION UTILITAIRE POUR SIMPLIFIER LE TRAVAIL


///////////////////////////////////////////////////
///----------------------INIT-----------------///
///////////////////////////////////////////////////



//ICI UNIQUEMENT DES FONCTION INIT
void InitWarrior(D_Perso* perso, int column, int line, D_Map2D **map)
{
	////INIT DATA ANIM
	perso->player[0].ToTalMouvement = 5;
	InitAnimData(&perso->player[0].Animation, perso->player[0].ToTalMouvement);
	strcpy(perso->player[0].Animation.AnimAndPath[0].Path, "Images/perso/Guerrier/Idle/");
	perso->player[0].Animation.AnimAndPath[0].TotalFrames = 4;
	perso->player[0].Animation.AnimAndPath[0].FrameTime = 0.1;
	perso->player[0].Animation.AnimAndPath[0].Loop = 1;

	strcpy(perso->player[0].Animation.AnimAndPath[1].Path, "Images/perso/Guerrier/Spell1/");
	perso->player[0].Animation.AnimAndPath[1].TotalFrames = 6;
	perso->player[0].Animation.AnimAndPath[1].FrameTime = 0.1;
	perso->player[0].Animation.AnimAndPath[1].Loop = 0;
	strcpy(perso->player[0].Animation.AnimAndPath[2].Path, "Images/perso/Guerrier/Spell2/");
	perso->player[0].Animation.AnimAndPath[2].TotalFrames = 6;
	perso->player[0].Animation.AnimAndPath[2].FrameTime = 0.1;
	perso->player[0].Animation.AnimAndPath[2].Loop = 0;
	strcpy(perso->player[0].Animation.AnimAndPath[3].Path, "Images/perso/Guerrier/Spell3/");
	perso->player[0].Animation.AnimAndPath[3].TotalFrames = 6;
	perso->player[0].Animation.AnimAndPath[3].FrameTime = 0.1;
	perso->player[0].Animation.AnimAndPath[3].Loop = 0;
	strcpy(perso->player[0].Animation.AnimAndPath[4].Path, "Images/perso/Guerrier/Spell4/");
	perso->player[0].Animation.AnimAndPath[4].TotalFrames = 6;
	perso->player[0].Animation.AnimAndPath[4].FrameTime = 0.1;
	perso->player[0].Animation.AnimAndPath[4].Loop = 0;
	////INIT DATA PERSO

	perso->player[0].Column = column;
	perso->player[0].Line = line;
	perso->player[0].x = map[perso->player[0].Line][perso->player[0].Column].Pos.x;
	perso->player[0].y = map[perso->player[0].Line][perso->player[0].Column].Pos.y;

	perso->player[0].Stat.def = 5;
}
void InitMage(D_Perso* perso, int column, int line, D_Map2D **map)
{

	////INIT DATA ANIM

	perso->player[1].ToTalMouvement = 5;
	InitAnimData(&perso->player[1].Animation, perso->player[1].ToTalMouvement);
	strcpy(perso->player[1].Animation.AnimAndPath[0].Path, "Images/perso/MageNoir/Idle/");
	perso->player[1].Animation.AnimAndPath[0].TotalFrames = 5;
	perso->player[1].Animation.AnimAndPath[0].FrameTime = 0.2;
	perso->player[1].Animation.AnimAndPath[0].Loop = 1;
	strcpy(perso->player[1].Animation.AnimAndPath[1].Path, "Images/perso/MageNoir/Spell1/");
	perso->player[1].Animation.AnimAndPath[1].TotalFrames = 6;
	perso->player[1].Animation.AnimAndPath[1].FrameTime = 0.2;
	perso->player[1].Animation.AnimAndPath[1].Loop = 0;
	strcpy(perso->player[1].Animation.AnimAndPath[2].Path, "Images/perso/MageNoir/Spell2/");
	perso->player[1].Animation.AnimAndPath[2].TotalFrames = 6;
	perso->player[1].Animation.AnimAndPath[2].FrameTime = 0.2;
	perso->player[1].Animation.AnimAndPath[2].Loop = 0;
	strcpy(perso->player[1].Animation.AnimAndPath[3].Path, "Images/perso/MageNoir/Spell3/");
	perso->player[1].Animation.AnimAndPath[3].TotalFrames = 6;
	perso->player[1].Animation.AnimAndPath[3].FrameTime = 0.2;
	perso->player[1].Animation.AnimAndPath[3].Loop = 0;
	strcpy(perso->player[1].Animation.AnimAndPath[4].Path, "Images/perso/MageNoir/Spell4/");
	perso->player[1].Animation.AnimAndPath[4].TotalFrames = 6;
	perso->player[1].Animation.AnimAndPath[4].FrameTime = 0.2;
	perso->player[1].Animation.AnimAndPath[4].Loop = 0;

	////INIT DATA PERSO
	perso->player[1].Column = column;
	perso->player[1].Line = line;

	perso->player[1].x = map[perso->player[1].Line][perso->player[1].Column].Pos.x;
	perso->player[1].y = map[perso->player[1].Line][perso->player[1].Column].Pos.y;

	perso->player[1].Stat.def = 1;
}
void InitPretre(D_Perso* perso, int column, int line, D_Map2D **map)
{

	////INIT DATA ANIM

	perso->player[2].ToTalMouvement = 5;
	InitAnimData(&perso->player[2].Animation, perso->player[2].ToTalMouvement);
	strcpy(perso->player[2].Animation.AnimAndPath[0].Path, "Images/perso/Pretre/Idle/");
	perso->player[2].Animation.AnimAndPath[0].TotalFrames = 7;
	perso->player[2].Animation.AnimAndPath[0].FrameTime = 0.2;
	perso->player[2].Animation.AnimAndPath[0].Loop = 1;
	strcpy(perso->player[2].Animation.AnimAndPath[1].Path, "Images/perso/Pretre/Spell1/");
	perso->player[2].Animation.AnimAndPath[1].TotalFrames = 7;
	perso->player[2].Animation.AnimAndPath[1].FrameTime = 0.2;
	perso->player[2].Animation.AnimAndPath[1].Loop = 0;
	strcpy(perso->player[2].Animation.AnimAndPath[2].Path, "Images/perso/Pretre/Spell2/");
	perso->player[2].Animation.AnimAndPath[2].TotalFrames = 7;
	perso->player[2].Animation.AnimAndPath[2].FrameTime = 0.2;
	perso->player[2].Animation.AnimAndPath[2].Loop = 0;
	strcpy(perso->player[2].Animation.AnimAndPath[3].Path, "Images/perso/Pretre/Spell3/");
	perso->player[2].Animation.AnimAndPath[3].TotalFrames = 7;
	perso->player[2].Animation.AnimAndPath[3].FrameTime = 0.2;
	perso->player[2].Animation.AnimAndPath[3].Loop = 0;
	strcpy(perso->player[2].Animation.AnimAndPath[4].Path, "Images/perso/Pretre/Spell4/");
	perso->player[2].Animation.AnimAndPath[4].TotalFrames = 7;
	perso->player[2].Animation.AnimAndPath[4].FrameTime = 0.2;
	perso->player[2].Animation.AnimAndPath[4].Loop = 0;
	////INIT DATA PERSO

	perso->player[2].Column = column;
	perso->player[2].Line = line;

	perso->player[2].x = map[perso->player[2].Line][perso->player[2].Column].Pos.x;
	perso->player[2].y = map[perso->player[2].Line][perso->player[2].Column].Pos.y;

	perso->player[2].Stat.def = 3;
}
void InitVoleur(D_Perso* perso, int column, int line, D_Map2D **map)
{
	////INIT DATA ANIM

	perso->player[3].ToTalMouvement = 5;
	InitAnimData(&perso->player[3].Animation, perso->player[3].ToTalMouvement);
	strcpy(perso->player[3].Animation.AnimAndPath[0].Path, "Images/perso/Voleuse/Idle/");
	perso->player[3].Animation.AnimAndPath[0].TotalFrames = 8;
	perso->player[3].Animation.AnimAndPath[0].FrameTime = 0.2;
	perso->player[3].Animation.AnimAndPath[0].Loop = 1;
	strcpy(perso->player[3].Animation.AnimAndPath[1].Path, "Images/perso/Voleuse/Spell1/");
	perso->player[3].Animation.AnimAndPath[1].TotalFrames = 4;
	perso->player[3].Animation.AnimAndPath[1].FrameTime = 0.1;
	perso->player[3].Animation.AnimAndPath[1].Loop = 0;
	strcpy(perso->player[3].Animation.AnimAndPath[2].Path, "Images/perso/Voleuse/Spell2/");
	perso->player[3].Animation.AnimAndPath[2].TotalFrames = 4;
	perso->player[3].Animation.AnimAndPath[2].FrameTime = 0.1;
	perso->player[3].Animation.AnimAndPath[2].Loop = 0;
	strcpy(perso->player[3].Animation.AnimAndPath[3].Path, "Images/perso/Voleuse/Spell3/");
	perso->player[3].Animation.AnimAndPath[3].TotalFrames = 4;
	perso->player[3].Animation.AnimAndPath[3].FrameTime = 0.1;
	perso->player[3].Animation.AnimAndPath[3].Loop = 0;
	strcpy(perso->player[3].Animation.AnimAndPath[4].Path, "Images/perso/Voleuse/Spell4/");
	perso->player[3].Animation.AnimAndPath[4].TotalFrames = 4;
	perso->player[3].Animation.AnimAndPath[4].FrameTime = 0.1;
	perso->player[3].Animation.AnimAndPath[4].Loop = 0;

	////INIT DATA PERSO

	perso->player[3].Column = column;
	perso->player[3].Line = line;

	perso->player[3].x = map[perso->player[3].Line][perso->player[3].Column].Pos.x;
	perso->player[3].y = map[perso->player[3].Line][perso->player[3].Column].Pos.y;

	perso->player[3].Stat.def = 3;
}
void InitPlayer(D_Perso* perso, D_MapCombat *map)
{
	for (int i = 0; i < NBPERSO; i++)
	{
		perso->player[i].Stat.PA = 6;
		perso->player[i].Stat.PM = 3;
		perso->player[i].Stat.PVMax = 100;
		perso->player[i].Stat.PV = 100;
		perso->player[i].Stat.crit = 50;
		perso->player[i].Stat.inCrit = 0;
		perso->player[i].StateDeplacement = 1;
		perso->player[i].Stat.Alive = 1;
		perso->player[i].Stat.isSelected = 0;
	}

	//Warrior Spell Init
	perso->player[0].spell[0].po = 1;
	perso->player[0].spell[0].dammage = 50;
	perso->player[0].spell[0].inUse = 0;
	perso->player[0].spell[0].CostPa = 3;
	perso->player[0].spell[0].buff = 0;
	perso->player[0].spell[0].debuff = 0;
	perso->player[0].spell[0].duration = 0;
	perso->player[0].spell[0].type = 1;

	perso->player[0].spell[1].po = 1;
	perso->player[0].spell[1].dammage = 0;
	perso->player[0].spell[1].inUse = 0;
	perso->player[0].spell[1].CostPa = 2;
	perso->player[0].spell[1].buff = 5;
	perso->player[0].spell[1].debuff = 0;
	perso->player[0].spell[1].duration = 3;
	perso->player[0].spell[1].type = 3;

	perso->player[0].spell[2].po = 3;
	perso->player[0].spell[2].duration = 3;
	perso->player[0].spell[2].inUse = 0;
	perso->player[0].spell[2].CostPa = 3;
	perso->player[0].spell[2].debuff = 10;
	perso->player[0].spell[2].buff = 0;
	perso->player[0].spell[2].dammage = 40;
	perso->player[0].spell[2].type = 2;

	perso->player[0].spell[3].po = 1;
	perso->player[0].spell[3].buff = 0;
	perso->player[0].spell[3].inUse = 0;
	perso->player[0].spell[3].CostPa = 3;
	perso->player[0].spell[3].duration = 1;
	perso->player[0].spell[3].dammage = 20;
	perso->player[0].spell[3].debuff = 0;
	perso->player[0].spell[3].type = 1;

	//Mage Spell Init 
	perso->player[1].spell[0].po = 3;
	perso->player[1].spell[0].dammage = 0;
	perso->player[1].spell[0].inUse = 0;
	perso->player[1].spell[0].CostPa = 2;
	perso->player[1].spell[0].buff = 0;
	perso->player[1].spell[0].debuff = 0;
	perso->player[1].spell[0].duration = 0;
	perso->player[1].spell[0].type = 2;

	perso->player[1].spell[1].po = 4;
	perso->player[1].spell[1].dammage = 30;
	perso->player[1].spell[1].inUse = 0;
	perso->player[1].spell[1].CostPa = 2;
	perso->player[1].spell[1].buff = 0;
	perso->player[1].spell[1].debuff = 0;
	perso->player[1].spell[1].duration = 0;
	perso->player[1].spell[1].type = 1;

	perso->player[1].spell[2].po = 3;
	perso->player[1].spell[2].dammage = 50;
	perso->player[1].spell[2].inUse = 0;
	perso->player[1].spell[2].CostPa = 4;
	perso->player[1].spell[2].buff = 0;
	perso->player[1].spell[2].debuff = 0;
	perso->player[1].spell[2].duration = 0;
	perso->player[1].spell[2].type = 3;

	perso->player[1].spell[3].po = 3;
	perso->player[1].spell[3].buff = 0;
	perso->player[1].spell[3].inUse = 0;
	perso->player[1].spell[3].CostPa = 4;
	perso->player[1].spell[3].debuff = 0;
	perso->player[1].spell[3].duration = 3;
	perso->player[1].spell[3].dammage = 65;
	perso->player[1].spell[3].type = 2;

	//Pretre Spell Init
	perso->player[2].spell[0].po = 2;
	perso->player[2].spell[0].dammage = 0;
	perso->player[2].spell[0].inUse = 0;
	perso->player[2].spell[0].CostPa = 2;
	perso->player[2].spell[0].buff = 0;
	perso->player[2].spell[0].debuff = 10;
	perso->player[2].spell[0].duration = 2;
	perso->player[2].spell[0].type = 1;

	//Pas de duration car c'est un heal flat 
	perso->player[2].spell[1].po = 3;
	perso->player[2].spell[1].buff = 25;
	perso->player[2].spell[1].inUse = 0;
	perso->player[2].spell[1].CostPa = 3;
	perso->player[2].spell[1].duration = 0;
	perso->player[2].spell[1].dammage = 0;
	perso->player[2].spell[1].debuff = 0;
	perso->player[2].spell[1].type = 1;

	perso->player[2].spell[2].po = 2;
	perso->player[2].spell[2].buff = 0;
	perso->player[2].spell[2].inUse = 0;
	perso->player[2].spell[2].CostPa = 0;
	perso->player[2].spell[2].duration = 0;
	perso->player[2].spell[2].dammage = 0;
	perso->player[2].spell[2].debuff = 0;
	perso->player[2].spell[2].type = 1;

	perso->player[2].spell[3].po = 2;
	perso->player[2].spell[3].buff = 1;
	perso->player[2].spell[3].inUse = 0;
	perso->player[2].spell[3].CostPa = 3;
	perso->player[2].spell[3].duration = 3;
	perso->player[2].spell[3].debuff = 0;
	perso->player[2].spell[3].dammage = 0;
	perso->player[2].spell[3].type = 3;

	//Voleur Spell Init 
	perso->player[3].spell[0].po = 3;
	perso->player[3].spell[0].dammage = 20;
	perso->player[3].spell[0].inUse = 0;
	perso->player[3].spell[0].CostPa = 3;
	perso->player[3].spell[0].buff = 0;
	perso->player[3].spell[0].debuff = 0;
	perso->player[3].spell[0].duration = 0;
	perso->player[3].spell[0].type = 2;

	perso->player[3].spell[1].po = 2;
	perso->player[3].spell[1].dammage = 0;
	perso->player[3].spell[1].inUse = 0;
	perso->player[3].spell[1].CostPa = 2;
	perso->player[3].spell[1].buff = 15;
	perso->player[3].spell[1].debuff = 0;
	perso->player[3].spell[1].duration = 2;
	perso->player[3].spell[1].type = 3;

	perso->player[3].spell[2].po = 1;
	perso->player[3].spell[2].buff = 0;
	perso->player[3].spell[2].duration = 0;
	perso->player[3].spell[2].inUse = 0;
	perso->player[3].spell[2].CostPa = 6;
	perso->player[3].spell[2].debuff = 0;
	perso->player[3].spell[2].dammage = 100;
	perso->player[3].spell[2].type = 1;

	perso->player[3].spell[3].po = 1;
	perso->player[3].spell[3].buff = 0;
	perso->player[3].spell[3].inUse = 0;
	perso->player[3].spell[3].CostPa = 4;
	perso->player[3].spell[3].duration = 0;
	perso->player[3].spell[3].debuff = 0;
	perso->player[3].spell[3].dammage = 75;
	perso->player[3].spell[3].type = 1;


	for (int i = 0; i < map->Size.y; i++)
	{
		for (int j = 0; j < map->Size.x; j++)
		{

			for (int k = map->Size.z - 1; k >= 0; k--)
			{
				if (map->CaseMap[i][j][k].PlacementState == 1)
				{
					printf("LOAD");
					InitWarrior(perso, j, i, map->Map2D);

				}
				if (map->CaseMap[i][j][k].PlacementState == 2)
				{
					InitMage(perso, j, i, map->Map2D);

				}
				if (map->CaseMap[i][j][k].PlacementState == 3)
				{
					InitPretre(perso, j, i, map->Map2D);

				}
				if (map->CaseMap[i][j][k].PlacementState == 4)
				{
					InitVoleur(perso, j, i, map->Map2D);
				}

			}
		}
	}
}
///////////////////////////////////////////////////
///----------------------EVENT-----------------///
///////////////////////////////////////////////////


///////////////////////////////////////////////////
///----------------------UPDATE-----------------///
///////////////////////////////////////////////////



void DisplayPlayer(D_Perso* perso,sfVector2f Camera, sfRenderWindow* window)
{
	for (int i = 0; i < 4; i++)
	{

	blitSprite(perso->spritePersonnage[i].Sprites[perso->player[i].Animation.currentAnimation][perso->player[i].Animation.CurrentFrame], (perso->player[i].x)+ Camera.x, (perso->player[i].y) + Camera.y, 0, window);
	}
}
//ICI UNIQUEMENT DES FONCTION UTILISER DANS DES UPDATES

