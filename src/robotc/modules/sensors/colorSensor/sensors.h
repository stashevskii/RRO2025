#ifndef _SENSORS_H_
#define _SENSORS_H_

void sensorRGB(tSensors sensor, float &r, float &g, float &b) {
	int rawR, rawG, rawB, rMin, gMin, bMin, rMax, gMax, bMax;
	getColorRawRGB(sensor, rawR, rawG, rawB);
	if (sensor == rightS) {
		rMin = calibration.r2Min; gMin = calibration.g2Min; bMin = calibration.b2Min;
		rMax = calibration.r2Max; gMax = calibration.g2Max; bMax = calibration.b2Max;
	} else {
		rMin = calibration.r1Min; gMin = calibration.g1Min; bMin = calibration.b1Min;
		rMax = calibration.r1Max; gMax = calibration.g1Max; bMax = calibration.b1Max;
	}
	r = map(rawR, rMin, rMax, 100);
	g = map(rawG, gMin, gMax, 100);
	b = map(rawB, bMin, bMax, 100);
}

#endif