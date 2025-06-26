#ifndef _TAKE_H_
#define _TAKE_H_

void takeDC() {
    turnLeft(60, 91, 20, 20);
    liftLeft45();
    liftRight45(true);
    driveCM(40, 16, 20, 20);
    closeLeft();
    closeRight(true);
    driveCM(80, -14.5, 20, 20);
}

void takeMR(int cm = 10) {
    align();
    turnOneMotor(leftMotor, 65, -18, 40, 40);
    driveCM(70, -2, 70, 70);
    openRight(true);
    stopBC(250);
    driveCM(40, cm, 20, 20);
    grabLowRight(true);
    driveCM(65, -7.5, 15, 15);
    turnOneMotor(leftMotor, 65, 18, 40, 40);
}

void takeML(int cm = 10) {
    align();
    turnOneMotor(rightMotor, 65, -18, 40, 40);
    driveCM(70, -2, 70, 70);
    openLeft(true);
    stopBC(250);
    driveCM(40, cm, 20, 20);
    grabLowLeft(true);
    driveCM(65, -7.5, 20, 20);
    turnOneMotor(rightMotor, 65, 18, 40, 40);
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