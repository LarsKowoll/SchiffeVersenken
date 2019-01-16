/**
  ******************************************************************************
  * @file    spielfeld.c 
  * @author  <Ihre Name>
  * @date    <Datum der Probeklausur>
  * @brief   Diese Datei gehört zur GS Probeklausur WS 2018-19 SchiffeVersenken
	*          Dieses Modul implementiert die Darstellung des 
	*          Spielfelds auf dem TFT Displays.
	*          Das linke obere Feld (ohne Rand) des Spielfelds hat die 
	*          Koordinaten (0,0).
  ******************************************************************************
  */
#include "spielfeld.h"
#include "general.h"
#include "tft.h"

#define WASSER                           ' '
#define TREFFER_BOOT                     '*'  // Farbe rot      
#define TREFFER_WASSER					         '+'  // Farbe weiss
#define ZIEL_KANONE                      '0'  // Farbe gelb
#define RAHMEN													 'X'  // Farbe weiss

#define MAX_ANZAHL_SPALTEN 40
#define MAX_ANZAHL_ZEILEN  15
#define START_SPALTE		((MAX_ANZAHL_SPALTEN - (ANZ_SPALTEN_SPIELFELD + 2))/2)
#define START_ZEILE			((MAX_ANZAHL_ZEILEN  - (ANZ_ZEILEN_SPIELFELD  + 2))/2)

/**
* @brief Diese Funktion druckt an der Position zeile, spalte ein Zeichen auf dem 
*        Spielfeld.
* @param zeile  Zeilenposition auf dem Spielfeld
* @param spalte Spaltenposition auf dem Spielfeld
* @param c Das zu druckende Zeichen
* @param color Farbe des zu druckenden Zeichens
* @retval none
*/

static void printChar(const unsigned char zeile, const unsigned char spalte, const char c, const int color) {
	 if ((zeile < ANZ_ZEILEN_SPIELFELD) || (spalte < ANZ_SPALTEN_SPIELFELD)) {
		  // im gueltigen Bereich
		  TFT_set_font_color(color);
		  TFT_gotoxy(spalte+2, zeile+2); // 1 für den Rand und 1 weil TFT bei (1,1) startet
	    TFT_putc(c); 
   }
}

/**
* @brief Diese Funktion druckt auf dem Spielfeld an der Position zeile, spalte
*        die Darstellung von Wasser - ein Leerzeichen.
* @param zeile Zeilenposition
* @param spalte Spaltenposition 
* @retval none
*/
void printWasser(const unsigned char zeile, const unsigned char spalte){
	printChar(zeile,spalte,WASSER,WHITE);
}

/**
* @brief Diese Funktion druckt auf dem Spielfeld an der Position zeile, spalte
*        die Darstellung eines Treffers eines Bootselements - ein roter *.
* @param zeile Zeilenposition
* @param spalte Spaltenposition
* @retval none
*/
void printTrefferBoot(const unsigned char zeile, const unsigned char spalte){
	printChar(zeile,spalte,TREFFER_BOOT,RED);
}

/**
* @brief Diese Funktion druckt auf dem Spielfeld an der Position zeile, spalte
*        die Darstellung eines Schluss ins Wasser - ein weisses +.
* @param zeile Zeilenposition
* @param spalte Spaltenposition
* @retval none
*/
void printTrefferWasser(const unsigned char zeile, const unsigned char spalte){
	printChar(zeile,spalte,TREFFER_WASSER,WHITE);
}

/**
* @brief Diese Funktion druckt auf dem Spielfeld an der Position zeile, spalte
*        die Darstellung, dass die Kanone auf dieses Feld zielt - ein gelbes O.
* @param zeile Zeilenposition
* @param spalte Spaltenposition
* @retval none
*/
void printPositionKanone(const unsigned char zeile, const unsigned char spalte){
	printChar(zeile,spalte,ZIEL_KANONE,YELLOW);
}

/**
* @brief Diese Funktion initialisiert das TFT Display und das Spielfeld.
*        Das Spielfeld ist ein Window mit dem Font FONT6x8.
*        Der Curser wird ausgeschaltet.
*        Das Spielfelds wird mit weissen X umrandet. Das ganze Spielfeld wird 
*        mit der Darstellung von Wasser gefüllt.
* @param none
* @retval none
*/
void initSpielfeld(void){
	 TFT_Init();
	 TFT_cls();
	 TFT_set_window(FONT6x8, START_SPALTE, START_ZEILE, ANZ_SPALTEN_SPIELFELD+2, ANZ_ZEILEN_SPIELFELD+2);	
	 TFT_cursor_off();
	 // Zeichne Rand
	 TFT_set_font_color(WHITE);	 
	 for (int zeile = 1; zeile <= ANZ_ZEILEN_SPIELFELD + 2; zeile++) { 
	    for (int spalte = 1; spalte <= ANZ_SPALTEN_SPIELFELD + 2; spalte++) {
          if ((zeile == 1) || (spalte == 1) || 
						  (zeile == ANZ_ZEILEN_SPIELFELD + 2) || (spalte == ANZ_SPALTEN_SPIELFELD + 2)) {
						 TFT_gotoxy(zeile,spalte);		
	           TFT_putc(RAHMEN);
					}
	    }
	 }
}
// EOF
