#pragma once
#include "ObjectBaseList.h"

class pusher : public ObjectBase
{
public:
	pusher(DOUBLE2 pos);
	virtual ~pusher();

	//-------------------------------------------------
	// Own methods
	//-------------------------------------------------
	virtual void Tick(double deltaTime);
	virtual void Paint();
	virtual void CollideWith(ObjectBase *colliderptr);
	void SetPlayerPtr(ObjectBase *playerPtr);
	void BecomeGhost();



private:
	enum pusher_state {
		STATE_NORMAL = 0,
		STATE_JUMP = 2,
		STATE_DIE = 5,
	};
	//-------------------------------------------------
	// Datamembers
	//-------------------------------------------------
	DOUBLE2 m_PointingDir;

	pusher_state m_State;

	double m_AnimationTick;
	double m_TimeToDie;

	ObjectBase *m_PlayerPtr;
	Bitmap *m_BmpSpritePtr = 0;

	double m_OnGround;
	DOUBLE2 m_Velocity;
	// Funks -----------------------------
	void DoCollitions(
		HitRegion **hitHoriPtr, HitRegion **hitVertPtr,
		DOUBLE2 *pos, DOUBLE2 *velocity);
	double ReturnGoodLen(double getal1, double getal2, double centerXY);
	// -------------------------
	// Disabling default copy constructor and default
	// assignment operator.
	// -------------------------
	pusher(const pusher& yRef);
	pusher& operator=(const pusher& yRef);
};


