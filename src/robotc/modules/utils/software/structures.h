#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct {
	long minR, maxR;
	long minG, maxG;
	long minB, maxB;
} lineColor;

typedef struct {
	long r1Min, g1Min, b1Min;
	long r1Max, g1Max, b1Max;

	long r2Min, g2Min, b2Min;
	long r2Max, g2Max, b2Max;
} lineValues;

lineColor blackLine;
lineColor whiteLine;

lineValues calibration;

void initColors() {
	blackLine.minR = -20;
	blackLine.maxR = 35;
	blackLine.minG = -20;
	blackLine.maxG = 35;
	blackLine.minB = -20;
	blackLine.maxB = 35;
}

void initLine() {
	calibration.r1Min = 0;
	calibration.g1Min = 38;
	calibration.b1Min = 39;
	calibration.r1Max = 263;
	calibration.g1Max = 278;
	calibration.b1Max = 336;

	calibration.r2Min = 22;
	calibration.g2Min = 47;
	calibration.b2Min = 42;
	calibration.r2Max = 151;
	calibration.g2Max = 276;
	calibration.b2Max = 356;
}

#endif