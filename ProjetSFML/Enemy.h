#ifndef ENNEMY_H
#define ENNEMY_H

///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include"Utils.h"
#include"MapCombat.h"
#include"GamData.h"
#include"Perso.h"
#include"Animation.h"


//inclure uniquement les INCLUDES NESSAICAIRE	 DANS LE .C et H.
// si par exemple on a juste besoins de faire des calcul alors 

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////

#define NBENEMY 2
#define POSSIBLE_MOVE 4
#define SPRITE_ENEMY 10

///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////

//Level of Intelligence
enum TYPEIA
{
	//GO on the player
	berserk,
	//Run away the player
	running,
	boss,
	hard,

	//Heal the enemy
	healer,
	//(Description Later)
	//IA boss (Not made well)
};

//Set the direction of Enemy (for sprite too)
enum DIRECTION
{
	UpRight,
	UpLeft,
	DownRight,
	DownLeft,
};

///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////
struct ANIMIA
{
	int ToTalMouvement;
	D_AnimationPerso Animation;
};
typedef struct ANIMIA D_AnimIa;



struct SPRITEENEMY
{
	sfSprite* Sprite[4];
};
////////////////////////////////
// Contain all DISPLAY of Enemy
///////////////////////////
//Image of Enemy
//--> sfSprite *Sprite;
////////////////////////////////
// "A_" signifie que c'est une struct d'affichage " AFFICHE_ = A_ "
typedef struct SPRITEENEMY A_Enemy;


struct DATAENEMY
{
	sfVector2i map;
	sfVector2f pos;
	int nbCase;
	int Move[POSSIBLE_MOVE];
	enum TYPEIA I_A;
	enum ACTION action, dir;
	D_Stat Stat;
	float pause,pauseMax;
	int isStun;
	sfVector2i *TabPath;
	int TotTabPath;
	int TabPathSave;
	int CurrentCaseMove;
	int Target;
	int ToTalMouvement;
	char Current;
	D_AnimationPerso Animation;
	int SidePlayer;
	int AsAtk;

	////ADD
	int deadState;//--> 0 / alive ; 1 / toutch ; 2 / dead;
	float timerdead;
	int SpellAnimTouch;

};

////////////////////////////////
// Contain all DATA of Enemy
///////////////////////////
//Position X and Y on the map
//-->sfVector2i map;;
//Position of Sprite on the map
//-->sfVector2f pos;
//PointMove, AttackPoint;
//--> int nbCase;
//Intelligence choice
//-->int Move[POSSIBLE_MOVE];
//Action of the player
//-->enum TYPEIA I_A;
//Move Possibility
//-->enum ACTION action, dir;
//Temps avant de prendre une décision
//-->float pause, pausemax;
////////////////////////////////
// "D_" signifie que c'est une struct de donné " DATA_ = D_ "
typedef struct DATAENEMY D_Enemy;

struct ENEMYMANAGER
{
	int AllTypeEnemy;
	int TOt_IA;
	D_AnimIa IA_Anime[4];
	A_Enemy Affichage_Enemy;
	D_Enemy *Data_Enemy;
	int TotEnemy;

	int spellAnimUse;
	int CurrentSpellUse;
};
/////////////////////////////
//
////////////////////////////
//-->int AllTypeEnemy;
//-->A_Enemy *Affichage_Enemy;
//-->D_Enemy *Data_Enemy;
typedef struct ENEMYMANAGER M_Enemy;
///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////

// void PROTOTYPE DE FONCTION(ARG); 

////UTILS////
// mettre ici les fonctions qui sont utils dans le Fichier EXEMPLE.c

////INIT////

///ici Mettre les Fonction Uniquement executer a l'init ou a un certaint moment///
D_Enemy* Generate_Ennemy(D_Enemy *D_Enemy, int nb);
void LoadEnemy(D_MapCombat *map, M_Enemy *Enemy, int nb);
void LoadSpriteEnemy(A_Enemy* A_Enemy);
void Destroy_Ennemy(D_Enemy *D_Enemy);

////UPDATE////

// mettre ici les fonctions qui sont utils en update par exemple un PROJECT.c
void DisplayEnemy(D_Enemy *D_Enemy, int nb, A_Enemy A_Enemy, sfVector2f Camera, sfRenderWindow* window);

#endif