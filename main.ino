#include <Arduino.h>

#include "anim_test.h"
#include "anim_start.h"
#include "anim_run.h"
#include "palette.h"

#define ANIMS 2 //number of animations
#define PALS 6 //number of palettes
#define INTERVAL 10000 //change interval, msec

Anim * anims[ANIMS];
Palette * pals[PALS] = {&PalRgb, &PalRainbow, &PalRainbowStripe, &PalParty, &PalHeat, &PalFire};

Anim * curAnim;

unsigned long ms = INTERVAL;
int period = 20;
int paletteInd = random(PALS);

void setup() {
  Serial.begin(9600);

  anims[0] = new AnimRun();
  anims[1] = new AnimRun();

  curAnim = anims[0];
  curAnim->setPeriod(period);
  curAnim->setPalette(pals[0]);
}

void loop() {
  if (millis() > ms) {
    ms = millis() + INTERVAL;
    switch (random(3)) {
      case 0: 
        curAnim = anims[random(1,ANIMS)];
        curAnim->setPeriod(period);
        curAnim->setPalette(pals[paletteInd]);
        break;
      case 1:
        period = random(5,50);
        curAnim->setPeriod(period);
        break;
      case 2:
        paletteInd = random(PALS);
        curAnim->setPalette(pals[paletteInd]);
        break;
    }
    

  }
  curAnim->run();
}
