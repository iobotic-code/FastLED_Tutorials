/* ¡Nos encanta desarrollar! IOBOTIC invierte tiempo y recursos para 
 *  propocionar este código abierto. La idea es seguir desarrollando 
 *  y compartir el conocimiento con todas las personas que aman la
 *  electrónica, la robótica y la tecnología.
 *  
 *  Por favor apoya a iobotic y al "Open-Source"
 *  TINDIE: http://bit.ly/2OVVR2N
 *  HACKADAY: https://hackaday.io/IOBOTIC
 *  Copyright (C) <2020> <Hugo Oroño>
 *  Este programa es software libre: usted puede redistribuirlo y / o modificarlo
 *  bajo los términos de la Licencia Pública General de GNU según lo publicado por
 *  la Free Software Foundation, en la versión 3 de la Licencia, o cualquier versión posterior.
 *  
 *  Escrito por Hugo Oroño para iobotic - 01/28/2020 
 *  Todo este texto debe ser incluido en su redistribución*/
 
// Paso #1: Importamos la librería FastLED
#include <FastLED.h>

// Paso #2: Definimos el número de LEDs y el Pin a utilizar
#define NUM_LEDS 100 
#define DATA_PIN 9 // Arduino Uno

// Paso opcional: Definir la intensidad del brillo
#define BRIGHTNESS  30

// Paso #3: Definimos el espacio de memoria donde guardaremos una Matriz LED que podamos manipular
CRGB leds[NUM_LEDS];

void setup() {
// Paso #4: Configuramos todos los LEDs
FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);

// Paso opcional: Configurar la intensidad del brillo
FastLED.setBrightness(BRIGHTNESS);

// Paso opcional: Apagado Preventivo y espera de carga segura
blackout();
delay(500);
}

//##################################################
//##################################################
// Paso #5: ¯\_(ツ)_/¯
void loop() {
  rainbow();
  delay(500);
}
//##################################################
//##################################################

// Esta función escribe/enciende un LEDs
void oneDot()
{
 leds[0] = 0x0000EE; // Blue
 leds[1] = 0x0000EE; // Blue
 leds[2] = 0x0000EE; // Blue
 FastLED.show();
 delay(30);
  }

// Esta función escribe/enciende los LEDs en secuencia
void dotsMoving()
{
  int t = 1;
  for(int dot = 0; dot <= NUM_LEDS; dot++)
  {
   leds[dot] = 0x565AEC;
   FastLED.show();
   delay(t);
   // Clear
   leds[dot] = CRGB::Black;
   delay(t); 
   t += 1;
    }
  }

//
void rainbow()
{
  fill_rainbow(leds,NUM_LEDS,0,2);
  FastLED.setBrightness(10);
  FastLED.show();
  delay(1000);
  }

// Esta función apaga todos los LEDs
void blackout()
{
  for(int dot = 0; dot <= NUM_LEDS; dot++)
  {
    leds[dot] = 0x000000;
    FastLED.show();
    delay(30);
    }
  }
