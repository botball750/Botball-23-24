#include <stdio.h>
#include <kipr/wombat.h>
#include <functions.h>

// Execute Code
int main()
{
    init(); // Start
	// Adjust Servos
    moveServo(0, 225);
    moveServo(1, 444);

    msleep(1000);
	// Drive Towards Pom 1
    driveFT(.7, 1);

    rotate(30, 90); // Knock Pom 1
    msleep(500);
    
    rotate(-40, 90);
    driveFT(0.5,1);
    
    rotate(40, 90);
    rotate(-40, 90);
    moveServo(1, 2047);
    // Finish Knocking Pom Two
    
    // Start Driving to middle
    driveFT(2,1);
    rotate(60, 90);
    driveFT(1.3,1);
    driveFT(-1.65, 1);
    rotate(25, 40);
    
    // Adjust to the height of the cubes
    moveServo(0,1700);
    driveFT(1.05,1);
    moveServo(1, 350); // Grab the Cube
    msleep(1000);
    driveFT(-0.5,1);
    rotate(30, 90);
    
    // Drop off the Cubes to the left
    driveFT(0.1,1);
    moveServo(0,225);
    msleep(500);
    moveServo(1, 2047);

    create3_wait(); // End
    return 0;
}
