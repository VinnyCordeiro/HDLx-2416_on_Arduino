/*
  HDLx2416.h - Library for easy use of HDLx-2416 dot matrix
  display family from Avago Technologies.

  Created by Vinicius N. Cordeiro, February 20, 2011.

  Released into the public domain.
*/

#ifndef HDLx2416_h
#define HDLx2416_h

#include "Arduino.h"
#include <inttypes.h>

/*
  This library is writen considering my specific needs. For that, I've
  connected pins 1, 2 & 6 of the display, considering the truth table.
  If you need to address these pins individually, you'll have to edit
  the library accordingly.

  Pin # - Function
  1 - _CE1 Chip Enable
  2 - _CE2 Chip Enable
  3 - _CLR Clear
  4 - CUE Cursor Enable
  5 - _CU Cursor Select
  6 - _WR Write
  7 - A1 Address Input
  8 - A0 Address Input
  9 - VDD
 10 - GND
 11 - D0 Data Input
 12 - D1 Data Input
 13 - D2 Data Input
 14 - D3 Data Input
 15 - D6 Data Input
 16 - D5 Data Input
 17 - D4 Data Input
 18 - _BL Display Blank

_ indicates a low activated port.
*/

class HDLx2416
{
public:

  // Public attributes
  //  
  uint8_t Chip_enable_1;
  uint8_t Chip_enable_2;
  uint8_t Clear;
  uint8_t cursor_enable;
  uint8_t Cursor_select;
  uint8_t Write;
  uint8_t address_input_1;
  uint8_t address_input_0;
  uint8_t data_input_6;
  uint8_t data_input_5;
  uint8_t data_input_4;
  uint8_t data_input_3;
  uint8_t data_input_2;
  uint8_t data_input_1;
  uint8_t data_input_0;
  uint8_t Display_blank;

  void initialize ( );
  void reset ( );
  void attributes ( );
  void set ( );
  /**
   * @param  position Posicão do display onde será exibido o caractere.
   * @param  valor Valor a ser exibido no display.
   */
  void value (uint8_t position, uint8_t valor );
  void show ( );
  void nochange ( );
  void change ( );
};

#endif // HDLX2416_H
