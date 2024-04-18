#include <stdio.h>
#include <kipr/wombat.h>
#include <mainFunctions.h>

int main()
{

    //wait_for_light(0);
    shut_down_in(119);
    enable_servos(1, 3); // wake up servos

    set_servo_position(1, 1640); // start the arm down
    set_servo_position(3, 1927); //claw is open (1)
    msleep(10);

    //First batch

    // drive straight to first batch of pom-poms
    motors(100,80);
    msleep(3500);

    // turn right to first batch of pom-poms
    motors(-50,50);
    msleep(2000);
    ao();
    
    // Go up to First Batch slowly
    motors(50,50);
    msleep(1200);

    // stop everything to prevent the robot from moving (1)
    ao();
    
    msleep(1010);
    servo(3, 630, 1);// close claw to grab the green pom-pom
    sleep(1);
    set_servo_position(1, 751); //arm is up to avoid hitting the red pom-poms

    // Turn left to make the robot straight and drop the green pom-pom
    sleep(1);
    motors(-50, 50);
    msleep(2600);
    ao();

    // Stop everything to prevent the robot from moving (2)
    ao();
    set_servo_position(1, 1759); // arm is down to put the green pom-pom down
    sleep(1);
    set_servo_position(3, 1000); //claw is open to release the green pom-pom
    sleep(1);
    set_servo_position(1, 751); // arm is up to avoid hitting the green pom-pom
    sleep(1);
    
    
    motors(50, -50);
    msleep(2800);
    ao();
    
    // Back up
    motors(-100, -100);
    msleep(500);
    ao();
    
    servo(1, 1800, 1);
    set_servo_position(3, 1850);
    
    // Go Forward to deliver 3 red poms
    motors(100,100);
    msleep(3000);
    
    ao();
    set_servo_position(1, 751); // arm is up to avoid hitting the red pom-poms
    
    // Align to 2nd batch
    motors(50, -50); // Go Left
    sleep(1);
    ao();
        
    motors(100,100); // Go Forward to align with 2nd batch
    msleep(1300);
    ao();
      
    motors(50, -50); // Go left to face the 2nd batch
    msleep(1600);
    ao();
    
    servo(1, 1700, 1); // Go down
    sleep(1);
    
    motors(32, 32); // Go up a bit
    msleep(1100);
    ao();
    
    servo(3, 750, 1); // Grab the red pom
    
    sleep(1); // Wait until grabbed red pom
    set_servo_position(1, 751); //arm is up to deliver red pom
    
    // Delivering Red Pom
    sleep(1);
    
    motors(50, -50); // Turn to pile
    msleep(2000);
    ao();
    
    set_servo_position(1, 1650); // Go Down
    msleep(500);
    set_servo_position(3, 1927); // Open Claw
    sleep(1);
    
    set_servo_position(1, 751); // Arm go up
    sleep(1);
    
    motors(-50, 50); // Turn back 
    msleep(2000);
    
    motors(-25, -25);
    sleep(1);
    
    ao();
    set_servo_position(1, 1850); // Go down
    sleep(1);
    
    motors(100, 90); // Deliver green poms
    msleep(3300);
    ao();
    
    motors(-100, -100); // Go back to prevent knocking green poms
    msleep(300);
    ao();
    
    motors(-10, 10); // Turn Right to align to air lock 
    sleep(5.1);
    ao();
    
    sleep(0.5);
    set_servo_position(1, 1650); // Setup Arm
    
    set_servo_position(3, 1080); // Setup Claw
        
    msleep(600);
    motors(60,60); // Go forward to go to the air lock
    sleep(1);
    
    set_servo_position(3, 650); // Close Claw
    msleep(300);
    
    motors(-100, -100); // Back up to free the air lock
    
    // Drive backwards to get the air lock
    motor(0, -100);
    motor(3, -100);
    msleep(1);
    /*
    // Turn left to get the air lock properly
    motor(0, 100);
    motor(3, 0);
    msleep(350);
    
    ao();
    set_servo_position(3, 1300); // Open Claw
    
    */
    sleep(1);

    ao();
    
    // Brian's Code
    set_servo_position(3, 920);
    set_servo_position(1, 1550);
    sleep(1);

    
    motor(3, 100);
    msleep(100);
    
    motor(0, 100);
    motor(3, 100);
    msleep(1680);

    ao();
    set_servo_position(1, 1000);
    sleep(1);
    
    motor(0, -100);
    motor(3, -100);
    msleep(1000);
    
    motor(3, 0);
    msleep(2700);
    
    motor(0, 100);
    motor(3, 100);
    msleep(200);
    
    ao();
    set_servo_position(3, 1940);
    msleep(1000);
    set_servo_position(1, 1740);
    msleep(1000);
    set_servo_position(3, 1360);
    msleep(1000);
    /*

    motor(0, -100);
    motor(3, -100);
    msleep(1150);

    motor(3, 0);
    msleep(120);

    ao();
    set_servo_position(3, 1000);
    set_servo_position(1, 2047);
    msleep(1);

    motor(0, 100);
    motor(3, 100);
    msleep(4200);
    
    ao();
    set_servo_position(3, 1700);
    sleep(1);

    motor(3, 0);
    msleep(600);

    motor(0, 100);
    motor(3, 100);
    msleep(1);
    disable_servos(1, 3); // put servos to sleep
    */
    return 0;
}


