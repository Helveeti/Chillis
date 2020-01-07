/**
* @mainpage ZumoBot Project
* @brief    You can make your own ZumoBot with various sensors.
* @details  <br><br>
    <p>
    <B>General</B><br>
    You will use Pololu Zumo Shields for your robot project with CY8CKIT-059(PSoC 5LP) from Cypress semiconductor.This 
    library has basic methods of various sensors and communications so that you can make what you want with them. <br> 
    <br><br>
    </p>
    
    <p>
    <B>Sensors</B><br>
    &nbsp;Included: <br>
        &nbsp;&nbsp;&nbsp;&nbsp;LSM303D: Accelerometer & Magnetometer<br>
        &nbsp;&nbsp;&nbsp;&nbsp;dig.l3GD20H: Gyroscope<br>
        &nbsp;&nbsp;&nbsp;&nbsp;Reflectance sensor<br>
        &nbsp;&nbsp;&nbsp;&nbsp;Motors
    &nbsp;Wii nunchuck<br>
    &nbsp;TSOP-2236: IR Receiver<br>
    &nbsp;HC-SR04: Ultrasonic sensor<br>
    &nbsp;APDS-9301: Ambient light sensor<br>
    &nbsp;IR LED <br><br><br>
    </p>
    
    <p>
    <B>Communication</B><br>
    I2C, UART, Serial<br>
    </p>
*/

#include <project.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Motor.h"
#include "Ultra.h"
#include "Nunchuk.h"
#include "Reflectance.h"
#include "Gyro.h"
#include "Accel_magnet.h"
#include "LSM303D.h"
#include "IR.h"
#include "Beep.h"
#include "mqtt_sender.h"
#include <time.h>
#include <sys/time.h>
#include "serial1.h"
#include <unistd.h>
#include <stdlib.h>

void FollowLine(void);
void Tankki(void);
void SmallTank(void);

void FollowLineTankTurnEdition(void);
void SkipBlack(void);
void SkipBlackSquare(void);
void TankTurnL(uint8 speed,uint32 delay);
void TankTurnR(uint8 speed,uint32 delay);


/**
 * @file    main.c
 * @brief   
 * @details  ** Enable global interrupt since Zumo library uses interrupts. **<br>&nbsp;&nbsp;&nbsp;CyGlobalIntEnable;<br>
*/

#if 0
// Hello World!
void zmain(void)
{
    printf("\nHello, World!\n");

    while(true)
    {
        vTaskDelay(100); // sleep (in an infinite loop)
    }
 }   
#endif

// Week 2
    // Assignment 1

#if 0
    
    void zmain(void){
    
        printf("Assigment 1");
        
        while(true){
            if(getchar()){
                
                for(int i = 0; i < 3; i++){
                    BatteryLed_Write(1);
                    vTaskDelay(500);
                
                    BatteryLed_Write(0);
                    vTaskDelay(500);
                }
                
                for(int j = 0; j < 3; j++){
                    BatteryLed_Write(1);
                    vTaskDelay(1000);
                
                    BatteryLed_Write(0);
                    vTaskDelay(500);
                }
                
                for(int k = 0; k < 3; k++){
                    BatteryLed_Write(1);
                    vTaskDelay(500);
                
                    BatteryLed_Write(0);
                    vTaskDelay(500);
                }
            }
        }
    
    }
#endif

    // Assignment 2

#if 0
    
    void zmain(void){
        
         printf("\nAssigment 2\n");
        
        int age = 0;
        int i = 0;
    
        printf("How old are you?\n");
    
        while(true){
        
            scanf("%d", &age);
        
            if(age != 0){
                break;
            }
        
            vTaskDelay(100);
            i++;
        }
    
        if(age <= 21){
            if(i < 300){
                printf("Super fast dude!\n");
            }else if(i >= 300 && i <= 500){
                printf("So mediocre.");
            }else{
                printf("My granny is faster than you!\n");
            }
        }else if(age >= 22 && age <= 50){
            if(i < 300){
                printf("Be quick or be dead.\n");
            }else if(i >= 300 && i <= 500){
                printf("You are so average.\n");
            }else{
                printf("You are doing okay for your age.\n");
            }
        }else if(age > 50){
            if(i < 300){
                printf("Still going strong!\n");
            }else if(i >= 300 && i <= 500){
                printf("You are doing ok for your age.\n");
            }else{
                printf("Do they still allow you to drive?\n");
            }
        }else{
                printf("Something went wrong.\n");
        }
         while(true)
        {
            vTaskDelay(100);
        }
    }
 #endif

    // Assignment 3

#if 0
//battery level//
void zmain(void)
{
    ADC_Battery_Start();        

    int16 adcresult = 0;
    float volts = 0.0;
    float v = 0.0;

    printf("\nBoot\n");

    BatteryLed_Write(0); 

    while(true)
    {
        ADC_Battery_StartConvert();
        if(ADC_Battery_IsEndConversion(ADC_Battery_WAIT_FOR_RESULT)) {
            adcresult = ADC_Battery_GetResult16();
            
            v = adcresult/4095.0;
            v = v * 1.5 * 5.0;
            volts = v;
            
                while(volts < 4.0){
                    BatteryLed_Write(1);
                    vTaskDelay(100);
                
                    BatteryLed_Write(0);
                    vTaskDelay(100);
                        
                    if(SW1_Read() == 0){
                        break;
                    }
                }
            printf("%d %f\r\n", adcresult, volts);
        }
        vTaskDelay(500);
    }
 }   
#endif

// Week 3
    // Assignment 1

#if 0
    
void zmain(void)
{
    motor_start();              // enable motor controller
    motor_forward(0,0);         // set speed to zero to stop motors

    vTaskDelay(3000);
    
    //motor_forward(100,2000);     // moving forward
    //motor_turn(200,50,2000);     // turn 180
    //motor_turn(50,200,2000);     // turn 360
    //motor_backward(100,2000);    // moving backward
   
        motor_turn(200,195,1650); //Forward
        motor_turn(150,55,1000); //Turn
        
        motor_turn(200,195,1100); //Forward
        motor_turn(150,55,1000); //Turn
        
        motor_turn(200,195,1250); //Forward
        motor_turn(100,25,1800); //Turn
        motor_turn(150,110,1400); //Turn
        
     
    motor_forward(0,0);         // stop motors

    motor_stop();               // disable motor controller
    
    while(true)
    {
        vTaskDelay(100);
    }
}
#endif

        // Assignment 2

#if 0
//ultrasonic sensor//
void zmain(void)
{
    Ultra_Start();
    motor_start();
    motor_forward(0,0);
    
    while(true) {
        int d = Ultra_GetDistance();
        printf("distance = %d\r\n", d);
        motor_forward(100,100);
        
        if(d <= 20){
            Beep(30,5);
            motor_backward(100,100);
            motor_turn(200,0,300);
        }
        
        vTaskDelay(200);
    }
}   
#endif

        // Assignment 3

#if 0
/* Accelerometer!!!*/
    
void zmain(void)
{
    motor_start();
    motor_forward(0,0);
    
    struct accData_ data;
    
    printf("Accelerometer test...\n");

    if(!LSM303D_Start()){
        printf("LSM303D failed to initialize!!! Program is Ending!!!\n");
        vTaskSuspend(NULL);
    }
    else {
        printf("Device Ok...\n");
    }
    
    while(true)
    {
        LSM303D_Read_Acc(&data);
        //printf("%8d %8d %8d\n",data.accX, data.accY, data.accZ);
        
        motor_forward(100,0);
        
        if(data.accY < -3000){
            
            int i = rand() % 2;
            
            switch(i){
                case 1:
                    motor_backward(100,500);
                    motor_turn(150, 55, 500); // Turning to right
                    break;
                case 2:
                    motor_backward(100,500);
                    motor_turn(55, 150, 500); // Turning to left
                    break;
                default:
                    motor_forward(0,0);
                    break;
                }
        }
    }
 }   
#endif 

    // Week 4
        // Assignment 1

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    
    while(true){
        motor_forward(0,0);
        
        if(SW1_Read() == 0){
            motor_forward(200,1000);
            motor_forward(0,0);
            break;
        }
    }
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
                
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
                
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            motor_forward(250,2000);
            motor_forward(0,0);
            IR_flush();
            break;
        }
    }
    
    while(true)
    {
        vTaskDelay(100);
    }
    
    }
}
#endif

#if 0

    void zmain(void){
        
    IR_Start();
    motor_start();
    
    struct sensors_ ref;
    struct sensors_ dig;
    
    while(true){
        motor_forward(0,0);
        
        if(SW1_Read() == 0){
            motor_forward(200,1000);
            motor_forward(0,0);
            break;
        }
    }
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            
            while(true){
            
                reflectance_read(&ref);
                printf("%5d %5d %5d %5d %5d %5d\r\n", ref.dig.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);
            
                reflectance_digital(&dig); 
                printf("%5d %5d %5d %5d %5d %5d \r\n", dig.dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);
            
                if(dig.l1 == 1 && dig.r1 == 0){
                    motor_turn(100,55,100);
                }else if(dig.l1 == 0 && dig.r1 == 1){
                    motor_turn(50,100,100);
                }else if(dig.l1 == 1 && dig.r1 == 1){
                    while(!(dig.r1 == 0)){
                        motor_turn(100,10,500);
                    }
                }else{
                    motor_forward(100,500); 
                }
            
            }
        
            vTaskDelay(200);
            
            IR_flush();
            break;
            }
        }
    }

    while(true){
        vTaskDelay(200);
    }
}
    
#endif

        // Assignement 1  -- TANJA && JANINA

#if 0
    //assignment 3.1. USE THIS

void zmain(void)
{
    motor_start(); 
    IR_Start();
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
                
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
                
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            FollowLine();
            SkipBlack();
            IR_flush();
            break;
        }
    }
        
     }  
    while(true){
            vTaskDelay(1000);
        }
    }

#endif

#if 0

   void zmain (void){
    motor_start();
    
    
 FollowLineTankTurnEdition();   

while(true){
            vTaskDelay(1000);
        }
    
}
    
#endif

void SkipBlack(void) {
    int blackLines = 0;
    bool wasOnBlackLine = false;
    
    struct sensors_ ref;
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
    
    while(true){
        
        reflectance_read(&ref);
        reflectance_digital(&dig);
    
        if (dig.l3 == 1 && dig.l2 == 1 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1){
            motor_forward(100,0);
            wasOnBlackLine = true;
        }else if (dig.l3 == 0 && dig.r3 == 0 && wasOnBlackLine == true){
             blackLines += 1;
             wasOnBlackLine = false;
                if (blackLines >= 4){
                    motor_forward(0,0);
                    break;
        }
            }
        else if(dig.l1 == 1 || dig.r1 == 1){ // näkee keskellä mustaa
            motor_forward(100,0);
        }else if(dig.l2 == 1 && dig.r2 == 0){ // näkee vasammalla mustaa
            motor_turn(20,100,0); // kääntyy vasemmalle
        }else if (dig.l3 == 1 && dig.r3 == 0){ // jos kaukana vasemmalla mustaa
            while(!(dig.l1 == 0 || dig.r1 == 0)){ // jos ei löydä mustaa, pyörii ympyrää
                motor_turn(20,150,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }else if(dig.r2 == 1 && dig.l2 == 0){ // näkee oikeella mustaa
            motor_turn(100,20,0); // kääntyy oikeelle
        }else if (dig.l3 == 0 && dig.r3 == 1){ // jos kaukana oikealla mustaa
             while(!(dig.l1 == 0 || dig.r1 == 0)){ //jyrkkä oikea niin kauan että löytyy mustaa
                motor_turn(150,55,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }
    }
    
}
#if 0
    // assignment 3.2 

void zmain(void){
        
    motor_start(); 
    IR_Start();
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
                
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
                
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            SkipBlackSquare();
            
            
            IR_flush();
            //break;
        }
    }
        
        while(true){
            vTaskDelay(1000);
        }
    }
}
   
#endif

void SkipBlackSquare(void) {
    int blackLines = 0;
    bool wasOnBlackLine = false;
    
    struct sensors_ ref;
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
    
    while(true){
        
        reflectance_read(&ref);
        reflectance_digital(&dig);
    
        if (dig.l3 == 1 && dig.l2 == 1 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1){
            motor_forward(100,0);
            wasOnBlackLine = true;
        }else if (dig.l3 == 0 && dig.r3 == 0 && wasOnBlackLine == true){
             blackLines += 1;
             wasOnBlackLine = false;
            Beep(200,200);
                if (blackLines >= 5){
                    motor_forward(0,0);
                    break;
                }else if(blackLines == 2){
                    TankTurnL(100,0);
                }else if(blackLines == 3 || blackLines == 4){
                    TankTurnR(100,0);
                }
            }
        else if(dig.l1 == 1 || dig.r1 == 1){ // näkee keskellä mustaa
            motor_forward(100,0);
        }else if(dig.l2 == 1 && dig.r2 == 0){ // näkee vasammalla mustaa
            motor_turn(20,100,0); // kääntyy vasemmalle
        }else if (dig.l3 == 1 && dig.r3 == 0){ // jos kaukana vasemmalla mustaa
            while(!(dig.l1 == 0 || dig.r1 == 0)){ // jos ei löydä mustaa, pyörii ympyrää
                motor_turn(20,150,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }else if(dig.r2 == 1 && dig.l2 == 0){ // näkee oikeella mustaa
            motor_turn(100,20,0); // kääntyy oikeelle
        }else if (dig.l3 == 0 && dig.r3 == 1){ // jos kaukana oikealla mustaa
             while(!(dig.l1 == 0 || dig.r1 == 0)){ //jyrkkä oikea niin kauan että löytyy mustaa
                motor_turn(150,55,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }
    }
    
}

void TankTurnL(uint8 speed,uint32 delay){
    MotorDirLeft_Write(1);      // set LeftMotor forward mode
    MotorDirRight_Write(0);     // set RightMotor backward mode
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    vTaskDelay(delay);
}

void TankTurnR(uint8 speed,uint32 delay){
    MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(1);     // set RightMotor forward mode
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    vTaskDelay(delay);
}

        // Assignment 1 - Autoline

#if 0
//reflectance
void zmain(void)
{
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    while(true){
        if(SW1_Read() == 0){
            FollowLine();
            break;
        }
    }
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
                printf("%d %d\r\n",b, l);
                
                for(int i = 0; i < 3; i++){
                    FollowLine();
                }
            }
        }
        
        break;
    }
    
    while(true){
        vTaskDelay(100);
    }
}   

#endif

#if 1

// Follow the line pls

void FollowLine(void){
    
    struct sensors_ ref;
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
    
    while(true){
        
        reflectance_read(&ref);
        reflectance_digital(&dig);

        if (dig.l3 == 1 && dig.l2 == 1 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1){
            motor_forward(0,0);
            break;
        }
        else if(dig.l1 == 1 || dig.r1 == 1){ // näkee keskellä mustaa
            motor_forward(150,0);
        }else if(dig.l2 == 1 && dig.r2 == 0){ // näkee vasammalla mustaa
            TankTurnL(150,0); // kääntyy vasemmalle
        }else if (dig.l3 == 1 && dig.r3 == 0){ // jos kaukana vasemmalla mustaa
            while(!(dig.l1 == 0 || dig.r1 == 0)){ // jos ei löydä mustaa, pyörii ympyrää
                motor_turn(20,150,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }else if(dig.r2 == 1 && dig.l2 == 0){ // näkee oikeella mustaa
            TankTurnR(150,0); // kääntyy oikeelle
        }else if (dig.l3 == 0 && dig.r3 == 1){ // jos kaukana oikealla mustaa
             while(!(dig.l1 == 0 || dig.r1 == 0)){ //jyrkkä oikea niin kauan että löytyy mustaa
                motor_turn(150,55,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }
    }
}

#endif

// CONTINUE -- TANJA && JANINA

void FollowLineTankTurnEdition(void){
    
    struct sensors_ ref;
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
    
    while(true){
        
        reflectance_read(&ref);
        reflectance_digital(&dig);
    
    //while(!(dig.l3 == 1 && dig.l2 == 1 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1)){
        
        if (dig.l3 == 1 && dig.l2 == 1 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1){
            motor_forward(0,0);
            break;
        }
        else if(dig.l1 == 1 || dig.r1 == 1){ // näkee keskellä mustaa
            motor_forward(150,0);
        }else if(dig.l2 == 1 && dig.r2 == 0){ // näkee vasammalla mustaa
            TankTurnL(150,0); // kääntyy vasemmalle
        }else if (dig.l3 == 1 && dig.r3 == 0){ // jos kaukana vasemmalla mustaa
            while(!(dig.l1 == 0 || dig.r1 == 0)){ // jos ei löydä mustaa, pyörii ympyrää
                motor_turn(20,150,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }else if(dig.r2 == 1 && dig.l2 == 0){ // näkee oikeella mustaa
            TankTurnR(150,0); // kääntyy oikeelle
        }else if (dig.l3 == 0 && dig.r3 == 1){ // jos kaukana oikealla mustaa
             while(!(dig.l1 == 0 || dig.r1 == 0)){ //jyrkkä oikea niin kauan että löytyy mustaa
                motor_turn(150,55,0);
                reflectance_read(&ref);
                reflectance_digital(&dig);
                Beep(244,244);
            }
        }/*else {
            Beep(100,100);
            motor_stop();
            break;
        }*/
        
    //}
    }
}

/* ------------------------------------------------------------------- */

// The maze -- Project -- ON PROGRESS

#if 1
    
    void zmain(void){
        
        struct sensors_ ref;
        struct sensors_ dig;
    
        reflectance_start();
        reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
        
        int x = 3, y = 0;
        
        motor_start();
        Ultra_Start();
        
        int d = Ultra_GetDistance();
        printf("distance = %d\r\n", d);
        
        while(true){
            motor_forward(0,0);
            
            reflectance_read(&ref);
            reflectance_digital(&dig);
        
            if(SW1_Read() == 0){
                vTaskDelay(100);
                FollowLine();
                break;
            }
        }
        
        while(true){
            
            int d = Ultra_GetDistance();
            reflectance_read(&ref);
            reflectance_digital(&dig);
            
            if(dig.l3 == 0 && dig.l2 == 0 && dig.l1 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0 && y == 13){
                motor_forward(0,0);
                break;
                
            }else if(d <= 15){ // NOTICE BARRICADE
                motor_forward(0,0);
                
                if(y == 8){ // WHEN REACHING 8th LINE, RETURN TO X = 3 IF NO BARRICADE
                     
                    if(x == 0 || x == 1 || x == 2){
                        TankTurnR(150,300);
                        
                        d = Ultra_GetDistance();
                        
                        while(!(x == 3 && d < 15)){
                            FollowLine();
                        }
                        
                        TankTurnL(150,300);
                    }else if(x == 3 || x == 4 || x == 5){  // IF YOU´RE ON THE RIGHT OR MIDDLE - TURN 90 RIGHT & CHECK NEXT
                    
                        TankTurnR(150,300);
                        
                        d = Ultra_GetDistance();
                        if(d <= 15){ // IF RIGHT EXIT IS BLOCKED
                            TankTurnL(150,300);
                            TankTurnL(150,300);
                            
                            d = Ultra_GetDistance();
                            if(d >= 15){ // IF LEFT EXIT IS BLOCKED AS WELL
                                
                                FollowLine();
                                TankTurnR(150,300);
                                y -= 1;
                            }else{
                                x -= 1;
                            }
                    }else{ // IF THERE´S NO BLOCK ON THE RIGHT EXIT - GO RIGHT
                        FollowLine();
                        TankTurnL(150,300);
                        
                        x += 1;
                    }
                }else if(x == 6){ // IF YOU´RE ON THE RIGHT EDGE - TURN 180 LEFT
                    TankTurnL(150,300);
                    TankTurnL(150,300);
                    
                    x -= 1;
                }else if(x == 2 ||x == 1){ // IF YOU´RE ON THE LEFT - TURN 90 LEFT & CHECK NEXT
                    
                    TankTurnL(150,300);
                    
                    d = Ultra_GetDistance();
                    if(d <= 15){ // IF LEFT EXIT IS BLOCKED
                        TankTurnR(150,300);
                        TankTurnR(150,300);
                        
                        d = Ultra_GetDistance();
                        if(d >= 15){ // IF RIGHT EXIT IS NOT BLOCKED
                            
                            FollowLine();
                            TankTurnL(150,300);
                            y -= 1;
                        }else{
                            x += 1;
                        }
                    }else{ // IF THERE´S NO BLOCK ON THE LEFT EXIT - GO LEFT
                        FollowLine();
                        TankTurnR(150,300);
                        
                        x -= 1;
                    }
                }else if(x == 0){ // IF YOU´RE ON THE LEFT EDGE - TURN 180 RIGHT
                    TankTurnR(150,300);
                    TankTurnR(150,300);
                    
                    x += 1;
                }else if(x == 4 || x == 5 ||x == 6){
                        TankTurnL(150,300);
                        
                        d = Ultra_GetDistance();
                        
                        while(!(x == 3 && d < 15)){
                            FollowLine();
                        }
                        
                        TankTurnR(150,300);
                    }
                    
                }else{ // JUST SO I´LL KNOW IF THE CODE GOES TO ELSE
                    BatteryLed_Write(1);
                    vTaskDelay(500);
                    BatteryLed_Write(0);
                    vTaskDelay(500);
                    BatteryLed_Write(1);
                    vTaskDelay(500);
                    BatteryLed_Write(0);
                    vTaskDelay(500);
                }
                
            }else if(dig.l3 == 0 && dig.l2 == 0 && dig.l1 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0){ // IF SENSORS MEET WHITE
                
                if(x == 0 || x == 1 || x == 2){ // IF ON THE LEFT SIDE - TURN RIGHT
                    while(!(dig.l3 == 0 && dig.l2 == 0 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 0 && dig.r3 == 0)){ // TURN UNTIL LINE IS FOUND
                        TankTurnR(150,0);
                    }
                    
                    while(true){ // GO STRAIGHT IF NO BARRICADES AHEAD
                        d = Ultra_GetDistance();
                        
                        if(d <= 15 || x == 3){ // IF A BARRICADE AHEAD
                            TankTurnL(150,300);
                            d = Ultra_GetDistance();
                            
                            if(d >= 15){ // IF NO BARRICADE AHEAD AFTER TURNING
                                FollowLine();
                            }
                        }else{
                            FollowLine();
                        }
                    }
                }if(x == 6 || x == 5 || x == 4){ // IF ON THE RIGHT SIDE - TURN LEFT
                    while(!(dig.l3 == 0 && dig.l2 == 0 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 0 && dig.r3 == 0)){ // TURN UNTIL LINE IS FOUND
                        TankTurnL(150,0);
                    }
                    
                    while(true){ // GO STRAIGHT IF NO BARRICADES AHEAD
                        d = Ultra_GetDistance();
                        
                        if(d <= 15 || x == 3){ // IF A BARRICADE AHEAD
                            TankTurnR(150,300);
                            d = Ultra_GetDistance();
                            
                            if(d >= 15){ // IF NO BARRICADE AHEAD AFTER TURNING
                                FollowLine();
                            }
                        }else{
                            FollowLine();
                        }
                    }
                }
            }else{ // GO STRAIGHT
                if(dig.l3 == 1 && dig.l2 == 1 && dig.l1 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1){ // IF ON THE BLACK, MOVE FROM IT
                    while(true){
                        reflectance_digital(&dig);
                        
                        if(dig.l3 == 0 && dig.r3 == 0){
                            break;
                        }
                        
                        motor_forward(100,0);
                    }
                }
                
                FollowLine();
                y += 1;
            }
        }
        
        while(true){
            vTaskDelay(100);
        }
    }
    
#endif

// SUMO WRESTLING

#if 0
    
    void zmain(void){
    
        motor_start();
        Ultra_Start();
        
        IR_Start();
    
        IR_flush(); // clear IR receive buffer
        
        struct sensors_ ref;
        struct sensors_ dig;
    
        reflectance_start();
        reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
        
        struct accData_ data;
    
        //printf("Accelerometer test...\n");

        if(!LSM303D_Start()){
            printf("LSM303D failed to initialize!!! Program is Ending!!!\n");
            vTaskSuspend(NULL);
        }
        else {
            printf("Device Ok...\n");
        }
        
        while(true){
            motor_forward(0,0);
        
            if(SW1_Read() == 0){
                vTaskDelay(100);
                FollowLine();
                break;
            }
        }
        
        while(true){
            
            uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
                printf("%d %d\r\n",b, l);
                
                motor_forward(150,500);
                
                while(true){ // TURNING AROUND AND WHEN GETTING HIT
                    
                    reflectance_read(&ref);
                    reflectance_digital(&dig);    
                    
                    TankTurnR(150,0);
                    
                    LSM303D_Read_Acc(&data);
                    
                    /*if(data.accY < -3000){
                    
                        if(dig.l1 == 0 && dig.l2 == 0 && dig.l3 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0){
                            motor_forward(150,0);
                        }else if(dig.l1 == 0 && dig.l2 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 1){
                            TankTurnL(150,0);
                        }else if(dig.l1 == 0 && dig.l2 == 0 && dig.r1 == 0 && dig.r2 == 1 && dig.r3 == 1){
                            TankTurnL(150,0);
                        }else if(dig.l1 == 0 && dig.l2 == 0 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 0){
                            TankTurnL(150,0);
                        }else if(dig.l1 == 1 && dig.l2 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0){
                            TankTurnR(150,0); 
                        }else if(dig.l1 == 1 && dig.l2 == 1 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0){
                            TankTurnR(150,300);
                        }else if(dig.l1 == 0 && dig.l2 == 1 && dig.r1 == 1 && dig.r2 == 0 && dig.r3 == 0){
                            TankTurnR(150,0);
                        }else{
                            motor_forward(0,0);
                            Beep(244,244);
                        }
                        
                    }else{*/
                        
                        if(dig.l1 == 0 && dig.l2 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 1){
                            TankTurnL(150,0);
                        }else if(dig.l1 == 0 && dig.l2 == 0 && dig.r1 == 0 && dig.r2 == 1 && dig.r3 == 1){
                            TankTurnL(150,0);
                        }else if(dig.l1 == 0 && dig.l2 == 0 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 0){
                            TankTurnL(150,0);
                        }else if(dig.l1 == 1 && dig.l2 == 0 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0){
                            TankTurnR(150,0);
                        }else if(dig.l1 == 1 && dig.l2 == 1 && dig.r1 == 0 && dig.r2 == 0 && dig.r3 == 0){
                            TankTurnR(150,0);
                        }else if(dig.l1 == 0 && dig.l2 == 1 && dig.r1 == 1 && dig.r2 == 0 && dig.r3 == 0){
                            TankTurnR(150,0);
                        }else{
                            motor_forward(0,0);
                            Beep(244,244);
                        }
                    
                    //}
                        
                    
                }
                break;
            }
    }
    }
        
        while(true){
            vTaskDelay(1000);
        }
        
    }
    
#endif

        // Assignment 2 - Autoline


        


        // TANKKI -- BACKWARD & TURN

#if 0

void zmain(void){
        
        
        IR_Start();
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
                
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
                
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            Tankki();
            IR_flush();
            break;
        }
    }
        
        while(true){
            vTaskDelay(1000);
        }
    }
}
    
#endif


#if 1 // TANKKI FUNCTION

void Tankki(void){
    
    motor_start();
    motor_forward(0,0);
    
    struct sensors_ ref;
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    reflectance_read(&ref);
    reflectance_digital(&dig);
    
    while(true){
        
        reflectance_read(&ref);
        reflectance_digital(&dig);
        
        
        if(dig.l1 == 1 && dig.l2 == 1 && dig.l3 == 1 && dig.r1 == 1 && dig.r2 == 1 && dig.r3 == 1){
            motor_forward(0,0);
            break;
        }else if(dig.l1 == 1 || dig.r1 == 1){
            motor_forward(150,0);
        }else if(dig.l2 == 1 && dig.r2 == 0){
            motor_turn(55,150,0);
        }else if(dig.l2 == 0 && dig.r2 == 1){
            motor_turn(150,55,0);
        }else if(dig.l3 == 1 && dig.r3 == 0){
            while(!(dig.r1 == 1)){
                reflectance_read(&ref);
                reflectance_digital(&dig);
                
                motor_backward(100,0);
                motor_turn(150,0,0);
            }
        }else if(dig.l3 == 0 && dig.r3 == 1){
            while(!(dig.l1 == 1)){
                reflectance_read(&ref);
                reflectance_digital(&dig);
                
                motor_backward(100,0);
                motor_turn(0,150,0);
            }
        }else{
            while(!(dig.l1 == 1 || dig.r1 == 1)){
                reflectance_read(&ref);
                reflectance_digital(&dig);
                
                motor_backward(100,0);
                motor_turn(0,150,0);
            }
        }
    }
}

#endif

    // Assignment 2 -- HARD CODED

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    
    while(true){
        motor_forward(0,0);
        
        if(SW1_Read() == 0){
            motor_forward(200,1000);
            motor_forward(0,0);
            break;
        }
    }
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            motor_forward(250,300);
            motor_turn(0,100,1000); // Turn left
            motor_forward(250,300);
            motor_turn(100,0,1000); // Turn right
            motor_forward(250,300);
            motor_turn(100,0,1000); // Turn right
            motor_forward(250,300);
            motor_forward(0,0);
            IR_flush();
            break;
        }
    }
    
    while(true)
    {
        vTaskDelay(100);
    }
    
    }
}
#endif

    // Assignment 3 -- HARD CODED

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    
    while(true){
        motor_forward(0,0);
        
        if(SW1_Read() == 0){
            Tank();
            break;
        }
    }
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    while(true)
    {   
        uint32_t IR_val;
        
        IR_wait();  // wait for IR command
        
        if(IR_get(0,1000) == true){
            if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            Tank();
            IR_flush();
            break;
        }
    }
    
    while(true)
    {
        vTaskDelay(100);
    }
    
    }
}
#endif

#if 0
// Name and age
void zmain(void)
{
    char name[32];
    int age;
    
    
    printf("\n\n");
    
    printf("Enter your name: ");
    //fflush(stdout);
    scanf("%s", name);
    printf("Enter your age: ");
    //fflush(stdout);
    scanf("%d", &age);
    
    printf("You are [%s], age = %d\n", name, age);

    while(true)
    {
        BatteryLed_Write(!SW1_Read());
        vTaskDelay(100);
    }
 }   
#endif


#if 0
//battery level//
void zmain(void)
{
    ADC_Battery_Start();        

    int16 adcresult =0;
    float volts = 0.0;

    printf("\nBoot\n");

    //BatteryLed_Write(1); // Switch led on 
    BatteryLed_Write(0); // Switch led off 
    //uint8 button;
    //button = SW1_Read(); // read SW1 on pSoC board
    // SW1_Read() returns zero when button is pressed
    // SW1_Read() returns one when button is not pressed

    while(true)
    {
        char msg[80];
        ADC_Battery_StartConvert(); // start sampling
        if(ADC_Battery_IsEndConversion(ADC_Battery_WAIT_FOR_RESULT)) {   // wait for ADC converted value
            adcresult = ADC_Battery_GetResult16(); // get the ADC value (0 - 4095)
            // convert value to Volts
            // you need to implement the conversion
            
            // Print both ADC results and converted value
            printf("%d %f\r\n",adcresult, volts);
        }
        vTaskDelay(500);
    }
 }   
#endif

#if 0
// button
void zmain(void)
{
    while(true) {
        printf("Press button within 5 seconds!\n");
        int i = 50;
        while(i > 0) {
            if(SW1_Read() == 0) {
                break;
            }
            vTaskDelay(100);
            --i;
        }
        if(i > 0) {
            printf("Good work\n");
            while(SW1_Read() == 0) vTaskDelay(10); // wait until button is released
        }
        else {
            printf("You didn't press the button\n");
        }
    }
}
#endif

#if 0
// button
void zmain(void)
{
    printf("\nBoot\n");

    //BatteryLed_Write(1); // Switch led on 
    BatteryLed_Write(0); // Switch led off 
    
    //uint8 button;
    //button = SW1_Read(); // read SW1 on pSoC board
    // SW1_Read() returns zero when button is pressed
    // SW1_Read() returns one when button is not pressed
    
    bool led = false;
    
    while(true)
    {
        // toggle led state when button is pressed
        if(SW1_Read() == 0) {
            led = !led;
            BatteryLed_Write(led);
            if(led) printf("Led is ON\n");
            else printf("Led is OFF\n");
            Beep(1000, 150);
            while(SW1_Read() == 0) vTaskDelay(10); // wait while button is being pressed
        }        
    }
 }   
#endif


#if 0
//ultrasonic sensor//
void zmain(void)
{
    Ultra_Start();                          // Ultra Sonic Start function
    
    while(true) {
        int d = Ultra_GetDistance();
        // Print the detected distance (centimeters)
        printf("distance = %d\r\n", d);
        vTaskDelay(200);
    }
}   
#endif

#if 0
//IR receiverm - how to wait for IR remote commands
void zmain(void)
{
    IR_Start();
    
    printf("\n\nIR test\n");
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    bool led = false;
    // Toggle led when IR signal is received
    while(true)
    {
        IR_wait();  // wait for IR command
        led = !led;
        BatteryLed_Write(led);
        if(led) printf("Led is ON\n");
        else printf("Led is OFF\n");
    }    
 }   
#endif



#if 0
//IR receiver - read raw data
void zmain(void)
{
    IR_Start();
    
    uint32_t IR_val; 
    
    printf("\n\nIR test\n");
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    // print received IR pulses and their lengths
    while(true)
    {
        if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
            Beep(150,50);
            IR_flush();
            break;
        }
    }    
 }   
#endif


#if 0
//reflectance
void zmain(void)
{
    struct sensors_ ref;
    struct sensors_ dig;

    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
    

    while(true)
    {
        // read raw sensor values
        reflectance_read(&ref);
        // print out each period of reflectance sensors
        printf("%5d %5d %5d %5d %5d %5d\r\n", ref.dig.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);       
        
        // read digital values that are based on threshold. 0 = white, 1 = black
        // when blackness value is over threshold the sensors reads 1, otherwise 0
        reflectance_digital(&dig); 
        //print out 0 or 1 according to results of reflectance period
        printf("%5d %5d %5d %5d %5d %5d \r\n", dig.dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);        
        
        vTaskDelay(200);
    }
}   
#endif


#if 0
//motor
void zmain(void)
{
    motor_start();              // enable motor controller
    motor_forward(0,0);         // set speed to zero to stop motors

    vTaskDelay(3000);
    
    motor_forward(100,2000);     // moving forward
    motor_turn(200,50,2000);     // turn
    motor_turn(50,200,2000);     // turn
    motor_backward(100,2000);    // moving backward
     
    motor_forward(0,0);         // stop motors

    motor_stop();               // disable motor controller
    
    while(true)
    {
        vTaskDelay(100);
    }
}
#endif

#if 0
/* Example of how to use te Accelerometer!!!*/
void zmain(void)
{
    struct accData_ data;
    
    printf("Accelerometer test...\n");

    if(!LSM303D_Start()){
        printf("LSM303D failed to initialize!!! Program is Ending!!!\n");
        vTaskSuspend(NULL);
    }
    else {
        printf("Device Ok...\n");
    }
    
    while(true)
    {
        LSM303D_Read_Acc(&data);
        printf("%8d %8d %8d\n",data.accX, data.accY, data.accZ);
        vTaskDelay(50);
    }
 }   
#endif    

#if 0
// MQTT test
void zmain(void)
{
    int ctr = 0;

    printf("\nBoot\n");
    send_mqtt("Zumo01/debug", "Boot");

    //BatteryLed_Write(1); // Switch led on 
    BatteryLed_Write(0); // Switch led off 

    while(true)
    {
        printf("Ctr: %d, Button: %d\n", ctr, SW1_Read());
        print_mqtt("Zumo01/debug", "Ctr: %d, Button: %d", ctr, SW1_Read());

        vTaskDelay(1000);
        ctr++;
    }
 }   
#endif


#if 0
void zmain(void)
{    
    struct accData_ data;
    struct sensors_ ref;
    struct sensors_ dig;
    
    printf("MQTT and sensor test...\n");

    if(!LSM303D_Start()){
        printf("LSM303D failed to initialize!!! Program is Ending!!!\n");
        vTaskSuspend(NULL);
    }
    else {
        printf("Accelerometer Ok...\n");
    }
    
    int ctr = 0;
    reflectance_start();
    while(true)
    {
        LSM303D_Read_Acc(&data);
        // send data when we detect a hit and at 10 second intervals
        if(data.accX > 1500 || ++ctr > 1000) {
            printf("Acc: %8d %8d %8d\n",data.accX, data.accY, data.accZ);
            print_mqtt("Zumo01/acc", "%d,%d,%d", data.accX, data.accY, data.accZ);
            reflectance_read(&ref);
            printf("Ref: %8d %8d %8d %8d %8d %8d\n", ref.dig.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);       
            print_mqtt("Zumo01/ref", "%d,%d,%d,%d,%d,%d", ref.dig.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);
            reflectance_digital(&dig);
            printf("Dig: %8d %8d %8d %8d %8d %8d\n", dig.dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);
            print_mqtt("Zumo01/dig", "%d,%d,%d,%d,%d,%d", dig.dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);
            ctr = 0;
        }
        vTaskDelay(10);
    }
 }   

#endif

#if 0
void zmain(void)
{    
    RTC_Start(); // start real time clock
    
    RTC_TIME_DATE now;

    // set current time
    now.Hour = 12;
    now.Min = 34;
    now.Sec = 56;
    now.DayOfMonth = 25;
    now.Month = 9;
    now.Year = 2018;
    RTC_WriteTime(&now); // write the time to real time clock

    while(true)
    {
        if(SW1_Read() == 0) {
            // read the current time
            RTC_DisableInt(); /* Disable Interrupt of RTC Component */
            now = *RTC_ReadTime(); /* copy the current time to a local variable */
            RTC_EnableInt(); /* Enable Interrupt of RTC Component */

            // print the current time
            printf("%2d:%02d.%02d\n", now.Hour, now.Min, now.Sec);
            
            // wait until button is released
            while(SW1_Read() == 0) vTaskDelay(50);
        }
        vTaskDelay(50);
    }
 }   
#endif

/* [] END OF FILE */
