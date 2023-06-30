#include"fmutils.h"




void InitDataButton(struct MENU* _MENU,int _totB,int _posX,int _posY,int _decal)
{
	
	for (int i = 0; i < _totB; i++)
	{
		////get Size Image
		_MENU->ButtonData[i].Size.x = sfSprite_getLocalBounds(_MENU->TabSpriteOff[i]).width;
		_MENU->ButtonData[i].Size.y = sfSprite_getLocalBounds(_MENU->TabSpriteOff[i]).height;
		////Set Position of Button on Vectical Line
		_MENU->ButtonData[i].Pos.x = _posX;
		_MENU->ButtonData[i].Pos.y = _posY + (i*(_MENU->ButtonData[i].Size.y + _decal));

	}
}

////Colision Test Mouse Vs Button
int MouseCollideOnButton(struct BUTTONDATA DataButton, sfVector2i _Mouse)
{
	if (_Mouse.x >= DataButton.Pos.x &&
		_Mouse.x <= DataButton.Pos.x + DataButton.Size.x &&
		_Mouse.y >= DataButton.Pos.y &&
		_Mouse.y <= DataButton.Pos.y + DataButton.Size.y )
	{
		return 1;
	}
	return 0;
}




