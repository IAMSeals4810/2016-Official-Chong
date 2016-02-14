/*
 * Control.h
 *
 *  Created on: Feb 8, 2016
 *      Author: 1750800404
 */

#ifndef TELEOPCONTROL_H
#define TELEOPCONTROL_H

#include "Joystick.h"
#include "Buttons/JoystickButton.h"
#include "SmartDashboard/SmartDashboard.h"
#include "DriveSystem.h"
#include "Shooter.h"

class TeleopControl{

public:
	TeleopControl();
	~TeleopControl();

	void StickDrive();
	void ButtonControl();
	void TriggerControl();

private:

	Joystick *cont1;
	Joystick *cont2;
	JoystickButton *aButton;
	JoystickButton *bButton;

	JoystickButton *lStickButton;
	JoystickButton *rStickButton;

	DriveSystem *drive;
	Shooter *shoot;

	float lStickIn;
	float rStickIn;

	float lStickScale;
	float rStickScale;

	SmartDashboard *dash;

protected:

};

#endif /* SRC_CONTROL_H_ */
