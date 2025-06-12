#ifndef _MANIPULATORRIGHT_H_
#define _MANIPULATORRIGHT_H_

const float manipKpRight = 2;
const float manipKdRight = 5;
const float manipKiRight = 0.001;
float factorRight = 1;

int manipPosRight = 0;
float eoldManipRight = 0;
float isumManipRight = 0;

task GrabberRight() {
	sleep(550);
	while(true) {
		float e2 = manipPosRight - nMotorEncoder[manipMotorRight];
		isumManipRight = isumManipRight + e2 * manipKiRight;
		isumManipRight = lim(isumManipRight, -60, 60);
		float u2 = e2 * manipKpRight + (e2 - eoldManipRight) * manipKdRight + isumManipRight;
		motor[manipMotorRight] = u2 * factorRight;
		eoldManipRight = e2;
		sleep(1);
	}
}

task initGrabberRight() {
	clearTimer(T2);
	while (time1[T2] < 80) {
		motor[manipMotorRight] = 100;
	}
	nMotorEncoder[manipMotorRight] = 0;
}

// right manipulator function template
void tr(float p, float k, bool afk, int w = 400) {
	factorRight = p;
	manipPosRight = k;
	if (afk) {stopBC(w);}
}

void grabLowRight(bool afk = false) {
	tr(0.7, -420, afk);
}

void openRightShip(bool afk = false) {
	tr(0.1, -600, afk);
}

void openRight(bool afk = false) {
	tr(1.2, -1000, afk);
}

void liftRight45(bool afk = false, int waiting = 400) {
	tr(0.55, -185, afk);
}

void liftContRight(int size, bool afk = false) {
	if (size == 0) {
		tr(0.25, -225, afk);
	} else {
		tr(0.25, -217, afk);
	}
}

void closeRight(bool afk = false) {
	tr(1.1, 500, afk);
}

#endif