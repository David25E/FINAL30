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
#include    "stdlib.h"
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions
#include    "Sonar.h"           // Include UBMP4 SONAR definitions
#include    "lcd.h"
#include    "Temp.h"

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Program variable definitions
unsigned char range = 0;        // SONAR target range underwater
unsigned char temp_value = 0;
unsigned char humidity_value = 0;

char buffer[20];
char temp[20];
char humi[20];

void Display_Depth(){
    if(sonar_ready())
        {
            range = sonar_range_cm();
        }
        
        if(range > 92 && range < 253){                              /// > 24 in air   
            sprintf(&buffer, "%03d cm  :Depth", range);
            Lcd_Set_Cursor(1, 1);
            Lcd_Write_String(buffer);                               ///using 92cm eliminates majority of the typical constant values of 88-95cm when entering the water
        }
        if(range < 92){                                             ///<24 if in air
            Lcd_Clear();
            Lcd_Set_Cursor(1, 1);
            Lcd_Write_String("Out of Range");
        }
        
        // Delay between SONAR pings
        __delay_ms(725);                                            ///25ms if in air
}

void Depth_Alarm(){
    if(range < 100){
        BEEPER = !BEEPER;
            }
}

void Display_Temp_Humi(){
    dht11_init();
    
    find_response();
    
    if(Check_bit == 1){
        RH_byte_1 = read_dht11();
        
        RH_byte_2 = read_dht11();
        
        Temp_byte_1 = read_dht11();
        
        Temp_byte_2 = read_dht11();
        
        Sumation = read_dht11();
        
        if(Sumation == ((RH_byte_1+RH_byte_2+Temp_byte_1+Temp_byte_2) & 0XFF)){
            
            Humidity = Temp_byte_1;

            RH = RH_byte_1;

            temp_value = (48 + ((RH / 10) % 10));                  //display temperature using sprintf
            temp_value = (48 + (RH % 10));
            sprintf(&temp, "03%d C   :Temp", temp_value);
            Lcd_Set_Cursor(2, 1);
            Lcd_Write_String(temp);                        
            
            humidity_value = (48 + ((Humidity / 10) % 10));        //display humidity using sprintf
            humidity_value = (48 + (Humidity % 10));
            sprintf(&humi, "03%d   :Humidity", humidity_value);
            Lcd_Set_Cursor(3, 1);
            Lcd_Write_String(humidity_value);

            }

        else{
            Lcd_Set_Cursor(2, 1);
            Lcd_Write_String("Check sum error");

        }
        
        }
        
        else {
            
            Lcd_Clear();
            
            Lcd_Set_Cursor(2, 1);
            
            Lcd_Write_String("Error!!!");
            
            Lcd_Set_Cursor(3, 1);
            
            Lcd_Write_String("No Response.");
            
            }
            
            __delay_ms(1000);
}

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
    Lcd_Init();

    while(1)
	{
        Display_Depth();
        Depth_Alarm();        
        

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}



        
