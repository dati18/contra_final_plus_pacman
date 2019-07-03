#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include "GameEngine.h"
#include "ObjectBaseList.h"
#include "Player.h"

//-----------------------------------------------------
// PowerUp Class
//-----------------------------------------------------
class PowerUp : public ObjectBase
{
public:
	PowerUp(DOUBLE2 pos, BulletType type);
	virtual ~PowerUp();

	//-------------------------------------------------
	// Own methods
	//-------------------------------------------------
	virtual void Tick(double deltaTime);
	virtual void Paint();
	virtual void CollideWith(ObjectBase *colliderptr);
	void SetPlayerPtr(Player *playerPtr) { m_PlayerPtr = playerPtr; }

private:
	//-------------------------------------------------
	// Datamembers
	//-------------------------------------------------

	// Power up's constants
	BulletType m_BulletType;


	static Bitmap *m_BmpSpritePtr;

	Player *m_PlayerPtr;

	//HitRegion *m_HitTerrainPtr;
	double m_OnGround;
	DOUBLE2 m_Velocity;
	// Funks -----------------------------
	bool DoCollitions(HitRegion *hitVertPtr, DOUBLE2& pos, DOUBLE2& velocity, HitRegion *levelHitPtr);
	/*void DoCollitions(
		HitRegion **hitHoriPtr, HitRegion **hitVertPtr,
		DOUBLE2 *pos, DOUBLE2 *velocity);*/
	double ReturnGoodLen(double getal1, double getal2, double centerXY);

	// -------------------------
	// Disabling default copy constructor and default
	// assignment operator.
	// -------------------------
	PowerUp(const PowerUp& yRef);
	PowerUp& operator=(const PowerUp& yRef);
};
