#ifndef __VECTOR_C_H__
#define __VECTOR_C_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////


#include "math.h"
#include <SFML/Graphics.h>


///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////

struct SFVECTOR3IDATA
{
	int x;
	int y;
	int z;
}; 
typedef struct SFVECTOR3IDATA sfVector3i;




///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////


////UTILS////
float fScalar(sfVector2f Va, sfVector2f Vb);
sfVector2f FoundVector(sfVector2f Va, sfVector2f Vb);
float NormVector(sfVector2f Va);
sfVector2f VectorNormal(sfVector2f Va, float NormVector);
sfVector2f AddVector(sfVector2f Va, sfVector2f Vb);
sfVector2f FmultVector(float Valeur, sfVector2f Va);
float Distb2v(sfVector2f Va, sfVector2f Vb);
sfVector2f NormalVb2p(sfVector2f Va, sfVector2f Vb);
////UPDATE////
void VectorDraw(sfVector2f _P0, sfVector2f _P1, sfColor _Color, sfRenderWindow* _Window);

#endif // !__VECTOR_C_H__



