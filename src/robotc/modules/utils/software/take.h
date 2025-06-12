#ifndef _TAKE_H_
#define _TAKE_H_

void takeDC() {
    driveCM(70, -1, 35, 35);
    turnLeft(60, 91, 20, 20);
    liftLeft45(true);
    liftRight45(true);
    driveCM(45, 16, 20, 20);
    closeLeft();
    closeRight(true);
    driveCM(80, -14.5, 20, 20);
}

void takeMR() {
    turnOneMotor(leftMotor, 80, -22, 40, 40);
    driveCM(70, -2, 70, 70);
    openRight(true);
    stopBC(250);
    driveCM(70, 11, 20, 20);
    grabLowRight(true);
    driveCM(65, -8, 15, 15);
    turnOneMotor(leftMotor, 70, 22, 40, 40);
}

void takeML() {
    turnOneMotor(rightMotor, 70, -22, 40, 40);
    driveCM(70, -2, 70, 70);
    openLeft(true);
    stopBC(250);
    driveCM(65, 11, 20, 20);
    grabLowLeft(true);
    driveCM(65, -8, 20, 20);
    turnOneMotor(rightMotor, 70, 22, 40, 40);
}

void retake() {
    lineCM(80, 10, 45, 45);
    openLeft();
    openRight();
    lineCM(50, 7.5, 35, 35);
    grabLowLeft();
    grabLowRight();
}

#endif