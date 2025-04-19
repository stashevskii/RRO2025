float shipTurn = 67.5;
const float copyST = 67.5;
const float turnPower = 42;

void r() {
    stopBC(2.5);
    delay(2.5);
}

int detectHigh() {
    if (getUSDistance(colorS2) > 7) {return 0;}
    else {return 1;}
}

void reverseArray(int *arr, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

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

void swapConts() {
    openFullLeft();
    openFullRight(true);
    driveCM(60, -10, 30, 30);
}

void takeRightManipWhenLeftIsBusy() {
    turnLine180(65, 165, 30);
    turnOneMotor(leftMotor, 65, -22, 35, 35);
    driveCM(70, -2, 70, 70);
    openFullRight(true);
    driveCM(65, 10.5, 30, 30);
    floorGrabRight(true);
    driveCM(65, -8.5, 30, 30);
    turnOneMotor(leftMotor, 65, 22, 35, 35);
}

void takeDuoCells() {
    turnLeft(55, 92.5, 35, 20);
    liftSomeLeft(true);
    liftSomeRight(true);
    driveCM(55, 17, 20, 40);
    closeFullLeft();
    closeFullRight(true);
    driveCM(55, -14.5, 20, 40);
}

void takeDuoManips() {
    turnLeft(50, 92, 35, 20);
    driveCM(55, -5, 25, 30);
    openFullLeft();
    openFullRight(true);
    driveCM(55, 13.5, 20, 40);
    floorGrabLeft();
    floorGrabRight(true);
    driveCM(55, -7, 20, 40);
    turnLeft(35, -93, 35, 20);
    lineCM(50, 5, 30, 30);
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
    turnOneMotor(rightMotor, turnPower, shipTurn, 35, 25);
    turnOneMotor(leftMotor, turnPower, shipTurn, 35, 25);
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

void retakeConts() {
    lineCM(80, 10, 35, 35);
    openFullLeft();
    openFullRight();
    lineCM(35, 7.5, 35, 35);
    floorGrabLeft();
    floorGrabRight();
}
