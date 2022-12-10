My final Project is Digital Angle Gauge using I2C where I will be calculating Roll and Pitch values and will be displayed in UART and also I have included calibration using UART and switch GPIO which I have mentioned in the proposal </br>

I have written test suites for the working of cbfifo,angle detect and LED glow through PWM</br>

I have maintained BLUE LED glow till I obtain ZERO Degree orientation and also displayed in UART then after I perform my demo.</br>

Basically I will be blinking 4 LEDS like Red for 30 Deg Orientation,Green for 45 Deg Orientation,60 Deg Orientation will be used to glow BLUE led and also white LED is glown for 90 Deg Orientation</br>

I have used two commands like 'angle' and 'calibrate' where if command 'angle' is given Im able to provide real time angle calculation roll and pitch and also if command 'calibrate' is given Im able to set roll and pitch angle as zero</br>

I have used external switch connected to PTD3 to calibrate the pitch and roll axis</br>

My learnings from this will be learning to handle multiple protocols and interrupts </br>

Challenges faced are to integrate I2C to UART and also the calculation of roll and pitch and also to maintain LED for the perspective orientation</br>

Thank you Mukta and Nimish for helping me out through out the assignment and this semister and also thanks to Lalit Pandit Sir for the teachings and guidance</br>

The required settings for UART were:</br>
i)Baud rate:38400</br>
ii)Parity bits:0 </br>
iii)Stop bits:2 </br>
iv)Total data bits :8</br>

Please find the Project Video Demonstration below via google doc link:</br>
https://drive.google.com/drive/folders/15Wb9ZRyAPbfEZ1HxP-fEK00Hb5iByYH_?usp=sharing </br>
