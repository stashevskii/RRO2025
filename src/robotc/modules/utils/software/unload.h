#ifndef _UNLOAD_H_
#define _UNLOAD_H_

float shipTurn = 75;
const float turnPower = 75;

void goShip(int w = 110) {
    localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

    setMotorSpeed(motorB, -65);
    setMotorSpeed(motorC, 65);
    delay(w);
    stopBC(0);

    localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void twoTurns(bool minus = false) {
    int m = (minus) ? -1 : 1;
    printNumber(m);
    turnOneMotor(leftMotor, turnPower, shipTurn * m, 20, 20);
    turnOneMotor(rightMotor, turnPower, shipTurn * m, 20, 20);
}

void right0left1() {
    twoTurns();
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -6, 30, 30);
    twoTurns(true);
}

void right1left0() {
    twoTurns();
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -5, 30, 30);
    twoTurns(true);
}

void openFunc(bool big) {
    if (big) {openLeftShip(true);}
    else {openRightShip(true);}
}

void twoSituations(bool big) {
    twoTurns();
    goShip(150);
    openFunc(big);
    driveCM(75, -5, 60, 60);
    twoTurns(true);
    openFunc(big);
    twoTurns();
    goShip(300);
    openFunc(big);
    driveCM(75, -5, 60, 60); 
    twoTurns(true);
}

void leaveContsAtShip(int r, int l) {
    if (r == 0 && l == 1) {right0left1();}
    else if (r == 1 && l == 0) {right1left0();}
    else if (r == 1 && l == 1) {twoSituations(true);} 
    else {twoSituations(false);}
}

#endif