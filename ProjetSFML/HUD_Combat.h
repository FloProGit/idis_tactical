#ifndef __HUD_Combat_H__
#define __HUD_Combat_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include <SFML/Graphics.h>
#include "FightSystem.h"
#include "GamData.h"
#include "System.h"
#include "Enemy.h"
#include "MapCombat.h"


//inclure uniquement les INCLUDES NESSAICAIRE DANS LE .C et H.
// si par exemple on a juste besoins de faire des calcul alors 

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////

struct SPELLHUD
{
	//Pour le HUD 
	int HudWidth;
	int HudHeight;
	int x;
	int y;
};


////////////////////////////
// Positionement de l'HUD en Combat
////////////////////////////
//-->int HudWidth;
//-->int HudHeight;
//-->int x;
//-->int y;
////////////////////////////////
typedef struct SPELLHUD  D_SpellHud;// "D_" signifie que c'est une strcut de donné " DATA_ = D_ "


struct SPELLHUDSPRITE
{
	sfSprite*  HudSpellSprite[4][4][2];
	//Bouton pour changer de tour 
	sfSprite* changeTurn;
	sfSprite* moove;
	//
	sfSprite* HudPlayers;
	sfSprite* HudRedSquare;
	sfSprite* displayWindow;

	sfSprite* HUDCombat;
	sfSprite* portraits[4];
	sfSprite* emptyHealth;
	sfSprite* emptyHealthEnemy;
	sfSprite* healthGauge;
	sfSprite* healthGauge2;
	sfSprite* alliedCursor;

	sfSprite* Spell1InUse;
	sfSprite* Spell2InUse;
	sfSprite* Spell3InUse;
	sfSprite* Spell4InUse;
};
////////////////////////////
// Rassemble TOUS les sprites lié a L'HUD en combat 
////////////////////////////
////////////////////////////
typedef struct SPELLHUDSPRITE  A_FightHud;


							 ///////////////////////////////////////////////////////////
							 ///------------------------PROTOTYPES-------------------///
struct TEXTE
{
	sfFont* font;
	sfText* text;
};
//////////////
//sfFont* font -> ajout de la font
//sfText* text -> ajout du text
//Struct contenant le sfFont et le sfText nécessaire a afficher du texte 
typedef struct TEXTE A_Texte;						 ///////////////////////////////////////////////////////////



struct HUDCOMBAT
{
	
	D_SpellHud HudCombat[4];
	D_SpellHud Hud;
	D_SpellHud infoWindow;
	D_SpellHud Portraits;
	D_SpellHud PortraitIsPlaying;
	D_SpellHud passTurn;
	D_SpellHud useMoove;
	A_FightHud AllSprite;
	A_Texte fontStats;
	float decYcursor;
	float cursorSpeed;
	char spellNames[4][4][150];
	char spellDescription[4][4][250];
	char spellCost[4][4][50];
	char spellPO[4][4][50];
	char spellArea[4][4][50];
	char spellDamage[4][4][50];
	sfColor colorPerso[4];
	char infoWindowIsDisplaying;
	char playerWindowDisplaying;
	char SpellIsDisplaying;
	char isDisplayingEnemyLife;
	char enemyDisplaying;
	
};
//////////////////////////
//
/////////////////////////
//--> 
///////////////////////////////////
typedef struct HUDCOMBAT  D_HudCombat;
////INIT////
void InitHud(D_SpellHud* _SpellHud, A_FightHud* AllSprite, D_HudCombat* hud);
///ici Mettre les Fonction Uniquement executer a l'init ou a un certaint moment
void initTexte(D_HudCombat * _Stats);

////UPDATE////
//Event in Update
void ClickHud(D_SpellHud* _SpellHud, DataSystem* DT, D_FightSystem* fightSystem, D_Perso* perso);
void ChangeTurn(DataSystem* DT, D_FightSystem* fightSystem, D_HudCombat* hud, E_StateSTF *STATE);
void ClickMoove(DataSystem* DT, D_FightSystem* fightSystem, D_HudCombat* hud, D_Perso* perso);
void updateDisplayWindow(D_HudCombat* hud, D_FightSystem* fightSystem,D_Perso* perso, int _MousePosX, int _MousePosY);
void updateLifeGaugeEnemy(D_HudCombat* hud, sfVector2i CaseSelect, M_Enemy* Enemy);


//
//void DisplayHud(D_SpellHud* _SpellHud, A_FightHud* AllSprite, D_FightSystem* fightSystem, DataSystem* DT, D_InCombat* combat);
void DisplayPassTurn(D_HudCombat* hud, DataSystem* DT);
void DisplayHud(D_SpellHud* _SpellHud, A_FightHud* AllSprite, D_FightSystem* fightSystem, DataSystem* DT, D_Perso* perso);
void DisplayHudPlayers(D_HudCombat* hud, DataSystem* DT, D_FightSystem* fightSystem, D_Perso* perso, sfVector2f camera);
void DisplayStatsHud(D_Perso* _perso, D_HudCombat* _Stats, DataSystem* DT);
void DisplayMoove(D_HudCombat* hud, DataSystem* DT);
void displayInfoWindow(D_HudCombat* hud,D_Perso* perso, D_FightSystem* fightsystem, sfRenderWindow* window);
void DisplayEnemyLife(D_HudCombat* hud, M_Enemy* enemy, sfVector2f Camera, sfRenderWindow* window);
void DisplaySpellInUse(D_HudCombat* hud, D_Perso* perso, DataSystem* DT);
// mettre ici les fonctions qui sont utils en update par exemple un PROJECT.c


#endif // !__MODELTYPE_H__



