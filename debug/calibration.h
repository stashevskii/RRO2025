#pragma config(Sensor, S1,     ,               sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S2,     leftS,          sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     rightS,         sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, openLoop, encoder)
#pragma config(Motor,  motorD,           ,             tmotorEV3_Medium, openLoop, encoder)

void calibrate() {
	// init arrays
	int rgbLeft[6] = {1000, 1000, 1000, 0, 0, 0};
    int rgbRight[6] = {1000, 1000, 1000, 0, 0, 0};
    int rgbS1[3], rgbS2[3];
    
    setMotorBrakeMode(leftMotor, motorCoast);
    setMotorBrakeMode(rightMotor, motorCoast);

    clearTimer(T1);
    while(time1[T1] < 5000) {
        getColorRawRGB(leftS, rgbS1[0], rgbS1[1], rgbS1[2]);
        getColorRawRGB(rightS, rgbS2[0], rgbS2[1], rgbS2[2]);
        
        for(int i = 0; i < 3; i++) {
            rgbLeft[i] = min(rgbS1[i], rgbLeft[i]);
            rgbLeft[i+3] = max(rgbS1[i], rgbLeft[i+3]);
            
            rgbRight[i] = min(rgbS2[i], rgbRight[i]);
            rgbRight[i+3] = max(rgbS2[i], rgbRight[i+3]);
        }
    }

    // print results
    for(int i = 0; i < 6; i++) {
        displayBigStringAt(
			(i < 3 ? 0 : 120),
			120 - i * 20, 
			"%s%d",
			(i%3==0?"r":i%3==1?"g":"b"),
			(i < 3 ? rgbLeft[i] : rgbRight[i - 3])
		);
    }

    while(!getButtonPress(buttonAny)) {}
}
