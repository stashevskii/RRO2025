#pragma config(Sensor, S1,     colorS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     ultrasonicS,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          manipMotorRIght,   tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,          manipMotorLeft,    tmotorEV3_Medium, PIDControl, encoder)

#include "modules/headers.h"

task main() {
	initSensor(&s, colorS);
	initColors();
	initLineValues();
	startTask(initGrabberLeft);
	startTask(GrabberLeft);
	startTask(initGrabberRight);
	startTask(GrabberRight);
	runner();
}
