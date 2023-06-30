#include"Animation.h"




void InitAnimData(D_AnimationPerso * Anim, int TotalAnimation)
{
	Anim->currentAnimation = 0;
	Anim->TotalAnimation = TotalAnimation;
	Anim->CurrentFrame = 0;
	Anim->CurrentTime = 0;
	Anim->AnimAndPath = calloc(TotalAnimation, sizeof(D_AnimAndPath));
}

//InitAnimData(Anim, TotalFrame, FrameTime, TotalAnimation);
void LoadSpriteAnimAtion(char _sNom[100], sfSprite* **Sprite, int CurrentAnimLoad, D_AnimationPerso *Anim, int TOTALFRAMES)
{
	Sprite[CurrentAnimLoad] = calloc(TOTALFRAMES, sizeof(sfSprite*));

	for (int i = 0; i < TOTALFRAMES; i++)
	{
		char tempPath[100];
		char Nbri[5];

		strcpy(tempPath, _sNom);

		sprintf(Nbri, "%d.png", i);
		strcat(tempPath, Nbri);
		if (debug == 1) { printf("LoadALLSprite/Voleur/path Animation (%s) == ok\n", tempPath); }


		Sprite[CurrentAnimLoad][i] = LoadSprite(tempPath, 1, 0, 0);


	}

}

void SwitchAnimation(D_AnimationPerso * Anim, int NewAnim)
{
	printf("SwitchAnimation\n");
	Anim->currentAnimation = NewAnim;
	Anim->CurrentFrame = 0;
	Anim->CurrentTime = 0;
	Anim->CurrentFrame = 0;
}

int UpdateAnimation(D_AnimationPerso * Anim, float DT)
{
	Anim->CurrentTime += DT;
	if (Anim->AnimAndPath[Anim->currentAnimation].Loop == 1)
	{
		if (Anim->CurrentTime > Anim->AnimAndPath[Anim->currentAnimation].FrameTime)
		{
			Anim->CurrentFrame++;
			Anim->CurrentTime = 0;
			if (Anim->CurrentFrame > Anim->AnimAndPath[Anim->currentAnimation].TotalFrames - 1)
			{
				Anim->CurrentFrame = 0;

			}

		}
	}
	else
	{
		if (Anim->CurrentTime > Anim->AnimAndPath[Anim->currentAnimation].FrameTime)
		{
			Anim->CurrentFrame++;
			Anim->CurrentTime = 0;
			if (Anim->CurrentFrame > Anim->AnimAndPath[Anim->currentAnimation].TotalFrames - 1)
			{
				Anim->CurrentFrame = 0;
				Anim->currentAnimation = 0;
				return 1;
			}

		}
	}
	return 0;

}

/////////////////////////////ANIMATION GENERAL///////////////////////////////


void InitAnimGeneral(D_AnimationG * Anim, char _sNom[100], float FrameTime, int Loop, int TotalFrames)
{
	Anim->CurrentFrame = 0;
	Anim->CurrentTime = 0;
	Anim->AnimAndPath.FrameTime = FrameTime;
	Anim->AnimAndPath.Loop = Loop;
	Anim->AnimAndPath.TotalFrames = TotalFrames;
	strcpy(Anim->AnimAndPath.Path, _sNom);

}


sfSprite* * LoadSpriteAnimAtionGeneral(sfSprite* *Sprite, D_AnimationG *Anim, int Xorigin, int Yorigin)
{

	Sprite = calloc(Anim->AnimAndPath.TotalFrames, sizeof(sfSprite*));

	for (int i = 0; i < Anim->AnimAndPath.TotalFrames; i++)
	{
		char tempPath[100];
		char Nbri[5];

		strcpy(tempPath, Anim->AnimAndPath.Path);

		sprintf(Nbri, "%d.png", i);
		strcat(tempPath, Nbri);
		if (debug == 1) { printf("LoadALLSprite/Voleur/path Animation (%s) == ok\n", tempPath); }
		//printf("%s", tempPath);
		Sprite[i] = LoadSprite(tempPath, 0, Xorigin, Yorigin);


		//printf("LOAD %d  = %d\n", i, Sprite[0]);
	}
	return Sprite;
}
int UpdateAnimationG(D_AnimationG * Anim, float DT)
{
	Anim->CurrentTime += DT;
	if (Anim->AnimAndPath.Loop == 1)
	{
		if (Anim->CurrentTime > Anim->AnimAndPath.FrameTime)
		{
			Anim->CurrentFrame++;
			Anim->CurrentTime = 0;
			if (Anim->CurrentFrame > Anim->AnimAndPath.TotalFrames - 1)
			{
				Anim->CurrentFrame = 0;

			}

		}
	}
	else
	{
		if (Anim->CurrentTime > Anim->AnimAndPath.FrameTime)
		{
			Anim->CurrentFrame++;
			Anim->CurrentTime = 0;
			if (Anim->CurrentFrame > Anim->AnimAndPath.TotalFrames - 1)
			{
				Anim->CurrentFrame = 0;
				return 1;
			}

		}
	}
	return 0;

}