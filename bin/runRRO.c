#pragma config(Sensor, S1,     colorS,         sensorEV3_Color)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     colorS2,        sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          manipMotor2,   tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,          manipMotor,    tmotorEV3_Medium, PIDControl, encoder)

#include "../includes/allHeaders.h"

task main() {
	initColors();
	startTask(PIDManipRight);
	startTask(initManipRight);
	startTask(PIDManipLeft);
	startTask(initManipLeft);
	runner();
}
