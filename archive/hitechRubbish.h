//CHANGE K DEPENDING ON DISTANCE
float stabilizeK(float current_distance, float known_distance, float k) {
	return (current_distance / known_distance) * k;
}

float getColorHTSashaNI(tHTCS2 sensor) {
	readSensor(&sensor);
	return sensor.color;
}


void getRGBHSVht(tHTCS2 sensor, float &r, float &g, float &b, float &h, float &s, float &v, float &color) {
	readSensor(&sensor);
	r = sensor.red;
	g = sensor.green;
	b = sensor.blue;
	color = sensor.color;
	float maxx = max3(r, g, b);
	float minn = min3(r, g, b);

	h = 0;
	if(maxx == r && g >= b)
		h = (60 * (g - b)) / (maxx - minn + 0.001);
	else if(maxx == r && g < b)
		h = (60 * (g - b)) / (maxx - minn + 0.001) + 360;
	else if(maxx == g)
		h = (60 * (b - r)) / (maxx - minn + 0.001) + 120;
	else
		h = (60 * (r - g)) / (maxx - minn + 0.001) + 240;

	s = 0;
	if(maxx != 0)
    s = 1 - (minn / (maxx  + 0.001));
  	v = maxx;
}

//GET PRECENTS HITECH
void getPercentsHT(tHTCS2 sensor, float &r_percent, float &g_percent, float &b_percent, float &h_percent, float &s_percent, float &v_percent) {
	float r, g, b, h, s, v, htcolor;
	getRGBHSVht(sensor, r, g, b, h, s, v, htcolor);
	float sum_rgb = r + g + b;
	float sum_hsv = h + s + v;
	r_percent = r / sum_rgb * 100;
	g_percent = g / sum_rgb * 100;
	b_percent = b / sum_rgb * 100;
	h_percent = h / sum_hsv * 100;
	s_percent = s / sum_hsv * 10000;
	v_percent = v / sum_hsv * 100;
}

float getRed(tHTCS2 sensor) {
	float r, g, b, h, s, v, htcolor;
	getRGBHSVht(sensor, r, g, b, h, s, v, htcolor);
	return r;
}

float getSaturation(tHTCS2 sensor) {
	float r, g, b, h, s, v, htcolor;
	getRGBHSVht(sensor, r, g, b, h, s, v, htcolor);
	return s;
}

//GET COLOR HITECH
int getColorHTSasha(tHTCS2 sensor) {
	float h, s, v, r, g, b, ht_color;
	float r_percent, g_percent, b_percent;
	float h_percent, s_percent, v_percent;

	getRGBHSVht(sensor, r, g, b, h, s, v, ht_color);
	if (r == 0) {r = 1;}
	else if (g == 0) {g = 1;}
	else if (b == 0) {b = 1;}
	else if (h == 0) {h = 1;}
	else if (s == 0) {s = 1;}
	else if (v == 0) {v = 1;}
	getPercentsHT(sensor, r_percent, g_percent, b_percent, h_percent, s_percent, v_percent);
	int col = 3;
	if (((r > 50 && g > 50 && b > 50) || (h > 239 && r >= 21 && g >= 21 && b >= 21)) && fabs(r - g) < 5.7) {col = 6;}
	else if (in_range(r_percent, 0, 40) && in_range(g_percent, 0, 40) && in_range(b_percent, 0, 43)) {
		if (h <= 218 && h > 3) {col = 3;}
		else {col = 1;}
	}
	else if (max3(r_percent, g_percent, b_percent) == r_percent && r_percent > 38.5) {
		if (g_percent >= 30) {col = 4;}
		else {col = 5;}
	}
	else if (max3(r_percent, g_percent, b_percent) == g_percent || fabs(g_percent - b_percent) < 5.5)
  	else if (max3(r_percent, g_percent, b_percent) == b_percent) {col = 2;}
	return col;
}

//GET CMYK FROM RGB
void rgbToCmyk(int r, int g, int b, float &c, float &m, float &y, float &k) {
    float rNorm = r / 255.0;
    float gNorm = g / 255.0;
    float bNorm = b / 255.0;

    k = 1 - max3(rNorm, gNorm, bNorm);

    if (k < 1) {
        c = (1 - rNorm - k) / (1 - k);
        m = (1 - gNorm - k) / (1 - k);
        y = (1 - bNorm - k) / (1 - k);
    } else {
        c = 0;
        m = 0;
        y = 0;
    }
}

void printCmyk(tHTCS2 sensor) {
	float r, g, b, c, m, y, k;
	while (true) {
		readSensor(&sensor);
		r = sensor.red;
		g = sensor.green;
		b = sensor.blue;
		rgbToCmyk(r, g, b, c, m, y, k);
		displayBigStringAt(0,120,"r %d",r);
		displayBigStringAt(0,100,"g %d",g);
		displayBigStringAt(0,80,"b %d",b);

		displayBigStringAt(50,120,"c %f",c);
		displayBigStringAt(50,100,"m %f",m);
		displayBigStringAt(50,80,"y %f",y);
		displayBigStringAt(50,60,"k %f",k);
	}
}
