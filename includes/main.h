#include "init/globals.h"

void scan() {
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
    if (gottenDir != 3) {lineCM(75, 6.5, 35, 35); directions(gottenDir, 1);}
    else {turnLeft(70, 179, 35);}
    align();

    lineCM(80, 10, 35, 35);
    openFullLeft();
    openFullRight();
    lineCM(35, 5, 35, 35);
    floorGrabLeft();
    floorGrabRight();
    XCross(75, 1, 100, true, 7);
}

void cubes() {
    turnLineRight(75, 70, 25);
    XCross(40, 1, 25, false);
    driveCM(60, 16.5, 35, 35);
    openFullLeft();
    openFullRight(true);
    driveCM(75, -10, 35, 53);
    closeFullLeft();
    closeFullRight(true);
    stopBC(350);
    liftSomeLeft();
    liftContRight(true);
    stopBC(100);
    driveCM(60, 5.5, 35, 53);
    driveCM(75, -26, 35, 53);
    stopBC(20000);
}

void takeCubes(){
    closeFullLeft();
    closeFullRight(true);
    stopBC(300);
    liftSomeLeft(true);
    liftSomeRight(true);
    stopBC(100); 
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
    XCross(80, 1, 40, true, 6);
    turnLineRight(70, 75, 30);
    XCross(80, 1, 40, true, 6);
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
    turnLine180(55, 165, 60);
    align();
}

void takeRubbish() {
    lineCM(75, 5, 75, 75);
    XCross(100, 1, 35);
    closeFullLeft();
    closeFullRight();
    XCross(100, 1, 100);
    XCross(75, 1, 75, true, 6.9);
    turnLineLeft(75, 65, 30);
    for (int i = 0; i < 3; i++) {XCross(65, 1, 50, true, 3);}
    XCross(65, 1, 40, true, 7.2);
    turnLineRight(70, 65, 30);
    liftSomeLeft(true);
    lineCM(35, 1.42, 35, 35);
	align();
	arc(45, 9, 91.7, 45, 45);
	driveCM(62, 51, 20, 25);
	openLeftRubbish(true);
	arc(75, 15, 90, 45, 45);
	driveCM(62, 42.5, 20, 25);
	liftContLeft(0, true);
    driveCM(62, -3.5, 20, 25);
	arc(85, 20, -90, 45, 45);
    closeFullLeft();
    closeFullRight();
    turnLineRight(75, 65, 30);
    align();
    lineCM(75, 2, 75, 75);
    XCross(75, 1, 40, true, 3);
    XCross(75, 1, 75, true, 6.5);
    turnLineRight(75, 65, 30);
    lineCM(100, 14, 40, 75);
    XCross(75, 1, 75, true, 6.8);
    turnLineLeft(75, 65, 30);
    XCross(75, 1, 40, false);
    driveCM(45, 21.5, 20, 20);
    while (true) {closeFullRight(true);}
}

void runner() {
    scan();
    toCubes();
    scanHeights();
    grab4();
    cubes();
    takeCubes();
    bringContsToShip();
    takeRubbish();
}