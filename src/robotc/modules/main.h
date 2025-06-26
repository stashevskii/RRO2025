#ifndef _MAIN_H_
#define _MAIN_H_

void scanColors() {
    clearTimer(T3);
    checkVoltage();
    driveCM(100, 8.5, 100, 30);
    lineCM(100, 22, 30, 30);
    lineReading(70, 35, scannedColors);
    // printArr(scannedColors, 6);
}

void toConts() {
    arc(100, 16.5, 50, 100, 100);
	driveCM(90, 58.5, 80, 50);
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
    turnLine180(65, 155, 25);
    // printArr(scannedHeights, 6);
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
    const int finishCross = 4, navigCm = 8.1;
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
    stopBC(100);
    driveCM(50, navigCm, 30, 30);
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
    stopBC(100);
    driveCM(50, navigCm, 30, 30);

    if (right) {
        directions(currentDir, 3);
        takeML();
    } else if (left) {
        turnLine180(70, 175, 35);
        directions(opposite(currentDir), 3);
        takeMR();
    }

    currCross = targetCross;

    navigate(currCross, finishCross, 3, false, currentDir);
    if (currentDir != 3) {
        lineCM(60, 8, 35, 35);
        directions(currentDir, 1);
    } else {
        // just turn, because already on finish cross
        turnLine180(70, 170, 40);
    }
    align();

    retake();
    XCross(80, 1, 100, true, 6);
}

void leaveCubes() {
    turnLineRight(55, 80, 25);
    lineCM(90, 5, 20, 35);

    XCross(40, 1, 25, false);
    turnOneMotor(rightMotor, 70, 1.2, 50, 50);
    driveCM(85, 16.1, 15, 15);

    openLeft();
    openRight(true);

    driveCM(85, -9, 35, 35);

    closeLeft();
    closeRight(true);
    stopBC(155);
    liftLeft45();
    liftRight45(true);

    driveCM(60, 7.5, 20, 20);
    driveCM(85, -43, 40, 35);
    turnLineRight(65, 70, 20);
    align();
    lineCM(70, 5, 20, 70);
}

void takeRubbishV2() {
    closeLeft();
    closeRight();

    XCross(70, 1, 70, true, 7.1);

    int r1 = -1, r2 = -1, currentDir;
    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 1 && r1 == -1) {
            r1 = i;
        } else if (scannedColors[i] == 1) {
            r2 = i;
            break;
        }
    }

    navigate(4, r1, 3, false, currentDir);
    if (r1 != 4) {
        stopBC();
        driveCM(60, 8, 30, 30);
        directions(currentDir, 3);
    }
    takeML();
    navigate(r1, r2, 3, false, currentDir);
    stopBC();
    driveCM(60, 8, 30, 30);
    turnLine180(70, 165, 35);
    directions(opposite(currentDir), 3);
    takeMR(11);

    navigate(r2, 4, 3, false, currentDir);
    if (currentDir != 3) {
        lineCM(60, 7, 30, 30);
        directions(currentDir, 1);
    } else {
        // just turn, because already on finish cross
        turnLine180(70, 175, 35);
    }
    align();

    retake();
    XCross(100, 1, 30, true, 7.5);
    turnLineLeft(50, 75, 35);
    XCross(30, 1, 25, false);
    driveCM(30, 5, 30, 30);

    openLeft();
    openRight(true);

    driveCM(75, -20, 35, 25);
    turnLine180(55, 160, 30);
}

void takeCubes() {
    liftLeft45();
    liftRight45();

    lineCM(55, 11, 20, 35);
    XCross(75, 1, 60, false);
    turnOneMotor(leftMotor, 40, 1.7, 20, 20);
    driveCM(30, 17.6, 20, 20);

    closeLeft();
    closeRight(true);

    stopBC(100);

    driveCM(80, -11, 20, 20);  
    openLeft()
    openRight(true)
    driveCM(80, 11, 20, 20);

    grabLowLeft();
    grabLowRight(true);

    driveCM(80, -30, 17, 17);
    turnLine180(60, 165, 30);
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
    driveCM(40, -19, 20, 20);

    turnLine180(60, 165, 35);
    align();

    XCross(80, 1, 40, false);
	stopBC(50);
    lineCM(35, 6.8, 40, 30);

    unload(manipRight, manipLeft);

    turnLine180(65, 165, 35);
    align();

    openLeft();
    openRight();
    XCross(35, 1, 35);

    grabLowLeft();
    grabLowRight(true);

    turnLine180(60, 160, 35);
    align();

    liftContLeft(cellLeft, true);
    liftContRight(cellRight, true);

    XCross(80, 1, 60, false);
    stopBC(50);
    lineCM(35, 5.8, 40, 30);

    unload(cellRight, cellLeft);

    turnRight(60, 90, 35, 35);
}

void finish() {
    closeLeft();
    closeRight();
    driveCM(85, 45, 50, 50);
    turnOneMotor(rightMotor, 80, 88, 45, 45);
    lineCM(45, 5, 25, 25);
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
    takeRubbishV2();
    takeCubes();
    leaveConts();
    finish();
}

#endif