/*

  GitHub: https://github.com/neittien0110/VariableResistorController
*/

/**
 * @brief Manage an rotary variable resistor
 */
class RotaryController {
  private:
  /// @brief pin
  int AnalogPin;
  public:
  RotaryController(const int pin){
    AnalogPin = pin;
    pinMode(pin, INPUT);
  }
  int read(){
    return map(analogRead(AnalogPin), 0, 1023, 0, 255);
  } 
};

/// The pins belows are Aruidno Uno pins.
const int analogInRight1Pin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInLeft1Pin = A1;  // Analog input pin that the potentiometer is attached to
const int analogInRight2Pin = A2;  // Analog input pin that the potentiometer is attached to
const int analogInLeft2Pin = A3;  // Analog input pin that the potentiometer is attached to
const int analogInRight3Pin = A4;  // Analog input pin that the potentiometer is attached to
const int analogInLeft3Pin = A5;  // Analog input pin that the potentiometer is attached to

/// declare 6 handlers for 6 variable resistors.
RotaryController  R1(analogInRight1Pin), L1(analogInLeft1Pin), R2(analogInRight2Pin), L2(analogInLeft2Pin), R3(analogInRight3Pin), L3(analogInLeft3Pin);

void setup() {
  // initialize serial communications at 115200 bps:
  Serial.begin(115200);
}

void loop() {
  // read the analog in value:
  Serial.print(R1.read());
  Serial.print(",");
  Serial.print(L1.read());
  Serial.print(",");
  Serial.print(R2.read());
  Serial.print(",");
  Serial.print(L2.read());
  Serial.print(",");
  Serial.print(R3.read());
  Serial.print(",");
  Serial.print(L3.read());
  Serial.println();
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
