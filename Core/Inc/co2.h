#include "main.h"

#define CO2_HW_MODULE                   (hi2c1)
#define CO2_ADDRESS                     (0x58)

#define CO2_ADDRESS_STATUS              (0x00)          
#define CO2_ADDRESS_MEAS_MODE           (0x01)
#define CO2_ADDRESS_ALG_RESULT_DATA     (0x02)
#define CO2_ADDRESS_RAW_DATA            (0x03)
#define CO2_ADDRESS_ENV_DATA            (0x05)
#define CO2_ADDRESS_THRESHOLDS          (0x10)
#define CO2_ADDRESS_BASELINE            (0x11)
#define CO2_ADDRESS_HW_ID               (0x20)
#define CO2_ADDRESS_HW_VERSION          (0x21)
#define CO2_ADDRESS_FW_BOOT_VERSION     (0x23)  
#define CO2_ADDRESS_FW_APP_VERSION      (0x24)
#define CO2_ADDRESS_INTERNAL_STATE      (0xA0)
#define CO2_ADDRESS_ERROR_ID            (0xE0)
#define CO2_ADDRESS_SW_RESET            (0xFF)

extern uint16 CO2_Data16;

extern void CO2_Init(void);
extern void CO2_Communication(void);