#ifndef _BATTERY_H_
#define _BATTERY_H_

void checkVoltage() {
    if (getBatteryVoltage() < 7.9) {
        peak();
    }
}

#endif