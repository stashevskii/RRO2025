#ifndef _DRIVE_H_
#define _DRIVE_H_

void driveCM(float power, float cm, int startPower = startDefault, int endPower = 15) {
	syncEold = 0;
	syncIsum = 0;

	if(startPower != 0) {
		globalDistB = localDistB;
		globalDistC = localDistC;
	}

	float enc = fromCmToDeg(cm);
	while(fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < 2 * fabs(enc))
		drive(power, power, enc, enc, startPower, endPower);

	localDistB -= enc;
	localDistC += enc;
}

void arc(float power, float r, float angle, int startPower = 35, int endPower = 20) {
	syncEold = 0;
	syncIsum = 0;

	if(r < 0) r *= 0.985;
	else r *= 1.005;

	if(startPower != 0) {
		globalDistB = localDistB;
		globalDistC = localDistC;
	}

	float rC = r - base / 2;
	float rB = r + base / 2;

	float lC = rC * PI * 2 * (angle / 360);
	float lB = rB * PI * 2 * (angle / 360);

	float powerC = power * rC / rB;
	float powerB = power;

	float encC = fromCmToDeg(lC) * sgn(r) * 1.01;
	float encB = fromCmToDeg(lB) * sgn(r) * 1.01;

	if(sgn(angle) == -1) {
		encC = fromCmToDeg(lC) * sgn(r) * 1.003;
		encB = fromCmToDeg(lB) * sgn(r) * 1.003;
	}


	if (r < 0) {
		powerC = power;
		powerB = power * rB / rC;
		encC = fromCmToDeg(lC) * sgn(r) * 1.015;
	  	encB = fromCmToDeg(lB) * sgn(r) * 1.015;

		if(sgn(angle) == -1) {
			encC = fromCmToDeg(lC) * sgn(r) * 1.015;
	  		encB = fromCmToDeg(lB) * sgn(r) * 1.015;
		}
	}


	while(max(fabs(nMotorEncoder[leftMotor] - localDistB), fabs(nMotorEncoder[rightMotor] - localDistC)) < max(fabs(encB), fabs(encC)))
		drive(fabs(powerB), fabs(powerC), encB, encC, startPower, endPower);

	localDistB -= encB;
	localDistC += encC;
}

// useable only in .h files
void turn(float power, float angle, int startPower = startDefault, int endPower = stopDefault) {
	syncEold = 0;
	syncIsum = 0;
	if(startPower != 0) {
		globalDistB = localDistB;
		globalDistC = localDistC;
	}

	float enc = d2d(angle, angle > 0 ? 1 : 1);
	while(fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < 2 * fabs(enc))
		drive(power , power, enc, -enc, startPower, endPower);

	localDistB -= enc;
	localDistC -= enc;
}

void turnRight(float power, float angle, int startPower = startDefault, int endPower = stopDefault) {
	syncEold = 0;
	syncIsum = 0;
	if(startPower != 0) {
		globalDistB = localDistB;
		globalDistC = localDistC;
	}

	float enc = d2d(angle, angle > 0 ? 1 : 1);
	while(fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < 2 * fabs(enc))
		drive(power , power, enc, -enc, startPower, endPower);

	localDistB -= enc;
	localDistC -= enc;
}

void turnLeft(float power, float angle, int startPower = startDefault, int endPower = stopDefault) {
	angle = -angle;
	syncEold = 0;
	syncIsum = 0;
	if(startPower != 0) {
		globalDistB = localDistB;
		globalDistC = localDistC;
	}

	float enc = d2d(angle, angle > 0 ? 1 : 1);
	while(fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < 2 * fabs(enc))
		drive(power , power, enc, -enc, startPower, endPower);

	localDistB -= enc;
	localDistC -= enc;
}

void turnOneMotor(tMotor m, int power, float angle, int startPower = startDefault, int endPower = stopDefault) {
	stopBC(0);
	syncEold = 0;
	syncIsum = 0;


	if(startPower != 0) {
		globalDistB = localDistB;
		globalDistC = localDistC;
	}

	float enc = d2d(angle) * 2;
	while (fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < fabs(enc)) {
		float speed = 0;
		if(m == leftMotor)
			speed = smoothB(startPower, power, endPower, -enc);
		else
			speed = smoothC(startPower, power, endPower, enc);
		motor[m] = speed;
	}

	if(m == leftMotor)
		localDistB -= enc;
	else
		localDistC += enc;
}

void turnLineRight(int power, int angle = defaultAngle90, int startPower = startDefault) {
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	turn(power, angle, startPower, 0);
	while(!checkColor(rightS, blackLine)) {
		drive(power, power, 1, -1, 0, 0);
	}

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void turnLineLeft(int power, int angle = defaultAngle90, int startPower = startDefault) {
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	turn(power, -angle, startPower, 0);
	while(!checkColor(leftS, blackLine)) {
		drive(power, power, -1, 1, 0, 0);
	}

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void turnLine180(int power, int angle = defaultAngle180, int startPower = startDefault) {
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	turn(power, angle, startPower, 0);
	if(angle < 0) {
		while(!checkColor(leftS, blackLine)) {
			drive(power, power, -1, 1, 0, 0);
		}

	} else {
		while(!checkColor(rightS, blackLine)) {
			drive(power, power, 1, -1, 0, 0);
		}
	}


	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

#endif