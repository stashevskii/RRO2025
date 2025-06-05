#ifndef _LINE_H_
#define _LINE_H_

const float lineKp = 0.4;
const float lineKd = 4.1;
const float lineKi = 0.001;
const float cS = 40;

const float lineKpOne = 1.1;
const float lineKdOne = 5.8;
const float lineKiOne = 0.01;
const float cSOne = 50;

float eold = 0;
float eoldInner = 0;
float isum = 0;
float isumInner = 0;

float line(int power) {
	float r1, g1, b1, r2, g2, b2;
	sensorRGB(leftS, r1, g1, b1);
	sensorRGB(rightS, r2, g2, b2);

	float e = (r1 + g1 + b1) / 3 - (r2 + g2 + b2) / 3;
	float kp = calcCoefficient(power, lineKp, cS);
	float kd = calcCoefficient(power, lineKd, cS);
	float ki = calcCoefficient(power, lineKi, cS);
	isum = isum + e * ki;
	isum = lim(isum, -60, 60);
	float u = kp * e + (e - eold) * kd + isum;
	eold = e;
	return u;
}

float lineS2Inner(int power, int gray = 20) {
	float r1, g1, b1;
	sensorRGB(leftS, r1, g1, b1);

	float eInner = gray - (r1 + g1 + b1) / 3;
	float kpInner = calcCoefficient(power, lineKpOne, cSOne);
	float kdInner = calcCoefficient(power, lineKdOne, cSOne);
	float kiInner = calcCoefficient(power, lineKiOne, cSOne);
	isumInner = isumInner + eInner * kiInner;
	isumInner = lim(isumInner, -60, 60);
	float u = kpInner * eInner + (eInner - eoldInner) * kdInner + isumInner;
	eoldInner = eInner;
	return u;
}

void lineReading(int power, int startPower = startDefault, int *cols) {
	nMotorEncoder[motorC] = 0;
	eold = 0;
	isum = 0;
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if (startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	int i = 0, count = 0, degr = 150;

	while (i < 6) {
		float speedB = smoothB(startPower, power, 0, 0);
		float speedC = smoothC(startPower, power, 0, 0);
		float u = line(speedC);
		float powerB =  -speedB - u;
		float powerC =  speedC - u;
		float ratio = max(max(1, fabs(powerB / 100)), fabs(powerC / 100));

		powerB /= ratio;
		powerC /= ratio;

		motor[motorB] = powerB;
		motor[motorC] = powerC;

		if (nMotorEncoder[motorC] > i * degr) {
			cols[i] = getSum(s);
			i++;
		}
	}

	rewriteColors(cols);

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void lineCM(int power, float cm, int startPower = startDefault, int endPower = stopDefault) {
	eold = 0;
	isum = 0;
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	float enc = fromCmToDeg(cm);

	while(fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < 2 * fabs(enc)) {
		float speedB = smoothB(startPower, power, endPower, enc);
		float speedC = smoothC(startPower, power, endPower, enc);
		float u = line(speedC);

		float powerB =  -speedB - u;
		float powerC =  speedC - u;
		float ratio = max(max(1, fabs(powerB / 100)), fabs(powerC / 100));
		powerB /= ratio;
		powerC /= ratio;

		motor[motorB] = powerB;
		motor[motorC] = powerC;
	}

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void XCross(int power, int n, int startPower = startDefault, bool toWheels = true, int dist = 8, lineColor stopColorLeft = blackLine, lineColor stopColorRight = blackLine) {
	eold = 0;
	isum = 0;
	int cur = 0;
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];s
		globalDistC = nMotorEncoder[rightMotor];
	}
	bool flag = false;

	while (cur < n) {
		float speedB = smoothB(startPower, power, 0, 0);
		float speedC = smoothC(startPower, power, 0, 0);
		float u = line(speedC);

		float powerB =  -speedB - u;
		float powerC =  speedC - u;
		float ratio = max(max(1, fabs(powerB / 100)), fabs(powerC / 100));
		powerB /= ratio;
		powerC /= ratio;

		motor[leftMotor] = powerB;
		motor[rightMotor] = powerC;

		if (checkColor(leftS, stopColorLeft) && checkColor(rightS, stopColorRight)) {
			if (!flag) {
				// driveCM(power, 2, power, power);
				cur++;
				flag = true;
			}
		} else {
			flag = false;
		}
		delay(1);
	}

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if (toWheels) {
		driveCM(power, dist, power, startPower)
	}
}

void QCross(int power, int n, int startPower = startDefault, bool last2wheels = false, int dist = 5) {
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {XCross(power - 20, 1, startPower, last2wheels, 0)}
		else {XCross(power, 1, startPower, true, dist)}
	}
}

void crossS2Inner(int power, int n, int startPower = startDefault) {
	eold = 0;
	isum = 0;
	int cur = 0;
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	bool flag = false;

	while (cur < n) {
		float speedB = smoothB(startPower, power, 0, 0);
		float speedC = smoothC(startPower, power, 0, 0);
		float u = lineS2Inner(speedC);

		float powerB =  -speedB - u;
		float powerC =  speedC - u;
		float ratio = max(max(1, fabs(powerB / 100)), fabs(powerC / 100));
		powerB /= ratio;
		powerC /= ratio;

		motor[leftMotor] = powerB;
		motor[rightMotor] = powerC;

		if(checkColor(leftS, blackLine) && checkColor(rightS, blackLine)) {
			if(!flag) {
				cur++;
				flag = true;
			}
		} else {
			flag = false;
		}
		delay(1);
	}

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void lineS2InnerCM(int power, float cm, int startPower = startDefault, int endPower = stopDefault) {
	eold = 0;
	isum = 0;
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	if(startPower != 0) {
		globalDistB = nMotorEncoder[leftMotor];
		globalDistC = nMotorEncoder[rightMotor];
	}

	float enc = fromCmToDeg(cm);

	while(fabs(nMotorEncoder[leftMotor] - localDistB) + fabs(nMotorEncoder[rightMotor] - localDistC) < 2 * fabs(enc)) {
		float speedB = smoothB(startPower, power, endPower, enc);
		float speedC = smoothC(startPower, power, endPower, enc);
		float u = lineS2Inner(speedC);

		float powerB =  -speedB - u;
		float powerC =  speedC - u;
		float ratio = max(max(1, fabs(powerB / 100)), fabs(powerC / 100));
		powerB /= ratio;
		powerC /= ratio;

		motor[leftMotor] = powerB;
		motor[rightMotor] = powerC;
	}

	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void align() {
	eold = 0;
	isum = 0;
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

	clearTimer(T1);
	while (time1[T1] < 220) {
		float u = line(50);
		motor[motorB] = 12 - u;
		motor[motorC] = 12 - u;
	}
	
	localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}


#endif