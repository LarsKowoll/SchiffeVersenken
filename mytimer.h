/**
  ******************************************************************************
  * @file    mytimer.h 
  * @author  <Ihre Name>
  * @date    <Datum der Probeklausur>
  * @brief   Diese Datei gehört zur GS Probeklausur WS 2018-19 SchiffeVersenken
	*          Interface des Moduls mytimer, das  einfache Timer Funktionen 
	*          realisiert.
  ******************************************************************************
  */
	#ifndef _MYTIMER_H
#define _MYTIMER_H
#include "general.h"
#include <stdint.h>

	void initMyTimer(void);
	void sleep(const uint32_t);
		
	#endif

// EOF
