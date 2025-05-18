#ifndef _MAIN_H_
#define _MAIN_H_

void scan() {
    clearTimer(T3);
    driveCM(100, 10.5, 15, 0);
    lineCM(90, 20, 0, 0);
    lineReading(60, 40, scannedColors);
    // printNumbers(scannedColors, 6);
}

void toCubes() {
    arc(95, 20, 41, 35, 35);
	driveCM(100, 69, 100, 70);
	arc(95, -20, 39, 70, 30);
	lineCM(95, 8, 30, 100);
    XCross(100, 1, 100, true, 6.9);
    turnLineLeft(95, 70, 35);
    driveCM(85, -4, 25, 25);
}

void scanHeights() {
    int counter = 0;
    reverseArray(scannedColors, 6);
    scanFiveConts(scannedHeights, counter);
    getFirstContHigh(scannedHeights, counter);
    turnLine180(65, 110, 25);
    // printNumbers(scannedHeights, 6);
}

void grab4() {
    int needCross = 0, currCross = 0, _, gottenDir = 0;
    const int finishCross = 4;
    bool left = false, right = false;
    reverseArray(scannedColors, 6);
    reverseArray(scannedHeights, 6);
    findDuoAndCross(scannedColors, needCross, cellRight, cellLeft);
    navigate(0, needCross, 0, false, _);
    takeDuoCells();
    findManipsAndCross(scannedColors, scannedHeights, currCross, needCross, cellRight, currCross, needCross, left, right, manipRight, manipLeft);
    navigate(currCross, needCross, 3, true, gottenDir, true);
    driveCM(75, 8.9, 30, 30);
    directions(gottenDir, 3);
    align();
    takeRightOrLeft(left);
    updateCurrAndNeedCross(currCross, needCross, currCross, needCross)
    navigate(currCross, needCross, 3, false, gottenDir);
    setDirectionByRightOrLeft(gottenDir, right, left);
    currCross = needCross;
    navigate(currCross, finishCross, 3, false, gottenDir);
    turnBasedOnDirection(gottenDir);
    align();
    retakeConts();
    XCross(100, 1, 50, true, 6.5);
}

void leaveCubes() {
    turnLineRight(70, 70, 20);
    XCross(60, 1, 25, false);
    driveCM(60, 16.1, 15, 15);
    openFullLeftLowSpeed();
    openFullRightLowSpeed(true);
    driveCM(60, -9.2, 35, 35);
    stopBC(0);
    closeFullLeft();
    closeFullRight(true);
    stopBC(350);
    liftSomeLeft();
    liftContRight(true);
    stopBC(100);
    driveCM(70, 7.5, 20, 20);
    driveCM(70, -29.3, 20, 20);
    turnLine180(60, 165, 20);
    XCross(50, 1, 30, true, 7);
    turnLineLeft(90, 70, 20);
}

void takeRubbish() {
    closeFullLeft();
    closeFullRight();
    XCross(55, 1, 20, true, 6.9);
    turnLineLeft(60, 65, 20);
    for (int i = 0; i < 3; i++) {XCross(80, 1, 80, true, 3);}
    XCross(65, 1, 20, true, 7);
    turnLineRight(75, 65, 20);
    liftSomeLeft(true);
    lineCM(26.5, 2.3, 35, 35);
	align();
	arc(38, 9, 93, 20, 20);
	driveCM(55, 51, 20, 20);
	openLeftRubbish(true);
	arc(65, 15, 90, 25, 25);
	driveCM(55, 44, 20, 25);
	liftContLeft(0, true);
    driveCM(62, -3.5, 20, 25);
	arc(60, 21, -90, 25, 25);
    closeFullLeft();
    closeFullRight();
    turnLineRight(75, 65, 20);
    align();
    XCross(75, 1, 30, true, 6.5);
}

void takeCubes() {
    turnLineRight(70, 70, 20);
    closeFullLeft();
    closeFullRight(true);
    stopBC(1);
    liftSomeLeft(true);
    liftSomeRight(true);
    stopBC(20);
    lineCM(35, 10, 25, 25);
    XCross(35, 1, 25, false);
    turnOneMotor(leftMotor, 40, 1.7, 20, 20);
    driveCM(20, 17.6, 20, 20);
    closeFullLeft();
    closeFullRight(true);
    stopBC(100);
    driveCM(70, -11, 20, 20);  
    openFullLeft()
    openFullRight(true)
    driveCM(70, 11, 20, 20);
    floorGrabLeft();
    floorGrabRight(true);
    driveCM(80, -30, 17, 17);
    turnLine180(65, 165, 30);
    XCross(55, 1, 40, true, 7);
    turnLineRight(65, 75, 30);
    XCross(80, 1, 50, true, 6);
    retakeConts();
    XCross(90, 1, 30, true, 5.7);
}

void bringContsToShip() {
    stopBC(100);
    turnLine180(65, 160, 25);
    align();
    liftContLeft(manipLeft, true);
    liftContRight(manipRight, true);
    lineCM(90, 28, 20, 20);
    driveCM(80, -18, 20, 20);
    stopBC(100);
    turnLine180(70, 165, 20);
    align();
    XCross(85, 1, 35, false);
    lineCM(80, 6.1, 30, 30);
    leaveContsAtShip(manipRight, manipLeft);
    turnLine180(70, 160, 20);
    align();
    openFullLeft();
    openFullRight(true);
    stopBC(250);
    XCross(35, 1, 35);
    floorGrabLeft();
    floorGrabRight(true);
    turnLine180(70, 170, 20);
    align();
    liftContLeft(cellLeft, true);
    liftContRight(cellRight, true);
    XCross(75, 1, 60, false);
    lineCM(70, 6, 30, 30);
    stopBC(100);
    leaveContsAtShip(cellRight, cellLeft);
    turnLine180(70, 165, 20);
    align();
}

void finish() {
    lineCM(45, 17, 25, 25);
    arc(100, -27.52, 179, 100, 100);
    lineCM(90, 5, 30, 100);
    closeFullLeft();
    closeFullRight();
    XCross(100, 1, 100, false);
    driveCM(70, 19, 100, 15);
    printTime();
}

void runner() {
    scan();
    toCubes();
    scanHeights();
    grab4();
    leaveCubes();
    takeRubbish();
    takeCubes();
    bringContsToShip();
    finish();
}

#endif