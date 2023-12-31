#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <tchar.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include "time.h"
#include "windows.h"
#include "math.h"


#include"GamData.h"



sfSprite* LoadSprite(char* _sNom, int _isCentered, int _oriX, int _oriY);

void blitSpriteComplex(sfSprite* _sprite, float _posX, float _posY, float _angle, float _scaleX, float _scaleY, float _R, float _G, float _B, float _alpha, sfRenderWindow* _window);

void blitSprite(sfSprite* _sprite, float _posX, float _posY, float _angle, sfRenderWindow* _window);

void BlitTexte(sfText*_Text, int _x, int _y, int _Size, sfFont* _Police, sfRenderWindow* _window);
void DestroySprite(sfSprite**Sprite);
void displayTexte(char* _sContenu, sfText* _text, int posX, int posY, sfRenderWindow* _window, sfColor _color, int _size);

#endif