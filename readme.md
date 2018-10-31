# Spooooky sounds—a ghoulish singer for a very scary IDeATe/MakerWing Halloween

## Schematic image:

![schematic image from Fritzing](https://github.com/robzach/spookySounds/blob/master/spookyWiring/spookyWiring_bb.jpg?raw=true)

(image from spookyWiring folder in this repo)

## Wiring and software overview (quoted from the block comment at the top of spookySounds.ino)

Spooky Sounds: a warbling theremin ghoul for a very IDeATe/MakerWing Halloween

An analog sensor input (we're using an IR proxmity sensor) modulates the central frequency around which a tone warbles. It's spoooooky sounding!

As a hand…or a skull!…gets closer to the IR proximity sensor, the ghoul sings higher and higher. Don't listen for too long or it might steal your soul.

Designed to be run on an ATTiny85.

Pin mapping:
  * analog sensor: Arduino pin 2, equivalent to A1 (ATTiny hardware pin 7)
  * piezo transducer: one leg each on Arduino pins 3 and 4 (which are ATTiny hardware pins 2 and 3)

## Project bill of materials (BOM):

number needed | item  | line cost | purchase link
--- | --- | --- | ---
1 | ATTiny85 | $1.03 | https://www.digikey.com/product-detail/en/microchip-technology/ATTINY85-20PU/ATTINY85-20PU-ND/735469
1 | 220Ω resistor | $0.0258 | https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-220R/220QBK-ND/1295
1 | 22KΩ resistor | $0.0258 | https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-22K/22KQBK-ND/1306
5 | male-male jumpers | $0.10 | https://www.aliexpress.com/item/40pcs-dupont-cable-jumper-wire-dupont-line-Male-to-Male-dupont-line-20cm-1P-40P-free/32540324209.html
1 | small breadboard | $0.396 | https://www.aliexpress.com/item/5PCS-SYB-170-5-Colors-Mini-Solderless-Breadboard-Prototype-Experiment-Test-Protoboard-170-Tie-Points-For/32671297865.html
1 | LTH1550-01 IR proximity sensor | $0.29 | https://www.jameco.com/z/LTH-1550-01-Lite-On-Electronics-Reflective-Photointerrupters-NPN-Phototransistor_2202378.html
1 | CR2032 lithium battery | $0.156 | https://www.arrow.com/en/products/cr2032/panasonic
1 | piezo transducer | $0.5275 | https://www.amazon.com/Luvay-12Pcs-Pickup-Transducer-Prewired/dp/B0775V78D1
