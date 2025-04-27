void initAll() {
	// initSensor(&sensor, S1);
	initColors();
}

void registerMapping() {
	long fileHandle = fileOpenRead("vals.txt");
	fileReadLong(fileHandle, &r1Min);
	fileReadLong(fileHandle, &g1Min);
	fileReadLong(fileHandle, &b1Min);
	fileReadLong(fileHandle, &r1Max);
	fileReadLong(fileHandle, &r1Max);
	fileReadLong(fileHandle, &r1Max);

	fileReadLong(fileHandle, &r2Min);
	fileReadLong(fileHandle, &g2Min);
	fileReadLong(fileHandle, &b2Min);
	fileReadLong(fileHandle, &r2Max);
	fileReadLong(fileHandle, &r2Max);
	fileReadLong(fileHandle, &r2Max);

	/*fileHandle = fileOpenRead("valsBlueGray.txt");
	fileReadLong(fileHandle, &r1MinBlueGray);
	fileReadLong(fileHandle, &g1MinBlueGray);
	fileReadLong(fileHandle, &b1MinBlueGray);
	fileReadLong(fileHandle, &r1MaxBlueGray);
	fileReadLong(fileHandle, &r1MaxBlueGray);
	fileReadLong(fileHandle, &r1MaxBlueGray);

	fileReadLong(fileHandle, &r2MinBlueGray);
	fileReadLong(fileHandle, &g2MinBlueGray);
	fileReadLong(fileHandle, &b2MinBlueGray);
	fileReadLong(fileHandle, &r2MaxBlueGray);
	fileReadLong(fileHandle, &r2MaxBlueGray);
	fileReadLong(fileHandle, &r2MaxBlueGray);*/
}

void registerLine(lineColor line1, lineColor line2, char* fileName) {
	long fileHandle = fileOpenRead(fileName);
	fileReadLong(fileHandle, &line1.minR);
	fileReadLong(fileHandle, &line1.minG);
	fileReadLong(fileHandle, &line1.minB);
	fileReadLong(fileHandle, &line1.maxR);
	fileReadLong(fileHandle, &line1.maxG);
	fileReadLong(fileHandle, &line1.maxB);
	fileReadLong(fileHandle, &line2.minR);
	fileReadLong(fileHandle, &line2.minG);
	fileReadLong(fileHandle, &line2.minB);
	fileReadLong(fileHandle, &line2.maxR);
	fileReadLong(fileHandle, &line2.maxG);
	fileReadLong(fileHandle, &line2.maxB);

	int deltaR = (line1.maxR - line1.minR) * 0.1;
	int deltaG = (line1.maxG - line1.minG) * 0.1;
	int deltaB = (line1.maxB - line1.minB) * 0.1;

	line1.minR -= deltaR;
	line1.minG -= deltaG;
	line1.minB -= deltaB;

	line1.maxR += deltaR;
	line1.maxG += deltaG;
	line1.maxB += deltaB;

	deltaR = (line2.maxR - line2.minR) * 0.1;
	deltaG = (line2.maxG - line2.minG) * 0.1;
	deltaB = (line2.maxB - line2.minB) * 0.1;

	line2.minR -= deltaR;
	line2.minG -= deltaG;
	line2.minB -= deltaB;

	line2.maxR += deltaR;
	line2.maxG += deltaG;
	line2.maxB += deltaB;
}