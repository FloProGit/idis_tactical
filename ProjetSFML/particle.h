#ifndef _PARTICLE_H
#define _PARTICLE_H
#include "Utils.h"
#include "SFML/Graphics.h"

struct LEAFEffect
{
	sfVector2f Pos;
	sfVector2f newPos;
	float scale;
	float angle;
	float speed;
};
/////////////////////////////////
typedef struct LEAFEffect D_Leaf;
//Struct des feuilles pour le mode Explo
//////////////////////////////////
struct ParticulesData
{
	sfVector2f Pos;
	sfVector2f newPos;
	float scale;
	float angle;
	float speed;
};
/////////////////////////
//Struct générique pour générée des Particules
typedef struct ParticulesData D_Particles;
//////////////////////////
struct PARTICLESprites
{
	sfSprite* rain;
	sfSprite* snow;
};
/////////////////////
//Struct contenant tout les sprites des particules
///////////////////
typedef struct PARTICLESprites A_Sprites;





struct PARTICLES
{
	D_Particles snow[450];
	D_Particles rain[450];
	int nbSnow;
	int nbRain;
	char isSnowing;
	char isRaining;
	A_Sprites sprites;
	
};

typedef struct PARTICLES A_PARTICLES;
////////////////////////////PROTOTYPES

void initParticles(A_PARTICLES* _Particles);
void updateParticles(A_PARTICLES* _Particles, float dt);
void displayParticlesBack(A_PARTICLES* _Particles, sfRenderWindow* window);
void displayParticlesFront(A_PARTICLES* _Particles, sfRenderWindow* window);


#endif
