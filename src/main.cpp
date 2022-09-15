#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include <time.h>
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "DHT11Service.h"
#include "DHT11View.h"


int main()
{
    std::cout << "Hello World!" << std::endl;
    Button modeButton(27);
    Button powerButton(28);
    ClockCheck clockCheck;
    DHT11 dht(7);
    DHT_Data dhtData;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    DHT11View dht11View(&lcd, &led1, &led2, &led3, &led4, &led5);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockService(&clockView);
    DHT11Service dht11Service(&dht11View);
    Controller control(&service, &clockService, &dht11Service);
    Listener listener(&modeButton, &powerButton, &control, &clockCheck, &dht);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(100);
        // if (!dhtData.error) {
        //     // std::printf("RH: %d.%d, Temp: %d.%d\n", 
        //     //             dhtData.RH, dhtData.RHDec,
        //     //             dhtData.Temp, dhtData.TempDec);
        //     std::cout<<"humidity(%) : "
        //     << dhtData.RH << "." << dhtData.RHDec
        //     << " Temperature(Celcius) : "
        //     << dhtData.Temp << "." << dhtData.TempDec
        //     << std::endl;
        // }
    }
    return 0;
}