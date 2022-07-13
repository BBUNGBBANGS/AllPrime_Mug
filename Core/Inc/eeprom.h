#include "main.h"

#define EEPROM_PAGE127_START ((uint32)(0x0801FC00))

extern uint8 switch_submodeEEP;
extern sint16 switch_trg_tempEEP; 
extern sint16 switch_trg_timeEEP;
extern sint16 switch_idle_tempEEP;

extern void EEPROM_Write(void);
extern void EEPROM_Read(void);
extern void EEPROM_Erase(void);