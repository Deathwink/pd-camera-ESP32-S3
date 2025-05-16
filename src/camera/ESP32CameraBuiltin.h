#pragma once
#include "Common.h"
#include "ESP32CameraIF.h"
#include <esp_camera.h>



///
class ESP32CameraBuiltin
    : public ESP32CameraIF
{
private:


    ///
    sensor_t* m_sensor;



public:


    ///
    ESP32CameraBuiltin();

    ///
    ~ESP32CameraBuiltin();



    /*
        ESP32CameraIF
    */


    ///
    virtual bool Initialize();

    ///
    virtual void SetContrast(int contrast);

    ///
    virtual void SetBrightness(int brightness);

    ///
    virtual void SetMirror(int mirror);

    ///
    virtual void Capture(DataBuffer* data);
};


