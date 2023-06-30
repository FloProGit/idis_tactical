#include "inventory.h"
//////////////////// Utils
void displayText(char* _sContenu, sfText* _text, int posX, int posY, sfRenderWindow* _window, sfColor _color)
{
	sfText_setString(_text, _sContenu);
	sfVector2f tempPos = { posX, posY };
	sfText_setPosition(_text, tempPos);
	sfText_setColor(_text, _color);
	sfRenderWindow_drawText(_window, _text, NULL);
}
//////////////////// Init
void initBattleTeam(D_Inventory* _Inventory)
{
	//-------------Mage Noir
	//Stats du Mage Noir 
	_Inventory->player[0].pv = 100;
	_Inventory->player[0].pa = 6;
	_Inventory->player[0].pm = 3;
	_Inventory->player[0].crit = 3;
	//Arme du Mage Noir 
	for (int i = 0; i < 3; i++)
	{
		_Inventory->player[0].weapon.rune[i].kind = None;
		_Inventory->player[0].weapon.rune[i].rarity = Null; //Raretée de la rune 

	}
	_Inventory->player[1].pv = 100;
	_Inventory->player[1].pa = 6;
	_Inventory->player[1].pm = 3;
	_Inventory->player[1].crit = 3;

	for (int i = 0; i < 3; i++)
	{
		_Inventory->player[1].weapon.rune[i].kind = None;
		_Inventory->player[1].weapon.rune[i].rarity = Null; //Raretée de la rune 

	}

	_Inventory->player[2].pv = 100;
	_Inventory->player[2].pa = 6;
	_Inventory->player[2].pm = 3;
	_Inventory->player[2].crit = 3;
	//Arme du Mage Noir 
	for (int i = 0; i < 3; i++)
	{
		_Inventory->player[2].weapon.rune[i].kind = None;
		_Inventory->player[2].weapon.rune[i].rarity = Null; //Raretée de la rune 

	}
	_Inventory->player[3].pv = 100;
	_Inventory->player[3].pa = 6;
	_Inventory->player[3].pm = 3;
	_Inventory->player[3].crit = 3;
	//Arme du Mage Noir 
	for (int i = 0; i < 3; i++)
	{
		_Inventory->player[3].weapon.rune[i].kind = None;
		_Inventory->player[3].weapon.rune[i].rarity = Null; //Raretée de la rune 

	}


	//Init du sac 
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			_Inventory->bag[j][i].kind = None;
			_Inventory->bag[j][i].rarity = Null;
		}
	}
	///////RUNE DONNEE AU DEBUT DU JEU POUR LA 1ST PLAYABLE ET OUI C EST DEGUALASSE
	//_Inventory->bag[0][0].kind = ATK;
	//_Inventory->bag[0][0].rarity = Legendary;
	//_Inventory->bag[1][0].kind = DEF;
	//_Inventory->bag[1][0].rarity = Rare;
	//_Inventory->bag[2][0].kind = CRIT;
	//_Inventory->bag[2][0].rarity = Mythical;
	//_Inventory->bag[3][0].kind = DEF;
	//_Inventory->bag[3][0].rarity = Uncommon;
	//_Inventory->bag[4][0].kind = DEF;
	//_Inventory->bag[4][0].rarity = Legendary;

	//Lecture des fichiers de sauvegardes
	FILE *fichierSac;
	if (!(fichierSac = fopen("SAVE/bag.bin", "rb"))) {
		printf("Erreur d'acces au fichier...\n");
		exit(EXIT_FAILURE);
	}
	fread(_Inventory->bag, sizeof(RUNE), 30, fichierSac);
	fclose(fichierSac);

	FILE *fichierINV;
	if (!(fichierINV = fopen("SAVE/inventory.bin", "rb"))) {
		printf("Erreur d'acces au fichier...\n");
		exit(EXIT_FAILURE);
	}
	fread(_Inventory->player, sizeof(D_PersoCombat), 4, fichierINV);
	fclose(fichierINV);

};
/////////////////////
void initSprites(D_Inventory* _inventory)
{
	_inventory->sprites.inventory = LoadSprite("IMG/INVENTORY/inventory.png", 0, 0, 0);
	_inventory->sprites.inventoryBag = LoadSprite("IMG/INVENTORY/inventoryBAG.png", 0, 0, 0);
	_inventory->sprites.inventoryBagSelected = LoadSprite("IMG/INVENTORY/inventorySelectionned.png", 0, 0, 0);
	_inventory->sprites.runeATK = LoadSprite("IMG/INVENTORY/RUNES/ICONS/ATK.png", 0, 0, 0);
	_inventory->sprites.runeDEF = LoadSprite("IMG/INVENTORY/RUNES/ICONS/DEF.png", 0, 0, 0);
	_inventory->sprites.runePO = LoadSprite("IMG/INVENTORY/RUNES/ICONS/CRIT.png", 0, 0, 0);
	_inventory->sprites.rarity1 = LoadSprite("IMG/INVENTORY/RUNES/RARITY/Uncommon.png", 0, 0, 0);
	_inventory->sprites.rarity2 = LoadSprite("IMG/INVENTORY/RUNES/RARITY/Rare.png", 0, 0, 0);
	_inventory->sprites.rarity3 = LoadSprite("IMG/INVENTORY/RUNES/RARITY/Legendary.png", 0, 0, 0);
	_inventory->sprites.rarity4 = LoadSprite("IMG/INVENTORY/RUNES/RARITY/Mythical.png", 0, 0, 0);
	_inventory->sprites.feedBackCommon = LoadSprite("IMG/INVENTORY/FeedBack/feedBackCommon.png", 0, 0, 0);
	_inventory->sprites.feedBackRare = LoadSprite("IMG/INVENTORY/FeedBack/feedBackRare.png", 0, 0, 0);
	_inventory->sprites.feedBackLegendary = LoadSprite("IMG/INVENTORY/FeedBack/feedBackLegendary.png", 0, 0, 0);
	_inventory->sprites.feedBackMythical = LoadSprite("IMG/INVENTORY/FeedBack/feedBackMythical.png", 0, 0, 0);
	_inventory->sprites.feedBackSelected = LoadSprite("IMG/INVENTORY/FeedBack/feedBackSelect.png", 0, 0, 0);
	_inventory->sprites.dropped = LoadSprite("IMG/INVENTORY/dropped.png", 0, 0, 0);
	_inventory->sprites.link = LoadSprite("IMG/INVENTORY/link.PNG", 0, 0, 0);
	_inventory->sprites.littleWindow = LoadSprite("IMG/INVENTORY/window.png", 0, 0, 0);
	_inventory->sprites.button = LoadSprite("IMG/INVENTORY/button.png", 0, 0, 0);
	_inventory->sprites.buttonSelect = LoadSprite("IMG/INVENTORY/buttonSelect.png", 0, 0, 0);
	_inventory->sprites.trash = LoadSprite("IMG/INVENTORY/poubelle.png", 0, 0, 0);
	_inventory->sprites.trashSelected = LoadSprite("IMG/INVENTORY/poubelleSelect.png", 0, 0, 0);
	_inventory->RuneIsDropped = FALSE;
	_inventory->timer = 0;
};
///////////////////
void initText(D_Inventory* _inventory)
{
	_inventory->fontStats.font = sfFont_createFromFile("IMG/INVENTORY/FONT/PixelIntv.otf");
	_inventory->fontStats.text = sfText_create();
	sfText_setFont(_inventory->fontStats.text, _inventory->fontStats.font);
	sfText_setCharacterSize(_inventory->fontStats.text, 20);
};
///////////////////
void initInventory(D_Inventory* _inventory)
{
	initSprites(_inventory);
	initBattleTeam(_inventory);
	initText(_inventory);
	updateTeamStats(_inventory);
	_inventory->tempRuneIsSelected = 0;
	_inventory->inventoryState = Stats;
};

///////////////////EVENT 
void selectRuneInInventory(D_Inventory*_inventory, int _mousePosX, int _mousePosY)
{
	{
		sfVector2i mousePos = { _mousePosX, _mousePosY };
		int decalageX = 589;
		int decalageYWar = 393;
		int decalageY = 131;
		int tailleCase = 72;
		int ecartCases = 125;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				// le Y sert a sélectionner le perso, le X le numéro de Rune Taille d'une case : 37*37
				if (mousePos.y >= decalageYWar + (j * decalageY) && mousePos.y < decalageYWar + ((j + 1) * decalageY) && mousePos.x >= decalageX)
				{
					if ((mousePos.x >= decalageX + (ecartCases * i)) && (mousePos.x <= decalageX + (ecartCases * (i + 1))))
					{
						_inventory->tempRune = _inventory->player[j].weapon.rune[i];
						_inventory->tempRuneIsSelected = 1;
						_inventory->teamMemberSelected = j;
						_inventory->RuneSelected = i;
					

					}

				}
			}
		};

	};
};

void updateTeamStats(D_Inventory* _inventory)
{
	int compteurATK = 0;
	int compteurCRIT = 0;
	int compteurDEF = 0;

	_inventory->player[0].atk = 10;
	_inventory->player[0].def = 10;
	_inventory->player[0].crit = 0;

	_inventory->player[1].atk = 10;
	_inventory->player[1].def = 5;
	_inventory->player[1].crit = 5;

	_inventory->player[2].atk = 5;
	_inventory->player[2].def = 5;
	_inventory->player[2].crit = 10;

	_inventory->player[3].atk = 10;
	_inventory->player[3].def = 0;
	_inventory->player[3].crit = 10;
	for (int j = 0; j < 4; j++)
	{
		_inventory->player[j].boostAtk = 0;
		_inventory->player[j].boostDef = 0;
		_inventory->player[j].boostCrit = 0;
		for (int i = 0; i < 3; i++)
		{
			if (_inventory->player[j].weapon.rune[i].kind == ATK)
			{
				compteurATK += 1;
				_inventory->player[j].boostAtk += (_inventory->player[j].weapon.rune[i].rarity + 1) * 5;
				if (compteurATK >= 2)
				{
					_inventory->player[j].link = LinkedATK;
				}
			}
			if (_inventory->player[j].weapon.rune[i].kind == DEF)
			{
				compteurDEF += 1;
				_inventory->player[j].boostDef += (_inventory->player[j].weapon.rune[i].rarity + 1) * 5;
				if (compteurDEF >= 2)
				{
					_inventory->player[j].link = LinkedDEF;
				}
			}
			if (_inventory->player[j].weapon.rune[i].kind == CRIT)
			{
				compteurCRIT += 1;
				_inventory->player[j].boostCrit += (_inventory->player[j].weapon.rune[i].rarity + 1) * 5;
				if (compteurCRIT >= 2)
				{
					_inventory->player[j].link = LinkedCrit;
				}
			}
		}
		if (compteurCRIT < 2)
		{
			if (compteurATK < 2)
			{
				if (compteurDEF < 2)
				{
					_inventory->player[j].link = NoneLinked;
				};
			};
		};
		compteurATK = 0;
		compteurDEF = 0;
		compteurCRIT = 0;
	}
};
///////////////////////
void selectRuneInBag(D_Inventory* _inventory, int _mousePosX, int _mousePosY)
{
	sfVector2i mousePos = { _mousePosX, _mousePosY };
	int decalageBagX = 1063;
	int decalageBagY = 390;
	float ecartBagX = 125;
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (mousePos.x >= decalageBagX + (ecartBagX * j) && mousePos.x <= decalageBagX + (ecartBagX * (j + 1)))
			{
				if (mousePos.y >= decalageBagY + (ecartBagX * i) && mousePos.y <= decalageBagY + (ecartBagX * (i + 1)))
				{
					if (_inventory->bag[j][i].kind != None && _inventory->bag[j][i].rarity != Null)
					{
						_inventory->tempRune.kind = _inventory->bag[j][i].kind;
						_inventory->tempRune.rarity = _inventory->bag[j][i].rarity;
						_inventory->tempRuneIsSelected = 1;
						_inventory->teamMemberSelected = 4;
						_inventory->LineSelected = i;
						_inventory->columnSelected = j;
					};
				}
			}
		}
	}
};
///////////////////////
void releaseRune(D_Inventory* _inventory, int _mousePosX, int _mousePosY)
{
	//Bugs connus = Création de nouvelles Runes, suppression de runes déja existantes. ( Vachement aléatoire, 3 fois en 25 lancements )
	sfVector2i mousePos = { _mousePosX, _mousePosY };
	int decalageX = 589;
	int decalageYWar = 393;
	int decalageY = 131;
	int tailleCase = 72;
	int ecartCases = 125;
	int trashX = 1706;
	int trashY = 870;
	int trashH = 60;
	int tailleINVX = 1135;
	int tailleINVY = 549;
	RUNE tempRune2;
	if (mousePos.x >= decalageX && mousePos.x <= decalageX + tailleINVX && mousePos.y >= decalageYWar && mousePos.y <= decalageYWar + tailleINVY)
	{





		


		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				// le Y sert a sélectionner le perso, le X le numéro de Rune
				if (mousePos.y >= decalageYWar + (j * decalageY) && mousePos.y < decalageYWar + ((j + 1) * decalageY) && mousePos.x >= decalageX)
				{
					if ((mousePos.x >= decalageX + (ecartCases * i)) && (mousePos.x <= decalageX + (ecartCases * (i + 1))))
					{
						tempRune2 = _inventory->player[j].weapon.rune[i];
						_inventory->player[j].weapon.rune[i] = _inventory->tempRune;
						_inventory->tempRuneIsSelected = 0;
						_inventory->tempRune.kind = None;
						_inventory->tempRune.rarity = Null;
					}
				}
			if (mousePos.y >= trashY && mousePos.y <= trashY + trashH && mousePos.x >= trashX && mousePos.x <= trashX + trashH)
				{
					_inventory->tempRuneIsSelected = 0;
					_inventory->tempRune.kind = None;
					_inventory->tempRune.rarity = Null;
				};
			}
		}
		//SAC
		int decalageBagX = 1063;
		int decalageBagY = 390;
		float ecartBagX = 125;
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (mousePos.x >= decalageBagX + (ecartBagX * j) && mousePos.x <= decalageBagX + (ecartBagX * (j + 1)) && mousePos.y >= decalageBagY + (ecartBagX * i) && mousePos.y <= decalageBagY + (ecartBagX * (i + 1)))
				{
					tempRune2 = _inventory->bag[j][i];
					_inventory->bag[j][i] = _inventory->tempRune;
					_inventory->tempRuneIsSelected = 0;
					_inventory->tempRune.kind = None;
					_inventory->tempRune.rarity = Null;
				}
				else if (mousePos.y >= trashY && mousePos.y <= trashY + trashH && mousePos.x >= trashX && mousePos.x <= trashX + trashH)
				{
					_inventory->tempRuneIsSelected = 0;
					_inventory->tempRune.kind = None;
					_inventory->tempRune.rarity = Null;
				}
				else
				{
					_inventory->tempRuneIsSelected = 0;
				}
			}
		};
		if (_inventory->teamMemberSelected == 4)
		{
			_inventory->bag[_inventory->columnSelected][_inventory->LineSelected] = tempRune2;
		}
		else
		{
			_inventory->player[_inventory->teamMemberSelected].weapon.rune[_inventory->RuneSelected] = tempRune2;
		}
		updateTeamStats(_inventory);
		_inventory->tempRuneIsSelected = 0;
	}
};
//////////////////


//////////////////
void eventSwitchInventoryPage(D_Inventory* _Inventory, int _mousePosX, int _mousePosY)
{
	sfVector2i mousePos = { _mousePosX,_mousePosY };
	int decalageX = 1048;
	int decalageY = 230;
	int heightBox = 112;
	int widthBox = 238;
	if (mousePos.y >= decalageY && mousePos.y <= decalageY + heightBox)
	{
		if (_Inventory->inventoryState == Bag)
		{
			if (mousePos.x >= decalageX && mousePos.x <= decalageX + widthBox)
			{
				_Inventory->inventoryState = Stats;
			};
		}
		else if (_Inventory->inventoryState == Stats)
		{
			if (mousePos.x >= decalageX + widthBox && mousePos.x <= decalageX + (widthBox * 2))
			{
				_Inventory->inventoryState = Bag;
			};
		};
	};
};
//////////////////
void updateSwitchInventoryPage(D_Inventory* _Inventory, int _mousePosX, int _mousePosY)
{

};
//////////////////
void updateLittleWindow(D_Inventory* _inventory, int _mousePosX, int _mousePosY)
{
	sfVector2i mousePos = { _mousePosX, _mousePosY };
	float maxTime = 3;
	if (_inventory->tempRuneIsSelected == 0)
	{
			int decalageX = 589;
			int decalageYWar = 393;
			int decalageY = 131;
			int tailleCase = 72;
			int ecartCases = 125;
			int tailleINVX = 1632;
			int tailleINVY = 862;
			float dt = 0.005f;
			if (mousePos.x >= decalageX && mousePos.x <= decalageX + tailleINVX && mousePos.y >= decalageYWar && mousePos.y <= decalageYWar + tailleINVY)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int i = 0; i < 3; i++)
					{
						// le Y sert a sélectionner le perso, le X le numéro de Rune Taille d'une case : 37*37
						if (mousePos.y >= decalageYWar + (j * decalageY) && mousePos.y < decalageYWar + ((j + 1) * decalageY) && mousePos.x >= decalageX)
						{
						
							if ((mousePos.x >= decalageX + (ecartCases * i)) && (mousePos.x <= decalageX + (ecartCases * (i + 1))))
							{
								printf("timer : %f\n", _inventory->timer);
      									_inventory->timer += dt;
									if (_inventory->timer > maxTime)
									{
										if (_inventory->player[j].weapon.rune[i].kind != None && _inventory->player[j].weapon.rune[i].rarity != Null)
										{

											_inventory->littleWindowIsDisplaying = 1;
											_inventory->explicatedRune = _inventory->player[j].weapon.rune[i];
										}
										else
										{
											_inventory->timer = 0;
											_inventory->littleWindowIsDisplaying = 0;
										}
									};
								
							}
						}
					}
				}
			}
			int decalageBagX = 1063;
			int decalageBagY = 390;
			float ecartBagX = 125;
			if (mousePos.x >= decalageBagX && mousePos.x <= decalageBagX + tailleINVX && mousePos.y >= decalageBagY && mousePos.y <= decalageBagY + tailleINVY)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						// le Y sert a sélectionner le perso, le X le numéro de Rune Taille d'une case : 37*37
						if (mousePos.y >= decalageBagY + (i * ecartBagX) && mousePos.y < decalageBagY + ((i + 1) * ecartBagX))
						{
							if ((mousePos.x >= decalageBagX + (ecartBagX * j)) && (mousePos.x <= decalageBagX + (ecartBagX * (j + 1))))
							{
								if (_inventory->bag[j][i].kind != None && _inventory->bag[j][i].rarity != Null)
								{
									_inventory->timer += dt;
									if (_inventory->timer > maxTime)
									{
										_inventory->littleWindowIsDisplaying = 1;
										_inventory->explicatedRune = _inventory->bag[j][i];
									};
								}
								else
								{
									_inventory->timer = 0;
									_inventory->littleWindowIsDisplaying = 0;
								};
							}
						}
					}
				}
			}
		}
	};
//////////////////DISPLAY
void displayLittleWindow(D_Inventory* _inventory, int _mousePosX, int _mousePosY, sfRenderWindow* window)
{
	char numstr[21];
	sfVector2i mousePos = { _mousePosX + 15, _mousePosY };
	sfColor tempCol = { 0,0,0,255 };
	if (_inventory->littleWindowIsDisplaying == 1)
	{
		blitSprite(_inventory->sprites.littleWindow, mousePos.x, mousePos.y, 0, window);

		int tempPosNameY = mousePos.y + 5;
		int tempPosRarityY = mousePos.y + 35;
		int tempPosStatsY = mousePos.y + 70;
		int tempPosX = mousePos.x + 3;
		if (_inventory->explicatedRune.kind == ATK)
		{
			sprintf(numstr, "Rune d'attaque");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosNameY, window, sfWhite);
			sprintf(numstr, "  d'attaque");
			displayText(numstr, _inventory->fontStats.text, tempPosX + 40, tempPosStatsY, window, sfWhite);
		}
		else if (_inventory->explicatedRune.kind == DEF)
		{
			sprintf(numstr, "Rune de défense");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosNameY, window, sfWhite);
			sprintf(numstr, "  de défense");
			displayText(numstr, _inventory->fontStats.text, tempPosX + 40, tempPosStatsY, window, sfWhite);
		}
		else if (_inventory->explicatedRune.kind == CRIT)
		{
			sprintf(numstr, "Rune de critique");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosNameY, window, sfWhite);
			sprintf(numstr, "  de critique");
			displayText(numstr, _inventory->fontStats.text, tempPosX + 40, tempPosStatsY, window, sfWhite);
		}
		else if (_inventory->explicatedRune.kind == None)
		{
			_inventory->littleWindowIsDisplaying = 0;
		};
		if (_inventory->explicatedRune.rarity == Uncommon)
		{
			sfColor tempCol = { 182,182,182,255 };
			sprintf(numstr, "Peu Commune");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosRarityY, window, tempCol);
			sprintf(numstr, "+ 5");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosStatsY, window, sfWhite);
		}
		else if (_inventory->explicatedRune.rarity == Rare)
		{
			sfColor tempCol = { 50,182,40,255 };
			sprintf(numstr, "Rare");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosRarityY, window, tempCol);
			sprintf(numstr, "+ 10");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosStatsY, window, sfWhite);
		}
		else if (_inventory->explicatedRune.rarity == Legendary)
		{
			sfColor tempCol = { 215,188,45 ,255 };
			sprintf(numstr, "Légendaire");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosRarityY, window, tempCol);
			sprintf(numstr, "+ 15");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosStatsY, window, sfWhite);
		}
		else if (_inventory->explicatedRune.rarity == Mythical)
		{
			sfColor tempCol = { 160,43,215,255 };
			sprintf(numstr, "Mythique");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosRarityY, window, tempCol);
			sprintf(numstr, "+ 20");
			displayText(numstr, _inventory->fontStats.text, tempPosX, tempPosStatsY, window, sfWhite);
		}
	};
};
///////////////////////
void displayInventory(D_Inventory* _inventory, sfRenderWindow* window)
{

	int decalageX = 592;
	int decalageYWar = 391;
	int decalageY = 131;
	int tailleCase = 72;
	int ecartCases = 124;
	//Affichage de l'inventaire 
	blitSprite(_inventory->sprites.inventory, 0, 0, 0, window);

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (_inventory->player[j].weapon.rune[i].rarity == Uncommon)
			{
				blitSprite(_inventory->sprites.rarity1, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			}
			else if (_inventory->player[j].weapon.rune[i].rarity == Rare)
			{
				blitSprite(_inventory->sprites.rarity2, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			}
			else if (_inventory->player[j].weapon.rune[i].rarity == Legendary)
			{
				blitSprite(_inventory->sprites.rarity3, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			}
			else if (_inventory->player[j].weapon.rune[i].rarity == Mythical)
			{
				blitSprite(_inventory->sprites.rarity4, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			};
			//Genre
			if (_inventory->player[j].weapon.rune[i].kind == ATK)
			{
				blitSprite(_inventory->sprites.runeATK, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			}
			else if (_inventory->player[j].weapon.rune[i].kind == DEF)
			{
				blitSprite(_inventory->sprites.runeDEF, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			}
			else if (_inventory->player[j].weapon.rune[i].kind == CRIT)
			{
				blitSprite(_inventory->sprites.runePO, decalageX + ((i)* ecartCases), decalageYWar + (j * decalageY), 0, window);
			};

		};
	};

};
///////////////////////
void displayBagPage(D_Inventory* _inventory, sfRenderWindow* window)
{
	// affichage du sac
	int decalageBagX = 1063;
	int decalageBagY = 390;
	float ecartBagX = 125;
	float ecartBagY = 131;
	//Raretée
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory->bag[j][i].rarity == Uncommon)
			{
				blitSprite(_inventory->sprites.rarity1, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
				blitSprite(_inventory->sprites.feedBackCommon, decalageBagX + (ecartBagX * j) - 7, decalageBagY + (ecartBagY * i) - 6, 0, window);
			}
			else if (_inventory->bag[j][i].rarity == Rare)
			{
				blitSprite(_inventory->sprites.rarity2, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
				blitSprite(_inventory->sprites.feedBackRare, decalageBagX + (ecartBagX * j) - 7, decalageBagY + (ecartBagY * i) - 6, 0, window);
			}
			else if (_inventory->bag[j][i].rarity == Legendary)
			{
				blitSprite(_inventory->sprites.rarity3, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
				blitSprite(_inventory->sprites.feedBackLegendary, decalageBagX + (ecartBagX * j) - 7, decalageBagY + (ecartBagY * i) - 6, 0, window);
			}
			else if (_inventory->bag[j][i].rarity == Mythical)
			{
				blitSprite(_inventory->sprites.rarity4, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
				blitSprite(_inventory->sprites.feedBackMythical, decalageBagX + (ecartBagX * j) - 7, decalageBagY + (ecartBagY * i) - 6, 0, window);

			}
			else if (_inventory->bag[j][i].rarity == Null)
			{
			};
			if (_inventory->bag[j][i].kind == ATK)
			{
				blitSprite(_inventory->sprites.runeATK, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
			}
			else if (_inventory->bag[j][i].kind == DEF)
			{
				blitSprite(_inventory->sprites.runeDEF, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
			}
			else if (_inventory->bag[j][i].kind == CRIT)
			{
				blitSprite(_inventory->sprites.runePO, decalageBagX + (ecartBagX * j), decalageBagY + (ecartBagY * i), 0, window);
			}
			if (_inventory->teamMemberSelected == 4)
			{
				if (i == (_inventory->LineSelected) && j == (_inventory->columnSelected) && _inventory->tempRuneIsSelected == 1)
				{
					blitSprite(_inventory->sprites.feedBackSelected, decalageBagX + (ecartBagX * j) - 5, decalageBagY + (ecartBagY * i) - 5, 0, window);
				}
		    }
		};
	};
};
////////////////////////////////////////////////////////////////
void displayTempRune(D_Inventory* _inventory, int _mousePosX, int _mousePosY, sfRenderWindow* window)
{
	sfVector2i mousePos = { _mousePosX, _mousePosY };
	int TailleImage = 36;
	if (_inventory->tempRuneIsSelected == 1)
	{

	}
};
void displayFeedBackInInventory(D_Inventory* _Inventory, int _MousePosX, int _MousePosY, sfRenderWindow* window)
{
	sfVector2i mousePos = { _MousePosX, _MousePosY };
	int decalageX = 592;
	int decalageYWar = 391;
	int decalageY = 131;
	int tailleCase = 72;
	int ecartCases = 124;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			//Guerrier
			if (_Inventory->player[j].weapon.rune[i].rarity == Uncommon)
			{
				blitSprite(_Inventory->sprites.feedBackCommon, decalageX + ((i)* ecartCases) - 7, decalageYWar + (j * decalageY) - 7, 0, window);
			}
			else if (_Inventory->player[j].weapon.rune[i].rarity == Rare)
			{
				blitSprite(_Inventory->sprites.feedBackRare, decalageX + ((i)* ecartCases) - 7, decalageYWar + (j * decalageY) - 7, 0, window);
			}
			else if (_Inventory->player[j].weapon.rune[i].rarity == Legendary)
			{
				blitSprite(_Inventory->sprites.feedBackLegendary, decalageX + ((i)* ecartCases) - 7, decalageYWar + (j * decalageY) - 7, 0, window);
			}
			else if (_Inventory->player[j].weapon.rune[i].rarity == Mythical)
			{
				blitSprite(_Inventory->sprites.feedBackMythical, decalageX + ((i)* ecartCases) - 7, decalageYWar + (j * decalageY) - 7, 0, window);
			};
			if ( _Inventory->RuneSelected == i && _Inventory->teamMemberSelected == j && _Inventory->tempRuneIsSelected == 1)
			{
				blitSprite(_Inventory->sprites.feedBackSelected, decalageX + ((i)* ecartCases) - 7, decalageYWar + (j * decalageY) - 7, 0, window);
			}
		};
	};
};
void displayTrash(D_Inventory* _Inventory, int _MousePosX, int _MousePosY, sfRenderWindow* window)
{
	sfVector2i mousePos = { _MousePosX, _MousePosY };
	int trashX = 1538;
	int trashY = 864 - 72;
	int trashH = 72;
	if (mousePos.x >= trashX && mousePos.x <= trashX + trashH && mousePos.y >= trashY && mousePos.y <= trashY + trashH)
	{
		blitSprite(_Inventory->sprites.trashSelected, trashX, trashY, 0, window);
	}
	else
	{
		blitSprite(_Inventory->sprites.trash, trashX, trashY, 0, window);

	}

};
void displayStats(D_Inventory* _Inventory, sfRenderWindow* window)
{
	char numstr[21]; // enough to hold all numbers up to 64-bits
					 //DifférentesCoordonnées 
	int decX = 290;
	int decX2 = 406;
	//Guerrier
	int decYAtkWar = 390;
	int decYDefWar = 415;
	int decYCritWar = 448;

	int ecartBTPerso = 0;
	sfColor tempCoul = sfBlack;
	sfColor tempCoul2 = { 0,100,0 ,255 };
	for (int i = 0; i < 4; i++)
	{
		//Guerrier 
		sprintf(numstr, "ATK  : %d", _Inventory->player[i].atk);
		if (_Inventory->player[i].link == LinkedATK)
		{
			tempCoul = tempCoul2;
		}
		else
		{
			tempCoul = sfBlack;
		}
		displayText(numstr, _Inventory->fontStats.text, decX, decYAtkWar + (120 * i) + ecartBTPerso, window, tempCoul);
		sprintf(numstr, "+ %d", _Inventory->player[i].boostAtk);
		displayText(numstr, _Inventory->fontStats.text, decX2, decYAtkWar + (120 * i) + ecartBTPerso, window, tempCoul2);
		//////////
		sprintf(numstr, "DEF  : %d", _Inventory->player[i].def);
		if (_Inventory->player[i].link == LinkedDEF)
		{
			tempCoul = tempCoul2;
		}
		else
		{
			tempCoul = sfBlack;
		}
		displayText(numstr, _Inventory->fontStats.text, decX, decYDefWar + (120 * i) + ecartBTPerso, window, tempCoul);
		sprintf(numstr, "+ %d", _Inventory->player[i].boostDef);
		displayText(numstr, _Inventory->fontStats.text, decX2, decYDefWar + (120 * i) + ecartBTPerso, window, tempCoul2);
		//////////////////
		sprintf(numstr, "CRIT : %d", _Inventory->player[i].crit);
		if (_Inventory->player[i].link == LinkedCrit)
		{
			tempCoul = tempCoul2;
		}
		else
		{
			tempCoul = sfBlack;
		}
		displayText(numstr, _Inventory->fontStats.text, decX, decYCritWar + (120 * i) + ecartBTPerso, window, tempCoul);
		sprintf(numstr, "+ %d", _Inventory->player[i].boostCrit);
		displayText(numstr, _Inventory->fontStats.text, decX2, decYCritWar + (120 * i) + ecartBTPerso, window, tempCoul2);
		ecartBTPerso += 11;
	}
};
void displayLinkedRunes(D_Inventory* _Inventory, sfRenderWindow* window)
{
	int decalageX = 592;
	int decalageYWar = 391;
	int decalageY = 131;
	int tailleCase = 84;
	int ecartCases = 124;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (_Inventory->player[j].weapon.rune[i].kind != None)
			{
				if (_Inventory->player[j].weapon.rune[i].kind == _Inventory->player[j].weapon.rune[i + 1].kind)
				{
					int tempPosY = decalageYWar + (j * ecartCases) + (tailleCase / 2) - 10;
					int tempPosX = decalageX + (i * ecartCases) + tailleCase;
					blitSprite(_Inventory->sprites.link, tempPosX, tempPosY, 0, window);
				}
			}
		}
	}
};
void displayDroppedRune(D_Inventory* _Inventory, sfRenderWindow* window)
{
	blitSprite(_Inventory->sprites.dropped, 0, 0, 0, window);
	sfVector2i pos;
	pos.x = 915;
	pos.y = 592;
	if (_Inventory->droppedRune.rarity == Uncommon)
	{
		blitSprite(_Inventory->sprites.rarity1, pos.x, pos.y, 0, window);
	}
	else if (_Inventory->droppedRune.rarity == Rare)
	{
		blitSprite(_Inventory->sprites.rarity2, pos.x, pos.y, 0, window);
	}
	else if (_Inventory->droppedRune.rarity == Legendary)
	{
		blitSprite(_Inventory->sprites.rarity3, pos.x, pos.y, 0, window);
	}
	else if (_Inventory->droppedRune.rarity == Mythical)
	{
		blitSprite(_Inventory->sprites.rarity4, pos.x, pos.y, 0, window);
	}
	if (_Inventory->droppedRune.kind == ATK)
	{
		blitSprite(_Inventory->sprites.runeATK, pos.x, pos.y, 0, window);
	}
	else if (_Inventory->droppedRune.kind == DEF)
	{
		blitSprite(_Inventory->sprites.runeDEF, pos.x, pos.y, 0, window);
	}
	else if (_Inventory->droppedRune.kind == CRIT)
	{
		blitSprite(_Inventory->sprites.runePO, pos.x, pos.y, 0, window);
	}

};
void displayFullInventory(D_Inventory* _Inventory, int _MousePosX, int _MousePosY, sfRenderWindow* window)
{
	displayInventory(_Inventory, window);
	displayStats(_Inventory, window);
	displayFeedBackInInventory(_Inventory, _MousePosX, _MousePosY, window);
	displayLinkedRunes(_Inventory, window);
	displayBagPage(_Inventory, window);
	//displayTrash(_Inventory, _MousePosX, _MousePosY, window);
	displayTempRune(_Inventory, _MousePosX, _MousePosY, window);
	displayLittleWindow(_Inventory, _MousePosX, _MousePosY, window);
};

void displayButtonInventory(D_Inventory* _Inventory, int _MousePosX, int _MousePosY, sfRenderWindow* window)
{
	sfVector2i mousePos = { _MousePosX, _MousePosY };
	int buttonX = 1920 - 100;
	int buttonY = 1080 - 100 - 100;
	int buttonH = 100;
	if (mousePos.x >= buttonX && mousePos.x <= buttonX + buttonH && mousePos.y >= buttonY && mousePos.y <= buttonY + buttonH)
	{
		blitSprite(_Inventory->sprites.buttonSelect, buttonX, buttonY, 0, window);
	}
	else
	{
		blitSprite(_Inventory->sprites.button, buttonX, buttonY, 0, window);
	};
}
void dropRune(D_Inventory* _Inventory)
{
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_Inventory->bag[j][i].kind == None && _Inventory->bag[j][i].rarity == Null)
			{
				_Inventory->bag[j][i].kind = rand() % 3;
				srand(time(NULL));
				int random = rand() % 100;
				printf("%d\n", random);
				if (random >= 0 && random <= 30)
				{
					_Inventory->bag[j][i].rarity = Uncommon;
				}
				else if (random >= 31 && random <= 60)
				{
					_Inventory->bag[j][i].rarity = Rare;
				}
				else if (random >= 61 && random <= 85)
				{
					_Inventory->bag[j][i].rarity = Legendary;
				}
				else if (random >= 86 && random <= 100)
				{
					_Inventory->bag[j][i].rarity = Mythical;
				};
				_Inventory->droppedRune = _Inventory->bag[j][i];
				_Inventory->RuneIsDropped = TRUE;
				return;
			};
		};
	};
};