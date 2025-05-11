#ifndef _TAKE_H_
#define _TAKE_H_

void takeDuoCells() {
    turnLeft(70, 92.5, 20, 20);
    liftSomeLeft(true);
    liftSomeRight(true);
    driveCM(55, 17, 20, 20);
    closeFullLeft();
    closeFullRight(true);
    driveCM(55, -14.5, 20, 40);
}

void takeRightManip() {
    turnOneMotor(leftMotor, 65, -17, 20, 20);
    driveCM(70, -2, 70, 70);
    openFullRight(true);
    stopBC(300);
    driveCM(65, 12, 30, 30);
    floorGrabRight(true);
    driveCM(65, -10, 30, 30);
    turnOneMotor(leftMotor, 65, 17, 20, 20);
}

void takeLeftManip() {
    turnOneMotor(rightMotor, 65, -22, 20, 20);
    driveCM(70, -2, 70, 70);
    openFullLeft(true);
    stopBC(300);
    driveCM(65, 10.5, 30, 30);
    floorGrabLeft(true);
    driveCM(65, -8.5, 30, 30);
    turnOneMotor(rightMotor, 65, 22, 20, 20);
}

void retakeConts() {
    lineCM(80, 10, 20, 20);
    openFullLeft();
    openFullRight();
    lineCM(35, 7.5, 20, 20);
    floorGrabLeft();
    floorGrabRight();
}

#endif