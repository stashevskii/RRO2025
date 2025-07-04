#ifndef _MANIPULATORLEFT_H_
#define _MANIPULATORLEFT_H_

const float manipKpLeft = 2;
const float manipKdLeft = 5;
const float manipKiLeft = 0.001;
float factorLeft = 1;

int manipPosLeft = 0;
float eoldManipLeft = 0;
float isumManipLeft = 0;

task GrabberLeft() {
	sleep(550);
	while(true) {
		float e = manipPosLeft - nMotorEncoder[manipMotorLeft];
		isumManipLeft = isumManipLeft + e * manipKiLeft;
		isumManipLeft = lim(isumManipLeft, -60, 60);
		float u = e * manipKpLeft + (e - eoldManipLeft) * manipKdLeft;
		motor[manipMotorLeft] = u * factorLeft;
		eoldManipLeft = e;
		sleep(1);
	}
}

task initGrabberLeft() {
	clearTimer(T1);
	while (time1[T1] < 80) {
		motor[manipMotorLeft] = -100;
	}
	nMotorEncoder[manipMotorLeft] = 0;
}

// left manipulator function template
void tl(float p, float k, bool afk, int w = 400) {
	factorLeft = p;
	manipPosLeft = k;
	if (afk) {stopBC(w);}
}

void grabLowLeft(bool afk = false) {
	tl(0.4, 420, afk);
}

void openLeftShip(bool afk = false) {
	tl(0.08, 600, afk);
}

void openLeftRubbish(bool afk = false) {
	tl(0.7, 380, afk);
}

void openLeft(bool afk = false) {
	tl(1.2, 1000, afk);
}

void openLeftSlow(bool afk = false) {
	tl(0.015, 1000, afk, 1500);
}

void liftLeft45(bool afk = false) { // 45 degr
	tl(0.45, 265, afk);
}

void liftContLeft(int size, bool afk = false) {
	if (size == 0) {
		tl(0.135, 257.5, afk, 500);
	} else {
		tl(0.15, 255, afk, 500);
	}
}

void closeLeft(bool afk = false) {
	tl(1.5, -500, afk);
}

#endif