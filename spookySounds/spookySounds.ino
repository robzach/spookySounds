unsigned long timer, timer2;
bool state;
int counter;

const byte SPEAKERA = 3, SPEAKERB = 4;

// lookup table that describes a sine wave
const float lookup[40] = {
  1.0,
  1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.1,
  1.09, 1.08, 1.07, 1.06, 1.05, 1.04, 1.03, 1.02, 1.01, 1.0,
  0.99, 0.98, 0.97, 0.96, 0.95, 0.94, 0.93, 0.92, 0.91, 0.9,
  0.91, 0.92, 0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99
};

void setup() {
  // put your setup code here, to run once:
  pinMode(SPEAKERA, OUTPUT);
  pinMode(SPEAKERB, OUTPUT);
}

void loop() {

  unsigned int wait = analogRead(A1);
  wait = map(wait, 0, 150, 10000, 500); // period of 10000->500 microseconds

  float warble = lookup[counter];

  wait *= warble;

  if (micros() - timer >= wait) {
    state = !state;
    digitalWrite(SPEAKERA, state);
    digitalWrite(SPEAKERB, !state);
    timer = micros();
  }

  // used to cycle through lookup table's entries
  if (micros() - timer2 >= 50) {
    counter++;
    if (counter == 40) counter = 0;
    timer2 = micros();
  }
}
