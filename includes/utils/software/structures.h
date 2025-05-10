#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct {
	long minR, maxR;
	long minG, maxG;
	long minB, maxB;
} lineColor;

lineColor blackLine;
lineColor whiteLine;

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

#endif