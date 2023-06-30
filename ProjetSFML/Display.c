#include"Display.h"





void LoadSpriteDecor(A_AllSprites * AllSprite)
{

	char temp_string[50] = { 0 };
	AllSprite->TotDecors = 70;

	AllSprite->Decors[0].Origin.x = 40;
	AllSprite->Decors[0].Origin.y = 160;

	AllSprite->Decors[1].Origin.x = 5;
	AllSprite->Decors[1].Origin.y = 232;

	AllSprite->Decors[2].Origin.x = 0;
	AllSprite->Decors[2].Origin.y = 232;

	AllSprite->Decors[3].Origin.x = 60;
	AllSprite->Decors[3].Origin.y = 200;

	AllSprite->Decors[4].Origin.x = 40;
	AllSprite->Decors[4].Origin.y = 220;

	AllSprite->Decors[5].Origin.x = -40;
	AllSprite->Decors[5].Origin.y = 0;

	AllSprite->Decors[6].Origin.x = -30;
	AllSprite->Decors[6].Origin.y = 0;

	AllSprite->Decors[7].Origin.x = -30;
	AllSprite->Decors[7].Origin.y = 0;

	AllSprite->Decors[8].Origin.x = -50;
	AllSprite->Decors[8].Origin.y = 0;

	for (int i = 9; i <= 60; i++)
	{
		AllSprite->Decors[i].Origin.x = 0;
		AllSprite->Decors[i].Origin.y = 68;
	}
	AllSprite->Decors[38].Origin.x = -75;
	AllSprite->Decors[38].Origin.y = -38;
	AllSprite->Decors[39].Origin.x = -5;
	AllSprite->Decors[39].Origin.y = -38;


	AllSprite->Decors[35].Origin.x = 60;
	AllSprite->Decors[35].Origin.y = 190;
	AllSprite->Decors[36].Origin.x = 60;
	AllSprite->Decors[36].Origin.y = 190;

	for (int i = 0; i < AllSprite->TotDecors; i++)
	{
		sprintf(temp_string, "Decors/%d.png", i);
		AllSprite->DecorsSprite[i].Sprite = LoadSprite(temp_string, 0, AllSprite->Decors[i].Origin.x, AllSprite->Decors[i].Origin.y);
	}


	InitAnimGeneral(&AllSprite->DecortsAnim[0], "Images/Combat/CaseBleuAnim/", 0.3, 1, 2);
	AllSprite->AnimMap[0].IDSprite = 75;
	AllSprite->AnimMap[0].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[0].Sprite, &AllSprite->DecortsAnim[0], 0, 0);

	InitAnimGeneral(&AllSprite->DecortsAnim[1], "Images/Combat/CaseRougeAnim/", 0.3, 1, 2);
	AllSprite->AnimMap[1].IDSprite = 75;
	AllSprite->AnimMap[1].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[1].Sprite, &AllSprite->DecortsAnim[1], 0, 0);

	////ARBRE 1
	InitAnimGeneral(&AllSprite->DecortsAnim[2], "Decors/AnimD/1/", 0.3, 1, 3);
	AllSprite->AnimMap[2].IDSprite = 1;
	AllSprite->AnimMap[2].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[2].Sprite, &AllSprite->DecortsAnim[2], 50, 232);
	////eau
	InitAnimGeneral(&AllSprite->DecortsAnim[3], "Decors/AnimD/2/", 0.8, 1, 4);
	AllSprite->AnimMap[3].IDSprite = 2;
	AllSprite->AnimMap[3].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[3].Sprite, &AllSprite->DecortsAnim[3], 0, 232);
	////herbe
	InitAnimGeneral(&AllSprite->DecortsAnim[4], "Decors/AnimD/3/", 0.8, 1, 4);
	AllSprite->AnimMap[4].IDSprite = 3;
	AllSprite->AnimMap[4].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[4].Sprite, &AllSprite->DecortsAnim[4], 0, 232);
	////ARBRE 3


	InitAnimGeneral(&AllSprite->DecortsAnim[5], "Decors/AnimD/4/", 0.8, 1, 2);
	AllSprite->AnimMap[5].IDSprite = 4;
	AllSprite->AnimMap[5].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[5].Sprite, &AllSprite->DecortsAnim[5], 40, 220);
	////ARBRE 3
	InitAnimGeneral(&AllSprite->DecortsAnim[6], "Decors/AnimD/14/", 0.8, 1, 2);
	AllSprite->AnimMap[6].IDSprite = 14;
	AllSprite->AnimMap[6].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[6].Sprite, &AllSprite->DecortsAnim[6], 0, 68);
	InitAnimGeneral(&AllSprite->DecortsAnim[7], "Decors/AnimD/15/", 0.8, 1, 2);
	AllSprite->AnimMap[7].IDSprite = 15;
	AllSprite->AnimMap[7].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[7].Sprite, &AllSprite->DecortsAnim[7], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[8], "Decors/AnimD/16/", 0.8, 1, 2);
	AllSprite->AnimMap[8].IDSprite = 16;
	AllSprite->AnimMap[8].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[8].Sprite, &AllSprite->DecortsAnim[8], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[9], "Decors/AnimD/17/", 0.8, 1, 2);
	AllSprite->AnimMap[9].IDSprite = 17;
	AllSprite->AnimMap[9].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[9].Sprite, &AllSprite->DecortsAnim[9], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[10], "Decors/AnimD/18/", 0.8, 1, 2);
	AllSprite->AnimMap[10].IDSprite = 18;
	AllSprite->AnimMap[10].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[10].Sprite, &AllSprite->DecortsAnim[10], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[11], "Decors/AnimD/19/", 0.8, 1, 2);
	AllSprite->AnimMap[11].IDSprite = 19;
	AllSprite->AnimMap[11].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[11].Sprite, &AllSprite->DecortsAnim[11], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[12], "Decors/AnimD/20/", 0.8, 1, 2);
	AllSprite->AnimMap[12].IDSprite = 20;
	AllSprite->AnimMap[12].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[12].Sprite, &AllSprite->DecortsAnim[12], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[13], "Decors/AnimD/21/", 0.8, 1, 2);
	AllSprite->AnimMap[13].IDSprite = 21;
	AllSprite->AnimMap[13].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[13].Sprite, &AllSprite->DecortsAnim[13], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[14], "Decors/AnimD/22/", 0.8, 1, 2);
	AllSprite->AnimMap[14].IDSprite = 22;
	AllSprite->AnimMap[14].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[14].Sprite, &AllSprite->DecortsAnim[14], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[15], "Decors/AnimD/23/", 0.8, 1, 2);
	AllSprite->AnimMap[15].IDSprite = 23;
	AllSprite->AnimMap[15].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[15].Sprite, &AllSprite->DecortsAnim[15], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[16], "Decors/AnimD/24/", 0.8, 1, 2);
	AllSprite->AnimMap[16].IDSprite = 24;
	AllSprite->AnimMap[16].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[16].Sprite, &AllSprite->DecortsAnim[16], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[17], "Decors/AnimD/25/", 0.8, 1, 2);
	AllSprite->AnimMap[17].IDSprite = 25;
	AllSprite->AnimMap[17].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[17].Sprite, &AllSprite->DecortsAnim[17], 0, 68);

	InitAnimGeneral(&AllSprite->DecortsAnim[18], "Decors/AnimD/26/", 0.8, 1, 3);
	AllSprite->AnimMap[18].IDSprite = 13;
	AllSprite->AnimMap[18].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[18].Sprite, &AllSprite->DecortsAnim[18], 0, 68);


	InitAnimGeneral(&AllSprite->DecortsAnim[19], "IDBLOC/BLOCEAU/", 0.3, 1, 2);
	AllSprite->AnimMap[19].IDSprite = 500;
	AllSprite->AnimMap[19].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[19].Sprite, &AllSprite->DecortsAnim[19], 0, 0);

	InitAnimGeneral(&AllSprite->DecortsAnim[20], "Decors/AnimD/48/", 0.3, 1, 14);
	AllSprite->AnimMap[20].IDSprite = 48;
	AllSprite->AnimMap[20].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->AnimMap[20].Sprite, &AllSprite->DecortsAnim[20], 0, 68);

	////SPELL
	////
	InitAnimGeneral(&AllSprite->AnimSpell[0], "Images/Spell/Choc electrique/", 0.4, 0, 4);
	AllSprite->SriteSpell[0].IDSprite = 0;
	AllSprite->SriteSpell[0].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[0].Sprite, &AllSprite->AnimSpell[0], 70, 85);

	InitAnimGeneral(&AllSprite->AnimSpell[1], "Images/Spell/DownStat/", 0.2, 0, 6);
	AllSprite->SriteSpell[1].IDSprite = 1;
	AllSprite->SriteSpell[1].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[1].Sprite, &AllSprite->AnimSpell[1], 70, 85);


	InitAnimGeneral(&AllSprite->AnimSpell[2], "Images/Spell/Explosion/", 0.2, 0, 9);
	AllSprite->SriteSpell[2].IDSprite = 2;
	AllSprite->SriteSpell[2].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[2].Sprite, &AllSprite->AnimSpell[2], 55, 60);


	InitAnimGeneral(&AllSprite->AnimSpell[3], "Images/Spell/Heal/", 0.2, 0, 4);
	AllSprite->SriteSpell[3].IDSprite = 3;
	AllSprite->SriteSpell[3].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[3].Sprite, &AllSprite->AnimSpell[3], 70, 85);


	InitAnimGeneral(&AllSprite->AnimSpell[4], "Images/Spell/UPStat/", 0.2, 0, 6);
	AllSprite->SriteSpell[4].IDSprite = 4;
	AllSprite->SriteSpell[4].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[4].Sprite, &AllSprite->AnimSpell[4], 70, 85);

	///////
	InitAnimGeneral(&AllSprite->AnimSpell[5], "Images/Spell/Charge/", 0.05, 0, 10);
	AllSprite->SriteSpell[5].IDSprite = 5;
	AllSprite->SriteSpell[5].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[5].Sprite, &AllSprite->AnimSpell[5], 70, 85);


	InitAnimGeneral(&AllSprite->AnimSpell[6], "Images/Spell/Slash/", 0.05, 0, 10);
	AllSprite->SriteSpell[6].IDSprite = 6;
	AllSprite->SriteSpell[6].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[6].Sprite, &AllSprite->AnimSpell[6], 20, 110);

	InitAnimGeneral(&AllSprite->AnimSpell[7], "Images/Spell/Profanation/", 0.2, 0, 14);
	AllSprite->SriteSpell[7].IDSprite = 7;
	AllSprite->SriteSpell[7].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[7].Sprite, &AllSprite->AnimSpell[7], 70, 85);

	InitAnimGeneral(&AllSprite->AnimSpell[8], "Images/Spell/ExploViolet/", 0.2, 0, 8);
	AllSprite->SriteSpell[8].IDSprite = 8;
	AllSprite->SriteSpell[8].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[8].Sprite, &AllSprite->AnimSpell[8], 55, 60);

	InitAnimGeneral(&AllSprite->AnimSpell[9], "Images/Spell/Explosionbleu/", 0.2, 0, 8);
	AllSprite->SriteSpell[9].IDSprite = 9;
	AllSprite->SriteSpell[9].Sprite = LoadSpriteAnimAtionGeneral(AllSprite->SriteSpell[8].Sprite, &AllSprite->AnimSpell[8], 55, 60);


}

void LoadALLSprite(D_Perso* Perso, M_Enemy * Enemy, A_AllSprites * AllSprite)
{
	if (debug == 1) { printf("___________LoadALLSprite_______\n"); }

	/////////////////////////////////////////////////////////
	//////// ------------------PERSONNAGE -----------////////
	/////////////////////////////////////////////////////////
	////WARRIOR////
	AllSprite->PersoSprite[0].Sprite = calloc(Perso->player[0].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Perso->player[0].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Perso->player[0].Animation.AnimAndPath[i].Path, AllSprite->PersoSprite[0].Sprite, i, &Perso->player[0].Animation, Perso->player[0].Animation.AnimAndPath[i].TotalFrames);
	}
	if (debug == 1) { printf("LoadALLSprite/Warrior == ok\n"); }

	////
	AllSprite->PersoSprite[1].Sprite = calloc(Perso->player[1].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Perso->player[1].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Perso->player[1].Animation.AnimAndPath[i].Path, AllSprite->PersoSprite[1].Sprite, i, &Perso->player[1].Animation, Perso->player[1].Animation.AnimAndPath[i].TotalFrames);
	}
	if (debug == 1) { printf("LoadALLSprite/Mage == ok\n"); }

	////

	AllSprite->PersoSprite[2].Sprite = calloc(Perso->player[2].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Perso->player[2].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Perso->player[2].Animation.AnimAndPath[i].Path, AllSprite->PersoSprite[2].Sprite, i, &Perso->player[2].Animation, Perso->player[2].Animation.AnimAndPath[i].TotalFrames);
	}
	if (debug == 1) { printf("LoadALLSprite/pretre == ok\n"); }

	////
	AllSprite->PersoSprite[3].Sprite = calloc(Perso->player[3].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Perso->player[3].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Perso->player[3].Animation.AnimAndPath[i].Path, AllSprite->PersoSprite[3].Sprite, i, &Perso->player[3].Animation, Perso->player[3].Animation.AnimAndPath[i].TotalFrames);
	}
	if (debug == 1) { printf("LoadALLSprite/Voleur == ok\n"); }



	/////////////////////////////////////////////////////////
	//////// ------------------ENEMY-----------------////////
	/////////////////////////////////////////////////////////


	AllSprite->EnemySprite[0].Sprite = calloc(Enemy->IA_Anime[0].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Enemy->IA_Anime[0].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Enemy->IA_Anime[0].Animation.AnimAndPath[i].Path, AllSprite->EnemySprite[0].Sprite, i, &Enemy->IA_Anime[0].Animation, Enemy->IA_Anime[0].Animation.AnimAndPath[i].TotalFrames);
	}
	if (debug == 1) { printf("LoadALLSprite/Warrior == ok\n"); }

	AllSprite->EnemySprite[1].Sprite = calloc(Enemy->IA_Anime[1].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Enemy->IA_Anime[1].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Enemy->IA_Anime[1].Animation.AnimAndPath[i].Path, AllSprite->EnemySprite[1].Sprite, i, &Enemy->IA_Anime[1].Animation, Enemy->IA_Anime[1].Animation.AnimAndPath[i].TotalFrames);
	}


	AllSprite->EnemySprite[2].Sprite = calloc(Enemy->IA_Anime[2].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Enemy->IA_Anime[2].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Enemy->IA_Anime[2].Animation.AnimAndPath[i].Path, AllSprite->EnemySprite[2].Sprite, i, &Enemy->IA_Anime[2].Animation, Enemy->IA_Anime[2].Animation.AnimAndPath[i].TotalFrames);
	}



	AllSprite->EnemySprite[3].Sprite = calloc(Enemy->IA_Anime[3].ToTalMouvement, sizeof(sfSprite* *));
	for (int i = 0; i < Enemy->IA_Anime[3].ToTalMouvement; i++)
	{
		LoadSpriteAnimAtion(Enemy->IA_Anime[3].Animation.AnimAndPath[i].Path, AllSprite->EnemySprite[3].Sprite, i, &Enemy->IA_Anime[3].Animation, Enemy->IA_Anime[3].Animation.AnimAndPath[i].TotalFrames);
	}
	//if (debug == 1) { printf("LoadALLSprite/Warrior == ok\n"); }

	/////////////////////////////////////////////////////////
	//////// ------------------Block-----------------////////
	/////////////////////////////////////////////////////////



	/////EAU////
	AllSprite->BlocSprite[0].IDSprite = 1111;
	AllSprite->BlocSprite[0].Sprite = LoadSprite("IDBLOC/1111.png", 0, 0, 0);

	AllSprite->BlocSprite[1].IDSprite = 1112;
	AllSprite->BlocSprite[1].Sprite = LoadSprite("IDBLOC/1112.png", 0, 0, 0);

	AllSprite->BlocSprite[2].IDSprite = 1113;
	AllSprite->BlocSprite[2].Sprite = LoadSprite("IDBLOC/1113.png", 0, 0, 0);




	////MUR//////

	AllSprite->BlocSprite[3].IDSprite = 1121;
	AllSprite->BlocSprite[3].Sprite = LoadSprite("IDBLOC/1121.png", 0, 0, 0);

	AllSprite->BlocSprite[4].IDSprite = 1122;
	AllSprite->BlocSprite[4].Sprite = LoadSprite("IDBLOC/1122.png", 0, 0, 0);

	AllSprite->BlocSprite[5].IDSprite = 1123;
	AllSprite->BlocSprite[5].Sprite = LoadSprite("IDBLOC/1123.png", 0, 0, 0);


	AllSprite->BlocSprite[6].IDSprite = 1124;
	AllSprite->BlocSprite[6].Sprite = LoadSprite("IDBLOC/1124.png", 0, 0, 0);

	AllSprite->BlocSprite[7].IDSprite = 1125;
	AllSprite->BlocSprite[7].Sprite = LoadSprite("IDBLOC/1125.png", 0, 0, 0);


	AllSprite->BlocSprite[8].IDSprite = 1126;
	AllSprite->BlocSprite[8].Sprite = LoadSprite("IDBLOC/1126.png", 0, 0, 0);

	AllSprite->BlocSprite[9].IDSprite = 1127;
	AllSprite->BlocSprite[9].Sprite = LoadSprite("IDBLOC/1127.png", 0, 0, 0);


	AllSprite->BlocSprite[10].IDSprite = 1128;
	AllSprite->BlocSprite[10].Sprite = LoadSprite("IDBLOC/1128.png", 0, 0, 0);


	AllSprite->BlocSprite[11].IDSprite = 1129;
	AllSprite->BlocSprite[11].Sprite = LoadSprite("IDBLOC/1129.png", 0, 0, 0);

	AllSprite->BlocSprite[12].IDSprite = 11210;
	AllSprite->BlocSprite[12].Sprite = LoadSprite("IDBLOC/11210.png", 0, 0, 0);

	AllSprite->BlocSprite[13].IDSprite = 11211;
	AllSprite->BlocSprite[13].Sprite = LoadSprite("IDBLOC/11211.png", 0, 0, 0);


	AllSprite->BlocSprite[14].IDSprite = 11212;
	AllSprite->BlocSprite[14].Sprite = LoadSprite("IDBLOC/11212.png", 0, 0, 0);


	AllSprite->BlocSprite[15].IDSprite = 11213;
	AllSprite->BlocSprite[15].Sprite = LoadSprite("IDBLOC/11213.png", 0, 0, 0);

	AllSprite->BlocSprite[16].IDSprite = 11214;
	AllSprite->BlocSprite[16].Sprite = LoadSprite("IDBLOC/11214.png", 0, 0, 0);

	AllSprite->BlocSprite[17].IDSprite = 11215;
	AllSprite->BlocSprite[17].Sprite = LoadSprite("IDBLOC/11215.png", 0, 0, 0);

	AllSprite->BlocSprite[18].IDSprite = 11216;
	AllSprite->BlocSprite[18].Sprite = LoadSprite("IDBLOC/11216.png", 0, 0, 0);

	AllSprite->BlocSprite[19].IDSprite = 11217;
	AllSprite->BlocSprite[19].Sprite = LoadSprite("IDBLOC/11217.png", 0, 0, 0);


	AllSprite->BlocSprite[20].IDSprite = 11218;
	AllSprite->BlocSprite[20].Sprite = LoadSprite("IDBLOC/11218.png", 0, 0, 0);

	AllSprite->BlocSprite[21].IDSprite = 11219;
	AllSprite->BlocSprite[21].Sprite = LoadSprite("IDBLOC/11219.png", 0, 0, 0);






	////SOL///////


	AllSprite->BlocSprite[22].IDSprite = 1131;
	AllSprite->BlocSprite[22].Sprite = LoadSprite("IDBLOC/1131.png", 0, 0, 0);

	AllSprite->BlocSprite[23].IDSprite = 1132;
	AllSprite->BlocSprite[23].Sprite = LoadSprite("IDBLOC/1132.png", 0, 0, 0);

	AllSprite->BlocSprite[24].IDSprite = 1133;
	AllSprite->BlocSprite[24].Sprite = LoadSprite("IDBLOC/1133.png", 0, 0, 0);

	AllSprite->BlocSprite[25].IDSprite = 1134;
	AllSprite->BlocSprite[25].Sprite = LoadSprite("IDBLOC/1134.png", 0, 0, 0);

	AllSprite->BlocSprite[26].IDSprite = 1135;
	AllSprite->BlocSprite[26].Sprite = LoadSprite("IDBLOC/1135.png", 0, 0, 0);

	AllSprite->BlocSprite[27].IDSprite = 1136;
	AllSprite->BlocSprite[27].Sprite = LoadSprite("IDBLOC/1136.png", 0, 0, 0);

	AllSprite->BlocSprite[28].IDSprite = 1137;
	AllSprite->BlocSprite[28].Sprite = LoadSprite("IDBLOC/1137.png", 0, 0, 0);

	AllSprite->BlocSprite[29].IDSprite = 1138;
	AllSprite->BlocSprite[29].Sprite = LoadSprite("IDBLOC/1138.png", 0, 0, 0);


	AllSprite->BlocSprite[30].IDSprite = 1139;
	AllSprite->BlocSprite[30].Sprite = LoadSprite("IDBLOC/1139.png", 0, 0, 0);



	AllSprite->BlocSprite[31].IDSprite = 11310;
	AllSprite->BlocSprite[31].Sprite = LoadSprite("IDBLOC/11310.png", 0, 0, 0);

	AllSprite->BlocSprite[32].IDSprite = 11311;
	AllSprite->BlocSprite[32].Sprite = LoadSprite("IDBLOC/11311.png", 0, 0, 0);


	AllSprite->BlocSprite[33].IDSprite = 11312;
	AllSprite->BlocSprite[33].Sprite = LoadSprite("IDBLOC/11312.png", 0, 0, 0);



	////TERRE//////

	AllSprite->BlocSprite[34].IDSprite = 1141;
	AllSprite->BlocSprite[34].Sprite = LoadSprite("IDBLOC/1141.png", 0, 0, 0);
	//BLOC DE TERRE
	AllSprite->BlocSprite[35].IDSprite = 1142;
	AllSprite->BlocSprite[35].Sprite = LoadSprite("IDBLOC/1142.png", 0, 0, 0);
	
	AllSprite->BlocSprite[36].IDSprite = 1143;
	AllSprite->BlocSprite[36].Sprite = LoadSprite("IDBLOC/1143.png", 0, 0, 0);


	AllSprite->BlocSprite[37].IDSprite = 1144;
	AllSprite->BlocSprite[37].Sprite = LoadSprite("IDBLOC/1144.png", 0, 0, 0);

	AllSprite->BlocSprite[38].IDSprite = 1145;
	AllSprite->BlocSprite[38].Sprite = LoadSprite("IDBLOC/1145.png", 0, 0, 0);

	AllSprite->BlocSprite[39].IDSprite = 1146;
	AllSprite->BlocSprite[39].Sprite = LoadSprite("IDBLOC/1146.png", 0, 0, 0);

	AllSprite->BlocSprite[40].IDSprite = 1147;
	AllSprite->BlocSprite[40].Sprite = LoadSprite("IDBLOC/1147.png", 0, 0, 0);

	AllSprite->BlocSprite[41].IDSprite = 1148;
	AllSprite->BlocSprite[41].Sprite = LoadSprite("IDBLOC/1148.png", 0, 0, 0);

















	AllSprite->ShadowMask[0] = LoadSprite("Images/Ombre/1.png", 0, 0, 0);
	AllSprite->ShadowMask[1] = LoadSprite("Images/Ombre/2.png", 0, 0, 0);
	AllSprite->ShadowMask[2] = LoadSprite("Images/Ombre/3.png", 0, 0, 0);
	AllSprite->ShadowMask[3] = LoadSprite("Images/Ombre/4.png", 0, 0, 0);
	AllSprite->ShadowMask[4] = LoadSprite("Images/Ombre/5.png", 0, 0, 0);
	AllSprite->ShadowMask[5] = LoadSprite("Images/Ombre/6.png", 0, 0, 0);
	AllSprite->ShadowMask[6] = LoadSprite("Images/Ombre/7.png", 0, 0, 0);
	AllSprite->ShadowMask[7] = LoadSprite("Images/Ombre/8.png", 0, 0, 0);
	AllSprite->ShadowMask[8] = LoadSprite("Images/Ombre/9.png", 0, 0, 0);
	AllSprite->ShadowMask[9] = LoadSprite("Images/Ombre/10.png", 0, 0, 0);
	AllSprite->ShadowMask[10] = LoadSprite("Images/Ombre/11.png", 0, 0, 0);

	AllSprite->ombresPerso = LoadSprite("Images/ombresPerso.png", 0, 0, 0);


	/////////////////////////////////////////////////////////
	//////// ------------------CaseSelect------------////////
	/////////////////////////////////////////////////////////





	AllSprite->A_CaseSelect = LoadSprite("caseSelect.png", 0, 0, 0);
	AllSprite->GreenCase = LoadSprite("caseIsoGreen.png", 0, 0, 0);
	AllSprite->RedCase = LoadSprite("caseIsoRed.png", 0, 0, 0);
	AllSprite->TrapCase = LoadSprite("caseIsoTrap.png", 0, 0, 0);
	AllSprite->orangeCase = LoadSprite("caseIsoOrange.png", 0, 0, 0);
	AllSprite->FeedBackSol = LoadSprite("feedback.png", 0, 0, 0);

	AllSprite->GameOver = LoadSprite("Images/Game over.png", 0, 0, 0);



	/////////////////////////////////////////////////////////
	//////// ------------------Decort----------------////////
	/////////////////////////////////////////////////////////

	LoadSpriteDecor(AllSprite);





}







void __DISPLAY_GENERAL__(D_MapCombat* Map, sfVector2i CurrentSelect, D_FightSystem* fightSystem, D_Perso* perso, M_Enemy * Enemy, sfVector2f Camera, A_AllSprites * AllSprite, int turn, sfRenderWindow* window)
{




	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{

			for (int k = Map->Size.z - 1; k >= 0; k--)
			{
				if (Map->CaseMap[i][j][k].Ident != 0)
				{
					for (int s = 0; s < 100; s++)
					{
						if (AllSprite->BlocSprite[s].IDSprite == Map->CaseMap[i][j][k].Ident)
						{
							if (AllSprite->BlocSprite[s].IDSprite == 1111 || AllSprite->BlocSprite[s].IDSprite == 1211)
							{

								blitSprite(AllSprite->AnimMap[19].Sprite[AllSprite->DecortsAnim[19].CurrentFrame], Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, (Map->CaseMap[i][j][k].VectorPos[0].y), 0, window);

							}
							else
							{
								blitSprite(AllSprite->BlocSprite[s].Sprite, Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);

							}
							for (int c = 0; c < Enemy->TotEnemy; c++)////////////////ENEMY
							{
								if (Enemy->Data_Enemy[c].map.x == j && Enemy->Data_Enemy[c].map.y == i && Enemy->Data_Enemy[c].Stat.PV > 0)
								{
									blitSprite(AllSprite->ombresPerso, Enemy->Data_Enemy[c].pos.x + Camera.x - 66, Enemy->Data_Enemy[c].pos.y + Camera.y, 0, window);
								}

							}
							for (int c = 0; c < 4; c++)//////////////PLAYER
							{

								if (perso->player[c].Column == j && perso->player[c].Line == i && perso->player[c].Stat.PV > 0)
								{
									blitSprite(AllSprite->ombresPerso, (perso->player[c].x) + Camera.x - 66, (perso->player[c].y) + Camera.y, 0, window);

								}
							}
						}

					}
					//printf("BLOCKD\n");
				}


				for (int o = 0; o < 11; o++)
				{
					if (o == Map->CaseMap[i][j][k].IDShadow)
					{
						blitSprite(AllSprite->ShadowMask[o], Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);

					}




				}

				if (Map->StateSTF != NullSTF)/////////////////////////COLORISATION CONTOUR CASE
				{
					if (Map->Map2D[i][j].isColored == 2)
					{

						//printf("BLITZ");
						switch (Map->StateSTF)
						{

						case 1:blitSprite(AllSprite->GreenCase, Map->Map2D[i][j].Pos.x + Camera.x - 64, Map->Map2D[i][j].Pos.y + Camera.y, 0, window); break;
						case 2:blitSprite(AllSprite->RedCase, Map->Map2D[i][j].Pos.x + Camera.x - 64, Map->Map2D[i][j].Pos.y + Camera.y, 0, window); break;

						default:
							break;
						}
					}
					//printf("STATESTF\n");


				}
				if (Map->Map2D[i][j].isColored == 3)
				{
					if (perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].type == 4 || perso->player[fightSystem->turn.turnPlayer - 1].spell[fightSystem->CurrentSelectSpell].type == 3)
					{
						blitSprite(AllSprite->orangeCase, Map->Map2D[i][j].Pos.x + Camera.x - 64, Map->Map2D[i][j].Pos.y + Camera.y, 0, window);
						//printf("ORANGE");
					}
					//printf("COLORED3\n");

				}

				//printf("COLOR = %d\n", Map->Map2D[CurrentSelect.y][CurrentSelect.x].isColored);
				if (Map->Map2D[i][j].isColored == 4)
				{

					blitSprite(AllSprite->orangeCase, Map->Map2D[i][j].Pos.x + Camera.x - 64, Map->Map2D[i][j].Pos.y + Camera.y, 0, window);

					//blitSprite(AllSprite->orangeCase, Map->Map2D[CurrentSelect.y][CurrentSelect.x].Pos.x + Camera.x - 64, Map->Map2D[CurrentSelect.y][CurrentSelect.x].Pos.y + Camera.y, 0, window);

					//printf("ORANGE");

				}
				if (CurrentSelect.x == j && CurrentSelect.y == i && Map->CaseMap[i][j][k].ValidCase == ValidCase)///////////////CASE SELECT GRISE
				{
					//blitSprite(AllSprite->A_CaseSelect, Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);

				}
				if (Map->CaseMap[i][j][k].ValidCase == ValidCase && Map->CaseMap[i][j][k].Ident != 0)/////////////AFFICHAGE DES VECTEUR
				{
					for (int v = 0; v < 4; v++)
					{

						//VectorDraw(Map->CaseMap[i][j][k].VectorPos[v], Map->CaseMap[i][j][k].VectorPos[v + 1], sfRed, window);

					}
				}
				if (Map->Map2D[i][j].trap == 1)
				{
					blitSprite(AllSprite->TrapCase, Map->Map2D[i][j].Pos.x + Camera.x - 64, Map->Map2D[i][j].Pos.y + Camera.y, 0, window);
					//printf("STATECASE5\n");

				}
				if (Map->CaseMap[i][j][k].ValidCase == ValidCase)
				{


					if (perso->player[turn - 1].Line == i && perso->player[turn - 1].Column == j && turn - 1 < 4)
					{
						blitSprite(AllSprite->AnimMap[0].Sprite[AllSprite->DecortsAnim[0].CurrentFrame], Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y - Map->CellSize.y + 64, 0, window);
						//blitSprite(AllSprite->AnimMap[2].Sprite[AllSprite->DecortsAnim[2].CurrentFrame], Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);
						//printf("lol\n");

					}

				}

				if (Map->CaseMap[i][j][k].IDDecorts != 999)
				{



					if (Map->CaseMap[i][j][k].IDDecorts == 1 || Map->CaseMap[i][j][k].IDDecorts == 2 || Map->CaseMap[i][j][k].IDDecorts == 3  || Map->CaseMap[i][j][k].IDDecorts == 4 || (Map->CaseMap[i][j][k].IDDecorts >= 13 && Map->CaseMap[i][j][k].IDDecorts <= 25) && Map->CaseMap[i][j][k].IDDecorts != 21 || Map->CaseMap[i][j][k].IDDecorts == 48)
					{
						
						for (int d = 0; d < 21; d++)
						{


							if (AllSprite->AnimMap[d].IDSprite == Map->CaseMap[i][j][k].IDDecorts )
							{
								
								blitSprite(AllSprite->AnimMap[d].Sprite[AllSprite->DecortsAnim[d].CurrentFrame], Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);

							}

						}
						//printf("DECORT\n");


					}
					else
					{
						blitSprite(AllSprite->DecorsSprite[Map->CaseMap[i][j][k].IDDecorts].Sprite, Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);
						//printf("DECORT3\n");
					}


					if (Map->CaseMap[i][j][k].IDDecorts == 48)
					{
						blitSprite(AllSprite->AnimMap[20].Sprite[AllSprite->DecortsAnim[20].CurrentFrame], Map->CaseMap[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->CaseMap[i][j][k].VectorPos[0].y, 0, window);

					}
				}
			}



			for (int c = 0; c < 4; c++)//////////////PLAYER
			{

				if (debug == 1) { printf("__DISPLAY_GENERAL__/perso %d inCheck\n", c); }

				if (perso->player[c].Stat.PV > 0)
				{

					if (perso->player[c].Line == i && perso->player[c].Column == j)
					{
						blitSprite(AllSprite->PersoSprite[c].Sprite[perso->player[c].Animation.currentAnimation][perso->player[c].Animation.CurrentFrame], (perso->player[c].x) + Camera.x, (perso->player[c].y) + Camera.y, 0, window);
						//printf("PLAYER1\n");

					}

					if (perso->player[c].SpellAnimTouch == 1 && fightSystem->spellAnimUse == 1)
					{
						blitSprite(AllSprite->SriteSpell[fightSystem->CurrentSpellUse].Sprite[AllSprite->AnimSpell[fightSystem->CurrentSpellUse].CurrentFrame], (perso->player[c].x) + Camera.x, (perso->player[c].y) + Camera.y, 0, window);
						//printf("PLAYER2\n");
					}

					if (Enemy->spellAnimUse == 1 && perso->player[c].SpellAnimTouch == 1)
					{
						blitSprite(AllSprite->SriteSpell[Enemy->CurrentSpellUse].Sprite[AllSprite->AnimSpell[Enemy->CurrentSpellUse].CurrentFrame], (perso->player[c].x) + Camera.x, (perso->player[c].y) + Camera.y, 0, window);

					}
				}
				char tempCharnb[20];
					sprintf(tempCharnb, "%d", (perso->player[c].Stat.isSelected) );
					displayTexte(tempCharnb, AllSprite->textDisplay, (perso->player[c].x) + Camera.x, (perso->player[c].y) + Camera.y- 20 - 70, window, sfBlue, 20);
			}
			//printf("TOT ENEMY = %d ", Enemy->TotEnemy);


			for (int c = 0; c < Enemy->TotEnemy; c++)////////////////ENEMY
			{




				//printf("ENEMY = %d\n",c);
				if (Enemy->Data_Enemy[c].Stat.Alive == 1)
				{

					//char tempCharnb[20];
					//sprintf(tempCharnb, "%d", Enemy->Data_Enemy[c].isStun);
					//displayTexte(tempCharnb, AllSprite->textDisplay, Enemy->Data_Enemy[c].pos.x + Camera.x, Enemy->Data_Enemy[c].pos.y + Camera.y - 20 - 70, window, sfBlue, 20);


					if (debug == 1) { printf("__DISPLAY_GENERAL__/Enemy %d inCheck\n", c); }

					if (Enemy->Data_Enemy[c].map.y == i && Enemy->Data_Enemy[c].map.x == j)
					{
						if (Enemy->Data_Enemy[c].deadState == 1 && ((Enemy->Data_Enemy[c].timerdead > 0.1 && Enemy->Data_Enemy[c].timerdead < 0.5) || (Enemy->Data_Enemy[c].timerdead > 1 && Enemy->Data_Enemy[c].timerdead < 1.5)))////colorisation enemy en rouge
						{
							sfColor TempColor = { 255,100,100,255 };
							sfSprite_setColor(AllSprite->EnemySprite[Enemy->Data_Enemy[c].I_A].Sprite[Enemy->Data_Enemy[c].Animation.currentAnimation][Enemy->Data_Enemy[c].Animation.CurrentFrame], TempColor);
						}
						else
						{
							sfColor TempColor = { 255,255,255,255 };
							sfSprite_setColor(AllSprite->EnemySprite[Enemy->Data_Enemy[c].I_A].Sprite[Enemy->Data_Enemy[c].Animation.currentAnimation][Enemy->Data_Enemy[c].Animation.CurrentFrame], TempColor);
						}

						if (Enemy->Data_Enemy[c].isStun)
						{
							sfColor TempColor = { 0,255,255,255 };
							sfSprite_setColor(AllSprite->EnemySprite[Enemy->Data_Enemy[c].I_A].Sprite[Enemy->Data_Enemy[c].Animation.currentAnimation][Enemy->Data_Enemy[c].Animation.CurrentFrame], TempColor);
						}
						//printf("AIMATION\n");

						if (Enemy->Data_Enemy[c].I_A != 3)
						{
							blitSprite(AllSprite->EnemySprite[Enemy->Data_Enemy[c].I_A].Sprite[Enemy->Data_Enemy[c].Animation.currentAnimation][Enemy->Data_Enemy[c].Animation.CurrentFrame], Enemy->Data_Enemy[c].pos.x + Camera.x, Enemy->Data_Enemy[c].pos.y + Camera.y, 0.f, window);

						}
						else
						{
							blitSprite(AllSprite->EnemySprite[Enemy->Data_Enemy[c].I_A].Sprite[Enemy->Data_Enemy[c].Animation.currentAnimation][Enemy->Data_Enemy[c].Animation.CurrentFrame], Enemy->Data_Enemy[c].pos.x + Camera.x - 30, Enemy->Data_Enemy[c].pos.y + Camera.y - 30, 0.f, window);

						}

						if (Enemy->Data_Enemy[c].SpellAnimTouch == 1 && fightSystem->spellAnimUse == 1)
						{
							//printf("AIMATIONSPELL\n");
							blitSprite(AllSprite->SriteSpell[fightSystem->CurrentSpellUse].Sprite[AllSprite->AnimSpell[fightSystem->CurrentSpellUse].CurrentFrame], Enemy->Data_Enemy[c].pos.x + Camera.x, Enemy->Data_Enemy[c].pos.y + Camera.y, 0, window);
							//system("pause");

						}
						//printf("DEGAT\n");
						char tempChar[20];


						sprintf(tempChar, "%d", Enemy->Data_Enemy[c].Stat.PV);

						if (Enemy->Data_Enemy[c].deadState == 1)////colorisation enemy en rouge
						{
							int decal = (Enemy->Data_Enemy[c].timerdead * 70);
							displayTexte(AllSprite->PrintDamage.Name, AllSprite->textDisplay, Enemy->Data_Enemy[c].pos.x + Camera.x, Enemy->Data_Enemy[c].pos.y + Camera.y - 20 - decal, window, sfRed, 20);
						}

					}
				}

			}
		}
	}
}