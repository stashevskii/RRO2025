#ifndef _UNLOAD_H_
#define _UNLOAD_H_

float shipTurn = 73;
const float turnPower = 80;

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
    turnOneMotor(leftMotor, turnPower, shipTurn, 26, 26);
    turnOneMotor(rightMotor, turnPower, shipTurn, 26, 26);
    toShipRun();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -6, 30, 30);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 26, 26);
    turnOneMotor(leftMotor, turnPower, -shipTurn, 26, 26);
}

void right1left0() {
    align();
    turnOneMotor(rightMotor, turnPower, shipTurn, 26, 26);
    turnOneMotor(leftMotor, turnPower, shipTurn, 26, 26);
    toShipRun();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -5, 30, 30);
    turnOneMotor(leftMotor, turnPower, -shipTurn, 26, 26);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 26, 26);
}

void twoSituations(bool big) {
    align();
    turnOneMotor(leftMotor, turnPower, shipTurn, 26, 26);
    turnOneMotor(rightMotor, turnPower, shipTurn, 26, 26);
    toShipRun(150);
    if (big) {openLeftShip(true);}
    else {openRightShip(true);}
    driveCM(75, -5, 60, 60);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 26, 26);
    turnOneMotor(leftMotor, turnPower, -shipTurn, 26, 26);
    if (big) {closeLeft();}
    else {closeRight();}
    turnOneMotor(rightMotor, turnPower, shipTurn - 3, 26, 26);
    turnOneMotor(leftMotor, turnPower, shipTurn - 3, 26, 26);
    toShipRun(300);
    if (big) {openRightShip(true);}
    else {openLeftShip(true);}
    driveCM(75, -5, 60, 60);
    turnOneMotor(leftMotor, turnPower, -shipTurn - 3, 26, 26);
    turnOneMotor(rightMotor, turnPower, -shipTurn - 3, 26, 26);
}

#endif