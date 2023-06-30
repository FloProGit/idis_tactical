#ifndef __WORLD_H__
#define __WOLRD_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////


#include "GamData.h"
#include"MapCombat.h"
#include "map_Explo.h"
#include "inventory.h"
#include "particle.h"
#include "Sound.h"



///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////
#define TRUE 1
#define FALSE 0


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////


enum STATEWORLD
{
	NullSW,
	OnWorld,
	OptionW,
	MapIsSelected,
	EndFightWin,
	EndFightLoose
};
/////////////////////////////////
// STATE USE WHEN YOU ARE IN WORLD MAP 
////////////////////////////////
//--> NullSW //When you are in Menu is A Default State of World Map
//--> OnWorld // When You Browse the World Map
//--> Option // When the Option Menu Is Selected
//--> MapIsSelected // When you go on Map Combat ("launch Destroy" Sprite World Map")
typedef enum STATEWORLD E_StateWorld;


///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////










struct DATAWORLD
{
	sfVector2f CameraWM;
	D_Str SaveName;
	E_MapStatus StatusMapCombat;
	E_StateWorld StatusWorldMap;
	D_MapExplo MapExplo;
	D_Inventory Inventory;
	A_PARTICLES Particles;
};
///////////////////////////////////
//contain all DATA for Project
///////////////////////////////////
//-->sfVector2f CameraWM;
//-->D_Str SaveName;
//-->E_MapStatus StatusMapCombat;
//-->E_StateWorld StatusWorldMap;
////////////////////////////////
typedef struct DATAWORLD D_WorldMap;


///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////
void LAUNCH_D_PROJET(GameData * GD, SD_GameSound* GameSound);
void INITWORLD(D_WorldMap* WorldMap, GameData * GD, SD_GameSound* GameSound);
void UPDATEPROJECT(D_WorldMap* WorldMap, GameData * GD, SD_GameSound* GameSound);

#endif // !__WOLRD_H__


