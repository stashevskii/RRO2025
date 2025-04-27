#include "../hardware/stop.h"

void printNumbers(int *nums, int n, int w = 5600) {
    stopBC(0);
    eraseDisplay();
    for (int i = 0; i < n; i++) {
        displayBigStringAt(0, 120 - i * 20, "%f", nums[i]);
    }
    delay(w);
}