#ifndef _MAIN_H_
#define _MAIN_H_

void scan() {
    clearTimer(T3);
    driveCM(100, 10.5, 20, 25);
    lineCM(100, 20, 20, 35);
    lineReading(60, 35, scannedColors);
    // printNumbers(scannedColors, 6);
}

void toCubes() {
    arc(100, 20, 41, 80, 80);
	driveCM(100, 67.2, 100, 70);
	arc(100, -20, 39, 80, 80);
	lineCM(95, 8, 30, 100);
    XCross(100, 1, 100, true, 6);
    turnLineLeft(90, 70, 35);
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

    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6 && scannedColors[i + 1] == 6) {
            needCross = i + 1;
            scannedColors[i] = -1;
            scannedColors[i + 1] = -1;
            cellLeft = scannedHeights[i];
            cellRight = scannedHeights[i + 1];
            break;
        }
    }

    navigate(0, needCross, 0, false, _);
    takeDuoCells();

    currCross = needCross;

    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6) {
            scannedColors[i] = -1;
            needCross = i;
            if (cellRight == scannedHeights[i]) {
                left = true;
                manipLeft = scannedHeights[i];
                for (int j = 0; j < 6; j++) {
                    if (scannedColors[j] == 6) {manipRight = scannedHeights[j]; break;}
                }
            } else {
                right = true;
                manipRight = scannedHeights[i];
                for (int j = 0; j < 6; j++) {
                    if (scannedColors[j] == 6) {manipLeft = scannedHeights[j]; break;}
                }
            }
            break;
        }
    }
    if (needCross < currCross) {currCross--;}

    navigate(currCross, needCross, 3, true, gottenDir, true);
    driveCM(75, 8.9, 30, 30);
    directions(gottenDir, 3);
    align();

    if (left) {takeLeftManip();}
    else {takeRightManip();}

    currCross = needCross; 
    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6) {
            needCross = i;
            break;
        }
    }

    if (needCross < currCross) {currCross--;}
    navigate(currCross, needCross, 3, false, gottenDir);
    if (right) {
        driveCM(90, 8.9, 30, 30);
        directions(gottenDir, 3);
        align();
        takeLeftManip();
    }
    else if (left) {
        driveCM(90, 8.9, 30, 30);
        turnLine180(70, 165, 35);
        directions(opposite(gottenDir), 3);
        align();
        takeRightManip();
    }

    currCross = needCross;

    navigate(currCross, finishCross, 3, false, gottenDir);
    if (gottenDir != 3) {
        lineCM(60, 7.25, 35, 35);
        directions(gottenDir, 1);
        align();
    }
    else {
        turnLeft(70, 179, 35);
    }

    align();
    retakeConts();
    XCross(80, 1, 100, true, 6.5);
}

void leaveCubes() {
    turnLineRight(70, 70, 25);
    XCross(60, 1, 25, false);
    driveCM(60, 16.1, 15, 15);
    openLeft();
    openRight(true);
    driveCM(60, -9.2, 35, 35);
    closeLeft();
    closeRight(true);
    stopBC(155);
    liftLeft45();
    liftRight45(true);
    driveCM(70, 7.5, 20, 20);
    driveCM(70, -29.3, 20, 20);
    turnLine180(60, 165, 20);
    XCross(50, 1, 30, true, 7);
    turnLineLeft(90, 70, 20);
}

void takeRubbish() {
    closeLeft();
    closeRight();
    XCross(70, 1, 20, true, 7.1);
    turnLineLeft(60, 65, 20);
    QCross(80, 4, 80, true, 2.8);
    XCross(40, 1, 70, true, 7.5);
    turnLineRight(75, 65, 20);
    liftLeft45(true);
    lineCM(30, 2.3, 35, 35);
	arc(35, 9, 92.5, 20, 20);
	driveCM(55, 51, 20, 20);
	openLeftRubbish(true);
	arc(65, 15, 90, 25, 25);
	driveCM(55, 44, 20, 25);
	liftContLeft(0, true);
    driveCM(62, -3.5, 20, 25);
	arc(60, 21, -90, 25, 25);
    closeLeft();
    closeRight();
    turnLineRight(75, 65, 20);
    align();
    closeLeft();
    closeRight();
    XCross(75, 1, 30, true, 6.5);
}

void takeCubes() {
    turnLineRight(70, 70, 20);
    liftLeft45();
    liftRight45();
    lineCM(35, 10, 25, 25);
    XCross(35, 1, 25, false);
    turnOneMotor(leftMotor, 40, 1.7, 20, 20);
    driveCM(20, 17.6, 20, 20);
    closeLeft();
    closeRight(true);
    stopBC(100);
    driveCM(70, -11, 20, 20);  
    openLeft()
    openRight(true)
    driveCM(70, 11, 20, 20);
    grabLowLeft();
    grabLowRight(true);
    driveCM(80, -30, 17, 17);
    turnLine180(65, 165, 30);
    XCross(55, 1, 40, true, 7);
    turnLineRight(65, 75, 30);
    XCross(80, 1, 50, true, 6);
    retakeConts();
    XCross(90, 1, 30, true, 5.7);
}

void bringContsToShip() {
    turnLine180(60, 160, 35);
    align();
    liftContLeft(manipLeft, true);
    liftContRight(manipRight, true);
    lineCM(90, 28, 20, 20);
    driveCM(80, -18, 20, 20);
    stopBC(100);
    turnLine180(60, 165, 35);
    align();
    XCross(85, 1, 35, false);
    lineCM(80, 6.1, 30, 30);
    leaveContsAtShip(manipRight, manipLeft);
    turnLine180(60, 165, 35);
    align();
    openLeft();
    openRight(true);
    stopBC(250);
    XCross(35, 1, 35);
    grabLowLeft();
    grabLowRight(true);
    turnLine180(60, 165, 35);
    align();
    liftContLeft(cellLeft, true);
    liftContRight(cellRight, true);
    XCross(75, 1, 60, false);
    lineCM(70, 6, 30, 30);
    stopBC(100);
    leaveContsAtShip(cellRight, cellLeft);
    turnLine180(60, 165, 35);
    align();
}

void finish() {
    lineCM(45, 17, 25, 25);
    arc(100, -27.52, 179, 100, 100);
    lineCM(90, 5, 30, 100);
    closeLeft();
    closeRight();
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