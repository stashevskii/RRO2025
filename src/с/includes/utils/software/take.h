#ifndef _TAKE_H_
#define _TAKE_H_

void takeDuoCells() {
    turnLeft(70, 92.5, 20, 20);
    liftSomeLeft(true);
    liftSomeRight(true);
    driveCM(70, 17, 10, 10);
    closeFullLeft();
    closeFullRight(true);
    driveCM(70, -14.5, 10, 10);
}

void takeRightManip() {
    turnOneMotor(leftMotor, 70, -17, 20, 20);
    driveCM(70, -2, 70, 70);
    openFullRight(true);
    stopBC(300);
    driveCM(70, 12, 10, 10);
    floorGrabRight(true);
    driveCM(65, -10, 15, 15);
    turnOneMotor(leftMotor, 70, 17, 20, 20);
}

void takeLeftManip() {
    turnOneMotor(rightMotor, 70, -22, 20, 20);
    driveCM(70, -2, 70, 70);
    openFullLeft(true);
    stopBC(300);
    driveCM(65, 10.5, 15, 15);
    floorGrabLeft(true);
    driveCM(65, -8.5, 15, 15);
    turnOneMotor(rightMotor, 70, 22, 20, 20);
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