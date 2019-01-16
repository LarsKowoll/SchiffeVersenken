/**
  ******************************************************************************
  * @file    hal.c 
  * @author  <Ihre Name>
  * @date    <Datum der Probeklausur>
  * @brief   Diese Datei gehört zur GS Probeklausur WS 2018-19 SchiffeVersenken
	*          Dieses Modul kapselt den Zugriff auf die Hardware.
  ******************************************************************************
  */

#include "hal.h"
#include <stdint.h>
#include <stdbool.h>
#include "TI_memory_map.h"
#include "mytimer.h"

// Der Zugriff auf die Schalter ist softwaremässig entprellt.
// Ein Taster prellt maximal DELTA_PRELLEN us
// Wenn ein Schalter prellt, werden maximal ANZAHL_LESEVERSUCHE_PRELLEN 
// Zugriffe auf den Schalter durchgefuehrt.

#define DELTA_PRELLEN   							20 // us
#define ANZAHL_LESEVERSUCHE_PRELLEN		5

#define MAX_TASTER										7  // Groesster Pin, an dem ein Taster angeschlossen ist.

#define	LOWER_BYTE_MASK								0x00FF
#define SHIFT_TO_UPPER_BYTE						8

/**
* @brief Diese Funktion fuehrt die Initialisierung der Hardware durch, die von den
*        in Init_TI_Board() umgesetzten Standardeinstellungen abweicht.
* @param None
* @retval None
*/
void initHal(void) {
}
 
/**
* @brief Diese Funktion setzt die oberen 8 an Port G angeschlossenen LEDs
*        gemaess dem in v uebergebenen Wert.
* @param v Wert, der binaer auf den LEDs ausgegeben wird.
* @retval None
*/
void setzeLEDHighByte(const unsigned char v) {
	GPIOG->ODR = (GPIOG->ODR & LOWER_BYTE_MASK) | (((uint16_t) v) << SHIFT_TO_UPPER_BYTE);
}


/**
* @brief Diese Funktion liest den in taster uebergebenen Taster aus.
*        Der Zugriff auf den Taster wird softwareseitig entprellt.
*        Es werden maximal ANZAHL_LESEVERSUCHE_PRELLEN Leseversuche
*        durchgefuehrt. 
*        Die Prelldauer eines Tasters betraegt maximal DELTA_PRELLEN us.
* @param taster Nummer des Tasters, der ausgelesen wird.
* @retval true, wenn der Taster gedrueckt ist. Ansonsten und im Fehlerfall
*         (nicht zulaessiger Taster oder Anzahl Leseversuche ueberschritten)
*         ist der Rueckgabewerte false.
*/
bool leseTaster(const unsigned char taster) {
	if (taster <= MAX_TASTER) {
		for (int i = 0; i < ANZAHL_LESEVERSUCHE_PRELLEN; i++) {
			uint16_t tasterMask = (0x01 << taster);
			uint16_t v1 = GPIOE->IDR & tasterMask;
		     sleep(DELTA_PRELLEN);
		     uint16_t v2 = GPIOE->IDR & tasterMask;
		     if (v1 == v2) {
				    return !(v1 == tasterMask);
		     }
	    }
	}
	return false;
}
// EOF
