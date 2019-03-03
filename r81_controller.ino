
#include <OneWire.h>
#include <Adafruit_AM2315.h>

Adafruit_AM2315 am2315;

String testString;
OneWire  ds(10);  // on pin 10 (a 4.7K resistor is necessary)

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  testString = String();

  if (! am2315.begin()) {
    Serial.println("Sensor not found, check wiring & pullups!");
    while (1);
  }
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  Serial.print("Hum: "); Serial.println(am2315.readHumidity());
  Serial.print("Temp: "); Serial.println(am2315.readTemperature());

  printTemerature();
}
