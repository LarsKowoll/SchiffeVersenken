/**
  ******************************************************************************
  * @file    logik.c 
  * @author  <Ihre Name>
  * @date    <Datum der Probeklausur>
  * @brief   Das Modul logik implementiert das Modell / die Logik des Spiels.
  ******************************************************************************
  */
#include "logik.h"
#include "general.h"
#include "spielfeld.h"
#include <stdbool.h>

#define BOOT 				      0x01  // An der Position liegt ein Element des Boots
#define SCHUSS 			      0x02  // Auf diese Position wurde schon geschossen

#define WASSER						0x00

#define START_POS_KANONE_ZEILE   0
#define START_POS_KANONE_SPALTE  0

/**
* @brief Diese Funktion belegt das Spielfeld mit neuen Booten. Wie wird zum Start
*        eines Spiels aufgerufen.
*        Damit das Spiel leichter testbar ist, wird immer die selbe Konstellation
*        vom Booten gewählt.
*        Boot 1: Ein Boot über drei Felder an der Position 
*                (Zeile 0, Spalte 3)  (Zeile 0, Spalte 4)  (Zeile 0, Spalte 5)
*        Boot 2: Ein Boot über drei Felder an der Position 
*                (Zeile 2, Spalte 1)  (Zeile 3, Spalte 1)  (Zeile 4, Spalte 1)
*        Boot 3: Ein Boot über ein Feld an der Position 
*                (Zeile 5, Spalte 5) 
* @param None
* @retval None
*/
static void neueBoote(void){

}

/**
* @brief Diese Funktion initialisiert das Spiel.
*        Das gesamte Spielfeld wird mit Wasser belegt. Über die Funktion 
*        neueBoote wird eine neue Konfiguration von Booten eingespielt.
*        Die Kanone zielt auf die Position (START_POS_KANONE_ZEILE,START_POS_KANONE_SPALTE).
*        Das TFT Display wird entsprechend belegt.
* @param None
* @retval None
*/
void initSpiel(void) {
}

/**
* @brief Diese Funktion fuehrt einen Schuss auf die Koordinate aus, 
*        auf die die Kanone zeigt.
*        Anschliessend wird die Kanone auf eine noch nicht beschossene
*        Position ausgerichtet.
*        Das Display und der Status des Spiels werden entsprechend aktualisiert.
* @param None
* @retval None
*/
void schussKanone(void) {
	
}

/**
* @brief Diese Funktion richtet die Kanone um eine Position weiter nach links, rechts
*        oben oder unten aus. 
*        Der Rand des Spielfelds wird nicht ueberschritten. Wenn zum Beispiel 
*        die Kanone schon auf eine Position in der oberen Zeile des Spielfelds zielt
*        und richtung nach oben zeigt, hat die Funktion bewegeKanone keine Auswirkung.
* @param richtung Die Richtung, in die die Kanone bewegt wird.
* @retval None
*/
void bewegeKanone(const enum richtung r) {
 
}
// EOF
