#include <stdio.h>
#include <kipr/wombat.h>
#include <main.h>

// Variables
int Servo_Arm = 0;
int Servo_Claw = 1;

// Execute Code
int main()
{
    init();
	
    moveServo(Servo_Claw, 1700);
    moveServo(Servo_Arm, 200);
    
    rotate(10,5);
    driveFT(4,5);
    moveServo(Servo_Claw, 600);
    
    rotate(25,5);
    moveServo(Servo_Claw, 1700);
    driveFT(2, 1);
    
    driveFT(-1, 1);
    rotate(-90,45);
   
    create3_wait();
    return 0;
}
