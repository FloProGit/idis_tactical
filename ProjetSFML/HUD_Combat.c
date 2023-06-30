#include "HUD_Combat.h"



///////////////////////////////////////////////////
///----------------------UTILS------------------///
///////////////////////////////////////////////////

//ICI UNIQUEMENT DES PETITE FONCTION UTILITAIRE POUR SIMPLIFIER LE TRAVAIL


///////////////////////////////////////////////////
///----------------------INIT-----------------///
///////////////////////////////////////////////////
void initSpellsDescription(D_HudCombat * hud)
{
	///GUERRIER
	//Sort 1
	strcpy(hud->spellNames[0][0], "Coup d'épée");
	strcpy(hud->spellDescription[0][0], "Un coup d'épée \nrapide et précis");
	strcpy(hud->spellArea[0][0], "");
	strcpy(hud->spellPO[0][0], "Portée : 1 Case");
	strcpy(hud->spellCost[0][0], "Cout : 3 PA");
	strcpy(hud->spellDamage[0][0], "Dommages : 25");
	//Sort 2
	strcpy(hud->spellNames[0][1], "Protection \nhéroïque");
	strcpy(hud->spellDescription[0][1], "Augmente la défense \nde tout les alliés \nprésents dans la zone");
	strcpy(hud->spellArea[0][1], "Zone d'effet : Croix \nde 2 cases");
	strcpy(hud->spellPO[0][1], "Portée : Soi-même");
	strcpy(hud->spellCost[0][1], "Cout : 3 PA");
	strcpy(hud->spellDamage[0][1], "+10 de défense");
	//Sort 3
	strcpy(hud->spellNames[0][2], "Chaines de \nl'inquisiteur");
	strcpy(hud->spellDescription[0][2], "Attrape un ennemi,\nlui reduit \n sa défense et\nl'attire jusqu'au \nGuerrier");
	strcpy(hud->spellArea[0][2], "");
	strcpy(hud->spellPO[0][2], "Portée : 3 Cases \nen ligne");
	strcpy(hud->spellCost[0][2], "Cout : 6 PA");
	strcpy(hud->spellDamage[0][2], "-10 de défense");
	//Sort 4
	strcpy(hud->spellNames[0][3], "KoudeBoul");
	strcpy(hud->spellDescription[0][3], "Inflige des \ndégats a la cible \net l'étourdit\npendant 1 tour");
	strcpy(hud->spellArea[0][3], "");
	strcpy(hud->spellPO[0][3], "Portée : 1 Case");
	strcpy(hud->spellCost[0][3], "Cout : 3 PA");
	strcpy(hud->spellDamage[0][3], "Dommages : 15");
	///MAGE NOIR
	//Sort 1
	strcpy(hud->spellNames[1][0], "Souvenir \nFuneste");
	strcpy(hud->spellDescription[1][0], "Fait reculer \nla cible d'une case");
	strcpy(hud->spellArea[1][0], "");
	strcpy(hud->spellPO[1][0], "Portée : 3 Cases en \nligne");
	strcpy(hud->spellCost[1][0], "Cout : 2 PA");
	strcpy(hud->spellDamage[1][0], "Dommages : 0");
	//Sort 2
	strcpy(hud->spellNames[1][1], "Blasphème");
	strcpy(hud->spellDescription[1][1], "Inflige des petits \ndommages a longue \nportée");
	strcpy(hud->spellArea[1][1], "");
	strcpy(hud->spellPO[1][1], "Portée : Cercle de \n3 cases");
	strcpy(hud->spellCost[1][1], "Cout : 2 PA");
	strcpy(hud->spellDamage[1][1], "Dommages : 15");
	//Sort 3
	strcpy(hud->spellNames[1][3], "Profanation");
	strcpy(hud->spellDescription[1][3], "Inflige de gros dégats \nen ligne");
	strcpy(hud->spellArea[1][3], "");
	strcpy(hud->spellPO[1][3], "Portée : 3 Cases en \nligne");
	strcpy(hud->spellCost[1][3], "Cout : 4 PA");
	strcpy(hud->spellDamage[1][3], "Dommages : 65");
	//Sort 4
	strcpy(hud->spellNames[1][2], "Messe Noire");
	strcpy(hud->spellDescription[1][2], "Inflige des dégats \ndévastateurs a un \ngroupe d'ennemis");
	strcpy(hud->spellArea[1][2], "Zone d'effet : Cercle \nde 2 cases");
	strcpy(hud->spellPO[1][2], "Portée : 3 Cases en \nligne");
	strcpy(hud->spellCost[1][2], "Cout : 4 PA");
	strcpy(hud->spellDamage[1][2], "Dommages : 50");
	///PRETRE 
	//Sort 1
	strcpy(hud->spellNames[2][0], "Prière de \nFaiblesse");
	strcpy(hud->spellDescription[2][0], "Réduit l'attaque \nde la cible");
	strcpy(hud->spellArea[2][0], "");
	strcpy(hud->spellPO[2][0], "Portée : Cercle de \n2 cases");
	strcpy(hud->spellCost[2][0], "Cout : 2 PA");
	strcpy(hud->spellDamage[2][0], "-10 d'attaque");

	//Sort 2
	strcpy(hud->spellNames[2][1], "Toucher \nAngélique");
	strcpy(hud->spellDescription[2][1], "Soigne modérément \nla cible");
	strcpy(hud->spellArea[2][1], "");
	strcpy(hud->spellPO[2][1], "Portée : Cercle de \n2 cases");
	strcpy(hud->spellCost[2][1], "Cout : 3 PA");
	strcpy(hud->spellDamage[2][1], "+20 PV");
	//Sort 3
	strcpy(hud->spellNames[2][3], "Marche \nMiraculeuse");
	strcpy(hud->spellDescription[2][3], "Augmente la portée du \nprochain déplacement \nde la cible");
	strcpy(hud->spellArea[2][3], "");
	strcpy(hud->spellPO[2][3], "Portée : Cercle de \n2 cases");
	strcpy(hud->spellCost[2][3], "Cout : 3 PA");
	strcpy(hud->spellDamage[2][3], "Déplacement +1");
	//Sort 4
	strcpy(hud->spellNames[2][2], "Messe \nBlanche");
	strcpy(hud->spellDescription[2][2], "Sort de zone \nqui regroupe \nles ennemis touchés");
	strcpy(hud->spellArea[2][2], "Zone d'effet : \nCroix de 3 cases");
	strcpy(hud->spellPO[2][2], "Portée : 3 cases en \nligne");
	strcpy(hud->spellCost[2][2], "Cout : 3 PA");
	strcpy(hud->spellDamage[2][2], "Regroupe les ennemis");
	///VOLEUSE
	//Sort 1
	strcpy(hud->spellNames[3][0], "Lancer de \ndagues");
	strcpy(hud->spellDescription[3][0], "Lance une dague \nqui inflige des \ndommages a distance");
	strcpy(hud->spellArea[3][0], "");
	strcpy(hud->spellPO[3][0], "Portée : 3 cases en \nligne");
	strcpy(hud->spellCost[3][0], "Cout : 3 PA");
	strcpy(hud->spellDamage[3][0], "Dommages : 20");
	//Sort 2
	strcpy(hud->spellNames[3][1], "Soif de Sang");
	strcpy(hud->spellDescription[3][1], "Augmente l'attaque \nde tout les alliés \nprésents dans la zone ");
	strcpy(hud->spellArea[3][1], "Zone d'effet : \nCroix de 1 case");
	strcpy(hud->spellPO[3][1], "Portée : Croix de \n 3 cases");
	strcpy(hud->spellCost[3][1], "Cout : 3 PA");
	strcpy(hud->spellDamage[3][1], "+ 15 d'attaque");
	//Sort 3
	strcpy(hud->spellNames[3][3], "Coup de \nJarnac");
	strcpy(hud->spellDescription[3][3], "Un coup habile, décisif, \nmais inattendu.\nUn coup donné \npar traîtrise");
	strcpy(hud->spellArea[3][3], "");
	strcpy(hud->spellPO[3][3], "Portée : 1 case");
	strcpy(hud->spellCost[3][3], "Cout : 4 PA");
	strcpy(hud->spellDamage[3][3], "Dommages : 75");
	//Sort 4
	strcpy(hud->spellNames[3][2], "Attrape\nNigaud");
	strcpy(hud->spellDescription[3][2], "Pose un piège \nqui blesse les ennemis\n qui marchent dessus");
	strcpy(hud->spellArea[3][2], "");
	strcpy(hud->spellPO[3][2], "Portée : cercle de \n2 cases");
	strcpy(hud->spellCost[3][2], "Cout : 3 PA");
	strcpy(hud->spellDamage[3][2], "Si contact avec le piège :\n100 Dommages");
};
//ICI UNIQUEMENT DES FONCTION INIT
void InitHud(D_SpellHud* _SpellHud, A_FightHud* AllSprite, D_HudCombat* hud)
{
	hud->cursorSpeed = 10;
	//Warrior spell
	AllSprite->changeTurn = LoadSprite("Images/Combat/HUD/changeTurn.png", 0, 0, 0);
	AllSprite->moove = LoadSprite("Images/Combat/HUD/moove.png", 0, 0, 0);

	AllSprite->HudSpellSprite[0][0][0] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill1/Skill1Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[0][0][1] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill1/Skill1HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[0][1][0] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill2/Skill2Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[0][1][1] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill2/Skill2HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[0][2][0] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill3/Skill3Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[0][2][1] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill3/Skill3HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[0][3][0] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill4/Skill4Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[0][3][1] = LoadSprite("Images/Combat/HUD/warriorSpell/Skill4/Skill4HudOn.png", 0, 0, 0);

	//Mage spell
	AllSprite->HudSpellSprite[1][0][0] = LoadSprite("Images/Combat/HUD/mageSpell/Skill1/Skill1Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[1][0][1] = LoadSprite("Images/Combat/HUD/mageSpell/Skill1/Skill1HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[1][1][0] = LoadSprite("Images/Combat/HUD/mageSpell/Skill2/Skill2Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[1][1][1] = LoadSprite("Images/Combat/HUD/mageSpell/Skill2/Skill2HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[1][3][0] = LoadSprite("Images/Combat/HUD/mageSpell/Skill3/Skill3Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[1][3][1] = LoadSprite("Images/Combat/HUD/mageSpell/Skill3/Skill3HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[1][2][0] = LoadSprite("Images/Combat/HUD/mageSpell/Skill4/Skill4Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[1][2][1] = LoadSprite("Images/Combat/HUD/mageSpell/Skill4/Skill4HudOn.png", 0, 0, 0);

	//Pretre spell
	AllSprite->HudSpellSprite[2][0][0] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill1/Skill1Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[2][0][1] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill1/Skill1HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[2][1][0] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill2/Skill2Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[2][1][1] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill2/Skill2HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[2][3][0] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill3/Skill3Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[2][3][1] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill3/Skill3HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[2][2][0] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill4/Skill4Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[2][2][1] = LoadSprite("Images/Combat/HUD/pretreSpell/Skill4/Skill4HudOn.png", 0, 0, 0);

	//Voleuse spell

	AllSprite->HudSpellSprite[3][0][0] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill1/Skill1Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[3][0][1] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill1/Skill1HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[3][1][0] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill2/Skill2Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[3][1][1] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill2/Skill2HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[3][3][0] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill3/Skill3Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[3][3][1] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill3/Skill3HudOn.png", 0, 0, 0);

	AllSprite->HudSpellSprite[3][2][0] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill4/Skill4Hud.png", 0, 0, 0);
	AllSprite->HudSpellSprite[3][2][1] = LoadSprite("Images/Combat/HUD/voleuseSpell/Skill4/Skill4HudOn.png", 0, 0, 0);
	/////// Sprite GENERAUX de LHUD
	initSpellsDescription(hud);
	////////////Bloc en dessous de l'écran avec les spells et le perso qui joue 
	AllSprite->HudPlayers = LoadSprite("Images/Combat/HUD/HudBattle.png", 0, 0, 0); // 
	AllSprite->displayWindow = LoadSprite("Images/Combat/HUD/window.png", 0, 0, 0);
	hud->Hud.x = 411;
	hud->Hud.y = 875;
	////Init des portraits
	hud->PortraitIsPlaying.x = 638;
	hud->PortraitIsPlaying.y = 930;
	////////////////////Portraits affichés en haut de la map avec un récap des barres de vies
	hud->Portraits.y = 0;
	hud->Portraits.x = 30;
	hud->Portraits.HudWidth = 112;
	hud->infoWindow.y = 236;
	hud->infoWindow.x = 1537;
	hud->infoWindowIsDisplaying = FALSE;
	for (int i = 0; i < 4; i++)
	{
		char nom[70];
		sprintf(nom, "Images/Combat/HUD/portraits/%d.png", i);
		AllSprite->portraits[i] = LoadSprite(nom, 0, 0, 0);
	};
	//Init des barres de vies 
	AllSprite->emptyHealth = LoadSprite("Images/Combat/HUD/emptyHealth.png", 0, 0, 0);
	AllSprite->emptyHealthEnemy = LoadSprite("Images/Combat/HUD/emptyHealthEnnemy.png", 0, 0, 0);
	AllSprite->healthGauge = LoadSprite("Images/Combat/HUD/health.png", 0, 0, 0);
	AllSprite->healthGauge2 = LoadSprite("Images/Combat/HUD/health2.png", 0, 0, 0);
	AllSprite->HudRedSquare = LoadSprite("Images/Combat/HUD/RedSquare.png", 0, 0, 0);
	AllSprite->alliedCursor = LoadSprite("Images/Combat/HUD/curseurV4.PNG", 0, 0, 0);

	AllSprite->Spell1InUse = LoadSprite("Images/Combat/HUD/Spell1Use.PNG", 0, 0, 0);
	AllSprite->Spell2InUse = LoadSprite("Images/Combat/HUD/Spell2Use.PNG", 0, 0, 0);
	AllSprite->Spell3InUse = LoadSprite("Images/Combat/HUD/Spell3Use.PNG", 0, 0, 0);
	AllSprite->Spell4InUse = LoadSprite("Images/Combat/HUD/Spell4Use.PNG", 0, 0, 0);

	hud->isDisplayingEnemyLife = FALSE;
	hud->enemyDisplaying = -1;
	//Init des couleurs des personnages 
	sfColor tempCoul = { 70, 85, 132, 255 };
	hud->colorPerso[0] = tempCoul;
	sfColor tempCoul2 = { 124, 24, 192, 255 };
	hud->colorPerso[1] = tempCoul2;
	sfColor tempCoul3 = { 53, 100, 55, 255 };
	hud->colorPerso[2] = tempCoul3;
	sfColor tempCoul4 = { 146, 81, 50, 255 };
	hud->colorPerso[3] = tempCoul4;
	int decal = 121;
	for (int i = 0; i < 4; i++)
	{
		_SpellHud[i].HudHeight = 66;
		_SpellHud[i].HudWidth = 66;
		_SpellHud[i].x = 819 + (i*decal);
		_SpellHud[i].y = 978;
	}
	hud->decYcursor = 0;
	hud->passTurn.x = 430;
	hud->passTurn.y = hud->Hud.y + 30;
	hud->passTurn.HudHeight = 42;
	hud->passTurn.HudWidth = 190;

	hud->useMoove.x = 430;
	hud->useMoove.y = hud->Hud.y + 120;
	hud->useMoove.HudHeight = 42;
	hud->useMoove.HudWidth = 190;
}
void initTexte(D_HudCombat * _Stats)
{
	_Stats->fontStats.font = sfFont_createFromFile("IMG/INVENTORY/FONT/PixelIntv.otf");
	_Stats->fontStats.text = sfText_create();
	sfText_setFont(_Stats->fontStats.text, _Stats->fontStats.font);
	sfText_setCharacterSize(_Stats->fontStats.text, 20);
};

///////////////////////////////////////////////////
///----------------------EVENT-----------------///
///////////////////////////////////////////////////
int collisionFact(sfVector2i mouse, int _objX, int _objY, int _SizeX, int _SizeY)
{
	if (mouse.x > _objX && mouse.x <_objX + _SizeX && mouse.y > _objY && mouse.y < _objY + _SizeY)
	{
		return 1;
	}

	return 0;
}

void ChangeTurn(DataSystem* DT, D_FightSystem* fightSystem, D_HudCombat* hud, E_StateSTF *STATE)
{
	//Passe ton tour

	if (collisionFact(DT->Mouse, hud->passTurn.x, hud->passTurn.y, hud->passTurn.HudWidth, hud->passTurn.HudHeight))
	{
		fightSystem->turn.turnPlayer = 5;
		*STATE = NullSTF;
	}
}

void ClickMoove(DataSystem* DT, D_FightSystem* fightSystem, D_HudCombat* hud, D_Perso* perso)
{
	//Passe en mode deplacement le joueur 
	if (perso->player[fightSystem->turn.turnPlayer - 1].StateDeplacement == 1)
	{

		if (collisionFact(DT->Mouse, hud->useMoove.x, hud->useMoove.y, hud->useMoove.HudWidth, hud->useMoove.HudHeight))
		{
			if (perso->player[fightSystem->turn.turnPlayer - 1].mooveMode == 1)
			{
				perso->player[fightSystem->turn.turnPlayer - 1].mooveMode = 0;

			}
			else
			{
				perso->player[fightSystem->turn.turnPlayer - 1].mooveMode = 1;
				perso->player[fightSystem->turn.turnPlayer - 1].attackMode = 0;
			}
		}
	}

}

void ClickHud(D_SpellHud* _SpellHud, DataSystem* DT, D_FightSystem* fightSystem, D_Perso* perso)
{
	for (int i = 0; i < 4; i++)
	{

		if (collisionFact(DT->Mouse, _SpellHud[i].x, _SpellHud[i].y, _SpellHud[i].HudWidth, _SpellHud[i].HudHeight))
		{
			if (perso->player[fightSystem->turn.turnPlayer - 1].spell[i].inUse == 1)
			{
				for (int j = 0; j < 4; j++)
				{
					perso->player[fightSystem->turn.turnPlayer - 1].spell[j].inUse = 0;
					perso->player[fightSystem->turn.turnPlayer - 1].attackMode = 0;
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					perso->player[fightSystem->turn.turnPlayer - 1].spell[j].inUse = 0;
					perso->player[fightSystem->turn.turnPlayer - 1].attackMode = 0;
				}
				perso->player[fightSystem->turn.turnPlayer - 1].spell[i].inUse = 1;
				perso->player[fightSystem->turn.turnPlayer - 1].attackMode = 1;
				fightSystem->CurrentSelectSpell = i;
			}
			perso->player[fightSystem->turn.turnPlayer - 1].mooveMode = 0;
		}
	}
}



	///////////////////////////////////////////////////
	///----------------------UPDATE-----------------///
	///////////////////////////////////////////////////

	void updateLifeGaugeEnemy(D_HudCombat* hud, sfVector2i CaseSelect, M_Enemy* Enemy)
	{
		int count = 0;
		for (int i = 0; i < Enemy->TotEnemy; i++)
		{

			if (Enemy->Data_Enemy[i].Stat.Alive == 1)
			{
				if (CaseSelect.x == Enemy->Data_Enemy[i].map.x && CaseSelect.y == Enemy->Data_Enemy[i].map.y)
				{
					hud->isDisplayingEnemyLife = TRUE;
					hud->enemyDisplaying = i;
					count++;
				}
			}

		}
		if (count == 0)
		{
			hud->isDisplayingEnemyLife = FALSE;
		}

	};
	void updateDisplayWindow(D_HudCombat* hud, D_FightSystem* fightSystem, D_Perso* perso, int _MousePosX, int _MousePosY)
	{
		hud->Portraits.y = 23;
		hud->Portraits.x = 35;
		int ecart = 110;
		int taille = 56;
		int decalageSpellX = 404;
		int decalageSpellY = 101;
		int ecartSpell = 117;
		int tailleCase = 67;
		sfVector2i mousePos = { _MousePosX, _MousePosY };
		for (int i = 0; i < 4; i++)
		{
			if (mousePos.y >= hud->Portraits.y && mousePos.y <= hud->Portraits.y + 56)
			{
				if (mousePos.x >= hud->Portraits.x + (i * ecart) && mousePos.x <= hud->Portraits.x + ((i + 1) * ecart))
				{
					hud->infoWindowIsDisplaying = TRUE;
					hud->playerWindowDisplaying = i;

				}
			}
			else if (mousePos.y >= hud->Hud.y + decalageSpellY && mousePos.y <= hud->Hud.y + decalageSpellY + tailleCase)
			{
				if ((mousePos.x >= hud->Hud.x + decalageSpellX + (i * ecartSpell) && (mousePos.x <= hud->Hud.x + decalageSpellX + ((i + 1) * ecartSpell))))
				{
					hud->infoWindowIsDisplaying = TRUE;
					hud->playerWindowDisplaying = 5;
					hud->SpellIsDisplaying = i;
				};
			}
			else
			{
				hud->infoWindowIsDisplaying = FALSE;
			}
		};
	};
	//ICI UNIQUEMENT DES FONCTION UTILISER DANS DES UPDATES

	void DisplayHud(D_SpellHud* _SpellHud, A_FightHud* AllSprite, D_FightSystem* fightSystem, DataSystem* DT, D_Perso* perso)
	{
		for (int i = 0; i < 4; i++)
		{
			if (fightSystem->turn.turnPlayer <= 4)
			{

				if (perso->player[fightSystem->turn.turnPlayer - 1].spell[i].inUse == 1)
				{
					blitSprite(AllSprite->HudSpellSprite[fightSystem->turn.turnPlayer - 1][i][1], _SpellHud[i].x, _SpellHud[i].y, 0, DT->window);
				}
				else
				{
					blitSprite(AllSprite->HudSpellSprite[fightSystem->turn.turnPlayer - 1][i][0], _SpellHud[i].x, _SpellHud[i].y, 0, DT->window);
				}
			}

		}
	}
	void displayInfoWindow(D_HudCombat* hud, D_Perso* _perso, D_FightSystem* fightsystem, sfRenderWindow* window)
	{
		char string[250];
		int classeX = 157;
		int classeY = 36;
		int PAY = 86;
		int PVY = 146;
		int DEFY = 226;
		int ATKY = 186;
		int CRITY = 266;
		int portaitX = 31;
		int portraitY = 36;
		if (hud->infoWindowIsDisplaying == TRUE)
		{
			blitSprite(hud->AllSprite.displayWindow, hud->infoWindow.x, hud->infoWindow.y, 0, window);
			if (hud->playerWindowDisplaying != 5)
			{
				blitSprite(hud->AllSprite.portraits[hud->playerWindowDisplaying], hud->infoWindow.x + portaitX, hud->infoWindow.y + portraitY, 0, window);
				if (hud->playerWindowDisplaying == 0)
				{
					sprintf(string, "Guerrier");
					displayTexte(string, hud->fontStats.text, hud->infoWindow.x + classeX, hud->infoWindow.y + classeY, window, hud->colorPerso[0], 25);
				}
				else if (hud->playerWindowDisplaying == 1)
				{
					sprintf(string, "Mage Noir");
					displayTexte(string, hud->fontStats.text, hud->infoWindow.x + classeX, hud->infoWindow.y + classeY, window, hud->colorPerso[1], 23);
				}
				else if (hud->playerWindowDisplaying == 2)
				{
					sprintf(string, "Prètre");
					displayTexte(string, hud->fontStats.text, hud->infoWindow.x + classeX, hud->infoWindow.y + classeY, window, hud->colorPerso[2], 25);
				}
				else if (hud->playerWindowDisplaying == 3)
				{
					sprintf(string, "Voleuse");
					displayTexte(string, hud->fontStats.text, hud->infoWindow.x + classeX, hud->infoWindow.y + classeY, window, hud->colorPerso[3], 25);
				};
				sprintf(string, "PA : %d", _perso->player[hud->playerWindowDisplaying].Stat.PA);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + classeX, hud->infoWindow.y + PAY, window, sfWhite, 30);
				sprintf(string, "PV : %d / %d", _perso->player[hud->playerWindowDisplaying].Stat.PV, _perso->player[hud->playerWindowDisplaying].Stat.PVMax);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX, hud->infoWindow.y + PVY, window, sfRed, 20);
				sprintf(string, "ATK : %d", _perso->player[hud->playerWindowDisplaying].Stat.ATK);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX, hud->infoWindow.y + ATKY, window, sfWhite, 20);
				sprintf(string, "+ %d", _perso->player[hud->playerWindowDisplaying].Stat.bonusATK);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX + 120, hud->infoWindow.y + ATKY, window, sfGreen, 20);
				sprintf(string, "DEF : %d", _perso->player[hud->playerWindowDisplaying].Stat.def);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX, hud->infoWindow.y + DEFY, window, sfWhite, 20);
				sprintf(string, "+ %d", _perso->player[hud->playerWindowDisplaying].Stat.bonusDEF);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX + 120, hud->infoWindow.y + DEFY, window, sfGreen, 20);
				sprintf(string, "CRIT : %d", _perso->player[hud->playerWindowDisplaying].Stat.crit);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX, hud->infoWindow.y + CRITY, window, sfWhite, 20);
				sprintf(string, "+ %d", _perso->player[hud->playerWindowDisplaying].Stat.bonusCRIT);
				displayTexte(string, hud->fontStats.text, hud->infoWindow.x + portaitX + 120, hud->infoWindow.y + CRITY, window, sfGreen, 20);
			}
			else
			{
				int nameSpellX = 125;
				int nameSpellY = 25;
				int descSpellY = 100;
				int decStatsY = 250;
				int decStatsY2 = 350;
				int decStatsY3 = 450;
				int decStatsY4 = 500;
				if (fightsystem->turn.turnPlayer != 5)
				{
					blitSprite(hud->AllSprite.HudSpellSprite[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying][1], hud->infoWindow.x + portaitX, hud->infoWindow.y + portraitY, 0, window);
					displayTexte(hud->spellNames[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying], hud->fontStats.text, hud->infoWindow.x + nameSpellX, hud->infoWindow.y + nameSpellY, window, hud->colorPerso[fightsystem->turn.turnPlayer - 1], 20);
					displayTexte(hud->spellDescription[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying], hud->fontStats.text, hud->infoWindow.x + portaitX - 25, hud->infoWindow.y + descSpellY, window, sfWhite, 20);
					displayTexte(hud->spellCost[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying], hud->fontStats.text, hud->infoWindow.x + portaitX - 25, hud->infoWindow.y + decStatsY, window, sfBlue, 20);
					displayTexte(hud->spellDamage[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying], hud->fontStats.text, hud->infoWindow.x + portaitX - 25, hud->infoWindow.y + decStatsY2, window, sfRed, 20);
					displayTexte(hud->spellPO[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying], hud->fontStats.text, hud->infoWindow.x + portaitX - 25, hud->infoWindow.y + decStatsY3, window, sfWhite, 20);
					displayTexte(hud->spellArea[fightsystem->turn.turnPlayer - 1][hud->SpellIsDisplaying], hud->fontStats.text, hud->infoWindow.x + portaitX - 25, hud->infoWindow.y + decStatsY4, window, sfWhite, 20);
				}
			
			};
		}
		else
		{
		};
	};
	void DisplayEnemyLife(D_HudCombat* hud, M_Enemy* enemy, sfVector2f Camera, sfRenderWindow* window)
	{
		if (hud->isDisplayingEnemyLife == TRUE)
		{
			for (int i = 0; i < enemy->TotEnemy; i++)
			{
				if (enemy->Data_Enemy[i].Stat.PV > 0)
				{
					blitSprite(hud->AllSprite.emptyHealthEnemy, enemy->Data_Enemy[i].pos.x + Camera.x - 50, enemy->Data_Enemy[i].pos.y + Camera.y - 50, 0, window);
					float coef = enemy->Data_Enemy[i].Stat.PV * 100 / enemy->Data_Enemy[i].Stat.PVMax;
					for (int l = 1; l < coef; l++)
					{
						blitSprite(hud->AllSprite.healthGauge, enemy->Data_Enemy[i].pos.x + Camera.x - 50 + l, enemy->Data_Enemy[i].pos.y + Camera.y - 50, 0, window);
					}
				}
			}
		}
	};
	void DisplayMoove(D_HudCombat* hud, DataSystem* DT)
	{
		char numstr[150];
		blitSprite(hud->AllSprite.moove, hud->useMoove.x, hud->useMoove.y, 0, DT->window);
		sprintf(numstr, "Déplacement");
		displayTexte(numstr, hud->fontStats.text, hud->useMoove.x + 15, hud->useMoove.y + 5, DT->window, sfBlack, 20);
	}

	void DisplayPassTurn(D_HudCombat* hud, DataSystem* DT)
	{
		char numstr[150];
		blitSprite(hud->AllSprite.changeTurn, hud->passTurn.x, hud->passTurn.y, 0, DT->window);
		sprintf(numstr, "Fin de tour");
		displayTexte(numstr, hud->fontStats.text, hud->passTurn.x + 15, hud->passTurn.y + 5, DT->window, sfBlack, 20);
	}

	void DisplayStatsHud(D_Perso* perso, D_HudCombat* _Stats, DataSystem* DT)
	{

	}

	void DisplayHudPlayers(D_HudCombat* hud, DataSystem* DT, D_FightSystem* fightSystem, D_Perso* perso, sfVector2f camera)
	{
		///AFFICHAGE DU BLOC EN BAS DE L ECRAN 
		///PERSONNAGE QUI JOUE 
		if (fightSystem->turn.turnPlayer != 5)
		{
			

			if (hud->decYcursor <= -5)
			{
				hud->cursorSpeed = 10;
			}
			if (hud->decYcursor >= 5)
			{
				hud->cursorSpeed = -10;
			}
			hud->decYcursor += hud->cursorSpeed * DT->DT;
			float tempY = perso->player[fightSystem->turn.turnPlayer - 1].y - 130 + camera.y + hud->decYcursor;
			blitSprite(hud->AllSprite.alliedCursor, perso->player[fightSystem->turn.turnPlayer - 1].x + camera.x - 10, tempY, 0, DT->window);
		};
		blitSprite(hud->AllSprite.HudPlayers, 0, 0, 0, DT->window);

		if (fightSystem->turn.turnPlayer != 5)
		{
			char numstr[21];

			sprintf(numstr, "PA : %d", perso->player[fightSystem->turn.turnPlayer - 1].Stat.PA);
			displayTexte(numstr, hud->fontStats.text, hud->PortraitIsPlaying.x, hud->PortraitIsPlaying.y - 45, DT->window, sfBlue, 20);
			blitSprite(hud->AllSprite.portraits[fightSystem->turn.turnPlayer - 1], hud->PortraitIsPlaying.x, hud->PortraitIsPlaying.y, 0, DT->window);
		}
		///Barre de vie en dessous des portraits 
		char numstr[25];
		for (int i = 0; i < 4; i++)
		{
			int coef = perso->player[i].Stat.PV * 58 / perso->player[i].Stat.PVMax;
			blitSprite(hud->AllSprite.emptyHealth, hud->Portraits.x + (i * hud->Portraits.HudWidth), hud->Portraits.y + 55, 0, DT->window);
			for (int j = 0; j < coef; j++)
			{
				blitSprite(hud->AllSprite.healthGauge, hud->Portraits.x + (i * hud->Portraits.HudWidth) + j, hud->Portraits.y + 55, 0, DT->window);
			}

			sprintf(numstr, "PA : %d", perso->player[i].Stat.PA);
			displayTexte(numstr, hud->fontStats.text, hud->Portraits.x + (i * hud->Portraits.HudWidth), hud->Portraits.y + 75, DT->window, sfBlue, 20);
		};
		int coef = perso->player[fightSystem->turn.turnPlayer - 1].Stat.PV * 531 / perso->player[fightSystem->turn.turnPlayer - 1].Stat.PVMax;
		if (fightSystem->turn.turnPlayer != 5)
		{
			for (int j = 0; j < coef; j++)
			{
				blitSprite(hud->AllSprite.healthGauge2, 769 + j, 940, 0, DT->window);
			}
		}
	};

	void DisplaySpellInUse(D_HudCombat* hud, D_Perso* perso, DataSystem* DT)
	{
		for (int i = 0; i < 4; i++)
		{

			if (perso->player[i].spell[0].inUse == 1)
			{
				blitSprite(hud->AllSprite.Spell1InUse, -1, 92, 0, DT->window);
			}

			if (perso->player[i].spell[1].inUse == 1)
			{
				blitSprite(hud->AllSprite.Spell2InUse, -1, 92, 0, DT->window);
			}

			if (perso->player[i].spell[2].inUse == 1)
			{
				blitSprite(hud->AllSprite.Spell3InUse, -1, 92, 0, DT->window);
			}

			if (perso->player[i].spell[3].inUse == 1)
			{
				blitSprite(hud->AllSprite.Spell4InUse, -1, 92, 0, DT->window);
			}

		}

	}

