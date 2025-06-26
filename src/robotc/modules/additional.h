#ifndef _MAIN_H_
#define _MAIN_H_

void scanColors() {
    clearTimer(T3);
    checkVoltage();
    driveCM(100, 8.5, 100, 30);
    lineCM(85, 24, 30, 30);
    lineReading(40, 35, scannedColors);
    // printArr(scannedColors, 6);
}

void toConts() {
	XCross(70, 1, 50);
	driveCM(80, -6, 50, 50);
	liftLeft45();
    liftRight45(true);
	turnOneMotor(rightMotor, 60, 65, 40, 40);
    turnOneMotor(leftMotor, 60, 65, 40, 40);
	goShip(450);
	closeLeft();
	closeRight(true);
	stopBC(250);
	turnOneMotor(leftMotor, 60, -65, 40, 40);
    turnOneMotor(rightMotor, 60, -65, 40, 40);
	driveCM(80, -8.5, 50, 50);
	openLeft();
	openRight(true);
	turnOneMotor(leftMotor, 60, 60, 40, 40);
    turnOneMotor(rightMotor, 60, 60, 40, 40);
	driveCM(80, 3, 50, 50);
	grabLowLeft();
	grabLowRight(true);
	turnOneMotor(rightMotor, 60, -60, 40, 40);
    turnOneMotor(leftMotor, 60, -60, 40, 40);
	turnLine180(60, 165, 50);
	liftLeft45();
	liftRight45(true);
	lineCM(70, 10, 50, 50);
	XCross(70, 1, 50);
	turnLineLeft(70, 70, 35);
	lineCM(70, 16, 50, 50);
	driveCM(70, -13, 50, 50);
	openLeft();
	openRight(true);
	driveCM(70, -2, 50, 50);
	turnLineRight(65, 70, 35);
	align();
	XCross(65, 1, 50);
	closeLeft();
	closeRight();
	turnLineLeft(70, 70, 35);
}

void grab4() {
	arc(100, 16.5, 50, 100, 100);
	driveCM(90, 58.5, 80, 50);
	arc(100, -20, 39, 100, 100);
	lineCM(95, 8, 40, 100);
    XCross(85, 1, 100, true, 5);

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
	lineCM(60, 6, 60, 60);
	openLeft();
	openRight(true);
	driveCM(50, -10, 50, 50);
	liftLeft45();
	liftRight45(true);
	lineCM(60, 18, 60, 60);
	closeLeft();
	closeRight();
	turnLine180(60, 165, 35);
	XCross(70, 1, 50);

	r1 = -1;
	r2 = -1;
	for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6 && r1 == -1) {
            r1 = i;
        } else if (scannedColors[i] == 6) {
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
	XCross(70, 1, 50, true, 7);
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
    driveCM(85, -24, 40, 35);

	turnLine180(60, 165, 50);

	XCross(40, 1, 35, true, 7);
	turnRight(60, 70, 40);
	align();
	XCross(70, 1, 50);
}

void takeCubes() {
    liftLeft45();
    liftRight45();

    lineCM(55, 3, 20, 35);
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

    twoSits(false);

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

    twoSits(true);

    turnRight(60, 90, 35, 35);
}

void finish() {
    closeLeft();
    closeRight();
    driveCM(85, 45, 50, 50);
    turnOneMotor(rightMotor, 80, 88, 45, 45);
    lineCM(45, 5, 25, 25);
    XCross(100, 1, 100, false);
    driveCM(70, 19.5, 100, 15);
    printTime();
}

void runner() {
    scanColors();
    grab4();
    leaveCubes();
	toConts();
	takeCubes();
	leaveConts();
	finish();
}

#endif