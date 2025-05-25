#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

int detectHigh() {
    if (getUSDistance(ultrasonicS) > 9) {return 0;}
    return 1;
}

#endif