#ifndef _TAKE_H_
#define _TAKE_H_

void takeDuoCells() {
    turnLeft(75, 92, 20, 20);
    liftSomeLeft(true);
    liftSomeRight(true);
    driveCM(80, 16, 20, 20);
    closeFullLeft();
    closeFullRight(true);
    driveCM(80, -14.5, 20, 20);
}

void takeRightManip() {
    turnOneMotor(leftMotor, 80, -17, 30, 30);
    driveCM(70, -2, 70, 70);
    openFullRight(true);
    stopBC(300);
    driveCM(70, 12, 20, 20);
    floorGrabRight(true);
    driveCM(65, -10, 15, 15);
    turnOneMotor(leftMotor, 70, 17, 30, 30);
}

void takeLeftManip() {
    turnOneMotor(rightMotor, 70, -22, 30, 30);
    driveCM(70, -2, 70, 70);
    openFullLeft(true);
    stopBC(300);
    driveCM(65, 10.5, 20, 20);
    floorGrabLeft(true);
    driveCM(65, -8.5, 20, 20);
    turnOneMotor(rightMotor, 70, 22, 30, 30);
}

void retakeConts() {
    lineCM(80, 10, 20, 20);
    openFullLeft();
    openFullRight();
    lineCM(50, 7.5, 20, 20);
    floorGrabLeft();
    floorGrabRight();
}

#endif