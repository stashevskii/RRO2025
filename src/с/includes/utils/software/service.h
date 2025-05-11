#ifndef _SERVICE_H_
#define _SERVICE_H_

void findDuoAndCross(int *colsArr, int &nc, int &cr, int &cl) {
    for (int i = 0; i < 6; i++) {
        if (colsArr[i] == 6 && colsArr[i + 1] == 6) {
            nc = i + 1;
            colsArr[i] = -1;
            colsArr[i + 1] = -1;
            cl = scannedHeights[i];
            cr = scannedHeights[i + 1];
            break;
        }
    }
}

void findManipsAndCross(
    int *colsArr,
    int *h,
    int currCross,
    int needCross,
    int cellRight,
    int &outCurrCross,
    int &outNeedCross,
    bool &outLeft,
    bool &outRight,
    int &outManipRight,
    int &outManipLeft,
) {
    currCross = needCross;
    for (int i = 0; i < 6; i++) {
        if (colsArr[i] == 6) {
            colsArr[i] = -1;
            needCross = i;
            if (cellRight == colsArr[i]) {
                outLeft = true;
                outManipLeft = h[i];
                for (int j = 0; j < 6; j++) {
                    if (colsArr[j] == 6) {outManipRight = h[j]; break;}
                }
            } else {
                outRight = true;
                outManipRight = h[i];
                for (int j = 0; j < 6; j++) {
                    if (colsArr[j] == 6) {outManipLeft = h[j]; break;}
                }
            }
            break;
        }
    }
    if (needCross < currCross) {currCross--;}
    outCurrCross = currCross;
    outNeedCross = needCross;
}

void takeRightOrLeft(bool l) {
    if (l) {takeLeftManip();}
    else {takeRightManip();}
}

void updateCurrAndNeedCross(int currCross, int needCross, int &outCurrCross, int &outNeedCross) {
    currCross = needCross; 
    for (int i = 0; i < 6; i++) {
        if (scannedColors[i] == 6) {
            needCross = i;
            break;
        }
    }
    if (needCross < currCross) {currCross--;}
    outCurrCross = currCross;
    outNeedCross = needCross;
}

void setDirectionByRightOrLeft(int gd, bool r, bool l) {
    if (r) {
        driveCM(90, 8.9, 30, 30);
        directions(gd, 3);
        align();
        takeLeftManip();
    } else if (l) {
        driveCM(90, 8.9, 30, 30);
        turnLine180(70, 165, 35);
        directions(oppositeDir(gd), 3);
        align();
        takeRightManip();
    }
}

void turnBasedOnDirection(int gd) {
    if (gd != 3) {lineCM(60, 7.25, 35, 35); directions(gd, 1); align();}
    else {turnLeft(70, 179, 35);}
}

void leaveContsAtShip(int r, int l) {
    if (r == 0 && l == 1) {right0left1();}
    else if (r == 1 && l == 0) {right1left0();}
    else if (r == 1 && l == 1) {twoSituations(true);} 
    else {twoSituations(false);}
}

void getFirstContHigh(int *h, int c) {
    if (c == 2) {h[0] = 0;}
    else {h[0] = 1;}
}

void scanFiveConts(int *h, int &counter) {
    for (int i = 1; i < 6; i++) {
        if (i == 5) {
            driveCM(75, 10.5, 85, 25);
            h[i] = detectHigh();
            driveCM(75, -3.5, 85, 25);
            if (h[i] == 1) {counter++;}
            break;
        }
        XCross(90, 1, 85, false);
        h[i] = detectHigh();
        if (h[i] == 1) {counter++;}
        driveCM(90, 2, 85, 100);
    }
}

#endif