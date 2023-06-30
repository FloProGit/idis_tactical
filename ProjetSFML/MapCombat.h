#ifndef __MAPCOMBAT_H__
#define __MAPCOMBAT_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////


#include <SFML/Graphics.h>
#include "windows.h"
#include "Vector_C.h"
#include"str.h"
#include"Utils.h"
#include "particle.h"
///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


#define  TOTVECTORCASE 5




///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////

enum PLACEMENTSTATE
{
	NullPlace,
	Perso1,
	Perso2,
	Perso3,
	Perso4,
	EnemyTypeA,
	enemyTypeB,
	enemyTypeC,
	enemyTypeD
};
typedef enum PLACEMENTSTATE E_PlacementState;


enum MAPSTATUS
{
	Unload,
	Loading,
	Load
};
//////////////////////////////
//STATUS OF LOADING MAP AFTER SELECT IN WORLD
//////////////////////////////
//-->Unload, "map is Unload all Data is Free"
//-->Loading 
//-->Load, "map Loading is end and DATA is Give to MapCombat"

/////////////////////////////
typedef enum MAPSTATUS E_MapStatus;


enum VALIDCASE
{
	NullCase,
	InvalidCase,
	ValidCase
};
//////////////////////////////
//STATUS OF LOADING MAP AFTER SELECT IN WORLD
//////////////////////////////
//-->Unload, "map is Unload all Data is Free"
//-->Loading 
//-->Load, "map Loading is end and DATA is Give to MapCombat"

/////////////////////////////
typedef enum VALIDCASE D_ValidCase;



enum ECASEMAP2D
{
	NullC2d,
	ValidC2d
};
//////////////////////////////
//STATUS OF LOADING MAP AFTER SELECT IN WORLD
//////////////////////////////
//-->Unload, "map is Unload all Data is Free"
//-->Loading 
//-->Load, "map Loading is end and DATA is Give to MapCombat"

/////////////////////////////
typedef enum ECASEMAP2D E_Case2D;

enum ONOFFCASE2D
{
	OFF,
	ON
};
//////////////////////////////
//STATUS OF LOADING MAP AFTER SELECT IN WORLD
//////////////////////////////
//-->Unload, "map is Unload all Data is Free"
//-->Loading 
//-->Load, "map Loading is end and DATA is Give to MapCombat"

/////////////////////////////
typedef enum ONOFFCASE2D E_OnOffCase2D;





enum STATETURNFIGHT
{
	NullSTF,
	Mouve,
	Att,
};
//////////////////////////////
//STATUS OF LOADING MAP AFTER SELECT IN WORLD
//////////////////////////////
//-->NullSTF,
//-->Mouve,
//-->Att,

/////////////////////////////
typedef enum STATETURNFIGHT E_StateSTF;
///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////





struct CASEMAP2D
{
	E_OnOffCase2D OnOffCase2D;
	E_Case2D StateCase;
	sfVector2f Pos;
	char isColored;
	char trap;
	char useForSpell;
};
//////////////////////////////
//contain DATA for CASE
/////////////////////////////
//-->E_OnOffCase2D OnOffCase2D
//-->sfVector2f VectorPos[5]
//-->int Ident;
////////////////////////////
typedef struct CASEMAP2D D_Map2D;
struct BLOCDATA
{
	D_ValidCase ValidCase;
	sfVector2f VectorPos[5];
	int Ident;
	int IDDecorts;
	E_PlacementState PlacementState;
	int IDShadow;
	int OpacityShadow;
};
//////////////////////////////
//contain DATA for CASE
/////////////////////////////
//-->sfVector2f VectorPos[5]
//-->int Ident;
////////////////////////////
typedef struct BLOCDATA D_Bloc;


struct BattleBackGround
{
	sfSprite* clouds;
	sfSprite* backGround;
	sfSprite* Yclouds;
	sfSprite* YbackGround;
	sfSprite* Bclouds;
	sfSprite* BbackGround;
	sfSprite* Rclouds;
	sfSprite* RbackGround;
	sfVector2f pos1;
	sfVector2f pos2;
	float speed;
};
typedef struct BattleBackGround A_BackGround;

struct MAPCOMBATDATA
{
	sfVector3i Size;
	D_Bloc ***CaseMap;
	D_Map2D **Map2D;
	sfVector2i CellSize;
	int TotalBlocSprite;
	E_StateSTF StateSTF;

	A_PARTICLES particles;
	A_BackGround background;
};
///////////////////////////
//Contain DATA of General MapCombat
//////////////////////////
//-->sfVector3i Size
//-->D_Bloc ***CASE "3D TABLE"
//--> sfVector2i CellSize;
///////////////////////////////////////
typedef struct MAPCOMBATDATA D_MapCombat;


///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////


//UTILS

void Create_Empty_MapCombat_From_Data_Lvl(D_MapCombat* Map);
int CalculScalaire(sfVector2i Mouse, D_Bloc * _case);
void Put_Data_On_MapCombat(D_MapCombat * Map, D_Str* _saveName);
void Createmap2d(D_MapCombat* Map);
//INIT
void INITMapCombat(D_MapCombat * Map, D_Str* _saveName);
void LoadBackgroundsSprite(D_MapCombat* map);
void BackgroundUpdate(D_MapCombat* Map, float dt);
void BackgroundDisplay(D_MapCombat* Map, sfRenderWindow* window);
void VectorCase(D_MapCombat* Map, sfVector2f Camera);

void CurrentCaseSelect(D_MapCombat* Map, sfVector2i Mouse, sfVector2i * caseSelect);

void ConvertMapto2DMap(D_MapCombat* Map, sfVector2f Camera);

//UPDATE


#endif // !__MAPCOMBAT_H__

