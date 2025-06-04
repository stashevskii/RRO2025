#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct {
	long minR, maxR;
	long minG, maxG;
	long minB, maxB;
} lineColor;

typedef struct {
	long r1Min;	long g1Min; long b1Min;
	long r1Max; long g1Max; long b1Max;

	long r2Min; long g2Min; long b2Min;
	long r2Max; long g2Max; long b2Max;
} lineValues;

lineColor blackLine;
lineColor whiteLine;

lineValues lv;

void initColors() {
	blackLine.minR = -20;
	blackLine.maxR = 35;
	blackLine.minG = -20;
	blackLine.maxG = 35;
	blackLine.minB = -20;
	blackLine.maxB = 35;
}

void initLineValues() {
	lv.r1Min = 0;
	lv.g1Min = 38;
	lv.b1Min = 39;
	lv.r1Max = 263;
	lv.g1Max = 278;
	lv.b1Max = 336;

	lv.r2Min = 22;
	lv.g2Min = 47;
	lv.b2Min = 42;
	lv.r2Max = 151;
	lv.g2Max = 276;
	lv.b2Max = 356;
}

#endif