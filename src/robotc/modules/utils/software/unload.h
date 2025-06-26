#ifndef _UNLOAD_H_
#define _UNLOAD_H_

float shipTurn = 70;
const float turnPower = 65;

void goShip(int w = 110) {
    localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];

    setMotorSpeed(motorB, -50);
    setMotorSpeed(motorC, 50);
    delay(w);
    stopBC(0);

    localDistB = nMotorEncoder[leftMotor];
	localDistC = nMotorEncoder[rightMotor];
}

void right0left1() {
    const int turn = 72;
    turnOneMotor(leftMotor, turnPower, turn, 50, 50);
    turnOneMotor(rightMotor, turnPower, turn, 50, 50);
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -5, 30, 30);
    turnOneMotor(rightMotor, turnPower, -turn, 50, 50);
    turnOneMotor(leftMotor, turnPower, -turn, 50, 50);
}

void right1left0() {
    const int turn = 72;
    turnOneMotor(rightMotor, turnPower, turn, 50, 50);
    turnOneMotor(leftMotor, turnPower, turn, 50, 50);
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -5, 30, 30);
    turnOneMotor(leftMotor, turnPower, -turn, 50, 50);
    turnOneMotor(rightMotor, turnPower, -turn, 50, 50);
}

void chooseOpen(bool big) {
    big ? openLeftShip(true) : openRightShip(true);
}

void chooseOpenRev(bool big) {
    big ? openRightShip(true) : openLeftShip(true);
}

void chooseClose(bool big) {
    big ? liftLeft45() : liftRight45();
}

void twoSits(bool big) {
    turnOneMotor(leftMotor, turnPower, shipTurn - 2, 50, 50);
    turnOneMotor(rightMotor, turnPower, shipTurn - 2, 50, 50);
    goShip(500);
    chooseOpen(big);
    driveCM(75, -5, 60, 60);
    turnOneMotor(rightMotor, turnPower, -shipTurn + 2, 50, 50);
    turnOneMotor(leftMotor, turnPower, -shipTurn + 2, 50, 50);
    chooseClose(big);
    turnOneMotor(rightMotor, turnPower, shipTurn, 50, 50);
    turnOneMotor(leftMotor, turnPower, shipTurn, 50, 50);
    goShip(350);
    chooseOpenRev(big);
    driveCM(75, -5, 60, 60); 
    turnOneMotor(leftMotor, turnPower, -shipTurn, 50, 50);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 50, 50);
}

void unload(int r, int l) {
    if (r == 0 && l == 1) {right0left1();}
    else if (r == 1 && l == 0) {right1left0();}
    else if (r == 1 && l == 1) {twoSits(true);} 
    else {twoSits(false);}
}

#endif