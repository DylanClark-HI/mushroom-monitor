# mushroom-monitor


ChatGPT Context Notes: 

The purpose of this project is to monitor and control the enviroment in a mushroom grow room. 
I have the necessary hardware to monitor the enviroment and control lights, heaters, a humidifier, and fans. 



-----------------------------------------------------------------------------------------
The hardware I am using to control and monitor the enviroment is listed here:

- Primary microcontroller: 
    FireBeetle_ESP8266_IOT_Microcontroller_SKU__DFR0489 (https://wiki.dfrobot.com/FireBeetle_ESP8266_IOT_Microcontroller_SKU__DFR0489)

- Secondary microcontroler: 
    Raspberry Pi 3 Model B+ (https://static.raspberrypi.org/files/product-briefs/Raspberry-Pi-Model-Bplus-Product-Brief.pdf)

- RTC Module: 
    Mini D1 RTC DS1307 (I cann't find a link with decent information on this exact model, please see what you can find. This is where I bought it: https://www.robotics.org.za/D1-RTC-MSD) 

    NOTE: this RTC module has a built in battery and an SD card slot. Any references in this document to either the SD card or the RTC module will refer to this module. (I'm making note of this because of the pin labels below) RTC Module and SD card are the same board.

- Temperature and Humidity Sensor (x2): 
    DHT11 (Plenty of info online about this sensor)

- LDR (Light Dependent Resistor) (x2): 
    Standard LDR. Expected average resistance of the LDR during normal opperation: 6.5kOhm (https://www.arduino.cc/en/Tutorial/LightDependentResistor)

- Shift Registers (x2): 
    74HC595 (https://www.ti.com/lit/ds/symlink/sn74hc595.pdf)

- Relay Module: 
    Relay Module 4 Channel Opto-Isolated 5V Logic (Couldn't find a decent link, please see what you can find. Here is where I bought it https://www.robotics.org.za/RELAY-4CH-5V)


-----------------------------------------------------------------------------------------


This part of the project is for the Primary microcontoller

There are frequent power outages where I live. I will use a 2 cell Lion battery shield to power the microcontroller during these outages. It holds 2x 18650 cells. It will be charged by the Raspberry Pi when the power returns. 

I am supplying the Primary microcontroller with the 5v from the battery shield. 
The secondary microcontroller will only be used when the power is on. 
The Shift Registers will be used to control the 5v to the sensors. We will then monitor the data iine for the sensors values. Only 1 sensor will be active at a time. 
We will iterate through the pins of the Shift Register, turning 1 sensor on at a time, taking a reading from the sensor, and then continuting to the next shift register pin.

Let's focus on the Primary microcontroller for now. 

The main loop should look something like this:
- Activate shift register Q1 (Starts from Q0 but we will start from Q1) 
    LATCH_PIN = 4;      // Latch pin of 74HC595 is connected to Digital pin 4
    CLOCK_PIN = 5;      // Clock pin of 74HC595 is connected to Digital pin 5
    DATA_OUT_PIN = 0;      // Data Out pin of 74HC595 is connected to Digital pin 0

- Read the data line for the sensor value
    DATA_INPUT_PIN = 13;    // Data returned from the digital sensors will be read with pin 13

- Read the Analog line for the LDR value
    LDR_PIN A0;     // LDR sensor is connected to Analog pin A0

- Get the current time from the RTC module
    Pins: 
        SDA -> D2 of RTC
        SCL -> D1 of RTC
        5v -> 5v
        3v3 -> 3v
        GND -> GND

- Log the data to the SD card
    Pins:
        MISO -> D6
        MOSI -> D7
        SCK -> D5
        IO0 (Chip select pin) -> D8 of RTC

    Data must be stored on the SD Card in this structure:

    // Structure Start //

        ---------------------------------------------------
        Sensor 1: 19-05-2022 13:45:12

        Temperature: 25.5 *C
        Humidity: 50.5 %
        Light Rating: 23.5 %
        ---------------------------------------------------
        Sensor 2: 19-05-2022 13:45:33

        Temperature: 25.5 *C
        Humidity: 50.5 %
        Light Rating: 23.5 %
        ---------------------------------------------------

    // Structure End //

    Notes:
        The sensor names will be dynamic.
        The date and time must be read and formatted before each write to the SD card.
        We will obviously use the collected data in place of the placeholder values above.

- Move on to the next pin on the Shift Register (Q2)
- Repeat until all pins have been read (Will specify this in the loop. For now we are just using 2 sets of sensors, so only Q1 and Q2 are in use)


This is as far as I have gotten...