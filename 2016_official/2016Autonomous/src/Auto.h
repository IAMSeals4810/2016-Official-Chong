#ifndef AUTO_H
#define AUTO_H

#include "Shooter.h"
#include "DriveSystem.h"
#include "Defense.h"
#include "ImageProcess.h"

class Auto{
private:
	DriveSystem* sys;
	//Defense* def; when developed
	Shooter* sho;
	ImageProcess* imp;

	bool targetAcquired;
	enum AutonPos{LEFT, RIGHT, NONE};
	enum AutonMode{TERRAIN, ARM, NONE_};
	AutonMode mode;
	AutonPos pos;
public:
	Auto();
	Auto(int mode, int pos);
	~Auto();

	void InternalAutonChooser();
	void TerrainCrosser();
	void ArmWallCrosser();
	void SetUpToShoot();
	void Shoot();
	bool Vision();

};



#endif /* SRC_AUTO_H_ */