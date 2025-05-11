#ifndef _MANIPULATORRIGHT_H_
#define _MANIPULATORRIGHT_H_

const float manipKp2 = 2;
const float manipKd2 = 5;
const float manipKi2 = 0.001;
float manipKc2 = 1;

int manipPos2 = 0;
float eoldManip2 = 0;
float isumManip2 = 0;

task PIDManipRight() {
	sleep(550);
	while(true) {
		float e2 = manipPos2 - nMotorEncoder[manipMotor2];
		isumManip2 = isumManip2 + e2 * manipKi2;
		isumManip2 = lim(isumManip2, -60, 60);
		float u2 = e2 * manipKp2 + (e2 - eoldManip2) * manipKd2 + isumManip2;
		motor[manipMotor2] = u2 * manipKc2;
		eoldManip2 = e2;
		sleep(1);
	}
}

task initManipRight() {
	clearTimer(T1);
	while(time1[T1] < 80) {
		motor[manipMotor2] = 100;
	}
	resetMotorEncoder(manipMotor2)
}

void floorGrabRight(bool afk = false) {
	manipKc2 = 1;
	manipPos2 = -390;
	if (afk) {stopBC(400);}
}

void openRightNotFull(bool afk = false) {
	manipKc2 = 0.1;
	manipPos2 = -550;
	if (afk) {stopBC(400);}
}

void openFullRight(bool afk = false) {
	manipKc2 = 1;
	manipPos2 = -1000;
	if (afk) {stopBC(400);}
}

void openFullRightLowSpeed(bool afk = false) {
	manipKc2 = 0.4;
	manipPos2 = -1000;
	if (afk) {stopBC(750);}
}

void openFullRightLowLowSpeed(bool afk = false) {
	manipKc2 = 0.017;
	manipPos2 = -1050;
	if (afk) {stopBC(400);}
}

void closeFullRightLowSpeed(bool afk = false) {
	manipKc2 = 0.0865;
	manipPos2 = 550;
	if (afk) {stopBC(400);}
}

void liftSomeRight(bool afk = false, int waiting = 400) {
	manipKc2 = 0.55;
	manipPos2 = -170;
	if (afk) {stopBC(400);}
}

void liftContRight(int size, bool afk = false) {
	if (size == 0) {
		manipKc2 = 0.16;
		manipPos2 = -195.5;
	} else {
		manipKc2 = 0.23;
		manipPos2 = -195.5;
	}
	if (afk) {stopBC(425);}
}

void closeFullRight(bool afk = false) {
	manipKc2 = 1;
	manipPos2 = 500;
	if (afk) {stopBC(400);}
}

#endif