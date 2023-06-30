#ifndef __DISPLAY_H__
#define __DISPLAY_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include"Animation.h"
#include"Enemy.h"
#include"Perso.h"
#include"FightSystem.h"
///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////
struct DATADECORS
{
	int ID;
	sfVector2f Pos;
	sfVector2i Origin;
};
typedef struct DATADECORS D_decors;

struct DATADECORSANIM
{
	int ID;
	sfVector2f Pos;
	sfVector2i Origin;
};
typedef struct DATADECORSANIM D_Animdecors;


struct ALLSPRITEANIMMAP
{
	int IDSprite;
	sfSprite* *Sprite;
};
/////////////////////////////////
// Containt Sprite of Map
////////////////////////////////
//-->sfSprite* BlocSprite;
////////////////////////////////
typedef struct ALLSPRITEANIMMAP A_AniMAp;
struct ALLSPRITEANIMSPELL
{
	int IDSprite;
	sfSprite* *Sprite;
};
/////////////////////////////////
// Containt Sprite of Map
////////////////////////////////
//-->sfSprite* BlocSprite;
////////////////////////////////
typedef struct ALLSPRITEANIMMAP A_AnimSpell;

struct ALLSPRITEMAP
{
	int IDSprite;
	sfSprite* Sprite;
};
/////////////////////////////////
// Containt Sprite of Map
////////////////////////////////
//-->sfSprite* BlocSprite;
////////////////////////////////
typedef struct ALLSPRITEMAP A_BlockSprite;

struct DATASPRITE
{
	sfSprite* **Sprite;
};

typedef struct DATASPRITE A_DataSprites;


struct ALLSPRITES
{
	int TotBiome;
	int TotBlocByType;
	struct BIOME *BiomeList;


	sfText* textDisplay;


	A_DataSprites EnemySprite[4];
	A_DataSprites PersoSprite[4];
	A_BlockSprite BlocSprite[100];
	D_decors Decors[100];
	A_BlockSprite DecorsSprite[100];
	sfSprite* ShadowMask[11];
	sfSprite* ombresPerso;

	sfSprite* GreenCase;
	sfSprite* RedCase;
	sfSprite* TrapCase;
	sfSprite* orangeCase;
	sfSprite* A_CaseSelect;
	sfSprite* FeedBackSol;
	sfSprite* GameOver;
	int TotDecors;
	D_Str PrintDamage;



	////////////////////////////ANIMATION SIMPLE


	D_AnimationG DecortsAnim[22];
	A_AniMAp AnimMap[22];




	//////////////////////////////ANIMATION SPELL

	D_AnimationG AnimSpell[10];
	A_AnimSpell SriteSpell[10];

};
typedef struct ALLSPRITES A_AllSprites;







///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////
void LoadALLSprite(D_Perso* Perso, M_Enemy * Enemy, A_AllSprites * AllSprite);

void __DISPLAY_GENERAL__(D_MapCombat* Map, sfVector2i CurrentSelect, D_FightSystem* fightSystem, D_Perso* perso, M_Enemy * Enemy, sfVector2f Camera, A_AllSprites * AllSprite, int turn, sfRenderWindow* window);
#endif // !__DISPLAY_H__


