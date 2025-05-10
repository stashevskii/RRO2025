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
	blackLine.minR = -14;
	blackLine.maxR = 31;
	blackLine.minG = -14;
	blackLine.maxG = 31;
	blackLine.minB = -14;
	blackLine.maxB = 31;

	whiteLine.minR = 20;
	whiteLine.maxR = 300;
	whiteLine.minG = 20;
	whiteLine.maxG = 300;
	whiteLine.minB = 20;
	whiteLine.maxB = 300;
}

void initLineValues() {
	lv.r1Min = 1;
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