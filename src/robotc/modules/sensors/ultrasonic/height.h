#ifndef _HEIGHT_H_
#define _HEIGHT_H_

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
            driveCM(87, 10, 87, 25);
            h[i] = detectHigh();
            driveCM(87, -3, 87, 25);
            if (h[i] == 1) {counter++;}
            break;
        }
        XCross(87, 1, 87, false);
        h[i] = detectHigh();
        if (h[i] == 1) {counter++;}
        driveCM(87, 1.7, 87, 87);
    }
}

#endif