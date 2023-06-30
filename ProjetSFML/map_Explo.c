#include "map_Explo.h"
/////////////////UTILS/
float Lerp(float _pointA, float _pointB, float _t)
{
	return _pointA + _t * (_pointB - _pointA);
}
sfView* view;
void initBalise(D_MapExplo* _MapExplo, int nb_Balise, int _x, int _y, char _isUnlocked, char Name[100])
{
	_MapExplo->balisesMax++;
	_MapExplo->balises[nb_Balise].Pos.x = _x;
	_MapExplo->balises[nb_Balise].Pos.y = _y;
	_MapExplo->balises[nb_Balise].isUnlocked = _isUnlocked;
	strcpy(_MapExplo->balises[nb_Balise].MapLVL.Name, Name);
};
//////////////////////
void initPerso(D_MapExplo* _MapExplo)
{
	_MapExplo->perso.currentBalise = 0;
	_MapExplo->perso.Pos.x = _MapExplo->balises[_MapExplo->perso.currentBalise].Pos.x;
	_MapExplo->perso.Pos.y = _MapExplo->balises[_MapExplo->perso.currentBalise].Pos.y;
	_MapExplo->perso.speed = 0.005f;
	_MapExplo->perso.timer = 0;
	_MapExplo->perso.timeToChange = 2;

};
///////////////////////
void initWorld(D_MapExplo* _MapExplo)
{
	printf("LAUNCH_D_PROJET %d\n", _MapExplo);

	_MapExplo->balisesMax = 0;
	_MapExplo->isDisplayingInventory = FALSE;
	///Monde 1
	initBalise(_MapExplo, 0, 260, 439, TRUE, "LVLMAP/Map1/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 1, 356, 746, FALSE, "LVLMAP/Map2/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 2, 634, 660, FALSE, "LVLMAP/Map3/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 3, 745, 407, FALSE, "LVLMAP/Map4/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 4, 1034, 355, FALSE, "LVLMAP/Map5/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 5, 1143, 556, FALSE, "LVLMAP/Map6/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 6, 980, 708, FALSE, "LVLMAP/Map7/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 7, 1242, 816, FALSE, "LVLMAP/Map8/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 8, 1427, 559, FALSE, "LVLMAP/Map9/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 9, 1674, 412, FALSE, "LVLMAP/Map10/map.txt");//////////////////MODIFY<--------------------------------
	///Monde 2
	initBalise(_MapExplo, 10, 213, 730, FALSE, "LVLMAP/Map11/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 11, 301, 378, FALSE, "LVLMAP/Map12/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 12, 584, 446, FALSE, "LVLMAP/Map13/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 13, 756, 721, FALSE, "LVLMAP/Map14/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 14, 1127, 753, FALSE, "LVLMAP/Map15/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 15, 1034, 498, FALSE, "LVLMAP/Map16/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 16, 1262, 321, FALSE, "LVLMAP/Map17/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 17, 1461, 538, FALSE, "LVLMAP/Map18/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 18, 1669, 721, FALSE, "LVLMAP/Map19/map.txt");//////////////////MODIFY<--------------------------------
	//Monde 3
	initBalise(_MapExplo, 19, 209, 626, FALSE, "LVLMAP/Map20/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 20, 867, 599, FALSE, "LVLMAP/Map21/map.txt");//////////////////MODIFY<--------------------------------
	initBalise(_MapExplo, 21, 1516, 548, FALSE, "LVLMAP/Map22/map.txt");//////////////////MODIFY<--------------------------------

	_MapExplo->perso.lastBalise = 0;
	FILE *ptrFichier;
	if (!(ptrFichier = fopen("SAVE/LastLevel.txt", "rt")))
	{
		printf("Erreur d'acces au fichier...\n");
		exit(EXIT_FAILURE);
	}
	fscanf(ptrFichier, "%d", &_MapExplo->perso.lastBalise);
	fclose(ptrFichier);

	for (int i = 0; i < _MapExplo->perso.lastBalise; i++)
	{
		_MapExplo->balises[i].isUnlocked = 1;
	}

	_MapExplo->sprites.background = LoadSprite("IMG/MAP/background.png", 0, 0, 0);
	_MapExplo->sprites.WorldMap1 = LoadSprite("IMG/MAP/WorldMap1.png", 0, 0, 0);
	_MapExplo->sprites.WorldMap2 = LoadSprite("IMG/MAP/WorldMap2.png", 0, 0, 0);
	_MapExplo->sprites.WorldMap3 = LoadSprite("IMG/MAP/WorldMap3.png", 0, 0, 0);
	_MapExplo->currentWorld = 1;
	_MapExplo->sprites.baliseLocked = LoadSprite("IMG/MAP/baliseLocked.png", 1, 0, 0);
	_MapExplo->sprites.curseurPetit = LoadSprite("IMG/PLAYER/Curseur/curseurPetit.png", 1, 0, 0);
	_MapExplo->sprites.curseurGrand = LoadSprite("IMG/PLAYER/Curseur/curseurGrand.png", 1, 0, 0);
	_MapExplo->sprites.curseur = LoadSprite("IMG/PLAYER/Curseur/curseur.png", 1, 0, 0);
	initPerso(_MapExplo);
};
///////////////Update 
void updateWorld(D_MapExplo* _MapExplo)
{
	_MapExplo->perso.Pos.x = Lerp(_MapExplo->perso.Pos.x, _MapExplo->balises[_MapExplo->perso.currentBalise].Pos.x, _MapExplo->perso.speed);
	_MapExplo->perso.Pos.y = Lerp(_MapExplo->perso.Pos.y, _MapExplo->balises[_MapExplo->perso.currentBalise].Pos.y, _MapExplo->perso.speed);
	_MapExplo->perso.timer += _MapExplo->perso.speed;
	if (_MapExplo->perso.timer >= _MapExplo->perso.timeToChange)
	{
		if (_MapExplo->perso.state == Petit)
		{
			_MapExplo->perso.state = Grand;
			_MapExplo->perso.timer = 0;
		}
		else if (_MapExplo->perso.state == Grand)
		{
			_MapExplo->perso.state = Petit;
			_MapExplo->perso.timer = 0;
		}
		else if (_MapExplo->perso.state == Pause)
		{
			_MapExplo->perso.state = Grand;
			_MapExplo->perso.timer = 0;
		};
	};
};
///////////////Event 
void inputWorld(D_MapExplo* _MapExplo, sfEvent _event)
{

	if (_event.key.code == sfKeyLeft)
	{
		if (_MapExplo->perso.currentBalise > 0)
		{
			_MapExplo->perso.currentBalise--;
			_MapExplo->perso.state = Pause;
		}
		if (_MapExplo->perso.currentBalise <= 9)
		{
			_MapExplo->currentWorld = 1;
		};
		if (_MapExplo->perso.currentBalise > 9 && _MapExplo->perso.currentBalise < 19)
		{
			_MapExplo->currentWorld = 2;
		}
		else if (_MapExplo->perso.currentBalise >= 19)
		{
			_MapExplo->currentWorld = 3;
		}
		if (_MapExplo->perso.currentBalise == 9)
		{
			_MapExplo->perso.Pos.x = 1674;
			_MapExplo->perso.Pos.y = 412;
		}
		else if (_MapExplo->perso.currentBalise == 18)
		{
			_MapExplo->perso.Pos.x = 1669;
			_MapExplo->perso.Pos.y = 721;
		}
	}
	if (_event.key.code == sfKeyRight)
	{
		if (_MapExplo->perso.currentBalise < _MapExplo->balisesMax - 1 && _MapExplo->balises[_MapExplo->perso.currentBalise + 1].isUnlocked == TRUE)
		{
			_MapExplo->perso.currentBalise++;
			_MapExplo->perso.state = Pause;
			if (_MapExplo->perso.currentBalise <= 9)
			{
				_MapExplo->currentWorld = 1;
			};
			if (_MapExplo->perso.currentBalise > 9 && _MapExplo->perso.currentBalise < 19)
			{
				_MapExplo->currentWorld = 2;
			}
			else if (_MapExplo->perso.currentBalise >= 19)
			{
				_MapExplo->currentWorld = 3;
			}
			if (_MapExplo->perso.currentBalise == 10)
			{
				_MapExplo->perso.Pos.x = 123;
				_MapExplo->perso.Pos.y = 730;
			}
			else if (_MapExplo->perso.currentBalise == 19)
			{
				_MapExplo->perso.Pos.x = 209;
				_MapExplo->perso.Pos.y = 626;
			}
		}
	}
	if (_event.key.code == sfKeyUp)
	{
		if (_MapExplo->perso.currentBalise != 21)
		{
			_MapExplo->balises[_MapExplo->perso.currentBalise + 1].isUnlocked = TRUE;
		}
		FILE *ptrFichier;
		if (!(ptrFichier = fopen("SAVE/LastLevel.txt", "wt"))) {
			printf("Erreur d'acces au fichier...\n");
			exit(EXIT_FAILURE);
		}
		if (_MapExplo->perso.currentBalise < 21 && _MapExplo->perso.currentBalise + 1 >= _MapExplo->perso.lastBalise)
		{
			int numéro = _MapExplo->perso.lastBalise + 1;
			fprintf(ptrFichier, "%d", numéro);
			_MapExplo->perso.lastBalise = numéro;
		}
		else
		{
			fprintf(ptrFichier, "%d", _MapExplo->perso.lastBalise);
		}
		fclose(ptrFichier);
	}
	if (_event.key.code == sfKeyI)
	{
		if (_MapExplo->isDisplayingInventory == FALSE)
		{
			_MapExplo->isDisplayingInventory = TRUE;
		}
		else if (_MapExplo->isDisplayingInventory == TRUE)
		{
			_MapExplo->isDisplayingInventory = FALSE;
		};
	}
	if (_event.key.code == sfKeyZ)
	{


		sfView_zoom(view, 0.5);
	};
};
void eventOpenInventory(D_MapExplo* _MapExplo, int _mousePosX, int _mousePosY)
{
	sfVector2i mousePos = { _mousePosX,_mousePosY };
	int buttonX = 1920 - 100;
	int buttonY = 1080 - 100 - 100;
	int buttonH = 100;
	if (mousePos.x > buttonX && mousePos.x <= buttonX + buttonH && mousePos.y > buttonY && mousePos.y < buttonY + buttonH)
	{
		_MapExplo->isDisplayingInventory = TRUE;
	}
};
//////////////Display 
void displayCurseur(D_MapExplo* _MapExplo, sfRenderWindow* window)
{
	view = sfRenderWindow_getView(window);
	if (_MapExplo->perso.state == Petit)
	{
		blitSprite(_MapExplo->sprites.curseurPetit, _MapExplo->perso.Pos.x, _MapExplo->perso.Pos.y - 6, 0, window);
	}
	else if (_MapExplo->perso.state == Grand)
	{
		blitSprite(_MapExplo->sprites.curseurGrand, _MapExplo->perso.Pos.x, _MapExplo->perso.Pos.y - 6, 0, window);
	}
	else if (_MapExplo->perso.state == Pause)
	{
		blitSprite(_MapExplo->sprites.curseurPetit, _MapExplo->perso.Pos.x, _MapExplo->perso.Pos.y - 6, 0, window);
	}
	blitSprite(_MapExplo->sprites.curseur, _MapExplo->perso.Pos.x, _MapExplo->perso.Pos.y - 6, 0, window);
};
void displayWorld(D_MapExplo* _MapExplo, sfRenderWindow* window)
{
	int BalisestoDisplayWorld;
	blitSprite(_MapExplo->sprites.background, 0, 0, 0, window);
	if (_MapExplo->currentWorld == 1)
	{
		blitSprite(_MapExplo->sprites.WorldMap1, 0, 0, 0, window);
		BalisestoDisplayWorld = 10;
	}
	else if (_MapExplo->currentWorld == 2)
	{

		blitSprite(_MapExplo->sprites.WorldMap2, 0, 0, 0, window);
		BalisestoDisplayWorld = 19;
	}
	else if (_MapExplo->currentWorld == 3)
	{
		blitSprite(_MapExplo->sprites.WorldMap3, 0, 0, 0, window);
		BalisestoDisplayWorld = 22;
	};

	//Balises 
	for (int i = 0; i < BalisestoDisplayWorld; i++)
	{
		if (_MapExplo->balises[i].isUnlocked == FALSE)
		{
			blitSprite(_MapExplo->sprites.baliseLocked, _MapExplo->balises[i].Pos.x, _MapExplo->balises[i].Pos.y, 0, window);
		}
	}
	displayCurseur(_MapExplo, window);
};