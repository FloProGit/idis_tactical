#ifndef menu__H
#define menu__H

#include"GamData.h"
#include "Sound.h"



#define TOTBUTTON 4

struct BUTTONDATA
{
	sfVector2i Pos;
	sfVector2i Size;
	char Name[10];
	char On;
	void(*Ptr_fct)(StateM*);

};
struct ILE
{
	sfVector2i pos;
	float Amplitude;
	float Frequence;
	float timer;
	sfClock* horloge;
	float dt;
};

struct MENU
{
	sfSprite* TabSpriteOff[TOTBUTTON];
	sfSprite* TabSpriteOn[TOTBUTTON];
	sfSprite* Background;
	sfSprite* Ile;
	sfSprite* crea;
	sfSprite* logo;
	sfSprite* title;
	sfSprite* histoire;

	sfVector2f histoirePosition;

	struct BUTTONDATA ButtonData[TOTBUTTON];
	struct ILE DataIle;
};

void OptionButton(StateM** State);
void ExitButton(StateM** State);
void DisplayMenu(GameData* Common, struct MENU* MenuData);
void DisplayHistoire(GameData* Common, struct MENU* MenuData);

void PlayButton(StateM** State);
void OptionButton(StateM** State);
; void ReturnButton(StateM** State);

void menuStateInit(struct COMMON* Common, struct MENU* MenuData, SD_GameSound* GameSound);
#endif
