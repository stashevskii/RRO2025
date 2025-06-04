#ifndef _MATH_H_
#define _MATH_H_

const float diametr = 6.24;
const float base = 17.657;

float min(float a, float b) {return a < b ? a : b; }
float max(float a, float b) {return a > b ? a : b; }

float min3(float a, float b, float c) {return min(a, min(b, c));}
float max3(float a, float b, float c) {return max(a, max(b, c));}

float fromCmToDeg(float cm) {return (cm * 360) / (diametr * PI);}
float fromDegToCm(float deg) {return (deg * diametr * PI) / 360;}

float d2d(float angle, float k = 1) {return (base * angle * k) / diametr;}
float map(float val, float l, float r, float maxVal) {return maxVal * (val - l) / (r - l);}

int lim(int cur, int l, int r) {return cur < l ? l : cur > r ? r : cur;}
float calcCoefficient(float speed, float default_coef, float default_speed) {return speed == 0 ? default_coef : default_coef * sqrt(speed / default_speed);}

#endif