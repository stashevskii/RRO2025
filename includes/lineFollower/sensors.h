#ifndef _SENSORS_H_
#define _SENSORS_H_

void sensorRGB(tSensors sensor, float &r, float &g, float &b) {
	int rawR, rawG, rawB, rMin, gMin, bMin, rMax, gMax, bMax;
	getColorRawRGB(sensor, rawR, rawG, rawB);
	if (sensor == rightS) {
		rMin = r2Min; gMin = g2Min; bMin = b2Min;
		rMax = r2Max; gMax = g2Max; bMax = b2Max;
	} else {
		rMin = r1Min; gMin = g1Min; bMin = b1Min;
		rMax = r1Max; gMax = g1Max; bMax = b1Max;
	}
	r = map(rawR, rMin, rMax, 100);
	g = map(rawG, gMin, gMax, 100);
	b = map(rawB, bMin, bMax, 100);
}

#endif