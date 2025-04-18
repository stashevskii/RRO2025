#pragma config(Sensor, S1,     colorS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     colorS2,        sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Motor,  motorA,          manipMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,          manipMotor2,   tmotorEV3_Medium, openLoop, encoder)

#include "../includes/allHeaders.h"

float ma = 0, mb = 0, mc = 0, md = 0;

int motors_or_sensors = 0;
string motors = "xx motors";
string sensors = "xx sensors";
string battery = "xx battery";

int wait = 100;
bool flag = true;

task main() {
	setMotorBrakeMode(motorB, motorCoast);
	setMotorBrakeMode(motorC, motorCoast);
	setMotorBrakeMode(motorA, motorCoast);
	setMotorBrakeMode(motorD, motorCoast);
	while (1 == 1) {
		delay(wait);
		eraseDisplay();
		while (!getButtonPress(buttonEnter)) {
			delay(wait);
			if (getButtonPress(buttonUp) && motors_or_sensors > 0) {
				motors_or_sensors--;
				delay(wait);
				} else if (getButtonPress(buttonDown) && motors_or_sensors < 3) {
				motors_or_sensors++;
				delay(wait);
			}

			if (motors_or_sensors == 0) {motors = "-> motors"; sensors = "xx sensors"; battery = "xx battery";}
			else if (motors_or_sensors == 1) {sensors = "-> sensors"; motors = "xx motors"; battery = "xx battery";}
			else {motors = "xx motors"; sensors = "xx sensors"; battery = "-> battery";}

			displayBigStringAt(20, 100, "%s", motors);
			displayBigStringAt(20, 80, "%s", sensors);
			displayBigStringAt(20, 60, "%s", battery);
			delay(wait);
		}
		resetMotorEncoder(motorA);
		resetMotorEncoder(motorB);
		resetMotorEncoder(motorC);
		resetMotorEncoder(motorD);
		eraseDisplay();
	start_:
		while (!getButtonPress(buttonLeft)) {
			if (motors == "-> motors") {
				if (getButtonPress(buttonRight)) {
					resetMotorEncoder(motorB);
					resetMotorEncoder(motorC);
					resetMotorEncoder(motorD);
					resetMotorEncoder(motorA);
					mb = 0;
					mc = 0;
					md = 0;
					ma = 0;
					delay(wait);
					eraseDisplay();
				}
				mb = getMotorEncoder(motorB) * (6.24 / PI) / 360 * 10;
				mc = getMotorEncoder(motorC) * (6.24 / PI) / 360 * 10;
				ma = getMotorEncoder(motorA) * (6.24 / PI) / 360 * 10;
				md = getMotorEncoder(motorD) * (6.24 / PI) / 360 * 10;
				displayBigStringAt(0, 100, "B - %.2f", mb);
				displayBigStringAt(0, 80, "C - %.2f", mc);
				displayBigStringAt(0, 60, "D - %.2f", md);
				displayBigStringAt(0, 40, "A - %.2f", ma);
				} else if (battery == "-> battery") {
				displayBigStringAt(0, 100, "voltage - %.2f v", getBatteryVoltage());
				displayBigStringAt(0, 80, "amperage - %.2f am", getBatteryCurrent());
				} else {
				delay(wait);
				eraseDisplay();
			sensor_menu:
				delay(wait);
				eraseDisplay();
				flag = true;
				while (flag) {
					delay(wait);
					if (getButtonPress(buttonUp) && sensor_choose > 0) {
						sensor_choose--;
						delay(wait);
						} else if (getButtonPress(buttonDown) && sensor_choose < 4) {
						sensor_choose++;
						delay(wait);
					}

					if (sensor_choose == 0) {
						p1 = "-> port 1";
						p2 = "xx port 2";
						p3 = "xx port 3";
						p4 = "xx port 4";
					}
					else if (sensor_choose == 1) {
						p1 = "xx port 1";
						p2 = "-> port 2";
						p3 = "xx port 3";
						p4 = "xx port 4";
					}
					else if (sensor_choose == 2) {
						p1 = "xx port 1";
						p2 = "xx port 2";
						p3 = "-> port 3";
						p4 = "xx port 4";
					}
					else {
						p1 = "xx port 1";
						p2 = "xx port 2";
						p3 = "xx port 3";
						p4 = "-> port 4";
					}
					if (getButtonPress(buttonLeft)) {flag = false; goto start_; delay(wait);}
					if (getButtonPress(buttonEnter)) {
						eraseDisplay();
						delay(wait);
						while (!getButtonPress(buttonLeft)) {
							if (sensor_choose == 0) {
								eraseDisplay();
								if (port1 == 0) {
									displayBigStringAt(0, 100, "connect sensor!");
									} else if (port1 == 2) {
									sensorRGB(S1, rrr, ggg, bbb);
									displayBigStringAt(0, 120, "r %.2f", rrr);
									displayBigStringAt(0, 100, "g %.2f", ggg);
									displayBigStringAt(0, 80, "b %.2f", bbb);
									} else {
									delay(wait);
									if (htDebugger(s) == 1) {delay(wait);goto sensor_menu;}
								}
								} else if (sensor_choose == 1) {
								if (port2 == 0) {
									displayBigStringAt(0, 100, "connect sensor!");
									} else if (port2 == 2) {
									sensorRGB(S2, rrr, ggg, bbb);
									displayBigStringAt(0, 100, "r %.2f", rrr);
									displayBigStringAt(0, 80, "g %.2f", ggg);
									displayBigStringAt(0, 60, "b %.2f", bbb);
									} else {
									delay(wait);
									if (htDebugger(s) == 1) {delay(wait);goto sensor_menu;}
								}
								} else if (sensor_choose == 2) {
								if (port3 == 0) {
									displayBigStringAt(0, 100, "connect sensor!");
									} else if (port3 == 2) {
									sensorRGB(S3, rrr, ggg, bbb);
									displayBigStringAt(0, 100, "r %.2f", rrr);
									displayBigStringAt(0, 80, "g %.2f", ggg);
									displayBigStringAt(0, 60, "b %.2f", bbb);
									} else {
									delay(wait);
									if (htDebugger(s) == 1) {delay(wait);goto sensor_menu;}
								}
								} else if (sensor_choose == 3) {
								if (port4 == 0) {
									displayBigStringAt(0, 100, "connect sensor!");
									} else if (port4 == 2) {
									sensorRGB(S4, rrr, ggg, bbb);
									displayBigStringAt(0, 100, "r %.2f", rrr);
									displayBigStringAt(0, 80, "g %.2f", ggg);
									displayBigStringAt(0, 60, "b %.2f", bbb);
									} else {
									delay(wait);
									if (htDebugger(s) == 1) {delay(wait);goto sensor_menu;}
								}
							}
						}
						delay(wait);
						goto sensor_menu;
					}
					displayBigStringAt(0, 100, "%s", p1);
					displayBigStringAt(0, 80, "%s", p2);
					displayBigStringAt(0, 60, "%s", p3);
					displayBigStringAt(0, 40, "%s", p4);
					delay(wait);
				}
			}
		}
	}
}
