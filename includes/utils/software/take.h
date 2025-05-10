#ifndef _TAKE_H_
#define _TAKE_H_

void takeDuoCells() {
    turnLeft(55, 92.5, 35, 20);
    liftSomeLeft(true);
    liftSomeRight(true);
    driveCM(55, 17, 20, 40);
    closeFullLeft();
    closeFullRight(true);
    driveCM(55, -14.5, 20, 40);
}

void takeRightManip() {
    turnOneMotor(leftMotor, 50, -17, 35, 35);
    driveCM(70, -2, 70, 70);
    openFullRight(true);
    stopBC(300);
    driveCM(65, 12, 30, 30);
    floorGrabRight(true);
    driveCM(65, -10, 30, 30);
    turnOneMotor(leftMotor, 50, 17, 35, 35);
}

void takeLeftManip() {
    turnOneMotor(rightMotor, 65, -22, 35, 35);
    driveCM(70, -2, 70, 70);
    openFullLeft(true);
    stopBC(300);
    driveCM(65, 10.5, 30, 30);
    floorGrabLeft(true);
    driveCM(65, -8.5, 30, 30);
    turnOneMotor(rightMotor, 65, 22, 35, 35);
}

void retakeConts() {
    lineCM(80, 10, 35, 35);
    openFullLeft();
    openFullRight();
    lineCM(35, 7.5, 35, 35);
    floorGrabLeft();
    floorGrabRight();
}

#endif