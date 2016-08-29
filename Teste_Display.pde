/*
HDLx-2416 - Teste 04: Exibindo outros caracteres agora
28-04-2011
*/
#include "HDLx2416.h"
#include <inttypes.h>

const uint8_t D0   = 0; const uint8_t D1   = 1; const uint8_t D2   = 2; const uint8_t D3   = 3;
const uint8_t D4   = 4; const uint8_t D5   = 5; const uint8_t D6   = 6; const uint8_t CUE  = 7;
const uint8_t BL_  = 8; const uint8_t CLR_ = 9; const uint8_t CEWR = 10; const uint8_t CU_ = 11;
const uint8_t A_0  = 12; const uint8_t A_1 = 13;

HDLx2416 LED;

void setup() {
  LED.Chip_enable_1 = CEWR;
  LED.Chip_enable_2 = CEWR;
  LED.Write = CEWR;
  LED.Clear = CLR_;
  LED.cursor_enable = CUE;
  LED.Cursor_select = CU_;
  LED.address_input_1 = A_1;
  LED.address_input_0 = A_0;
  LED.data_input_6 = D6;
  LED.data_input_5 = D5;
  LED.data_input_4 = D4;
  LED.data_input_3 = D3;
  LED.data_input_2 = D2;
  LED.data_input_1 = D1;
  LED.data_input_0 = D0;
  LED.Display_blank = BL_;

  LED.initialize();
  LED.reset();
  LED.attributes();
}

void loop() {
  uint8_t teste = 0;

  while (teste <= 127) {
    LED.change();
    LED.set();

    LED.value(3, teste);
    LED.value(2, teste+1);
    LED.value(1, teste+2);
    LED.value(0, teste+3);

    LED.show();
    LED.nochange();
  
    teste++;
    delay(500);
  }
}
