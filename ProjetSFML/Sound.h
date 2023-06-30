#ifndef __SOUND_H__
#define __SOUND_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////

#include <SFML/Audio.h>


///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////

#define INTERACTION "SOUND/InteractSound/" 

///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////

struct SOUNDTRACK
{
	sfMusic* SoutrackList[4];
};
////////////////////////
//Contain Music soundtrack
//////////////////////
typedef struct SOUNDTRACK SD_SoundTrack;







struct HUDMENUSOUND
{

	sfSound* IntefaceSoundList[1];

};
////////////////////////
//Contain interface Sound
//like Menu or Option , HUD
//////////////////////
typedef struct HUDMENUSOUND SD_Interface;







struct AMBIENCESOUND
{

	sfMusic* AmbienceList[1];

};
////////////////////////
//Contain Sound out of the Game
//////////////////////
typedef struct AMBIENCESOUND SD_AmbienceSound;








struct IDENTIFICATIONNG
{

	sfSound* IdentNotGPList[1];

};
////////////////////////
// "IS NOT FOR GAMEPLAY"
//Contain All identification sound
//like end of fight or start
//////////////////////
typedef struct IDENTIFICATIONNG SD_IdentNotGamePlay;









struct IDENTIFICATIONG
{
	sfSound* IdentGPList[1];
};
////////////////////////
// "IS FOR GAMEPLAY
// contain all sound like select Case
//////////////////////
typedef struct IDENTIFICATIONG SD_IdentGamePlay;







struct ACTIONSOUND
{
	sfSound* ActionSound[20];


};
////////////////////////
//Contain Action Sound of Game
// like attack , heal,KO,Buff,DeBuff,Mouve
//////////////////////
typedef struct ACTIONSOUND SD_Action;






struct SOUNDMANAGER
{
	SD_SoundTrack SoundTrack;
	SD_Interface Interface;
	SD_AmbienceSound Ambience;
	SD_IdentNotGamePlay InotGamePlay;
	SD_IdentGamePlay IdentGamePlay;
	SD_Action ActionSound;

};
////////////////////////
//Contain all Struct of different game Sound
//////////////////////
typedef struct SOUNDMANAGER SD_GameSound;




///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////

sfSound* LoadSound(char* _sNom);
void SetVolumeAllSound(SD_GameSound* GameSound);
void LoadAllSound(SD_GameSound* GameSound);
void LoadAllMusic(SD_GameSound* GameSound);
void PlayMusic(sfMusic* music);
#endif // !__SOUND_H__



