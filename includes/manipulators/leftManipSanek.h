void initManipLeftParams() {
    mLeft.power = 70;
    mLeft.u = 100;
    mLeft.eOld = 0;
	mLeft.motor = manipMotor;
	motor[mLeft.motor] = 0;
}

task initManipLeft() {
	clearTimer(T1);
	while(time1[T1] < 80) {
		motor[mLeft.motor] = -100;
	}
	nMotorEncoder[mLeft.motor] = 0;
}

task manipLeft() {
    delay(650);
    clearTimer(T4);
	while (time1[T4] < 200 || getMotorSpeed(mLeft.motor) != 0) {
		mLeft.e = mLeft.pos - nMotorEncoder[mLeft.motor];
		mLeft.u = mLeft.e + mLeft.eOld * 10;
    	if (mLeft.u > mLeft.power) {mLeft.u = mLeft.power;}
    	else if (mLeft.u < -mLeft.power) {mLeft.u = -mLeft.power;}
    	motor[mLeft.motor] = mLeft.u;
    	mLeft.eOld = mLeft.e;
  	}
  	clearTimer(T4);
  	while (time1[T4] < 100) {
    	mLeft.e = mLeft.pos - nMotorEncoder[mLeft.motor];
    	mLeft.u = mLeft.e + mLeft.eOld * 10
    	if (mLeft.u > mLeft.power) {mLeft.u = mLeft.power;} 
		else if (mLeft.u < -mLeft.power) {mLeft.u = -mLeft.power;}
    	motor[mLeft.motor] = mLeft.u;
    	mLeft.eOld = mLeft.e;
	}
  	motor[mLeft.motor] = 0;
}

void openFullLeft(bool afk = false) {
	mLeft.power = 100;
	mLeft.pos = 1000;
	if (afk) {stopBC(400);}
}

void floorGrabLeft(bool afk = false) {
	mLeft.power = 55;
	mLeft.pos = 390;
	if (afk) {stopBC(400);}
}

void openLeftNotFull(bool afk = false) {
	mLeft.power = 25;
	mLeft.pos = 515;
	if (afk) {stopBC(400);}
}