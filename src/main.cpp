#include "Common.h"
// #include <M5Unified.h> // Rimosso M5Unified
#include "PDCamera.h"
// #include "PowerOffButton.h" // Rimosso PowerOffButton perché dipende da M5Touch

///
static PDCamera pdCamera;
static USBSerialHost& host = USBSerialHost::GetInstance();
// static PowerOffButton offBtn; // Rimosso offBtn

///
void setup()
{
    esp_log_level_set("*", ESP_LOG_NONE);

    // auto cfg = M5.config(); // Rimosso
    // M5.begin(cfg); // Rimosso

    Serial.begin(115200); // Aggiunta inizializzazione Seriale
    // GLInitialize(GroveLog::M5StackCoreS3_PortB); // Rimosso, GroveLog potrebbe richiedere modifiche o rimozione
    // GLPrintln("== Begin pd-camera-m5 =="); // Rimosso
    Serial.println("== Begin pd-camera-xiao =="); // Aggiunto messaggio di avvio su Seriale

    // To supply power to Playdate.
    // M5.Power.setUsbOutput(true); // Rimosso/Commentato

    host.Initialize();
    pdCamera.Initialize();
}

///
void loop()
{
    // M5.update(); // Rimosso
    // offBtn.Update(); // Rimosso

    pdCamera.AppTask();
}


