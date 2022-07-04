/*
 * File:   led.c
 * Author: wissem
 *
 * Created on June 29, 2022, 1:39 PM
 */


#include <xc.h>
#include "config.h"

// define frequency 
#define _XTAL_FREQ 48000000


// location of the LED, DATA output, and pushbutton
#define LED RC2
#define DATA RC3
#define SW1 !RA5





// macro to send the bit 'b' 
#define send(b) DATA = 1 ;NOP();NOP();NOP();DATA=b ;NOP();NOP();NOP();NOP();DATA=0;NOP();NOP();NOP();NOP();


//functions
void sendByte (unsigned char b);                                  // send 8 bit with WS protocol
void sendRGB (unsigned char r, unsigned char g, unsigned char b); // send RGB 



void sendByte (unsigned char b) {

    if (b & 0b10000000) { send(1); } else { send(0); }
    if (b & 0b01000000) { send(1); } else { send(0); }
    if (b & 0b00100000) { send(1); } else { send(0); }
    if (b & 0b00010000) { send(1); } else { send(0); }
    if (b & 0b00001000) { send(1); } else { send(0); }
    if (b & 0b00000100) { send(1); } else { send(0); }
    if (b & 0b00000010) { send(1); } else { send(0); }
    if (b & 0b00000001) { send(1); } else { send(0); }
    
}

void sendRGB (unsigned char r, unsigned char g, unsigned char b) {

    sendByte(g);
    sendByte(r);
    sendByte(b);
    
}
void main(void) {
    return;
}
