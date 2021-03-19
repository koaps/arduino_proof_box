# Arduino Controlled Proofing Box

![Proofing Box](https://i.imgur.com/edXFRzXl.jpg)

*Note: the jar is sitting on a container of water as a thermal load, I wouldn't put it directly on the heat mat*

I used an [Arduino Diecimila](https://www.arduino.cc/en/Main/ArduinoBoardDiecimila) but you should be able to use any Arduino really, like an UNO or Nano.

An even better solution is using a [SparkFun Qwiic Pro Micro](https://www.sparkfun.com/products/15795) which gives you I2C over their QWIIC connector making it very easy to add a [Digital Temperature Sensor](https://www.sparkfun.com/products/16304) or an [OLED Display](https://www.sparkfun.com/products/17153) or all sorts of other stuff using [QWIIC](https://www.sparkfun.com/qwiic#products) or [Adafruit STEMMA](https://www.adafruit.com/category/1005), See [this page](https://learn.adafruit.com/introducing-adafruit-stemma-qt/sparkfun-qwiic) for more info.

This uses [Docker](https://www.docker.com/products/docker-desktop) to run [ino](http://inotool.org/) to build and upload the code to the Arduino.

I used digital pin 2 for the sensor and pin 7 for the relay

To change the Arduino hardware type, see the ino.ini file

To change the USB port, see the upload.sh also

First run the build the docker image
```
./build.sh
```

then upload code to th Arduino (it should be connected to a USB port)
```
./upload.sh
```

You can install minicom and connect to the console to see the current values of the sensor
```
minicom -D /dev/ttyUSB0 -b 9600

Welcome to minicom 2.7.1

OPTIONS: I18n
Compiled on May  6 2018, 08:02:47.
Port /dev/ttyUSB0, 00:46:48

Press CTRL-A Z for help on special keys

AM2302 Humidity - Temperature Sensor
RH              Temp (C)        Temp (F)        Heat Index (C)  Heat Index (F)  Power state
54.60 %         23.60 *C        74.48 *F        25.18 *C        77.33 *F        0
54.60 %         23.60 *C        74.48 *F        25.18 *C        77.33 *F        0
54.60 %         23.60 *C        74.48 *F        25.18 *C        77.33 *F        0
...
47.70 %         23.20 *C        73.76 *F        25.15 *C        77.26 *F        1
47.30 %         23.20 *C        73.76 *F        25.15 *C        77.27 *F        1
47.20 %         23.10 *C        73.58 *F        25.13 *C        77.23 *F        1
...
49.40 %         24.80 *C        76.64 *F        25.77 *C        78.38 *F        0
49.40 %         24.80 *C        76.64 *F        25.77 *C        78.38 *F        0
49.40 %         24.80 *C        76.64 *F        25.77 *C        78.38 *F        0
```
Tip: use `control+a`, then `z`, then `x` to exit minicom on OSX

The code will try to keep the temp between 74*F and 76*F (it will go slightly higher realistically, like 78*F), you can tweak that in the sketch.ino if you want, but should be good for bread and other ferments.

Hardware:
* [Arduino UNO](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU)
* [Iot Relay](https://www.amazon.com/Iot-Relay-Enclosed-High-Power-Raspberry/dp/B00WV7GMA2)
* [Temp Sensor](https://www.amazon.com/s?k=am2302&i=electronics)
* [Heat mat](https://www.amazon.com/certified-Seedfactor-Waterproof-Germination-Hydroponic/dp/B074753J5V)

References:
* [arduino-delivery-container](https://github.com/raft-tech/arduino-delivery-container)
* [Arduino Power – DLI IoT Power Relay](https://www.elithecomputerguy.com/2020/05/arduino-power-dli-iot-power-relay/)
* [Arduino AM2302 hookup](http://cactus.io/hookups/sensors/temperature-humidity/am2302/hookup-arduino-to-am2302-temp-humidity-sensor)
* [DHT11 DHT22 Arduino tutorial](https://www.makerguides.com/dht11-dht22-arduino-tutorial/) - has LCD code if interested in that
