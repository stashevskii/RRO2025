#ifndef _ACCELERATION_H_
#define _ACCELERATION_H_

float globalDistB = 0;
float globalDistC = 0;

float localDistB = 0;
float localDistC = 0;

float boost = 19.5;
float slow = -9.8;

float smoothB(int startSpeed, int maxSpeed, int stopSpeed, int enc = 0, float ratio = 1, float boostK = boost, float slowK = slow){
	if (ratio > 1) ratio = 1;
	boostK *= ratio;
	slowK *= ratio;
	startSpeed *= ratio;
	stopSpeed *= ratio;
	float finalSpeed = fabs(maxSpeed);
	finalSpeed = min(finalSpeed, sqrt(startSpeed * startSpeed + 2 * boostK * fabs(nMotorEncoder[leftMotor] - globalDistB)));

	if (stopSpeed != 0)
		finalSpeed = min(finalSpeed, sqrt(stopSpeed * stopSpeed - 2 * slowK * (fabs(enc) - fabs(nMotorEncoder[leftMotor] - localDistB))));
	if (enc != 0)
		finalSpeed *= sgn(enc);
	return finalSpeed;
}

float smoothC(int startSpeed, int maxSpeed, int stopSpeed, int enc = 0, float ratio = 1, float boostK = boost, float slowK = slow) {
	if (ratio > 1) ratio = 1;
	boostK *= ratio;
	slowK *= ratio;
	startSpeed *= ratio;
	stopSpeed *= ratio;
	float finalSpeed = fabs(maxSpeed);
	finalSpeed = min(finalSpeed, sqrt(startSpeed * startSpeed + 2 * boostK * fabs(nMotorEncoder[rightMotor] - globalDistC)));

	if (stopSpeed != 0)
		finalSpeed = min(finalSpeed, sqrt(stopSpeed * stopSpeed - 2 * slowK * (fabs(enc) - fabs(nMotorEncoder[rightMotor] - localDistC))));
	if (enc != 0)
		finalSpeed *= sgn(enc);
	return finalSpeed;
}

#endif