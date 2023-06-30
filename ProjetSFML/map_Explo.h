#ifndef _MAP_EXPLO_H_
#define _MAP_EXPLO_H_

#include <SFML/Graphics.h>
#include "Utils.h"
#include "str.h"
//inclure uniquement les INCLUDES NESSAICAIRE DANS LE .C et H.
// si par exemple on a juste besoins de faire des calcul alors 

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////

#define exemple
#define NB_BALISES 22
#define TRUE 1
#define FALSE 0

///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////
enum playerState
{
	Grand,
	Petit,
	Pause
};
///////////////
typedef enum playerState A_PlayerState;
///////////////////////////////////////////////////////////
////STRUCT 
///////////////////////////////////////////////////////////
struct BALISE
{
	sfVector2i Pos;
	char isUnlocked;
	D_Str MapLVL;
};
////////////////////////////
//Struct contenant les données d'une Balise
////////////////////////////
typedef struct BALISE D_Balise;
////////////////////////////
struct PERSO_EXPLO_D
{
	sfVector2f Pos;
	int currentBalise;
	int lastBalise;
	float speed;
	A_PlayerState state;
	float timer;
	int timeToChange;
};
//////////////////////////
//Struct contenant les données du personnage 
////////////////////////
typedef struct PERSO_EXPLO_D D_PersoExplo;
//////////////////////////
struct SPRITES
{
	sfSprite* background;
	sfSprite* WorldMap1;
	sfSprite* WorldMap2;
	sfSprite* WorldMap3;
	sfSprite* baliseLocked;
	sfSprite* curseurPetit;
	sfSprite* curseurGrand;
	sfSprite* curseur;
};
///////////////////////////
//Struct contenant tout les sprites de la map 
///////////////////////////
typedef struct SPRITES D_Sprites;
////////////////STRUCT DE LA MAP EXPLO


struct MAP_EXPLO
{
	D_PersoExplo perso;
	D_Balise balises[NB_BALISES];
	D_Sprites sprites;
	char balisesMax; // Nombre de balises créee, utlisée dans les boucles for parcourant la table
	char isDisplayingInventory; // Booléeen retourant TRUE si l'inventaire est ouvert, FALSE si il est fermé. Active les fonctions d'inventaire
	char currentWorld;
};
/////////////////
//-->D_PersoExplo perso;
//-->D_Balise balises[NB_BALISES];
//-->D_Sprites sprites;
//-->char balisesMax;
/////////////////////////////////
typedef struct MAP_EXPLO D_MapExplo;


// explication Courte et bréve
//du fonctionement de la Strcut(ex : Struct Contain Data for "Player".
////////////////////////////
//-->sfVector2f CameraE;
//-->int INTE;
//-->float FLOATE;
//-->E_Name TESTENUM;
////////////////////////////////



							 ///////////////////////////////////////////////////////////
							 ///------------------------PROTOTYPES-------------------///
							 ///////////////////////////////////////////////////////////



							 // void PROTOTYPE DE FONCTION(ARG); 

							 ////UTILS////
float Lerp(float _pointA, float _pointB, float _t);
void displayText(char* _sContenu, sfText* _text, int posX, int posY, sfRenderWindow* _window);
// mettre ici les fonctions qui sont utils dans le Fichier EXEMPLE.c

////INIT////
void initWorld(D_MapExplo* _MapExplo);
///ici Mettre les Fonction Uniquement executer a l'init ou a un certaint moment


////UPDATE////
void updateWorld(D_MapExplo* _MapExplo);

// mettre ici les fonctions qui sont utils en update par exemple un PROJECT.c

//EVENT
void inputWorld(D_MapExplo* _MapExplo, sfEvent _event);
void eventOpenInventory(D_MapExplo* _MapExplo, int _mousePosX, int _mousePosY);
//Display
void displayWorld(D_MapExplo* _MapExplo, sfRenderWindow* window);
#endif
