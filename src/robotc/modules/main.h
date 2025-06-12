#ifndef _MAIN_H_
#define _MAIN_H_

void scanColors() {
    clearTimer(T3);
    driveCM(100, 8.5, 100, 30);
    lineCM(100, 22, 30, 30);
    lineReading(90, 30, scannedColors);
    // printArr(scannedColors, 6);
}

void toConts() {
    arc(100, 16.5, 50, 100, 100);
	driveCM(100, 58.8, 100, 100);
	arc(100, -20, 39, 100, 100);
	lineCM(95, 8, 40, 100);
    XCross(85, 1, 100, true, 5);
    turnLineLeft(55, 70, 45);
}

void scanHeights() {
    int counter = 0;
    reverseArray(scannedColors, 6);
    scanFive(scannedHeights, counter);
    getFirst(scannedHeights, counter);
    turnLine180(65, 110, 25);
    printArr(scannedHeights, 6);
}

void setManipValues(bool &v1, int &v2, int &v3, int i) {
    // v2 and v3 - manipulator variables
    v1 = true;
    v2 = scannedHeights[i];
    for (int j = 0; j < 6; j++) {
        if (scannedColors[j] == 6) {
            v3 = scannedHeights[j];
            return;
        }
    }
}

void grab4() {
    int targetCross = 0, currCross = 0, _, currentDir = 0;
    const int finishCross = 4;
    bool left = false, right = false;

    reverseArray(scannedColors, 6);
    reverseArray(scannedHeights, 6);

    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6 && scannedColors[i + 1] == 6) {
            targetCross = i + 1;
            scannedColors[i] = -1;
            scannedColors[i + 1] = -1;
            cellLeft = scannedHeights[i];
            cellRight = scannedHeights[i + 1];
            break;
        }
    }

    navigate(0, targetCross, 0, false, _);
    takeDC();

    currCross = targetCross;

    for (int i = 0; i < 6; i++) {
        // white found
        if (scannedColors[i] == 6) {
            scannedColors[i] = -1;
            targetCross = i;
            // set vals
            if (cellRight == scannedHeights[i]) {
                setManipValues(left, manipLeft, manipRight, i);
            } else {
                setManipValues(right, manipRight, manipLeft, i);
            }
            break;
        }
    }
    if (targetCross < currCross) {currCross--;}

    navigate(currCross, targetCross, 3, true, currentDir, true);
    driveCM(70, 10, 30, 30);
    directions(currentDir, 3);

    left ? takeML() : takeMR();

    currCross = targetCross; 
    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6) {
            targetCross = i;
            break;
        }
    }

    if (targetCross < currCross) {currCross--;}

    navigate(currCross, targetCross, 3, false, currentDir);
    driveCM(90, 10, 30, 30);

    if (right) {
        directions(currentDir, 3);
        takeML();
    } else if (left) {
        turnLine180(70, 165, 35);
        directions(opposite(currentDir), 3);
        takeMR();
    }

    currCross = targetCross;

    navigate(currCross, finishCross, 3, false, currentDir);
    if (currentDir != 3) {
        lineCM(60, 7.25, 35, 35);
        directions(currentDir, 1);
    } else {
        // just turn, because already on finish cross
        turnLeft(65, 178, 35);
        align();
    }

    retake();
    XCross(80, 1, 100, true, 6);
}

void leaveCubes() {
    turnLineRight(55, 80, 25);
    lineCM(90, 5, 20, 35);

    XCross(40, 1, 25, false);
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
    turnLine180(60, 155, 20);

    XCross(50, 1, 30, true, 7);
    turnLineLeft(90, 70, 20);
}

void takeRubbish() {
    closeLeft();
    closeRight();

    XCross(70, 1, 20, true, 7.1);
    turnLineLeft(60, 65, 20);

    QCross(80, 4, 80, true, 2.8);
    XCross(40, 1, 70, true);

    turnLineRight(75, 65, 20);
    liftLeft45(true);
    lineCM(30, 2.9, 35, 35);

	arc(40, 9, 88.5, 35, 35);

	driveCM(40, 51, 20, 20);
	openLeftRubbish(true);

	arc(65, 15, 90, 25, 25);

	driveCM(55, 41, 20, 25);
	liftContLeft(0, true);
    driveCM(62, -3.5, 20, 25);

	arc(50, 20, -90, 25, 25);

    closeLeft();
    closeRight();
    turnLineRight(75, 65, 20);

    closeLeft();
    closeRight();
    XCross(85, 1, 30, true, 6.5);
}

void takeCubes() {
    turnLineRight(70, 70, 20);

    liftLeft45();
    liftRight45();

    lineCM(25, 10, 25, 25);
    XCross(25, 1, 25, false);
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
    turnLine180(65, 155, 30);
    XCross(55, 1, 40, true, 7);
    turnLineRight(65, 75, 30);

    XCross(80, 1, 50, true, 6);
    retake();
    XCross(90, 1, 30, true, 5.7);
}

void leaveConts() {
    turnLine180(60, 160, 35);
    align();

    liftContLeft(manipLeft, true);
    liftContRight(manipRight, true);

    lineCM(90, 28, 20, 20);
    driveCM(80, -18, 20, 20);

    stopBC(100);

    turnLine180(60, 160, 35);
    align();

    XCross(85, 1, 35, false);
    lineCM(80, 6.1, 30, 30);
    unload(manipRight, manipLeft);

    turnLine180(65, 165, 35);
    align();

    openLeft();
    openRight(true);
    stopBC(250);
    XCross(35, 1, 35);

    grabLowLeft();
    grabLowRight(true);

    turnLine180(60, 160, 35);
    align();

    liftContLeft(cellLeft, true);
    liftContRight(cellRight, true);

    XCross(75, 1, 60, false);

    lineCM(70, 6, 30, 30);
    stopBC(100);

    unload(cellRight, cellLeft);

    turnLine180(60, 160, 35);
    align();
}

void finish() {
    lineCM(45, 17, 25, 25);
    arc(100, -27.52, 179, 100, 100);
    lineCM(90, 5, 30, 100);

    closeLeft();
    closeRight();

    XCross(100, 1, 100, false);
    driveCM(70, 20.5, 100, 15);

    printTime();
}

void runner() {
    scanColors();
    toConts();
    scanHeights();
    grab4();
    leaveCubes();
    takeRubbish();
    takeCubes();
    leaveConts();
    finish();
}

#endif