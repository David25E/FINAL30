#define DHT11_Data_Pin            LATBbits.LATB5

#define DHT11_Data_Pin_Direction  TRISBbits.TRISB5

unsigned char Check_bit, Temp_byte_1, Temp_byte_2, RH_byte_1, RH_byte_2;

unsigned char Humidity, RH, Sumation ;

void dht11_init(){
    DHT11_Data_Pin_Direction= 0; //Configure RD0 as output
    
    DHT11_Data_Pin = 0; //RD0 sends 0 to the sensor
    
    __delay_ms(16);
    
    DHT11_Data_Pin = 1; //RD0 sends 1 to the sensor
    
    __delay_us(30);
    
    DHT11_Data_Pin_Direction = 1; //Configure RD0 as input
    
    }

 
/*

 * This will find the dht11 sensor is working or not.

 */


 void find_response(){

 Check_bit = 0;

 __delay_us(80);

 if (DHT11_Data_Pin == 0){

 __delay_us(80);

 if (DHT11_Data_Pin == 1){

    Check_bit = 1;

 }     

 __delay_us(50);
 }

 }

 

 /*

 This Function is for read dht11.

 */

 

 char read_dht11(){

 char data, for_count;

 for(for_count = 0; for_count < 8; for_count++){

     while(!DHT11_Data_Pin); 

    __delay_us(26);

    if(DHT11_Data_Pin == 0){

        data&= ~(1<<(7 - for_count)); //Clear bit (7-b)

    }

    else{

        data|= (1 << (7 - for_count)); //Set bit (7-b)

        while(DHT11_Data_Pin);

    } //Wait until PORTD.F0 goes LOW

    }

 return data;

 }

 


