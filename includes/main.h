bool left = false, right = false;
int blackElement1, blackElement2;
int scannedColors[6], scannedHeights[6];
int sizeToLift;
int manipLeft = -1, manipRight = -1;
int cellLeft = -1, cellRight = -1;
int currCross = 1;
int needCross = 0;
const int finishCross = 4;

void scan() {
    driveCM(85, 18, 25, 85);
    lineCM(85, 18.6, 85, 75);
    lineReading(75, 75, blackElement1, blackElement2);
    for (int bEl = 0; bEl < 6; bEl++) {
        if (bEl == blackElement1 || bEl == blackElement2) {scannedColors[bEl] = 1;}
        else {scannedColors[bEl] = 6;}
    }
    printNumbers(scannedColors, 6, 10000);
}

void toCubes() {
    XCross(65, 1, 60, true, 7.2);
    turnLineRight(80, 70, 45);
    align();
    lineCM(70, 27.4, 50, 50);
    arc(100, -24, 178, 45, 45);
    XCross(80, 1, 35, true, 5.5);
    driveCM(75, -6, 30, 30);
    turnLine180(75, 160, 35);
    align();
    lineCM(35, 15, 30, 0);
    driveCM(35, -38, 40, 40);
    stopBC(3100);
    driveCM(75, 3, 75, 75);
    lineCM(75, 9.5, 75, 75);
    arc(80, -37.7, 84.5, 45, 45);
    XCross(75, 1, 55, true, 7.15);
}

void scanHeights() {
    reverseArray(scannedColors, 6);
    reverseArray(scannedHeights, 6);

    int counter = 0;

    turnLineLeft(70, 50, 15);
    turnOneMotor(leftMotor, 50, -35, 30, 70);
    turnOneMotor(rightMotor, 50, -35, 30, 70);
    driveCM(90, -8, 15, 30);

    int k = 0;
    for (int cont = 0; cont < 5; cont++) {
        XCross1Sensor(60, 1, 40, false);
        scannedHeights[cont] = detectHigh();
        leaveCubes(scannedHeights, scannedColors, cont);
        if (scannedHeights[cont] == 1) {k++;}
        driveCM(40, 5, 60, 40);
    }

    stopBC(0);
    if (scannedColors[5] == 6) {
        driveCM(75, 10, 15, 35);
        if (k == 1) {peak(); scannedHeights[5] = 1;}
        else {whiteSound(); scannedHeights[5] = 0;}
        leaveCubes(scannedHeights, scannedColors, 5);
        stopBC(0);
        driveCM(75, -15, 20, 35);
    } else {driveCM(65, -7, 20, 35);}

    turnOneMotor(rightMotor, 60, 35, 30, 40);
    turnOneMotor(leftMotor, 60, 35, 30, 40);
    turnLine180(55, 110, 25);
}

void grab4() {
    reverseArray(scannedColors, 6);
    reverseArray(scannedHeights, 6);

    int needCross, currCross, _, gottenDir;
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
                sizeToLift = manipLeft;
                for (int j = 0; j < 6; j++) {
                    if (scannedColors[j] == 6) {manipRight = scannedHeights[j]; break;}
                }
            } else {
                right = true;
                manipRight = scannedHeights[i];
                sizeToLift = manipRight;
                for (int j = 0; j < 6; j++) {
                    if (scannedColors[j] == 6) {manipLeft = scannedHeights[j]; break;}
                }
            }
            break;
        }
    }
    if (needCross < currCross) {currCross--;}

    navigate(currCross, needCross, 3, true, gottenDir, true);
    driveCM(65, 8.9, 30, 30);
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
    driveCM(65, 8.9, 30, 30);
    directions(gottenDir, 3);
    align();

    if (right) {takeLeftManip();}
    else if (left) {takeRightManipWhenLeftIsBusy();}
    else {takeLeftManip();}

    currCross = needCross;
    navigate(currCross, finishCross, 3, false, gottenDir);
    if (gottenDir != 3) {lineCM(75, 6.5, 35, 35); directions(gottenDir, 1);}
    else {turnLeft(70, 179, 35);}
    align();

    XCross(100, 1, 35);
    openFullLeft();
    openFullRight();
    lineCM(35, 5, 35, 35);
    floorGrabLeft();
    floorGrabRight();
    XCross(100, 1, 100);
    XCross(75, 1, 100);
}

void bringContsToShip() {
    stopBC(100);
    turnLine180(65, 160, 25);
    align();
    liftContLeft(manipLeft, true);
    liftContRight(manipRight, true);
    lineCM(80, 26, 50, 50);
    driveCM(65, -15, 50, 50);
    stopBC(100);
    turnLine180(55);
    align();
    XCross(70, 1, 45, false);
    lineCM(70, 6.1, 35, 35);

    if (manipRight == 0 && manipLeft == 1) {right0left1();}
    else if (manipRight == 1 && manipLeft == 0) {right1left0();}
    else if (manipRight == 1 && manipLeft == 1) {twoSituations(true);} 
    else {twoSituations(false);}

    turnLine180(55, 150, 30);
    align();
    openFullLeft();
    openFullRight(true);
    stopBC(500);
    XCross(35, 1, 35);
    floorGrabLeft();
    floorGrabRight(true);
    turnLine180(55, 170, 35);
    align();

    liftContLeft(cellLeft, true);
    liftContRight(cellRight, true);

    XCross(75, 1, 35, false);
    lineCM(70, 6, 35, 35);
    stopBC(100);

    if (cellRight == 0 && cellLeft == 1) {right0left1();}
    else if (cellRight == 1 && cellLeft == 0) {right1left0();}
    else if (cellRight == 1 && cellLeft == 1) {twoSituations(true);} 
    else {twoSituations(false);}
    turnLine180(55, 155, 60);
    align();

    XCross(85, 1, 35);
    XCross(85, 1, 85);
    XCross(85, 1, 85);
}

void runner() {
    scan();
    toCubes();
    scanHeights();
    grab4();
    bringContsToShip();
}