unsigned long timer, timer2;
bool state;
int counter;
unsigned int maxSeen, minSeen;

unsigned int wait;

const byte SPEAKERA = 3, SPEAKERB = 4;
const byte READPIN = A1;

// lookup table that describes a sine wave
const float lookup[] = {
  0.00, 0.10, 0.20, 0.30, 0.39, 0.48, 0.56, 0.64, 0.72, 0.78, 0.84, 0.89, 0.93, 0.96, 0.99, 1.00, 1.00, 0.99, 0.97, 0.95, 0.91, 0.86, 0.81, 0.75, 0.68, 0.60, 0.52, 0.43, 0.33, 0.24, 0.14, 0.04, -0.06, -0.16, -0.26, -0.35, -0.44, -0.53, -0.61, -0.69, -0.76, -0.82, -0.87, -0.92, -0.95, -0.98, -0.99, -1.00, -1.00, -0.98, -0.96, -0.93, -0.88, -0.83, -0.77, -0.71, -0.63, -0.55, -0.46, -0.37, -0.28, -0.18, -0.08
};

void setup() {
  pinMode(READPIN, INPUT);
  pinMode(SPEAKERA, OUTPUT);
  pinMode(SPEAKERB, OUTPUT);
}

void loop() {



  if (micros() - timer >= wait) {
    state = !state;
    digitalWrite(SPEAKERA, state);
    digitalWrite(SPEAKERB, !state);
    timer = micros();
    static int count;
    count++;
    if (count == 25) {

      wait = analogRead(READPIN);

      if (wait > maxSeen) maxSeen = wait;
      if (wait < minSeen) minSeen = wait;

      wait = map(wait, minSeen, maxSeen, 10, 5000);

      //      wait = log(wait + 1) / log(5000) * 100;

      float warble = lookup[counter];

      wait += (warble * 200);
      count = 0;
    }
  }


  // used to cycle through lookup table's entries
  if (micros() - timer2 >= 2500) {
    counter++;
    if (counter == 62) counter = 0;
    timer2 = micros();
  }

}
