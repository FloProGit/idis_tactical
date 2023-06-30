#ifndef __ANIMATION_H__
#define __ANIMATION_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////
#include"Utils.h"


///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////
struct ANIMETOTANDPATH
{

	int TotalFrames;
	float FrameTime;
	int Loop;
	char Path[100];


};
typedef struct ANIMETOTANDPATH D_AnimAndPath;



struct BASESTRCUTANIMPERSO
{
	int currentAnimation;
	int TotalAnimation;
	int CurrentFrame;
	float CurrentTime;
	D_AnimAndPath *AnimAndPath;
};
////////////////////////////////
//Contains all Data need for Animation
////////////////////////////////
//->int CurrentFrame;
//->float FrameTime;
//->float CurrentTime;
//->int TotalFrames;
////////////////////////////////
typedef struct BASESTRCUTANIMPERSO D_AnimationPerso;

struct BASESTRCUTANIMGEN
{
	int CurrentFrame;
	float CurrentTime;
	D_AnimAndPath AnimAndPath;
};
////////////////////////////////
//Contains all Data need for Animation
////////////////////////////////
//->int CurrentFrame;
//->float FrameTime;
//->float CurrentTime;
//->int TotalFrames;
////////////////////////////////
typedef struct BASESTRCUTANIMGEN D_AnimationG;

///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////
void InitAnimData(D_AnimationPerso * Anim, int TotalAnimation);
int UpdateAnimation(D_AnimationPerso * Anim, float DT);
void LoadSpriteAnimAtion(char _sNom[100], sfSprite* **Sprite, int CurrentAnimLoad, D_AnimationPerso *Anim, int TOTALFRAMES);

/////////////////////////////ANIMATION GENERAL///////////////////////////////

void InitAnimGeneral(D_AnimationG * Anim, char _sNom[100], float FrameTime, int Loop, int TotalFrames);

sfSprite* * LoadSpriteAnimAtionGeneral(sfSprite* *Sprite, D_AnimationG *Anim, int Xorigin, int Yorigin);

int UpdateAnimationG(D_AnimationG * Anim, float DT);


void SwitchAnimation(D_AnimationPerso * Anim, int NewAnim);

#endif // !__ANIMATION_H__



