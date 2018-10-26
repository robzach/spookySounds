/*
 * Spooky Sounds: a warbling theremin ghoul for a very IDeATe/MakerWing Halloween
 * 
 * An analog sensor input (we're using an IR proxmity sensor) modulates the
 * central frequency around which a tone warbles. It's spoooooky sounding!
 * 
 * As a hand...or a skull!...gets closer to the IR proximity sensor, the ghoul
 * sings higher and higher. Don't listen for too long or it might steal your soul.
 * 
 * Pin mapping:
 *    analog sensor: pin XXXXXXXXXXXXXXXX
 *    speaker: pin 0
 * 
 * released to the public domain by the author
 * Robert Zacharias, rzach@cmu.edu
 * Oct. 23, 2018
 */

const int SENSORPIN = A1;
const int SPEAKERPIN = 4;

// lookup table that describes a sine wave
const float lookup[] = {
  0.00, 0.10, 0.20, 0.30, 0.39, 0.48, 0.56, 0.64, 0.72, 0.78, 0.84, 0.89, 0.93, 0.96, 0.99, 1.00, 1.00, 0.99, 0.97, 0.95, 0.91, 0.86, 0.81, 0.75, 0.68, 0.60, 0.52, 0.43, 0.33, 0.24, 0.14, 0.04, -0.06, -0.16, -0.26, -0.35, -0.44, -0.53, -0.61, -0.69, -0.76, -0.82, -0.87, -0.92, -0.95, -0.98, -0.99, -1.00, -1.00, -0.98, -0.96, -0.93, -0.88, -0.83, -0.77, -0.71, -0.63, -0.55, -0.46, -0.37, -0.28, -0.18, -0.08
};

int counter;

void setup() {
  pinMode(SENSORPIN, INPUT);
  pinMode(SPEAKERPIN, OUTPUT);
}

void loop() {
  int readVal = analogRead(SENSORPIN);
  
  // all four map() constants can be modified based on the sensor input range
  // and desired sound output range. These values for LTH1550-01 IR rangefinder.
  int base = map(readVal, 0, 75, 100, 2000);

  // much faster to look up, rather than compute, the sine wave
  float wave = lookup[counter]; 

  // the width of the warble, in Hz
  int multiplier = 50;
  
  int speakerval = base + (multiplier * wave);
  
  tone(SPEAKERPIN, speakerval);

  // used to cycle through lookup table's entries
  counter++;
  if (counter == 62) counter = 0;

  // change this value to affect the speed of the warble (lower delay->faster)
  delayMicroseconds(1500);
}
