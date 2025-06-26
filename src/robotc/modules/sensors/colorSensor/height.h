#ifndef _HEIGHT_H_
#define _HEIGHT_H_

int getHeight() {
    if (getUSDistance(ultraS) < 10) {return 1;}
    return 0;
}

void getFirst(int *arr, int c) {
    arr[0] = (c != 2);
}

void scanOne(int *arr, int speed, int i, int cm = 3) {
    XCross(speed, 1, speed, false);
    stopBC(45);
    arr[i] = getHeight();
    driveCM(speed, cm, speed, speed);
}

void scanFive(int *arr, int &counter) {
    for (int i = 1; i < 6; i++) {
        switch (i) {
            case 1:
                scanOne(arr, 30, i, 4);
                break;
            case 5:
                driveCM(70, 11, 70, 25);
                arr[i] = getHeight();
                driveCM(70, -3, 70, 25);
                break;
            default:
                scanOne(arr, 50, i);
        }
        if (arr[i] == 1) {counter++};
    }
}

#endif