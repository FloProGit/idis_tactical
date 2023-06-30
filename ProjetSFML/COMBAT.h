#ifndef __COMBAT_H__
#define __COMBAT_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include"World.h"
#include"Perso.h"
#include"Pathfinding.h"
#include "HUD_Combat.h"
#include "FightSystem.h"
#include "I_A.h"
#include"Enemy.h"
#include"inventory.h"
#include"Display.h"
#include"Sound.h"

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////


struct INCOMBATDATA
{
	A_AllSprites AllSprite;
	sfVector2f CameraMC;
	D_MapCombat MapCombat;
	D_MapPath MapPathfinding;
	sfVector2i CurrentCaseSelect;
	sfVector2i CaseSaveSpell;
	D_Perso Perso;
	D_FightSystem Fightsystem;
	D_HudCombat FightHud;
	//Enemy
	M_Enemy ManagerEnemy;
	struct GAMEDATA GameDataEnemy;
	int Out;
	float TimerStateLV;
	int teleport;


};
/////////////////////////////////
// Containt Data of MapCombat,Player,Ennemy,(inventory)
////////////////////////////////
//-->sfVector2f CameraMC
//-->D_MapCombat MapCombat
//-->sfVector2i CurrentCaseSelect
////////////////////////////////
typedef struct INCOMBATDATA D_InCombat;





///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////

void INITCOMBAT(D_Str * Name, D_InCombat* InGameCombat, D_Inventory* _Inventory);
void UPDATECOMBAT(D_InCombat* InGameCombat, GameData * GD, SD_GameSound* GameSound);
void LAUNCHCOMBAT(D_Str * Name, GameData * GD, E_StateWorld *STATE, D_Inventory* _Inventory, SD_GameSound* GameSound);
#endif // !__COMBAT_H__



