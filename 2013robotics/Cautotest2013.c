#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     kGyroSensor,    sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     S_lightsensor,  sensorLightActive)
#pragma config(Sensor, S4,     HTIRS2,              sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     M_DriveFL,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     M_DriveBR,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     M_DriveFR,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     M_DriveBL,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     M_Lift,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     M_Unused,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    SV_TiltLeft,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    SV_TiltRight,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    SV_Swivel,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    SV_LightSensor,       tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool  GB_liftTargetSet; //to indicate automatic target for lift
int   GI_liftTarget;    //target value

int expectedGyro=0;//used to integrate and track rotations
int testScore=-1; //-1,     0,1,2  LMR for testing without IR

float powerfactor;
float batvolt;

#include "CHSGyroDriver.c"
void reInitializeGyro(){
	fGyroAngle=0;
	expectedGyro=0;
}

#include "JoystickDriver.c"
#include "getJoyValues.c"
#include "constants.c"

#include "Driving.c"
#include "ServoFns.c"
#include "LiftFns.c"
#include "drivers/hitechnic-irseeker-v2.h"
#include "TrackingRoutines.c"
#include "autoSub.c"
#include "ScoreLeft.c"
#include "ScoreRight.c"
#include "ScoreMiddle.c"



void initializeRobot(){
	//StartTask(GyroDeviceDriver,255);

	batvolt = externalBattery;
 	if(batvolt==-1) powerfactor=1;
 	else
 	{
   	powerfactor=12800.0/batvolt;
 	}

  servoChangeRate[SV_TiltLeft]        = 10;
  servoChangeRate[SV_TiltRight]       = 10;
  servoChangeRate[SV_Swivel]          = 10;
  servoChangeRate[SV_LightSensor]      = 0;

  nMotorEncoder[M_Lift]    = 0;

  servo[SV_Swivel]=C_SVSWIVELCENTER;
  servo[SV_TiltRight]=C_SVTILTRIGHTUP;
  servo[SV_TiltLeft]=C_SVTILTLEFTUP;
  servo[SV_LightSensor]=C_SVLIGHTSENSORIN;

  wait1Msec(2000);
  servo[SV_TiltRight]=C_SVTILTRIGHTDOWN;
  servo[SV_TiltLeft]=C_SVTILTLEFTDOWN;
  wait1Msec(200);
  servo[SV_TiltRight]=C_SVTILTRIGHTUP;
  servo[SV_TiltLeft]=C_SVTILTLEFTUP;

  reInitializeGyro();//should be anyway


  // the default DSP mode is 1200 Hz.
  //tHTIRS2DSPMode _mode = DSP_1200;
}

task main()
{
  int _dirAC = 0;

	initializeRobot();

	waitForStart();

	//for maintenance
	servo[SV_Swivel]=C_SVSWIVELCENTER;
  servo[SV_TiltRight]=C_SVTILTRIGHTUP;
  servo[SV_TiltLeft]=C_SVTILTLEFTUP;
  servo[SV_LightSensor]=C_SVLIGHTSENSORIN;

  /*
  int loc=scanForEdge(C_SVLIGHTSENSORIN,C_SVLIGHTSENSORMXOUT+100);
  setLight(loc);
  wait1Msec(200);
  //direction*=-1;
  //while(true){};
  trackEdge(C_SVLIGHTSENSORMXOUT,C_SVLIGHTSENSORIN,20000);
  return;
  */

/*
  autoRotate(360.0);
  wait1Msec(200);
  //autoRotate(0-fGyroAngle);

  while(true) gyroDisplay();
  return;
  */

  autoRotate(45.0);
  autoDrive(7,24.0);
  autoRotate(-90.0);
  autoDrive(5,24.0);
  autoRotate(-90.0);
  autoDrive(3,24.0);
  autoRotate(-90.0);
  autoDrive(1,24.0);
  autoRotate(-135.0);

}
