#include <kipr/wombat.h>

void ao();
{
    create_drive_direct(0, 0);
}

void servo(int port,int target_position, int pause_time)
{
    enable_servos();

    int current_position= get_servo_position(port);    

    while(current_position != target_position)
    {

        if(current_position < target_position)
        { current_position = current_position + 1;
        }   
        else
        {  
            current_position = current_position - 1;
        }  
        set_servo_position(port,current_position);
        msleep(pause_time);  
    }

}                

void turn(int tangle)
{
    set_create_total_angle(0);

    if (tangle < 0) // Right
    {
        while(get_create_total_angle() > tangle)
        {
            create_drive_direct(100, -100);
            printf("%d\n", get_create_total_angle());
        }
    }
    else
    {
        while(get_create_total_angle() < tangle)
        {
            create_drive_direct(-100, 100);
        }  
    }
    ao();
}

void movegmpc(int GMPCNumber, int powerleft, int powerright)
{
    set_create_distance(0);

    while (get_create_distance() < GMPCNumber) {
        create_drive_direct(powerleft,powerright);
    }
}

void movebump()
{
    while(get_create_rbump() == 0 && get_create_lbump() == 0)
    {
        create_drive_direct(200,200);   
    }
}

void sleep(float time)
{
    msleep(time * 1000);   
}
    
    return 0;
}
          
