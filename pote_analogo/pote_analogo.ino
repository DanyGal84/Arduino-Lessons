void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int read_value = analogRead(A0);
  int adapted_value = map(read_value, 0, 1023, 0, 255);
  analogWrite(3, adapted_value);
  Serial.println("Adapted value is: " + String(adapted_value));
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
