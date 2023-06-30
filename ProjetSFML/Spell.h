#ifndef __SPELL_H__
#define __SPELL_H__

#include "MapCombat.h"


////INIT////
void Critic(int* Critic, char* inCrit);
void SpellAttack(int* CibleHp, int *CibleDef, int damageSpell, int* LanceurPa, int CostPa, int DebuffSpell, int AtkBonus, char* inCrit, int *LastDomage);
void SpellBuff(int *CibleHp, int BuffSpell);
void BuffDef(int *CibleDef, int BuffSpell);
void BuffAtk(int *CibleATK, int BuffSpell);
void DebuffAtk(int *CibleAtk, int BuffSpell);
void Attract(int* posColumnCible, int* posLineCible, int posColumn, int posLine, int* LanceurPa, int CostPa);
void PriestSpell(D_Map2D **map, int* posColumnCible, int* posLineCible, int posColumn, int posLine, int* LanceurPa, int CostPa);
void Push(int* posColumnCible, int* posLineCible, int posColumn, int posLine, int* LanceurPa, int CostPa, int nbPush, D_MapCombat *MapCombat, D_Map2D **map);
////UPDATE////
//Event in Update

//

#endif
