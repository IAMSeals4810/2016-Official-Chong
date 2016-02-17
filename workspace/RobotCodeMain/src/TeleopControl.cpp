/*
 * Control.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: 1750800404
 */

#include "TeleopControl.h"

/*A Button, 0
B Button, 1
X Button, 2
Y Button, 3
L Button, 4
R Button, 5
Back, 6
Start, 7
Left Stick Button, 8
Right Stick Button 9
Left Analog X Axis, 0
Left Analog Y Axis, 1
Right Analog X Axis, 4
Right Analog Y Axis, 5
Left Trigger Axis, 2
Right Trigger Axis, 3*/

TeleopControl::TeleopControl(){

	cont1 = new Joystick(0);
	cont2 = new Joystick(1);
	l1StickButton = new JoystickButton(cont1, 8);
	r1StickButton = new JoystickButton(cont1, 9);
	a2Button = new JoystickButton(cont2, 0);
	x2Button = new JoystickButton(cont2, 2);
	y2Button = new JoystickButton(cont2, 3);
	b2Button = new JoystickButton(cont2, 1);
	r2Bumper = new JoystickButton(cont2, 5);
	l2Bumper = new JoystickButton(cont2, 4);

	drive = new DriveSystem();
	shoot = new Shooter();

	dash = new SmartDashboard();

}

TeleopControl::~TeleopControl(){

	delete cont1;
	delete cont2;
	delete a2Button;
	delete b2Button;
	delete x2Button;
	delete y2Button;
	delete l1StickButton;
	delete r1StickButton;
	delete r2Bumper;
	delete l2Bumper;
	delete drive;
	delete shoot;
	//delete dash;

}

void TeleopControl::StickDrive(){

	l1StickIn = cont1->GetRawAxis(1);
	r1StickIn = cont1->GetRawAxis(5);
	l1StickScale = pow(l1StickIn, 5);
	r1StickScale = pow(r1StickIn, 5);

	if (l1StickIn <= 0.5 && l1StickIn >= -0.5){

		drive->Drive(0, r1StickScale);

	}

	if (r1StickIn <= 0.5 && r1StickIn >= -0.5){

		drive->Drive(l1StickScale, 0);

	}

	if ((l1StickIn > 0.5 || l1StickIn < -0.5) && (r1StickIn > 0.5 || r1StickIn < -0.5)) {

		drive->Drive(l1StickScale, r1StickScale);

	}

	dash->PutNumber("Left Stick Y Raw", l1StickIn);
	dash->PutNumber("Left Stick Y Scaled", l1StickScale);
	dash->PutNumber("Right Stick Y Raw", r1StickIn);
	dash->PutNumber("Right Stick Y Scaled", r1StickScale);

}

void TeleopControl::ButtonControl(){

	r2TrigIn = cont2->GetRawAxis(3);
	r2TrigScale = (r2TrigIn - 0.25) * 1.33;

	if((l1StickButton->Get() || r1StickButton->Get()) && drive->casterLow == false){

		drive->LowerCasters();

	}

	else if((l1StickButton->Get() || r1StickButton->Get()) && drive->casterLow == true){

		drive->RaiseCasters();

	}

	if(a2Button->Get()){
		shoot->LowGoal(0.25, 100);
	}

	if(b2Button->Get()){
		shoot->HighGoal(0.25, 1000);
	}

	if(x2Button->Get()){
		shoot->Lower(0.25);
	}

	if(y2Button->Get()){
		shoot->Raise(0.25);
	}

	if(r2TrigIn > 0.25){
		shoot->Pickup(r2TrigScale);
	}

	if(r2Bumper->Get()){
		shoot->Shoot(5200, 5200);
	}

	if(l2Bumper->Get()){
		shoot->Shoot(4000, 4000);
	}

}

void TeleopControl::TriggerControl(){

}
