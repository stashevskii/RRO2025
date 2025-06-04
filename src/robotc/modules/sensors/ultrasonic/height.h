#ifndef _HEIGHT_H_
#define _HEIGHT_H_

void getFirstContHigh(int *arr, int c) {
    arr[0] = (c != 2);
}

void scanFiveConts(int *arr, int &counter) {
    for (int i = 1; i < 6; i++) {
        if (i == 5) {
            driveCM(80, 11, 80, 25);
            arr[i] = detectHigh();
            driveCM(80, -3, 80, 25);
        } else {
            XCross(80, 1, 80, false);
            arr[i] = detectHigh();
            driveCM(80, 1.7, 80, 80);
        }

        if (arr[i] == 1) {counter++};
    }
}

#endif