#ifndef _UNLOAD_H_
#define _UNLOAD_H_

float shipTurn = 67.5;
const float copyST = 67.5;
const float turnPower = 55;

void toShipRun(int w = 110) {
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
    align();
    turnOneMotor(leftMotor, turnPower, shipTurn + 2, 35, 25);
    turnOneMotor(rightMotor, turnPower, shipTurn + 2, 35, 25);
    toShipRun();
    openLeftNotFull();
    openRightNotFull(true);
    driveCM(65, -6, 30, 30);
    turnOneMotor(rightMotor, turnPower, -shipTurn + 4, 35, 25);
    turnOneMotor(leftMotor, turnPower, -shipTurn + 5.5, 35, 25);
}

void right1left0() {
    align();
    turnOneMotor(rightMotor, turnPower, shipTurn - 2, 35, 25);
    turnOneMotor(leftMotor, turnPower, shipTurn - 2, 35, 25);
    toShipRun();
    openLeftNotFull();
    openRightNotFull(true);
    driveCM(65, -5, 30, 30);
    turnOneMotor(leftMotor, turnPower, -shipTurn + 2, 35, 25);
    turnOneMotor(rightMotor, turnPower, -shipTurn + 3, 35, 25);
}

void twoSituations(bool big) {
    align();
    if (big && !big) {shipTurn += 6.35;}
    turnOneMotor(leftMotor, turnPower, shipTurn, 35, 25);
    if (big && !big) {shipTurn -= 5.5;}
    turnOneMotor(rightMotor, turnPower, shipTurn, 35, 25);
    toShipRun(150);
    if (big) {openLeftNotFull(true);}
    else {openRightNotFull(true);}
    driveCM(75, -5, 60, 60);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 35, 25);
    turnOneMotor(leftMotor, turnPower, -shipTurn, 35, 25);
    if (big) {closeFullLeft();}
    else {closeFullRight();}
    if (big) {shipTurn -= 1;}
    else {shipTurn -= 2;}
    turnOneMotor(rightMotor, turnPower, shipTurn, 35, 25);
    turnOneMotor(leftMotor, turnPower, shipTurn, 35, 25);
    toShipRun(300);
    if (big) {openRightNotFull(true);}
    else {openLeftNotFull(true);}
    driveCM(75, -5, 60, 60);
    turnOneMotor(leftMotor, turnPower, -shipTurn - 3, 35, 25);
    turnOneMotor(rightMotor, turnPower, -shipTurn - 3, 35, 25);
    shipTurn = copyST;
}

#endif