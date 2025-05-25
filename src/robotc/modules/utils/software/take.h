#ifndef _TAKE_H_
#define _TAKE_H_

void takeDuoCells() {
    turnLeft(75, 92, 20, 20);
    liftLeft45(true);
    liftRight45(true);
    driveCM(80, 16, 20, 20);
    closeLeft();
    closeRight(true);
    driveCM(80, -14.5, 20, 20);
}

void takeRightManip() {
    turnOneMotor(leftMotor, 80, -17, 30, 30);
    driveCM(70, -2, 70, 70);
    openRight(true);
    stopBC(300);
    driveCM(70, 12, 20, 20);
    grabLowRight(true);
    driveCM(65, -10, 15, 15);
    turnOneMotor(leftMotor, 70, 17, 30, 30);
}

void takeLeftManip() {
    turnOneMotor(rightMotor, 70, -22, 30, 30);
    driveCM(70, -2, 70, 70);
    openLeft(true);
    stopBC(300);
    driveCM(65, 10.5, 20, 20);
    grabLowLeft(true);
    driveCM(65, -8.5, 20, 20);
    turnOneMotor(rightMotor, 70, 22, 30, 30);
}

void retakeConts() {
    lineCM(80, 10, 20, 20);
    openLeft();
    openRight();
    lineCM(50, 7.5, 20, 20);
    grabLowLeft();
    grabLowRight();
}

#endif