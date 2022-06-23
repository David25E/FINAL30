# **Sonar Tackle Box Journey** 

## **Week One**
This week was the initial week to begin brainstorming of what I want to do and how I can acheive goals with my planned process. Additionally, I also had to think about how I can rapidly and efficiently adapt to changes.
Changes such as,
- Arrival times of components
- Issues with libraries
- Difficulties with configuring an i2c display module

However, I was easily able to connect each available component to the board because either only consisted of two header pins, power and ground pin. This allows me to utilise more components with the less header pins needed.
### **What I Should Have Done to Improve my Understanding**
Additionally, to improve my knowledge of library choosing and changing code, I should have done prior research to see what will work and to determine possible issues in the future. Because of this, I would have made the journey more convinent and less troubling.

The configuration of the lcd display decently slowed down the process of the plan since I underestimated the lcd display. I originally thought I could configure it within a couple days, but after a week I am still having issues.

### **What I Learned and Absorbed**
Overall, I thought it would have been easier because I used a library that can work with the board(PIC16F1459). But, it showed to be more difficult because of my no experience regarding coding with different components. Thus, I asked for help, which signifcantly helped me understand how to change certain aspects of the code to configure it with the board.
This aspects are:
- Assigning each pin, such as SDA and SCL to certain header pins
- Having to make both swap between states of input and output
- Wiring the cables correctly to have current/a signal run through the headers

This helped me understand how to choose libraries that can work with components by changing the code correctly. Because of this, I was quickly and easily able to get my distance sensor working with slight issues. I have my code set up to light up an LED if it between the blind and max distance(20-600cm). Initially it did not work, but after placing it down and being more than 20cm apart an object the LED lit up and remained lit even after I was in the blind zone.
Hence, it showed me that there is a signal going to the header pin and the distance sensor module was receiving it. 
But there could be two issues:
- 1st Issue: Within the last few days the board seemed to be crashing frequently since the reset button would not work. I would repeatedly have to unplug and replug the power cable while pressing down the button. Ultimately, this could freeze the transportation of data from the sensor to the board.
- 2nd Issue: The code may still consist of improper assigning of the header pins. Instead, the code is messing with the bits of the LED and it is somehow lighting the LED in a way that I am unaware of.


## **Week Two**
This week I made momentous progress with the significant help of Mr. Lam, without his help I may have only completed a small portion of my specified idea.
Progress I made this week:
- Got my distance sensor working in air (JSN SRT04 V3.0)
- Functioning of my lcd display by using it manually instead of the troubling i2c module
<img src="https://user-images.githubusercontent.com/99207863/175181243-3f778f8e-ddf2-4f19-92d4-7febe5d7570c.jpg"  width=50% height=25%>

- Temperature/Humidity sensor (DHT11) code works with the lcd display, however, I am having trouble with assigning its header pins to display the data
- Figured out the significant research I need to do to calibrate my distance sensor to function underwater

### **My Struggles this Week**
I intially continued to have trouble with my lcd display using the i2c module, so I was going to desolder my buttons to use the ports my preset code was using. However, Mr. Lam told me to simply use it manually. Although it uses six header pins insetad of 2, I still have enough for my distance sensor which uses two. Additionally, my flow sensor simply has two cables that can connected after I de-solder a button.
After testing my distance sensor in my bathtub I figured out the truth. I should have done more research before the project to truly figure out how the sensor works underwater because it is not designed to work underwater. I simply bought it because it is a waterproof and cheaper(20 dollar) alternative. Fortunately, it is possible to calibrate it to work underwater, but it will require excess research, time, and testing. I could have bought a better air sensor that can more easily be calibrated, but I was not going to pay 100-150 dollars.

Ultimately, it will come down to the last week to see if I am going to be able to finish my overall idea. I will need to brainstorm a good way to be able to test my sonar underwater at school to allow for the most efficient and thorough testing.

#### **Small Change in Plans**
Because of those reasons, I will not be using the flow sensor and built in mcu temperature sensor. Instead, I found a temperature/humidity temperature sensor(DHT11), which will provide a time saving alternative. With the built in temperature sensor I would have to figure out how to display it on my lcd and potentially convert the adc output to celsius. Yes it would not have taken much time, but I found a library for the temperature sensor that also corporates the lcd display library. With this I saved much time and somewhat involved a bonus by switching the flow data to temperature and humidity data. Additionally, the flow sensor would have been difficult to test, especially in a school environment.

I sincerely want to calibrate my distance sensor to work underwater and actually get it to function in a decentl manner. Thus, next week will primarily be research and underwater testing of my sensor, but first I have to code it to display the readings on the lcd. Plus, I will attempt to add the flow sensor during the summer so it is not wasted. I apologize Mr. Lam for having to buy the flow sensor, especially since I am not going to use it for the project.

### **Minor Inconveniences**
I experiecned several minor inconvenices that caused me to waste a signifcant amount of time. I realized that small changes in the code can have the largest difference, such as defining XTAl_FREQ in my main file instead of keeping it in my lcd header file, and simply having to change the trigger delay of my sonar from 10 to 25 microseconds. 
- Trouble with assigning the correct header pins to the correct output latches of the board
- Defining the frequency in my main file allowed me to prevent the display to constantly show junk and random characters.
<img src="https://user-images.githubusercontent.com/99207863/175181666-10dbfeeb-9cb3-4a6f-bd89-1aabcf714b29.jpg"  width=40% height=40%>

## **Week Three**
My primary goal for this week was to calibrate my JSN SR04T sensor to function underwater. However, I was having difficulties because it is not designed for underwater usage. Before starting my project, I found a paper and a few forums that said that it is somehow posssible to calibrate it underwater, but with no exact explanation.
Thus, I researched underwater calibration for other sensors and found some points to test with my sensor:
- The speed of sound is about 4.3 times faster in water
- My minimum sensing distance in water would be at least about 86 cm (20cm blind zone x 4.3)
- Slight changes in turbulence, temperature and ground material can greatly affecting sensing

It always displayed a constant value of 90-95 cm no matter the actual depth of my testing tube. At first, I thought it had worked but when I got an actual tube with a sealed off bottom instead of a fully ducktaped carboard tube, it did not function.
<img src="https://user-images.githubusercontent.com/99207863/175181956-422aef2d-2cca-4499-abda-60514362d683.jpg"  width=40% height=40%>
The tube is six feet tall.

### **My Issues**
Initally, I had trouble displaying the changing distances on my lcd display because it was displaying the ascii table,

https://user-images.githubusercontent.com/99207863/175182831-4cac3838-4015-43e9-9886-e4946e3b2624.mp4

so I used the sprintf function. This function allowed me to convert the data from ascii to whole numbers in centimeters.
It uses two parameters; the first being the converted int/char into my desired state and the second one is the string I will write with %d, which will replace the char range for the distance. After, I will simply set the cursor location and type Lcd_Write_String(variable).

Plus, I continued having issues with my DHT11 sensor because it was not cycling between states of high to low voltage in order to switch states of reading and sending data to the MCU. This was because the voltage constantly stayed high and did not pull down. I do not know the exact reason for this because I correctly assigned the single data cable to its header pin of RB5.

### **My Other Possible Options**
- Attempt to use an actual fish finder transducer
<img src="https://user-images.githubusercontent.com/99207863/175180883-157785e0-b8ff-4af0-a48f-9a9903ce3798.jpg"  width=50% height=50%>
- Use a laser module to light a beam through the water and have it reflected it back to be sensed by an ambient light sensor. With this sensor I will try to convert the intensity of the light to centimeters
- Continue with my JSN SR04T
With only three days left until its due, I have to make a thorough decision. Should I continue with my JSN sensor, try the laser idea, or somehow attempt to connect a 20 year old transducer.

I tried the laser idea and de-soldered my ir sensor to use an ambient light sensor, however, it was a waste time but I learned from it. The laser worked as I put a small metal plate at the bottom of the tube and it pentreated the water and reflected back, but the ambient light sensor was too small to detect it. The ambient light sensor had to be perfectly lined up with the reflection as the surface area was too small.

## **Last Three Days**
These last three days I have been trying to configure my DHT11 to work and calibrate my distance sensor to work underwater. I continued to have trouble with both tasks. However, on the last day I was able to get my distance sensor to work underwater.
In contrast, I dropped off my temeperature sensor to be tested by Mr. Lam and he was able to pull down the voltage.

### **What I realized**
I realized several points that I forgot and did not give enough thought to during the planning, build, and testing process. Overall, I should have done more research to better understand the sensor and how ultrasound works underwater.
- The sensor needed to be perfectly pointed and positioned to function
- A reason for that was that the sensing angle is quite high of 70-75 degrees and my testing tube is 4cm in diamater, which prevented the sensor from working even in air.
These reaons caused me to waste a significant amount of time because it misled me to think that my code was not working, so I was constaly changing small values and adding other aspects, such as trying to use a formula. 

The formula is: 2(distance) = Vsound(velocity of sound) * time.
Fortunately, out of no where it worked the same way as it worked last week. Thus, my only goal is to eliminate the constant value that it sometimes reads and try to figure out the proper positioning and angle of the sensor.
It worked with about a 12cm difference of the actual distance, so I add 12cm to the range if it is over 100cm to eliminate the constant.


Overall, I learned a significant amount and gained a tremendous amount of interest in programming and electronics. I extremely enjoyed this project and will definitely continute improvng and adding to it during the summer.
Thank You, Mr. Lam.
