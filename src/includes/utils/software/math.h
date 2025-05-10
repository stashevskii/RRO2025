#ifndef _MATH_H_
#define _MATH_H_

const float diametr = 6.24;
const float base = 17.657;

float min(float a, float b) {
	if (a > b) return b;
	return a;
}

float max(float a, float b) {
	if (a < b) return b;
	return a;
}

float min3(float a, float b, float c) {
	if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

float max3(float a, float b, float c) {
	if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

float fromCmToDeg(float cm) {
	return (cm / (diametr * PI)) * 360;
}

float fromDegToCm(float degr) {
	return (degr * (diametr / PI)) / 360;
}

float d2d(float angle, float k = 1) {
	return (base * angle * k) / diametr;
}

float map(float val, float l, float r, float maxVal) {
	float a = (val - l) / (r - l);
  	return a * maxVal;
}

int lim(int cur, int l, int r) {
	if(cur > r)
    	return r;
  	else if(cur < l)
    	return l;
  	return cur;
}

float calcCoefficient(float speed, float default_coef, float default_speed) {
	if(speed == 0) return default_coef;
	return sqrt(speed / default_speed) * default_coef;
}

#endif