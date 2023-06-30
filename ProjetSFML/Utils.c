#include"Utils.h"

sfSprite* LoadSprite(char* _sNom, int _isCentered, int _oriX, int _oriY)//// fonction qui permet de charger un sprite
{
	sfTexture* tempTex = sfTexture_createFromFile(_sNom, NULL);
	sfSprite* tempSprite = sfSprite_create();
	sfSprite_setTexture(tempSprite, tempTex, sfTrue);
	if (_isCentered == 1)
	{
		sfVector2f tempOrigin = { sfTexture_getSize(tempTex).x / 2, sfTexture_getSize(tempTex).y / 2 };
		sfSprite_setOrigin(tempSprite, tempOrigin);
	}
	else
	{
		sfVector2f tempOrigin = { _oriX, _oriY };
		sfSprite_setOrigin(tempSprite, tempOrigin);
	}
	return tempSprite;
}
void DestroySprite(sfSprite**Sprite)
{
	sfTexture* tempTex = sfSprite_getTexture(Sprite);
	sfTexture_destroy(tempTex);
	sfSprite_destroy(Sprite);
}
void blitSpriteComplex(sfSprite* _sprite, float _posX, float _posY, float _angle, float _scaleX, float _scaleY, float _R, float _G, float _B, float _alpha, sfRenderWindow* _window) ///// Fonction qui permet d'affiché et actualisé la position d'un sprite
{
	sfVector2f pos = { _posX, _posY };
	sfVector2f scale = { _scaleX ,_scaleY };
	sfColor color = { _R ,_G ,_B ,_alpha };
	sfSprite_setRotation(_sprite, _angle);
	sfSprite_setPosition(_sprite, pos);
	sfSprite_setColor(_sprite, color);
	sfSprite_setScale(_sprite, scale);
	sfRenderWindow_drawSprite(_window, _sprite, NULL);
}
void blitSprite(sfSprite* _sprite, float _posX, float _posY, float _angle, sfRenderWindow* _window) ///// Fonction qui permet d'affiché et actualisé la position d'un sprite
{

	sfVector2f pos = { _posX, _posY };
	sfSprite_setRotation(_sprite, _angle);
	sfSprite_setPosition(_sprite, pos);
	sfRenderWindow_drawSprite(_window, _sprite, NULL);
}

void BlitTexte(sfText*_Text,int _x,int _y,int _Size,sfFont* _Police, sfRenderWindow* _window)
{
	sfVector2f tempPos = { _x,_y };
	sfText_setPosition(_Text, tempPos);
	sfText_setColor(_Text,sfWhite);
	sfText_setCharacterSize(_Text,_Size);
	sfText_setFont(_Text,_Police);
	sfRenderWindow_drawText(_window, _Text, NULL);
};
void displayTexte(char* _sContenu, sfText* _text, int posX, int posY, sfRenderWindow* _window, sfColor _color, int _size)
{
	sfText_setString(_text, _sContenu);
	sfVector2f tempPos = { posX, posY };
	sfText_setPosition(_text, tempPos);
	sfText_setColor(_text, _color);
	sfText_setCharacterSize(_text, _size);
	sfRenderWindow_drawText(_window, _text, NULL);
}