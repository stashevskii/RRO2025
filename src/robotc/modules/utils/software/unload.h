#ifndef _UNLOAD_H_
#define _UNLOAD_H_

float shipTurn = 73;
const float turnPower = 68;

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

void right0left1() {
    int v = 3;
    turnOneMotor(leftMotor, turnPower, shipTurn + v, 20, 20);
    turnOneMotor(rightMotor, turnPower, shipTurn + v, 20, 20);
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -6, 30, 30);
    turnOneMotor(rightMotor, turnPower, -shipTurn - v, 20, 20);
    turnOneMotor(leftMotor, turnPower, -shipTurn - v, 20, 20);
}

void right1left0() {
    int v = 3;
    turnOneMotor(rightMotor, turnPower, shipTurn + v, 20, 20);
    turnOneMotor(leftMotor, turnPower, shipTurn + v, 20, 20);
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -5, 30, 30);
    turnOneMotor(leftMotor, turnPower, -shipTurn - v, 20, 20);
    turnOneMotor(rightMotor, turnPower, -shipTurn - v, 20, 20);
}

void chooseOpen(bool big) {
    big ? openLeftShip(true) : openRightShip(true);
}

void chooseOpenRev(bool big) {
    big ? openRightShip(true) : openLeftShip(true);
}

void chooseClose(bool big) {
    big ? closeLeft() : closeRight();
}

void twoSits(bool big) {
    int v = 3;
    turnOneMotor(leftMotor, turnPower, shipTurn, 20, 20);
    turnOneMotor(rightMotor, turnPower, shipTurn, 20, 20);
    goShip(150);
    chooseOpen(big);
    driveCM(75, -5, 60, 60);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 20, 20);
    turnOneMotor(leftMotor, turnPower, -shipTurn, 20, 20);
    chooseClose(big);
    turnOneMotor(rightMotor, turnPower, shipTurn - v, 20, 20);
    turnOneMotor(leftMotor, turnPower, shipTurn - v, 20, 20);
    goShip(300);
    chooseOpenRev(big);
    driveCM(75, -5, 60, 60); 
    turnOneMotor(leftMotor, turnPower, -shipTurn - v, 20, 20);
    turnOneMotor(rightMotor, turnPower, -shipTurn - v, 20, 20);
}

void unload(int r, int l) {
    if (r == 0 && l == 1) {right0left1();}
    else if (r == 1 && l == 0) {right1left0();}
    else if (r == 1 && l == 1) {twoSits(true);} 
    else {twoSits(false);}
}

#endif