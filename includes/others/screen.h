void printNumbers(float *nums, int n) {
    stopBC(0);
    eraseDisplay();
    for (int i = 0; i < n; i++) {
        displayBigStringAt(0, 120 - i * 20, "%f", i);
    }
    delay(5600);
}