#include <Arduino.h>
#include <esp_camera.h>
#include <vector>
#include "ESP32CameraBuiltin.h"


///
ESP32CameraBuiltin::ESP32CameraBuiltin()
: m_sensor(NULL)
{
}


///
ESP32CameraBuiltin::~ESP32CameraBuiltin()
{

}


///
bool ESP32CameraBuiltin::Initialize()
{
    // Pinout per XIAO ESP32S3 Sense
    static camera_config_t camera_config = {
        .pin_pwdn     = -1, // Non definito specificamente per XIAO o gestito internamente
        .pin_reset    = -1, // Non definito specificamente per XIAO o gestito internamente
        .pin_xclk     = 10,
        .pin_sscb_sda = 40, // CAM_SDA
        .pin_sscb_scl = 39, // CAM_SCL

        .pin_d7 = 48, // DVP_Y9
        .pin_d6 = 11, // DVP_Y8
        .pin_d5 = 12, // DVP_Y7
        .pin_d4 = 14, // DVP_Y6
        .pin_d3 = 16, // DVP_Y5
        .pin_d2 = 18, // DVP_Y4
        .pin_d1 = 17, // DVP_Y3
        .pin_d0 = 15, // DVP_Y2

        .pin_vsync = 38, // DVP_VSYNC
        .pin_href  = 47, // DVP_HREF
        .pin_pclk  = 13, // DVP_PCLK

        .xclk_freq_hz = 20000000,
        .ledc_timer   = LEDC_TIMER_0,
        .ledc_channel = LEDC_CHANNEL_0,

        .pixel_format = PIXFORMAT_GRAYSCALE, // Il progetto originale usa GRAYSCALE
        .frame_size   = FRAMESIZE_QVGA,   // QVGA(320x240)
        .jpeg_quality = 0, // Qualità JPEG (0-63). Usato se pixel_format è JPEG
        .fb_count     = 2, // Aumentato a 2 come da molti esempi, fb_count=1 può dare problemi
        .fb_location  = CAMERA_FB_IN_PSRAM,
        .grab_mode    = CAMERA_GRAB_WHEN_EMPTY, // o CAMERA_GRAB_LATEST se si preferisce il frame più recente
    };

    esp_err_t err = esp_camera_init(&camera_config);
    if (err != ESP_OK)
    {
        Serial.printf("Camera Init Failed with error 0x%x\n", err); // Output su Seriale
        return false;
    }

    m_sensor = esp_camera_sensor_get();
    if (m_sensor == NULL)
    {
        Serial.println("Failed to get camera sensor"); // Output su Seriale
        return false;
    }
    
    // Impostazioni sensore aggiuntive se necessario (es. flip, AWB, etc.)
    // sensor_t * s = esp_camera_sensor_get();
    // s->set_vflip(s, 1); // example
    // s->set_hmirror(s, 1); // example

    return true;
}


///
void ESP32CameraBuiltin::SetContrast(int contrast)
{
    if (m_sensor)
    {
        m_sensor->set_contrast(m_sensor, contrast);
    }
}


///
void ESP32CameraBuiltin::SetBrightness(int brightness)
{
    if (m_sensor)
    {
        m_sensor->set_brightness(m_sensor, brightness);
    }
}


///
void ESP32CameraBuiltin::SetMirror(int mirror)
{
    if (m_sensor)
    {
        m_sensor->set_hmirror(m_sensor, mirror); // Assumendo che mirror 0 o 1 controlli hmirror
        // Per vflip, si potrebbe aggiungere un altro metodo o modificare questo
    }
}


///
void ESP32CameraBuiltin::Capture(DataBuffer* data)
{
    // acquire a frame

    assert(data != NULL);

    camera_fb_t* fb = esp_camera_fb_get();
    if (fb)
    {
        if (data->GetSize() < fb->len) // Controlla se il buffer di destinazione è abbastanza grande
        {
            // Se il buffer fornito è più piccolo del frame catturato,
            // copia solo la porzione che ci sta. Questo potrebbe essere un problema
            // a seconda di come CAMERA_DATA_SIZE_W e CAMERA_DATA_SIZE_H sono definiti
            // e se corrispondono a fb->width e fb->height e pixel_format.
            // Per PIXFORMAT_GRAYSCALE, fb->len è width*height.
            // Per sicurezza, o si assicura che DataBuffer sia sempre della dimensione corretta,
            // o si gestisce il troncamento/errore.
            // L'implementazione originale copiava CAMERA_DATA_SIZE_W * CAMERA_DATA_SIZE_H bytes
            // se il buffer era piccolo, il che potrebbe essere corretto se quelle dimensioni
            // sono le dimensioni attese dal resto del sistema.
            // Mantengo la logica originale per ora.
            ::memcpy(data->GetBuffer(), fb->buf, CAMERA_DATA_SIZE_W * CAMERA_DATA_SIZE_H);
        }
        else
        {
            ::memcpy(data->GetBuffer(), fb->buf, fb->len);
        }
        esp_camera_fb_return(fb);
    }
    else
    {
        Serial.println("Camera capture failed"); // Segnala errore su seriale
        // L'originale riempiva il buffer con 0xff. Potrebbe essere un placeholder per 'no image'.
        ::memset(data->GetBuffer(), 0xff,  CAMERA_DATA_SIZE_W * CAMERA_DATA_SIZE_H);
    }
}

