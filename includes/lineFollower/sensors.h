#ifndef _SENSORS_H_
#define _SENSORS_H_

void sensorRGB(tSensors sensor, float &r, float &g, float &b) {
	int rawR, rawG, rawB, rMin, gMin, bMin, rMax, gMax, bMax;
	getColorRawRGB(sensor, rawR, rawG, rawB);
	if (sensor == rightS) {
		rMin = lv.r2Min; gMin = lv.g2Min; bMin = lv.b2Min;
		rMax = lv.r2Max; gMax = lv.g2Max; bMax = lv.b2Max;
	} else {
		rMin = lv.r1Min; gMin = lv.g1Min; bMin = lv.b1Min;
		rMax = lv.r1Max; gMax = lv.g1Max; bMax = lv.b1Max;
	}
	r = map(rawR, rMin, rMax, 100);
	g = map(rawG, gMin, gMax, 100);
	b = map(rawB, bMin, bMax, 100);
}

#endif