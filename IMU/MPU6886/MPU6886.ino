  

#include "M5Atom.h"


float temp = 0;

float AccX = 0, AccY = 0, AccZ = 0;
float GyroX = 0, GyroY = 0, GyroZ = 0;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;

int c = 0;



bool IMU6886Flag = false;

void setup()
{
    M5.begin(true, true, true);

    if (M5.IMU.Init() != 0)
        IMU6886Flag = false;
    else
        IMU6886Flag = true;


}

void loop()
{

    if (IMU6886Flag == true)
    {
        M5.IMU.getGyroData(&GyroX, &GyroY, &GyroZ);
        M5.IMU.getAccelData(&AccX, &AccY, &AccZ);
//        M5.IMU.getTempData(&temp);

        M5.IMU.getAhrsData(&pitch, &roll, &yaw);



  Serial.printf("%.2f\r\n", yaw);
  Serial.printf("%.2f\r\n", roll);
  Serial.printf("%.2f\r\n", pitch);
 
    }
    delay(50);
    M5.update();
}
