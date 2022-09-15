#include "DHT11View.h"

DHT11View::DHT11View(LCD *lcd)
{
    this->lcd = lcd;
}

DHT11View::~DHT11View()
{

}

void DHT11View::setTempHumidData(float temp, float humid)
{
    char buff[30];
    sprintf(buff, "  %.1fC  %.1f%%", temp, humid);
    lcd->WriteStringXY(0, 0, buff);
    printf("%s\n", buff);
}