#ifndef __PERSONNAGE_H__
#define __PERSONNAGE_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include <SFML/Graphics.h>
#include"Utils.h"
#include"MapCombat.h"
#include"Animation.h"


//inclure uniquement les INCLUDES NESSAICAIRE DANS LE .C et H.
// si par exemple on a juste besoins de faire des calcul alors 

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////

#define IMGPERSO "Images/perso/Voleuse/"
#define NBPERSO 4

///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////

struct SPRITEPERSO
{
	//tous les perso
	sfSprite* **Sprites;

};
////////////////////////////
//Tous les sprite des personnages jouable
////////////////////////////
//-->sfSprite* warrior;
//-->sfSprite* mage;
//-->sfSprite* pretre;
//-->sfSprite* voleuse;
////////////////////////////////

typedef struct SPRITEPERSO  A_Personnage;

struct SPELL
{
	int po;
	int dammage;
	int CostPa;
	int duration;
	int debuff;
	int buff;
	char inUse;
	char type;
};
////////////////////////////
//Rassemble toutes les variables lié au Personnages et à leurs caractéristique 
////////////////////////////
//-->int po;
//-->int dammage;
//-->int CostPa;
//-->int duration;
//-->int debuff;
//-->int buff;
//-->char inUse; savoir si le sort est en train d'etre utilisé ou non
////////////////////////////////
typedef struct SPELL  D_Spell;

struct STATS
{
	int PV;
	int PVMax;
	int PA;
	int PMMax;
	int PM;
	int ATK;
	int def;
	int crit;
	char inCrit;
	int bonusATK;
	int bonusDEF;
	int bonusCRIT;
	int Alive;
	char isSelected;
	int Special;
	int SpecialMax;
};
////////////////////////////
//Tous les sprite des personnages jouable
////////////////////////////
//-->int PV;
//-->int PA;
//-->int PM;
//-->int ATK;
//-->int def;
//-->int crit;
////////////////////////////////
typedef struct STATS  D_Stat;


struct PERSONNAGE
{
	int Line;
	int Column;
	int x;
	int y;
	D_Stat Stat;
	D_Spell spell[4];
	char attackMode;
	char mooveMode;
	char inTurn;
	int ToTalMouvement;
	D_AnimationPerso Animation;
	int StateDeplacement;
	int SpellAnimTouch;
	int lastDomage;

};


////////////////////////////
//Rassemble toutes les variables lié au Personnages et à leurs caractéristique 
////////////////////////////
//-->int Line;
//-->int Column;
//-->int x;
//-->int y;
//-->int PA; Point d'action
//-->int def;
//-->char attackMode; est t'il en mode attaque ? 
//-->char inTurn; est ce son tour ? 
////////////////////////////////
typedef struct PERSONNAGE  D_Personnage;// "D_" signifie que c'est une strcut de donné " DATA_ = D_ "

									///////////////////////////////////////////////////////////
									///------------------------PROTOTYPES-------------------///
									///////////////////////////////////////////////////////////



struct PLAYER
{
	A_Personnage spritePersonnage[NBPERSO];

	D_Personnage player[NBPERSO];

	char spellInUse;
};

//////////////////////////
//
/////////////////////////
//--> 
///////////////////////////////////
typedef struct PLAYER  D_Perso;
////INIT////

///ici Mettre les Fonction Uniquement executer a l'init ou a un certaint moment
void InitWarrior(D_Perso* perso, int column, int line, D_Map2D **map);
void InitMage(D_Perso* mage, int column, int line, D_Map2D **map);
void InitPretre(D_Perso* pretre, int column, int line, D_Map2D **map);
void InitVoleur(D_Perso* voleur, int column, int line, D_Map2D **map);
void InitPlayer(D_Perso* perso, D_MapCombat *map);


////UPDATE////
//Event in Update

//

void DisplayPlayer(D_Perso* perso, sfVector2f Camera, sfRenderWindow* window);

// mettre ici les fonctions qui sont utils en update par exemple un PROJECT.c


#endif // !__MODELTYPE_H__


