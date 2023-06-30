#ifndef __FIGHT_SYSTEM_H__
#define __FIGHT_SYSTEM_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include <SFML/Graphics.h>
#include "Perso.h"
#include"MapCombat.h"
#include"Pathfinding.h"
#include "Enemy.h"
#include "System.h"
#include "Spell.h"

//inclure uniquement les INCLUDES NESSAICAIRE DANS LE .C et H.
// si par exemple on a juste besoins de faire des calcul alors 

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////

#define MAPLINE 10
#define MAPCOLUMN 10
#define NBSPELL 4


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////

struct TURN
{
	int turnPlayer;
};
/////////////////////////////////
// Contiens les variables du tous du joueur 
////////////////////////////////
//-->int turnPlayer;
////////////////////////////////
typedef struct TURN D_Turn;


// "D_" signifie que c'est une strcut de donné " DATA_ = D_ "

struct PATHFIDING
{
	int **chemin;
	int **tabPo;
	int pathFidingPersoX;
	int pathFidingPersoY;
	int pathFidingSpellX;
	int pathFidingSpellY;
};
////////////////////////////
//Donné utilisé par le pathFiding
////////////////////////////
//-->int chemin[MAPLINE][MAPCOLUMN];
//-->int tabPo[MAPCOLUMN][MAPLINE];
//-->int pathFidingPersoX; Destination du personnage
//-->int pathFidingPersoY;
//-->int pathFidingSpellX;
//-->int pathFidingSpellY;
////////////////////////////////
typedef struct PATHFIDING D_PathFiding;

struct SPRITECASE
{
	//Utile au pathfiding
	sfSprite* PathFidingHori;
	sfSprite* PathFidingVerti;

	//Case de différente couleur pour le déplacement et pour lattaque 
	sfSprite* isoGreen;
	sfSprite* isoRed;
};
////////////////////////////
//Sprite utilisé par le pathFiding
////////////////////////////
//-->sfSprite* PathFidingHori;
//-->sfSprite* PathFidingVerti;
//-->sfSprite* isoGreen;
//-->sfSprite* isoRed;
////////////////////////////////
typedef struct SPRITECASE A_Case;

///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////

struct FIGHT_SYSTEM
{
	A_Case caseSprite;



	D_PathFiding pathFiding;
	D_Turn turn;
	int CurrentSelectSpell;
	sfVector2i CaseSelect;

	int mapIscreate;
	sfVector2i SizeMapF;

	int spellAnimUse;
	int CurrentSpellUse;

	int caseX;
	int caseY;
};

//////////////////////////
//
/////////////////////////
//--> 
///////////////////////////////////
typedef struct FIGHT_SYSTEM  D_FightSystem;
////INIT////

///ici Mettre les Fonction Uniquement executer a l'init ou a un certaint moment
void InitFightSystem(D_FightSystem* fightSystem, D_MapCombat* Map);

void resetAttackMode(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map);
void MouveSystem(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, D_MapPath* MapPath, D_Enemy * Enemy, sfVector2i Currentcase);
void FightSystem(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, D_MapPath* MapPath, M_Enemy * Enemy, sfVector2i Currentcase);
void MoovePlayer(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, sfVector2i Currentcase, sfVector2i Mouse);
void Attack(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map, D_MapCombat *MapCombat, sfVector2i Mouse, M_Enemy *Enemy, sfVector2i Currentcase, SD_GameSound* GameSound);

////UPDATE////
//Event in Update
void PersoDead(D_Perso* perso);
//
void UpdtateStateAttMouve(D_Perso* perso, E_StateSTF* State, D_FightSystem* fightSystem);
void MooveEnemiesDead(M_Enemy *Enemy);
void UpdateFightSystem(D_FightSystem* fightSystem, D_Perso* perso, D_Map2D **map);
void UpdateMapFight(D_FightSystem* fightSystem, D_Map2D **map);
int ItsATrap(D_Map2D **map, D_Perso* perso, M_Enemy *Enemy, D_FightSystem* fightSystem, SD_GameSound* GameSound);

void selectPlayer(sfVector2i CaseSelect, D_Perso* perso, D_FightSystem* fightsystem, sfVector2i Mouse);


// mettre ici les fonctions qui sont utils en update par exemple un PROJECT.c
void SpellRegroup(D_Map2D **map, D_FightSystem* fightSystem, D_Perso* perso, M_Enemy *Enemy, sfVector2i Currentcase, int mode, int nb);


#endif // !__MODELTYPE_H__



