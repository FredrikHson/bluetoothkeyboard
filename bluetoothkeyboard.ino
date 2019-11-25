#include <bluefruit.h>
#include "keyconfig.h"

/*#define SDEBUG 1*/

BLEDis bledis;
BLEHidAdafruit blehid;

int numpressedatonce = 0;
int keymode = 0;
hid_keyboard_report_t report;

void set_keyboard_led(uint16_t conn_handle, uint8_t led_bitmap);
void startAdv(void);

void setupPins()
{
    for(int i = 0; i  < NUMKEYS; i ++)
    {
        pinMode(pins[i], INPUT);
    }
}
void setupMode()
{
    for(int i = 0; i  < NUMMODES; i ++)
    {
        if(digitalRead(pins[i]) == LOW)
        {
            keymode = i;
            return;
        }
    }
}

void setup()
{
    setupPins();
    setupMode();
    #ifdef SDEBUG
    Serial.begin(115200);

    while(!Serial)
    {
        delay(10);    // for nrf52840 with native usb
    }

    #endif
    Bluefruit.begin();
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Bluefruit52");
    // Configure and Start Device Information Service
    bledis.setManufacturer("Adafruit Industries");
    bledis.setModel("Bluefruit Feather 52");
    bledis.begin();
    /* Start BLE HID
     * Note: Apple requires BLE device must have min connection interval >= 20m
     * ( The smaller the connection interval the faster we could send data).
     * However for HID and MIDI device, Apple could accept min connection interval
     * up to 11.25 ms. Therefore BLEHidAdafruit::begin() will try to set the min and max
     * connection interval to 11.25  ms and 15 ms respectively for best performance.
     */
    blehid.begin();
    // Set callback for set LED from central
    blehid.setKeyboardLedCallback(set_keyboard_led);
    /* Set connection interval (min, max) to your perferred value.
     * Note: It is already set by BLEHidAdafruit::begin() to 11.25ms - 15ms
     * min = 9*1.25=11.25 ms, max = 12*1.25= 15 ms
     */
    /* Bluefruit.Periph.setConnInterval(9, 12); */
    // Set up and start advertising
    startAdv();
}

void startAdv(void)
{
    // Advertising packet
    Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
    Bluefruit.Advertising.addTxPower();
    Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
    // Include BLE HID service
    Bluefruit.Advertising.addService(blehid);
    // There is enough room for the dev name in the advertising packet
    Bluefruit.Advertising.addName();
    /* Start Advertising
     * - Enable auto advertising if disconnected
     * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
     * - Timeout for fast mode is 30 seconds
     * - Start(timeout) with timeout = 0 will advertise forever (until connected)
     *
     * For recommended advertising interval
     * https://developer.apple.com/library/content/qa/qa1931/_index.html
     */
    Bluefruit.Advertising.restartOnDisconnect(true);
    Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
    Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
    Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
    Bluefruit.autoConnLed(false);
}
void keyPress(key& k)
{
    for(int i = 0; i  < 6; i ++)
    {
        if(report.keycode[i] == 0)
        {
            //report.modifier |= k.modifier;
            report.keycode[i] = k.scancode;
            break;
        }
    }
}

void keyRelease(key& k)
{
    for(int i = 0; i  < 6; i ++)
    {
        if(report.keycode[i] == k.scancode)
        {
            report.keycode[i] = 0;
        }
    }
}

void sendReport()
{
    #ifdef SDEBUG
    char buf[256] = {0};
    sprintf(buf, "sending report %i %i %i %i %i %i",
            report.keycode[0],
            report.keycode[1],
            report.keycode[2],
            report.keycode[3],
            report.keycode[4],
            report.keycode[5]);
    Serial.println(buf);
    #endif
    blehid.keyboardReport(&report);
}


bool keystates[NUMKEYS] = {0};
void loop()
{
    for(int i = 0; i  < NUMKEYS; i ++)
    {
        bool pressed = digitalRead(pins[i]);

        if(pressed != keystates[i]) // send only on changed state
        {
            keystates[i] = pressed;

            for(int j = 0; j  < 4; j++)
            {
                key& k = keys[keymode].keys[i][j];

                if(k.scancode != 0)
                {
                    if(pressed == true)
                    {
                        keyRelease(k);
                        #ifdef SDEBUG
                        char buf[32] = {0};
                        sprintf(buf, "keyrelease %i %i %i", i, (int)k.scancode, pressed);
                        Serial.println(buf);
                        #endif
                    }
                    else
                    {
                        keyPress(k);
                        #ifdef SDEBUG
                        char buf[32] = {0};
                        sprintf(buf, "keypress %i  %i %i", i, (int)k.scancode, pressed);
                        Serial.println(buf);
                        #endif
                    }
                }
            }

            sendReport();
        }
    }

    delay(150);
}

/**
 * Callback invoked when received Set LED from central.
 * Must be set previously with setKeyboardLedCallback()
 *
 * The LED bit map is as follows: (also defined by KEYBOARD_LED_* )
 *    Kana (4) | Compose (3) | ScrollLock (2) | CapsLock (1) | Numlock (0)
 */
void set_keyboard_led(uint16_t conn_handle, uint8_t led_bitmap)
{
    (void) conn_handle;
    // light up Red Led if any bits is set
    /*if(led_bitmap)*/
    /*{*/
    /*ledOn(LED_RED);*/
    /*}*/
    /*else*/
    /*{*/
    /*ledOff(LED_RED);*/
    /*}*/
}
