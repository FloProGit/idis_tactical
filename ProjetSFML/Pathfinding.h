#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include"MapCombat.h"
#include "windows.h"
#include "Perso.h"
#include "Enemy.h"
///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////
enum  TYPEFILTERS
{
	TargetPlayer,
	TargetEnemy,
	MouvePLayer,
	MouverEnemy
};
typedef enum  TYPEFILTERS E_Target;

enum  TYPEFILLING
{
	ATKFull,
	ATKCross,
	NOATK

};

typedef enum  TYPEFILLING E_Atk;


enum  TYPEZONE
{
	Single,
	Cross,
	AOE,
	NOZONE
};
typedef enum  TYPEFILLING E_Zone;







enum STATECASE
{
	Unavailable,
	Available
};
//////////////////////////
//
/////////////////////////
//-->unavailable
//-->available
////////////////////////
typedef enum STATECASE E_StateCase;
///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////


struct FILLING
{

	E_Target Target;
	E_Atk ATK;
	E_Zone Zone;
};
typedef struct FILLING D_Filling;


struct CASEPATH
{
	E_StateCase State;
	char isColored;
	int nbr;
};
////////////////////////
//
////////////////////////
//-->E_StateCase StateCase
//-->int nbr
////////////////////////
typedef  struct CASEPATH D_Casepath;




struct MAPPATH
{
	sfVector2i SizeMap;
	D_Casepath **MapP;
	D_Filling Filling;

	int **TabReturn;
};
////////////////////////////
//
///////////////////////////
//-->D_Casepath **MapP
//////////////////////////
typedef struct MAPPATH D_MapPath;

///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////
void CleanMap(D_MapPath* Map);
void CreatemapPath(D_MapPath* Map, sfVector3i MapSize);
void UpdateMapPath(D_MapPath* MapPath, D_Map2D **Map2D);
void CleanMap2DandPath(D_MapPath* Map, D_Map2D **Map2D);
int**  GeneralFillingAndPath(D_Filling *Filling, D_MapPath* MapPath, D_Map2D **map, M_Enemy *Enemy, D_Perso *Perso, sfVector2i Currentcase, int Turn, int PoSpell, int FilingSpell, int WhoPlay);
#endif // !__PATHFINDING_H__


