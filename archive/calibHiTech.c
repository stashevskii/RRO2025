
#pragma config(Sensor, S1,     colorS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Motor,  motorA,          manipMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,          liftMotor,     tmotorEV3_Medium, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

long r1Min = 19;
long g1Min = 24;
long b1Min = 21;
long r1Max = 186;
long g1Max = 230;
long b1Max = 177;

long r2Min = 23;
long g2Min = 32;
long b2Min = 15;
long r2Max = 213;
long g2Max = 247;
long b2Max = 144;

long r1MinBlueGray = 0;
long g1MinBlueGray = 38;
long b1MinBlueGray = 39;
long r1MaxBlueGray = 263;
long g1MaxBlueGray = 278;
long b1MaxBlueGray = 336;

long r2MinBlueGray = 22;
long g2MinBlueGray = 47;
long b2MinBlueGray = 42;
long r2MaxBlueGray = 151;
long g2MaxBlueGray = 276;
long b2MaxBlueGray = 356;

int startDefault = 30;
int stopDefault = 30;

int defaultAngle90 = 40;
int defaultAngle180 = 150;

int defaultSpeed = 90;

#include "hitechnic-colour-v2.h"
tHTCS2 s;

#include "math.h"
#include "structures.h"
#include "sensors.h"
#include "stop.h"
#include "acceleration.h"
#include "colorsCheckers.h"
#include "debugger.h"
#include "line.h"
#include "motorSync.h"
#include "manipulator.h"
#include "lift.h"
#include "drive.h"
#include "cubes.h"

task main() {
	initSensor(&s, S4);
	showHSV(s);
}
