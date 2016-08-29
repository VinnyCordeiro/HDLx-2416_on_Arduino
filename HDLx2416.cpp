/*
  HDLx2416.cpp - Library for easy use of HDLx-2416 dot matrix
  display family from Avago Technologies.

  Created by Vinicius N. Cordeiro, February 20, 2011.

  Released into the public domain.
*/
/*
  Usually you will want to connect Chip_enable_1, Chip_enable_2 and Write in the same pin, for simplicity.
*/
#include "WProgram.h"
#include "HDLx2416.h"
#include <inttypes.h>

  void HDLx2416::initialize ( )
  {
	pinMode(Chip_enable_1, OUTPUT);
	//pinMode(Chip_enable_2, OUTPUT);
	//pinMode(Write, OUTPUT);
	pinMode(Clear, OUTPUT);
	pinMode(cursor_enable, OUTPUT);
	pinMode(Cursor_select, OUTPUT);
	pinMode(address_input_1, OUTPUT);
	pinMode(address_input_0, OUTPUT);
	pinMode(data_input_6, OUTPUT);
	pinMode(data_input_5, OUTPUT);
	pinMode(data_input_4, OUTPUT);
	pinMode(data_input_3, OUTPUT);
	pinMode(data_input_2, OUTPUT);
	pinMode(data_input_1, OUTPUT);
	pinMode(data_input_0, OUTPUT);
	pinMode(Display_blank, OUTPUT);

	digitalWrite(Chip_enable_1, HIGH);
	//digitalWrite(Chip_enable_2, HIGH);
	//digitalWrite(Write, HIGH);
	digitalWrite(Clear, HIGH);
	digitalWrite(cursor_enable, HIGH);
	digitalWrite(Cursor_select, HIGH);
	digitalWrite(address_input_1, HIGH);
	digitalWrite(address_input_0, HIGH);
	digitalWrite(data_input_6, HIGH);
	digitalWrite(data_input_5, HIGH);
	digitalWrite(data_input_4, HIGH);
	digitalWrite(data_input_3, HIGH);
	digitalWrite(data_input_2, HIGH);
	digitalWrite(data_input_1, HIGH);
	digitalWrite(data_input_0, HIGH);
	digitalWrite(Display_blank, HIGH);
  }
  
  void HDLx2416::reset ( )
  {
	digitalWrite(Clear, LOW);
	delay(5);
  }
  
  void HDLx2416::attributes ( )
  {
	digitalWrite(Clear, HIGH);
	digitalWrite(Chip_enable_1, LOW);
	//digitalWrite(Chip_enable_2, LOW);
	//digitalWrite(Write, LOW);
	digitalWrite(Cursor_select, LOW);
	digitalWrite(data_input_6, LOW);
	digitalWrite(data_input_5, LOW);
	digitalWrite(data_input_4, LOW);
	digitalWrite(data_input_3, LOW);
	digitalWrite(data_input_2, LOW);

	digitalWrite(address_input_1, LOW);
	digitalWrite(address_input_0, LOW);
	digitalWrite(data_input_1, LOW);
	digitalWrite(data_input_0, LOW);
	
	digitalWrite(address_input_1, LOW);
	digitalWrite(address_input_0, HIGH);
	digitalWrite(data_input_1, LOW); 
	digitalWrite(data_input_0, LOW);
	
	digitalWrite(address_input_1, HIGH);
	digitalWrite(address_input_0, LOW);
	digitalWrite(data_input_1, LOW);
	digitalWrite(data_input_0, LOW);
	
	digitalWrite(address_input_1, HIGH);
	digitalWrite(address_input_0, HIGH);
	digitalWrite(data_input_1, LOW);
	digitalWrite(data_input_0, LOW);
  }
  
  void HDLx2416::set ( )
  {
	digitalWrite(Clear, HIGH);
	digitalWrite(Chip_enable_1, LOW);
	//digitalWrite(Chip_enable_2, LOW);
	//digitalWrite(Write, LOW);
	digitalWrite(Cursor_select, HIGH);
  }
  
  void HDLx2416::value (uint8_t position, uint8_t valor )
  {
    switch (position) {
      case 3: // * _ _ _
		digitalWrite(address_input_1, HIGH); digitalWrite(address_input_0, HIGH); break;
      case 2: // _ * _ _
        digitalWrite(address_input_1, HIGH); digitalWrite(address_input_0, LOW); break;
      case 1: // _ _ * _
        digitalWrite(address_input_1, LOW); digitalWrite(address_input_0, HIGH); break;
      default: // _ _ _ * -> case 0
        digitalWrite(address_input_1, LOW); digitalWrite(address_input_0, LOW); break;
    }
    if (valor > 127) {
      digitalWrite(data_input_6, LOW);
      digitalWrite(data_input_5, HIGH);
      digitalWrite(data_input_4, LOW);
      digitalWrite(data_input_3, LOW);
      digitalWrite(data_input_2, LOW);
      digitalWrite(data_input_1, LOW);
      digitalWrite(data_input_0, LOW);
    } else {
      uint8_t umOuZero;
      for (uint8_t i = 7; i > 0; i--) {
        umOuZero = valor % 2;
        if (umOuZero == 1) {
		  switch (i) {
            case 7: // D0 - d�gito menos significativo
              digitalWrite(data_input_0, HIGH); break;
            case 6: // D1
              digitalWrite(data_input_1, HIGH); break;
            case 5: // D2
              digitalWrite(data_input_2, HIGH); break;
            case 4: // D3
              digitalWrite(data_input_3, HIGH); break;
            case 3: // D4
              digitalWrite(data_input_4, HIGH); break;
            case 2: // D5
              digitalWrite(data_input_5, HIGH); break;
            case 1: // D6 - d�gito mais significativo
              digitalWrite(data_input_6, HIGH); break;
          }
        } else {
          switch (i) {
            case 7: // D0 - d�gito menos significativo
              digitalWrite(data_input_0, LOW); break;
            case 6: // D1
              digitalWrite(data_input_1, LOW); break;
            case 5: // D2
              digitalWrite(data_input_2, LOW); break;
            case 4: // D3
              digitalWrite(data_input_3, LOW); break;
            case 3: // D4
              digitalWrite(data_input_4, LOW); break;
            case 2: // D5
              digitalWrite(data_input_5, LOW); break;
            case 1: // D6 - d�gito mais significativo
              digitalWrite(data_input_6, LOW); break;
          }
        }
      valor = valor >> 1;
      }
    }
  }
  
  void HDLx2416::show ( )
  {
	digitalWrite(cursor_enable, LOW);
	digitalWrite(Display_blank, HIGH);
	digitalWrite(Clear, HIGH);
  }
  
  void HDLx2416::nochange ( )
  {
  	digitalWrite(Chip_enable_1, HIGH);
	//digitalWrite(Chip_enable_2, HIGH);
	//digitalWrite(Write, HIGH);
  }
  
  void HDLx2416::change ( )
  {
	digitalWrite(Chip_enable_1, LOW);
	//digitalWrite(Chip_enable_2, LOW);
	//digitalWrite(Write, LOW);
  }
  
