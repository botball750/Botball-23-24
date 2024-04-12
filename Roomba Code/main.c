// Import Libraries
#include <stdio.h>
#include <kipr/wombat.h>
#include <mainFunctions.h>

int main()
{
  // Reference Guide
  /*
    mavs(speed (percentage) - Utilize both motors
    drive(distance (ticks) , speed (percentage) - Drive while using GMPC
    
    // SERVOS
    armdown() (makes the arm go down)
    armup() self explanitory 
    
    clawopen() self explanitory 
    clawclose() self explanitory 
  */
    shut_down_in(119);
    enable_servos(1, 3); // wake up servos

    set_servo_position(1, 1990); // start the arm down
    set_servo_position(3, 1700); //claw is open (1)
    msleep(800);

	// Drive to Cabinet
    mavs(10000, 10000);
    msleep(3000);
    ao();
    
    motor(1, 25);
    motor(3, -25);
    msleep(1750);
    
    mavs(10000,10000);
    msleep(2000);
    ao(); // Stop Motor
    
    set_servo_position(3, 2047); //grab cabinet
    msleep(1000);
    
	mavs(-10000, -10000);
    msleep(1000);
    ao(); // Drive Back to release cabinet
    
    set_servo_position(3, 60); // Open Claw
    msleep(1000);
   	
    motor(1, -25); // Go For Rock One
    motor(3, 25);
    msleep(1750);
    ao();
    
    set_servo_position(1, 2047); // Go Down
    mavs(10000, 10000);
    msleep(850);
    ao();
    
    msleep(1000); // Wait until stopped
    set_servo_position(3, 1950); // Grab Rock One
    
    msleep(1000);
    
    // Deliver Rock
    armup();
    msleep(1000); // Delay 
    
    // 
    motor(1, -25); // Go Around Orange
    motor(3, 25);
    msleep(1600);
    ao();
    
    mavs(6000, 10000); // Drive to Rock Heap
    msleep(4000);
    ao();
    
    motor(1, 50); // Turn Towards Rock Heap
    motor(3, -50);
    msleep(1350);
    ao();
    
    mavs(-10000,-10000);
    msleep(500);
    ao();
    
    armdown();
    msleep(1000);
    clawopen(); // Drop Off
    
    mavs(10000, 10000);
    msleep(3000); // Drive Up
    ao();
    
  return 0;
}
