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
	JoystickButton *a2Button;
	JoystickButton *b2Button;
	JoystickButton *r2Bumper;
	JoystickButton *l2Bumper;
	JoystickButton *x2Button;
	JoystickButton *y2Button;

	JoystickButton *l1StickButton;
	JoystickButton *r1StickButton;

	DriveSystem *drive;
	Shooter *shoot;

	float l1StickIn;
	float r1StickIn;

	float l1StickScale;
	float r1StickScale;

	float r2TrigIn;
	float r2TrigScale;

	SmartDashboard *dash;

protected:

};

#endif /* SRC_CONTROL_H_ */
