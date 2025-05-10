#ifndef _COLORSCAN_H_
#define _COLORSCAN_H_

bool checkColor(tSensors sensor, lineColor color) {
	float r, g, b;
	sensorRGB(sensor, r, g, b);
	return color.minR <= r && r <= color.maxR && color.minB <= b && b <= color.maxB && color.minG <= g && g <= color.maxG;
}

void getRGBcs(tSensors sensor, long &r, long &g, long &b) {
    long r1, g1, b1;
    getColorRawRGB(sensor, r1, g1, b1);
    r = r1;
    g = g1;
    b = b1;
}

void getHSVLcs(tSensors sensor, float &h, float &s, float &v, float &l) {
    long r, g, b;
    getRGBcs(sensor, r, g, b);
    float max_ = max3(r, g, b);
    float min_ = min3(r, g, b);
    if (max_ == min_) {h = 0;}
    else if (max_ == r && g >= b) {h = 60 * (g - b) / (max_ - min_);}
    else if (max_ == r && g < b) {h = 60 * (g - b) / (max_ - min_) + 360;}
    else if (max_ == g) {h = 60 * (b - r) / (max_ - min_) + 120;}
    else if (max_ == b) {h = 60 * (r - g) / (max_ - min_) + 240;}

    if (max_ == 0) {s = 0;}
    else {s = 1 - min_ / max_;}

    l = (max_ + min_) / 2;
    v = max_;
}

int getColorCS(tSensors sensor) {
    float h, s, v, l;
    getHSVLcs(sensor, h, s, v, l);
    if (v < 20) {return 5;}
    else {
        if (s < 0.3) {return 6}
        else {
            if ((h >= 300 && h <= 360) || (h < 20) ) {return 1;}
            else if (h >= 20 && h < 90) {return 2;}
            else if (h >= 90 && h < 160) {return 3;}
            else if (h >= 160 && h < 300) {return 4;}
        }
    }
}


#endif