#ifndef _HITECHCOLORSCAN_H_
#define _HITECHCOLORSCAN_H_

#include "drivers/hitechnic-colour-v2.h"

tHTCS2 s;
tHTCS2 hS;

void getRGB(tHTCS2 sensor, float &r, float &g, float &b) {
    readSensor(&sensor);
    r = sensor.red;
    g = sensor.green;
    b = sensor.blue;
}

float getSum(tHTCS2 sensor) {
    float r, g, b;
    getRGB(sensor, r, g, b);
    return r + g + b;
}

void getHSVL(tHTCS2 sensor, float &h, float &s, float &v, float &l) {
    float r, g, b;
    getRGB(sensor, r, g, b);
    float maxV = max3(r, g, b);
    float minV = min3(r, g, b);
    if (maxV == minV) {h = 0;}
    else if (maxV == r && g >= b) {h = 60 * (g - b) / (maxV - minV);}
    else if (maxV == r && g < b) {h = 60 * (g - b) / (maxV - minV) + 360;}
    else if (maxV == g) {h = 60 * (b - r) / (maxV - minV) + 120;}
    else if (maxV == b) {h = 60 * (r - g) / (maxV - minV) + 240;}

    if (maxV == 0) {s = 0;}
    else {s = 1 - minV / maxV;}

    l = (maxV + minV) / 2;
    v = maxV; 
}

// 0.3 cm - min; 5 cm - max
int getColorCloseHT(tHTCS2 sensor) {
    float h, s, v, l;
    getHSVL(sensor, h, s, v, l);
    if (v < 7) {return 0;}
    if (s <= 0.4) {
        if (h >= 90 && h < 210) {return 3;}
        else if (v < 60) {return 1;}
        else {return 6;}
    } else {
        if ((h >= 300 && h <= 360) || (h < 20)) {return 5;}
        else if (h >= 20 && h < 90) {return 4;}
        else if (h >= 90 && h < 210) {return 3;}
        else if (h >= 210 && h < 300) {return 2;}
    }
    return -1;
}

// 5 cm - min; 9 cm - max;
int getColorFarHT(tHTCS2 sensor) {
    float h, s, v, l;
    getHSVL(sensor, h, s, v, l);
    if (v < 7) {return 0;}
    if (s < 0.4 && h > 215) {
        if (v >= 25) {return 6;}
        else {return 1;}
    } else {
        if ((h >= 300 && h <= 360) || (h < 20)) {return 5;}
        else if (h >= 20 && h < 90) {return 4;}
        else if (h >= 90 && h < 220) {return 3;}
        else {return 2;}
    }
}

#endif