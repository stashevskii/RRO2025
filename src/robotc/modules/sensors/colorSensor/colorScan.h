#ifndef _COLORSCAN_H_
#define _COLORSCAN_H_

bool checkColor(tSensors sensor, lineColor color) {
	float r, g, b;
	sensorRGB(sensor, r, g, b);
	return color.minR <= r && r <= color.maxR && color.minB <= b && b <= color.maxB && color.minG <= g && g <= color.maxG;
}

void getRGBcs(tSensors sensor, long &r, long &g, long &b) {
    getColorRawRGB(sensor, r, g, b);
}

long getRGBSum(tSensors sensor) {
    long r, g, b;
    getRGBcs(sensor, r, g, b);
    return r + g + b;
}

void getHSVLcs(tSensors sensor, float &h, float &s, float &v, float &l) {
    long r, g, b;
    getRGBcs(sensor, r, g, b);
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

int getColorCS(tSensors sensor) {
    float h, s, v, l;
    getHSVLcs(sensor, h, s, v, l);
    if (v < 20) {return 5;}
    if (s < 0.3) {return 6}
    else {
        if ((h >= 300 && h <= 360) || (h < 20) ) {return 1;}
        else if (h >= 20 && h < 90) {return 2;}
        else if (h >= 90 && h < 160) {return 3;}
        else if (h >= 160 && h < 300) {return 4;}
    }
}

#endif