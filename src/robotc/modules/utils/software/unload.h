#ifndef _UNLOAD_H_
#define _UNLOAD_H_

float shipTurn = 70;
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

void right0left1() {
    // align();
    turnOneMotor(leftMotor, turnPower, shipTurn - 5, 20, 20);
    turnOneMotor(rightMotor, turnPower, shipTurn - 5, 20, 20);
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -6, 30, 30);
    turnOneMotor(rightMotor, turnPower, -shipTurn + 5, 20, 20);
    turnOneMotor(leftMotor, turnPower, -shipTurn + 5, 20, 20);
}

void right1left0() {
    // align();
    turnOneMotor(rightMotor, turnPower, shipTurn - 3, 20, 20);
    turnOneMotor(leftMotor, turnPower, shipTurn - 3, 20, 20);
    goShip();
    openLeftShip();
    openRightShip(true);
    driveCM(65, -5, 30, 30);
    turnOneMotor(leftMotor, turnPower, -shipTurn + 3, 20, 20);
    turnOneMotor(rightMotor, turnPower, -shipTurn + 3, 20, 20);
}

void twoSituations(bool big) {
    // align();
    turnOneMotor(leftMotor, turnPower, shipTurn, 20, 20);
    turnOneMotor(rightMotor, turnPower, shipTurn, 20, 20);
    goShip(150);
    if (big) {openLeftShip(true);}
    else {openRightShip(true);}
    driveCM(75, -5, 60, 60);
    turnOneMotor(rightMotor, turnPower, -shipTurn, 20, 20);
    turnOneMotor(leftMotor, turnPower, -shipTurn, 20, 20);
    if (big) {closeLeft();}
    else {closeRight();}
    turnOneMotor(rightMotor, turnPower, shipTurn - 2.5, 20, 20);
    turnOneMotor(leftMotor, turnPower, shipTurn - 2.5, 20, 20);
    goShip(300);
    if (big) {openRightShip(true);}
    else {openLeftShip(true);}
    driveCM(75, -5, 60, 60); 
    turnOneMotor(leftMotor, turnPower, -shipTurn + 5, 20, 20);
    turnOneMotor(rightMotor, turnPower, -shipTurn + 5, 20, 20);
}

void leaveContsAtShip(int r, int l) {
    if (r == 0 && l == 1) {right0left1();}
    else if (r == 1 && l == 0) {right1left0();}
    else if (r == 1 && l == 1) {twoSituations(true);} 
    else {twoSituations(false);}
}

#endif