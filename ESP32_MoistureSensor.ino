#define Moisture_Sensor 34
int dryValue = 4095;      // calibration of moisture sensor (in air)
int wetValue = 1500;      // calibration of moisture sensor (in water)
void setup() {
Serial.brgin(115200);
}
void loop() {
int moistureValue = analogRead(MOISTURE_PIN);
  int moisturePercent = map(moistureValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  String soilType;
  if (moisturePercent < 15) {
    soilType = "Very Dry";
  } else if (moisturePercent < 35) {
    soilType = "Dry";
  } else if (moisturePercent < 60) {
    soilType = "Moist";
  } else if (moisturePercent < 85) {
    soilType = "Wet";
  } else {
    soilType = "Very Wet";
  }
  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("% --> ");
  Serial.println(soilType);

  Serial.println(moistureValue);

  Serial.println("----------------------------------------");
}