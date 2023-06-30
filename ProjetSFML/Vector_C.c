#include"Vector_C.h"




///////////////////////////////////////////////////
///----------------------UTILS------------------///
///////////////////////////////////////////////////

float fScalar(sfVector2f Va, sfVector2f Vb)
{
	return  Va.x * Vb.x + Va.y*Vb.y;
}

sfVector2f FoundVector(sfVector2f Va, sfVector2f Vb)
{
	sfVector2f newVector = { Vb.x - Va.x,Vb.y - Va.y };
	return newVector;
}
sfVector2f AddVector(sfVector2f Va, sfVector2f Vb)
{
	sfVector2f newVector = { Va.x + Vb.x,Va.y + Vb.y };
	return newVector;
}

sfVector2f FmultVector(float Valeur, sfVector2f Va)
{
	sfVector2f newVector = { Va.x * Valeur,Va.y * Valeur };
	return newVector;
}
float NormVector(sfVector2f Va)
{
	return  sqrt((Va.x *Va.x) + (Va.y *Va.y));
}

sfVector2f VectorNormal(sfVector2f Va, float NormVector)
{
	sfVector2f normalise = { Va.x / NormVector,Va.y / NormVector };
	return normalise;
}

float Distb2v(sfVector2f Va, sfVector2f Vb)
{

	sfVector2f tempVect = FoundVector(Va, Vb);
	//printf("X*X = %d", (tempVect.x * tempVect.x));
	//printf("Y*Y = %d", (tempVect.y * tempVect.y));

	float dist = (tempVect.x * tempVect.x) + (tempVect.y * tempVect.y);
	//printf("dist1 = %d", dist);
	return  dist;
}
sfVector2f NormalVb2p(sfVector2f Va, sfVector2f Vb)
{
	sfVector2f TempVector;
	TempVector = FoundVector(Va, Vb);
	//printf("x = %f y = %f\n", TempVector.x, TempVector.y);
	float NormalTempVector = NormVector(TempVector);
	//printf("norme = %f\n", NormalTempVector);

	TempVector = VectorNormal(TempVector, NormalTempVector);	
	return TempVector;
}
///////////////////////////////////////////////////
///----------------------UPDATE-----------------///
///////////////////////////////////////////////////


void VectorDraw(sfVector2f _P0, sfVector2f _P1, sfColor _Color, sfRenderWindow* _Window)
{

	sfVertex VecticeTemp[2];

	VecticeTemp[0].color = _Color;
	VecticeTemp[0].position.x = _P0.x;
	VecticeTemp[0].position.y = _P0.y;

	VecticeTemp[1].color = _Color;
	VecticeTemp[1].position.x = _P1.x;
	VecticeTemp[1].position.y = _P1.y;
	sfRenderWindow_drawPrimitives(_Window, VecticeTemp, 2, sfLines, NULL);

}