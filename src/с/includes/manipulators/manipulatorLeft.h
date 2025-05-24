#ifndef _MANIPULATORLEFT_H_
#define _MANIPULATORLEFT_H_

const float manipKp = 2;
const float manipKd = 5;
const float manipKi = 0.001;
float manipKc = 1;

int manipPos = 0;
float eoldManip = 0;
float isumManip = 0;

task PIDManipLeft() {
	sleep(550);
	while(true) {
		float e = manipPos - nMotorEncoder[manipMotor];
		isumManip = isumManip + e * manipKi;
		isumManip = lim(isumManip, -60, 60);
		float u = e * manipKp + (e - eoldManip) * manipKd;
		motor[manipMotor] = u * manipKc;
		eoldManip = e;
		sleep(1);
	}
}

task initManipLeft() {
	clearTimer(T1);
	while(time1[T1] < 80) {
		motor[manipMotor] = -100;
	}
	resetMotorEncoder(manipMotor);
}

void funcTemplate(float p, float k, bool afk, int w = 400) {
	manipKc = p;
	manipPos = k;
	if (afk) {stopBC(w);}
}

void floorGrabLeft(bool afk = false) {
	funcTemplate(0.7, 395, afk);
}

void openLeftNotFull(bool afk = false) {
	funcTemplate(0.1, 585, afk);
}

void openLeftRubbish(bool afk = false) {
	funcTemplate(0.7, 380, afk);
}

void openFullLeft(bool afk = false) {
	funcTemplate(1.2, 1000, afk);
}

void openFullLeftLowSpeed(bool afk = false) {
	funcTemplate(0.4, 1000, afk);
}

void liftSomeLeft(bool afk = false) {
	funcTemplate(0.55, 185, afk);
}

void liftContLeft(int size, bool afk = false) {
	funcTemplate(0.13, 268, afk, 500);
}

void closeFullLeft(bool afk = false) {
	funcTemplate(1.5, -500, afk);
}

#endif