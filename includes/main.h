#include "init/globals.h"

void scan() {
    clearTimer(T3);
    driveCM(85, 18, 25, 85);
    lineCM(85, 18.6, 85, 75);
    lineReading(75, 75, blackElement1, blackElement2);
    for (int i = 0; i < 6; i++) {
        if (i == blackElement1 || i == blackElement2) {scannedColors[i] = 1;}
        else {scannedColors[i] = 6;}
    }
    
}

void toCubes() {
    XCross(65, 1, 60, true, 3);
    turnLineRight(80, 50, 45);
    XCross(90, 1, 50, true, 4);
    turnLineLeft(80, 70, 35);
    XCross(100, 1, 80, true, 3);
    XCross(70, 1, 100, true, 7.1);
    turnLineLeft(80, 70, 35);
    driveCM(80, -4, 25, 25);
}

void scanHeights() {
    reverseArray(scannedColors, 6);

    int counter = 0;
    int k = 0;

    for (int cont = 1; cont < 6; cont++) {
        if (cont == 5) {
            driveCM(60, 11, 25, 25);
            scannedHeights[cont] = detectHigh();
            driveCM(60, -4, 25, 25);
            if (scannedHeights[cont] == 1) {counter++;}
            break;
        }
        XCross(50, 1, 50, false);
        scannedHeights[cont] = detectHigh();
        if (scannedHeights[cont] == 1) {counter++;}
        driveCM(50, 2, 50, 50);
    }
    if (counter == 2) {scannedHeights[0] = 0;}
    else {scannedHeights[0] = 1;}
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
    if (right) {
        driveCM(65, 8.9, 30, 30);
        directions(gottenDir, 3);
        align();
        takeLeftManip();
    }
    else if (left) {
        driveCM(65, 8.9, 30, 30);
        turnLine180(70, 165, 35);
        directions(oppositeDir(gottenDir), 3);
        align();
        takeRightManip();
    }

    currCross = needCross;
    navigate(currCross, finishCross, 3, false, gottenDir);
    if (gottenDir != 3) {lineCM(60, 7.25, 35, 35); directions(gottenDir, 1); align();}
    else {turnLeft(70, 179, 35);}
    align();

    lineCM(80, 10, 35, 35);
    openFullLeft();
    openFullRight();
    lineCM(35, 7.5, 35, 35);
    floorGrabLeft();
    floorGrabRight();
    XCross(60, 1, 100, true, 6.5);
}

void cubes() {
    turnLineRight(60, 70, 25);
    XCross(40, 1, 25, false);
    driveCM(50, 16, 35, 35);
    openFullLeft();
    openFullRight(true);
    driveCM(75, -10, 35, 53);
    closeFullLeft();
    closeFullRight(true);
    stopBC(350);
    liftSomeLeft();
    liftContRight(true);
    stopBC(100);
    driveCM(60, 7.2, 35, 53);
    driveCM(75, -29, 35, 53);
    turnLine180(55, 165, 30);
    XCross(50, 1, 30, true, 7);
    turnLineLeft(65, 70, 30);
}

void takeCubes() {
    turnLineRight(60, 70, 30);
    closeFullLeft();
    closeFullRight(true);
    stopBC(1);
    liftSomeLeft();
    liftSomeRight(true);
    stopBC(20);
    lineCM(35, 10, 25, 25);
    XCross(35, 1, 25, false);
    driveCM(30, 15, 35, 35);
    closeFullLeft();
    closeFullRight(true);
    stopBC(100);
    driveCM(60, -8, 35, 35);  
    openFullLeft()
    openFullRight(true)
    driveCM(60, 11, 35, 35);
    floorGrabLeft();
    floorGrabRight(true);
    driveCM(60, -30, 35, 35);
    turnLine180(65, 165, 30);
    XCross(55, 1, 40, true, 5.8);
    turnLineRight(50, 75, 30);
    XCross(80, 1, 30, true, 6);
    XCross(80, 1, 40, true, 6);
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
    turnLine180(55, 165, 30);
    align();
    XCross(70, 1, 45, false);
    lineCM(70, 6.1, 35, 35);

    if (manipRight == 0 && manipLeft == 1) {right0left1();}
    else if (manipRight == 1 && manipLeft == 0) {right1left0();}
    else if (manipRight == 1 && manipLeft == 1) {twoSituations(true);} 
    else {twoSituations(false);}

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

    XCross(75, 1, 35, false);
    lineCM(70, 6, 35, 35);
    stopBC(100);

    if (cellRight == 0 && cellLeft == 1) {right0left1();}
    else if (cellRight == 1 && cellLeft == 0) {right1left0();}
    else if (cellRight == 1 && cellLeft == 1) {twoSituations(true);} 
    else {twoSituations(false);}
    turnLine180(45, 150, 60);
    align();
}

void takeRubbish() {
    closeFullLeft();
    closeFullRight();
    XCross(48, 1, 35, true, 6.9);
    turnLineLeft(55, 65, 30);
    for (int i = 0; i < 3; i++) {XCross(65, 1, 50, true, 3);}
    XCross(50, 1, 40, true, 7.2);
    turnLineRight(70, 65, 30);
    liftSomeLeft(true);
    lineCM(29, 2.4, 35, 35);
	align();
	arc(38, 9, 92.5, 45, 45);
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

void finish() {
    lineCM(27, 8, 25, 25);
    arc(80, -27.4, 179, 50, 50);
    lineCM(80, 5, 80, 100);
    closeFullLeft();
    closeFullRight();
    XCross(65, 1, 100, false);
    driveCM(40, 20, 40, 40);
    stopBC(0);
    int time = time1[T3] / 1000;
    while (true) {displayBigStringAt(0, 120, "%d secs", time);}
}

void runner() {
    scan();
    toCubes();
    scanHeights();
    grab4();
    cubes();
    takeRubbish();
    takeCubes();
    bringContsToShip();
    finish();
}