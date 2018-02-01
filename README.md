# iomote-app-gettingstarted

## The app
The app is a X400 basic example. When use press the front panel button, the app will: 
* read Device Key string and print it to Serial Monitor 
* send 2 random numbers to the cloud.

### Before starting
Before starting you have to execute some steps to get your system ready to work with X400 and MyMote platform.
* Get an account on MyMote platform (it will be provided with your first X400 purchase).
* Install the Arduino IDE on your computer. (you can download it form www.arduino.cc Windows - Linux - Mac)


> WARNING: (for Windows users) download the installer from arduino website, not the app from the Windows store (we had problem with that version of the IDE).

Once the Arduino IDE is installed you have to add the X400 libraries:
* Go to menu File -> Preferences
* On the Additional board manager URLs, add: https://github.com/iomote/arduino-ide-bsp/raw/master/package_iomote_index.json  (use comma if there are other addresses) and confirm.
* Open the Board manager (menu Tools -> Board:xxx -> Board Manager)
* Search and install the package Arduino SAMD Boards (32.bits ARM Cortex-M0+) by Arduino
* Search and install the package Iomote X400 by Iomote
* Open the Library Manager  (menu Sketch -> Include Library -> Manage libraries)
* Install the library RTCZero by Arduino
* Select X400 from Tools -> Board:xxx -> Iomote X400

**Now the IDE is ready to create Apps for X400**.


### Usage
* Copy the .ino file inside your project (or open it with Arduino IDE)
* Verify/Compile
* Upload the file to the board

To get debug informations, open the serial monitor of the IDE.

### How it works
Once started, the app will initialize all the hardware and send application name and version to **Iomote Core** processor.
When the front panel button is pressed:
* Dev Key is requested to **Iomote Core** processor, and printed to Serial Monitor
* Random data is prepared and sent to **Iomote Core** device to cloud messages queue
