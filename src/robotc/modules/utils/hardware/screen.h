#ifndef _SCREEN_H_
#define _SCREEN_H_

void printNumbers(int *nums, int n, int w = 5600) {
    stopBC(0);
    eraseDisplay();
    for (int i = 0; i < n; i++) {
        displayBigStringAt(0, 120 - i * 20, "%f", nums[i]);
    }
    delay(w);
}

void printNumber(int n, int w = 5600) {
    stopBC(0);
    eraseDisplay();
    displayBigStringAt(0, 120, "%f", n);
    delay(w);
}

void printTime() {
    stopBC(0);
    displayBigStringAt(0, 120, "%d secs", time1[T3] / 1000);
    while (true) {}
}

#endif