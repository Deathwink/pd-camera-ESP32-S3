#include "Common.h"
#include <Arduino.h> // Assicura che Arduino.h sia incluso per LED_BUILTIN, pinMode, digitalWrite, millis
// #include <M5Unified.h> // Rimosso M5Unified
#include "PDCamera.h"
// #include "PowerOffButton.h" // Rimosso PowerOffButton perché dipende da M5Touch

///
static PDCamera pdCamera;
static USBSerialHost& host = USBSerialHost::GetInstance();
// static PowerOffButton offBtn; // Rimosso offBtn

// Variabili per il controllo del LED utente
static unsigned long pdCameraInitializedTime = 0;
static bool userLedTurnedOff = false;
const int userLedPin = LED_BUILTIN; // Pin del LED utente

///
void setup()
{
    esp_log_level_set("*", ESP_LOG_NONE);

    pinMode(userLedPin, OUTPUT);      // Configura il pin del LED come output
    digitalWrite(userLedPin, LOW);    // Accende il LED utente (LOW per accendere)

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
    // Registra il tempo dopo l'inizializzazione di pdCamera
    // Si potrebbe aggiungere un controllo sul successo di pdCamera.Initialize() se restituisse un booleano
    pdCameraInitializedTime = millis(); 
}

///
void loop()
{
    // M5.update(); // Rimosso
    // offBtn.Update(); // Rimosso

    // Logica per spegnere il LED utente dopo 10 secondi
    if (pdCameraInitializedTime > 0 && !userLedTurnedOff) {
        if (millis() - pdCameraInitializedTime >= 10000) {
            digitalWrite(userLedPin, HIGH); // Spegne il LED utente (HIGH per spegnere)
            userLedTurnedOff = true;
            Serial.println("User LED turned off after 10 seconds.");
        }
    }

    pdCamera.AppTask();
}


