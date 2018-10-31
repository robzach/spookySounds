unsigned long timer, timer2;
bool state;
int counter;
unsigned int maxSeen, minSeen;

const byte SPEAKERA = 3, SPEAKERB = 4;
const byte READPIN = A1;

// lookup table that describes a linear scale from 100->110->90->99%
const float lookup[40] = {
  1.0,
  1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.1,
  1.09, 1.08, 1.07, 1.06, 1.05, 1.04, 1.03, 1.02, 1.01, 1.0,
  0.99, 0.98, 0.97, 0.96, 0.95, 0.94, 0.93, 0.92, 0.91, 0.9,
  0.91, 0.92, 0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99
};

void setup() {
  Serial.begin(9600);
  pinMode(READPIN, INPUT);
  pinMode(SPEAKERA, OUTPUT);
  pinMode(SPEAKERB, OUTPUT);
}

void loop() {

  unsigned int wait = analogRead(READPIN);

  if (wait > maxSeen) maxSeen = wait;
  if (wait < minSeen) minSeen = wait;

  wait = map(wait, minSeen, maxSeen, 250, 5000);

  float warble = lookup[counter];

  wait *= warble;

  if (micros() - timer >= wait) {
    state = !state;
    digitalWrite(SPEAKERA, state);
    digitalWrite(SPEAKERB, !state);
    timer = micros();
  }

  // used to cycle through lookup table's entries
  if (micros() - timer2 >= 50000) {
    Serial.println(wait);

    //    counter++;
    //    if (counter == 40) counter = 0;
    timer2 = micros();
  }
}
