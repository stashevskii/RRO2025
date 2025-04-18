#pragma config(Sensor, S1,     colorS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Motor,  motorA,          manipMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,          liftMotor,     tmotorEV3_Medium, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int firstScan = 0, secondScan = 0;
int colors[4];
bool busy1 = false, busy2 = false, busy3 = false, busy4 = false;

long r1Min = 0;
long g1Min = 38;
long b1Min = 39;
long r1Max = 263;
long g1Max = 278;
long b1Max = 336;

long r2Min = 22;
long g2Min = 47;
long b2Min = 42;
long r2Max = 151;
long g2Max = 276;
long b2Max = 356;

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

int startDefault = 20;
int stopDefault = 20;

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
	long fileHandle = fileOpenRead("vals.txt");
	fileReadLong(fileHandle, &r1Min);
	fileReadLong(fileHandle, &g1Min);
	fileReadLong(fileHandle, &b1Min);
	fileReadLong(fileHandle, &r1Max);
	fileReadLong(fileHandle, &r1Max);
	fileReadLong(fileHandle, &r1Max);

	fileReadLong(fileHandle, &r2Min);
	fileReadLong(fileHandle, &g2Min);
	fileReadLong(fileHandle, &b2Min);
	fileReadLong(fileHandle, &r2Max);
	fileReadLong(fileHandle, &r2Max);
	fileReadLong(fileHandle, &r2Max);

	float rgbValsLeft[6];
	float rgbValsRight[6];
  setMotorBrakeMode(leftMotor, motorCoast);
  setMotorBrakeMode(rightMotor, motorCoast);

  for(int i = 0; i < 3; i++) {
  	rgbValsLeft[i] = 1000;
  	rgbValsRight[i] = 1000;
	}

 	for(int i = 3; i < 6; i++) {
 		rgbValsLeft[i] = 0;
 		rgbValsRight[i] = 0;
	}
	float rgbS1[3];
	float rgbS2[3];
	clearTimer(T1);
	while(time1[T1] < 5000) {
		displayBigTextLine(0, "%d", time1[T1]);
		sensorRGB(leftS, rgbS1[0], rgbS1[1], rgbS1[2]);
		sensorRGB(rightS, rgbS2[0], rgbS2[1], rgbS2[2]);
		for(int i = 0; i < 3; i++){
			rgbValsLeft[i] = min(rgbS1[i], rgbValsLeft[i]);
			rgbValsLeft[3 + i] = max(rgbS1[i], rgbValsLeft[3 + i]);
			rgbValsRight[i] = min(rgbS2[i], rgbValsRight[i]);
			rgbValsRight[3 + i] = max(rgbS2[i], rgbValsRight[3 + i]);
		}
	}

	fileHandle = fileOpenWrite("valsGray.txt");
	fileWriteLong(fileHandle, rgbValsLeft[0]);
	fileWriteLong(fileHandle, rgbValsLeft[1]);
	fileWriteLong(fileHandle, rgbValsLeft[2]);
	fileWriteLong(fileHandle, rgbValsLeft[3]);
	fileWriteLong(fileHandle, rgbValsLeft[4]);
	fileWriteLong(fileHandle, rgbValsLeft[5]);

	fileWriteLong(fileHandle, rgbValsRight[0]);
	fileWriteLong(fileHandle, rgbValsRight[1]);
	fileWriteLong(fileHandle, rgbValsRight[2]);
	fileWriteLong(fileHandle, rgbValsRight[3]);
	fileWriteLong(fileHandle, rgbValsRight[4]);
	fileWriteLong(fileHandle, rgbValsRight[5]);
	fileClose(fileHandle);

	delay(2000);
}
