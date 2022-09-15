#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "View.h"
#include "LightState.h"

#pragma once

class Service
{
private:
    int lightState;
    View *view;

public:
    Service(View *view);
    virtual ~Service();
    void updateState(std::string strState);

};

#endif