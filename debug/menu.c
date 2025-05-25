#pragma config(Sensor, S1,     ,               sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,           ,             tmotorEV3_Medium, openLoop, encoder)

#include "../src/robotc/includes/utils/software/math.h"
#include "calibration.h"

const int space = 20;
const int defaultX = 120;
const int maxArrLen = 100;
int curPos = 1;
int maxPos;
string a[maxArrLen];

void changePos(int x) {
	eraseDisplay();
	curPos = curPos + x;
	if (curPos == 0) {
		curPos += maxPos;
	} else if (curPos == maxPos + 1) {
		curPos = 1;
	}

	displayBigStringAt(0, defaultX - space * (curPos - 1), "-");
	for(int i = 0; i < maxPos; i++) {
		displayBigStringAt(20, defaultX - space * i, a[i]);
	}
}

int handler() {
	eraseDisplay();
	if (curPos == 1) {
		resetMotorEncoder(motorB);
		resetMotorEncoder(motorC);
		while (!getButtonPress(buttonLeft)) {
			float mb = getMotorEncoder(motorB) * (6.24 / PI) / 360 * 10;
			float mc = getMotorEncoder(motorC) * (6.24 / PI) / 360 * 10;
			displayBigStringAt(0, 100, "B - %.2f", mb);
			displayBigStringAt(0, 80, "C - %.2f", mc);
		}
		return 0;
	} else if (curPos == 2) {
		while (!getButtonPress(buttonLeft)) {
			displayBigStringAt(0, 100, "voltage - %.2f", getBatteryVoltage());
			displayBigStringAt(0, 80, "amperage - %.2f", getBatteryCurrent());
		}
		return 0;
	} else if (curPos == 3) {
		calibrate();
		return 0;
	}
	return 1;
}

task main() {
	setMotorBrakeMode(leftMotor, motorCoast);
	setMotorBrakeMode(rightMotor, motorCoast);

	maxPos = 3;
	a[0] = "motors";
	a[1] = "battary";
	a[2] = "calibration";
	changePos(0);

	mainMenu:
		changePos(0);
		while (true) {
			if (getButtonPress(buttonUp)) {
				changePos(-1);
				delay(500);
			} else if (getButtonPress(buttonDown)) {
				changePos(1);
				delay(500);
			} else if (getButtonPress(buttonEnter)) {
				while (handler() != 0) {}
				goto mainMenu;
			}
		}
}
