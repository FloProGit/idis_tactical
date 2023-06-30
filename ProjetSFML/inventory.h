#ifndef _INVENTORY_H_
#define _INVENTORY_H_
///////Include///////
#include <SFML/Graphics.h>
#include "Utils.h"

//////Enums///////
enum BAGSTATE
{
	Bag,
	Stats,
	Nothing
};
///////////////////
//Dans quel etat de l'inventaire se trouve le joueur 
///////////////////
typedef BAGSTATE;
enum RUNERARITY
{
	Uncommon,
	Rare,
	Legendary,
	Mythical,
	Null
};
////////////////////////////
// différentes raretée des Runes ( Uncommon = 0, Mythical = 3)
////////////////////////////
typedef RUNERARITY;
////////////////////////////////
enum RUNEKIND
{
	ATK,
	DEF,
	CRIT,
	None
};
////////////////
//Différents types de Runes (ATK = 0, PO = 3)
////////////////
typedef RUNEKIND;
///////////////
enum isLinked
{
	LinkedATK,
	LinkedDEF,
	LinkedCrit,
	NoneLinked
};
////////////////
//Enum pour déterminer de quel bonus de synergie dispose le player
////////////////
typedef isLinked;
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////
struct RUNE_D
{
	 RUNEKIND kind;
	 RUNERARITY rarity;
};
/////////////
//Rune de base, RUNEKIND + RARITY 
/////////////
typedef struct RUNE_D RUNE;
/////////////
struct WEAPON
{
 RUNE rune[3];
};
/////////////////////////
//Struct de l'arme qui contient 3 Runes 
////////////////////////
typedef struct WEAPON WEAPON_D;
/////////////////////////
/////////////////////////
struct PERSOCOMBAT_D
{
	int pv;
	int pa;
	int pm;
	int atk;
	int boostAtk;
	int def;
	int boostDef;
	int crit;
	int boostCrit;
	isLinked link;
	WEAPON_D weapon;
};
///////////////////////
//Struct contenant les stats des persos individuellement
//////////////////////
typedef struct PERSOCOMBAT_D D_PersoCombat;
/////////////////////
////////////////
//Struct contenant les 4 personnages; a envoyé au Z
////////////////
////////////////
struct SPRITES_D
{
	sfSprite* inventory;
	sfSprite* inventoryBag;
	sfSprite* inventoryBagSelected;
	sfSprite* runeATK;
	sfSprite* runeDEF;
	sfSprite* runePO;
	sfSprite* rarity1;
	sfSprite* rarity2;
	sfSprite* rarity3;
	sfSprite* rarity4;
	sfSprite* feedBackCommon;
	sfSprite* feedBackRare;
	sfSprite* feedBackLegendary;
	sfSprite* feedBackMythical;
	sfSprite* feedBackSelected;
	sfSprite* dropped;
	sfSprite* link; 
	sfSprite* littleWindow;
	sfSprite* button;
	sfSprite* buttonSelect;
	sfSprite* trash;
	sfSprite* trashSelected;
};
//////////////
//Struct contenant tout les sprites nécéssaires a l'inventaire
//////////////
typedef struct SPRITES_D Sprites;
////////////////
struct TEXT
{
	sfFont* font;
	sfText* text;
};
//////////////
//Struct contenant le sfFont et le sfText nécessaire a afficher du texte 
typedef struct TEXT A_Text;
//////////////STRUCT INVENTORY///////////
struct INVENTORY
{
	D_PersoCombat player[4];
	Sprites sprites;
	RUNE bag[5][6];
	RUNE tempRune;
	RUNE droppedRune;
	A_Text fontStats;
	BAGSTATE inventoryState;
	char tempRuneIsSelected;
	char teamMemberSelected;
	char RuneSelected;
	char LineSelected;
	char columnSelected;
	char RuneIsDropped;
	char littleWindowIsDisplaying;
	RUNE explicatedRune;
	float timer;
};
///////
typedef struct INVENTORY D_Inventory;
//Struct " globale " de l'inventaire, remplace GAMEDATA 
///////
//Prototype de Fonctions 
//////////////////////
//////////////-----INIT
void initInventory(D_Inventory* _inventory);
/////////////////////----UPDATE
void updateSwitchInventoryPage(D_Inventory* _Inventory, int _mousePosX, int _mousePosY);
void updateLittleWindow(D_Inventory* _inventory, int _mousePosX, int _mousePosY);
////////////////////-----EVENT
void releaseRune(D_Inventory* _inventory, int _mousePosX, int _mousePosY);
void selectRuneInInventory(D_Inventory* _inventory, int _mousePosX, int _mousePosY);
void selectRuneInBag(D_Inventory* _inventory, int _mousePosX, int _mousePosY);
void updateTeamStats(D_Inventory* _inventory);
void dropRune(D_Inventory* _Inventory);
void eventSwitchInventoryPage(D_Inventory* _Inventory, int _mousePosX, int _mousePosY);
/////////////////------DISPLAY
void displayDroppedRune(D_Inventory* _Inventory, sfRenderWindow* window);
void displayFullInventory(D_Inventory* _Inventory, int _MousePosX, int _MousePosY, sfRenderWindow* window);
void displayButtonInventory(D_Inventory* _Inventory, sfRenderWindow* window);
#endif
