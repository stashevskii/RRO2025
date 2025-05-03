void scan() {
    int blackElement1, blackElement2;
    clearTimer(T3);
    driveCM(100, 18, 30, 85);
    lineCM(90, 18.6, 85, 90);
    lineReading(80, 80, blackElement1, blackElement2);
    writeColorsArr(scannedColors, blackElement1, blackElement2);
    // printNums(scannedColors, 6)
}

void toCubes() {
    arc(90, 20, 37, 25, 25);
	driveCM(95, 80.5, 70, 70);
	arc(90, -20, 39, 70, 70);
	lineCM(75, 5, 50, 75);
    XCross(75, 1, 100, true, 7.1);
    turnLineLeft(80, 70, 35);
    driveCM(90, -4, 25, 25);
}

void scanHeights() {
    int counter = 0;
    reverseArray(scannedColors, 6);
    scanFiveConts(counter);
    getFirstContHigh(scannedColors, counter);
    turnLine180(65, 110, 25);
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
    findManipsAndCross(scannedColors, currCross, needCross, cellRight, currCross, needCross, left, right, manipRight, manipLeft);
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
    XCross(80, 1, 100, true, 6.5);
}

void leaveCubes() {
    turnLineRight(60, 70, 25);
    XCross(50, 1, 25, false);
    driveCM(35, 16.1, 35, 35);
    openFullLeftLowSpeed();
    openFullRightLowSpeed(true);
    driveCM(35, -9.2, 35, 35);
    stopBC(0);
    closeFullLeft();
    closeFullRight(true);
    stopBC(350);
    liftSomeLeft();
    liftContRight(true);
    stopBC(100);
    driveCM(35, 7.5, 35, 35);
    driveCM(35, -29.3, 35, 35);
    turnLine180(55, 165, 30);
    XCross(50, 1, 30, true, 7);
    turnLineLeft(65, 70, 30);
}

void takeRubbish() {
    closeFullLeft();
    closeFullRight();
    XCross(48, 1, 35, true, 6.9);
    turnLineLeft(55, 65, 30);
    QCross(65, 3, 50, true, 3);
    XCross(50, 1, 40, true, 7.5);
    turnLineRight(70, 65, 30);
    liftSomeLeft(true);
    lineCM(26.5, 2.3, 35, 35);
	align();
	arc(38, 9, 92.25, 45, 45);
	driveCM(40, 51, 20, 25);
	openLeftRubbish(true);
	arc(65, 15, 90, 45, 45);
	driveCM(55, 44, 20, 25);
	liftContLeft(0, true);
    driveCM(62, -3.5, 20, 25);
	arc(50, 21, -90, 45, 45);
    closeFullLeft();
    closeFullRight();
    turnLineRight(75, 65, 30);
    align();
    XCross(50, 1, 75, true, 6.5);
}

void takeCubes() {
    turnLineRight(60, 70, 30);
    closeFullLeft();
    closeFullRight(true);
    stopBC(1);
    liftSomeLeft(true);
    liftSomeRight(true);
    stopBC(20);
    lineCM(35, 10, 25, 25);
    XCross(35, 1, 25, false);
    turnOneMotor(leftMotor, 35, 1.7, 35, 35);
    driveCM(20, 17.6, 35, 35);
    closeFullLeft();
    closeFullRight(true);
    stopBC(100);
    driveCM(60, -11, 35, 35);  
    openFullLeft()
    openFullRight(true)
    driveCM(60, 11, 35, 35);
    floorGrabLeft();
    floorGrabRight(true);
    driveCM(60, -30, 35, 35);
    turnLine180(65, 165, 30);
    XCross(55, 1, 40, true, 5.8);
    turnLineRight(50, 75, 30);
    XCross(80, 1, 50, true, 6);
    retakeConts();
    XCross(90, 1, 80, true, 5.7);
}

void bringContsToShip() {
    stopBC(100);
    turnLine180(65, 160, 25);
    align();
    liftContLeft(manipLeft, true);
    liftContRight(manipRight, true);
    lineCM(90, 28, 50, 50);
    driveCM(80, -18, 50, 50);
    stopBC(100);
    turnLine180(60, 165, 30);
    align();
    XCross(85, 1, 60, false);
    lineCM(80, 6.1, 60, 60);
    leaveContsAtShip(manipRight, manipLeft);
    turnLine180(55, 160, 30);
    align();
    openFullLeft();
    openFullRight(true);
    stopBC(250);
    XCross(35, 1, 35);
    floorGrabLeft();
    floorGrabRight(true);
    turnLine180(55, 170, 35);
    align();
    liftContLeft(cellLeft, true);
    liftContRight(cellRight, true);
    XCross(75, 1, 60, false);
    lineCM(70, 6, 60, 60);
    stopBC(100);
    leaveContsAtShip(cellRight, cellLeft);
    turnLine180(45, 165, 50);
    align();
}

void finish() {
    lineCM(35, 17, 25, 25);
    arc(90, -27.52, 179, 60, 60);
    lineCM(90, 5, 80, 100);
    closeFullLeft();
    closeFullRight();
    XCross(100, 1, 100, false);
    driveCM(70, 19, 100, 100);
    stopBC(0);
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