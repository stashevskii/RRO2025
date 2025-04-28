#ifndef __SENSORS_H__
#define __SENSORS_H__

void sensorRGB(tSensors sensor, float &r, float &g, float &b) {
	int r1, g1, b1;
	if(sensor == leftS) {
		getColorRawRGB(sensor, r1, g1, b1);
		r = map(r1, r1Min, r1Max, 100);
		g = map(g1, g1Min, g1Max, 100);
		b = map(b1, b1Min, b1Max, 100);
	} else if (sensor == rightS){
		getColorRawRGB(sensor, r1, g1, b1);
		r = map(r1, r2Min, r2Max, 100);
		g = map(g1, g2Min, g2Max, 100);
		b = map(b1, b2Min, b2Max, 100);
	} else {
		getColorRawRGB(sensor, r1, g1, b1);
		r = map(r1, r1Min, r1Max, 100);
		g = map(g1, g1Min, g1Max, 100);
		b = map(b1, b1Min, b1Max, 100);
	}
}

#endif
