/*
   Spooky Sounds: a warbling theremin ghoul for a very IDeATe/MakerWing Halloween

   An analog sensor input (we're using an IR proxmity sensor) modulates the
   central frequency around which a tone warbles. It's spoooooky sounding!

   As a hand...or a skull!...gets closer to the IR proximity sensor, the ghoul
   sings higher and higher. Don't listen for too long or it might steal your soul.

   Designed to be run on an ATTiny85.

   Pin mapping:
      analog sensor: Arduino pin 2 (ATTiny hardware pin 7)
      piezo transducer: one leg each on Arduino pins 3 and 4
          (which are ATTiny hardware pins 2 and 3)

   released to the public domain by the author
   Robert Zacharias, rzach@cmu.edu
   Oct. 31, 2018
*/

const byte READPIN = A1;
const byte SPEAKERA = 3, SPEAKERB = 4;

unsigned long timer, timer2;
bool state;
int warbleCounter;
unsigned int maxSeen, minSeen;
unsigned int wait;

// lookup table that describes a sine wave from -1 to 1
const float lookup[] = {
  0.00, 0.10, 0.20, 0.30, 0.39, 0.48, 0.56, 0.64, 0.72, 0.78, 0.84, 0.89, 0.93, 0.96, 0.99, 1.00, 1.00, 0.99, 0.97, 0.95, 0.91, 0.86, 0.81, 0.75, 0.68, 0.60, 0.52, 0.43, 0.33, 0.24, 0.14, 0.04, -0.06, -0.16, -0.26, -0.35, -0.44, -0.53, -0.61, -0.69, -0.76, -0.82, -0.87, -0.92, -0.95, -0.98, -0.99, -1.00, -1.00, -0.98, -0.96, -0.93, -0.88, -0.83, -0.77, -0.71, -0.63, -0.55, -0.46, -0.37, -0.28, -0.18, -0.08
};

void setup() {
  pinMode(READPIN, INPUT);
  pinMode(SPEAKERA, OUTPUT);
  pinMode(SPEAKERB, OUTPUT);
}

void loop() {
  /*
     if one period (defined by wait) has passed:
      1) flip the speaker outputs
      2) and every 25th time, update the analogRead, then
         calculate the new wait
  */
  if (micros() - timer >= wait) {
    state = !state;
    digitalWrite(SPEAKERA, state);
    digitalWrite(SPEAKERB, !state);
    timer = micros();
    static int count;
    count++;

    if (count == 25) {

      wait = analogRead(READPIN);

      // update max and min appropriately based on observations
      if (wait > maxSeen) maxSeen = wait;
      if (wait < minSeen) minSeen = wait;

      // output's wave has a period of 10 to 2000 microseconds
      wait = map(wait, minSeen, maxSeen, 10, 2000);

      float warble = lookup[warbleCounter];

      wait += (warble * 100);
      count = 0;
    }
  }


  /*
     Every 2500 microseconds advance the warbler one step through
     its lookup table
  */
  if (micros() - timer2 >= 2500) {
    warbleCounter++;
    if (warbleCounter == 62) warbleCounter = 0;
    timer2 = micros();
  }
}
