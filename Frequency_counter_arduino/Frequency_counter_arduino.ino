//arduino Frequency counter
#define PIN_READ 2  //digitalPin that the PWM it's coming

//Var
volatile bool numReads = false; //flag to select what gonna read
volatile long unsigned int firstMeasure = 0;  //first rising of PWM
volatile long unsigned int secondMeasure = 0; //seconds rising of PWM
volatile float period = 1.0;
volatile float frequency = 0;
unsigned long time_now = 0; 
int delayms = 500;  //each delayms print the frequency on Serial

void setup() {
  pinMode(PIN_READ, INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(PIN_READ), readFrequency, RISING);
}

void loop() {
  if (millis() > time_now + delayms) {
    time_now = millis();
    frequency = 1000000 / period;
    Serial.println(frequency);
  }
}


void readFrequency() {
  if (numReads) {
    firstMeasure = micros();
  } else {
    secondMeasure = micros();
    period = (secondMeasure - firstMeasure);
  }
  numReads = !numReads;
}
