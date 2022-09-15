#ifndef DHT11VIEW_H
#define DHT11VIEW_H

#include "LCD.h"

class DHT11View
{
private:
    LCD *lcd;

public:
    DHT11View(LCD *lcd);
    ~DHT11View();
    void setTempHumidData(float temp, float humid);
};

#endif