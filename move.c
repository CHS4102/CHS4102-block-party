#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, openLoop,reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorFR,       tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void goForward (int pwr)
{
	motor[motorFL] = pwr;
	motor[motorFR] = pwr;
	motor[motorBR] = pwr;
	motor[motorBL] = pwr;
}
void goBackward (int pwr)
{
	motor[motorFL] = -pwr;
	motor[motorFR] = -pwr;
	motor[motorBR] = -pwr;
	motor[motorBL] = -pwr;
}
void goLeft (int pwr)
{
	motor[motorFL] = -pwr;
	motor[motorFR] = pwr;
	motor[motorBR] = -pwr;
	motor[motorBL] = pwr;
}
void goRight (int pwr)
{
	motor[motorFL] = pwr;
	motor[motorFR] = -pwr;
	motor[motorBR] = pwr;
	motor[motorBL] = -pwr;
}
void LeftForward (int pwr)
{
	motor[motorFL] = 0;
	motor[motorFR] = pwr;
	motor[motorBR] = 0;
	motor[motorBL] = pwr;
}
void RightForward (int pwr)
{
	motor[motorFL] = pwr;
	motor[motorFR] = 0;
	motor[motorBR] = pwr;
	motor[motorBL] = 0;
}
void RightBackward (int pwr)
{
	motor[motorFL] = 0;
	motor[motorFR] = -pwr;
	motor[motorBR] = 0;
	motor[motorBL] = -pwr;
}
void LeftBackward (int pwr)
{
	motor[motorFL] = -pwr;
	motor[motorFR] = 0;
	motor[motorBR] = -pwr;
	motor[motorBL] = 0;
}

void halt ()
{
	motor[motorFL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	motor[motorBL] = 0;
}
task main(){
	goForward(25);
	wait1Msec(500);
	goBackward(25);
	wait1Msec(500);
	goLeft(25);
	wait1Msec(500);
	goRight(25);
	wait1Msec(500);
	LeftForward(25);
	wait1Msec(500);
	LeftBackward(25);
	wait1Msec(500);
	RightForward(25);
	wait1Msec(500);
	RightBackward(25);
	wait1Msec(500);
	halt();
}
