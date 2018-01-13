// SparkFun Si7021 Humidity and Temperature Sensor - Version: Latest 
#include <SparkFun_Si7021_Breakout_Library.h>
#include <Wire.h>

//  Student Accelerator Hackathon - 2018
//  HC-05 Basic program to send value (0 or 1) triggered by a button   
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(9,10); // Arduino RX 9 - BT TX 9  | Arduino TX 10 - BT RX 10 

float tempf = 0;

int power = ?;
int GND = ?;

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
    
    // sets the output pins 
    pinMode(power, OUTPUT);
    pinMode(GND, OUTPUT);
    
    // write 
    digitalWrite(power, HIGH);
    digitalWrite(GND, LOW);

    //Initialize the I2C sensors and ping them
    sensor.begin();
}
 
void loop()
{
    getWeather();
    checkMotion();
    printInfo();
    delay(1000);
}

void getWeather() {
  tempf = sensor.getTempF();
}

void checkMotion()
{
  if(digitalRead(4)==HIGH)  
    {
      Serial.println("Movement detected.");
    }
    else  
    {
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


