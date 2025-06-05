#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

int getHeight() {
    if (getUSDistance(ultrasonicS) > 10) {return 0;}
    return 1;
}

#endif