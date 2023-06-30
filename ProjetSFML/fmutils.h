#ifndef FMUTILS_H
#define FMUTILS_H

#include"Utils.h"
#include"menuState.h"



void InitDataButton(struct MENU* _MENU, int _totB, int _posX, int _posY, int _decal);
int MouseCollideOnButton(struct BUTTONDATA DataButton, sfVector2i _Mouse);

#endif

