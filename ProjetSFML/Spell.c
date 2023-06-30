#include "spell.h"

void Critic(int* Critic, char* inCrit)
{
	int chance = rand() % 100;
	printf("\n chance : %d \n", chance);
	printf("\n chancedecrit : %d \n", *Critic);
	if (chance <= *Critic)
	{
		*inCrit = 1;
	}
	else
	{
		*inCrit = 0;
	}
	printf("\n crit : %d \n", *inCrit);
}

void SpellAttack(int* CibleHp, int *CibleDef, int damageSpell, int* LanceurPa, int CostPa, int DebuffSpell, int AtkBonus, char* inCrit, int *LastDomage)
{
	//Pour les spell basique de dégat !
	int Attaque = 0;

	if (*inCrit == 1)
	{
		Attaque = ((damageSpell * 2) + AtkBonus) - (*CibleDef);
		*inCrit == 0;
	}
	else
	{
		Attaque = (damageSpell + AtkBonus) - (*CibleDef);

	}
	printf("ATk %d \n dammageSpell %d \n ATkBonus %d \n   CibleDef %d \n", Attaque, damageSpell, AtkBonus, *CibleDef);
	if (Attaque >= 0)
	{
		*(CibleHp) -= Attaque;
		printf("Point de vie = %d \n", *CibleHp);
		*LastDomage = Attaque;
	}

	*CibleDef -= DebuffSpell;

}

void SpellBuff(int *CibleHp, int BuffSpell)
{
	//Choice buff 1 pour le HEAL 	
	
	*CibleHp += BuffSpell;

	if (*CibleHp > 100)
	{
		*CibleHp = 100;
	}

}

void BuffDef(int *CibleDef, int BuffSpell)
{
	*CibleDef += BuffSpell;
}

void BuffAtk(int *CibleATK, int BuffSpell)
{
	*CibleATK += BuffSpell;
}

void DebuffAtk(int *CibleAtk, int BuffSpell)
{
	*CibleAtk -= BuffSpell;
}


void Push(int* posColumnCible, int* posLineCible, int posColumn, int posLine, int* LanceurPa, int CostPa, int nbPush, D_MapCombat *MapCombat, D_Map2D **map)
{
	//Compétence du warrior qui attire a la case en face de lui 
	if (*posLineCible == posLine)
	{
		if (*posColumnCible < posColumn)
		{
			if (*posColumnCible - nbPush >= 0)
			{
				if (map[*posLineCible][*posColumnCible - nbPush].OnOffCase2D == ON)
				{
					*posColumnCible -= nbPush;
				}
				else
				{
					*LanceurPa += 2;
				}
			}
		}

		if (*posColumnCible > posColumn)
		{
			if (*posColumnCible + nbPush < MapCombat->Size.x)
			{
				if (map[*posLineCible][*posColumnCible + nbPush].OnOffCase2D == ON)
				{
					*posColumnCible += nbPush;
				}
				else
				{
					*LanceurPa += 2;
				}
			}
		}
	}
	if (*posColumnCible == posColumn)
	{
		if (*posLineCible < posLine)
		{
			if (*posLineCible - nbPush >= 0)
			{
				if (map[*posLineCible - nbPush][*posColumnCible].OnOffCase2D == ON)
				{
					*posLineCible -= nbPush;
				}
				else
				{
					*LanceurPa += 2;
				}
			}
		}

		if (*posLineCible > posLine)
		{
			if (*posLineCible + nbPush < MapCombat->Size.y)
			{
				if (map[*posLineCible + nbPush][*posColumnCible].OnOffCase2D == ON)
				{
					*posLineCible += nbPush;
				}
				else
				{
					*LanceurPa += 2;
				}
			}
		}
	}
}

void Attract(int* posColumnCible, int* posLineCible, int posColumn, int posLine, int* LanceurPa, int CostPa)
{
	//Compétence du warrior qui attire a la case en face de lui 
	if (*posLineCible == posLine)
	{
		if (*posColumnCible < posColumn)
		{
			*posColumnCible = posColumn - 1;
		}

		if (*posColumnCible > posColumn)
		{
			*posColumnCible = posColumn + 1;
		}
	}
	if (*posColumnCible == posColumn)
	{
		if (*posLineCible < posLine)
		{
			*posLineCible = posLine - 1;
		}

		if (*posLineCible > posLine)
		{
			*posLineCible = posLine + 1;
		}
	}
}








void PriestSpell(D_Map2D **map, int* posColumnCible, int* posLineCible, int posColumn, int posLine, int* LanceurPa, int CostPa)
{






}