void debugManipulator(tMotor mm, int func, int size, int waiting) {
    if (mm == manipMotor) {openFullLeft(true);}
    else {openFullRight(true);}
    stopBC(waiting);
    if (func == 0) {
        if (mm == manipMotor) {liftContLeft(size, true);}
        else {liftContRight(size, true);}
    }
    delay(waiting * 4);
}