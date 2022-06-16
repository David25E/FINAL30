/*==============================================================================
 Project: Intro-2-Variables
 Date:    May 16, 2021
 
 This example program demonstrates the use of byte (char) constants and
 variables to count button presses and trigger actions when a limit is reached.
  
 Additional program analysis and programming activities demonstrate using bit
 (Boolean, or bool) variables to store state for operations such as preventing 
 multiple counting of a singe button press during successive program loops.
 Additional activities include the creation of a two-player rapid-clicker game,
 simulating a real-world toggle button, and counting switch contact bounce.
==============================================================================*/
// set configuration words


#define _XTAL_FREQ 4000000

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdio.h"
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions
#include    "Sonar.h"           // Include UBMP4 SONAR definitions
#include    "lcd.h"
#include    "Temp.h"


// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Program variable definitions
unsigned char range = 0;        // SONAR target range
// variables declaration
char Temperature[] = "Temp = 00.0 C  ";
char Humidity[]    = "RH   = 00.0 %  ";
unsigned char T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum ;
 
int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
    Lcd_Init();
    char buffer[20];
    //T1CON  = 0x10;        // set Timer1 clock source to internal with 1:2 prescaler (Timer1 clock = 1MHz)
    //TMR1H  = 0;           // reset Timer1
    //TMR1L  = 0;
    
    while(1)
	{
        if(sonar_ready())
        {
            range = sonar_range_cm() + 3;
        }
        // Delay between SONAR pings
        __delay_ms(25);
        
        if(range > 24 && range < 253){
            sprintf(&buffer, "%03d cm  :Depth", range);
            Lcd_Set_Cursor(1, 1);
            Lcd_Write_String(buffer);
        }
        if(range < 28){
            Lcd_Clear();
            Lcd_Set_Cursor(1, 1);
            Lcd_Write_String("Out of Range");
        }
        __delay_ms(700);

        if(range < 105){
            BEEPER = !BEEPER;
            __delay_us(956);
        }
        

        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
/* 
Start_Signal();     // send start signal to the sensor
        
        if(Check_Response())    // check if there is a response from sensor (If OK start reading humidity and temperature data)
        {
            // read (and save) data from the DHT11 sensor and check time out errors
            if(Read_Data(&RH_Byte1) || Read_Data(&RH_Byte2) || Read_Data(&T_Byte1) || Read_Data(&T_Byte2) || Read_Data(&CheckSum))
            {
                Lcd_Clear();       // clear LCD
                Lcd_Set_Cursor(2, 1);           // go to column 5, row 2
                Lcd_Write_String("Time out!");   // display "Time out!"
                }
                
                else         // if there is no time out error
                {
                    if(CheckSum == ((RH_Byte1 + RH_Byte2 + T_Byte1 + T_Byte2) & 0xFF))
                    {                                       // if there is no checksum error
                    Temperature[7]  = T_Byte1 / 10  + '0';
                    Temperature[8]  = T_Byte1 % 10  + '0';
                    Temperature[10] = T_Byte2 / 10  + '0';
                    Humidity[7]     = RH_Byte1 / 10 + '0';
                    Humidity[8]     = RH_Byte1 % 10 + '0';
                    Humidity[10]    = RH_Byte2 / 10 + '0';
                    Temperature[11] = 223;    // put degree symbol (°)
                    Lcd_Set_Cursor(2, 1);           // go to column 1, row 1
                    Lcd_Write_String(Temperature);
                    Lcd_Set_Cursor(3, 1);           // go to column 1, row 2
                    Lcd_Write_String(Humidity);
                    }
                    // if there is a checksum error
                    else
                    {
                        Lcd_Clear();       // clear LCD
                        Lcd_Set_Cursor(2, 1);           // go to column 1, row 1
                        Lcd_Write_String("Checksum Error!");
                        }
                }
    }
    // if there is a response (from the sensor) problem
        else
        {
            Lcd_Clear();// clear LCD
            Lcd_Set_Cursor(1, 1);           // go to column 3, row 1
            Lcd_Write_String("No response");
            Lcd_Set_Cursor(2, 1);           // go to column 1, row 2
            Lcd_Write_String("from the sensor");
    }
    
        TMR1ON = 0;        // disable Timer1 module
        __delay_ms(1000);  // wait 1 second
    
*/


        
