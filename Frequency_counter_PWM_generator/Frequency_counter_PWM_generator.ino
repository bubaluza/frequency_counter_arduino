//ESP32 PWM generator
#define PIN_PWM 32

void setup() {
  Serial.begin(115200);
  pinMode(PIN_PWM, OUTPUT);
  ledcAttachPin(PIN_PWM, 0);
  ledcSetup(0, 1, 10);
  ledcWrite(0, 512);
}

void loop() {
  if(Serial.available())
  while(Serial.available()>0){ //when got something to read
    int pwm = Serial.parseInt();
    ledcSetup(0, pwm, 10);
    ledcWrite(0, 512);
    Serial.print("generating pwm with ");
    Serial.print(pwm);
    Serial.println(" Hz");
  }
}
