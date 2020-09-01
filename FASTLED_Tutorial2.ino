/* ¡Nos encanta desarrollar! IOBOTIC invierte tiempo y recursos para 
 *  propocionar este código abierto. La idea es seguir desarrollando 
 *  y compartir el conocimiento con todas las personas que aman la
 *  electrónica, la robótica y la tecnología.
 *  
 *  Por favor apoya a iobotic y al "Open-Source"
 *  TINDIE: http://bit.ly/2OVVR2N
 *  HACKADAY: https://hackaday.io/IOBOTIC
 *  
 *  Copyright (C) <2020> <Hugo Oroño>
 *  Este programa es software libre: usted puede redistribuirlo y / o modificarlo
 *  bajo los términos de la Licencia Pública General de GNU según lo publicado por
 *  la Free Software Foundation, en la versión 3 de la Licencia, o cualquier versión posterior.
 *  
 *  Escrito por Hugo Oroño para iobotic - 01/28/2020 
 *  Todo este texto debe ser incluido en su redistribución*/

/// Paso #1: Configuración
#include <FastLED.h>

#define NUM_LEDS 100 
#define DATA_PIN 9 // Arduino Uno
#define BRIGHTNESS  30
#define COLOR_ORDER GRB // Green - Red - Blue

CRGB leds[NUM_LEDS];



void setup() {
// Paso #2: Configuramos todos los LEDs
FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
FastLED.setBrightness(BRIGHTNESS);
// Paso 3: Apagado preventivo
blackOut();
delay(1000);

}

void loop() {
  //setRGB();
  //fillOut(500);
  //dFill(20,4);
  //fadeMoving(10,10);
  //glitch();
  colorRain();
  //gradient(500);
  //lightUp(10,10);
}
//##################################################
//##################################################
// ...(▀̿Ĺ̯▀̿ ̿)...Funciones!

//Configuración de colores, -> COLOR_ORDER
void setRGB()
{
  /*Encenderemos 6 LEDs, si el orden de RGB es correcto, deberíamos ver
  1 LED Rojo, 2 LEDs Verdes y 3 LEDs Azules. ~ Si el orden no es correcto*/
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Green;
    leds[2] = CRGB::Green;
    leds[3] = CRGB::Blue;
    leds[4] = CRGB::Blue;
    leds[5] = CRGB::Blue;
    leds[6] = CRGB(0,0,0);
    FastLED.show();
    delay(1000);
  }

/*Encender toda la Matriz sin retraso*/
void fillOut(int t)
{
 //Red
 for(int x = 0; x <= NUM_LEDS; x++)
 {
  leds[x] = 0xFF4040; //RoseRed
  }
  FastLED.show();
  delay(t);

 //Green
 for(int x = 0; x <= NUM_LEDS; x++)
 {
  leds[x] = 0x00FF7F; //SpringGreen
  }
  FastLED.show();
  delay(t);

 //Blue
 for(int x = 0; x <= NUM_LEDS; x++)
 {
  leds[x] = 0x4876FF; //RoyalBlue
  }
  FastLED.show();
  delay(t);
  }

/*Enciende la Matriz con un retraso 't' y un fade 'f'
Valores sugeridos t = 20; f = 4*/
void dFill(int timing, int fade)
{
  for(int d = 0; d <= NUM_LEDS; d++)
  {
    leds[d] = 0x458B74; //aquamarine4
    FastLED.show();
    delay(timing);
    fadeToBlackBy(leds,NUM_LEDS,fade);
    }
  }

/*Desplaza un LED con degradado en la Matriz, valores sugeridos v = 10, f = 10*/
void fadeMoving(int v, int f)
{
  for(int m = 0; m <= NUM_LEDS; m++)
  {
    leds[m] = 0xFF4040; //RoseRed
    FastLED.show();
    fadeToBlackBy(leds,NUM_LEDS,f);
    //leds[m] = CRGB::Black; // Desplazamiento tradicional
    delay(v);
    }

  for(int m = 99; m >= 0; m--)
  {
    leds[m] = 0x6959CD; //SlateBlue3
    FastLED.show();
    fadeToBlackBy(leds,NUM_LEDS,f/2); //fade/2 
    //leds[m] = CRGB::Black; // Desplazamiento tradicional
    delay(v);
    } 
  } 

/*Genera una destello aleatorio ~ función de complemento*/
void glitch()
{
  leds[random(0,NUM_LEDS)] = CRGB::White;
  delay(10); 
  FastLED.show();
  blackOut();
  }

/*Genera destellos de colores en posiciones aleatorias con devanecimiento*/
void colorRain()
{
  fadeToBlackBy(leds,NUM_LEDS,5);
  int pos = random16(NUM_LEDS); // Guarda una posición aleatoria
  leds[pos] += CRGB(random(255),100,random(255)); // Escribe el LED guardado con un color aleatorio
  FastLED.show(); 
  }

/*Genera un degradado entre 2 colores*/
void gradient(int c)
{
  fill_gradient_RGB (leds,  0, CRGB::Blue, 99, CRGB::Red); //leds, initPos,initColor,endPost,endColor
  FastLED.show();
  delay(c);
  fill_gradient_RGB (leds,  0, 0xFF4040, 99, 0xFF7F24);
  FastLED.show();
  delay(c);
  fill_gradient_RGB (leds,  0, 0x2F4F4F, 99, CRGB::White);
  FastLED.show();
  delay(c);
  fill_gradient_RGB (leds,  0, 0xFF1493, 99, 0x2F4F4F);
  FastLED.show();
  delay(c);
  fill_gradient_RGB (leds,  0,0x9F79EE, 99, 0xEECFA1);
  FastLED.show();
  delay(c);
  fill_gradient_RGB (leds,  0,0xFFC125, 99, 0x8B8682);
  FastLED.show();
  delay(c);
  }

/*Desplaza un LED con degradado claro en la Matriz, valores sugeridos v = 10, f = 10*/
void lightUp(int timing, int light)
{
  int8_t hue = 0;
  for(int l = 0; l <= NUM_LEDS; l++)
  {
    leds[l] = CRGB(10,hue,200);//0x8B8B00+hue;
    FastLED.show();
    fadeLightBy (leds, NUM_LEDS, light); //leds, NUM_LEDS, factor_Amount
    //fadeToBlackBy (leds, NUM_LEDS, light);
    delay(timing);
    hue+=3;
    }
  }
   
void blackOut()
  {
    for(int f = 0; f <= NUM_LEDS; f++)
    {
      leds[f] = 0x000000;
      }
      FastLED.show();
  }
