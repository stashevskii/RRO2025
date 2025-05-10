#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

int detectHigh() {
    if (getUSDistance(colorS2) > 7) {return 0;}
    else {return 1;}
}

#endif