/*
* Getting started
* Basic example to 
*  - read Device Key string and print it to Serial Monitor 
*  - send 2 random numbers as data to the cloud when the button is pressed.

* License: MIT license

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include <iomoteClass.h>

#define Serial   SerialUSB 

char buff[3750]; // max message size is 3750 bytes
char devKeyBuff[65]; // 64 bytes are used for devKey value, 1 byte for terminator char

void setup() 
{
	//	This instruction initializes the board, it's mandatory for any sketch to correctly work with the X400 Cloud Operations!
	Iomote.begin("getting started", 1,0,0);	
	
	Serial.write("X400 Getting Started!\r\n");
}


void loop() 
{
	//	Check of front button to detect the push event
	if(Iomote.buttonRead() == 0)
	{
		memset(devKeyBuff, '\0', 65);

		// Read devKey from device:
		int8_t result = Iomote.devKey(devKeyBuff);
		if(result == 0)
		{
			Serial.write("devKey: ");
			Serial.println(devKeyBuff);
		}
		else
		{
			Serial.write("Unable to send data now! Result: ");
			Serial.println(result);
		}
		memset(buff, '\0', 3750);
		//	Two random number are created and are sent to the Iot Hub
		int16_t randomData1 = rand();
		int16_t randomData2 = rand();
		time_t now = Iomote.rtc.getEpoch();
		sprintf(buff, "{\"rand_1\":%d,\"rand_2\":%d,\"ts\":%u}", randomData1, randomData2, now);

		//	With the sendData command the data is put in a queue, and wil be 
		//	sent to IoT Hub. 
		int8_t sendResult = Iomote.sendMessage(buff);
		if(sendResult == 0)
		{
			Serial.write("Data correctly enqueued and ready to be sent!\r\n");
		}
		else
		{
			Serial.write("Unable to send data now! Result: ");
			Serial.println(sendResult);
		}
		delay(1000);
	}
}
