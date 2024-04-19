#include <kipr/wombat.h>
#include <header.h>

int main()
{
    // Startup
    enable_servos();
    // Setup Arm
    set_servo_position(1, 1800);
    clawopen();

    // Execute Code
    motors(100, 100);
    sleep(3);
    
    // Turn to face the rock
    slowm(20, -20);
    sleep(0.4);
    
    motors(100, 100);
    sleep(1.3);
    
    // Grab Rock
    clawclose(); 
    
    sleep(1);
    
    // Rock Up
    armup();
    
    // Turn to face the orange poms
    slowm(-20, 20);
    sleep(0.4);
    
    // Get all Orange Poms
    motors(100, 100);
    sleep(3);
    
    // Deliver Orange Poms Turn Left
    slowm(50, -50);
    sleep(1);
    
    // Deliver
    motors(100, 100);
    sleep(1.5);
    
    ao();
    
    // Back Up
    motors(-100, -100);
    sleep(1);
    
    slowm(-50, 50);
    sleep(1.2);
    
    // Deliver Rock into Rock Heap
    motors(100, 100);
    sleep(2);
    
    slowm(50, -50);
    sleep(0.7);
    
    // Delivering
    armdown();
    sleep(0.5);
    clawopen();
    
    sleep(1);
    armup();
    
    motors(100, 100);
    sleep(1);
    
    // Back out Rock Heap
    motors(-100, -100);
    sleep(1);
    
    slowm(-50, 50);
    sleep(0.6);
    
    motors(-100, -100); // Go to Poms
    sleep(6);
    
    // Pom Sorting
    slowm(-50, 50);
    sleep(1.3);
    
    // Backup to align
    motors(-100, -100);
    sleep(2);
    
    // Go up to Poms
    armdown();
    slowm(50, 50);
    sleep(1.2);
    
    slowm(25, -25);
    sleep(0.25);
    ao();
    
    sleep(1);
    slowm(50, 50);
    sleep(1.7);
    
    // Grabbing the Pom
    clawclose(); // Grab the Pom
    
    sleep(1);
    
    armup();
    motors(100, 100);
    sleep(1.5);
    
    motors(-100, -100); // Backup to Align
    sleep(4);
    
    // Place Red Pom between arms
    armdown();
    sleep(1);
   	clawopen();
    
    sleep(1);
    
    motors(100, 100); // Go to second batch
    sleep(1);
    
    // Turn to face towards the second batch
    slowm(-25, 25);
    sleep(0.45);
    ao();
    
    // Go up to second batch
    slowm(50, 50);
    sleep(1);
    
    clawclose();
    sleep(1);
    armup();
    
    // Deliver Red Poms
    motors(100, 100);
    sleep(1);
    
    slowm(50, -50);
    sleep(3.3);
    ao();
    
    // Align with back wall and deliver green pom
    motors(-100, -100);
    sleep(4);
    
    armdown();
    sleep(0.5);
    clawopen();
    
    return 0;
}
