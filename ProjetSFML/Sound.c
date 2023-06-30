#include"Sound.h"




sfSound* LoadSound(char* _sNom)
{
	sfSoundBuffer* tempBuffer = 0;
	sfSound* tempSound = 0;
	//Initialisation et chargement du son
	tempBuffer = sfSoundBuffer_createFromFile(_sNom); //Chargement des données du son
	tempSound = sfSound_create(); //création du son
	sfSound_setBuffer(tempSound, tempBuffer); //Assignation des données du fichier au son

	return tempSound;
}

void SetVolumeAllSound(SD_GameSound* GameSound)
{
	float Interaction = 40.f;
	sfSound_setVolume(GameSound->Interface.IntefaceSoundList[0], Interaction);
}

void LoadAllSound(SD_GameSound* GameSound)
{
	GameSound->Interface.IntefaceSoundList[0] = LoadSound(INTERACTION"ClicMenu.wav");

	GameSound->ActionSound.ActionSound[16] = LoadSound(INTERACTION"Clic.wav");
	GameSound->ActionSound.ActionSound[17] = LoadSound(INTERACTION"EndFight.wav");
	GameSound->ActionSound.ActionSound[18] = LoadSound(INTERACTION"LooseFight.wav");

	//Son Spell warrior 
	GameSound->ActionSound.ActionSound[0] = LoadSound("SOUND/PersoSound/Warrior/Spell1.wav");
	GameSound->ActionSound.ActionSound[1] = LoadSound("SOUND/PersoSound/Warrior/Spell2.wav");
	GameSound->ActionSound.ActionSound[2] = LoadSound("SOUND/PersoSound/Warrior/Spell3.wav");

	//Son Spell Mage 
	GameSound->ActionSound.ActionSound[4] = LoadSound("SOUND/PersoSound/Mage/Spell1.wav");
	GameSound->ActionSound.ActionSound[5] = LoadSound("SOUND/PersoSound/Mage/Spell2.wav");
	GameSound->ActionSound.ActionSound[6] = LoadSound("SOUND/PersoSound/Mage/Spell3.wav");
	GameSound->ActionSound.ActionSound[7] = LoadSound("SOUND/PersoSound/Mage/Spell4.wav");

	//Son Spell Pretre
	GameSound->ActionSound.ActionSound[8] = LoadSound("SOUND/PersoSound/Pretre/Spell1.wav");
	GameSound->ActionSound.ActionSound[9] = LoadSound("SOUND/PersoSound/Pretre/Spell2.wav");
	GameSound->ActionSound.ActionSound[11] = LoadSound("SOUND/PersoSound/Pretre/Spell4.wav");

	//Son Spell Voleuse
	GameSound->ActionSound.ActionSound[12] = LoadSound("SOUND/PersoSound/Voleur/Spell1.wav");
	GameSound->ActionSound.ActionSound[13] = LoadSound("SOUND/PersoSound/Voleur/Spell2.wav");
	GameSound->ActionSound.ActionSound[15] = LoadSound("SOUND/PersoSound/Voleur/Spell4.wav");
}

void LoadAllMusic(SD_GameSound* GameSound)
{
	GameSound->SoundTrack.SoutrackList[0] = sfMusic_createFromFile("SOUND/Music/MusicWorld.wav");
	GameSound->SoundTrack.SoutrackList[1] = sfMusic_createFromFile("SOUND/Music/FightMusic1.wav");
	GameSound->SoundTrack.SoutrackList[2] = sfMusic_createFromFile("SOUND/Music/MenuMusic.wav");
}

void PlayMusic(sfMusic* music)
{
	printf("MUSIC IN %d\n", music);
	sfMusic_setVolume(music, 10); //Volume réduit de moitié (sur 100)
	sfMusic_setLoop(music, 1); //Lecture en boucle
	sfMusic_play(music); //Lancement de la musique
}