#include "particle.h"
////////////UTILS
float LerpParticle(float _pointA, float _pointB, float _t)
{
	return _pointA + _t * (_pointB - _pointA);
}

///////////////INITS
void initParticle(D_Particles* _kind, int nb_Leaf, int _x, int _y, int _newX, int _newY, float angle, float speed)
{

	_kind[nb_Leaf].Pos.x = _x;
	_kind[nb_Leaf].Pos.y = _y;
	_kind[nb_Leaf].newPos.x = _newX;
	_kind[nb_Leaf].newPos.y = _newY;
	_kind[nb_Leaf].angle = angle;
	_kind[nb_Leaf].speed = speed;

};
///////////////
void initSnow(A_PARTICLES* _Particles, int nb_Leaf, int _x, int _y, int _newX, int _newY, float angle, float speed)
{

	_Particles->snow[nb_Leaf].Pos.x = _x;
	_Particles->snow[nb_Leaf].Pos.y = _y;
	_Particles->snow[nb_Leaf].newPos.x = _newX;
	_Particles->snow[nb_Leaf].newPos.y = _newY;
	_Particles->snow[nb_Leaf].angle = angle;
	_Particles->snow[nb_Leaf].speed = speed;

};
void initRain(A_PARTICLES* _Particles, int nb_Rain, int _x, int _y, int _newX, int _newY, float angle, float speed)
{

	_Particles->rain[nb_Rain].Pos.x = _x;
	_Particles->rain[nb_Rain].Pos.y = _y;
	_Particles->rain[nb_Rain].newPos.x = _newX;
	_Particles->rain[nb_Rain].newPos.y = _newY;
	_Particles->rain[nb_Rain].angle = angle;
	_Particles->rain[nb_Rain].speed = speed;

};
////////////////////////////////////

void launchSnow(A_PARTICLES* _Particles, int _nbSnow)
{
	_Particles->nbSnow = _nbSnow;
	_Particles->isSnowing = TRUE;
	for (int i = 0; i < _Particles->nbSnow; i++)
	{
		float hasard = rand() / (float)RAND_MAX;
		int randX = 100;
		int randY = 100;
		int randNewX = -100;
		int randNewY = rand() % 540 + 540;
		float angle = 105;
		int TempRand = rand() % 100 + 500;
		float TempRandF = (rand() % 1000) / 1000;
		float speed = (TempRand + TempRandF) / 100;
		initSnow(_Particles, i, randX, randY, randNewX, randNewY, angle, speed);
	};
};
void launchRain(A_PARTICLES* _Particles, int _nbRain)
{
	_Particles->nbRain = _nbRain;
	_Particles->isRaining = TRUE;
	for (int i = 0; i < _Particles->nbRain; i++)
	{
		int randX = rand() % 3000;
		int randY = -rand() % 1000;
		int randNewX = -100;
		int randNewY = rand() % 540 + 540;
		float angle = 105;
		float speed = rand() % 1500 + 1500;
		initRain(_Particles, i, randX, randY, randNewX, randNewY, angle, speed);
	};
};
void initParticles(A_PARTICLES* _Particles)
{
	_Particles->sprites.rain = LoadSprite("IMG/MAP/rain.png", 1, 0, 0);
	_Particles->sprites.snow = LoadSprite("IMG/MAP/snow.png", 1, 0, 0);
	launchRain(_Particles, 449);
};
////////////////////////////////////UPDATES

void updateRain(A_PARTICLES* _Particles, float dt)
{
	int randX = rand() % 3000;
	int randY = -rand() % 1000;
	int randNewX = -100;
	int randNewY = rand() % 540 + 540;
	float angle = 105;
	float speed = rand() % 2500 + 1000;

	for (int i = 0; i < _Particles->nbRain; i++)
	{
		_Particles->rain[i].scale = (_Particles->rain[i].speed / 50);
		_Particles->rain[i].Pos.x -= (_Particles->rain[i].speed / 2) * dt ;
		_Particles->rain[i].Pos.y += _Particles->rain[i].speed  * dt;
		
		if (_Particles->rain[i].Pos.x <= 0 || _Particles->rain[i].Pos.y >= 1080)
		{
			initRain(_Particles, i, randX, randY, randNewX, randNewY, angle, speed);
		}
	};
}

void updateSnow(A_PARTICLES* _Particles, float dt)
{
	int randX = rand() % 3000;
	int randY = -rand() % 1000;
	int randNewX = -100;
	int randNewY = rand() % 540 + 540;
	float angle = 105;
	int TempRand = rand() % 100 + 750;
	float TempRandF = (rand() % 1000) / 1000;
	float speed = rand() % 2500 + 1000;
	for (int i = 0; i < _Particles->nbSnow; i++)
	{
		_Particles->snow[i].Pos.x -= _Particles->snow[i].speed * dt  ;
		_Particles->snow[i].Pos.y += _Particles->snow[i].speed * dt;
		if (_Particles->snow[i].Pos.x <= 0 || _Particles->snow[i].Pos.y >= 1080)
		{
			initSnow(_Particles, i, randX, randY, randNewX, randNewY, angle, speed);
		}
	};
}
void updateParticles(A_PARTICLES* _Particles, float dt)
{
	if (_Particles->isRaining == TRUE)
	{
		updateRain(_Particles, dt);

	}
	else if (_Particles->isSnowing == TRUE)
	{
		updateSnow(_Particles, dt);

	};
};
////////////////////////////////////DISPLAYS
void displayRainBack(A_PARTICLES* _Particles, sfRenderWindow* window)
{
	for (int i = 0; i < _Particles->nbRain / 2; i++)
	{
		blitSpriteComplex(_Particles->sprites.rain, _Particles->rain[i].Pos.x, _Particles->rain[i].Pos.y, _Particles->rain[i].angle, _Particles->rain[i].scale, 1, 255, 255, 255, 255, window);
	}
};
void displaySnowBack(A_PARTICLES* _Particles, sfRenderWindow* window)
{
	for (int i = 0; i < _Particles->nbSnow / 2; i++)
	{
		blitSpriteComplex(_Particles->sprites.snow, _Particles->rain[i].Pos.x, _Particles->rain[i].Pos.y, _Particles->rain[i].angle, _Particles->rain[i].scale, 1, 255, 255, 255, 255, window);
	}
};
void displayParticlesBack(A_PARTICLES* _Particles, sfRenderWindow* window)
{
	if (_Particles->isRaining == TRUE)
	{
		displayRainBack(_Particles, window);
	}
	else if (_Particles->isSnowing == TRUE)
	{
		displaySnowBack(_Particles, window);
	};
}
////// DISPLAY :)
void displayRainFront(A_PARTICLES* _Particles, sfRenderWindow* window)
{
	for (int i = _Particles->nbRain - (_Particles->nbRain / 2); i < _Particles->nbRain; i++)
	{
		blitSpriteComplex(_Particles->sprites.rain, _Particles->rain[i].Pos.x, _Particles->rain[i].Pos.y, _Particles->rain[i].angle, _Particles->rain[i].scale, 1, 255, 255, 255, 255, window);
	}
};
void displaySnowFront(A_PARTICLES* _Particles, sfRenderWindow* window)
{
	for (int i = _Particles->nbSnow - (_Particles->nbSnow / 2); i < _Particles->nbSnow; i++)
	{
		blitSpriteComplex(_Particles->sprites.snow, _Particles->snow[i].Pos.x, _Particles->snow[i].Pos.y, _Particles->snow[i].angle, _Particles->snow[i].scale, 1, 255, 255, 255, 255, window);
	}
};
void displayParticlesFront(A_PARTICLES* _Particles, sfRenderWindow* window)
{
	if (_Particles->isRaining == TRUE)
	{
		displayRainFront(_Particles, window);
	}
	else if (_Particles->isSnowing == TRUE)
	{
		displaySnowFront(_Particles, window);
	};
}