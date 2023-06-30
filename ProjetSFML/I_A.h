#ifndef __I_A_H__
#define __I_A_H__

///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include"Enemy.h"
#include"FightSystem.h"
#include"Perso.h"
#include"Pathfinding.h"

//inclure uniquement les INCLUDES NESSAICAIRE DANS LE .C et H.
// si par exemple on a juste besoins de faire des calcul alors 

///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////

//Choice of attack
enum ACTION
{
	//Nothing he can do anything
	nothing,
	//Not a attack, but that say have to move
	move,
	//Attack of front
	hit,
	//Run ou the player and shoot on him
	shoot,
	//The name tell by himself
	heal,
	//Death
	death,
	//Run off the player
	escape,
	//Before Hit
	EndAnimAtk,
	///EndTrun

};


///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////


// void PROTOTYPE DE FONCTION(ARG); 

////UTILS////

// mettre ici les fonctions qui sont utils dans le Fichier EXEMPLE.c

////INIT////

///ici Mettre les Fonction Uniquement executer a l'init ou a un certaint moment///


////UPDATE////

// mettre ici les fonctions qui sont utils en update par exemple un PROJECT.c

D_Personnage *ChoosePlayer(D_Perso *personnage, D_MapPath* MapPath, D_Enemy *_Enemy, int nb);
int SaveDataTabPathfindind(M_Enemy * Enemy, D_MapPath* MapPath, D_Map2D **map, D_Perso* Perso, int NbEnemy);
void UpdateEnemy(struct GAMEDATA *_GameData, D_MapCombat *MapCombat, D_MapPath* MapPath, D_Personnage *perso, D_Perso* personnage, D_Map2D **map, struct TURN *turn, D_Enemy *D_Enemy, M_Enemy * M_Enemy, int nb, D_Perso* _perso, float dt, int NBRENEMY);
#endif // !__I_A_H__
