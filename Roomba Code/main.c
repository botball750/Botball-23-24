#include <kipr/wombat.h>
#include <main.h>

int main()
{
    //wait_for_light(1);
    shut_down_in(115);

    create_connect();
    enable_servos();

    // Setup
    printf("hello world\n");
    create_drive_direct(-200,-200); // Align with back wall
    set_servo_position(0, 1000);
    sleep(1);
    set_servo_position(1,750);
    sleep(1);
    set_servo_position(2,2047);
    sleep(1);

    sleep(3);

    movegmpc(700, 200, 200); // Go to Pile 1
    ao();

    turn(45);

    set_servo_position(1, 100); // Claw Down
    sleep(1);
    set_servo_position(2, 1500); // Claw Open Equal
    sleep(1);

    movegmpc(150, 50, 50); // Go up Slowly
    servo(2, 200, 1); // Bring Rocks Together

    sleep(1);
    turn(-30);

    set_servo_position(2, 1500); // Open Claw
    movegmpc(150, 50, 50); // Go to Alone Rock
    sleep(0.5);
    servo(2, 0, 1); // Grab Third Rock

    sleep(1);
    turn(45); // Face Towards zone + last rock
    movegmpc(150, 100, 100);
    set_servo_position(2, 1000);
    movegmpc(650, 200, 200); 

    create_drive_direct(-100, -100);
    sleep(0.5);
    turn(10);
    
    sleep(1);
    
    create_drive_direct(-200, -200); // Align Back Wall
    sleep(3);

    turn(15);
    create_drive_direct(-200, -200); // Align Back Wall
    set_servo_position(2, 1700);
    sleep(3);
    
    movegmpc(600, 150, 150);
    ao();

    servo(1, 1960, 0.8);

    sleep(1);
    turn(30); // Face towards rock group one
    sleep(1);
    create_drive_direct(100, 100);
    msleep(600);
    ao();

    servo(2, 330, 1);
    sleep(1);
    
    create_drive_direct(-100, -100);
    sleep(1.3);
    
    turn(-90);
    
    servo(1, 300, 1);
    sleep(2);
    servo(2, 1800, 0.6);

    return 0;
}
