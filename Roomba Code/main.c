#include <kipr/wombat.h>
#include <functions.h>

int main()
{
    //wait_for_light(1);
    shut_down_in(115);
    
    create_connect();
    enable_servos();
    
    movegmpc(700,200, 200);
    ao();
    
    turn(30); // Turn to align to two rocks
    
    sleep(1);
    set_servo_position(2, 1300); // Push rocks together
    sleep(1);
    
    movegmpc(200, 200, 200); // Move up a little to fully grab the two rocks
    set_servo_position(2, 300); // Fully Close
    
    movegmpc(700, 200, 200); // Go Towards 3rd rock
    set_servo_position( 2, 1800); // Open Claw to get the third rock
    
    movegmpc(500, 200, 200); // Deliver Rocks
    
    return 0;
}
