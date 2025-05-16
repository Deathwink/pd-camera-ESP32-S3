#pragma once
#include "common.h"
#include <memory>


#define USE_CAMERA_BUILTIN


#if defined USE_CAMERA_BUILTIN
    #include "ESP32CameraBuiltin.h"
#endif

#include <Dither.h>


///
enum DitherType
{
    STUCKI,
    ATKINSON,
    FS,
    FAST,
    BAYER,
    RNDM,
    THRESHOLD
};


#define CAMERA_QUEUE_COUNT 1
#define CAMERA_QUEUE_POOL_COUNT (CAMERA_QUEUE_COUNT + 2)


///
class PDCameraTask
{
protected:


    ///
    DataBuffer* m_bufPool[CAMERA_QUEUE_POOL_COUNT];

    ///
    int m_poolIndex;

    ///
    QueueHandle_t m_queue;

    ///
    Dither m_oDither;

    ///
    DitherType m_currDitherType;

    ///
    uint8_t m_thresh;

    ///
    int m_contrast;

    ///
    int m_brightness;

    ///
    int m_mirror;


    ///
    std::shared_ptr<ESP32CameraIF> m_spCamera;

    ///
    void Capture();

    ///
    void CameraCaptureTask();

    ///
    static void _CameraCaptureTask(void* param);



public:


    ///
    PDCameraTask();

    ///
    ~PDCameraTask();

    ///
    void BeginTask();

    ///
    void SetDitherType(DitherType currDitherType);

    ///
    DitherType GetDitherType();

    ///
    void SetThresh(uint8_t thresh);    

    ///
    void SetContrast(int contrast);

    ///
    void SetBrightness(int brightness);

    ///
    void SetMirror(int mirror);

    ///
    DataBuffer* GetCameraData();
};


