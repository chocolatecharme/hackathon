// SparkFun Si7021 Humidity and Temperature Sensor - Version: Latest 
#include <SparkFun_Si7021_Breakout_Library.h>
#include <Wire.h>

//  Student Accelerator Hackathon - 2018
//  HC-05 Basic program to send value (0 or 1) triggered by a button   
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(9,10); // Arduino RX 9 - BT TX 9  | Arduino TX 10 - BT RX 10 

float tempf = 0;
bool motion = 0;

struct DataPack
{
  int tempData;
  bool motionData;
};

//int power = ?;
//int GND = ?;

Weather sensor;

// //button to pin 3
// int button = 3; 

void setup() 
{  
    //Serial monitor (top right icon) set to 9600 baud rate
    Serial.begin(9600);
    Serial.println("Arduino Serial Begin");

    //HC-05 communication set at 9600 baud rate
    BTserial.begin(9600);  
    Serial.println("Bluetooth Serial Begin");
    
    // set inputs and outputs
//    pinMode(power, OUTPUT);
//    pinMode(GND, OUTPUT);
    pinMode(6,INPUT);

    
    // set corresponding voltage
//    digitalWrite(power, HIGH);
//    digitalWrite(GND, LOW);
    digitalWrite(6,LOW);

    //Initialize the I2C sensors and ping them
    sensor.begin();
}
 
void loop()
{
    getWeather();
    checkMotion();
    printInfo();
    sendData();
    delay(1000);
}

void getWeather() {
  tempf = sensor.getTempF();
}

void checkMotion()
{
  if(digitalRead(4)==HIGH)  
    {
      motion = 1;
      Serial.println("Movement detected.");
    }
    else  
    {
      motion = 0;
      Serial.println("Nothing.");
    }
    delay(1000);
}

void printInfo()
{
//This function prints the weather data out to the default Serial Port

  Serial.print("Temp:");
  Serial.print(tempf);
  Serial.print("F, ");
}

void sendData() {
 //read value from button(pin 3) and send via Bluetooth 
 BTserial.print(motion + "-" + static_cast<int>(tempf)); 
 
 //read value from button(pin 3) and send to serial monitor 
 Serial.println(motion + "-" + static_cast<int>(tempf));

 //delay 50milliseconds 
 delay(50);   
}
